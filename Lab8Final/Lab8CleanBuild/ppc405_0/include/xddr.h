/* $Id: xddr.h,v 1.3 2005/09/22 22:24:31 trujillo Exp $ */
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
* @file xddr.h
*
* This header file contains interface for the DDR device driver.  This device
* driver is not necessary for the DDR device unless ECC is being used.
*
* ECC (Error Correction Code) is a mode that detects and corrects some memory
* errors.  This device driver provides the following abilities.
*  - Enable and disable ECC mode
*  - Enable and disable interrupts for specific ECC errors
*  - Error injection for testing of ECC mode
*  - Statistics for specific ECC errors detected
*
* The Xilinx DDR controller is a soft IP core designed for Xilinx FPGAs on
* the OPB or PLB bus. The OPB DDR device does not currently support ECC such
* that there would be no reason to use this driver for the device.
*
*<b> Hardware Parameters Needed</b>
*
* In order for the driver to be used with the hardware device, ECC registers
* must be enabled in the hardware.
*
* The interrupt capability for the device must be enabled in the hardware
* if interrupts are to be used with the driver.  The interrupt functions of
* the device driver will assert when called if interrupt support is not
* present in the hardware.
*
* The ability to force errors is a test mode and it must be enabled
* in the hardware if the control register is to be used to force ECC errors.
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

#ifndef XDDR_H /* prevent circular inclusions */
#define XDDR_H /* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "xddr_l.h"
#include "xbasic_types.h"
#include "xio.h"
#include "xstatus.h"

/************************** Constant Definitions *****************************/


/**************************** Type Definitions *******************************/

/*
 * This typedef contains configuration information for the device.
 */
typedef struct
{
    Xuint16 DeviceId;
    Xuint32 BaseAddress;
    Xboolean InterruptPresent;
} XDdr_Config;

/**
 * The XDdr driver stats data. A pointer to a variable of this type is
 * passed to the driver API functions.
 */
typedef struct
{
   Xuint16 SingleErrorCount;
   Xuint16 DoubleErrorCount;
   Xuint16 ParityErrorCount;
} XDdr_Stats;

/**
 * The XDdr driver instance data. The user is required to allocate a
 * variable of this type for every DDR device in the system. A pointer
 * to a variable of this type is then passed to the driver API functions.
 */
typedef struct
{
    Xuint32 BaseAddress;            /**< Base address of registers */
    Xuint32 IsReady;                /**< Device is initialized and ready */
    XDdr_Config *ConfigPtr;
} XDdr;

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/

/************************** Variable Definitions *****************************/

/*
 * API Basic functions implemented in xddr.c
 */
XStatus XDdr_Initialize(XDdr *InstancePtr, Xuint16 DeviceId);
void    XDdr_EnableEcc(XDdr *InstancePtr);
void    XDdr_DisableEcc(XDdr *InstancePtr);

void    XDdr_SetControl(XDdr *InstancePtr, Xuint32 Control);
Xuint32 XDdr_GetControl(XDdr *InstancePtr);
Xuint32 XDdr_GetStatus(XDdr *InstancePtr);
void    XDdr_ClearStatus(XDdr *InstancePtr);

XDdr_Config *XDdr_LookupConfig(Xuint16 DeviceId);

/*
 * API Functions implemented in xddr_stats.c
 */
void    XDdr_GetStats(XDdr *InstancePtr, XDdr_Stats *StatsPtr);
void    XDdr_ClearStats(XDdr *InstancePtr);

/*
 * API Functions implemented in xddr_selftest.c
 */
XStatus XDdr_SelfTest(XDdr *InstancePtr);

/*
 * API Functions implemented in xddr_intr.c
 */
void    XDdr_InterruptGlobalEnable(XDdr *InstancePtr);
void    XDdr_InterruptGlobalDisable(XDdr *InstancePtr);

void    XDdr_InterruptEnable(XDdr *InstancePtr, Xuint32 Mask);
void    XDdr_InterruptDisable(XDdr *InstancePtr, Xuint32 Mask);
void    XDdr_InterruptClear(XDdr *InstancePtr, Xuint32 Mask);
Xuint32 XDdr_InterruptGetEnabled(XDdr *InstancePtr);
Xuint32 XDdr_InterruptGetStatus(XDdr *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif            /* end of protection macro */

