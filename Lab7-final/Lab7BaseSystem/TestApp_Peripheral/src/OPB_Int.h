#ifndef OPBINTERRUPTS
#define OPBINTERRUPTS
#include "xparameters.h"
#include "xintc.h"
void disableAudioInterrupt();

void enableAudioInterrupt();

void acknowledgeAudioInterrupts();

void clearInterrupts();

void initializeMER();
#endif