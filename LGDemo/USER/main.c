#include "main.h"


void delayOpenClose(u8 (*relay_key)(void));
int main()
{
    delay_init();
    TFT_init();
    component.clearScreen();
    tp_dev.init();
    RTC_Init();
    key_init();
    channel.initChannel();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	  auzActivity.auzActivityUserPage();//�������ʹ�ô���;
	  activity.readData();//�豸��ʼ������
    //homeActivity.mainOpenSplash();
	  activity.activeActivity=activity.HOME;       
    while(1)
        {
                  
             activity.creatActivity(activity.activeActivity);

        }
}



