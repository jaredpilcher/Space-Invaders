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

/* Defaults to all zeros */
WorkingDirectory *cwd[MAXPARTITION] = { 0 };
int DefaultPartition = 0;

void delete_working_directory_stack(WorkingDirectory * wd)
{
  WorkingDirectory *parent;

  while (wd) {
    parent = wd->parent;
    free_wd(wd);
    wd = parent;
  }

  return;
}

#define WD_BUFSIZE      10
#define WD_EXT_BUFSIZE   5

WorkingDirectory *_build_working_directory_stack(const char *path,
                                                 int is_dir, int create)
{
  char buf[WD_BUFSIZE];
  char ext_buf[WD_EXT_BUFSIZE];
  field_type type = PATH_START;
  WorkingDirectory *wd = 0;
  WorkingDirectory *child;
  int i = 0;
  int partition = DefaultPartition;
#if defined(CONFIG_WRITE) && defined(CONFIG_DIR_SUPPORT)
  char leaf_buf[WD_BUFSIZE];
#endif

  while (type != PATH_DONE) {
    i += parse_path(path + i, buf, WD_BUFSIZE, is_dir, &type);

    switch (type) {
    case DEVICE_NAME:
      /* Cannot support server spec */
      if (strlen(buf) > 1) {
        delete_working_directory_stack(wd);
        return 0;
      }
      /* interpret drive letter */
      if ((partition = tolower(buf[0]) - 'a') < 0
          || partition >= MAXPARTITION) {
        delete_working_directory_stack(wd);
        return 0;
      }
      break;

    case DIR_NAME:
      if (wd == 0 && !strcmp(buf, DIRSEPSTRING)) {
        /* The specification is absolute - this is the root directory */
        if ((wd = make_root_directory(partition)) == 0)
          return 0;
        break;
      }

      if (wd == 0) {
        /* This is a relative pathname - see if there is a CWD for this partition.
         * If not, default to the root directory for the partition. Then duplicate
         * the default stack so that the child can be appended. */
        if (cwd[partition] == 0)
          cwd[partition] =
            make_root_directory(partition);
        if (cwd[partition] == 0)
          return 0;
        wd = copy_directory_stack(cwd[partition]);
        if (wd == 0)
          return 0;
      }

      /* Add the child directory to the path */
      if ((child = make_child_directory(buf, NULL, wd)) == 0) {
#if defined(CONFIG_WRITE) && defined(CONFIG_DIR_SUPPORT)
        if ((!is_dir) || (is_dir && !create)) 
#endif
          {
            delete_working_directory_stack(wd);
            return 0;
          }
      }

#if defined(CONFIG_WRITE) && defined(CONFIG_DIR_SUPPORT)
      /* request to create a directory */
      if (is_dir && create && (child == 0)) {	
        /* create only if we are at the leaf */
        parse_path(path + i, leaf_buf, WD_BUFSIZE, is_dir, &type);
        if (type != PATH_DONE) {
          /* we are not at the leaf, but couldn't go further
           * so invalid path */
          return 0;
        } else  /* we are at the leaf, so we need to create the directory */
          return create_file_entry(buf, "", wd, ATTR_DIRECTORY);
      }
#endif

      wd = child;
      break;

    case FILE_NAME:
      /* Buf contains a filename - now see if there is an extension there */
      parse_path(path + i, ext_buf, WD_EXT_BUFSIZE,
                 is_dir, &type);
      if (type == PATH_DONE) {	/* The extension is empty */
        ext_buf[0] = 0;
      } else if (type != FILE_EXT) {	/* There was an error */
        delete_working_directory_stack(wd);
        return 0;
      }

      if (wd == 0) {		/* There is no directory, so copy over the cwd */
        if (cwd[partition] == 0)
          cwd[partition] = make_root_directory(partition);
        if (cwd[partition] == 0)
          return 0;
        wd = copy_directory_stack(cwd[partition]);
        if (wd == 0)
          return 0;
      }

      /* See if this file exists */
      if ((child = make_child_directory(buf, ext_buf, wd)) == 0) {
#ifdef CONFIG_WRITE
        if (!create) 	/* no such file, and no request to create one */
#endif
          {	
            delete_working_directory_stack(wd);
            return 0;
          }
      }

      /* if this is a request to create an entry, then
       * create an entry if none exists 
       */
#ifdef CONFIG_WRITE
      if (create && child == 0) {
        /* search for a free directory entry
         * make a new entry with size 0
         */ 
        child = create_file_entry(buf, ext_buf, wd, 0);
      }
#endif
      return child;

    case PATH_DONE:
      return wd;

    default:
      /* Error condition */
      delete_working_directory_stack(wd);
      return 0;
    }
  }

  return wd;
}

WorkingDirectory *build_working_directory_stack(const char *path,
						int is_dir, int write)
{
  WorkingDirectory *wd = NULL;

  if (write == 0)	/* create for read mode */
    return _build_working_directory_stack(path, is_dir, 0);

#ifdef CONFIG_WRITE
  /* when created in write mode, the  file has to be 
   * 	truncated if already present
   * 	created if absent
   */
  wd = _build_working_directory_stack(path, is_dir, 1);
  if (!wd)
    return 0;
	
  if (is_dir)
    return wd;

  /* if this is a pre-existing file (size != 0), then truncate it */
  if (wd->v.child.FileSize != 0) {
    debug_xil_printf("File already exists..size = %d\n\r", 
                     (unsigned int)wd->v.child.FileSize);
    if (truncate_file(wd->v.child.FirstCluster, wd->pi) < 0)
      return 0;

    /* change filesize to 0.
     * the directory entry is not changed yet 
     */	
    wd->v.child.FileSize = 0;
    debug_xil_printf("%s @ %d, file truncated\n\r", __FUNCTION__, __LINE__);
  } else {
    debug_print("File doesn't exist (Created now) or size 0.\n\r");
  }
#endif

  return wd;
}

void set_child_details(WorkingDirectory *wd, UINT32 firstcluster,
                       UINT32 filesize, UINT32 de_sector, UINT32 de_offset,
                       WorkingDirectory *parent) 
{
  wd->v.child.FirstCluster = firstcluster;
  wd->v.child.FileSize = filesize;
  wd->v.child.DirLocation.sector = de_sector;
  wd->v.child.DirLocation.offset = de_offset;
  wd->parent = parent;
  wd->pi = parent->pi;
}

WorkingDirectory *make_child_directory(const char *name, const char *ext,
				       WorkingDirectory * parent)
{
  WorkingDirectory *wd;
  UINT32 firstcluster;
  UINT32 filesize;
  UINT32 de_sector;
  UINT32 de_offset;

  /* find if child is present in given parent directory */
  if (!find_in_directory(parent, name, ext, &firstcluster,
                         &filesize, &de_sector, &de_offset))
    return 0;

  /* create child wd */
  if ((wd = malloc_wd(name)) == 0)
    return 0;
  set_child_details(wd, firstcluster, filesize, de_sector,
                    de_offset, parent);
  return wd;
}

void set_root_details(WorkingDirectory *wd, PartitionInfo *pi)
{
  switch(pi->FatType) {
  case FAT12:
  case FAT16:
    wd->v.root.StartSector = pi->RootDirSector;
    wd->v.root.DirCount = pi->RootDirCount;
    return;
  case FAT32:
    wd->v.child.FirstCluster = pi->RootCluster;
    return;
  }
}

WorkingDirectory *make_root_directory(int partition)
{
  WorkingDirectory *wd;
  PartitionInfo *pi;

  if ((pi = get_partition_info(partition)) == 0)
    return 0;

  if ((wd = malloc_wd(DIRSEPSTRING)) == 0)
    return 0;
  wd->parent = 0;
  wd->pi = pi;

  /* copy over the information about root directory */
  set_root_details(wd, pi);

  return wd;
}

#ifdef CONFIG_WRITE
/* names are truncated to 8.3 format when writing */
void initialize_de(DirectoryEntry *de, 
                   char *name, 
                   char *ext, 
                   UINT32 firstcluster, 
                   UINT32 filesize, 
                   PartitionInfo *pi, 
                   BYTE attrib)
{
  int i;

  for (i = 0; i < 8; i++) {
    if (*name) {
      de->Name[i] = toupper(*name);
      name++;
    } else
      de->Name[i] = ' ';
  }

  for (i = 0; i < 3; i++) {
    if (*ext) {
      de->Extension[i] = toupper(*ext);
      ext++;
    } else
      de->Extension[i] = ' ';
  }

  de->Attributes = attrib;
  memset(de->Reserved, 0, 8);
  memset(de->Date, 0, 2);

  update_de_firstcluster(de, firstcluster, pi);

  update_de_filesize(de, filesize);

  return;
}
#endif

WorkingDirectory *copy_directory_stack(WorkingDirectory * stack)
{
  WorkingDirectory *src, *dest, *first, *previous;

  first = 0;
  previous = 0;
  src = stack;

  /* Copy child directories */
  while (src) {
    dest = malloc_wd(src->name);
    if (dest == 0) {
      delete_working_directory_stack(first);
      return 0;
    }

    if (first == 0)
      first = dest;

    if (previous)
      previous->parent = dest;

    dest->parent = 0;
    dest->pi = src->pi;

    if (src->parent || src->pi->FatType == FAT32) {
      /* Child directory */
      dest->v.child.FirstCluster = src->v.child.FirstCluster;
      dest->v.child.FileSize = src->v.child.FileSize;
    } else {
      /* Root directory */
      dest->v.root.StartSector = src->v.root.StartSector;
      dest->v.root.DirCount = src->v.root.DirCount;
    }

    src = src->parent;
    previous = dest;
  }

  return first;
}
