#ifndef WAVE_HEADER_SA
#define WAVE_HEADER_SA
typedef struct {
  int ID;
  int size;
  short AudioFormat;
  short NumChannels;
  int SampleRate;
  int ByteRate;
  short BlockAlign;
  short BitsPerSample;
} wav_format;

typedef struct {
  int ID;
  int Size;
  char * data;
} wav_data;

typedef struct {
  int ID;
  int size;
  int format;
  wav_format fmt;
  wav_data data;
} wav_riff;


int getSampleRate(char * tempSpace);

#endif
