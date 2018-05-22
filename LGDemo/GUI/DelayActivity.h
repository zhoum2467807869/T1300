#ifndef __DELAYACTIVITY_H
#define __DELAYACTIVITY_H

#include "Component.h"
#include "Activity.h"


typedef struct  /*开延时数据结构体*/
{  
	u8 chan1;
	u8 chan2;
	u8 chan3;
	u8 chan4;
	u8 chan5;
	u8 chan6;
	u8 chan7;
	u8 chan8;
}_chan_open_data;
typedef struct  /*修改开关延时的中间变量结构体*/
{
	u16 data1;
	u16 data2;
	u16 data3;
	u16 data4;
}_chan_data;
typedef struct  /*关延时数据结构体*/
{
	u8 chan1;
	u8 chan2;
	u8 chan3;
	u8 chan4;
	u8 chan5;
	u8 chan6;
	u8 chan7;
	u8 chan8;
}_chan_close_data;



typedef struct{	
	
u8 subPageNum; 
void (*delayPage)(void);
u8 isShowSpinner;//是否显示子页面选择框
	
void (*saveDelayData)(u8 pageNum);
void (*readDelayData)(void);	
	
_chan_open_data*  chan_open_data;
_chan_close_data*  chan_close_data;
	
}DelayActivity;
extern DelayActivity delayActivity;
void delayPage(void);
void delayActivityAction(void);
void delatPageSelectItem(void);
void flashItem(u8 anchor,u8 lastanchor);
void delaySpinnerItemSelect(void);
void flashDelaySpinnerItem(u8 anchor,u8 lastanchor);
void flashSubPage(u8 pageNum);
void assignVal(u8 pageNum);
void saveDelayData(u8 pageNum);
void readDelayData(void);
extern DelayActivity delayActivity;

#endif

