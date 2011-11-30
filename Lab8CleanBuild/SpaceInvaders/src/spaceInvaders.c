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
//#include "sound.h"


int * tempSpace = 0x00800000;
int * nextFreeAddress;
//Sound * current_sound;
enum sound_enum { AMove1, AMove2, AMove3, AMove4, Fire, TankExplode, SpaceShip, SpaceShipHit, Stairway };
//Sound sounds[20];


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

int main() {
	// sounds[AMove1] = createSound("a:\\AMove1.wav");
	// sounds[AMove1].priority = 1;
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

	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 8);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 4 + 8);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 4, 0xBEEFADED);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 3 + 8);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 4, 0xADEFACED);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, 4 + 8);
	int a = XIo_In32(XPAR_AUDIO_DMA_0_BASEADDR + 4);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR,3 + 8);
	int b = XIo_In32(XPAR_AUDIO_DMA_0_BASEADDR + 4);
	usleep(100000);
	xil_printf("%x should == %x\n\r", 0xBEEFADED, a);
	xil_printf("%x should == %x\n\r", 0xADEFACED, b);






}