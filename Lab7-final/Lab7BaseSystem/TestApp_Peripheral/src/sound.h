#ifndef SPACE_INVADERS_SOUND
#define SPACE_INVADERS_SOUND

typedef struct{
	int * address;
	int length;
	int sampling;
	int current_sample;
	int priority;
}Sound;

void initializeSound();
void playSilenceMS(int time_in_ms);

int * convertArrayToInt(char * wav_sound, int length);
int getFileFromCF(char * audiobuffer, char * fileName);

void volumeUp();
void volumeDown();


void playSound(Sound * newSound);
void endSound(Sound * newSound);
Sound createSound(char * filename);

extern int * tempSpace;
extern int * nextFreeAddress;
extern Sound * current_sound;

#endif
