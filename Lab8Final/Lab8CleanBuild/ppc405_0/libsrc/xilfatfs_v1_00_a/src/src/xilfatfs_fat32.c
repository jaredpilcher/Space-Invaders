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

UINT32 get_fat32_sector_for_cluster(UINT32 cluster, PartitionInfo *pi)
{
  /* Each FAT entry takes 4 bytes in FAT 32 */
  return ((cluster * 4) / SECTORSIZE) + pi->FatSector;
}

UINT32 get_fat32_offset_for_cluster(UINT32 cluster, PartitionInfo *pi)
{
  /* Each FAT entry takes 4 bytes in FAT 32 */
  return ((cluster * 4) % SECTORSIZE);
}

UINT32 get_next_cluster_fat32(BYTE *fat_entry, PartitionInfo *pi)
{
  return 0x0FFFFFFF & make_UINT32(*(fat_entry + 3),
                                  *(fat_entry + 2), 
                                  *(fat_entry + 1), 
                                  *(fat_entry));
}

void set_next_cluster_fat32(BYTE *fat_entry, UINT32 next_cluster, PartitionInfo *pi)
{
  UINT32 old_entry;

  /* extract the higher order 4 bits from old entry */
  old_entry = 0xf0000000 & make_UINT32(*(fat_entry + 3),
                                       *(fat_entry + 2), 
                                       *(fat_entry + 1), 
                                       *(fat_entry));

  next_cluster &= 0x0fffffff;
  next_cluster |= old_entry;

  write_UINT32(fat_entry, next_cluster);
}

int is_eoc_fat32(UINT32 cluster, PartitionInfo *pi) 
{
  return (cluster >= FAT32_EOC);
}

int is_valid_cluster_fat32(UINT32 cluster, PartitionInfo *pi)
{
  return (cluster < MAX_FAT32_CLUSTERS);
}

fat_ops fat32_ops = { 
  get_fat32_sector_for_cluster, 
  get_fat32_offset_for_cluster,
  get_next_cluster_fat32,
  set_next_cluster_fat32,
  is_eoc_fat32,
  is_valid_cluster_fat32,
  next_cluster_generic,
  free_cluster_chain_generic,
  allocate_one_cluster_generic,
  link_cluster_generic,
};
