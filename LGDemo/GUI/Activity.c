#include "Activity.h"
ActivityStructure activity= {1,2,3,4,5,6,7,8,9,10,0,createActivity,toucharea,scanAddSubstruct,encoderToAddSub,readData,flashTime,executeInWhile};
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
            delay_ms(10);//消抖
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
u8 scanAddSubstruct(u8 x,u8 y,u8 width,u8 height){
   
	 
	    u8 addx=x-20;
	    u8 addy=y;
	    u8 subx=x+width;
      u8 suby=y;
	       tp_dev.scan(0);
    if(tp_dev.sta&TP_PRES_DOWN)
        {
            delay_ms(10);//消抖
            if(tp_dev.sta&TP_PRES_DOWN)
                {
									
                    if((tp_dev.x[0]>addx)&&(tp_dev.x[0]<addx+20)&&(tp_dev.y[0]>addy)&&(tp_dev.y[0]<addy+20))
                        {
													delay_ms(50);
                          return SUB;
													
                        }else if((tp_dev.x[0]>subx)&&(tp_dev.x[0]<subx+20)&&(tp_dev.y[0]>suby)&&(tp_dev.y[0]<suby+20)){
											  	delay_ms(50);
												return ADD;
												}
                }
        }
				return 0;
}

u8 encoderToAddSub(u8* flag,u8*state){

	if(*flag==1){
  if(*state==TURN_L)
		 return ADD;	 
	if(*state==TURN_R)
		 return SUB;	 
	if(*state==EN_KEY_DOWN)
	*flag=0;
	*state=0;
  }
	return 0;

}
void readData(){
	
pwdActivity.readPwdData();
switchActivity.readEnchanData();
ipActivity.readIPData();
uvovActivity.readUVOVData();
delayActivity.readDelayData();

	
}
void flashTime(){
    if(flag_ten_sec>=10){
    Fill_Fast_Rec(175,0,45,30,Blue);
    TFT_ShowNum(175,13,calendar.hour,16,White);
    TFT_ShowNum(198,13,calendar.min,16,White);
    TFT_ShowString(190,13,":",16,White);
			flag_ten_sec=0;
		}
}
void executeInWhile(){
/*放置必要执行函数*/	

 channel.flashChannel=channel.sequenceToDelayOpenClose(&(channel.sequenceAction));  

}




