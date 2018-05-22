#ifndef __UVOVACTIVITY_H
#define __UVOVACTIVITY_H

#include "Component.h"
#include "Channel.h"
#define OVER  1
#define UNDER 2

typedef struct  /*过压欠压保护数据结构体*/
{
 u8 rdv;
 u8 uv;
 u8 uv_state;
 u16 ov;
 u8 ov_state;		
}_uv_ov_data;
extern _uv_ov_data uv_ov_data;
typedef struct{
	
 void (*uvovActivityPage)(void);
 void (*uvovActivityItemSelect)(void);
 void (*saveUVOVData)(void);
 void (*readUVOVData)(void);
 u8 (*uvovProtection)(u32* Val);
 u8 alarmEvent;
}UVOVActivity;

extern UVOVActivity uvovActivity;

void uvovActivityPage(void);
void uvovActivityItemSelect(void);
void uvovActivityAction(void);
void flashUVOVItem(u8 anchor,u8 lastanchor);
void saveUVOVData(void);
void readUVOVData(void);
u8 uvovProtection(u32* adcVal);
#endif

