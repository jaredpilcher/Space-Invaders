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
  xil_printf("SampleRate: %x\n", tempRIFF->fmt.SampleRate);
  xil_printf("NumChannels: %d\n", tempRIFF->fmt.NumChannels);
  unsigned char * upper = (char*)&tempRIFF->fmt.SampleRate;
  xil_printf("%x ", *upper);
  unsigned char * upper_mid = upper + 1;
  xil_printf("%x ", *upper_mid);
  unsigned char * lower_mid = upper + 2;
  xil_printf("%x ", *lower_mid);
  unsigned char * lower = upper + 3;
  xil_printf("%x ", *lower);
  int sample = ((unsigned)*lower) << 24 | ((unsigned)*lower_mid) << 16 | ((unsigned)*upper_mid) << 8 | *upper;
  xil_printf("Rate in Other endian: %x\n", sample);
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
			 return sample ;
  }
  return sample;
}
