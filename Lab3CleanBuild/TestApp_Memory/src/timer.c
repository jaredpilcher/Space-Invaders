#include "timer.h"

Timer newTimer(int interval, void (* callback)()){
	Timer t;
	t.current = 0;
	t.max = interval;
	t.callback = callback;
	return t;
}

void incTimer(Timer * t, int amount){
	t->current += amount;
	if (t->current > t->max){
		t->current -= t->max;
		t->callback();
	}
}
