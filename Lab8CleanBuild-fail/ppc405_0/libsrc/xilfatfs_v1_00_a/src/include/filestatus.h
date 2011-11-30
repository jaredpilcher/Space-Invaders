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

#ifndef __FILESTATUS_H_
#define __FILESTATUS_H_

#include "fat.h"
#include "sysace_stdio.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct _FileStatus { 
	WorkingDirectory *wd;
	BYTE read;
	BYTE write;
	UINT32 CurrentCluster;
	UINT32 PositionInCluster; // Bytes from start of cluster
	UINT32 PositionInFile;    // Bytes from start of file
	struct _FileStatus *next;
	int reserved;             // Reserved for allocation code
} FileStatus;

FileStatus *find_file_status(SYSACE_FILE *stream);
FileStatus *create_file_status(WorkingDirectory * wd,
				      BYTE read, BYTE write);
int delete_file_status(FileStatus * status);


#ifdef __cplusplus
}
#endif

#endif
