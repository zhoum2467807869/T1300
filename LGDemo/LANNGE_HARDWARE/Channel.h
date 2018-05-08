#ifndef __CHANNEL_H
#define __CHANNEL_H

typedef struct{
  
	void (*initChannel)(void);


}Channel;

extern Channel channel;

                  
                  
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
#endif





