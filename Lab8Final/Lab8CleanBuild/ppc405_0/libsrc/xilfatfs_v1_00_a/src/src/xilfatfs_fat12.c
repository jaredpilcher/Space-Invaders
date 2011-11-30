/////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////

#include "fat.h"
#include "directory.h"
#include "util.h"

/* given the cluster #, find the sector in the partition where
 * the FAT entry for that cluster is present 
 */
UINT32 get_fat12_sector_for_cluster(UINT32 cluster, PartitionInfo *pi)
{
  /* Each FAT entry takes 1.5 bytes in FAT 12 */
  return ((cluster + cluster/2) / SECTORSIZE) + pi->FatSector;
}

/* given the cluster #, find the offset in the sector in the partition where
 * the FAT entry for that cluster is present 
 */
UINT32 get_fat12_offset_for_cluster(UINT32 cluster, PartitionInfo *pi)
{
  return ((cluster + cluster/2) % SECTORSIZE);
}

/* given the address (fat_entry) where the FAT entry for a cluster
 * is present, return the next cluster for that entry
 */
UINT32 get_next_cluster_fat12(BYTE *fat_entry, PartitionInfo *pi, UINT32 cluster)
{
  UINT32 tmp_next_cluster;

  /* We need 12 bits from the 2 bytes - so first read in the 2 bytes */
  tmp_next_cluster = (UINT32) make_UINT16(*(fat_entry + 1), *(fat_entry));
  if (cluster & 0x1) /* if cluster is odd, we take the higher 12 bits */
    tmp_next_cluster >>= 4;
  else		   /* else we take the lower 12 bits */
    tmp_next_cluster &= 0xFFF;

  return tmp_next_cluster;
}

/* given the address (fat_entry) where the FAT entry for a cluster
 * is present, set the next cluster entry to next_cluster
 */
void set_next_cluster_fat12(BYTE *fat_entry, 
                            UINT32 next_cluster, 
                            PartitionInfo *pi, 
                            UINT32 cluster)
{
  UINT16 old_entry = make_UINT16(*(fat_entry+1), *(fat_entry));
  UINT32 new_entry;

  if (cluster & 0x1) { /* if cluster is odd, we need to update the higher 12 bits */
    new_entry = (next_cluster << 4) | (old_entry & 0xF);
    write_UINT16(fat_entry, new_entry);
  } else {	     /* else write the lower order 12 bits */
    new_entry = (next_cluster & 0xFFF) | (old_entry & 0xF000);
    write_UINT16(fat_entry, new_entry);
  }
}

/* find if this is the end of cluster mark */
int is_eoc_fat12(UINT32 cluster, PartitionInfo *pi) 
{
  return (cluster >= FAT12_EOC);
}

int is_valid_cluster_fat12(UINT32 cluster, PartitionInfo *pi)
{
  return (cluster < MAX_FAT12_CLUSTERS);
}

/* next_cluster_fat12: given a cluster number, return the 
 * cluster that is next in this cluster chain by looking
 * into the FAT data structure for this partition
 *
 * For FAT12, each entry in the FAT is 1.5 bytes = 12 bits.
 * This results in two complications:
 * 	1. A single FAT entry may span two sectors.
 * 	2. After reading in 16 bits, 12 bits must be extracted
 * 	depending on whether the cluster # is even or odd.
 */
UINT32 next_cluster_fat12(UINT32 cluster, PartitionInfo * pi)
{
  BYTE buf[SECTORSIZE*2];
  UINT32 TempNextCluster;
  UINT32 Fat0SectorNum;
  UINT32 Fat1SectorNum;
  int NextClusterPosition;

  if (cluster > MAX_FAT12_CLUSTERS)
    return BAD_CLUSTER;

  Fat0SectorNum = pi->op->get_fat_sector_for_cluster(cluster, pi);
  NextClusterPosition = pi->op->get_fat_offset_for_cluster(cluster, pi);

  if (read_sector(Fat0SectorNum, buf) != SECTORSIZE)
    return BAD_CLUSTER;

  /* Additionally (as compared to FAT 16/32 we have to see if the entry
   * spans a sector boundary, and if so read in the next sector. 
   */
  if (NextClusterPosition == SECTORSIZE - 1)
    if (read_sector(Fat0SectorNum + 1, buf + SECTORSIZE) != SECTORSIZE)
      return BAD_CLUSTER;

  TempNextCluster = get_next_cluster_fat12(buf + NextClusterPosition, pi, cluster);

  /* check for FAT misMatch !!! */
  if (pi->NumberOfFats > 1) {
    UINT32 FAT1_TempNextCluster = 0;

    Fat1SectorNum = Fat0SectorNum + pi->SectorsPerFat;

    if (read_sector(Fat1SectorNum, buf) != SECTORSIZE)
      return 0;
    if (NextClusterPosition == SECTORSIZE - 1)
      if (read_sector(Fat0SectorNum + 1, buf + SECTORSIZE) != SECTORSIZE)
        return BAD_CLUSTER;

    FAT1_TempNextCluster = get_next_cluster_fat12(buf + NextClusterPosition, pi, cluster);

    if (TempNextCluster != FAT1_TempNextCluster)
      return BAD_CLUSTER;	/* FAT tables don't match bail */
  }

  return (TempNextCluster);
}

/* Follow the cluster chain in FAT12 and free all allotted clusters. */
int free_cluster_chain_fat12(UINT32 cluster, PartitionInfo *pi)
{
  UINT32 sector_in_buf = 0;
  UINT32 sector, offset, old_cluster;
  int modified = 0;	/* denotes if the sector_in_buf has been modified */
  int used_second_sector = 0; /* denotes if a 2nd sector was read & modified */
  char buf[SECTORSIZE*2];

  while (!pi->op->is_eoc(cluster, pi)) {
    sector = pi->op->get_fat_sector_for_cluster(cluster, pi);
    debug_xil_printf("%d: cluster: %d is at sector: %d\n\r", __LINE__, 
                     (int)cluster, (int)sector);
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

        /* if the writes had spanned 2 sectors, then write out 
         * the 2nd sector too 
         */
        if (used_second_sector) {
          if (write_sector(sector_in_buf, 
                           buf + SECTORSIZE) != SECTORSIZE)
            return -1;

          /* update FAT 2 */
          if (pi->NumberOfFats > 1)
            if (write_sector(sector_in_buf + pi->SectorsPerFat, 
                             buf + SECTORSIZE) != SECTORSIZE)
              return -1;

          used_second_sector = 0;
        }
        debug_xil_printf("written modified sec %d\n", (unsigned int)sector_in_buf);
        modified = 0;
      }

      debug_xil_printf("%s @ %d, reading in new sector\n\r", 
                       __FUNCTION__, __LINE__);
      /* read in the new sector */
      if (read_sector(sector, buf) != SECTORSIZE)
        return -1;

      sector_in_buf = sector;
    }

    offset = pi->op->get_fat_offset_for_cluster(cluster, pi);
    if (offset == SECTORSIZE - 1) {	/* FAT entry spans sector boundary */
      if (read_sector(sector, buf + SECTORSIZE) != SECTORSIZE)
        return 0;
      used_second_sector = 1;
    }

    /* obtain the current value & reset it to zero */
    old_cluster = cluster;
    cluster = get_next_cluster_fat12(buf + offset, pi, cluster);
    set_next_cluster_fat12(buf + offset, 0, pi, old_cluster);
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

    /* if the writes had spanned 2 sectors, then write out 
     * the 2nd sector too 
     */
    if (used_second_sector) {
      if (write_sector(sector_in_buf, 
                       buf + SECTORSIZE) != SECTORSIZE)
        return -1;

      /* update FAT 2 */
      if (pi->NumberOfFats > 1)
        if (write_sector(sector_in_buf + pi->SectorsPerFat, 
                         buf + SECTORSIZE) != SECTORSIZE)
          return -1;

      used_second_sector = 0;
    }

    debug_xil_printf("written modified sec %d\n", (unsigned int)sector_in_buf);
    modified = 0;
  }
			
  return 0;
}

int link_cluster_fat12(UINT32 from_cluster, UINT32 to_cluster, PartitionInfo *pi)
{
  UINT32 sector = pi->op->get_fat_sector_for_cluster(from_cluster, pi);
  UINT32 offset = pi->op->get_fat_offset_for_cluster(from_cluster, pi);
  BYTE buf[SECTORSIZE*2];
	
  if (read_sector(sector, buf) != SECTORSIZE)
    return -1;
  if (offset == SECTORSIZE - 1) {	
    /* read in next sector if this FAT entry spans two sectors */
    if (read_sector(sector + 1, buf + SECTORSIZE) != SECTORSIZE)
      return -1;
  }

  /* set the next cluster for from_cluster to to_cluster */
  set_next_cluster_fat12(buf + offset, to_cluster, pi, from_cluster);

  if (write_sector(sector, buf) != SECTORSIZE)
    return -1;
  if (offset == SECTORSIZE - 1) 
    if (write_sector(sector + 1, buf + SECTORSIZE) != SECTORSIZE)
      return -1;
	
  /* update 2nd FAT if present */
  if (pi->NumberOfFats > 1) {
    if (write_sector(sector + pi->SectorsPerFat, buf) != SECTORSIZE)
      return -1;
    if (offset == SECTORSIZE - 1) 
      if (write_sector(sector + 1 + pi->SectorsPerFat, buf + SECTORSIZE) 
          != SECTORSIZE)
        return -1;
	

  }

  return 0;
}

/* find a free cluster, set the next entry of that cluster to EOC
 * and return that cluster.
 */
UINT32 allocate_one_cluster_fat12(PartitionInfo *pi)
{
  UINT32 cluster = 0;

  for (cluster = 2; 
       cluster < (pi->TotalSectors/pi->SectorsPerCluster); 
       cluster++)
    if (next_cluster(cluster, pi) == 0) {
      link_cluster_fat12(cluster, FAT12_EOC, pi);
      return cluster;
    }

  return 0;
}

fat_ops fat12_ops = { 
  get_fat12_sector_for_cluster, 
  get_fat12_offset_for_cluster,
  0,
  0,
  is_eoc_fat12,
  is_valid_cluster_fat12,
  next_cluster_fat12,
  free_cluster_chain_fat12,
  allocate_one_cluster_fat12,
  link_cluster_fat12,
};
