#ifndef __UVOVACTIVITY_H
#define __UVOVACTIVITY_H

#include "Component.h"

typedef struct{
	
 void (*uvovActivityPage)(void);
 void (*uvovActivityItemSelect)(void);
	
}UVOVActivity;

extern UVOVActivity uvovActivity;

void uvovActivityPage(void);
void uvovActivityItemSelect(void);
void uvovActivityAction(void);

#endif

