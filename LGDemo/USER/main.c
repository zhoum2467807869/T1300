#include "main.h"
extern u8 flag_ten_sec;
u8 static lastindex=0;
u8 isHome=0;
u8 flag_=1;
char* itemName[] = {"HOME","DELAY","SWITCH","TIMER","OTHER"};

void showItem(u8 x,u8 y,u8 width,u8 height,char* itemName[],u8 index,u16 corlor)
{
    Fill_Fast_Rec(x,y+(height+2)*index,width,height,corlor);
    Write_Word_Center(x,y+(height+2)*index,x+width,y+height+(height+2)*index,16,itemName[index],White);
}

void delayOpenClose(u8 (*relay_key)(void));
int main()
{
    u8 i=0;
    delay_init();
    TFT_init();
    RTC_Init();
    key_init();
    channel.initChannel();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
    homeActivity.mainOpenSplash();
    homeActivity.mainPage();
    isHome=1;
    while(1)
        {
            i=encoder();
            if(i==TURN_L)
                {
                    delay_ms(50);
                    if(lastindex==0)
                        {
                            if(flag_==0)
                                {
                                    component.ShowpageSpinner();
                                }
                            else
                                {
                                    component.pageSpinner(10,0,70,30,"HOME",Blue,Blue_100);
                                }
                            lastindex=1;
                        }
                    else if(lastindex==1)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,0,Blue_100);
                                }
                            else
                                {
                                    component.pageSpinner(10,0,70,30,"HOME",Blue,White);

                                    component.pageCircleButton(5,90,40,40,"1",1,Blue_100,24);


                                }
                            lastindex=2;
                        }
                    else if(lastindex==2)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,0,Blue_200);
                                    showItem(0,32,80,20,itemName,1,Blue_100);
                                }
                            else
                                {
                                    if(ReadCH1)
                                        component.pageCircleButton(5,90,40,40,"1",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(5,90,40,40,"1",0,Blue_200,24);

                                    component.pageCircleButton(61,90,40,40,"2",1,Blue_100,24);

                                }
                            lastindex=3;
                        }
                    else if(lastindex==3)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,1,Blue_200);
                                    showItem(0,32,80,20,itemName,2,Blue_100);
                                }
                            else
                                {
                                    if(ReadCH2)
                                        component.pageCircleButton(61,90,40,40,"2",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(61,90,40,40,"2",0,Blue_200,24);

                                    component.pageCircleButton(117,90,40,40,"3",1,Blue_100,24);

                                }
                            lastindex=4;
                        }
                    else if(lastindex==4)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,2,Blue_200);
                                    showItem(0,32,80,20,itemName,3,Blue_100);
                                }
                            else
                                {
                                    if(ReadCH3)
                                        component.pageCircleButton(117,90,40,40,"3",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(117,90,40,40,"3",0,Blue_200,24);

                                    component.pageCircleButton(173,90,40,40,"4",1,Blue_100,24);
                                }

                            lastindex=5;
                        }
                    else if(lastindex==5)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,3,Blue_200);
                                    showItem(0,32,80,20,itemName,4,Blue_100);
                                }
                            else
                                {
                                    if(ReadCH4)
                                        component.pageCircleButton(173,90,40,40,"4",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(173,90,40,40,"4",0,Blue_200,24);
                                    component.pageCircleButton(5,135,40,40,"5",1,Blue_100,24);
                                }
                            lastindex=6;
                        }
                    else if(lastindex==6)
                        {
                            if(flag_==1)
                                {
                                    if(ReadCH5)
                                        component.pageCircleButton(5,135,40,40,"5",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(5,135,40,40,"5",0,Blue_200,24);
                                    component.pageCircleButton(61,135,40,40,"6",1,Blue_100,24);
                                    lastindex=7;

                                }

                        }
                    else if(lastindex==7)
                        {
                            if(flag_==1)
                                {
                                    if(ReadCH6)
                                        component.pageCircleButton(61,135,40,40,"6",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(61,135,40,40,"6",0,Blue_200,24);
                                    component.pageCircleButton(117,135,40,40,"7",1,Blue_100,24);
                                    lastindex=8;

                                }
                        }
                    else if(lastindex==8)
                        {

                            if(flag_==1)
                                {
                                    if(ReadCH7)
                                        component.pageCircleButton(117,135,40,40,"7",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(117,135,40,40,"7",0,Blue_200,24);
                                    component.pageCircleButton(173,135,40,40,"8",1,Blue_100,24);
                                    lastindex=9;

                                }
                        }

                }
            else	if(i==TURN_R)
                {
                    delay_ms(50);
                    if(lastindex==0)
                        {
                            if(flag_==0)
                                {
                                    component.ShowpageSpinner();
                                }
                            else
                                {
                                    component.pageSpinner(10,0,70,30,"HOME",Blue,Blue_100);
                                }
                            lastindex=1;
                        }
                    else if(lastindex==2)
                        {

                            if(flag_==1)
                                {
                                    component.pageSpinner(10,0,70,30,"HOME",Blue,Blue_100);
                                    if(ReadCH1)
                                        component.pageCircleButton(5,90,40,40,"1",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(5,90,40,40,"1",0,Blue_200,24);
                                    lastindex=1;
                                }

                        }
                    else if(lastindex==3)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,1,Blue_200);
                                    showItem(0,32,80,20,itemName,0,Blue_100);
                                }
                            else
                                {
                                    if(ReadCH2)
                                        component.pageCircleButton(61,90,40,40,"2",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(61,90,40,40,"2",0,Blue_200,24);
                                    component.pageCircleButton(5,90,40,40,"1",1,Blue_100,24);

                                }
                            lastindex=2;

                        }
                    else if(lastindex==4)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,2,Blue_200);
                                    showItem(0,32,80,20,itemName,1,Blue_100);
                                }
                            else
                                {
                                    component.pageCircleButton(61,90,40,40,"2",1,Blue_100,24);
                                    if(ReadCH3)
                                        component.pageCircleButton(117,90,40,40,"3",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(117,90,40,40,"3",0,Blue_200,24);
                                }
                            lastindex=3;
                        }
                    else if(lastindex==5)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,3,Blue_200);
                                    showItem(0,32,80,20,itemName,2,Blue_100);
                                }
                            else
                                {
                                    component.pageCircleButton(117,90,40,40,"3",1,Blue_100,24);
                                    if(ReadCH4)
                                        component.pageCircleButton(173,90,40,40,"4",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(173,90,40,40,"4",0,Blue_200,24);

                                }
                            lastindex=4;
                        }
                    else if(lastindex==6)
                        {
                            if(flag_==0)
                                {
                                    showItem(0,32,80,20,itemName,4,Blue_200);
                                    showItem(0,32,80,20,itemName,3,Blue_100);
                                }
                            else
                                {
                                    component.pageCircleButton(173,90,40,40,"4",1,Blue_100,24);
                                    if(ReadCH5)
                                        component.pageCircleButton(5,135,40,40,"5",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(5,135,40,40,"5",0,Blue_200,24);
                                }
                            lastindex=5;
                        }
                    else if(lastindex==7)
                        {
                            component.pageCircleButton(5,135,40,40,"5",1,Blue_100,24);
                            if(ReadCH6)
                                component.pageCircleButton(61,135,40,40,"6",1,Blue_200,24);
                            else
                                component.pageCircleButton(61,135,40,40,"6",0,Blue_200,24);


                            lastindex=6;

                        }
                    else if(lastindex==8)
                        {

                            component.pageCircleButton(61,135,40,40,"6",1,Blue_100,24);
                            if(ReadCH7)
                                component.pageCircleButton(117,135,40,40,"7",1,Blue_200,24);
                            else
                                component.pageCircleButton(117,135,40,40,"7",0,Blue_200,24);
                            lastindex=7;
                        }
                    else if(lastindex==9)
                        {
                            component.pageCircleButton(117,135,40,40,"7",1,Blue_100,24);
                            if(ReadCH8)
                                component.pageCircleButton(173,135,40,40,"8",1,Blue_200,24);
                            else
                                component.pageCircleButton(173,135,40,40,"8",0,Blue_200,24);
                            lastindex=8;
                        }
                }
            else if(i==EN_KEY_DOWN)
                {

                    if(lastindex==1)
                        {

                            if(flag_==1)
                                {
                                    flag_=0;
                                    component.ShowpageSpinner();
                                }
                            lastindex=1;
                        }
                    else if(lastindex==2)
                        {
                            if(flag_==0)
                                {
                                    component.clearScreen();
                                    homeActivity.mainPage();
                                    flag_=1;
                                    isHome=1;
                                    lastindex=0;
                                }
                            else
                                {
                                    if(ReadCH1)
                                        {
                                            ResetCH1
                                        }
                                    else
                                        {
                                            SetCH1
                                        }
                                    if(ReadCH1)
                                        component.pageCircleButton(5,90,40,40,"1",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(5,90,40,40,"1",0,Blue_200,24);
                                }
                        }
                    else if(lastindex==3)
                        {
                            if(flag_==0)
                                {
                                    component.clearScreen();
                                    delayActivity.delayPage();
                                    isHome=0;
                                    lastindex=0;
                                }
                            else
                                {
                                    if(ReadCH2)
                                        {
                                            ResetCH2
                                        }
                                    else
                                        {
                                            SetCH2
                                        }
                                    if(ReadCH2)
                                        component.pageCircleButton(61,90,40,40,"2",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(61,90,40,40,"2",0,Blue_200,24);
                                }
                        }
                    else if(lastindex==4)
                        {
                            if(flag_==0)
                                {
                                    component.clearScreen();
                                    switchActivity.switchActivitypage();
                                    isHome=0;
                                    lastindex=0;
                                }
                            else
                                {
                                    if(ReadCH3)
                                        {
                                            ResetCH3
                                        }
                                    else
                                        {
                                            SetCH3
                                        }
                                    if(ReadCH3)
                                        component.pageCircleButton(117,90,40,40,"3",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(117,90,40,40,"3",0,Blue_200,24);

                                }
                        }
                    else if(lastindex==5)
                        {
                            if(flag_==0)
                                {
                                    component.clearScreen();
                                    timerActivity.timerActivityPage();
                                    isHome=0;
                                    lastindex=0;
                                }
                            else
                                {
                                    if(ReadCH4)
                                        {
                                            ResetCH4
                                        }
                                    else
                                        {
                                            SetCH4
                                        }
                                    if(ReadCH4)
                                        component.pageCircleButton(173,90,40,40,"4",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(173,90,40,40,"4",0,Blue_200,24);
                                }
                        }
                    else if(lastindex==6)
                        {
                            if(flag_==0)
                                {
                                    component.clearScreen();
                                    otherActivity.otherActivityPage();
                                    isHome=0;
                                    lastindex=0;
                                }
                            else
                                {
                                    if(ReadCH5)
                                        {
                                            ResetCH5
                                        }
                                    else
                                        {
                                            SetCH5
                                        }
                                    if(ReadCH5)
                                        component.pageCircleButton(5,135,40,40,"5",1,Blue_200,24);
                                    else
                                        component.pageCircleButton(5,135,40,40,"5",0,Blue_200,24);
                                }
                        }
                    else if(lastindex==7)
                        {

                            if(ReadCH6)
                                {
                                    ResetCH6
                                }
                            else
                                {
                                    SetCH6
                                }
                            if(ReadCH6)
                                component.pageCircleButton(61,135,40,40,"6",1,Blue_200,24);
                            else
                                component.pageCircleButton(61,135,40,40,"6",0,Blue_200,24);
                        }
                    else if(lastindex==8)
                        {

                            if(ReadCH7)
                                {
                                    ResetCH7
                                }
                            else
                                {
                                    SetCH7
                                }
                            if(ReadCH7)
                                component.pageCircleButton(117,135,40,40,"7",1,Blue_200,24);
                            else
                                component.pageCircleButton(117,135,40,40,"7",0,Blue_200,24);
                        }
                    else if(lastindex==9)
                        {

                            if(ReadCH8)
                                {
                                    ResetCH8
                                }
                            else
                                {
                                    SetCH8
                                }
                            if(ReadCH8)
                                component.pageCircleButton(173,135,40,40,"8",1,Blue_200,24);
                            else
                                component.pageCircleButton(173,135,40,40,"8",0,Blue_200,24);

                        }
                    delay_ms(400);
                }
            i=0;
            if(isHome==1&&flag_ten_sec>=10)
                {
                    flag_ten_sec=0;
                    showVolAndTime();
                }
        delayOpenClose(relay_key);



        }
}
void delayOpenClose(u8 (*relay_key)(void))
{
    u8 static i=0; 
if(isHome==1&&flag_==1){	
    if(i==0&&RE_KEY_DOWN==relay_key())
        {
					i=1;
          delay_ms(1000);
          SetCH1
					component.pageCircleButton(5,90,40,40,"1",1,Blue_200,24); 
					delay_ms(1000);
          SetCH2
					component.pageCircleButton(61,90,40,40,"2",1,Blue_200,24); 
					delay_ms(1000);
          SetCH3
					component.pageCircleButton(117,90,40,40,"3",1,Blue_200,24);
					delay_ms(1000);		
          SetCH4
					component.pageCircleButton(173,90,40,40,"4",1,Blue_200,24);				
					delay_ms(1000);
          SetCH5
					component.pageCircleButton(5,135,40,40,"5",1,Blue_200,24);
					delay_ms(1000);
          SetCH6
					component.pageCircleButton(61,135,40,40,"6",1,Blue_200,24);
					delay_ms(1000);
          SetCH7
					component.pageCircleButton(117,135,40,40,"7",1,Blue_200,24);
					delay_ms(1000);
          SetCH8
					component.pageCircleButton(173,135,40,40,"8",1,Blue_200,24);
				}else if(i==1&&RE_KEY_DOWN==relay_key()){
					i=0;
				  delay_ms(1000);
          ResetCH8
					component.pageCircleButton(173,135,40,40,"8",0,Blue_200,24);					
					delay_ms(1000);
          ResetCH7
					component.pageCircleButton(117,135,40,40,"7",0,Blue_200,24);
					delay_ms(1000);
          ResetCH6
					component.pageCircleButton(61,135,40,40,"6",0,Blue_200,24);					
					delay_ms(1000);		
          ResetCH5
					component.pageCircleButton(5,135,40,40,"5",0,Blue_200,24);				
					delay_ms(1000);
          ResetCH4
					component.pageCircleButton(173,90,40,40,"4",0,Blue_200,24);					
					delay_ms(1000);
          ResetCH3
					component.pageCircleButton(117,90,40,40,"3",0,Blue_200,24);
					delay_ms(1000);
          ResetCH2				
					component.pageCircleButton(61,90,40,40,"2",0,Blue_200,24); 
					delay_ms(1000);
          ResetCH1
					component.pageCircleButton(5,90,40,40,"1",0,Blue_200,24); 
				}
			}
}


