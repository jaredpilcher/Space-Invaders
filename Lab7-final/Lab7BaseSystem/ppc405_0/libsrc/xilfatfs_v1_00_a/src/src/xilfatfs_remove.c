/////////////////////////////////////////////////////////////////////////-*-C-*- 
//
// Copyright (c) 2006 Xilinx, Inc.  All rights reserved.
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

#include <string.h>
#include "alloc.h"
#include "fat.h"
#include "filestatus.h"
#include "sysace_stdio.h"
#include "util.h"
#include "xilfatfs_errno.h"

int sysace_remove_entry(const char *path, int is_dir)
{
	WorkingDirectory *wd = NULL;
	BYTE dir_buf[SECTORSIZE];
	DirectoryEntry *de;

	wd = _build_working_directory_stack(path, is_dir, 0);
	if (!wd)	/* unable to locate */
		return XILFATFS_ENOENT;
	
	if (is_dir) {	
		if (wd->parent == NULL) {
			/* cannot delete root directory */
			return XILFATFS_EINVALID;
		}

		/* make sure directory is empty (only "." and ".." entries) 
		 * before deleting it 
		 */
		if (!is_dir_empty(wd))
			return XILFATFS_DIRNOTEMPTY;
	}

	/* truncate file contents */
	if (is_dir || wd->v.child.FileSize != 0) {
		/* if this is a pre-existing file (size != 0), then truncate it */
		debug_xil_printf("File already exists..size = %d\n\r", 
				(unsigned int)wd->v.child.FileSize);
		if (truncate_file(wd->v.child.FirstCluster, wd->pi) < 0)
			return 0;

		/* change filesize to 0.
		 * the directory entry is not changed yet 
		 */	
		wd->v.child.FileSize = 0;
		debug_xil_printf("%s @ %d, file truncated\n\r", __FUNCTION__, __LINE__);
	}

	/* delete the entry */
	/* read directory entry for this file. the directory entry
	 * is updated at the end with the new file size 
	 */
	if (read_sector(wd->v.child.DirLocation.sector, dir_buf) != SECTORSIZE)
		return XILFATFS_EIO;
	de = (DirectoryEntry *) (dir_buf + wd->v.child.DirLocation.offset);
	update_de_firstcluster(de, 0xFFFFFFF8, wd->pi);
	de->Name[0] = 0xe5;	/* mark as erased */

	/* write back the directory entry */
	if (write_sector(wd->v.child.DirLocation.sector, dir_buf) != SECTORSIZE) {
		/* in this case, we were able to read the directory entry
		 * but not write to it. the fs is in an inconsistent state
		 * since the FAT has been altered, but filesize not updated
		 * in the directory entry */
		return XILFATFS_EIO;
	}
#ifdef XILFATFS_BUFCACHE
	sync_bufcache();
#endif

	return 0;
}

int sysace_remove_file(const char *path)
{
	return sysace_remove_entry(path, 0);
}

int sysace_remove_dir(const char *path)
{
	return sysace_remove_entry(path, 1);
}
