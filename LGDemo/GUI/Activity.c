#include "Activity.h"

ActivityStructure activity= {1,2,3,4,5,6,7,8,9,10,0,createActivity,toucharea};
void createActivity(u8 activityName)
{

    if(activity.HOME==activityName)
        {
            component.clearScreen();
            homeActivity.mainPage();
					  homeActivity.homeActivityAction();
					  
        }
    else if(activity.DELAY==activityName)
        {
            component.clearScreen();
            delayActivity.delayPage();
        }
    else if(activity.SWITCH==activityName)
        {
            component.clearScreen();
            switchActivity.switchActivitypage();
        }
    else if(activity.TIME==activityName)
        {
            component.clearScreen();
            timeActivity.timeActivityPage();
        }
    else if(activity.TIMER==activityName)
        {
            component.clearScreen();
            timerActivity.timerActivityPage();
        }
    else if(activity.PWD==activityName)
        {
            component.clearScreen();
            pwdActivity.pwdActivityPage();
        }
    else if(activity.IP==activityName)
        {
            component.clearScreen();
            ipActivity.IPActivityPage();
        }
    else if(activity.AUZ==activityName)
        {
            component.clearScreen();
            auzActivity.auzActivityPage();
        }
    else if(activity.UVOV==activityName)
        {
            component.clearScreen();
            uvovActivity.uvovActivityPage();
        }
		else if(activity.SPINNER==activityName)
        {
            SpinnerActivity.pageSpinnerActivity();
            
        }
}
u8 toucharea(u8 x,u8 y,u8 width,u8 height,u8 index)
{
    tp_dev.scan(0);
    if(tp_dev.sta&TP_PRES_DOWN)
        {
            delay_ms(10);//Ïû¶¶
            if(tp_dev.sta&TP_PRES_DOWN)
                {
                    if((tp_dev.x[0]>x)&&(tp_dev.x[0]<x+width)&&(tp_dev.y[0]>y)&&(tp_dev.y[0]<y+height))
                        {
                          return index;
                        }else{
												return 0;
												}

                }

        }
				return 0;
}


u8 selectActivityItem(u8 (*item[])(int))
{
    encoder();
    item[1](2);
    return 1;
}




