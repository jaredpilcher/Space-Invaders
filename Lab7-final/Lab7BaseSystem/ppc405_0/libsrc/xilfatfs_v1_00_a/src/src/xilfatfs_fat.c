/////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2004 Xilinx, Inc.  All rights reserved.
//
// Xilinx, Inc.
//
// XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
// COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
// ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
// STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
// IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
// FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.  
// XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
// THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
// ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
// FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
// AND FITNESS FOR A PARTICULAR PURPOSE.
// 
////////////////////////////////////////////////////////////////////////////////

#include "fat.h"
#include "directory.h"
#include "util.h"

/* given a cluster, look into the FAT to find the next 
 * cluster in the link list */
UINT32 next_cluster(UINT32 cluster, PartitionInfo * pi)
{
  if (cluster < 2)
    return BAD_CLUSTER;

  return pi->op->next_cluster(cluster, pi);
}

/* return the first sector corresponding to a cluster */
UINT32 starting_sector(UINT32 cluster, PartitionInfo * pi)
{
	if (cluster == 0)
		return 0;
	return (((cluster - 2) * (UINT32) pi->SectorsPerCluster) +
		pi->DataSector);
}

/* next_cluster_generic: given a cluster number, return the 
 * cluster that is next in this cluster chain by looking
 * into the FAT data structure for this partition
 *
 * generic for FAT16 & FAT32
 */
UINT32 next_cluster_generic(UINT32 cluster, PartitionInfo * pi)
{
  BYTE buf[SECTORSIZE];
  UINT32 TempNextCluster;
  UINT32 Fat0SectorNum;
  UINT32 Fat1SectorNum;
  int NextClusterPosition;

  if (!pi->op->is_valid_cluster(cluster, pi))
    return BAD_CLUSTER;

  Fat0SectorNum = pi->op->get_fat_sector_for_cluster(cluster, pi);
  NextClusterPosition = pi->op->get_fat_offset_for_cluster(cluster, pi);

  if (read_sector(Fat0SectorNum, buf) != SECTORSIZE)
    return BAD_CLUSTER;

  TempNextCluster = pi->op->get_next_cluster(buf + NextClusterPosition, pi);

  /* check for FAT misMatch !!! */
  if (pi->NumberOfFats > 1) {
    Fat1SectorNum = Fat0SectorNum + pi->SectorsPerFat;

    if (read_sector(Fat1SectorNum, buf) != SECTORSIZE)
      return BAD_CLUSTER;

    if (TempNextCluster != pi->op->get_next_cluster(buf + NextClusterPosition, pi))
      return BAD_CLUSTER;	/* FAT tables don't match bail */
  }

  return (TempNextCluster);
}

/* Follow the cluster chain in FAT16/32 and free all allotted
 * clusters. 
 */
int free_cluster_chain_generic(UINT32 cluster, PartitionInfo *pi)
{
  UINT32 sector_in_buf = 0;
  UINT32 sector, offset;
  int modified = 0;	/* denotes if the sector_in_buf has been modified */
  BYTE buf[SECTORSIZE];

  while (!pi->op->is_eoc(cluster, pi)) {
    sector = pi->op->get_fat_sector_for_cluster(cluster, pi);
    if (sector != sector_in_buf) { /* have to read in a new sector from FAT */
      /* write to disk if the old sector was modified */
      if (modified) {
        if (write_sector(sector_in_buf, buf) != SECTORSIZE)
          return -1;

        /* update FAT 2 */
        if (pi->NumberOfFats > 1)
          if (write_sector(sector_in_buf + pi->SectorsPerFat, buf) 
              != SECTORSIZE)
            return -1;
        modified = 0;
      }

      /* read in the new sector */
      if (read_sector(sector, buf) != SECTORSIZE)
        return -1;

      sector_in_buf = sector;
    }

    offset = pi->op->get_fat_offset_for_cluster(cluster, pi);

    /* obtain the current value & reset it to zero */
    cluster = pi->op->get_next_cluster(buf + offset, pi);
    pi->op->set_next_cluster(buf + offset, 0, pi);
    modified = 1;
  }

  if (modified) {
    if (write_sector(sector_in_buf, buf) != SECTORSIZE)
      return -1;
    /* update FAT 2 */
    if (pi->NumberOfFats > 1)
      if (write_sector(sector_in_buf + pi->SectorsPerFat, buf) 
          != SECTORSIZE)
        return -1;
    modified = 0;
  }
			
  return 0;
}

/* truncate a file to size 0: done by following the cluster chain 
 * and freeing all allotted clsuters for this file
 */
int truncate_file(UINT32 cluster, PartitionInfo *pi)
{
  if (cluster < 2)
    return -1;

  return pi->op->free_cluster_chain(cluster, pi);
}

/* find a free cluster, set the next entry of that cluster to EOC
 * and return that cluster.
 * A request to allocate_one_cluster automatically sets the entry
 * in FAT for that cluster to point to EOC. This is because we want
 * to reduce the # of read and write calls to the disk
 */
UINT32 allocate_one_cluster_generic(PartitionInfo *pi)
{
  BYTE buf[SECTORSIZE];
  int FatEntrySize;
  UINT32 cluster = 0, sector, i;
  UINT32 eoc;

  if (pi->FatType == FAT16) {
    FatEntrySize = 2;
    eoc = FAT16_EOC;
  } else if (pi->FatType == FAT32) {
    FatEntrySize = 4;
    eoc = FAT32_EOC;
  } else {	/* works only for FAT16/32 */
    return 0;
  }

  for (sector = pi->FatSector; 
       sector < pi->FatSector + pi->SectorsPerFat;
       sector++) {
    /* read in the sector */
    if (read_sector(sector, buf) != SECTORSIZE)
      return 0;

    /* find if an entry is free */
    for (i = 0; i < SECTORSIZE; i+= FatEntrySize) {
      UINT32 cluster_val = pi->op->get_next_cluster(buf + i, pi);
      if (cluster_val == 0) { /* this cluster is free */
        BYTE buf2[SECTORSIZE];
        UINT32 cluster_val_2;

        if (read_sector(sector + pi->SectorsPerFat, buf2) != SECTORSIZE)
          return 0;
				
        cluster_val_2 = pi->op->get_next_cluster(buf2 + i, pi);

        if (cluster_val_2 != cluster_val)
          return 0;	/* FAT mismatch */

        /* write EOC as the entry for this cluster
         * in both the FATs */
        pi->op->set_next_cluster(buf2 + i, eoc, pi);
        if (write_sector(sector + pi->SectorsPerFat, buf2) != SECTORSIZE)
          return 0;

        pi->op->set_next_cluster(buf + i, eoc, pi);
        if (write_sector(sector, buf) != SECTORSIZE)
          return 0;

        return cluster;
      }
      cluster++;
    }
  }

  return 0;
}

int link_cluster_generic(UINT32 from_cluster, UINT32 to_cluster, PartitionInfo *pi)
{
  UINT32 sector = pi->op->get_fat_sector_for_cluster(from_cluster, pi);
  UINT32 offset = pi->op->get_fat_offset_for_cluster(from_cluster, pi);
  BYTE buf[SECTORSIZE];
	
  if (read_sector(sector, buf) != SECTORSIZE)
    return -1;

  /* set the next cluster for from_cluster to to_cluster */
  pi->op->set_next_cluster(buf + offset, to_cluster, pi);

  if (write_sector(sector, buf) != SECTORSIZE)
    return -1;

  sector += pi->SectorsPerFat;
  if (read_sector(sector, buf) != SECTORSIZE)
    return -1;

  /* set the next cluster for from_cluster to to_cluster */
  pi->op->set_next_cluster(buf + offset, to_cluster, pi);

  if (write_sector(sector, buf) != SECTORSIZE)
    return -1;


  return 0;
}
