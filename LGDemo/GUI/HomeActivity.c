#include "HomeActivity.h"
u8 vol[28] = {220,218,230,234,232,228,226,225,223,226,231,232,230,239,235,236,234,229,226,227,226,223,224,225,221,220,218,232};
HomeActivity homeActivity= {mainPage,mainOpenSplash,showVolAndTime,homeActivityAction,0,220,0,flashChannel,flashChannelSate};
Rectangle homeItemXY[10];
Rectangle passcordItemXY[5];
pwd_data pwdTempData= {0,0,0,0};
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
            homeItemXY[0].xyStructuee=component.pageSpinner(10,0,70,30,"HOME",Blue,White,DOWN);
            if(homeActivity.machine==1)
                homeItemXY[9].xyStructuee=component.pageButton(95,13,60,17,"LOCK",Blue,White);
            if(homeActivity.machine==0)
                homeItemXY[9].xyStructuee=component.pageButton(95,13,60,17,"UNLOCK",Blue,White);


            //DisAPI.Fill_Fast_Rec(28,48,190-28,24,Black);
            DisAPI.TFT_ShowString(18+10,48,"VOLT:",24,White);
            DisAPI.TFT_ShowNum(100+10,48,220,24,White);
            DisAPI.TFT_ShowString(160+10,48,"V",24,White);
//					  component.pageButton(18+10,48,80,24,"PASSWORD:",Blue_200,White);
//					  passcordItemXY[0].xyStructuee=component.pageEditText(100+10,48,20,24,0,White,Black);
//					  passcordItemXY[1].xyStructuee=component.pageEditText(120+10,48,20,24,0,White,Black);
//					  passcordItemXY[2].xyStructuee=component.pageEditText(140+10,48,20,24,0,White,Black);
//					  passcordItemXY[3].xyStructuee=component.pageEditText(160+10,48,20,24,0,White,Black);

            gui_4_yuanhu_CU_EMPTY(5,35,215,85,5,White);

            if(ReadCH1)
                homeItemXY[1].xyStructuee=component.pageCircleButton(5,90,40,40,"1",1,Red,24);
            else
                homeItemXY[1].xyStructuee=component.pageCircleButton(5,90,40,40,"1",0,Red,24);
            if(ReadCH5)
                homeItemXY[2].xyStructuee=component.pageCircleButton(5,135,40,40,"5",1,Red,24);
            else
                homeItemXY[2].xyStructuee=component.pageCircleButton(5,135,40,40,"5",0,Red,24);
            if(ReadCH2)
                homeItemXY[3].xyStructuee=component.pageCircleButton(61,90,40,40,"2",1,Red,24);
            else
                homeItemXY[3].xyStructuee=component.pageCircleButton(61,90,40,40,"2",0,Red,24);
            if(ReadCH6)
                homeItemXY[4].xyStructuee=component.pageCircleButton(61,135,40,40,"6",1,Red,24);
            else
                homeItemXY[4].xyStructuee=component.pageCircleButton(61,135,40,40,"6",0,Red,24);
            if(ReadCH3)
                homeItemXY[5].xyStructuee=component.pageCircleButton(117,90,40,40,"3",1,Red,24);
            else
                homeItemXY[5].xyStructuee=component.pageCircleButton(117,90,40,40,"3",0,Red,24);
            if(ReadCH7)
                homeItemXY[6].xyStructuee=component.pageCircleButton(117,135,40,40,"7",1,Red,24);
            else
                homeItemXY[6].xyStructuee=component.pageCircleButton(117,135,40,40,"7",0,Red,24);
            if(ReadCH4)
                homeItemXY[7].xyStructuee=component.pageCircleButton(173,90,40,40,"4",1,Red,24);
            else
                homeItemXY[7].xyStructuee=component.pageCircleButton(173,90,40,40,"4",0,Red,24);
            if(ReadCH8)
                homeItemXY[8].xyStructuee=component.pageCircleButton(173,135,40,40,"8",1,Red,24);
            else
                homeItemXY[8].xyStructuee=component.pageCircleButton(173,135,40,40,"8",0,Red,24);
        }
    homeActivity.homeActivityAction();
};
void homeActivityAction()
{

    while(activity.activeActivity==activity.HOME)
        {
            /*这里放置系统必要执行函数*/
            activity.executeInWhile();
					  homeActivity.flashChannelSate(channel.getflashChannel());
            activity.flashTime();
            if(homeActivity.machine==0)
                homeActivitySelectItem();
            if(homeActivity.machine==1)
                pwdSelectItem();

        }

}

void pwdSelectItem()
{
    u8 state=encoder();
    u8 static anchor=0;
    u8 static encoderAddSubflag=0;
    u8 static lastanchor=0;
    u8 addsubsatus=activity.encoderToAddSub(&encoderAddSubflag,&state);
    if(encoderAddSubflag)
        state=0;

    if(activity.toucharea(homeItemXY[9].xyStructuee.sx,homeItemXY[9].xyStructuee.sy,homeItemXY[9].xyStructuee.width,homeItemXY[9].xyStructuee.height,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(passcordItemXY[0].xyStructuee.sx,passcordItemXY[0].xyStructuee.sy,passcordItemXY[0].xyStructuee.width,passcordItemXY[0].xyStructuee.height,1)==1)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(passcordItemXY[1].xyStructuee.sx,passcordItemXY[1].xyStructuee.sy,passcordItemXY[1].xyStructuee.width,passcordItemXY[1].xyStructuee.height,1)==1)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(passcordItemXY[2].xyStructuee.sx,passcordItemXY[2].xyStructuee.sy,passcordItemXY[2].xyStructuee.width,passcordItemXY[2].xyStructuee.height,1)==1)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(passcordItemXY[3].xyStructuee.sx,passcordItemXY[3].xyStructuee.sy,passcordItemXY[3].xyStructuee.width,passcordItemXY[3].xyStructuee.height,1)==1)
        {
            anchor=5;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(passcordItemXY[4].xyStructuee.sx,passcordItemXY[4].xyStructuee.sy,passcordItemXY[4].xyStructuee.width,passcordItemXY[4].xyStructuee.height,1)==1)
        {
            anchor=6;
            state=EN_KEY_DOWN;
        }
    switch(addsubsatus)
        {
        case ADD:
            if(pwdTempData.p_one<9&&anchor==2)
                {
                    pwdTempData.p_one++;
                    component.flashData(&passcordItemXY[0],pwdTempData.p_one,Blue_100,Black);
                }
            if(pwdTempData.p_two<9&&anchor==3)
                {
                    pwdTempData.p_two++;
                    component.flashData(&passcordItemXY[1],pwdTempData.p_two,Blue_100,Black);
                }
            if(pwdTempData.p_three<9&&anchor==4)
                {
                    pwdTempData.p_three++;
                    component.flashData(&passcordItemXY[2],pwdTempData.p_three,Blue_100,Black);
                }
            if(pwdTempData.p_four<9&&anchor==5)
                {
                    pwdTempData.p_four++;
                    component.flashData(&passcordItemXY[3],pwdTempData.p_four,Blue_100,Black);
                }
            break;
        case SUB:
            if(pwdTempData.p_one>0&&anchor==2)
                {
                    pwdTempData.p_one--;
                    component.flashData(&passcordItemXY[0],pwdTempData.p_one,Blue_100,Black);
                }
            if(pwdTempData.p_two&&anchor==3)
                {
                    pwdTempData.p_two--;
                    component.flashData(&passcordItemXY[1],pwdTempData.p_two,Blue_100,Black);
                }
            if(pwdTempData.p_three>0&&anchor==4)
                {
                    pwdTempData.p_three--;
                    component.flashData(&passcordItemXY[2],pwdTempData.p_three,Blue_100,Black);
                }
            if(pwdTempData.p_four>0&&anchor==5)
                {
                    pwdTempData.p_four--;
                    component.flashData(&passcordItemXY[3],pwdTempData.p_four,Blue_100,Black);
                }
            break;
        }
    switch(state)
        {
        case TURN_L:
            if(anchor<6&&homeActivity.isShowPWD==1)
                flashPasswordItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1&&homeActivity.isShowPWD==1)
                flashPasswordItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:

            if(anchor==1)
                {
                    if(homeActivity.isShowPWD==0)
                        homeActivity.isShowPWD=1;
                    else if(homeActivity.isShowPWD==1)
                        homeActivity.isShowPWD=0;

                }
            else if(anchor==2||anchor==3||anchor==4||anchor==5)
                {
                    encoderAddSubflag=1;
                    flashPasswordItem(anchor,lastanchor);
                    lastanchor=anchor;
                }
            else if(anchor==6)
                {
                    encoderAddSubflag=0;
                    pwdTempData.p_one=0;
                    pwdTempData.p_two=0;
                    pwdTempData.p_three=0;
                    pwdTempData.p_four=0;
                    if(pwdActivity.checkPwd(&pwdTempData,pwdActivity.pwdData)==4)
                        {



                            homeActivity.isShowPWD=0;
                            homeActivity.machine=0;
                            component.pageButton(95,13,60,17,"UNLOCK",Blue,White);

                        }
                    else
                        {
                            DisAPI.Fill_Fast_Rec(18-5,48,212-18,24,Black);
                            DisAPI.Write_Word_Center(18-5,48,212,48+24,16,"PASSWORD ERROR",White);
                            delay_ms(1000);

                        }
                    anchor=1;
                }
            if(homeActivity.isShowPWD==1&&anchor==1)
                {
                    /*显示PWD编辑框*/
                    delay_ms(500);
                    DisAPI.Fill_Fast_Rec(18-5,48,212-18,24,Black);
                    component.pageButton(13,48,80,24,"PASSWORD:",Blue_200,White);
                    passcordItemXY[0].xyStructuee=component.pageEditText(100-5,48,20,24,pwdTempData.p_one,White,Black);
                    passcordItemXY[1].xyStructuee=component.pageEditText(120-5,48,20,24,pwdTempData.p_two,White,Black);
                    passcordItemXY[2].xyStructuee=component.pageEditText(140-5,48,20,24,pwdTempData.p_three,White,Black);
                    passcordItemXY[3].xyStructuee=component.pageEditText(160-5,48,20,24,pwdTempData.p_four,White,Black);
                    passcordItemXY[4].xyStructuee=component.pageButton(180-5,48,30,24,"OK",White,Black);
                }
            else if(homeActivity.isShowPWD==0&&anchor==1)
                {
                    /*显示电压*/
                    delay_ms(500);
                    DisAPI.Fill_Fast_Rec(18-5,48,212-18,24,Black);
                    DisAPI.TFT_ShowString(18+10,48,"VOLT:",24,White);
                    DisAPI.TFT_ShowNum(100+10,48,220,24,White);
                    DisAPI.TFT_ShowString(160+10,48,"V",24,White);

                }
            break;
        }
}
void flashPasswordItem(u8 anchor,u8 lastanchor)
{

    switch(anchor)
        {
        case 1:
            if(homeActivity.machine==1)
                homeItemXY[9].xyStructuee=component.pageButton(95,13,60,17,"LOCK",Blue,Blue_100);
            if(homeActivity.machine==0)
                homeItemXY[9].xyStructuee=component.pageButton(95,13,60,17,"UNLOCK",Blue,Blue_100);
            break;
        case 2:
            component.flashData(&passcordItemXY[0],pwdTempData.p_one,Blue_100,Black);
            break;
        case 3:
            component.flashData(&passcordItemXY[1],pwdTempData.p_two,Blue_100,Black);
            break;
        case 4:
            component.flashData(&passcordItemXY[2],pwdTempData.p_three,Blue_100,Black);
            break;
        case 5:
            component.flashData(&passcordItemXY[3],pwdTempData.p_four,Blue_100,Black);
            break;
        case 6:
            component.pageButton(180-5,48,30,24,"OK",Blue_100,Black);
            break;
        }
    if(anchor!=lastanchor)
        switch(lastanchor)
            {
            case 1:
                if(homeActivity.machine==1)
                    homeItemXY[9].xyStructuee=component.pageButton(95,13,60,17,"LOCK",Blue,White);
                if(homeActivity.machine==0)
                    homeItemXY[9].xyStructuee=component.pageButton(95,13,60,17,"UNLOCK",Blue,White);
                break;
            case 2:
                component.flashData(&passcordItemXY[0],pwdTempData.p_one,White,Black);
                break;
            case 3:
                component.flashData(&passcordItemXY[1],pwdTempData.p_two,White,Black);
                break;
            case 4:
                component.flashData(&passcordItemXY[2],pwdTempData.p_three,White,Black);
                break;
            case 5:
                component.flashData(&passcordItemXY[3],pwdTempData.p_four,White,Black);
                break;
            case 6:
                component.pageButton(180-5,48,30,24,"OK",White,Black);
                break;
            }

}
void homeActivitySelectItem()
{
    u8 static lastindex=0;
    u8 Anthor = encoder();
    RectangleXY xy=homeItemXY[0].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,1)==1)
        {
            lastindex=1;
            Anthor=EN_KEY_DOWN;

        }
    xy=homeItemXY[1].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,2)==2)
        {
            lastindex=2;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[2].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,3)==3)
        {
            lastindex=6;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[3].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,4)==4)
        {
            lastindex=3;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[4].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,5)==5)
        {
            lastindex=7;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[5].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,6)==6)
        {
            lastindex=4;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[6].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,7)==7)
        {
            lastindex=8;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[7].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,8)==8)
        {
            lastindex=5;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[8].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,9)==9)
        {
            lastindex=9;
            Anthor=EN_KEY_DOWN;
        }
    xy=homeItemXY[9].xyStructuee;
    if(activity.toucharea(xy.sx,xy.sy,xy.width,xy.height,10)==10)
        {
            lastindex=10;
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

                    flashChannel(1);

                    component.pageCircleButton(61,90,40,40,"2",1,Blue_100,24);


                    lastindex=3;
                }
            else if(lastindex==3)
                {

                    flashChannel(2);

                    component.pageCircleButton(117,90,40,40,"3",1,Blue_100,24);


                    lastindex=4;
                }
            else if(lastindex==4)
                {

                    flashChannel(3);

                    component.pageCircleButton(173,90,40,40,"4",1,Blue_100,24);


                    lastindex=5;
                }
            else if(lastindex==5)
                {

                    flashChannel(4);
                    component.pageCircleButton(5,135,40,40,"5",1,Blue_100,24);

                    lastindex=6;
                }
            else if(lastindex==6)
                {

                    flashChannel(5);
                    component.pageCircleButton(61,135,40,40,"6",1,Blue_100,24);
                    lastindex=7;



                }
            else if(lastindex==7)
                {

                    flashChannel(6);
                    component.pageCircleButton(117,135,40,40,"7",1,Blue_100,24);
                    lastindex=8;


                }
            else if(lastindex==8)
                {

                    flashChannel(7);
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
                    flashChannel(1);
                    lastindex=1;


                }
            else if(lastindex==3)
                {

                    flashChannel(2);
                    component.pageCircleButton(5,90,40,40,"1",1,Blue_100,24);


                    lastindex=2;

                }
            else if(lastindex==4)
                {

                    component.pageCircleButton(61,90,40,40,"2",1,Blue_100,24);
                    flashChannel(3);

                    lastindex=3;
                }
            else if(lastindex==5)
                {

                    component.pageCircleButton(117,90,40,40,"3",1,Blue_100,24);
                    flashChannel(4);


                    lastindex=4;
                }
            else if(lastindex==6)
                {

                    component.pageCircleButton(173,90,40,40,"4",1,Blue_100,24);
                    flashChannel(5);

                    lastindex=5;
                }
            else if(lastindex==7)
                {
                    component.pageCircleButton(5,135,40,40,"5",1,Blue_100,24);
                    flashChannel(6);


                    lastindex=6;

                }
            else if(lastindex==8)
                {

                    component.pageCircleButton(61,135,40,40,"6",1,Blue_100,24);
                    flashChannel(7);
                    lastindex=7;
                }
            else if(lastindex==9)
                {
                    component.pageCircleButton(117,135,40,40,"7",1,Blue_100,24);
                    flashChannel(8);
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
                            if(EnCH1)
                                SetCH1
                            }
                    flashChannel(1);
                    delay_ms(500);
                }
            else if(lastindex==3)
                {

                    if(ReadCH2)
                        {
                            ResetCH2
                        }
                    else
                        {
                            if(EnCH2)
                                SetCH2

                            }
                    flashChannel(2);
                    delay_ms(500);
                }
            else if(lastindex==4)
                {

                    if(ReadCH3)
                        {
                            ResetCH3
                        }
                    else
                        {
                            if(EnCH3)
                                SetCH3
                            }
                    flashChannel(3);

                    delay_ms(500);
                }
            else if(lastindex==5)
                {

                    if(ReadCH4)
                        {
                            ResetCH4
                        }
                    else
                        {
                            if(EnCH4)
                                SetCH4
                            }
                    flashChannel(4);
                    delay_ms(500);
                }
            else if(lastindex==6)
                {

                    if(ReadCH5)
                        {
                            ResetCH5
                        }
                    else
                        {
                            if(EnCH5)
                                SetCH5
                            }
                    flashChannel(5);
                    delay_ms(500);
                }
            else if(lastindex==7)
                {

                    if(ReadCH6)
                        {
                            ResetCH6
                        }
                    else
                        {
                            if(EnCH6)
                                SetCH6
                            }
                    flashChannel(6);
                    delay_ms(500);
                }
            else if(lastindex==8)
                {

                    if(ReadCH7)
                        {
                            ResetCH7
                        }
                    else
                        {
                            if(EnCH7)
                                SetCH7
                            }
                    flashChannel(7);
                    delay_ms(500);
                }
            else if(lastindex==9)
                {

                    if(ReadCH8)
                        {
                            ResetCH8
                        }
                    else
                        {
                            if(EnCH8)
                                SetCH8
                            }
                    flashChannel(8);
                    delay_ms(500);
                }
            else if(lastindex==10)
                {
                    homeItemXY[9].xyStructuee=component.pageButton(95,13,60,17,"LOCK",Blue,White);
                    lastindex=0;
                    homeActivity.machine=1;
                    delay_ms(500);
                }
            break;
        }
}
void flashChannel(u8 channelIndex)
{
    switch(channelIndex)
        {
        case 1:
            if(ReadCH1)
                component.pageCircleButton(5,90,40,40,"1",1,Red,24);
            else
                component.pageCircleButton(5,90,40,40,"1",0,Red,24);
            break;
        case 2:
            if(ReadCH2)
                component.pageCircleButton(61,90,40,40,"2",1,Red,24);
            else
                component.pageCircleButton(61,90,40,40,"2",0,Red,24);
            break;
        case 3:
            if(ReadCH3)
                component.pageCircleButton(117,90,40,40,"3",1,Red,24);
            else
                component.pageCircleButton(117,90,40,40,"3",0,Red,24);
            break;
        case 4:
            if(ReadCH4)
                component.pageCircleButton(173,90,40,40,"4",1,Red,24);
            else
                component.pageCircleButton(173,90,40,40,"4",0,Red,24);
            break;
        case 5:
            if(ReadCH5)
                component.pageCircleButton(5,135,40,40,"5",1,Red,24);
            else
                component.pageCircleButton(5,135,40,40,"5",0,Red,24);
            break;
        case 6:
            if(ReadCH6)
                component.pageCircleButton(61,135,40,40,"6",1,Red,24);
            else
                component.pageCircleButton(61,135,40,40,"6",0,Red,24);
            break;
        case 7:
            if(ReadCH7)
                component.pageCircleButton(117,135,40,40,"7",1,Red,24);
            else
                component.pageCircleButton(117,135,40,40,"7",0,Red,24);
            break;
        case 8:
            if(ReadCH8)
                component.pageCircleButton(173,135,40,40,"8",1,Red,24);
            else
                component.pageCircleButton(173,135,40,40,"8",0,Red,24);
            break;
        }
}

void  flashChannelSate(u8 sec){//刷新CHANNEL状态
  if(sec>0)sec-=1;
	if(sec==delayActivity.chan_open_data->chan1){
	flashChannel(1);
	
	}
	if(sec==delayActivity.chan_open_data->chan2){
	
	flashChannel(2);
	}
	if(sec==delayActivity.chan_open_data->chan3){
	flashChannel(3);
	
	}
	if(sec==delayActivity.chan_open_data->chan4){
	flashChannel(4);
	
	}
	if(sec==delayActivity.chan_open_data->chan5){
	
	flashChannel(5);
	}
	if(sec==delayActivity.chan_open_data->chan6){
	flashChannel(6);
	
	}
	if(sec==delayActivity.chan_open_data->chan7){
	
	flashChannel(7);
	}
 if(sec==delayActivity.chan_open_data->chan8){
	
	flashChannel(8);
	}
 

	if(sec==delayActivity.chan_close_data->chan1){
	flashChannel(1);
	
	}
	if(sec==delayActivity.chan_close_data->chan2){
	
	flashChannel(2);
	}
	if(sec==delayActivity.chan_close_data->chan3){
	
	flashChannel(3);
	}
	if(sec==delayActivity.chan_close_data->chan4){
	
	flashChannel(4);
	}
	if(sec==delayActivity.chan_close_data->chan5){
	flashChannel(5);
	
	}
	if(sec==delayActivity.chan_close_data->chan6){
	
	flashChannel(6);
	}
	if(sec==delayActivity.chan_close_data->chan7){
	
	flashChannel(7);
	}
 if(sec==delayActivity.chan_close_data->chan8){
	flashChannel(8);
	
	}
}
