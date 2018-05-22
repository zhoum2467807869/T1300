#ifndef __SWITCHACTIVITY
#define __SWITCHACTIVITY

#include "Component.h"
#define EnCH1       ChanenStructure.CHAN1
#define EnCH2       ChanenStructure.CHAN2
#define EnCH3       ChanenStructure.CHAN3
#define EnCH4       ChanenStructure.CHAN4
#define EnCH5       ChanenStructure.CHAN5
#define EnCH6       ChanenStructure.CHAN6
#define EnCH7       ChanenStructure.CHAN7
#define EnCH8       ChanenStructure.CHAN8
typedef struct  /*通道使能结构体*/
{
u8 CHAN1;
u8 CHAN2;
u8 CHAN3;
u8 CHAN4;
u8 CHAN5;
u8 CHAN6;
u8 CHAN7;
u8 CHAN8;
}CHANEN;
typedef struct{
	
void  (*switchActivitypage)(void);
CHANEN* ChanenStructure;
void (*saveEnchanData)(void);
void (*readEnchanData)(void);
}SwitchActivity;
extern SwitchActivity switchActivity;

extern CHANEN ChanenStructure;
void  switchActivitypage(void);
void switchActivityAction(void);
void switchActivitySelectItem(void);
void flashSwitchItem(u8 anchor,u8 lastanchor);
void saveEnchanData(void);
void readEnchanData(void);
#endif

