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

#include "xparameters.h"

#include "sysace.h"
#include "xsysace_l.h"
#include "xsysace.h"
#include "xstatus.h"
#include "xbasic_types.h"
#include "xio.h"
#include "bufcache.h"
#include "stats.h"

static Xuint32 sysace_base_addr = 0;

int read_sector_cf(UINT32 sector, BYTE *pSectorBuffer)
{
	xilfatfs_stats_read++;
	return XSysAce_ReadSector(sysace_base_addr, 
			sector, pSectorBuffer);
}

int write_sector_cf(UINT32 sector, BYTE *pSectorBuffer)
{
	xilfatfs_stats_write++;
	return XSysAce_WriteSector(sysace_base_addr, 
			sector, pSectorBuffer);
}

/***** initalize system ace for  reading and writing  *****/
int init_ace()
{
	XSysAce Ace;
	XStatus Result;
	XStatus  status_init; 

	/* This code assumes only one systemace interface in the build and its Device ID is 0*/
	status_init = XSysAce_Initialize(&Ace, 0);
	sysace_base_addr = Ace.BaseAddress;
	while ((Result = XSysAce_Lock(&Ace, XFALSE)) != XST_SUCCESS)
		;
	XSysAce_RegWrite32(sysace_base_addr + XSA_CR_OFFSET, 
			XSA_CR_FORCECFGMODE_MASK);

	init_bufcache(write_sector_cf);

	return (int) (status_init);
}

int read_sector(UINT32 sector, BYTE *sector_buf)
{
	if (is_buffered((int)sector) < 0) {	/* sector not buffered */
		int n = read_sector_cf(sector, sector_buf);
		if (n == SECTORSIZE) {			/* if valid data read */
			if (update_bufcache(sector, sector_buf, 0) < 0)
				return -1;
		}
		return n;
	} else {	/* sector already present in buffer */
		return read_bufcache(sector, sector_buf);
	}
}

int write_sector(UINT32 sector, BYTE *sector_buf)
{
	return update_bufcache(sector, sector_buf, 1);
}
