#ifndef __ACTIVITY_H
#define __ACTIVITY_H
#include "sys.h"
#include "HomeActivity.h"
#include "DelayActivity.h" 
#include "SwitchActivity.h"
#include "TimerActivity.h"
#include "OtherActivity.h"
#include "TimeActivity.h"
#include "PWDActivity.h"
#include "IPActivity.h"
#include "AUZActivity.h"
#include "UVOVActivity.h"
#include "PageSpinnerActivity.h"
#include "key.h"
#include "touch.h"

#define ADD 1
#define SUB 2
#define OFF 0
#define ON  1

typedef struct {
	
  u8 HOME;
	u8 DELAY;
	u8 SWITCH;
	u8 TIMER;
	u8 TIME;
	u8 PWD;
  u8 IP;
  u8 UVOV;
  u8 AUZ;	
	u8 SPINNER;
	u8 activeActivity;
	void (*creatActivity)(u8);
	u8 (*toucharea)(u8,u8,u8,u8,u8);
  u8 (*scanAddSubstruct)(u8,u8,u8,u8);
	u8 (*encoderToAddSub)(u8* ,u8*);
	void (*readData)(void);
	void (*flashTime)(void);
	void (*executeInWhile)(void);
}ActivityStructure;
extern ActivityStructure activity;
void createActivity(u8 activityName);
u8 toucharea(u8 x,u8 y,u8 width,u8 height,u8 index);
u8 scanAddSubstruct(u8 x,u8 y,u8 width,u8 height);
u8 encoderToAddSub(u8* flag,u8* state);

void executeInWhile(void);
void readData(void);
void flashTime(void);

#endif

