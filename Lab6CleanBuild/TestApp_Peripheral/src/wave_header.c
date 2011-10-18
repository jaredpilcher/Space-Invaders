#include "wave_header.h"
#include "sound.h"
#include "xparameters.h"
#include "xac97_l.h"
#include "xsysace.h"
#include "sysace_header.h"
#include "sysace_stdio.h"

int getSampleRate(char * tempSpace){
  wav_riff * tempRIFF = (wav_riff *) tempSpace;
  int i;
  xil_printf("RIFF address: %d, sample address: %d\n",&tempRIFF,&tempRIFF->fmt.SampleRate);
  xil_printf("SampleRate: %d\n", tempRIFF->fmt.SampleRate);
  xil_printf("NumChannels: %d\n", tempRIFF->fmt.NumChannels);
  unsigned char * upper = (char*)tempRIFF->fmt.SampleRate;
  unsigned char * upper_mid = upper + 1;
  unsigned char * lower_mid = upper + 2;
  unsigned char * lower = upper + 3;
  int sample = *upper << 24 | *upper_mid << 16 | *lower_mid << 8 | *lower;
  xil_printf("Rate in Other endian: %d\n", sample);
  switch(sample){
		case 8000:
			 return AC97_PCM_RATE_8000_HZ ;
		case 11025:
			 return AC97_PCM_RATE_11025_HZ ;
		case 16000:
			 return AC97_PCM_RATE_16000_HZ ;
		case 22050:
			 return AC97_PCM_RATE_22050_HZ ;
		case 44100:
			 return AC97_PCM_RATE_44100_HZ ;
		case 48000:
			 return AC97_PCM_RATE_48000_HZ ;
		default:
			 return AC97_PCM_RATE_48000_HZ ;
  }
  return sample;
}
