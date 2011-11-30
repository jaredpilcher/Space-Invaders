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
////////////////////////////////////////////////////////////////////////////

// Directory separator
#define DIRSEPCHAR        '\\'
#define DIRSEPSTRING      "\\"


#ifdef __cplusplus
extern "C" {
#endif

typedef enum _field_type { PATH_START, DEVICE_NAME, DIR_NAME,
                 FILE_NAME, FILE_EXT, PATH_ERROR, PATH_DONE } field_type;


int parse_path( const char *path, char *buf, int length, int is_dir, field_type *type );


#ifdef __cplusplus
}
#endif
