/////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2004 Xilinx, Inc.  All rights reserved.
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

#ifndef __FSINFO_H_
#define __FSINFO_H_

#include <fatops.h>


#ifdef __cplusplus
extern "C" {
#endif

/* Structures for internal use */
typedef enum _FSType { FAT12, FAT16, FAT32 } FSType;

/* This hold pertinent information about a partition.
 * This can only be created if the partition is FAT
 * and all parameters are valid.
 */
typedef struct _PartitionInfo { 	
	int     PartitionNum;
	UINT32  StartSector;
	UINT32  TotalSectors;
	UINT16  BytesPerSector;
	BYTE    SectorsPerCluster;
	UINT32  SectorsPerFat;
	BYTE    NumberOfFats;
	UINT16  RootDirCount;
	UINT32  FatSector;
	UINT32  RootDirSector;
	UINT32  DataSector;

	FSType	FatType;
	UINT32  RootCluster;	/* used only for FAT32 */

	fat_ops	*op;
} PartitionInfo;


#ifdef __cplusplus
}
#endif

#endif
