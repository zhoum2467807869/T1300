#ifndef __COMPONENT_H
#define __COMPONENT_H
#include "Dis_API.h"

typedef struct{

	void (*titleBar)(void);
	void (*pageSpinner)(u16,u16,u16,u16,char *,u16,u16);
	void (*subPageSpinner)(void);
  void (*clearScreen)(void); 
	void (*adderSubtracter)(u8,u8,u8,u8,u8,u8,char*,char*);
  void (*pageSpinnerItem)(u16,u16,u16,u16,char **,u8);
	void (*pageButton)(u8,u8,u8,u8,char* p,u16,u16);
	void (*pageCheckBox)(u8,u8 ,u8,u8,u16,char* );
	void (*pageswitch)(u8 x,u8 y,u8 ,u8 ,char* ,u16 ,u16 );
	void (*ShowpageSpinner)(void);
	void (*pageCircleButton)(u8 ,u8 ,u8 ,u8 ,char* p,u8 ,u16,u8);
}Component;

void titleBar(void);
void pageSpinner(u16 x,u16 y,u16 width,u16 hegiht,char *p,u16 background,u16 textCorlor);
void subPageSpinner(void);
void clearScreen(void);
void adderSubtracter(u8 x,u8 y,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,char* n);
void pageSpinnerItem(u16 x,u16 y,u16 width,u16 hegiht,char *p[],u8 itemNum);
void pageButton(u8 x,u8 y,u8 width,u8 height,char* p,u16 blackground,u16 textCorlor);
void pageswitch(u8 x,u8 y,u8 width,u8 height,char* p,u16 background,u16 textCorlor);
void pageCheckBox(u8 x,u8 y,u8 width,u8 height,u16 corlor,char* p);
void pageCircleButton(u8 x,u8 y,u8 width,u8 height,char* p,u8 mode,u16 color,u8 textSize);
void ShowpageSpinner(void);

extern Component component;

#endif



