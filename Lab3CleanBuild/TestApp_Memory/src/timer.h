#ifndef SPACE_INVADER_TIMER
#define SPACE_INVADER_TIMER

typedef struct {
	int current;
	int max;
	void (* callback)();
} Timer;
void incTimer(Timer * t, int amount);
Timer newTimer(int interval, void (* callback)());
#endif
