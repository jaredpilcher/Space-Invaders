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


#ifndef __PART_H_
#define __PART_H_

#define MAXPARTITION       4        /* Maximum number of partitions */

typedef struct _PartitionEntry {
	BYTE  x86DefaultBP;
	BYTE  startHead;
	BYTE  StartSector;
	BYTE  StartCyclinder;
	BYTE  PartitionEntryType;   /* Describes Partition Type FAT12, 16 */
	BYTE  EndHead;
	BYTE  EndSector;
	BYTE  EndCyclinder;
	BYTE  PartitionSector[4];
	BYTE  TotalSectors[4];      /* partition size */
} __attribute__((packed)) PartitionEntry;

typedef struct  _MasterBootRecord { 
	BYTE            BootCode[446];
	PartitionEntry  PartitionEntryArray[MAXPARTITION];
	BYTE            Signature[2];
} __attribute__((packed)) MasterBootRecord;

#endif
