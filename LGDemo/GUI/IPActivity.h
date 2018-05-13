#ifndef __IPACTIVITY_H
#define __IPACTIVITY_H
#include "Component.h"
typedef struct{

 void (*IPActivityPage)(void);
 void (*IPActivityItemSelect)(void);
	
	
}IPActivity;
extern IPActivity ipActivity;
void IPActivityPage(void);
void ipActivityItemSelect(void);
void ipActivityAction(void);	
#endif 
