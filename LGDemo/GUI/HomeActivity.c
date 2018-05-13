#include "HomeActivity.h"
u8 vol[28] = {220,218,230,234,232,228,226,225,223,226,231,232,230,239,235,236,234,229,226,227,226,223,224,225,221,220,218,232};
HomeActivity homeActivity= {mainPage,mainOpenSplash,showVolAndTime,homeActivityAction};
void mainOpenSplash()
{

    Fill_Fast_Rec(0,0,220,176,Black);//刷黑屏
    TFT_Show_Any_Picture(33,73,155,30,Blue_50,LOGO);	//显示LOGO
    delay_ms(1000);
    TFT_Show_Any_Picture(33,73,155,30,Blue_100,LOGO);	//显示LOGO
    delay_ms(1000);
    TFT_Show_Any_Picture(33,73,155,30,Blue_250,LOGO);	//显示LOGO
    delay_ms(1000);
    TFT_Show_Any_Picture(33,73,155,30,Blue_300,LOGO);	//显示LOGO
    delay_ms(1000);
    Fill_Fast_Rec(0,0,220,176,Black);//刷黑屏

}
void showVolAndTime()
{
    u8 static i;

    Fill_Fast_Rec(100,48,50,25,Black);
    TFT_ShowNum(110,48,vol[i],24,White);
    Fill_Fast_Rec(175,0,45,30,Blue);
    TFT_ShowNum(175,13,calendar.hour,16,White);
    TFT_ShowNum(198,13,calendar.min,16,White);
    TFT_ShowString(190,13,":",16,White);
    i++;
    if(i==28)
        i=0;
}
void mainPage()
{
    if(activity.activeActivity==activity.HOME)
        {
            component.titleBar();
            component.pageSpinner(10,0,70,30,"HOME",Blue,White,DOWN);
            TFT_ShowString(10,48,"VOLT:       V",24,White);
            gui_4_yuanhu_CU_EMPTY(5,35,215,85,5,White);

            if(ReadCH1)
                component.pageCircleButton(5,90,40,40,"1",1,Red,24);
            else
                component.pageCircleButton(5,90,40,40,"1",0,Red,24);
            if(ReadCH5)
                component.pageCircleButton(5,135,40,40,"5",1,Red,24);
            else
                component.pageCircleButton(5,135,40,40,"5",0,Red,24);
            if(ReadCH2)
                component.pageCircleButton(61,90,40,40,"2",1,Red,24);
            else
                component.pageCircleButton(61,90,40,40,"2",0,Red,24);
            if(ReadCH6)
                component.pageCircleButton(61,135,40,40,"6",1,Red,24);
            else
                component.pageCircleButton(61,135,40,40,"6",0,Red,24);
            if(ReadCH3)
                component.pageCircleButton(117,90,40,40,"3",1,Red,24);
            else
                component.pageCircleButton(117,90,40,40,"3",0,Red,24);
            if(ReadCH7)
                component.pageCircleButton(117,135,40,40,"7",1,Red,24);
            else
                component.pageCircleButton(117,135,40,40,"7",0,Red,24);
            if(ReadCH4)
                component.pageCircleButton(173,90,40,40,"4",1,Red,24);
            else
                component.pageCircleButton(173,90,40,40,"4",0,Red,24);
            if(ReadCH8)
                component.pageCircleButton(173,135,40,40,"8",1,Red,24);
            else
                component.pageCircleButton(173,135,40,40,"8",0,Red,24);
        }
    homeActivity.homeActivityAction();
};
void homeActivityAction()
{

    while(activity.activeActivity==activity.HOME)
        {
            //系统必要执行函数
            homeActivitySelectItem();

        }

}

void homeActivitySelectItem()
{
    u8 static lastindex=0;
    u8 Anthor = encoder();
    if(activity.toucharea(10,0,70,30,1)==1)
        {
            lastindex=1;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(5,90,40,40,2)==2)
        {
            lastindex=2;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(61,90,40,40,3)==3)
        {
            lastindex=3;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(117,90,40,40,4)==4)
        {
            lastindex=4;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(173,90,40,40,5)==5)
        {
            lastindex=5;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(5,135,40,40,6)==6)
        {
            lastindex=6;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(61,135,40,40,7)==7)
        {
            lastindex=7;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(117,135,40,40,8)==8)
        {
            lastindex=8;
            Anthor=EN_KEY_DOWN;
        }
    if(activity.toucharea(173,135,40,40,9)==9)
        {
            lastindex=9;
            Anthor=EN_KEY_DOWN;
        }
    switch(Anthor)
        {
        case TURN_L:
            delay_ms(50);
            if(lastindex==0)
                {


                    component.pageSpinner(10,0,70,30,"HOME",Blue,Blue_100,DOWN);

                    lastindex=1;
                }
            else if(lastindex==1)
                {

                    component.pageSpinner(10,0,70,30,"HOME",Blue,White,DOWN);
                    component.pageCircleButton(5,90,40,40,"1",1,Blue_100,24);

                    lastindex=2;
                }
            else if(lastindex==2)
                {

                    if(ReadCH1)
                        component.pageCircleButton(5,90,40,40,"1",1,Red ,24);
                    else
                        component.pageCircleButton(5,90,40,40,"1",0,Red,24);

                    component.pageCircleButton(61,90,40,40,"2",1,Blue_100,24);


                    lastindex=3;
                }
            else if(lastindex==3)
                {

                    if(ReadCH2)
                        component.pageCircleButton(61,90,40,40,"2",1,Red,24);
                    else
                        component.pageCircleButton(61,90,40,40,"2",0,Red,24);

                    component.pageCircleButton(117,90,40,40,"3",1,Blue_100,24);


                    lastindex=4;
                }
            else if(lastindex==4)
                {

                    if(ReadCH3)
                        component.pageCircleButton(117,90,40,40,"3",1,Red,24);
                    else
                        component.pageCircleButton(117,90,40,40,"3",0,Red,24);

                    component.pageCircleButton(173,90,40,40,"4",1,Blue_100,24);


                    lastindex=5;
                }
            else if(lastindex==5)
                {

                    if(ReadCH4)
                        component.pageCircleButton(173,90,40,40,"4",1,Red,24);
                    else
                        component.pageCircleButton(173,90,40,40,"4",0,Red,24);
                    component.pageCircleButton(5,135,40,40,"5",1,Blue_100,24);

                    lastindex=6;
                }
            else if(lastindex==6)
                {

                    if(ReadCH5)
                        component.pageCircleButton(5,135,40,40,"5",1,Red,24);
                    else
                        component.pageCircleButton(5,135,40,40,"5",0,Red,24);
                    component.pageCircleButton(61,135,40,40,"6",1,Blue_100,24);
                    lastindex=7;



                }
            else if(lastindex==7)
                {

                    if(ReadCH6)
                        component.pageCircleButton(61,135,40,40,"6",1,Red,24);
                    else
                        component.pageCircleButton(61,135,40,40,"6",0,Red,24);
                    component.pageCircleButton(117,135,40,40,"7",1,Blue_100,24);
                    lastindex=8;


                }
            else if(lastindex==8)
                {


                    if(ReadCH7)
                        component.pageCircleButton(117,135,40,40,"7",1,Red,24);
                    else
                        component.pageCircleButton(117,135,40,40,"7",0,Red,24);
                    component.pageCircleButton(173,135,40,40,"8",1,Blue_100,24);
                    lastindex=9;


                }

            break;
        case TURN_R:

            delay_ms(50);
            if(lastindex==0)
                {



                    component.pageSpinner(10,0,70,30,"HOME",Blue,Blue_100,DOWN);

                    lastindex=1;
                }
            else if(lastindex==2)
                {


                    component.pageSpinner(10,0,70,30,"HOME",Blue,Blue_100,DOWN);
                    if(ReadCH1)
                        component.pageCircleButton(5,90,40,40,"1",1,Red,24);
                    else
                        component.pageCircleButton(5,90,40,40,"1",0,Red,24);
                    lastindex=1;


                }
            else if(lastindex==3)
                {

                    if(ReadCH2)
                        component.pageCircleButton(61,90,40,40,"2",1,Red,24);
                    else
                        component.pageCircleButton(61,90,40,40,"2",0,Red,24);
                    component.pageCircleButton(5,90,40,40,"1",1,Blue_100,24);


                    lastindex=2;

                }
            else if(lastindex==4)
                {

                    component.pageCircleButton(61,90,40,40,"2",1,Blue_100,24);
                    if(ReadCH3)
                        component.pageCircleButton(117,90,40,40,"3",1,Red,24);
                    else
                        component.pageCircleButton(117,90,40,40,"3",0,Red,24);

                    lastindex=3;
                }
            else if(lastindex==5)
                {

                    component.pageCircleButton(117,90,40,40,"3",1,Blue_100,24);
                    if(ReadCH4)
                        component.pageCircleButton(173,90,40,40,"4",1,Red,24);
                    else
                        component.pageCircleButton(173,90,40,40,"4",0,Red,24);


                    lastindex=4;
                }
            else if(lastindex==6)
                {

                    component.pageCircleButton(173,90,40,40,"4",1,Blue_100,24);
                    if(ReadCH5)
                        component.pageCircleButton(5,135,40,40,"5",1,Red,24);
                    else
                        component.pageCircleButton(5,135,40,40,"5",0,Red,24);

                    lastindex=5;
                }
            else if(lastindex==7)
                {
                    component.pageCircleButton(5,135,40,40,"5",1,Blue_100,24);
                    if(ReadCH6)
                        component.pageCircleButton(61,135,40,40,"6",1,Red,24);
                    else
                        component.pageCircleButton(61,135,40,40,"6",0,Red,24);


                    lastindex=6;

                }
            else if(lastindex==8)
                {

                    component.pageCircleButton(61,135,40,40,"6",1,Blue_100,24);
                    if(ReadCH7)
                        component.pageCircleButton(117,135,40,40,"7",1,Red,24);
                    else
                        component.pageCircleButton(117,135,40,40,"7",0,Red,24);
                    lastindex=7;
                }
            else if(lastindex==9)
                {
                    component.pageCircleButton(117,135,40,40,"7",1,Blue_100,24);
                    if(ReadCH8)
                        component.pageCircleButton(173,135,40,40,"8",1,Red,24);
                    else
                        component.pageCircleButton(173,135,40,40,"8",0,Red,24);
                    lastindex=8;
                }
            break;
        case EN_KEY_DOWN:

            if(lastindex==1)
                {
                   
									  activity.activeActivity=activity.SPINNER;
									  lastindex=0;
                }
            else if(lastindex==2)
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
                        component.pageCircleButton(5,90,40,40,"1",1,Red,24);
                    else
                        component.pageCircleButton(5,90,40,40,"1",0,Red,24);

                }
            else if(lastindex==3)
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
                        component.pageCircleButton(61,90,40,40,"2",1,Red,24);
                    else
                        component.pageCircleButton(61,90,40,40,"2",0,Red,24);

                }
            else if(lastindex==4)
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
                        component.pageCircleButton(117,90,40,40,"3",1,Red,24);
                    else
                        component.pageCircleButton(117,90,40,40,"3",0,Red,24);


                }
            else if(lastindex==5)
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
                        component.pageCircleButton(173,90,40,40,"4",1,Red,24);
                    else
                        component.pageCircleButton(173,90,40,40,"4",0,Red,24);

                }
            else if(lastindex==6)
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
                        component.pageCircleButton(5,135,40,40,"5",1,Red,24);
                    else
                        component.pageCircleButton(5,135,40,40,"5",0,Red,24);

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
                        component.pageCircleButton(61,135,40,40,"6",1,Red,24);
                    else
                        component.pageCircleButton(61,135,40,40,"6",0,Red,24);
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
                        component.pageCircleButton(117,135,40,40,"7",1,Red,24);
                    else
                        component.pageCircleButton(117,135,40,40,"7",0,Red,24);
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
                        component.pageCircleButton(173,135,40,40,"8",1,Red,24);
                    else
                        component.pageCircleButton(173,135,40,40,"8",0,Red,24);

                }
            
            break;
        }
    if(flag_ten_sec>=10)
        {
            flag_ten_sec=0;
            showVolAndTime();
        }

}

