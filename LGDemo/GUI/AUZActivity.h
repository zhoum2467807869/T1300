#ifndef __AUZACTIVITY_H
#define __AUZACTIVITY_H

#include "Component.h"

typedef struct{
	
 void (*auzActivityPage)(void);
 void (*auzActivityItemSelect)(void);
	
}AUZActivity;

extern AUZActivity auzActivity;

void auzActivityPage(void);
void auzActivityItemSelect(void);
void auzActivityAction(void);
#endif

