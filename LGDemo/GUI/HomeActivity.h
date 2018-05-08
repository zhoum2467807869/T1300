#ifndef __HOMEACTIVITY_H
#define __HOMEACTIVITY_H

#include "Dis_API.h"
#include "rtc.h"
#include "Component.h"
#include "Channel.h"
typedef struct
{
	void (*mainPage)(void);
	void (*mainOpenSplash)(void);
	void (*showVolAndTime)(void);
	
}HomeActivity;
void mainPage(void);
void mainOpenSplash(void);
void showVolAndTime(void);
extern HomeActivity homeActivity;
#endif

