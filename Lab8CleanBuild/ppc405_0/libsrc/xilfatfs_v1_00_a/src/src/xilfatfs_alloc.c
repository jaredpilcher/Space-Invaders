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

/* Create and release WDs */
static WorkingDirectory wd_buf[MAXWD];
static int wd_init_flag = 1;
 
WorkingDirectory *
malloc_wd(const char *name)
{ 
  int i;

  /* Do initialization because MBlaze seems not to initialize statics per K&R */
  if(wd_init_flag) { 
    wd_init_flag = 0;
    for(i=0; i<MAXWD; i++ )
      wd_buf[i].name[0] = 0;
  }

  for(i=0; i<MAXWD; i++)
    if(wd_buf[i].name[0] == 0) { 
      strncpy(wd_buf[i].name, name, MAXFILENAMESIZE);
      return wd_buf + i;
    }

  return 0;
}

void 
free_wd(WorkingDirectory *wd)
{ 
  wd->name[0] = 0;  
}

static FileStatus fs_buf[MAXFILES];
static int fs_init_flag = 1;

FileStatus *
malloc_fs(void)
{ 
  int i;

  if(fs_init_flag) { 
    fs_init_flag = 0;
    for(i=0; i<MAXFILES; i++)
      fs_buf[i].reserved = 0;
  }

  for(i=0; i<MAXFILES; i++)
    if( fs_buf[i].reserved == 0 ) { 
      fs_buf[i].reserved = 1;
      return fs_buf + i;
    }

  return 0;
}

void 
free_fs(FileStatus *fs)
{ 
  fs->reserved = 0;
}
