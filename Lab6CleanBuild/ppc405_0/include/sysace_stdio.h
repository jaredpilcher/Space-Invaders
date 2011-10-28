/////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002-2004 Xilinx, Inc.  All rights reserved.
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

 
#ifndef _SYSACE_STDIO_H_
#define _SYSACE_STDIO_H_


#define SYSACE_FILE   void 
#include <stdio.h>


#ifdef __cplusplus
extern "C" {
#endif

// IF YOU WANT TO USE fopen instead of sysace_fopen, 
// and fclose, fread and fwrite instead of the corresponding
// sysace_ prefixed function names uncomment the following few lines
// and comment out the preceding two lines of code
// WARNING: This will cause link time failures for functions
// such as printf and scanf that depend on standard definitions of fwrite/fread
// so use with caution
// #define SYSACE_FILE    FILE
// typedef void FILE;
// 
// #define fopen  sysace_fopen
// #define fclose sysace_fclose
// #define fread  sysace_fread
// #define fwrite sysace_fwrite

#define FILENAME_SIZE 8
#define EXTENSION_SIZE 3

typedef struct {
	char name[FILENAME_SIZE + 1], ext[EXTENSION_SIZE + 1];
	unsigned int size;
	unsigned char attributes;
} dirent;

SYSACE_FILE *sysace_fopen(const char *file, const char *mode );
int sysace_fclose(SYSACE_FILE *stream );
int sysace_fread(void *buffer, int size, int count, SYSACE_FILE *stream );

/* write to a file, enabled by CONFIG_WRITE */
int sysace_fwrite(void *buffer, int size, int count, SYSACE_FILE *stream );

/* functions to create and change current dir, enabled by CONFIG_DIR_SUPPORT */
int sysace_mkdir(const char *path);
int sysace_chdir(const char *path);
/* read directory pointed to by *path into the array entry[] of size n_entries,
 * return value indicates the actual number of entries that was read
 */
int sysace_readdir(char *path, dirent entry[], int n_entries);


/* functions to remove file/dir. enabled by CONFIG_WRITE */
int sysace_remove_file(const char *path);
int sysace_remove_dir(const char *path);

#ifdef __cplusplus
}
#endif

#endif
