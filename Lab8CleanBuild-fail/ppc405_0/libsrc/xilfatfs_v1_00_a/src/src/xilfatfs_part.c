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

#include <ctype.h>
#include <string.h>
#include "fat.h"
#include "directory.h"
#include "util.h"

/* The partition info buffers can be statically allocated.
 * Never free a pi !
 */
static PartitionInfo pibuf[MAXPARTITION];

/* Make a new PartitionInfo structure and populate it */
PartitionInfo *get_partition_info(int partition)
{
  BYTE buf[SECTORSIZE];
  MasterBootRecord *mbr;
  PartitionEntry *pe;
  PartitionBootRecord *pbr;
  UINT16 total16;
  UINT32 total32;
  UINT16 reserved;
  UINT32 partitionSize, rootSize, dataClusters, dataOffset, fatSize;
  PartitionInfo *pi;

  static int sysace_initialized = 0, partition_warning = 0;

  if (partition < 0 || partition >= MAXPARTITION)
    return 0;

  pi = pibuf + partition;
  pi->PartitionNum = partition;

  if (!sysace_initialized) {	/* initialize sysace the first time around */
	  if (init_ace() < 0)
		  return 0;
	  sysace_initialized = 1;
  }
	
  /* Master Boot Record is always sector 0 */
  if (read_sector(0, buf) != SECTORSIZE)
    return 0;
  mbr = (MasterBootRecord *) buf;

  /* Check Signature */
  if (mbr->Signature[0] != 0x55 || mbr->Signature[1] != 0xaa)
    return 0;

  /* Point to the Relevant Partition Entry */
  pe = &(mbr->PartitionEntryArray[partition]);

  pi->StartSector =
    make_UINT32(pe->PartitionSector[3], pe->PartitionSector[2],
                pe->PartitionSector[1], pe->PartitionSector[0]);

  partitionSize =
    make_UINT32(pe->TotalSectors[3], pe->TotalSectors[2],
                pe->TotalSectors[1], pe->TotalSectors[0]);
	
  /* Read the Partition Boot Record */
  if (read_sector(pi->StartSector, buf) != SECTORSIZE)
    return 0;

  pbr   = (PartitionBootRecord *)   buf;

  /* Determine the total number of sectors in this partition
   * It may be specified in 16 or 32 bits */
  total16 =
    make_UINT16(pbr->BPB.TotalSectors16[1],
                pbr->BPB.TotalSectors16[0]);
  total32 =
    make_UINT32(pbr->BPB.TotalSectors32[3],
                pbr->BPB.TotalSectors32[2],
                pbr->BPB.TotalSectors32[1],
                pbr->BPB.TotalSectors32[0]);
  if (total16) {
    if (total32 != 0 && total32 != total16)
      return 0;
    pi->TotalSectors = (UINT32) total16;
  } else {
    if (total32 == 0)
      return 0;
    pi->TotalSectors = total32;
  }

  if (pi->TotalSectors > partitionSize) {
	  if (!partition_warning) {
		  xil_printf("Partition size according to partition table = %d\n", partitionSize);
		  xil_printf("However this partition (%d) has more sectors (%d) than the partition size.\n",
				  partition, pi->TotalSectors);
		  partition_warning = 1;
	  }
  }

  pi->BytesPerSector = make_UINT16(pbr->BPB.BytesPerSector[1],
                                   pbr->BPB.BytesPerSector[0]);

  /* Check against compile-time constants
   * currently allow only 512 bytes per sec */
  if (pi->BytesPerSector != SECTORSIZE)
    return 0;

  pi->SectorsPerCluster = pbr->BPB.SectorsPerCluster;
  if (pi->SectorsPerCluster == 0) {
    /* Protect division later on! */
    return 0;
  }
  /* sanity check for SectorsPerCluster: 
   *	should be a power of 2
   *	should be <= 128
   *	should be such that bytes per cluster <= 32k (MAX_BYTES_PER_CLUSTER)
   */
  if (pi->SectorsPerCluster & (pi->SectorsPerCluster - 1))
    return 0;
  if (pi->SectorsPerCluster > 128)
    return 0;
  if (pi->SectorsPerCluster * pi->BytesPerSector > MAX_BYTES_PER_CLUSTER)
    return 0;

  reserved = make_UINT16(pbr->BPB.ReservedSector[1],
                         pbr->BPB.ReservedSector[0]);

  pi->NumberOfFats = pbr->BPB.NumberOfFats;

  pi->RootDirCount = make_UINT16(pbr->BPB.RootDirCount[1],
                                 pbr->BPB.RootDirCount[0]);

  pi->SectorsPerFat = (UINT32) make_UINT16(pbr->BPB.SectorsPerFat[1],
                                           pbr->BPB.SectorsPerFat[0]);

  if (pi->SectorsPerFat == 0) {
    /* check if the fat32 entry is present
     * if not then this is invalid FAT
     */
    pi->SectorsPerFat = make_UINT32(pbr->BPB.SectorsPerFat_32[3], 
                                    pbr->BPB.SectorsPerFat_32[2], 
                                    pbr->BPB.SectorsPerFat_32[1], 
                                    pbr->BPB.SectorsPerFat_32[0]);
    if (pi->SectorsPerFat == 0)
      return 0;
  }

  /* Determine the FAT type based on the # of data clusters */
  rootSize =
    ((pi->RootDirCount << LOG2_DIRENT_SIZE) + SECTORSIZE -
     1) / SECTORSIZE;
  fatSize = pi->SectorsPerFat * pi->NumberOfFats;
  dataOffset = reserved + fatSize + rootSize;
  dataClusters =
    (pi->TotalSectors - dataOffset) / pi->SectorsPerCluster;

  if (dataClusters < MAX_FAT12_CLUSTERS) {
    debug_print("FAT12 PARTITION\n\r");
    pi->FatType = FAT12;
#ifdef CONFIG_FAT12
    pi->op = &fat12_ops;
#else
    pi->op = NULL;
#endif
  } else if (dataClusters < MAX_FAT16_CLUSTERS) {
    debug_print("FAT16 PARTITION\n\r");
    pi->FatType = FAT16;
    pi->op = &fat16_ops;
  } else {
    pi->FatType = FAT32;
    debug_print("FaT32 PARTITION\n\r");
    pi->op = &fat32_ops;
  }

  /* more consistency checks */
  switch (pi->FatType) {
  case FAT12:
  case FAT16:
    if (reserved != 1)
      return 0;

    /* pi->RootDirCount * 32 should be an even multiple 
     * of BytesPerSector */
    if ((pi->RootDirCount * 32) % pi->BytesPerSector)
      return 0;
    if (((pi->RootDirCount * 32) / pi->BytesPerSector) % 2)
      return 0;
    break;
  case FAT32:
    if (pi->RootDirCount != 0)
      return 0;
    break;
  default:
    return 0;
  }

  pi->FatSector = pi->StartSector + reserved;
  pi->RootDirSector = pi->FatSector + fatSize;
  pi->DataSector = pi->RootDirSector + rootSize;

  if (pi->FatType == FAT32) {
    pi->RootCluster = make_UINT32(pbr->BPB.RootCluster[3], 
                                  pbr->BPB.RootCluster[2], 
                                  pbr->BPB.RootCluster[1], 
                                  pbr->BPB.RootCluster[0]);
  }

  return pi;
}
