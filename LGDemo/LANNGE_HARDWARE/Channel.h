#ifndef __CHANNEL_H
#define __CHANNEL_H

#include "SwitchActivity.h"
typedef struct{
  
	void (*initChannel)(void);
  u8 (*sequenceToDelayOpenClose)(u8*);
  u8 flashChannel;//需要刷新的CHANNEL
	u8 (*getflashChannel)(void);
	u8 sequenceAction;
}Channel;

extern Channel channel;
#define OPEN 1
#define CLOSE 2

#define SetCH1       GPIO_SetBits(GPIOC,GPIO_Pin_0);
#define SetCH2       GPIO_SetBits(GPIOC,GPIO_Pin_1);
#define SetCH3       GPIO_SetBits(GPIOC,GPIO_Pin_2);
#define SetCH4       GPIO_SetBits(GPIOC,GPIO_Pin_3);
#define SetCH5       GPIO_SetBits(GPIOC,GPIO_Pin_4);
#define SetCH6       GPIO_SetBits(GPIOC,GPIO_Pin_5);
#define SetCH7       GPIO_SetBits(GPIOC,GPIO_Pin_6);
#define SetCH8       GPIO_SetBits(GPIOC,GPIO_Pin_7);
                                    
#define ResetCH1    GPIO_ResetBits(GPIOC,GPIO_Pin_0); 
#define ResetCH2    GPIO_ResetBits(GPIOC,GPIO_Pin_1); 
#define ResetCH3    GPIO_ResetBits(GPIOC,GPIO_Pin_2); 
#define ResetCH4    GPIO_ResetBits(GPIOC,GPIO_Pin_3); 
#define ResetCH5    GPIO_ResetBits(GPIOC,GPIO_Pin_4); 
#define ResetCH6    GPIO_ResetBits(GPIOC,GPIO_Pin_5); 
#define ResetCH7    GPIO_ResetBits(GPIOC,GPIO_Pin_6); 
#define ResetCH8    GPIO_ResetBits(GPIOC,GPIO_Pin_7); 
                                   
#define ReadCH1      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0)
#define ReadCH2      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1)
#define ReadCH3      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2)
#define ReadCH4      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_3)
#define ReadCH5      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_4)
#define ReadCH6      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_5)
#define ReadCH7      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_6)
#define ReadCH8      GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_7)

void initChannel(void);
u8 sequenceToDelayOpenClose(u8* actionStatus);
u8 getflashChannel(void);
#endif





