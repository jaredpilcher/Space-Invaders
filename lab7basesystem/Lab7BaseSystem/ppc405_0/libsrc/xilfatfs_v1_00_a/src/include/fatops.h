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

#ifndef __FAT_OPS_H_
#define __FAT_OPS_H_

#include <sysace.h>


#ifdef __cplusplus
extern "C" {
#endif

/* forward reference */
struct _PartitionInfo;

typedef struct _fat_ops {
	UINT32 (*get_fat_sector_for_cluster)(UINT32 cluster, struct _PartitionInfo *pi);
	UINT32 (*get_fat_offset_for_cluster)(UINT32 cluster, struct _PartitionInfo *pi);
	UINT32 (*get_next_cluster)(BYTE *fat_entry, struct _PartitionInfo *pi);
	void   (*set_next_cluster)(BYTE *fat_entry, UINT32 next_cluster, struct _PartitionInfo *pi);
	int    (*is_eoc)(UINT32 cluster, struct _PartitionInfo *pi); 
	int    (*is_valid_cluster)(UINT32 cluster, struct _PartitionInfo *pi);
	UINT32 (*next_cluster)(UINT32 cluster, struct _PartitionInfo * pi);
	int    (*free_cluster_chain)(UINT32 cluster, struct _PartitionInfo *pi);
	UINT32 (*allocate_one_cluster)(struct _PartitionInfo *pi);
	int    (*link_cluster)(UINT32 from_cluster, UINT32 to_cluster, struct _PartitionInfo *pi);
} fat_ops;

extern fat_ops fat12_ops, fat16_ops, fat32_ops;


#ifdef __cplusplus
}
#endif

#endif
