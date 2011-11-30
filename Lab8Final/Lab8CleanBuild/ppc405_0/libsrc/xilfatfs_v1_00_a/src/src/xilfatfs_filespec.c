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
#include "filespec.h"

/* Routines to parse out path names. The only characters that are
 * checked for are \ (backslash), . (period) and : (colon). The
 * rest are treated as valid characters for names.
 *
 * Examine path to see if it starts with a directory name.
 * If so, copy it to buf and return number of characters
 * consumed. If buf is too short, 0 is returned. The is_dir
 * flags says that we expect this to be a directory specifier, i.e.
 * a trailing name with no file extension is a directory name,
 * not a file name. The root flag says that this might be the root
 * directory, i.e if it starts with backslash, return just that.
 */
static int find_dir(const char *path, char *buf, int length, int is_dir,
		    int root)
{
  int i = 0;
  int relative = 0;

  if (root && path[0] == DIRSEPCHAR) {
    /* This is the root */
    if (length < 2)
      return 0;
    buf[0] = DIRSEPCHAR;
    buf[1] = 0;
    return 1;
  }

  while (i < length) {
    if (path[i] == 0) {
      /* End of string - could be a directory or a file
       * name that has no extension */
      if (is_dir) {
        /* Last field is a directory */
        buf[i] = 0;
        return i;
      } else {
        /* Last field is a file */
        return 0;
      }
    }

    if (path[i] == DIRSEPCHAR) {
      if (i > 0) {
        /* hierarchy separator  */
        buf[i] = 0;
        return i + 1;	/* eat the directory separator too */
      } else
        return 0;
    }
    /* Look for bad characters */
    if (path[i] == '.') {
      if (i == 0)
        relative = 1;
      else if (i > 1 || !relative)
        return 0;
    }

    if (path[i] == ':')
      return 0;

    /* Keep copying - so far so good */
    buf[i] = path[i];
    ++i;
  }

  /* Never found the end of this name */
  return 0;
}

/* Examine path to see if it starts with a device spec.
 * If so, copy it to buf and return the number of chars
 * consumed. If buf is too short, 0 is returned.
 * Device spec can be a DOS style (e.g. a:) or network
 * style (e.g. \\server).
 */
static int find_device(const char *path, char *buf, int length)
{
  char c;
  int i;

  /* look for server form */
  if (path[0] == DIRSEPCHAR && path[1] == DIRSEPCHAR) {
    /* Find the server name - it looks just like a directory name */
    i = 0;
    while (i < length) {
      if (path[i + 2] == 0 || path[i + 2] == DIRSEPCHAR) {
        /* hit end of server name */
        buf[i] = 0;
        return i + 2;	/* eat the double backslash too */
      }
      /* Watch for illegal characters */
      if (path[i + 2] == '.' || path[i + 2] == ':')
        return 0;

      buf[i] = path[i + 2];
      ++i;
    }
    return 0;
  }
  /* Must be a plain old DOS disk (letter colon) */
  if (length < 2 || path[0] == 0 || path[1] != ':')
    return 0;
  c = tolower(path[0]);
  if (c < 'a' || c > 'z')
    return 0;

  /* It was a device */
  buf[0] = c;
  buf[1] = 0;

  return 2;
}

/* Examine path to see if it starts with a file name.
 * If so, copy it to buf and return number of characters
 * consumed. If buf is too short, 0 is returned. The is_dir
 * flags says that we expect this to be a directory specifier, i.e.
 * a trailing name with no file extension is a directory name,
 * not a file name.
 */
static int find_file(const char *path, char *buf, int length, int is_dir)
{
  int i = 0;

  /* Do not apply file name rules if this is known to be a directory path */
  if (is_dir)
    return 0;

  while (i < length) {
    if (path[i] == 0) {
      /* End of string -  file has no extension */
      buf[i] = 0;
      return i;
    }

    if (path[i] == '.') {
      /* Hit the file extension */
      buf[i] = 0;
      return i;
    }
    /* Look for bad characters */
    if (path[i] == DIRSEPCHAR || path[i] == ':')
      return 0;

    /* Keep copying - so far so good */
    buf[i] = path[i];
    ++i;
  }

  /* Never found the end of this name */
  return 0;
}

static int find_ext(const char *path, char *buf, int length)
{
  int i = 0;

  /* Must start with a dot */
  if (path[0] != '.')
    return 0;

  while (i < length) {
    /* 3 character max */
    if (i > 3)
      return 0;

    if (path[i + 1] == 0) {
      buf[i] = 0;
      return i + 1;
    }
    /* Look for bad characters */
    if (path[i + 1] == '.' || path[i + 1] == DIRSEPCHAR
        || path[i + 1] == ':')
      return 0;

    /* Keep copying - so far so good */
    buf[i] = path[i + 1];
    ++i;
  }

  /* Never found the end of this name */
  return 0;
}

/* Find the next field in the path. Returns the number of characters
 * consumed by this field. The field type pointed to by type should
 * Be set initially to 'START' and will be updated after the field
 * has been found. The identified field will be stored in buf (up to l
 * characters) - if it does not fit, there will be an error.
 * The flag is_dir says that the path is a directory path, i.e. the
 * last field will be treated as a directory, not a file with no
 * extension.
 */
int parse_path(const char *path, char *buf, int length,
	       int is_dir, field_type * type)
{
  int i = 0;

  switch (*type) {
  case PATH_START:
    /* String cannot be empty */
    if (*path == 0) {
      *type = PATH_ERROR;
      break;
    }

    /* Can start with device, directory or file */
    if ((i = find_device(path, buf, length)) > 0)
      *type = DEVICE_NAME;
    else if ((i = find_dir(path, buf, length, is_dir, 1)) > 0)
      *type = DIR_NAME;
    else if ((i = find_file(path, buf, length, is_dir)) > 0)
      *type = FILE_NAME;
    else
      *type = PATH_ERROR;
    break;

  case DEVICE_NAME:
    /* String cannot be empty if we are looking for a file name */
    if (*path == 0) {
      if (!is_dir)
        *type = PATH_ERROR;
      else
        *type = PATH_DONE;
      break;
    }
    /* Device can be followed by directory or file */
    if ((i = find_dir(path, buf, length, is_dir, 1)) > 0)
      *type = DIR_NAME;
    else if ((i = find_file(path, buf, length, is_dir)) > 0)
      *type = FILE_NAME;
    else
      *type = PATH_ERROR;
    break;

  case DIR_NAME:
    /* String cannot be empty if we are looking for a file name */
    if (*path == 0) {
      if (!is_dir)
        *type = PATH_ERROR;
      else
        *type = PATH_DONE;
      break;
    }
    /* Directory can be followed by directory or file */
    if ((i = find_dir(path, buf, length, is_dir, 0)) > 0)
      *type = DIR_NAME;
    else if ((i = find_file(path, buf, length, is_dir)) > 0)
      *type = FILE_NAME;
    else
      *type = PATH_ERROR;
    break;

  case FILE_NAME:
    if (*path == 0)
      *type = PATH_DONE;
    else if ((i = find_ext(path, buf, length)) > 0)
      *type = FILE_EXT;
    else
      *type = PATH_ERROR;
    break;

  case FILE_EXT:
    if (*path == 0)
      *type = PATH_DONE;
    else
      *type = PATH_ERROR;
    break;

  default:
    *type = PATH_ERROR;
    break;
  }

  return i;
}
