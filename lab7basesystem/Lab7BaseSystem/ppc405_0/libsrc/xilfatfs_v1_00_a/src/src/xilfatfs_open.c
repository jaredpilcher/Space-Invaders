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
#include "sysace_stdio.h"
#include "fat.h"
#include "filestatus.h"

SYSACE_FILE *sysace_fopen(const char *file, const char *mode)
{
  BYTE read = 0;
  BYTE write = 0;
  WorkingDirectory *wd;
  FileStatus *ps;

  /* only "r" and "w" modes are supported */
  if (!strcmp(mode, "r"))
    read = 1;
  else if (!strcmp(mode, "w"))
    write = 1;
  else
    return 0;

  /* create a working directory stack for the file */
  if ((wd = build_working_directory_stack(file, 0, write)) == 0)
    return 0;

  if ((ps = create_file_status(wd, read, write)) == 0) {
    delete_working_directory_stack(wd);
    return 0;
  }

  return (SYSACE_FILE *) ps;
}
