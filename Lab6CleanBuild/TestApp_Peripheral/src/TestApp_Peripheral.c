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
void playFile(int * wav_sound, int length);
int fetchFile(char * filename, int * wav_sound);

int main (void) {
	while(1){
		initializeSound();
		playSound(shoot_wav_sound, SHOOT_WAV_LEN);
		usleep(1000000);
	}

}
void a(){
	int * wav_sound = (int*)0x00800000;
	int sound[20];
	int sound_lengths[20];
	int ints_read;
	sound[0] = wav_sound;
	ints_read = fetchFile("a:\\AMove1.wav", sound[0]);
	sound_lengths[0] = ints_read;
	sound[1] = sound[0] + ints_read;
	ints_read = fetchFile("a:\\TankFire.wav", sound[1]);
	sound_lengths[1] = ints_read;
	sound[2] = sound[1] + ints_read;
	ints_read = fetchFile("a:\\AMove3.wav", sound[2]);
	sound_lengths[2] = ints_read;
	sound[3] = sound[2] + ints_read;
	ints_read = fetchFile("a:\\AMove4.wav", sound[3]);
	sound_lengths[3] = ints_read;
	int i;
	int k;
	for(i = 44; i < 500; i++){
		int * sound_data = sound[0];
		xil_printf("%.8x ",sound_data[i]);
		k++;
		if(k == 8){
			k = 0;
			print("\n\r");
		}
	}
	print("next\n\r");
	for(i = 44; i < 500; i++){
		int * sound_data = sound[1];
		xil_printf("%.8x ",sound_data[i]);
		k++;
		if(k == 8){
			k = 0;
			print("\n\r");
		}
	}
	while(1){
		for(i = 0; i < 4; i++){
			playFile(sound[i],sound_lengths[i]);
		}
	}

}
int fetchFile(char * filename, int * wav_sound){	
	SYSACE_FILE * infile;
	char * audiobuffer = (char*)0x00600000;
	int numread;
	infile = sysace_fopen(filename, "r");
	int j = 0;
	int i = 0;
	xil_printf("Reading file : %s into address : %x\n\r", filename, wav_sound);
	
	while(1){
		if(infile) {
		
	      print("Success\n\r");
			
			numread = sysace_fread(audiobuffer, 1, WAV_LEN, infile);
			
			if(numread == 0)
				break;
			
			
			for(i = 0; i < numread; i++){
				int value = audiobuffer[i];
				value -= 128;
				value = (value << 24) | ((value << 8)& 0xFFFF);
				wav_sound[j++] = value;
			}
			
		} else {
			print ("Failure\n\r");
			break;
		}
	}
	
	sysace_fclose(filename);
	return j;
}

void playFile(int * wav_sound, int length){
	xil_printf("playing file %x, of length %d\n\r", wav_sound, length);
	int i;
	for(i = 44; i < length; i++){
		//xil_printf("Fifo level: %d\r\n", XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR));
		while(1){
			int fifo_level = XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR);
			if(fifo_level<100){
				//xil_printf("Fifo level: %d\r\n", XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR));
				//xil_printf("i: %d\r\n", i);
				XAC97_mSetInFifoData(XPAR_AUDIO_CODEC_BASEADDR,wav_sound[i]);
				break;
			}
		}
	}
	int sleep_time=10000*2;
	while(1){
		if(XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR)<100){
			for(i=0; i < 200; i++){
				XAC97_mSetInFifoData(XPAR_AUDIO_CODEC_BASEADDR,0);
			}
			sleep_time-=200;
			if(sleep_time < 0){
				break;
			}
		}
	}
}