/////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2003, 2004 Xilinx, Inc.  All rights reserved.
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
//////////////////////////////////////////////////////////////////////////


#ifndef __SYSACE_H__
#define __SYSACE_H__


#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char	BYTE;					
typedef unsigned short	UINT16;
typedef unsigned long	UINT32;

#define SECTORSIZE      512         // sector size in bytes

/* interface functions to SystemAce */
int init_ace();
int read_sector(UINT32 sector, BYTE *pSectorBuffer );
int write_sector(UINT32 sector, BYTE *pSectorBuffer );

#define make_UINT16(b1, b0) 		( ((b1)<<8) | (b0) )
#define make_UINT32(b3, b2, b1, b0) 	( ((b3)<<24) | ((b2)<<16) | ((b1)<<8) | (b0) )

#define write_UINT32(addr, val) 	do { \
		*((BYTE *)addr) = ((BYTE)val&0xff);	\
		*(((BYTE *)addr) + 1) = ((BYTE)(val>>8)&0xff);	\
		*(((BYTE *)addr) + 2) = ((BYTE)(val>>16)&0xff);	\
		*(((BYTE *)addr) + 3) = ((BYTE)(val>>24)&0xff);	\
} while (0);

#define write_UINT16(addr, val) 	do { 			\
		*((BYTE *)addr) = ((BYTE)val&0xff);		\
		*(((BYTE *)addr) + 1) = ((BYTE)(val>>8)&0xff);	\
} while (0);


#ifdef __cplusplus
}
#endif

#endif  /* __SYSACE_H__ */
