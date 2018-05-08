#ifndef __DELAYACTIVITY_H
#define __DELAYACTIVITY_H

#include "Component.h"

typedef struct{
	
void (*delayPage)(void);
	
}DelayActivity;
void delayPage(void);
extern DelayActivity delayActivity;

#endif

