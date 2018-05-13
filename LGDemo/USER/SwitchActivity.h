#ifndef __SWITCHACTIVITY
#define __SWITCHACTIVITY

#include "Component.h"

typedef struct{
	
void  (*switchActivitypage)(void);
	

}SwitchActivity;

extern SwitchActivity switchActivity;
void  switchActivitypage(void);
void switchActivityAction(void);
void switchActivitySelectItem(void);
#endif

