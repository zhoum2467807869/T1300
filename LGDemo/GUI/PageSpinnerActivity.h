#ifndef __PAGESPINNERACTIVITY_H
#define __PAGESPINNERACTIVITY_H
#include "Component.h"
#include "Activity.h"
#include "touch.h"
#include "key.h"

typedef struct{

 u8 sx;
 u8 sy;
 u8 width;
 u8 height;

}SpinnerXY;


typedef struct{

	void (*pageSpinnerActivity)(void);
	void (*pageSpinnerActivityAction)(void);
  void (*showItem)(u8 x,u8 y,u8 width,u8 height,char* itemName[],u8 index,u16 corlor);
}PageSpinnerActivity;

extern PageSpinnerActivity SpinnerActivity;
void pageSpinnerActivity(void);
void pageSpinnerActivityAction(void);
void spinnerAction(void);
void showItem(u8 x,u8 y,u8 width,u8 height,char* itemName[],u8 index,u16 corlor);
void showotherItem(u8 x,u8 y,u8 width,u8 height,char* itemName[],u8 index,u16 corlor);
#endif
