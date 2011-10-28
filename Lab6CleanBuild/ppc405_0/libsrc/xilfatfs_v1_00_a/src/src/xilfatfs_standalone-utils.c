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

/* Define the same functions present in sysace.c & sysace_stdio.c
 * only these now work on a file (virtualized disk) rather than
 * the compact flash
 */

#include <stdio.h>
#include <sysace.h>

/* pointer to the virtual disk */
FILE *disk_fp;
char *diskpath = "../cfdisk";

int init_ace()
{
  disk_fp = fopen(diskpath, "r+");
  if (!disk_fp) {
    printf("%s: Error opening virtual disk: %s\n", __FUNCTION__, diskpath);
    return -1;
  }

  return 0;
}

int read_sector(UINT32 sector, BYTE *sector_buf)
{
  /* fseek to the correct position & return the sector */
  if (fseek(disk_fp, sector * SECTORSIZE, SEEK_SET) < 0) {
    printf("error while seeking..\n");
    return -1;
  }
  return fread(sector_buf, 1, SECTORSIZE, disk_fp);
}

int write_sector(UINT32 sector, BYTE *sector_buf)
{
  /* fseek to the correct position & write the sector */
  if (fseek(disk_fp, sector * SECTORSIZE, SEEK_SET) < 0) {
    printf("error while seeking..\n");
    return -1;
  }
  return fwrite(sector_buf, 1, SECTORSIZE, disk_fp);
}
