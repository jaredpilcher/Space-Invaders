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

#include "sound.h"
#include "game_sounds2.h"
#define GPIO_CHANNEL1 1

#define FILE_LENGTH 15000

#define WAV_LEN 5000
//====================================================

int * tempSpace = 0x00600000;
int * nextFreeAddress = 0x00800000;
enum sound_enum { AMove1, AMove2, AMove3, AMove4, Fire, TankExplode, SpaceShip, SpaceShipHit };
Sound sounds[20];

Sound * current_sound;

void bufferUnderrun(XIntc * device){
	XIntc_Disable(device, XPAR_OPB_INTC_0_AUDIO_CODEC_INTERRUPT_INTR);
	XIntc_Acknowledge(device, XPAR_OPB_INTC_0_AUDIO_CODEC_INTERRUPT_INTR);
	if(current_sound){
		int result = fillFIFOWithSound(current_sound);
		xil_printf("Result: %d\n\r", result);
		if (result == 0){
			current_sound = 0;
		}
	} else {
		fillFIFOWithSilence();
	}
	XIntc_Enable(device, XPAR_OPB_INTC_0_AUDIO_CODEC_INTERRUPT_INTR);
}

int main (void) {
	print("round asfklawer\n\r");
	int i;
	void * data;
	XIntc ac97_opb;
	initializeSound();
	XIntc_Initialize(&ac97_opb, XPAR_INTC_SINGLE_DEVICE_ID);
	XIntc_Start(&ac97_opb,XIN_REAL_MODE);
	XIntc_Connect(&ac97_opb, XPAR_OPB_INTC_0_AUDIO_CODEC_INTERRUPT_INTR, bufferUnderrun, &ac97_opb);
	sounds[AMove1] = createSound("a:\\AMove1.wav");
	sounds[AMove2] = createSound("a:\\AMove2.wav");
	sounds[AMove3] = createSound("a:\\AMove3.wav");
	sounds[AMove4] = createSound("a:\\AMove4.wav");
	sounds[Fire] = createSound("a:\\fire.wav");
	sounds[TankExplode] = createSound("a:\\TankXplo.wav");
	sounds[SpaceShip] = createSound("a:\\SHigh2.wav");
	sounds[SpaceShipHit] = createSound("a:\\SLow.wav");
	playSound(sounds[Fire]);
	XExc_Init();
	XExc_mEnableExceptions(XEXC_NON_CRITICAL);
	XExc_RegisterHandler(XEXC_ID_NON_CRITICAL_INT, XIntc_InterruptHandler , &ac97_opb);
	XIntc_Enable(&ac97_opb, XPAR_OPB_INTC_0_AUDIO_CODEC_INTERRUPT_INTR);
	while(1){
		usleep(1000000);
		xil_printf("Fire Value: %d",sounds[Fire].current_sample);
		current_sound = &sounds[Fire];
		print("Play Fire\n\r");
		usleep(1000000);
		current_sound = 0;
		print("Play Silence\n\r");
	}
}