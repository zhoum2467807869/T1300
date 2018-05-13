#ifndef __PWDACTIVITY_H
#define __PWDACTIVITY_H
#include "Component.h"
typedef struct{
	
 void (*pwdActivityPage)(void);
 void (*pwdActivityItemSelect)(void);
	
}PWDActivity;

extern PWDActivity pwdActivity;

void pwdActivityPage(void);
void pwdActivityItemSelect(void);
void pwdActivityAction(void);
#endif

