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

int main (void) {
	int i;
	initializeSound();
	sounds[AMove1] = createSound("a:\\AMove1.wav");
	sounds[AMove2] = createSound("a:\\AMove2.wav");
	sounds[AMove3] = createSound("a:\\AMove3.wav");
	sounds[AMove4] = createSound("a:\\AMove4.wav");
	sounds[Fire] = createSound("a:\\fire.wav");
	sounds[TankExplode] = createSound("a:\\TankXplo.wav");
	sounds[SpaceShip] = createSound("a:\\SHigh2.wav");
	sounds[SpaceShipHit] = createSound("a:\\SLow.wav");
	while(1){
		for(i = 0; i < 8; i++){
			playSound(sounds[i]);
			playSilenceMS(1000);
		}
	}
}