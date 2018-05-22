#ifndef __TIMEACTIVITY_H
#define __TIMEACTIVITY_H
#include "Component.h"
#include "Activity.h"
typedef struct{

	void (*timeActivityPage)(void);
  void (*timeActivityItemSelect)(void);

	
	
}TimeActivity;
extern TimeActivity timeActivity;

void timeActivityPage(void);
void timeActivityAction(void);
void timeActivityItemSelect(void);
void flashTimeItem(u8 anchor,u8 lastanchor);
#endif
