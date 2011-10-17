#include "sound.h"
#include "xparameters.h"
#include "xac97_l.h"
#include "xsysace.h"
#include "sysace_header.h"
#include "sysace_stdio.h"

#define BASE_ADDRESS 0x00600000

void initializeSound(){
   XAC97_mSetControl(XPAR_AUDIO_CODEC_BASEADDR, AC97_ENABLE_RESET_AC97);
   usleep(100);
   XAC97_mSetControl(XPAR_AUDIO_CODEC_BASEADDR, AC97_DISABLE_RESET_AC97);
   usleep(100);
   XAC97_SoftReset(XPAR_AUDIO_CODEC_BASEADDR);
   XAC97_AwaitCodecReady(XPAR_AUDIO_CODEC_BASEADDR);

   XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_MasterVol,0x0909);
   XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCMOutVol,0x0909);
   XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_AuxOutVol,0x0909);
	
	XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_ExtendedAudioStat,AC97_EXTENDED_AUDIO_CONTROL_VRA);
	XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCM_DAC_Rate,AC97_PCM_RATE_44100_HZ);

}

Sound createSound(char * filename){
	Sound newSound;
	newSound.length = getFileFromCF(tempSpace, filename);
	newSound.address = convertArrayToInt(tempSpace, newSound.length);
	nextFreeAddress += newSound.length;
	newSound.sampling = AC97_PCM_RATE_44100_HZ;
	newSound.current_sample = 0;
	return newSound;
}

void playSilenceMS(int time_in_ms){
	int i;
	for(i = 0; i < (time_in_ms * 11025)/1000; i++){
		while(1){
			int fifo_level = XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR);
			if(fifo_level < 100){
				XAC97_mSetInFifoData(XPAR_AUDIO_CODEC_BASEADDR,0);
				break;
			}
		}
	}
}

int getFileFromCF(char * wav_file_char, char * filename){
	SYSACE_FILE * infile;
	int numread;
	char * audiobuffer = 0x00c00000;
	infile = sysace_fopen(filename, "r");
	int j = 0;
	int i = 0;
	
	while(1){
		if(infile) {
			
			numread = sysace_fread(audiobuffer, 1, 1000, infile);
			
			if(numread == 0)
				break;
			
			for(i = 0; i < numread; i++){
				wav_file_char[j++] = audiobuffer[i];
			}
			
		} else {
			print ("Failure\n\r");
			break;
		}
	}
	
	sysace_fclose(infile);
	return j;

}

int * convertArrayToInt(char * wav_sound, int length){
	int i;
	int * sound = nextFreeAddress;
	for(i = 276; i < length; i++){
		int value = wav_sound[i];
		value -= 128;
		value = (value << 24) | ((value << 8)& 0xFFFF);
		sound[i] = value;
	}
	return sound;
}

void playSound(Sound newSound){
	int i;

	for(i = newSound.current_sample; i < newSound.length; i++){
		while(1){
			int fifo_level = XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR);
			if(fifo_level < 100){
				XAC97_mSetInFifoData(XPAR_AUDIO_CODEC_BASEADDR,newSound.address[i]);
				break;
			}
		}
	}
}