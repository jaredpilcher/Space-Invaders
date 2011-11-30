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

#ifndef __BUFCACHE_H_
#define __BUFCACHE_H_

#include "sysace.h"


#ifdef __cplusplus
extern "C" {
#endif

/* return the index of sector in buffer cache if present,
 * -1 if sector not in buffer cache
 */
int is_buffered(int sector);

/* initialize buffer cache. 
 * should be called before any other function to bufcache
 */
void init_bufcache(int (*ll_write)(UINT32 sector, BYTE *buf));

/* update buffer cache with data for @sector */
int update_bufcache(int sector, unsigned char *sector_buf, int dirty);

/* read data for @sector from buffer cache */
int read_bufcache(int sector, unsigned char *sector_buf);

/* sync dirty entries to the disk using the low level write function (*ll_write) */
int sync_bufcache();


#ifdef __cplusplus
}
#endif

#endif
