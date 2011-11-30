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

#include "filestatus.h"
#include "sysace_stdio.h"
#include "fat.h"

#if defined( DUMMY_DISK )
static char *dummy_data = "Are we there yet?\n";
#endif

int read_from_file(FileStatus * fs, char *buf, int count)
{
  int readcount, n;
  int remaining;
  BYTE sectorbuf[SECTORSIZE];
  UINT32 sector;
  UINT32 filesize;
  UINT32 nsectors;
  UINT32 sector_offset;
  int byte_offset;

  /* Safety check */
  if (fs == 0 || !fs->read || count < 0)
    return 0;

  filesize = fs->wd->v.child.FileSize;

  if (fs->PositionInFile >= filesize)
    return 0;

  readcount = 0;

  /* Compute number of bytes left to read - may be limited
   * by size of users buf or by file size */
  remaining = filesize - fs->PositionInFile;
  if (count < remaining)
    remaining = count;

  while (fs->PositionInFile < filesize) {
    /* Which sector of this cluster did we leave off at last time ? */
    sector_offset = fs->PositionInCluster / SECTORSIZE;

    /* Which byte of that sector did we leave off at last time ? */
    byte_offset = fs->PositionInCluster % SECTORSIZE;

    /* Sector address to start reading this time */
    sector = starting_sector(fs->CurrentCluster, fs->wd->pi);
    if (sector == 0) {
      /* FAT problem ? */
      return 0;
    }
    sector += sector_offset;

    /* How many sectors left to read in this cluster */
    nsectors = fs->wd->pi->SectorsPerCluster - sector_offset;

    while (nsectors) {
      if (read_sector(sector, sectorbuf) != SECTORSIZE)
        return -1;
      if (remaining <= (SECTORSIZE - byte_offset)) {
        /* End of file or end of buffer occurs in this sector
         * Read what's left and quit */
        memcpy(buf + readcount,
               (char *) (sectorbuf + byte_offset),
               remaining);
        fs->PositionInFile += remaining;
        fs->PositionInCluster += remaining;
        return (remaining + readcount);
      }
      /* End of file is beyond this sector */
      n = SECTORSIZE - byte_offset;
      memcpy(buf + readcount,
             (char *) (sectorbuf + byte_offset), n);
      fs->PositionInFile += n;
      fs->PositionInCluster += n;
      readcount += n;
      remaining -= n;

      /* Point to start of next sector in cluster */
      byte_offset = 0;
      sector += 1;
      nsectors -= 1;
    }	/* end of while */

    /* Done with that cluster, advance to the next one */
    fs->CurrentCluster = next_cluster(fs->CurrentCluster, fs->wd->pi);
    if (fs->CurrentCluster == BAD_CLUSTER) {
      /* Bad cluster address - this means that there is a FAT problem,
       * because we should have dtected that this was the last cluster
       * based on filesize. The file system is hosed. */
      return 0;
    }
    /* We are at the start of this new cluster */
    fs->PositionInCluster = 0;
  }

  return readcount;
}

int sysace_fread(void *buffer, int size, int count, SYSACE_FILE *stream)
{
  FileStatus *fs = find_file_status(stream);

  if (fs == 0)
    return -1;

  return read_from_file(fs, (char *) buffer, size * count);
}
