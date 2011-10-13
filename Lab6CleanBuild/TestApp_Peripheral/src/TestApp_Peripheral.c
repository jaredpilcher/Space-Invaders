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
#include "sysace_stdio.h"
#include "xac97_l.h"

#include "game_sounds2.h"
#define GPIO_CHANNEL1 1

//====================================================

int main (void) {


	
   XAC97_mSetControl(XPAR_AUDIO_CODEC_BASEADDR, AC97_ENABLE_RESET_AC97);
   usleep(100);
   XAC97_mSetControl(XPAR_AUDIO_CODEC_BASEADDR, AC97_DISABLE_RESET_AC97);
   usleep(100);
   XAC97_SoftReset(XPAR_AUDIO_CODEC_BASEADDR);

	XAC97_AwaitCodecReady(XPAR_AUDIO_CODEC_BASEADDR);
	XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_MasterVol,0x0a0a);
	int i = 0;
	while(1){
		if(!XAC97_isInFIFOFull(XPAR_AUDIO_CODEC_BASEADDR)){
			XAC97_mSetInFifoData(XPAR_AUDIO_CODEC_BASEADDR,shoot_wav_sound[i]);
			i++;
		}
		if (i >= SHOOT_WAV_LEN){
				i = 0;
				usleep(1000000);
		}
	}
		
	
	SYSACE_FILE * infile;
	char * audiobuffer = 0x00600000;
	int numread;
	infile = sysace_fopen("a:\\fire.wav", "r");
	if(infile) {
		xil_printf("Reading file : %s\n\r", "a:\\fire.wav");
		int total_to_read = 500;
		numread = sysace_fread(audiobuffer, 2, total_to_read, infile);
		int i;
		for(i = 0; i < total_to_read; i++){
			xil_printf("%x ",audiobuffer[i]);
		}
		print("\n\r");
		sysace_fclose(infile);
	}
	
}