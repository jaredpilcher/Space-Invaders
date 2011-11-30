/* $Id: xintc_options.c,v 1.2 2005/01/04 17:48:57 moleres Exp $ */
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
* @file xintc_options.c
*
* Contains option functions for the XIntc driver. These functions allow the
* user to configure an instance of the XIntc driver.  This file requires other
* files of the component to be linked in also.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------------
* 1.00b jhl  02/21/02 First release
* 1.00c rpm  10/17/03 New release. Support the relocation of the options flag
*                     from the instance structure to the xintc_g.c
*                     configuration table.
* </pre>
*
******************************************************************************/

/***************************** Include Files *********************************/

#include "xbasic_types.h"
#include "xintc.h"

/************************** Constant Definitions *****************************/


/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/


/************************** Function Prototypes ******************************/


/************************** Variable Definitions *****************************/


/*****************************************************************************/
/**
*
* Set the options for the interrupt controller driver.
*
* @param    InstancePtr is a pointer to the XIntc instance to be worked on.
* @param    Options to be set. The available options are described in xintc.h.
*
* @return
*
* - XST_SUCCESS if the options were set successfully
* - XST_INVALID_PARAM if the specified option was not valid
*
* @note
*
* None.
*
****************************************************************************/
XStatus XIntc_SetOptions(XIntc *InstancePtr, Xuint32 Options)
{

    XASSERT_NONVOID(InstancePtr != XNULL);
    XASSERT_NONVOID(InstancePtr->IsReady == XCOMPONENT_IS_READY);

    /*
     * make sure option request is valid
     */
    if ((Options == XIN_SVC_SGL_ISR_OPTION) ||
        (Options == XIN_SVC_ALL_ISRS_OPTION))
    {
        InstancePtr->CfgPtr->Options = Options;
        return XST_SUCCESS;
    }
    else
    {
        return XST_INVALID_PARAM;
    }
}

/*****************************************************************************/
/**
*
* Return the currently set options.
*
* @param    InstancePtr is a pointer to the XIntc instance to be worked on.
*
* @return
*
* The currently set options. The options are described in xintc.h.
*
* @note
*
* None.
*
****************************************************************************/
Xuint32 XIntc_GetOptions(XIntc *InstancePtr)
{
    /*
     * assert the arguments
     */
    XASSERT_NONVOID(InstancePtr != XNULL);
    XASSERT_NONVOID(InstancePtr->IsReady == XCOMPONENT_IS_READY);

    return InstancePtr->CfgPtr->Options;
}

