/* $Id: xddr_l.h,v 1.3 2005/09/22 22:24:31 trujillo Exp $ */
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
*       (c) Copyright 2003 - 2004 Xilinx Inc.
*       All rights reserved.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file xddr_l.h
*
* This header file contains identifiers and low-level driver functions for the
* DDR device driver.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.00a jhl  12/24/03 First release
* </pre>
*
******************************************************************************/

#ifndef XDDR_L_H /* prevent circular inclusions */
#define XDDR_L_H /* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "xbasic_types.h"
#include "xio.h"

/************************** Constant Definitions *****************************/

/** @name Register offsets
 * @{
 */
#define XDDR_ECCCR_OFFSET      0x0  /**< Control Register */
#define XDDR_ECCSR_OFFSET      0x4  /**< Status Register */
#define XDDR_ECCSEC_OFFSET     0x8  /**< Single Error Count Register */
#define XDDR_ECCDEC_OFFSET     0xC  /**< Double Error Count Register */
#define XDDR_ECCPEC_OFFSET     0x10 /**< Parity Field Error Count Register */
#define XDDR_ECCSETR_OFFSET    0x14 /**< Single Error Interrupt Threshold
                                         Register */
#define XDDR_ECCPETR_OFFSET    0x18 /**< Parity Error Interrupt Threshold
                                         Register */
#define XDDR_IPIF_OFFSET       0x100/**< IPIF Registers */

/* The following offsets are from the start of the IPIF in the device
 * such that these offsets must be added to the IPIF offset
 */

#define XDDR_DGIE_OFFSET       0x1C /**< Device Global Interrupt Enable Register */
#define XDDR_IPISR_OFFSET      0x20 /**< IP Interrupt Status Register */
#define XDDR_IPIER_OFFSET      0x28 /**< IP Interrupt Enable Register */
/*@}*/

/** @name ECC Control Register bitmaps and masks
 *
 * @{
 */
#define XDDR_ECCCR_FORCE_PE_MASK 0x10    /**< Force parity error */
#define XDDR_ECCCR_FORCE_DE_MASK 0x08    /**< Force double bit error */
#define XDDR_ECCCR_FORCE_SE_MASK 0x04    /**< Force single bit error */
#define XDDR_ECCCR_RE_MASK       0x02    /**< ECC read enable */
#define XDDR_ECCCR_WE_MASK       0x01    /**< ECC write enable */
/*@}*/

/** @name ECC Status Register bitmaps and masks
 *
 * @{
 */
#define XDDR_ECCSR_SE_SYND_MASK 0x3F8   /**< Single bit error syndrome */
#define XDDR_ECCSR_PE_MASK      0x004   /**< Parity field bit error */
#define XDDR_ECCSR_DE_MASK      0x002   /**< Double bit error */
#define XDDR_ECCSR_SE_MASK      0x001   /**< Single bit error */
/*@}*/

/** @name Device Global Interrupt Enable Register bitmaps and masks
 *
 * Bit definitions for the global interrupt enable register.
 * @{
 */
#define XDDR_DGIE_GIE_MASK      0x80000000  /**< Global interrupt enable */
/*@}*/

/** @name Interrupt Status and Enable Register bitmaps and masks
 *
 * Bit definitions for the interrupt status register and interrupt enable
 * registers.
 * @{
 */
#define XDDR_IPIXR_PE_IX_MASK   0x4     /**< Parity field error interrupt */
#define XDDR_IPIXR_DE_IX_MASK   0x2     /**< Double bit error interrupt */
#define XDDR_IPIXR_SE_IX_MASK   0x1     /**< Single bit error interrupt */
/*@}*/

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/


/****************************************************************************/
/**
*
* Write a value to a DDR register. A 32 bit write is performed.
*
* @param   BaseAddress is the base address of the DDR device.
* @param   RegOffset is the register offset from the base to write to.
* @param   Data is the data written to the register.
*
* @return  None.
*
* @note    None.
*
* C-style signature:
*    void XDdr_mWriteReg(Xuint32 BaseAddress, unsigned RegOffset,
*                        Xuint32 Data)
*
****************************************************************************/
#define XDdr_mWriteReg(BaseAddress, RegOffset, Data) \
    (XIo_Out32((BaseAddress) + (RegOffset), (Xuint32)(Data)))

/****************************************************************************/
/**
*
* Read a value from a DDR register. A 32 bit read is performed.
*
* @param   BaseAddress is the base address of the DDR device.
* @param   Register is the register offset from the base to read from.
*
* @return  The value read from the register.
*
* @note    None.
*
* C-style signature:
*    Xuint32 XDdr_mReadReg(Xuint32 BaseAddress, unsigned RegOffset)
*
****************************************************************************/
#define XDdr_mReadReg(BaseAddress, RegOffset) \
    (XIo_In32((BaseAddress) + (RegOffset)))

/************************** Function Prototypes ******************************/

/************************** Variable Definitions *****************************/

#ifdef __cplusplus
}
#endif

#endif            /* end of protection macro */

