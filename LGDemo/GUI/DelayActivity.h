#ifndef __DELAYACTIVITY_H
#define __DELAYACTIVITY_H

#include "Component.h"
#include "Activity.h"
typedef struct{
	
void (*delayPage)(void);
	
}DelayActivity;
extern DelayActivity delayActivity;
void delayPage(void);
void delayActivityAction(void);
void delatPageSelectItem(void);
extern DelayActivity delayActivity;

#endif

