#include "key.h"
#include "sys.h"
#include "delay.h"
#define ROTATE_A  PBin(10)
#define ROTATE_B PBin(11)

_relay_key_dev relay_key_dev= {XNULL}; //按键结构体

_encoder_dev encoder_dev;//编码器状态结构体

u8 back_flag,front_flag;
u8 LAST_A_LEVEL=1;//保存上一次编码器状态A脚电平值
u8 LAST_KEY_LEVEL=1;//保存上一次编码器按键电平状态
u8 LAST_REKEY_LEVEL=1;
void key_init()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;//编码器，电源开关
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}
u8 encoder()//判断编码器状态
{

    if(!(ENCODER_A==LAST_A_LEVEL))////编码器或者编码器按钮发生电平转变
        {
            delay_us(200);//消抖
            if(!(ENCODER_A==LAST_A_LEVEL))//编码器A引脚发生电平转变
                {
                    if(LAST_A_LEVEL==1)//下降沿     //牺牲一个半个周期判断正反转
                        {
                            if(ENCODER_B==1)front_flag=1;
                            else back_flag=1;
                        }
                    else  //上升沿
                        {
                            if(front_flag==1)//向后标志1
                                {
                                    if(ENCODER_B==0)
                                        {
																					  front_flag=0;
                                            return TURN_R;
                                            
                                        }
                                }
                            else if(back_flag==1)
                                {
                                    if(ENCODER_B)
                                        {
																					  back_flag=0;
                                            return TURN_L;
                                            
                                        }
                                }
                            back_flag=0;
                            front_flag=0;
                        }
                    LAST_A_LEVEL=ENCODER_A;
                }
        }
    return encoder_key();//扫描编码器按键状态
}
u8 encoder_key()//判断编码器按键状态
{   
    u8 static  key_up=1;//按键按松开标志
    if(key_up&&ENCODER_KEY==0)
        {
            delay_ms(100);
            key_up=0;
            if(ENCODER_KEY==0)
                {
                  return EN_KEY_DOWN;         
                }
        }
    else if(ENCODER_KEY==1)key_up=1;
		return EN_KEY_UP;
}
u8 relay_key() //判断时序按键状态
{
    static u8 key_up=1;//按键按松开标志
    if(key_up&&RELAY_KEY==0)
        {
            delay_ms(100);
            key_up=0;
            if(RELAY_KEY==0)
                {
                  return RE_KEY_DOWN;         
                }
        }
    else if(RELAY_KEY==1)key_up=1;
				return RE_KEY_UP;
}


