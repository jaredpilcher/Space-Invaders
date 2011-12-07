#include <stdlib.h>
#include "xparameters.h"
#include "xuartlite_l.h"
#include "xtft_l.h"
#include "xsysace.h"
#include "xgpio.h"

#include "stdio.h"
#include "xutil.h"
#include "xexception_l.h"
#include "xintc.h"

#include "gameParameters.h"
#include "xcache_l.h"

//#include "OPB_Int.h"
#include "sound.h"


//int * tempSpace = 0x00800000;
//int * nextFreeAddress;
//Sound * current_sound;
enum sound_enum { AMove1, AMove2, AMove3, AMove4, Fire, TankExplode, SpaceShip, SpaceShipHit };
Sound sounds[20];
// int main() {
  // print("Starting up\n\r");
  // // int enable = XIo_In32(XPAR_AUDIO_DMA_0_BASEADDR + 4);
  // // int idle = XIo_In32(XPAR_AUDIO_DMA_0_BASEADDR + 8);
  // // int zero = XIo_In32(XPAR_AUDIO_DMA_0_BASEADDR + 12);
  // // usleep(1000000);
  // // print("Current state:\n\r");
  // // usleep(1000000);
  // // xil_printf("enable: %x\n\r", enable);
  // // usleep(1000000);
  // // xil_printf("idle: %x zero: %x\n\r", idle, zero);
  // // usleep(1000000);
  // int i;
  // for(i = 0; i< 10; i++){
	// XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 1);
	// usleep(10000);
  // }
  // print("\n\rDone\n\r");
  // while(1){};
// }


int maint() {
	print("Starting up... \n\r");
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 0);
	
	//initializeSound();
	sounds[AMove1] = createSound("a:\\AMove1.wav");
	sounds[AMove2] = createSound("a:\\AMove2.wav");
	sounds[AMove3] = createSound("a:\\AMove3.wav");
	sounds[AMove4] = createSound("a:\\AMove4.wav");
	sounds[Fire] = createSound("a:\\fire.wav");
	sounds[TankExplode] = createSound("a:\\TankXplo.wav");
	sounds[SpaceShipHit] = createSound("a:\\SLow.wav");
	sounds[SpaceShip] = createSound("a:\\Ufo.wav");
	usleep(1000000);
	initializeSound();
	//startLoop(&sounds[]);
	usleep(10000000);
	endLoop();
	while(1){
		int i;
		for(i = 0; i < 8; i++){
			playSound(&sounds[i]);
			usleep(1000000);
			xil_printf("Look no hands\n\r");
		}
		startLoop(&sounds[SpaceShip]);
		usleep(10000000);
		endLoop();
	}
	//future sounds to implement
	// sounds[AMove2] = createSound("a:\\AMove2.wav");
	// sounds[AMove2].priority = 1;
	// sounds[AMove3] = createSound("a:\\AMove3.wav");
	// sounds[AMove3].priority = 1;
	// sounds[AMove4] = createSound("a:\\AMove4.wav");
	// sounds[AMove4].priority = 1;
	//sounds[Fire] = createSound("a:\\fire.wav");
	//sounds[Fire].priority = 7;
	// sounds[TankExplode] = createSound("a:\\TankXplo.wav");
	// sounds[TankExplode].priority = 10;
	// sounds[SpaceShip] = createSound("a:\\SHigh2.wav");
	// sounds[SpaceShip].priority = 8;
	// sounds[SpaceShipHit] = createSound("a:\\SLow.wav");
	// sounds[SpaceShipHit].priority = 9;
	
	
	
//	char hello[] = "Hello World\n\r";
//	int world[11];
//	int i;
//	for(i = 0; i < 13; i++){
//		world[i] = hello[i];
//	}
//	//xil_printf("Hello\n\r");
//	usleep(10000);
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 0);
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 12, XPAR_RS232_UART_1_BASEADDR + 4);
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 4, world);
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 8, 24);
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 1);
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 4, world + 6);
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 8, 28);
//	for(i = 0; i < 11; i++){
//		XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 56);
//		usleep(10000);
//		XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 57);
//		usleep(10000);
//	}
//	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 0);
//	xil_printf("Done!\n\r");
	
}