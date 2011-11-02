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

#ifndef __DIRECTORY_H_
#define __DIRECTORY_H_

#include "fsinfo.h"

#define DIRENT_SIZE       32        // Directory entry size in bytes
#define LOG2_DIRENT_SIZE   5

/* File attributes */
#define ATTR_ARCHIVE        0x20
#define ATTR_DIRECTORY      0x10
#define ATTR_VOLUME_ID      0x08
#define ATTR_SYSTEM         0x04
#define ATTR_HIDDEN         0x02
#define ATTR_READ_ONLY      0x01

#define ATTR_LONG_NAME      (ATTR_READ_ONLY|ATTR_HIDDEN|ATTR_SYSTEM|ATTR_VOLUME_ID)
#define ATTR_LONG_NAME_MASK (ATTR_LONG_NAME|ATTR_DIRECTORY|ATTR_ARCHIVE)


#ifdef __cplusplus
extern "C" {
#endif

typedef struct _DirectoryEntry {
	BYTE    Name[8];
	BYTE    Extension[3];
	BYTE    Attributes;
	BYTE    Reserved[8];
	BYTE	FirstClusterOfFile_hi[2];
	BYTE    TimeStamp[2];
	BYTE    Date[2];
	BYTE    FirstClusterOfFile[2];
	BYTE    FileSize[4];
} __attribute__((packed)) DirectoryEntry;

/* Pointer to the sector/offset of the directory entry 
 * corresponding to a file 
 */
typedef struct _DirectoryEntryLocation {
	UINT32	sector;
	UINT32	offset;
} DirectoryEntryLocation;

void update_de_filesize(DirectoryEntry *de, UINT32 filesize);
void update_de_firstcluster(DirectoryEntry *de, UINT32 firstcluster, 
		PartitionInfo *pi);

#ifdef __cplusplus
}
#endif

#endif
