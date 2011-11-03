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

#include "filestatus.h"
#include "alloc.h"

/* global static for linked list start pointer */
static FileStatus *FileListHead = 0;

/* find the filestatus corresponding to a given stream */
FileStatus *find_file_status(SYSACE_FILE *stream)
{
  FileStatus *fs;

  for (fs = FileListHead; fs; fs = fs->next)
    if (fs == stream)
      return fs;

  return 0;
}


/* Create a new FILEINFO and add to list. 
 * Fail if file is already open for write 
 */
FileStatus *create_file_status(WorkingDirectory * wd,
				      BYTE read, BYTE write)
{
  FileStatus *ps;

  /* See it this file is already opened */
  for (ps = FileListHead; ps; ps = ps->next) {
    if (ps->wd->v.child.FirstCluster ==
        wd->v.child.FirstCluster && (write || ps->write))
      return 0;
  }

  if ((ps = malloc_fs()) == 0)
    return 0;

  ps->wd = wd;
  ps->read = read;
  ps->write = write;
  ps->CurrentCluster = wd->v.child.FirstCluster;
  ps->PositionInCluster = 0;
  ps->PositionInFile = 0;

  ps->next = FileListHead;
  FileListHead = ps;

  return ps;
}

int delete_file_status(FileStatus * status)
{
  FileStatus *ps;

  /* First unlink this item */
  if (FileListHead == status) {
    /* It's the first item, just step over it */
    FileListHead = status->next;
  } else {
    /* It's further down the list - keep looking */
    for (ps = FileListHead; ps; ps = ps->next) {
      if (ps->next == status) {
        /* found it - remove from list */
        ps->next = status->next;
        /* Stop search */
        break;
      }
    }
    if (ps == 0) {
      /* Went through whole list and it wasn't there!! */
      return -1;
    }
  }

  delete_working_directory_stack(status->wd);
  free_fs(status);
  return 0;
}
