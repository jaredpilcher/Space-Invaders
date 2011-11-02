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

#include "fat.h"
#include "filespec.h"
#include "directory.h"
#include "util.h"

/* Limited to 8 character filenames */
int sysace_chdir(const char *path)
{
  WorkingDirectory *wd;
  int partition;

  wd = build_working_directory_stack(path, 1, 0);

  if (wd) {
    /* This is a valid directory path */
    partition = wd->pi->PartitionNum;
    if (cwd[partition])
      delete_working_directory_stack(cwd[partition]);
    cwd[partition] = wd;
    DefaultPartition = partition;
    return 0;
  }

  return -1;
}

#ifdef GET_CWD

#define GETDCWDBUFSIZE 100

char *my_getdcwd(int drive, char *path, int pathsize)
{
  int length, level;
  int i, j;
  char *s, *buf_t;
  char buf[GETDCWDBUFSIZE];
  WorkingDirectory *wd;

  if (drive == 0) {
    /* Use the default drive */
    drive = DefaultPartition;
  } else
    drive -= 1;

  if (drive < 0 || drive >= MAXPARTITION)
    return 0;

  if (cwd[drive] == 0) {
    /* Set the default */
    cwd[drive] =
      build_working_directory_stack(DIRSEPSTRING, 1, 0);
    if (cwd[drive] == 0)
      return 0;
  }
  /* Determine the total length needed */
  level = 0;
  length = 3;		/* Drive specification, terminating 0 */

  wd = cwd[drive];
  while (wd) {
    length += strlen(wd->name);
    ++level;
    wd = wd->parent;
  }

  if (level > 2)
    length += level - 2;	/* Allow for separating characters */

  if (path) {
    /* Use the users buffer */
    if (pathsize < length)
      return 0;
    s = path;
  } else {
    if (GETDCWDBUFSIZE < length)
      return 0;
    s = buf;
  }

  /* Drive letter */
  s[0] = 'a' + drive;
  s[1] = ':';

  /* terminate the string */
  i = length;
  s[--i] = 0;

  wd = cwd[drive];
  while (wd) {
    j = strlen(wd->name);

    /* Copy the directory name */
    while (j > 0) {
      if (i < 2) {	/* Something went wrong - we re about to run out of room */
        return 0;
      }
      s[--i] = wd->name[--j];
    }

    /* Add separator. Note that root and 2nd level directory do not need separators. */
    if (level > 2)
      s[--i] = DIRSEPCHAR;
    --level;
    wd = wd->parent;
  }

  if (i != 2) {
    /* Something went wrong - at this point there should be space remaining for
     * the drive spec (2 characters). */
    return 0;
  }

  if (s == path)
    return path;

  /* Make a new string - user is responsible for free()ing this string */
  buf_t = (char *)malloc(strlen(buf) + 1);
  if (!buf_t) 
    return 0;
  return strcpy(buf_t, buf);
}

#endif /*GET_CWD */
