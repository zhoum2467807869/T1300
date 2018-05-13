#ifndef __OTHERACTIVITY_H
#define __OTHERACTIVITY_H
#include "Activity.h"
#include "Component.h"
typedef struct{

	
void (*otherActivityPage)(void);
void (*otherPageSpinner)(void);
void (*otherActivityAction)(void);
	
}OtherActivity;

extern OtherActivity otherActivity;
void otherActivityPage(void);
void otherPageSpinner(void);
void otherActivityAction(void);
void showotherItem(u8 x,u8 y,u8 width,u8 height,char* itemName[],u8 index,u16 corlor);
#endif 

