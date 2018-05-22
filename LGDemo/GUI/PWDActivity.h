#ifndef __PWDACTIVITY_H
#define __PWDACTIVITY_H
#include "Component.h"

typedef struct  /*密码数据结构体*/
{
u8 p_one;
u8 p_two;
u8 p_three;	
u8 p_four;	
}pwd_data;

typedef struct{
	
 void (*pwdActivityPage)(void);
 void (*pwdActivityItemSelect)(void);
 void (*savePwdData)(void);
 void (*readPwdData)(void);	
 u8 (*checkPwd)(pwd_data* data,pwd_data* pwddata);
 pwd_data* pwdData;
}PWDActivity;
extern PWDActivity pwdActivity;

void pwdActivityPage(void);
void pwdActivityItemSelect(void);
void pwdActivityAction(void);
void flashPwdItem(u8 anchor,u8 lastanchor);
u8 checkPwd(pwd_data* data,pwd_data* pwddata);
void savePwdData(void);
void readPwdData(void);
#endif

