#include "key.h"
#include "sys.h"
#include "delay.h"
#define ROTATE_A  PBin(10)
#define ROTATE_B PBin(11)

_relay_key_dev relay_key_dev= {XNULL}; //�����ṹ��

_encoder_dev encoder_dev;//������״̬�ṹ��

u8 back_flag,front_flag;
u8 LAST_A_LEVEL=1;//������һ�α�����״̬A�ŵ�ƽֵ
u8 LAST_KEY_LEVEL=1;//������һ�α�����������ƽ״̬
u8 LAST_REKEY_LEVEL=1;
void key_init()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;//����������Դ����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}
u8 encoder()//�жϱ�����״̬
{

    if(!(ENCODER_A==LAST_A_LEVEL))////���������߱�������ť������ƽת��
        {
            delay_us(200);//����
            if(!(ENCODER_A==LAST_A_LEVEL))//������A���ŷ�����ƽת��
                {
                    if(LAST_A_LEVEL==1)//�½���     //����һ����������ж�����ת
                        {
                            if(ENCODER_B==1)front_flag=1;
                            else back_flag=1;
                        }
                    else  //������
                        {
                            if(front_flag==1)//����־1
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
    return encoder_key();//ɨ�����������״̬
}
u8 encoder_key()//�жϱ���������״̬
{   
    u8 static  key_up=1;//�������ɿ���־
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
u8 relay_key() //�ж�ʱ�򰴼�״̬
{
    static u8 key_up=1;//�������ɿ���־
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


