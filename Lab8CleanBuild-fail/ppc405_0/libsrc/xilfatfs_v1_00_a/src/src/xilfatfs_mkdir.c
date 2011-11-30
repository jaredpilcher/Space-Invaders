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

#include "bufcache.h"
#include "fat.h"
#include "filespec.h"
#include "directory.h"
#include "util.h"

DirectoryEntry dotdot_entry[2];

int sysace_mkdir(const char *path)
{
	WorkingDirectory *wd = build_working_directory_stack(path, 1, 0);
	if (wd) { /* directory already exists */
		delete_working_directory_stack(wd);
		return -1;
	}

	wd = build_working_directory_stack(path, 1, 1);

	if (wd) {	/* create dir succeeded */
		delete_working_directory_stack(wd);
#ifdef XILFATFS_BUFCACHE
		sync_bufcache();
#endif
		return 0;
	} else
		return -1;
}
