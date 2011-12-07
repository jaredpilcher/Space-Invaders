#include "sound.h"
#include "xparameters.h"
#include "xac97_l.h"
#include "xsysace.h"
#include "sysace_header.h"
#include "sysace_stdio.h"

#define BASE_ADDRESS 0x00600000
int nextChannel = 0;

void initializeSound(){

	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 12, XPAR_AUDIO_CODEC_BASEADDR);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, GLOBAL_ENABLE);
	
   XAC97_mSetControl(XPAR_AUDIO_CODEC_BASEADDR, AC97_ENABLE_RESET_AC97);
   usleep(100);
   XAC97_mSetControl(XPAR_AUDIO_CODEC_BASEADDR, AC97_DISABLE_RESET_AC97);
   usleep(100);
   XAC97_SoftReset(XPAR_AUDIO_CODEC_BASEADDR);
   XAC97_mSetControl(XPAR_AUDIO_CODEC_BASEADDR, AC97_ENABLE_IN_FIFO_INTERRUPT);
   XAC97_AwaitCodecReady(XPAR_AUDIO_CODEC_BASEADDR);

   XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_MasterVol,0x0909);
   XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCMOutVol,0x0909);
   XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_AuxOutVol,0x0909);
	
	XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_ExtendedAudioStat,AC97_EXTENDED_AUDIO_CONTROL_VRA);
	XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCM_DAC_Rate,AC97_PCM_RATE_44100_HZ);

}

void volumeUp(){
	int master = XAC97_ReadReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_MasterVol);
	if(master < 0x1f1f){
		XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_MasterVol,master + 0x0101);
	}
	int pcm = XAC97_ReadReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCMOutVol);
	if(pcm < 0x1f1f){
		XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCMOutVol,pcm + 0x0101);
	}
	int aux = XAC97_ReadReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_AuxOutVol);
	if(aux < 0x1f1f){
		XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_AuxOutVol,aux + 0x0101);
	}
}

void volumeDown(){
	int master = XAC97_ReadReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_MasterVol);
	if(master > 0x0000){
		XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_MasterVol,master - 0x0101);
	}
	int pcm = XAC97_ReadReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCMOutVol);
	if(pcm > 0x0000){
		XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCMOutVol,pcm - 0x0101);
	}
	int aux = XAC97_ReadReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_AuxOutVol);
	if(aux > 0x0000){
		XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_AuxOutVol,aux - 0x0101);
	}
}

Sound createSound(char * filename){
	Sound newSound;
	newSound.length = getFileFromCF((char *)tempSpace, filename);
	newSound.address = convertArrayToInt((char *)tempSpace, newSound.length);
	newSound.channel = nextChannel;
	nextFreeAddress += newSound.length;
	nextChannel++;
	newSound.sampling = getSampleRate(tempSpace);
	newSound.current_sample = 0;
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, newSound.channel);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 4, newSound.address + 44*4);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR + 8, (newSound.length-200)*4);
	return newSound;
}

void fillFIFOWithSilence(){
	int fifo_level = XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR);
	int i;
	for(i=fifo_level; i < 1000; i++){
		XAC97_mSetInFifoData(XPAR_AUDIO_CODEC_BASEADDR,0);
		break;
	}
}

int fillFIFOWithSound(Sound * newSound){
	int fifo_level = XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR);
	int i;
	int limit = newSound->current_sample + (1000- fifo_level);
	if(limit <= 0)
		return 1;
	//xil_printf("FIFO Level: %d, limit: %d, current: %d",fifo_level,limit,newSound->current_sample);
	for(i=newSound->current_sample; (i < limit )&&( i < newSound->length); i++){
		XAC97_mSetInFifoData(XPAR_AUDIO_CODEC_BASEADDR, newSound->address[i]);
	} 
	if(i == newSound->length){
		newSound->current_sample = 0;
	}else{
		newSound->current_sample = i;
	}
	return newSound->current_sample;
}

void playSilenceMS(int time_in_ms){
	int i;
	for(i = 0; i < (time_in_ms * 11025)/1000; i++){
		while(1){
		
			int fifo_level = XAC97_getInFIFOLevel(XPAR_AUDIO_CODEC_BASEADDR);
			if(fifo_level < 300){
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
	print("Opening file...");
	infile = sysace_fopen(filename, "r");
	print("Success!\n\r");
	int j = 0;
	int i = 0;
	
	while(1){
		if(infile) {
//			print("Reading....");
//			xil_printf("audiobuffer: %x...", audiobuffer);
//			xil_printf("infile: %x...", infile);
			numread = sysace_fread(audiobuffer, 1, 100, infile);

			if(numread == 0)
				break;
			
			for(i = 0; i < numread; i++){
				wav_file_char[j++] = audiobuffer[i];
			}
			
		} else {
			print ("COMPACT FLASH Failure\n\r");
			break;
		}
	}
	print("Closing file...");
	sysace_fclose(infile);
	print("Success!\n\r");
	
	return j;

}

int * convertArrayToInt(char * wav_sound, int length){
	int i;
	int * sound = nextFreeAddress;
	for(i = 0; i < length; i++){
		int value = wav_sound[i];
		value -= 128;
		value = (value << 24) | ((value << 8)& 0xFFFF);
		sound[i] = value;
	}
	return sound;
}

void playSound(Sound * newSound){
	XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCM_DAC_Rate,newSound->sampling);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, PLAY_NO_LOOPING + newSound->channel);
}

void startLoop(Sound * newSound){
	XAC97_WriteReg(XPAR_AUDIO_CODEC_BASEADDR,AC97_PCM_DAC_Rate,newSound->sampling);
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, PLAY_LOOPING + newSound->channel);
}

void endLoop(){
	XIo_Out32(XPAR_AUDIO_DMA_0_BASEADDR, GLOBAL_ENABLE + ENABLE + PLAY);
}

void endSound(Sound * newSound){
	newSound->current_sample=0;
	current_sound = 0;
}