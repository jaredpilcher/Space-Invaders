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

UINT32 get_fat16_sector_for_cluster(UINT32 cluster, PartitionInfo *pi)
{
  /* Each FAT entry takes 2 bytes in FAT 16 */
  return ((cluster * 2) / SECTORSIZE) + pi->FatSector;
}

UINT32 get_fat16_offset_for_cluster(UINT32 cluster, PartitionInfo *pi)
{
  /* Each FAT entry takes 2 bytes in FAT 16 */
  return ((cluster * 2) % SECTORSIZE);
}

UINT32 get_next_cluster_fat16(BYTE *fat_entry, PartitionInfo *pi)
{
  return (UINT32)(0xffff & make_UINT16(*(fat_entry + 1), *(fat_entry)));
}

void set_next_cluster_fat16(BYTE *fat_entry, UINT32 next_cluster, PartitionInfo *pi)
{
  write_UINT16(fat_entry, next_cluster);
}

int is_eoc_fat16(UINT32 cluster, PartitionInfo *pi) 
{
  return (cluster >= FAT16_EOC);
}

int is_valid_cluster_fat16(UINT32 cluster, PartitionInfo *pi)
{
  return (cluster < MAX_FAT16_CLUSTERS);
}

fat_ops fat16_ops = { 
  get_fat16_sector_for_cluster, 
  get_fat16_offset_for_cluster, 
  get_next_cluster_fat16,
  set_next_cluster_fat16,
  is_eoc_fat16,
  is_valid_cluster_fat16,
  next_cluster_generic,
  free_cluster_chain_generic,
  allocate_one_cluster_generic,
  link_cluster_generic,
};


