
/*******************************************************************
*
* CAUTION: This file is automatically generated by libgen.
* Version: Xilinx EDK 9.1.02 EDK_J_SP2.4
* DO NOT EDIT.
*
* Copyright (c) 2005 Xilinx, Inc.  All rights reserved. 
* 
* Description: Driver parameters
*
*******************************************************************/

#define STDIN_BASEADDRESS 0x40600000
#define STDOUT_BASEADDRESS 0x40600000

/******************************************************************/

/* Definitions for driver UARTLITE */
#define XPAR_XUARTLITE_NUM_INSTANCES 1

/* Definitions for peripheral RS232_UART_1 */
#define XPAR_RS232_UART_1_BASEADDR 0x40600000
#define XPAR_RS232_UART_1_HIGHADDR 0x4060FFFF
#define XPAR_RS232_UART_1_DEVICE_ID 0
#define XPAR_RS232_UART_1_BAUDRATE 9600
#define XPAR_RS232_UART_1_USE_PARITY 0
#define XPAR_RS232_UART_1_ODD_PARITY 0
#define XPAR_RS232_UART_1_DATA_BITS 8


/******************************************************************/

#define XPAR_XSYSACE_MEM_WIDTH 16
/* Definitions for driver SYSACE */
#define XPAR_XSYSACE_NUM_INSTANCES 1

/* Definitions for peripheral SYSACE_COMPACTFLASH */
#define XPAR_SYSACE_COMPACTFLASH_BASEADDR 0x41800000
#define XPAR_SYSACE_COMPACTFLASH_HIGHADDR 0x4180FFFF
#define XPAR_SYSACE_COMPACTFLASH_DEVICE_ID 0
#define XPAR_SYSACE_COMPACTFLASH_MEM_WIDTH 16


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 3

/* Definitions for peripheral LEDS_4BIT */
#define XPAR_LEDS_4BIT_BASEADDR 0x40040000
#define XPAR_LEDS_4BIT_HIGHADDR 0x4004FFFF
#define XPAR_LEDS_4BIT_DEVICE_ID 0
#define XPAR_LEDS_4BIT_INTERRUPT_PRESENT 0
#define XPAR_LEDS_4BIT_IS_DUAL 0


/* Definitions for peripheral DIPSWS_4BIT */
#define XPAR_DIPSWS_4BIT_BASEADDR 0x40020000
#define XPAR_DIPSWS_4BIT_HIGHADDR 0x4002FFFF
#define XPAR_DIPSWS_4BIT_DEVICE_ID 1
#define XPAR_DIPSWS_4BIT_INTERRUPT_PRESENT 0
#define XPAR_DIPSWS_4BIT_IS_DUAL 0


/* Definitions for peripheral PUSHBUTTONS_5BIT */
#define XPAR_PUSHBUTTONS_5BIT_BASEADDR 0x40000000
#define XPAR_PUSHBUTTONS_5BIT_HIGHADDR 0x4000FFFF
#define XPAR_PUSHBUTTONS_5BIT_DEVICE_ID 2
#define XPAR_PUSHBUTTONS_5BIT_INTERRUPT_PRESENT 1
#define XPAR_PUSHBUTTONS_5BIT_IS_DUAL 0


/******************************************************************/

#define XPAR_INTC_MAX_NUM_INTR_INPUTS 2
#define XPAR_XINTC_HAS_IPR 1
#define XPAR_XINTC_USE_DCR 0
/* Definitions for driver INTC */
#define XPAR_XINTC_NUM_INSTANCES 1

/* Definitions for peripheral OPB_INTC_0 */
#define XPAR_OPB_INTC_0_BASEADDR 0x41200000
#define XPAR_OPB_INTC_0_HIGHADDR 0x4120FFFF
#define XPAR_OPB_INTC_0_DEVICE_ID 0
#define XPAR_OPB_INTC_0_KIND_OF_INTR 0x00000000


/******************************************************************/

#define XPAR_INTC_SINGLE_BASEADDR 0x41200000
#define XPAR_INTC_SINGLE_HIGHADDR 0x4120FFFF
#define XPAR_INTC_SINGLE_DEVICE_ID XPAR_OPB_INTC_0_DEVICE_ID
#define XPAR_AUDIO_CODEC_INTERRUPT_MASK 0X000001
#define XPAR_OPB_INTC_0_AUDIO_CODEC_INTERRUPT_INTR 0
#define XPAR_PUSHBUTTONS_5BIT_IP2INTC_IRPT_MASK 0X000002
#define XPAR_OPB_INTC_0_PUSHBUTTONS_5BIT_IP2INTC_IRPT_INTR 1

/******************************************************************/

/* Definitions for driver TFT_REF */
#define XPAR_XTFT_NUM_INSTANCES 1

/* Definitions for peripheral VGA_FRAMEBUFFER */
#define XPAR_VGA_FRAMEBUFFER_DCR_BASEADDR 0x41818800
#define XPAR_VGA_FRAMEBUFFER_DCR_HIGHADDR 0x41818807
#define XPAR_VGA_FRAMEBUFFER_DEVICE_ID 0


/******************************************************************/

/* Definitions for driver AC97 */
#define XPAR_XAC97_NUM_INSTANCES 1

/* Definitions for peripheral AUDIO_CODEC */
#define XPAR_AUDIO_CODEC_BASEADDR 0x7D400000
#define XPAR_AUDIO_CODEC_HIGHADDR 0x7D40FFFF


/******************************************************************/

/* Definitions for driver DDR */
#define XPAR_XDDR_NUM_INSTANCES 1

/* Definitions for peripheral DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5 */
#define XPAR_DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5_ECC_BASEADDR 0xFFFFFFFF
#define XPAR_DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5_ECC_HIGHADDR 0x00000000
#define XPAR_DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5_DEVICE_ID 0
#define XPAR_DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5_INCLUDE_ECC_INTR 0


/******************************************************************/

/* Definitions for peripheral DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5 */
#define XPAR_DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5_MEM0_BASEADDR 0x00000000
#define XPAR_DDR_256MB_32MX64_RANK1_ROW13_COL10_CL2_5_MEM0_HIGHADDR 0x0FFFFFFF

/******************************************************************/


/* Definitions for peripheral PLB_BRAM_IF_CNTLR_1 */
#define XPAR_PLB_BRAM_IF_CNTLR_1_BASEADDR 0xfffe0000
#define XPAR_PLB_BRAM_IF_CNTLR_1_HIGHADDR 0xffffffff


/******************************************************************/

#define XPAR_CPU_PPC405_CORE_CLOCK_FREQ_HZ 100000000

/******************************************************************/

#define XPAR_CPU_ID 0
#define XPAR_PPC405_ID 0
#define XPAR_PPC405_CORE_CLOCK_FREQ_HZ 100000000
#define XPAR_PPC405_ISOCM_DCR_BASEADDR 0x00000010
#define XPAR_PPC405_ISOCM_DCR_HIGHADDR 0x00000013
#define XPAR_PPC405_DSOCM_DCR_BASEADDR 0x00000020
#define XPAR_PPC405_DSOCM_DCR_HIGHADDR 0x00000023
#define XPAR_PPC405_DISABLE_OPERAND_FORWARDING 1
#define XPAR_PPC405_DETERMINISTIC_MULT 0
#define XPAR_PPC405_MMU_ENABLE 1
#define XPAR_PPC405_DCR_RESYNC 0
#define XPAR_PPC405_HW_VER "2.00.c"

/******************************************************************/

#define XILFATFS_MAXFILES 5
#define XILFATFS_BUFCACHE_SIZE 10240
