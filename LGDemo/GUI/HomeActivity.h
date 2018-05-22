#ifndef __HOMEACTIVITY_H
#define __HOMEACTIVITY_H

#include "Dis_API.h"
#include "rtc.h"
#include "Component.h"
#include "Channel.h"
#include "Activity.h"
typedef struct
{
	void (*mainPage)(void);
	void (*mainOpenSplash)(void);
	void (*showVolAndTime)(void);
	void (*homeActivityAction)(void);
	u8 machine;//�Ƿ�����
	u8 volt;
  u8 isShowPWD;//��ʾPWD	
	void (*flashChannel)(u8 channelIndex);
	void  (*flashChannelSate)(u8 sec);
}HomeActivity;
void mainPage(void);
void mainOpenSplash(void);
void showVolAndTime(void);
void homeActivitySelectItem(void);
void homeActivityAction(void);
void flashPasswordItem(u8 anchor,u8 lastanchor);
void flashChannel(u8 channelIndex);
void  flashChannelSate(u8 sec);//��������ˢ������
extern HomeActivity homeActivity;
#endif

