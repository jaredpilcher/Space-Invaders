/******************************************************************************
*
*       XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"
*       AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND
*       SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,
*       OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,
*       APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION
*       THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,
*       AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE
*       FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY
*       WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE
*       IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR
*       REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF
*       INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*       FOR A PARTICULAR PURPOSE.
*
*       (c) Copyright 2002 Xilinx Inc.
*       All rights reserved.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xenv_none.h
*
* Defines common services specified by xenv.h. Some of these services are
* defined as not performing any action. The implementation of these services
* are left to the user.
*
* @note
*
* This file is not intended to be included directly by driver code. Instead,
* the generic xenv.h file is intended to be included by driver code.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.00a rmm  03/21/02 First release
* 1.00a xd   11/03/04 Improved support for doxygen.
* 1.00a rmm  01/24/06 Implemented XENV_USLEEP. Assume implementation is being
*                     used under Xilinx standalone BSP.
* 1.00a xd   04/17/07 Added caching handling macros
* </pre>
*
*
******************************************************************************/

#ifndef XENV_NONE_H /* prevent circular inclusions */
#define XENV_NONE_H /* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#if defined __MICROBLAZE__
#  include "mb_interface.h"  /* If Microblaze, include MB header file */
#elif defined __PPC__
#  include "sleep.h"         /* If PPC, include sleep.h for the delay macro */
#  include "xcache_l.h"      /* also include xcache_l.h for caching macros */
#endif

/*****************************************************************************/
/**
 *
 * Copies a non-overlapping block of memory.
 *
 * @param   DestPtr is the destination address to copy data to.
 * @param   SrcPtr is the source address to copy data from.
 * @param   Bytes is the number of bytes to copy.
 *
 * @return  None.
 *
 * @note
 *
 * Signature: void XENV_MEM_COPY(void *DestPtr, void *SrcPtr, unsigned Bytes)
 *
 *****************************************************************************/
#define XENV_MEM_COPY(DestPtr, SrcPtr, Bytes)                     \
{                                                                 \
    char *Dest = (char*)(DestPtr);                                \
    char *Src  = (char*)(SrcPtr);                                 \
    unsigned BytesLeft = (Bytes);                                 \
                                                                  \
    while (BytesLeft--) *Dest++ = *Src++;                         \
}

/*****************************************************************************/
/**
 *
 * Fills an area of memory with constant data.
 *
 * @param   DestPtr is the destination address to set.
 * @param   Data contains the value to set.
 * @param   Bytes is the number of bytes to set.
 *
 * @return  None.
 *
 * @note
 *
 * Signature: void XENV_MEM_FILL(void *DestPtr, char Data, unsigned Bytes)
 *
 *****************************************************************************/
#define XENV_MEM_FILL(DestPtr, Data, Bytes)                       \
{                                                                 \
    char *Dest = (char*)(DestPtr);                                \
    char c = (Data);                                              \
    unsigned BytesLeft = (Bytes);                                 \
                                                                  \
    while (BytesLeft--) *Dest++ = c;                              \
}

/**
 * A structure that contains a time stamp used by other time stamp macros
 * defined below. This structure is processor dependent.
 */
typedef int XENV_TIME_STAMP;

/*****************************************************************************/
/**
 *
 * Time is derived from the 64 bit PPC timebase register
 *
 * @param   StampPtr is the storage for the retrieved time stamp.
 *
 * @return  None.
 *
 * @note
 *
 * Signature: void XENV_TIME_STAMP_GET(XTIME_STAMP *StampPtr)
 * <br><br>
 * This macro must be implemented by the user.
 *
 *****************************************************************************/
#define XENV_TIME_STAMP_GET(StampPtr)

/*****************************************************************************/
/**
 *
 * This macro is not yet implemented and always returns 0.
 *
 * @param   Stamp1Ptr is the first sampled time stamp.
 * @param   Stamp2Ptr is the second sampled time stamp.
 *
 * @return  0
 *
 * @note
 *
 * This macro must be implemented by the user.
 *
 *****************************************************************************/
#define XENV_TIME_STAMP_DELTA_US(Stamp1Ptr, Stamp2Ptr)     (0)

/*****************************************************************************/
/**
 *
 * This macro is not yet implemented and always returns 0.
 *
 * @param   Stamp1Ptr is the first sampled time stamp.
 * @param   Stamp2Ptr is the second sampled time stamp.
 *
 * @return  0
 *
 * @note
 *
 * This macro must be implemented by the user.
 *
 *****************************************************************************/
#define XENV_TIME_STAMP_DELTA_MS(Stamp1Ptr, Stamp2Ptr)     (0)

/*****************************************************************************/
/**
 *
 * XENV_USLEEP(unsigned delay)
 *
 * Delay the specified number of microseconds. Not implemented without OS
 * support.
 *
 * @param   delay is the number of microseconds to delay.
 *
 * @return  None.
 *
 * @note    If PowerPC, use usleep for the sleep macro, otherwise a no-op.
 *
 *****************************************************************************/
#ifdef __PPC__
#define XENV_USLEEP(delay) usleep(delay)
#else
#define XENV_USLEEP(delay)
#endif

/******************************************************************************
 *
 * CACHE handling macros / mappings
 *
 ******************************************************************************/
/******************************************************************************
 *
 * Processor independent macros
 *
 ******************************************************************************/

#define XCACHE_ENABLE_CACHE()	\
		{ XCACHE_ENABLE_DCACHE(); XCACHE_ENABLE_ICACHE(); }

#define XCACHE_DISABLE_CACHE()	\
		{ XCACHE_DISABLE_DCACHE(); XCACHE_DISABLE_ICACHE(); }


/******************************************************************************
 *
 * MicroBlaze case
 *
 * NOTE: Currently the following macros will only work on systems that contain
 * only ONE MicroBlaze processor. Also, the macros will only be enabled if the
 * system is built using a xparameters.h file.
 *
 ******************************************************************************/

#if defined __MICROBLAZE__

/* Check if MicroBlaze data cache was built into the core.
 */
#if XPAR_MICROBLAZE_USE_DCACHE == 1
#  define XCACHE_ENABLE_DCACHE()	microblaze_enable_dcache()
#  define XCACHE_DISABLE_DCACHE()	microblaze_disable_dcache()
#  define XCACHE_INVALIDATE_DCACHE_RANGE(Addr, Len) \
					microblaze_init_dcache_range(Addr, Len)

/* MicroBlaze Cache is write-through for v4, v5 and v6. We define the FLUSH
 * macro blank. For other versions (v7 and following as they emerge) we may
 * need to add additional checks here if the cache policy changes.
 */
#  define XCACHE_FLUSH_DCACHE_RANGE(Addr, Len)

#else
#  define XCACHE_ENABLE_DCACHE()
#  define XCACHE_DISABLE_DCACHE()
#  define XCACHE_INVALIDATE_DCACHE_RANGE(Addr, Len)
#  define XCACHE_FLUSH_DCACHE_RANGE(Addr, Len)
#endif


/* Check if MicroBlaze instruction cache was built into the core.
 */
#if XPAR_MICROBLAZE_USE_ICACHE == 1
#  define XCACHE_ENABLE_ICACHE()	microblaze_enable_icache()
#  define XCACHE_DISABLE_ICACHE()	microblaze_disable_icache()
#else
#  define XCACHE_ENABLE_ICACHE()
#  define XCACHE_DISABLE_ICACHE()
#endif


/******************************************************************************
 *
 * PowerPC case
 *
 *   Note that the XCACHE_ENABLE_xxx functions are hardcoded to enable a
 *   specific memory region (0x80000001). Each bit (0-30) in the regions
 *   bitmask stands for 128MB of memory. Bit 31 stands for the upper 2GB
 *   range.
 *
 *   regions    --> cached address range
 *   ------------|--------------------------------------------------
 *   0x80000000  | [0, 0x7FFFFFF]
 *   0x00000001  | [0xF8000000, 0xFFFFFFFF]
 *   0x80000001  | [0, 0x7FFFFFF],[0xF8000000, 0xFFFFFFFF]
 *
 ******************************************************************************/

#elif defined __PPC__

#define XCACHE_ENABLE_DCACHE()		XCache_EnableDCache(0x80000001)
#define XCACHE_DISABLE_DCACHE()		XCache_DisableDCache()
#define XCACHE_ENABLE_ICACHE()		XCache_EnableICache(0x80000001)
#define XCACHE_DISABLE_ICACHE()		XCache_DisableICache()

#define XCACHE_INVALIDATE_DCACHE_RANGE(Addr, Len) \
    {                                             \
        const unsigned cacheline = 32;            \
        unsigned int end;                         \
        unsigned int adr = (unsigned int)Addr;    \
        unsigned int len = (unsigned int)Len;     \
                                                  \
        if (len != 0)                             \
        {                                         \
            end = adr + len;                      \
            adr = adr & ~(cacheline - 1);         \
                                                  \
            while (adr < end)                     \
            {                                     \
                XCache_InvalidateDCacheLine(adr); \
                adr += cacheline;                 \
            }                                     \
        }                                         \
    }

#define XCACHE_FLUSH_DCACHE_RANGE(Addr, Len)      \
    {                                             \
        const unsigned cacheline = 32;            \
        unsigned int end;                         \
        unsigned int adr = (unsigned int)Addr;    \
        unsigned int len = (unsigned int)Len;     \
                                                  \
        if (len != 0)                             \
        {                                         \
            end = adr + len;                      \
            adr = adr & ~(cacheline - 1);         \
                                                  \
            while (adr < end)                     \
            {                                     \
                XCache_FlushDCacheLine(adr);      \
                adr += cacheline;                 \
            }                                     \
        }                                         \
    }

#define XCACHE_INVALIDATE_ICACHE()	XCache_InvalidateICache()


/******************************************************************************
 *
 * Unknown processor / architecture
 *
 ******************************************************************************/

#else
#error "Unknown processor / architecture. Must be MicroBlaze or PowerPC."
#endif

#ifdef __cplusplus
}
#endif

#endif            /* end of protection macro */

