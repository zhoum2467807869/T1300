#ifndef __TIMERACTIVITY_H
#define __TIMERACTIVITY_H
#include "component.h"

typedef struct{
void (*timerActivityPage)(void);
	
	
}TimerActivity;

extern TimerActivity timerActivity;
void timerActivityPage(void);
void timerActivityAction(void);
void timerActivitySelectItem(void);
#endif

