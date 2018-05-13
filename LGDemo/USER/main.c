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
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
    homeActivity.mainOpenSplash();
	  activity.activeActivity=activity.HOME;       
    while(1)
        {
                  
             activity.creatActivity(activity.activeActivity);

        }
}



