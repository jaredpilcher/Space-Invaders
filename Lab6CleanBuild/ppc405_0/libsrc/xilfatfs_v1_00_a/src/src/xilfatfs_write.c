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

#include <string.h>

#include "alloc.h"
#include "fat.h"
#include "filestatus.h"
#include "sysace.h"
#include "sysace_stdio.h"
#include "util.h"

/* write_to_file:
 * 	Write from the current position in chunks of sectors.
 * 	Update the file size in the directory entry
 * 	Update FAT if a new cluster is added
 */
int write_to_file(FileStatus *fs, BYTE *buf, int count)
{
	int writecount, n;
	int remaining;
	BYTE sectorbuf[SECTORSIZE], dir_buf[SECTORSIZE];
	UINT32 sector;
	UINT32 nsectors;
	UINT32 sector_offset;
	UINT32 filesize;
	int byte_offset;
	PartitionInfo *pi = fs->wd->pi;
	UINT32 next_cluster;
	DirectoryEntry *de;

	/* Safety check */
	if (fs == 0 || !fs->write || count <= 0)
		return 0;

	filesize = fs->wd->v.child.FileSize;
	debug_xil_printf("Original file size: %d\n\r", (int)filesize);
	writecount = 0;		/* written til now */
	remaining = count;	/* remaining left to write */

	/* read directory entry for this file. the directory entry
	 * is updated at the end with the new file size 
	 */
	if (read_sector(fs->wd->v.child.DirLocation.sector, dir_buf) != SECTORSIZE)
		return -1;
	de = (DirectoryEntry *) (dir_buf + fs->wd->v.child.DirLocation.offset);

	/* if this is the first byte of the file, then the firstcluster
	 * entry for it should be set in its directory entry
	 */
	if (filesize == 0) {
		fs->wd->v.child.FirstCluster = pi->op->allocate_one_cluster(pi);
		if (fs->wd->v.child.FirstCluster == 0)
			return 0;	/* out of space */

		fs->CurrentCluster = fs->wd->v.child.FirstCluster;
		fs->PositionInCluster = fs->PositionInFile = 0;

		/* set the first cluster entry in the directory entry */
		debug_xil_printf("First cluster set to: %d\n\r", (int)fs->CurrentCluster);
		update_de_firstcluster(de, fs->CurrentCluster, pi);
	}

	/* if we are currently in the middle of a sector, then read in
	 * the contents before writing into it. 
	 */

	/* Which byte of that sector did we leave off at last time ? */
	byte_offset = fs->PositionInCluster % SECTORSIZE;

	if (byte_offset) {
		debug_xil_printf("%s @ %d: byte_offset = %d\n\r", __FUNCTION__,
				__LINE__, byte_offset);
		/* Which sector of this cluster did we leave off at last time ? */
		sector_offset = fs->PositionInCluster / SECTORSIZE;

		/* Sector address to start writing this time */
		sector = starting_sector(fs->CurrentCluster, pi);
		if (sector == 0) { /* FAT problem ? */
			return 0;
		}
		sector += sector_offset;

		if (read_sector(sector, sectorbuf) != SECTORSIZE)
			return -1;

		n = SECTORSIZE - byte_offset;
		if (remaining < n)
			n = remaining;
		memcpy(sectorbuf + byte_offset, buf + writecount, n);

		if (write_sector(sector, sectorbuf) != SECTORSIZE) {
			/* nothing has changed. return error */
			return -1;
		}

		/* we have written n bytes. update all fields accordingly */
		filesize += n;
		writecount += n;
		remaining -= n;
		fs->PositionInCluster += n;
	}

	/* now we are sector aligned. keep writing sector
	 * sized chunks. allocate a new cluster when needed 
	 */
	while (remaining > 0) {
		/* Which sector of this cluster did we leave off at last time ? */
		sector_offset = fs->PositionInCluster / SECTORSIZE;

		/* Sector address to start writing this time */
		sector = starting_sector(fs->CurrentCluster, pi);
		if (sector == 0) {
			/* FAT problem ? */
			return 0;
		}
		sector += sector_offset;

		/* How many sectors left to write in this cluster */
		nsectors = pi->SectorsPerCluster - sector_offset;

		while (nsectors) {
			if (remaining <= SECTORSIZE) {
				debug_xil_printf("%s @ %d: last write of file data, remaining = %d\n\r", 
						__FUNCTION__, __LINE__, remaining);
				/* the remaining data fits in this sector */
				memcpy((char *) sectorbuf,
						buf + writecount, remaining);
				if (write_sector(sector, sectorbuf) != SECTORSIZE)
					goto update_dentry;

				fs->PositionInFile += remaining;
				fs->PositionInCluster += remaining;
				filesize += remaining;
				writecount += remaining;
				remaining = 0;

				/* go and update the directory entry */
				goto update_dentry;
			}

			/* End of file is beyond this sector */
			n = SECTORSIZE;
			if (write_sector(sector, buf + writecount) != SECTORSIZE)
				goto update_dentry;

			fs->PositionInFile += n;
			fs->PositionInCluster += n;
			filesize += n;
			writecount += n;
			remaining -= n;

			/* Point to start of next sector in cluster */
			sector += 1;
			nsectors -= 1;
		}	

		/* Done with that cluster, advance to the next one */
		if ((next_cluster = pi->op->allocate_one_cluster(pi)) == 0) {
			/* no more free clusters, update directory
			 * with whatever was written */
			goto update_dentry;
		}

		/* link the current cluster to the next cluster in FAT */
		if (pi->op->link_cluster(fs->CurrentCluster, next_cluster, pi) < 0)
			goto update_dentry; /* error linking cluster chain */

		/* start using the new cluster */
		fs->CurrentCluster = next_cluster;
		fs->PositionInCluster = 0;
	}

update_dentry:
	/* update the file size in the directory entry */
	update_de_filesize(de, filesize);

	/* update filesize in file status */
	fs->wd->v.child.FileSize = filesize;

	/* write back the directory entry */
	if (write_sector(fs->wd->v.child.DirLocation.sector, dir_buf) != SECTORSIZE) {
		/* in this case, we were able to read the directory entry
		 * but not write to it. the fs is in an inconsistent state
		 * since the FAT has been altered, but filesize not updated
		 * in the directory entry */
		return -1;
	}

	return writecount;
}

int sysace_fwrite(void *buffer, int size, int count, SYSACE_FILE * stream)
{
	FileStatus *fs = find_file_status(stream);

	if (fs == 0)
		return -1;

	return write_to_file(fs, (BYTE *) buffer, size * count);
}

/* create an entry for the file name.ext in parent directory */
WorkingDirectory *create_file_entry(const char *name, const char *ext,
                                    WorkingDirectory *parent, BYTE attributes)
{
	BYTE buf[SECTORSIZE];
	WorkingDirectory *wd;
	int de;
	UINT32 firstcluster;
	UINT32 filesize;
	UINT32 de_sector;
	UINT32 de_offset;
	DirectoryEntry dir_entry;
	PartitionInfo *pi = parent->pi;

	/* find a free directory entry */
	if ((de = find_in_directory(parent, NULL, NULL, &firstcluster,
					&filesize, &de_sector, &de_offset)) == 0)
		return 0;	/* no free entries available */

	filesize = firstcluster = 0;

#ifdef CONFIG_DIR_SUPPORT
	/* when creating a directory, two special directories (. & ..) within 
	 * that directory should always be created
	 */
	if ((attributes & ATTR_DIRECTORY) == ATTR_DIRECTORY) {
		UINT32 sector, parent_cluster;
		int i;

		firstcluster = pi->op->allocate_one_cluster(pi);
		debug_xil_printf("firstcluster for dir: %ld\n", firstcluster);
		if (firstcluster == 0)	
			return 0;	/* no free space */

		/* zero out all sectors in the allotted cluster */
		memset(buf, 0, sizeof buf);
		sector = starting_sector(firstcluster, pi);
		debug_xil_printf("sectors starting from: %ld\n", sector);
		for (i = 1, sector++; 	/* the first sector needs to have dot, dotdot entries
					 * and will be filled in later */
				i < pi->SectorsPerCluster; 
				i++, sector++)
			if (write_sector(sector, buf) != SECTORSIZE)
				return 0;	/* disk error */

		/* create dot & dotdot entries for the directory */

		/* the dot entry points to itself */
		initialize_de(dotdot_entry, ".", "", firstcluster, 0, pi, ATTR_DIRECTORY);

		/* the dotdot entry should point to the parent of the new directory */
		parent_cluster = parent->v.child.FirstCluster;
		if (parent->parent == NULL)	/* root */
			parent_cluster = 0;
		debug_xil_printf("parent cluster = %ld\n", parent_cluster);
		initialize_de(dotdot_entry+1, "..", "", parent_cluster, 0, pi, ATTR_DIRECTORY);

		memcpy(buf, dotdot_entry, sizeof(DirectoryEntry)*2);
		sector = starting_sector(firstcluster, pi);
		if (write_sector(sector, buf) != SECTORSIZE)
			return 0;
	}
#endif

	initialize_de(&dir_entry, (char *)name, (char *)ext, firstcluster, filesize, 
			pi, attributes);

	/* allocate a wd structure to hold the working directory info*/
	if ((wd = malloc_wd(name)) == 0)
		return 0;

	/* 1. read in the whole sector */
	if (read_sector(de_sector, buf) != SECTORSIZE)
		return 0;

	/* 2. write the new directory entry */
	memcpy(buf + de_offset, (char*)&dir_entry, sizeof dir_entry);

	/* 3. write out the whole sector */
	if (write_sector(de_sector, buf) != SECTORSIZE)
		return 0;

	wd->v.child.FirstCluster = firstcluster;
	wd->v.child.FileSize = filesize;
	wd->v.child.DirLocation.sector = de_sector;
	wd->v.child.DirLocation.offset = de_offset;
	wd->pi = parent->pi;
	wd->parent = parent;
	return wd;
}
