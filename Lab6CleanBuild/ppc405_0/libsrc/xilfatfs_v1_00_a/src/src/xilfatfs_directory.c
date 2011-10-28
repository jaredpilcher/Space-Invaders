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

#include <ctype.h>
#include <string.h>
#include "fat.h"
#include "filespec.h"
#include "alloc.h"
#include "directory.h"
#include "util.h"
#include "xilfatfs_errno.h"

int dir_name_compare(const char *a, const char *b, int n)
{
  char ac, bc;
  int an = strlen(a);

  while (an > 0 && *a) {
    ac = tolower(*a);
    bc = tolower(*b);

    if (ac < bc)
      return -1;
    if (ac > bc)
      return 1;

    ++a;
    ++b;
    --n;
    --an;
  }

  while (n > 0) {		/* finished text chars now check for trailing spaces */
    if (*b != ' ')
      return -1;

    ++b;
    --n;
  }

  if (n == 0)
    return 0;
  if (*b)
    return 1;

  return 0;
}

/* Locate the named file or directory in the specified working directory
 * The name is not hierarchical. Set ext = NULL to find a directory.
 * Set ext = name = NULL to find an free entry
 */
int find_in_directory(WorkingDirectory *wd, const char *name,
		      const char *ext, UINT32 * firstcluster,
		      UINT32 * filesize, UINT32 *de_sector, UINT32 *de_offset)
{
  BYTE buf[SECTORSIZE];
  int bufcount;
  int is_sub_dir = 0;
  UINT32 sector;
  UINT32 filecount;
  UINT32 nsectors;
  UINT32 cluster;
  DirectoryEntry *de;

  if (wd->pi->FatType != FAT32 && wd->parent == 0) {
    /* Root directory */
    filecount = wd->v.root.DirCount * DIRENT_SIZE;
    sector = wd->v.root.StartSector;
    nsectors = filecount / SECTORSIZE;
    cluster = 0;
  } else {
    /* Child directory || FAT32 
     * (In Fat32 root & child are treated similarly) */
    cluster = wd->v.child.FirstCluster;
    sector = starting_sector(cluster, wd->pi);
    nsectors = wd->pi->SectorsPerCluster;
    filecount = nsectors * SECTORSIZE;
    is_sub_dir = 1;

    if (sector == 0) {
      /* FAT problem ? */
      return 0;
    }
  }

  /* Keep going until the whole directory has been read.
   * Note: it is necessary to check filecount in the inner
   * loops as well because we can hit end-of-file anywhere
   * within a cluster. */
  while (filecount) {
    /* Keep going until the whole root or cluster has been read */
    while (nsectors && filecount) {
      /* Get the current sector */
      if (read_sector(sector, buf) != SECTORSIZE)
        return 0;
      bufcount = 0;
      ++sector;
      --nsectors;

      while ((bufcount < SECTORSIZE) && filecount) {
        /* Process a single directory entry */
        filecount -= DIRENT_SIZE;

        if (filecount < 0) {
          /* This is some wierd error, both filesize and 
           * SECTORSIZE should be an integer multiple of DIRENT_SIZE.
           */
          return 0;
        }

        de = (DirectoryEntry *) (buf + bufcount);

        switch (de->Name[0]) {
        case 0x00:	/* This, and all subsequent entries are empty */
          if (!name) { /* we are looking for a free entry */
            *de_sector = sector - 1;
            *de_offset = bufcount;
            return 1;
          }
          return 0;
          break;

        case 0xe5:	/* This entry is empty, but there may be more after it */
          if (!name) { /* we are looking for a free entry */
            *de_sector = sector - 1;
            *de_offset = bufcount;
            return 1;
          }
          break;

        case 0x05:	/* escaped Kanji character */
          de->Name[0] = 0xe5;
          /* fall through to default case ... */

        default:
          if (!name)	/* we are looking for a free entry */
            break;	/* and this is not it.. */

          if ((de->Attributes & ATTR_LONG_NAME_MASK) ==
              ATTR_LONG_NAME) {
            /* This is a long file name */
            break;
          }

          /* Must be a file, directory or volume ID */
          switch (de->Attributes & (ATTR_DIRECTORY | ATTR_VOLUME_ID)) {
          case 0x00:		/* This entry is a file */
            if (ext) {	/* Here if we are looking for a file */
              if (!dir_name_compare(name, (char *) (de->Name), 8)
                  && !dir_name_compare(ext, (char *) (de->Extension), 3)) {
                if (wd->pi->FatType == FAT32) {
                  /* first cluster is a 32 bit entry for FAT32 */
                  *firstcluster = make_UINT32
                    (de->FirstClusterOfFile_hi[1],
                     de->FirstClusterOfFile_hi[0],
                     de->FirstClusterOfFile[1], 
                     de->FirstClusterOfFile[0]);
                } else {
                  *firstcluster = (UINT32)make_UINT16
                    (de->FirstClusterOfFile[1], 
                     de->FirstClusterOfFile[0]);
                }
                *filesize = make_UINT32(de->FileSize[3], 
                                        de->FileSize[2], 
                                        de->FileSize[1], 
                                        de->FileSize[0]);
                *de_sector = sector - 1;
                *de_offset = bufcount;
                return 1;
              }
            }
            break;

          case ATTR_DIRECTORY:	/* This entry is a directory */
            if (ext == 0) {
              if (!dir_name_compare(name, (char *) (de->Name), 8)) {
                if (wd->pi->FatType == FAT32) {
                  /* first cluster is a 32 bit entry for FAT32 */
                  *firstcluster = make_UINT32
                    (de->FirstClusterOfFile_hi[1],
                     de->FirstClusterOfFile_hi[0],
                     de->FirstClusterOfFile[1], 
                     de->FirstClusterOfFile[0]);
                } else {
                  *firstcluster = (UINT32)make_UINT16
                    (de->FirstClusterOfFile[1], 
                     de->FirstClusterOfFile[0]);
                }
                *filesize = make_UINT32(de->FileSize[3],
                                        de->FileSize[2],
                                        de->FileSize[1],
                                        de->FileSize[0]);
                *de_sector = sector - 1;
                *de_offset = bufcount;
                return 1;
              }
            }
            break;

          case ATTR_VOLUME_ID:	/* Volume ID */
            break;

          default:		/* Bad directory */
            return 0;
          }
        }
        bufcount += DIRENT_SIZE;
      }
    }

    /* Finished with root or current cluster. If this is not the
     * root, then move to the next cluster. */

    /* Root directory (in FAT12/16) has one continuous list of sectors */
    if (wd->pi->FatType != FAT32 && wd->parent == 0)
      return 0;

    /* If this is a child directory go to next cluster */
    cluster = next_cluster(cluster, wd->pi);
    if (cluster == BAD_CLUSTER) {
      /* FAT problem ? */
      return 0;
    }

    if (is_sub_dir) {
      /* reset filesize to read another clusters worth of directory entries */
      filecount = (wd->pi->SectorsPerCluster * SECTORSIZE);
    }

    if ((sector = starting_sector(cluster, wd->pi)) == 0) {
      /* FAT problem ? */
      return 0;
    }
    nsectors = wd->pi->SectorsPerCluster;


  } /* while(filesize) */

  /* Never found it */
  return 0;
}

void update_de_filesize(DirectoryEntry *de, UINT32 filesize)
{
  write_UINT32(de->FileSize, filesize);
}

void update_de_firstcluster(DirectoryEntry *de, UINT32 firstcluster, PartitionInfo *pi)
{
  UINT16 f_lo, f_hi;
	
  f_lo = (UINT16)(firstcluster & 0xFFFF);
  f_hi = (UINT16)(firstcluster >> 16);
  write_UINT16(de->FirstClusterOfFile, f_lo);
  if (pi->FatType == FAT32)
    write_UINT16(de->FirstClusterOfFile_hi, f_hi);
}

int is_dir_empty(WorkingDirectory *wd)
{
	BYTE buf[SECTORSIZE];
	int bufcount;
	int is_sub_dir = 0;
	UINT32 sector;
	UINT32 filecount;
	UINT32 nsectors;
	UINT32 cluster;
	DirectoryEntry *de;

	if (wd->pi->FatType != FAT32 && wd->parent == 0) {
		/* Root directory */
		filecount = wd->v.root.DirCount * DIRENT_SIZE;
		sector = wd->v.root.StartSector;
		nsectors = filecount / SECTORSIZE;
		cluster = 0;
	} else {
		/* Child directory || FAT32 
		 * (In Fat32 root & child are treated similarly) */
		cluster = wd->v.child.FirstCluster;
		sector = starting_sector(cluster, wd->pi);
		nsectors = wd->pi->SectorsPerCluster;
		filecount = nsectors * SECTORSIZE;
		is_sub_dir = 1;

		if (sector == 0) {
			/* FAT problem ? */
			return 0;
		}
	}

	/* Keep going until the whole directory has been read.
	 * Note: it is necessary to check filecount in the inner
	 * loops as well because we can hit end-of-file anywhere
	 * within a cluster. */
	while (filecount) {
		/* Keep going until the whole root or cluster has been read */
		while (nsectors && filecount) {
			/* Get the current sector */
			if (read_sector(sector, buf) != SECTORSIZE)
				return 0;
			bufcount = 0;
			++sector;
			--nsectors;

			while ((bufcount < SECTORSIZE) && filecount) {
				/* Process a single directory entry */
				filecount -= DIRENT_SIZE;

				if (filecount < 0) {
					/* This is some wierd error, both filesize and 
					 * SECTORSIZE should be an integer multiple of DIRENT_SIZE.
					 */
					return 0;
				}
				de = (DirectoryEntry *) (buf + bufcount);

				switch (de->Name[0]) {
				case 0x00:	/* This, and all subsequent entries are empty */
					return 1;
					break;

				case '.':
				case 0xe5:	/* This entry is empty, but there may be more after it */
					break;

				case 0x05:	/* escaped Kanji character */
				default:
					/* check if the entry is in LFN format */
					if ((de->Attributes & ATTR_VOLUME_ID) == ATTR_VOLUME_ID) 
						break;
					return 0;
				}
				bufcount += DIRENT_SIZE;
			}
		}

		/* Finished with root or current cluster. If this is not the
		 * root, then move to the next cluster. */

		/* Root directory (in FAT12/16) has one continuous list of sectors */
		if (wd->pi->FatType != FAT32 && wd->parent == 0)
			return 0;

		/* If this is a child directory go to next cluster */
		cluster = next_cluster(cluster, wd->pi);
		if (cluster == BAD_CLUSTER) {
			/* FAT problem ? */
			return 0;
		}

		if (is_sub_dir) {
			/* reset filesize to read another clusters worth of directory entries */
			filecount = (wd->pi->SectorsPerCluster * SECTORSIZE);
		}

		if ((sector = starting_sector(cluster, wd->pi)) == 0) {
			/* FAT problem ? */
			return 0;
		}
		nsectors = wd->pi->SectorsPerCluster;
	} /* while(filesize) */

	/* Never found an entry */
	return 1;
}

int sysace_readdir(char *path, dirent entry[], int n_entries)
{
	BYTE buf[SECTORSIZE];
	int bufcount;
	int is_sub_dir = 0;
	UINT32 sector;
	UINT32 filecount, filesize = 0;
	UINT32 nsectors;
	UINT32 cluster;
	DirectoryEntry *de;
	WorkingDirectory *wd = NULL;
	int cur_entry = 0;
	int place = 0;

	wd = _build_working_directory_stack(path, 1, 0);
	if (!wd)	/* unable to locate */
		return XILFATFS_ENOENT;

	if (wd->pi->FatType != FAT32 && wd->parent == 0) {
		/* Root directory */
		filecount = wd->v.root.DirCount * DIRENT_SIZE;
		sector = wd->v.root.StartSector;
		nsectors = filecount / SECTORSIZE;
		cluster = 0;
	} else {
		/* Child directory || FAT32 
		 * (In Fat32 root & child are treated similarly) */
		cluster = wd->v.child.FirstCluster;
		sector = starting_sector(cluster, wd->pi);
		nsectors = wd->pi->SectorsPerCluster;
		filecount = nsectors * SECTORSIZE;
		is_sub_dir = 1;

		if (sector == 0) {
			/* FAT problem ? */
			return XILFATFS_EIO;
		}
	}

	cur_entry = 0;
	/* Keep going until the whole directory has been read.
	 * Note: it is necessary to check filecount in the inner
	 * loops as well because we can hit end-of-file anywhere
	 * within a cluster. */
	while (filecount) {
		/* Keep going until the whole root or cluster has been read */
		while (nsectors && filecount) {
			/* Get the current sector */
			if (read_sector(sector, buf) != SECTORSIZE)
				return cur_entry;
			bufcount = 0;
			++sector;
			--nsectors;

			while ((bufcount < SECTORSIZE) && filecount) {
				/* Process a single directory entry */
				filecount -= DIRENT_SIZE;

				if (cur_entry >= n_entries)
					return cur_entry;

				if (filecount < 0) {
					/* This is some wierd error, both filesize and 
					 * SECTORSIZE should be an integer multiple of DIRENT_SIZE.
					 */
					return cur_entry;
				}

				de = (DirectoryEntry *) (buf + bufcount);

				switch (de->Name[0]) {
				case 0x00:	/* This, and all subsequent entries are empty */
					debug_xil_printf("End of dir entry: %d\n", place);
					return cur_entry;

				case 0xe5:	/* This entry is empty, but there may be more after it */
					debug_xil_printf("Entry %d is empty, but more after it..\n", place);
					break;

				case 0x05:	/* escaped Kanji character */
					de->Name[0] = 0xe5;
					/* fall through to default case ... */

				default:
					if ((de->Attributes & ATTR_LONG_NAME_MASK) ==
					    ATTR_LONG_NAME) {
						/* This is a long file name */
						strcpy(entry[cur_entry].name, "LFN     ");
						entry[cur_entry].ext[0] = 0;
						entry[cur_entry].size = 0;
						entry[cur_entry].attributes = de->Attributes;
						cur_entry++;
						break;
					}

					/* Must be a file, directory or volume ID */
					memcpy(entry[cur_entry].name, de->Name, FILENAME_SIZE);
					memcpy(entry[cur_entry].ext, de->Extension, EXTENSION_SIZE);
					entry[cur_entry].name[FILENAME_SIZE] = 
						entry[cur_entry].ext[EXTENSION_SIZE] = 0;

					filesize = make_UINT32(de->FileSize[3], de->FileSize[2], de->FileSize[1], de->FileSize[0]);
					entry[cur_entry].size = filesize;
					entry[cur_entry].attributes = de->Attributes;
					cur_entry++;
					debug_xil_printf("entry %d, name = %c%c%c%c%c\n", place, de->Name[0],
							de->Name[1], de->Name[2], de->Name[3], de->Name[4]);
				}
				bufcount += DIRENT_SIZE;
				place++;
			}
		}

		/* Finished with root or current cluster. If this is not the
		 * root, then move to the next cluster. */

		/* Root directory (in FAT12/16) has one continuous list of sectors */
		if (wd->pi->FatType != FAT32 && wd->parent == 0)
			return cur_entry;

		/* If this is a child directory go to next cluster */
		cluster = next_cluster(cluster, wd->pi);
		if (cluster == BAD_CLUSTER) {
			/* FAT problem ? */
			return cur_entry;
		}

		if (is_sub_dir) {
			/* reset filesize to read another clusters worth of directory entries */
			filecount = (wd->pi->SectorsPerCluster * SECTORSIZE);
		}

		if ((sector = starting_sector(cluster, wd->pi)) == 0) {
			/* FAT problem ? */
			return cur_entry;
		}
		nsectors = wd->pi->SectorsPerCluster;


	} /* while(filesize) */

	/* Never found it */
	return cur_entry;
}
