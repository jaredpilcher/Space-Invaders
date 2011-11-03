/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * Xilinx EDK 9.1.02 EDK_J_SP2.4
 *
 * This file is a sample test application
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * XPS project when you run the "Generate Libraries" menu item
 * in XPS.
 *
 * Your XPS project directory is at:
 *    C:\Lab5CleanBuild\
 */


// Located in: ppc405_0/include/xparameters.h
#include "xparameters.h"


#include "stdio.h"

#include "xintc.h"
#include "xexception_l.h"
#include "intc_header.h"
#include "xsysace.h"
#include "sysace_header.h"
#include "xbasic_types.h"
#include "xgpio.h"
#include "gpio_header.h"
#include "gpio_intr_header.h"

#define GPIO_CHANNEL1 1

//====================================================

void disableSlaveInterrupt(){
	Xint32 ier = XIntc_In32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET);
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET, (ier & ~XPAR_LAB3_SLAVE_0_INTERRUPTREQUEST_MASK));
//	XIo_Out32(0x40080000 + 16, 0);
}

void enableSlaveInterrupt(){
	Xint32 ier = XIntc_In32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET);
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET, (ier | XPAR_LAB3_SLAVE_0_INTERRUPTREQUEST_MASK));
	XIo_Out32(0x40080000 + 16, 1);
}

void acknowledgeSlaveInterrupts(){

	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IAR_OFFSET, XPAR_LAB3_SLAVE_0_INTERRUPTREQUEST_MASK);
	XIo_Out32(0x40080000 + 12, 1);
}

void clearSlaveInterrupts(){
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_MER_OFFSET, 0);
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET, 0);
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IAR_OFFSET, 0xFFFFFFFF);
	XIo_Out32(0x40080000 + 16, 0);
}

void initializeMER(){
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_MER_OFFSET, XIN_INT_MASTER_ENABLE_MASK | XIN_INT_HARDWARE_ENABLE_MASK);
}

void testHandler(XIntc * device){
	disableSlaveInterrupt();
	//xil_printf("ack: %x \n\r", XIo_In32(0x40080000 + 12));
	acknowledgeSlaveInterrupts();
	print("interrupt occured\n");
	enableSlaveInterrupt();
	//XIntc_Enable(device, XPAR_OPB_INTC_0_AUDIO_CODEC_INTERRUPT_INTR);
}

int to_hex_display(int value){
	int d0 = value % 10;
	int d1 = (value % 100)/10;
	int d2 = (value % 1000)/100;
	int d3 = (value % 10000)/1000;
	return d0 + 16*d1 + 16*16*d2 + 16*16*16*d3;
}
int main (void) {
	XIntc dud;
	clearSlaveInterrupts();
	acknowledgeSlaveInterrupts();
	initializeMER();
	XExc_Init();
	XIo_Out32(0x40080050, 16000000);
	XExc_mEnableExceptions(XEXC_NON_CRITICAL);
	XExc_RegisterHandler(XEXC_ID_NON_CRITICAL_INT, testHandler , &dud);
	enableSlaveInterrupt();
	
	int value = 4379;

	XIo_Out32(0x40080000, to_hex_display(4379));
//	int ack = XIo_In32(0x40080000 + 12);
//	int int_en = XIo_In32(0x40080000 + 16);
//	xil_printf("ack value: %x int_en value: %x\n\r",ack, int_en);
//	char c;
//	print("push a button\n\r");
//	read(0,&c,1);
//	
//	ack = XIo_In32(0x40080000 + 12);
//	int_en = XIo_In32(0x40080000 + 16);
//	xil_printf("ack value: %x int_en value: %x\n\r",ack, int_en);
//	XIo_Out32(0x40080000 + 16, 1);
//	print("enabled interrupts\n\r");
//	int_en = XIo_In32(0x40080000 + 16);
//	xil_printf("ack value: %x int_en value: %x\n\r",ack, int_en);
//	print("push a button\n\r");
//	read(0,&c,1);
//	
//	ack = XIo_In32(0x40080000 + 12);
//	int_en = XIo_In32(0x40080000 + 16);
//	xil_printf("ack value: %x int_en value: %x\n\r",ack, int_en);
//	print("acknowledging interrupt\n\r");
//	XIo_Out32(0x40080000 + 12, 1);
//	ack = XIo_In32(0x40080000 + 12);
//	int_en = XIo_In32(0x40080000 + 16);
//	xil_printf("ack value: %x int_en value: %x\n\r",ack, int_en);
	
	while(1){
//		char c;
//		xil_printf("LEDS: %x\n\r", XIo_In32(0x40080000 + 40));
//		read(0,&c,1);
//		XIo_Out32;
	}
	
//   static XIntc intc;

//   static XGpio PushButtons_5Bit_Gpio;
//   print("-- Entering main() --\r\n");
//
//
//   {
//      XStatus status;
//      
//      print("\r\n Runnning IntcSelfTestExample() for opb_intc_0...\r\n");
//      
//      status = IntcSelfTestExample(XPAR_OPB_INTC_0_DEVICE_ID);
//      
//      if (status == 0) {
//         print("IntcSelfTestExample PASSED\r\n");
//      }
//      else {
//         print("IntcSelfTestExample FAILED\r\n");
//      }
//   } 
//	
//   {
//       XStatus Status;
//
//       Status = IntcInterruptSetup(&intc, XPAR_OPB_INTC_0_DEVICE_ID);
//       if (Status == 0) {
//          print("Intc Interrupt Setup PASSED\r\n");
//       } 
//       else {
//         print("Intc Interrupt Setup FAILED\r\n");
//      } 
//   }
//
//   /*
//    * Peripheral SelfTest will not be run for RS232_Uart_1
//    * because it has been selected as the STDOUT device
//    */
//
//
//
//   {
//      XStatus status;
//      
//      print("\r\nRunning SysAceSelfTestExample() for SysACE_CompactFlash...\r\n");
//      status = SysAceSelfTestExample(XPAR_SYSACE_COMPACTFLASH_DEVICE_ID);
//      if (status == 0) {
//         print("SysAceSelfTestExample PASSED\r\n");
//      }
//      else {
//         print("SysAceSelfTestExample FAILED\r\n");
//      }
//   }
//
//
//   {
//      Xuint32 status;
//      
//      print("\r\nRunning GpioOutputExample() for LEDs_4Bit...\r\n");
//
//      status = GpioOutputExample(XPAR_LEDS_4BIT_DEVICE_ID,4);
//      
//      if (status == 0) {
//         print("GpioOutputExample PASSED.\r\n");
//      }
//      else {
//         print("GpioOutputExample FAILED.\r\n");
//      }
//   }
//
//
//   {
//      Xuint32 status;
//      
//      print("\r\nRunning GpioInputExample() for DIPSWs_4Bit...\r\n");
//
//      Xuint32 DataRead;
//      
//      status = GpioInputExample(XPAR_DIPSWS_4BIT_DEVICE_ID, &DataRead);
//      
//      if (status == 0) {
//         xil_printf("GpioInputExample PASSED. Read data:0x%X\r\n", DataRead);
//      }
//      else {
//         print("GpioInputExample FAILED.\r\n");
//      }
//   }
//
//
//   {
//      Xuint32 status;
//      
//      print("\r\nRunning GpioInputExample() for PushButtons_5Bit...\r\n");
//
//      Xuint32 DataRead;
//      
//      status = GpioInputExample(XPAR_PUSHBUTTONS_5BIT_DEVICE_ID, &DataRead);
//      
//      if (status == 0) {
//         xil_printf("GpioInputExample PASSED. Read data:0x%X\r\n", DataRead);
//      }
//      else {
//         print("GpioInputExample FAILED.\r\n");
//      }
//   }
//   {
//      
//      XStatus Status;
//        
//      Xuint32 DataRead;
//      
//      print(" Press button to Generate Interrupt\r\n");
//      
//      Status = GpioIntrExample(&intc, &PushButtons_5Bit_Gpio, \
//                               XPAR_PUSHBUTTONS_5BIT_DEVICE_ID, \
//                               XPAR_OPB_INTC_0_PUSHBUTTONS_5BIT_IP2INTC_IRPT_INTR, \
//                               GPIO_CHANNEL1, &DataRead);
//	
//      if (Status == 0 ){
//             if(DataRead == 0)
//                print("No button pressed. \r\n");
//             else
//                print("Gpio Interrupt Test PASSED. \r\n"); 
//      } 
//      else {
//         print("Gpio Interrupt Test FAILED.\r\n");
//      }
//	
//   }
//
//   print("-- Exiting main() --\r\n");
//   return 0;
}

