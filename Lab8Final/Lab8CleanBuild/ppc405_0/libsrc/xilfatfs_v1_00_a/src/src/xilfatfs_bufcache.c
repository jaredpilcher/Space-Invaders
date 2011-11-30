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

#include "xparameters.h"
#include "sysace.h"
#include "bufcache.h"
#include "util.h"

struct bufcache_status_s {
	unsigned char valid;
	unsigned char dirty;
	int sector;
};

#define N_BUFCACHE_ENTRIES	((XILFATFS_BUFCACHE_SIZE/SECTORSIZE))

struct bufcache_status_s bc_status[N_BUFCACHE_ENTRIES];
unsigned char bc[XILFATFS_BUFCACHE_SIZE];
int bc_replace_index;

int (*ll_write)(UINT32 sector, BYTE *buf);

/* return the index of sector in buffer cache if present,
 * -1 if sector not in buffer cache
 */
int is_buffered(int sector)
{
	int i;

	for (i = 0; i < N_BUFCACHE_ENTRIES; i++)
		if (bc_status[i].valid && bc_status[i].sector == sector)
			return i;
	return -1;
}

/* get a free entry in the buffer cache */
int bc_get_free_entry()
{
	int i;

	for (i = 0; i < N_BUFCACHE_ENTRIES; i++)
		if (!bc_status[i].valid)
			return i;

	return -1;
}

/* find free space by replacing an entry */
int sequential_replace()
{
	int cur_index = bc_replace_index;
	bc_replace_index = (bc_replace_index + 1)%N_BUFCACHE_ENTRIES;

	if (!bc_status[cur_index].valid) {
		/* current entry to be replaced is not in use */
		return cur_index;
	}

	if (bc_status[cur_index].dirty) {
		/* sync the current entry to disk */
		int n = (*ll_write)(bc_status[cur_index].sector, 
				(bc+cur_index*SECTORSIZE));
		if (n != SECTORSIZE) {
			/* fatal - cannot be synced */
			return -1;
		}
		bc_status[cur_index].dirty = 0;
	}

	return cur_index;
}

/* initialize buffer cache. 
 * use the low level write function (*ll_write_fn) when required to sync to disk
 * should be called before any other function to bufcache
 */
void init_bufcache(int (*ll_write_fn)(UINT32 sector, BYTE *buf))
{
	memset(bc_status, 0, sizeof (bc_status));
	bc_replace_index = 0;
	ll_write = ll_write_fn;
}

/* update buffer cache with data for @sector */
int update_bufcache(int sector, unsigned char *sector_buf, int dirty)
{
	int index = is_buffered(sector);

	if (index < 0)	/* if not buffered */
		index = bc_get_free_entry();

	if (index < 0) {	/* not buffered, and no free entry in the cache */ 
		index = sequential_replace();	/* replace something */
		if (index < 0)
			return -1;
	}
	
	bc_status[index].valid  = 1;
	bc_status[index].dirty  = dirty;
	bc_status[index].sector = sector;

	memcpy(bc + index*SECTORSIZE, sector_buf, SECTORSIZE);
	return SECTORSIZE;
}

/* read data for @sector from buffer cache */
int read_bufcache(int sector, unsigned char *sector_buf)
{
	int n = is_buffered(sector);
	if (n < 0)
		return -1;
	memcpy(sector_buf, bc + n*SECTORSIZE, SECTORSIZE);
	return SECTORSIZE;
}

/* sync dirty entries to the disk */
int sync_bufcache()
{
	int i, error = 0;

	for (i = 0; i < N_BUFCACHE_ENTRIES; i++)
		if (bc_status[i].valid && bc_status[i].dirty) {
			if ((*ll_write)(bc_status[i].sector, bc + i*SECTORSIZE) != SECTORSIZE)
				error = 1;
			bc_status[i].dirty = 0;
		}

	return -error;
}
