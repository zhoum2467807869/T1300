#ifndef __HOMEACTIVITY_H
#define __HOMEACTIVITY_H

#include "Dis_API.h"
#include "rtc.h"
#include "Component.h"
#include "Channel.h"
#include "Activity.h"
typedef struct
{
	void (*mainPage)(void);
	void (*mainOpenSplash)(void);
	void (*showVolAndTime)(void);
	void (*homeActivityAction)(void);
}HomeActivity;
void mainPage(void);
void mainOpenSplash(void);
void showVolAndTime(void);
void homeActivitySelectItem(void);
void homeActivityAction(void);
extern HomeActivity homeActivity;
#endif

