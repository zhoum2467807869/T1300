#ifndef __COMPONENT_H
#define __COMPONENT_H
#include "Dis_API.h"
#include "key.h"
#include "PageSpinnerActivity.h"

typedef struct{

 u8 sx;
 u8 sy;
 u8 width;
 u8 height;

}RectangleXY;

typedef struct{


  RectangleXY xyStructuee;
	
}Rectangle;

typedef struct{
	
	void (*titleBar)(void);
	RectangleXY (*pageSpinner)(u16,u16,u16,u16,char *,u16,u16,u8 );
  void (*clearScreen)(void); 
	RectangleXY (*virticleadderSubtracter)(u8,u8,u8,u8,u8,u8,char*,u16);
  Rectangle* (*pageSpinnerItem)(u16,u16,u16,u16,char **,u8);
	RectangleXY (*pageButton)(u8,u8,u8,u8,char* p,u16,u16);
	void (*pageCheckBox)(u8,u8 ,u8,u8,u16,char* );
	RectangleXY (*pageswitch)(u8 x,u8 y,u8 ,u8 ,char* ,u8,u16 ,u16);
	void (*ShowpageSpinner)(u8 );
	RectangleXY (*pageCircleButton)(u8 ,u8 ,u8 ,u8 ,char* p,u8 ,u16,u8);
	void (*clearPage)(void);
	void (*clear)(u8 ,u8 ,u8 ,u8 ,u16 );
	RectangleXY (*horizontaladderSubtracter)(u8,u8,u8,u8,u8,u8,u8,char*,u16);
	void (*assignStructure)(u8,u8,u8,u8,RectangleXY*);
  void (*flashData)(Rectangle*,u16,u16,u16);
	void (*flashChar)(Rectangle*,char*,u16,u16);
	void (*emptyRectangle)(RectangleXY*,u8 ,u16);
	RectangleXY (*pageEditText)(u8,u8,u8,u8,u16,u16,u16); 
	u8 (*getMAXofArray)(u8 *,u8 );
}Component;

void titleBar(void);
RectangleXY pageSpinner(u16 x,u16 y,u16 width,u16 hegiht,char *p,u16 background,u16 textCorlor,u8 dir);
void clearScreen(void);
RectangleXY virticleadderSubtracter(u8 x,u8 y,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,u16 Num);
Rectangle* pageSpinnerItem(u16 x,u16 y,u16 width,u16 hegiht,char *p[],u8 itemNum);
RectangleXY pageButton(u8 x,u8 y,u8 width,u8 height,char* p,u16 blackground,u16 textCorlor);
RectangleXY pageswitch(u8 x,u8 y,u8 width,u8 height,char* p,u8 switchStatus,u16 background,u16 textCorlor);
void pageCheckBox(u8 x,u8 y,u8 width,u8 height,u16 corlor,char* p);
RectangleXY pageCircleButton(u8 x,u8 y,u8 width,u8 height,char* p,u8 mode,u16 color,u8 textSize);
void ShowpageSpinner(u8 spinnertype);
void clearPage(void);
void clear(u8 x,u8 y,u8 width,u8 height,u16 corlor);
RectangleXY horizontaladderSubtracter(u8 x,u8 y,u8 textwidth,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,u16 Num);
void assignStructure(u8 x,u8 y,u8 width,u8 height,RectangleXY* rectanglexy);
void flashData(Rectangle *rectangle,u16 Num,u16 rectangleColor,u16 contentColor);
void flashChar(Rectangle* rectangle,char* p,u16 rectangleColor,u16 contentColor);
void emptyRectangle(RectangleXY* rectanglexy,u8 switchStatus,u16 color);
RectangleXY pageEditText(u8 x,u8 y,u8 width,u8 height,u16 num,u16 blackground,u16 textCorlor);
u8 getMAXofArray(u8 *buf,u8 arrayLen);/*获取数组的最大值，arrayLen为数组长度*/

extern Component component;

#endif



