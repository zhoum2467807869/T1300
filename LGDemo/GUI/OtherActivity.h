#ifndef __OTHERACTIVITY_H
#define __OTHERACTIVITY_H

#include "Component.h"
typedef struct{

	

void (*otherActivityPage)(void);
	
}OtherActivity;

extern OtherActivity otherActivity;
void otherActivityPage(void);
#endif 