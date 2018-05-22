#include "AUZActivity.h"


Rectangle auzXY[15];
AUZ_Data auzDataTemp= {0,0,0,0,0,0};//auz code 临时数据
AUZ_Data auzData= {1,5,0,0,5,1};//auz code 数据
AUZ_Data userData= {0,0,0,0,0,0};//user code 临时数据写到24C08
u8 freeTime=50;//免费使用天数 来源24C08
u8 isAUZRight=0;//auz code是否正确
Rectangle auzXY_u[7];
AUZ_Data userDataTemp= {0,0,0,0};
AUZ_Data user_Data= {1,2,3,4,5,6}; //user code 数据来源24C08
AUZActivity auzActivity= {auzActivityPage,auzActivityItemSelect,&userData,&freeTime,checkAUZData,saveAUZData,readAUZData,auzActivityUserPage};
void auzActivityUserPage()
{
    if(isFreeDayOver()==2)
        {
            u8 isUserRight=1;
            component.pageButton(20,65,60,20,"USER CODE:",Black,White);
            DisAPI.Fill_Fast_Rec(10,85,150,20,White);
            auzXY_u[0].xyStructuee=component.pageEditText(100-70,85,18,20,0,White,Black);
            auzXY_u[1].xyStructuee=component.pageEditText(118-70,85,18,20,0,White,Black);
            auzXY_u[2].xyStructuee=component.pageEditText(136-70,85,18,20,0,White,Black);
            auzXY_u[3].xyStructuee=component.pageEditText(154-70,85,18,20,0,White,Black);
            auzXY_u[4].xyStructuee=component.pageEditText(172-70,85,18,20,0,White,Black);
            auzXY_u[5].xyStructuee=component.pageEditText(190-70,85,18,20,0,White,Black);
            auzXY_u[6].xyStructuee=component.pageButton(170,85,40,20,"OK",Blue_200,White);
            while(isUserRight)
                {
                    auzActivityUserPageItemSelect(&userDataTemp,&isUserRight);

                }
        }
}
void auzActivityUserPageItemSelect(AUZ_Data* userDataTemp,u8* isUserRight)
{
    u8 state=encoder();
    u8 static anchor=0;
    u8 static encoderAddSubflag=0;
    u8 static lastanchor=0;
    u8 static is_user_freeTime_DataChange=0;
    u8 addsubsatus=activity.encoderToAddSub(&encoderAddSubflag,&state);
    if(encoderAddSubflag)
        state=0;
    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    switch(addsubsatus)
        {
        case ADD:
            if(userDataTemp->p_one<9&&anchor==1)
                {
                    userDataTemp->p_one++;
                    component.flashData(&auzXY_u[0],userDataTemp->p_one,Blue_100,Black);
                }
            if(userDataTemp->p_two<9&&anchor==2)
                {
                    userDataTemp->p_two++;
                    component.flashData(&auzXY_u[1],userDataTemp->p_two,Blue_100,Black);
                }
            if(userDataTemp->p_three<9&&anchor==3)
                {
                    userDataTemp->p_three++;
                    component.flashData(&auzXY_u[2],userDataTemp->p_three,Blue_100,Black);
                }
            if(userDataTemp->p_four<9&&anchor==4)
                {
                    userDataTemp->p_four++;
                    component.flashData(&auzXY_u[3],userDataTemp->p_four,Blue_100,Black);
                }

            if(userDataTemp->p_five<9&&anchor==5)
                {
                    userDataTemp->p_five++;
                    component.flashData(&auzXY_u[4],userDataTemp->p_five,Blue_100,Black);
                }
            if(userDataTemp->p_six<9&&anchor==6)
                {
                    userDataTemp->p_six++;
                    component.flashData(&auzXY_u[5],userDataTemp->p_six,Blue_100,Black);
                }
            break;
        case SUB:
            if(userDataTemp->p_one>0&&anchor==1)
                {
                    userDataTemp->p_one--;
                    component.flashData(&auzXY_u[0],userDataTemp->p_one,Blue_100,Black);
                }
            if(userDataTemp->p_two>0&&anchor==2)
                {
                    userDataTemp->p_two--;
                    component.flashData(&auzXY_u[1],userDataTemp->p_two,Blue_100,Black);
                }
            if(userDataTemp->p_three>0&&anchor==3)
                {
                    userDataTemp->p_three--;
                    component.flashData(&auzXY_u[2],userDataTemp->p_three,Blue_100,Black);
                }
            if(userDataTemp->p_four>0&&anchor==4)
                {
                    userDataTemp->p_four--;
                    component.flashData(&auzXY_u[3],userDataTemp->p_four,Blue_100,Black);
                }
            if(userDataTemp->p_five>0&&anchor==5)
                {
                    userDataTemp->p_five--;
                    component.flashData(&auzXY_u[4],userDataTemp->p_five,Blue_100,Black);
                }
            if(userDataTemp->p_six>0&&anchor==6)
                {
                    userDataTemp->p_six--;
                    component.flashData(&auzXY_u[5],userDataTemp->p_six,Blue_100,Black);
                }
            break;
        }
    switch(state)
        {
        case TURN_L:
            if(anchor<7)
                flashUserItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashUserItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            if(anchor==1||anchor==2||anchor==3||anchor==4||anchor==5||anchor==6)
                {
                    encoderAddSubflag=1;
                }
            else if(anchor==7)
                {
                    auzActivity.readAUZData();
                    if(checkAUZData(&(*userDataTemp),&user_Data)==6)
                        {
                            *isUserRight=0;//退出AUZ界面
                            /*永久使用*/
                            freeTime=100;
                            AT24CXX_Write(221,&freeTime,1);
                        }
                    else
                        {
                            component.pageButton(80,110,60,20,"ERROR",Black,White);
                            delay_ms(1000);
                            component.pageButton(80,110,60,20,"ERROR",Black,Black);
                        }

                }
            break;
        }
}
void flashUserItem(u8 anchor,u8 lastanchor)
{
    switch(anchor)
        {
        case 1:
            component.flashData(&auzXY_u[0],userDataTemp.p_one,Blue_100,Black);
            break;
        case 2:
            component.flashData(&auzXY_u[1],userDataTemp.p_two,Blue_100,Black);
            break;
        case 3:
            component.flashData(&auzXY_u[2],userDataTemp.p_three,Blue_100,Black);
            break;
        case 4:
            component.flashData(&auzXY_u[3],userDataTemp.p_four,Blue_100,Black);
            break;
        case 5:
            component.flashData(&auzXY_u[4],userDataTemp.p_five,Blue_100,Black);
            break;
        case 6:
            component.flashData(&auzXY_u[5],userDataTemp.p_six,Blue_100,Black);
            break;
        case 7:
            component.pageButton(170,85,40,20,"OK",Blue_100,White);
            break;
        }
    if(anchor!=lastanchor)
        switch(lastanchor)
            {
            case 1:
                component.flashData(&auzXY_u[0],userDataTemp.p_one,White,Black);
                break;
            case 2:
                component.flashData(&auzXY_u[1],userDataTemp.p_two,White,Black);
                break;
            case 3:
                component.flashData(&auzXY_u[2],userDataTemp.p_three,White,Black);
                break;
            case 4:
                component.flashData(&auzXY_u[3],userDataTemp.p_four,White,Black);
                break;
            case 5:
                component.flashData(&auzXY_u[4],userDataTemp.p_five,White,Black);
                break;
            case 6:
                component.flashData(&auzXY_u[5],userDataTemp.p_six,White,Black);
                break;
            case 7:
                component.pageButton(170,85,40,20,"OK",Blue_200,White);
                break;
            }



}
void auzActivityPage()
{
    if(activity.activeActivity==activity.AUZ)
        {

            component.titleBar();
            auzXY[0].xyStructuee=component.pageSpinner(10,0,70,30,"AUZ",Blue,White,DOWN);

            component.pageButton(15,60,80,20,"AUZ CODE",Blue_200,White);
            component.pageButton(15,85,80,20,"USER CODE",Blue_200,White);

            auzXY[1].xyStructuee=component.pageEditText(100-5,60,18,20,0,White,Black);
            auzXY[2].xyStructuee=component.pageEditText(118-5,60,18,20,0,White,Black);
            auzXY[3].xyStructuee=component.pageEditText(136-5,60,18,20,0,White,Black);
            auzXY[4].xyStructuee=component.pageEditText(154-5,60,18,20,0,White,Black);
            auzXY[5].xyStructuee=component.pageEditText(172-5,60,18,20,0,White,Black);
            auzXY[6].xyStructuee=component.pageEditText(190-5,60,18,20,0,White,Black);

            auzXY[7].xyStructuee=component.pageEditText(100-5,85,18,20,0,White,Black);
            auzXY[8].xyStructuee=component.pageEditText(118-5,85,18,20,0,White,Black);
            auzXY[9].xyStructuee=component.pageEditText(136-5,85,18,20,0,White,Black);
            auzXY[10].xyStructuee=component.pageEditText(154-5,85,18,20,0,White,Black);
            auzXY[11].xyStructuee=component.pageEditText(172-5,85,18,20,0,White,Black);
            auzXY[12].xyStructuee=component.pageEditText(190-5,85,18,20,0,White,Black);

            component.pageButton(15,110,80,20,"FREE DAY",Blue_200,White);
            if(freeTime<100)
                auzXY[13].xyStructuee=component.pageEditText(100-5,110,108,20,freeTime,White,Black);
            else
                auzXY[13].xyStructuee=component.pageButton(100-5,110,108,20,"MAX",White,Black);
            component.clear(0,157,220,18,Blue);
            auzXY[14].xyStructuee=component.pageButton(175,157,40,18,"OK",Blue,White);

        }
    auzActivityAction();
}
void auzActivityAction()
{

    while(activity.activeActivity==activity.AUZ)
        {
            activity.flashTime();
            auzActivityItemSelect();
        }

}
void auzActivityItemSelect()
{

    u8 state=encoder();
    u8 static anchor=0;
    u8 static encoderAddSubflag=0;
    u8 static lastanchor=0;
    u8 static is_user_freeTime_DataChange=0;
    u8 addsubsatus=activity.encoderToAddSub(&encoderAddSubflag,&state);
    if(encoderAddSubflag)
        state=0;

    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[1].xyStructuee.sx,auzXY[1].xyStructuee.sy,auzXY[1].xyStructuee.width,auzXY[1].xyStructuee.height,2)==2)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[2].xyStructuee.sx,auzXY[2].xyStructuee.sy,auzXY[2].xyStructuee.width,auzXY[2].xyStructuee.height,2)==2)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[3].xyStructuee.sx,auzXY[3].xyStructuee.sy,auzXY[3].xyStructuee.width,auzXY[3].xyStructuee.height,2)==2)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[4].xyStructuee.sx,auzXY[4].xyStructuee.sy,auzXY[4].xyStructuee.width,auzXY[4].xyStructuee.height,2)==2)
        {
            anchor=5;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[5].xyStructuee.sx,auzXY[5].xyStructuee.sy,auzXY[5].xyStructuee.width,auzXY[5].xyStructuee.height,2)==2)
        {
            anchor=6;
            state=EN_KEY_DOWN;
        }

    if(activity.toucharea(auzXY[6].xyStructuee.sx,auzXY[6].xyStructuee.sy,auzXY[6].xyStructuee.width,auzXY[6].xyStructuee.height,2)==2)
        {
            anchor=7;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[7].xyStructuee.sx,auzXY[7].xyStructuee.sy,auzXY[7].xyStructuee.width,auzXY[7].xyStructuee.height,2)==2&&isAUZRight==1)
        {
            anchor=8;
            state=EN_KEY_DOWN;
        }
				
    if(activity.toucharea(auzXY[8].xyStructuee.sx,auzXY[8].xyStructuee.sy,auzXY[8].xyStructuee.width,auzXY[8].xyStructuee.height,2)==2&&isAUZRight==1)
        {
            anchor=9;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[9].xyStructuee.sx,auzXY[9].xyStructuee.sy,auzXY[9].xyStructuee.width,auzXY[9].xyStructuee.height,2)==2&&isAUZRight==1)
        {
            anchor=10;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[10].xyStructuee.sx,auzXY[10].xyStructuee.sy,auzXY[10].xyStructuee.width,auzXY[10].xyStructuee.height,2)==2&&isAUZRight==1)
        {
            anchor=11;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[11].xyStructuee.sx,auzXY[11].xyStructuee.sy,auzXY[11].xyStructuee.width,auzXY[11].xyStructuee.height,2)==2&&isAUZRight==1)
        {
            anchor=12;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[12].xyStructuee.sx,auzXY[12].xyStructuee.sy,auzXY[12].xyStructuee.width,auzXY[12].xyStructuee.height,2)==2&&isAUZRight==1)
        {
            anchor=13;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(auzXY[13].xyStructuee.sx,auzXY[13].xyStructuee.sy,auzXY[13].xyStructuee.width,auzXY[13].xyStructuee.height,2)==2&&isAUZRight==1)
        {
            anchor=14;
            state=EN_KEY_DOWN;
        }
				
    if(activity.toucharea(auzXY[14].xyStructuee.sx,auzXY[14].xyStructuee.sy,auzXY[14].xyStructuee.width,auzXY[14].xyStructuee.height,2)==2)
        {
            anchor=15;
            state=EN_KEY_DOWN;
        }
    switch(addsubsatus)
        {
        case ADD:

            if(auzDataTemp.p_one<9&&anchor==2)
                {
                    auzDataTemp.p_one++;
                    component.flashData(&auzXY[1],auzDataTemp.p_one,Blue_100,Black);

                }
            if(auzDataTemp.p_two<9&&anchor==3)
                {
                    auzDataTemp.p_two++;
                    component.flashData(&auzXY[2],auzDataTemp.p_two,Blue_100,Black);
                }
            if(auzDataTemp.p_three<9&&anchor==4)
                {
                    auzDataTemp.p_three++;
                    component.flashData(&auzXY[3],auzDataTemp.p_three,Blue_100,Black);
                }
            if(auzDataTemp.p_four<9&&anchor==5)
                {
                    auzDataTemp.p_four++;
                    component.flashData(&auzXY[4],auzDataTemp.p_four,Blue_100,Black);
                }

            if(auzDataTemp.p_five<9&&anchor==6)
                {
                    auzDataTemp.p_five++;
                    component.flashData(&auzXY[5],auzDataTemp.p_five,Blue_100,Black);
                }
            if(auzDataTemp.p_six<9&&anchor==7)
                {
                    auzDataTemp.p_six++;
                    component.flashData(&auzXY[6],auzDataTemp.p_six,Blue_100,Black);
                }


            if(userData.p_one<9&&anchor==8)
                {
                    userData.p_one++;
                    component.flashData(&auzXY[7],userData.p_one,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_two<9&&anchor==9)
                {
                    userData.p_two++;
                    component.flashData(&auzXY[8],userData.p_two,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_three<9&&anchor==10)
                {
                    userData.p_three++;
                    component.flashData(&auzXY[9],userData.p_three,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_four<9&&anchor==11)
                {
                    userData.p_four++;
                    component.flashData(&auzXY[10],userData.p_four,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }

            if(userData.p_five<9&&anchor==12)
                {
                    userData.p_five++;
                    component.flashData(&auzXY[11],userData.p_five,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_six<9&&anchor==13)
                {
                    userData.p_six++;
                    component.flashData(&auzXY[12],userData.p_six,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(freeTime<100&&anchor==14)
                {
                    freeTime++;
                    component.flashData(&auzXY[13],freeTime,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(freeTime==100&&anchor==14)
                {
                    component.pageButton(auzXY[13].xyStructuee.sx,auzXY[13].xyStructuee.sy,
                                         auzXY[13].xyStructuee.width,auzXY[13].xyStructuee.height,"MAX",Blue_100,White);
                }
            break;
        case SUB:
            if(auzDataTemp.p_one>0&&anchor==2)
                {
                    auzDataTemp.p_one--;
                    component.flashData(&auzXY[1],auzDataTemp.p_one,Blue_100,Black);
                }
            if(auzDataTemp.p_two>0&&anchor==3)
                {
                    auzDataTemp.p_two--;
                    component.flashData(&auzXY[2],auzDataTemp.p_two,Blue_100,Black);
                }
            if(auzDataTemp.p_three>0&&anchor==4)
                {
                    auzDataTemp.p_three--;
                    component.flashData(&auzXY[3],auzDataTemp.p_three,Blue_100,Black);
                }
            if(auzDataTemp.p_four>0&&anchor==5)
                {
                    auzDataTemp.p_four--;
                    component.flashData(&auzXY[4],auzDataTemp.p_four,Blue_100,Black);
                }
            if(auzDataTemp.p_five>0&&anchor==6)
                {
                    auzDataTemp.p_five--;
                    component.flashData(&auzXY[5],auzDataTemp.p_five,Blue_100,Black);
                }
            if(auzDataTemp.p_six>0&&anchor==7)
                {
                    auzDataTemp.p_six--;
                    component.flashData(&auzXY[6],auzDataTemp.p_six,Blue_100,Black);
                }
            if(userData.p_one>0&&anchor==8)
                {
                    userData.p_one--;
                    component.flashData(&auzXY[7],userData.p_one,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_two>0&&anchor==9)
                {
                    userData.p_two--;
                    component.flashData(&auzXY[8],userData.p_two,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_three>0&&anchor==10)
                {
                    userData.p_three--;
                    component.flashData(&auzXY[9],userData.p_three,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_four>0&&anchor==11)
                {
                    userData.p_four--;
                    component.flashData(&auzXY[10],userData.p_four,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_five>0&&anchor==12)
                {
                    userData.p_five--;
                    component.flashData(&auzXY[11],userData.p_five,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            if(userData.p_six>0&&anchor==13)
                {
                    userData.p_six--;
                    component.flashData(&auzXY[12],userData.p_six,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }

            if(freeTime>5&&anchor==14)
                {
                    freeTime--;
                    component.flashData(&auzXY[13],freeTime,Blue_100,Black);
                    is_user_freeTime_DataChange=1;
                }
            break;
        }


    switch(state)
        {
        case TURN_L:
            if(anchor<15)
                flashAUZItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashAUZItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
                    anchor=0;
                }
            else if(anchor==2||anchor==3||anchor==4||anchor==5||anchor==6||anchor==7)
                {
                    flashAUZItem(anchor,lastanchor);
                    lastanchor=anchor;
                    encoderAddSubflag=1;
                }
            else if(anchor==8||anchor==9||anchor==10||anchor==11||anchor==12||anchor==13||anchor==14)
                {
                    flashAUZItem(anchor,lastanchor);
                    lastanchor=anchor;
                    if(isAUZRight==1)//输入正确的AUZ代码之后才可以修改user code和free day
                        encoderAddSubflag=1;
                }
            else if(anchor==15)
                {

                    if(checkAUZData(&auzDataTemp,&auzData)==6)
                        {
                            isAUZRight=1;
                            if(is_user_freeTime_DataChange==0)
                                {
                                    component.pageButton(70,157,80,18,"AUZ CODE CORRECT",Blue,White);
                                    delay_ms(1000);
                                    component.pageButton(70,157,80,18,"AUZ CODE CORRECT",Blue,Blue);
                                }
                        }
                    else
                        {
                            component.pageButton(70,157,80,18,"AUZ CODE ERROR",Blue,White);
                            delay_ms(1000);
                            component.pageButton(70,157,80,18,"AUZ CODE ERROR",Blue,Blue);
                        }
                    if(isAUZRight==1&& is_user_freeTime_DataChange==1)
                        {
                            isAUZRight=0;
                            is_user_freeTime_DataChange=0;
                            saveAUZData();//保存freeTime和user code
                            component.pageButton(70,157,80,18,"SUCCESS",Blue,White);
                            delay_ms(1000);
                            component.pageButton(70,157,80,18,"SUCCESS",Blue,Blue);
                        }

                }
            break;
        }
}

void flashAUZItem(u8 anchor,u8 lastanchor)
{

    switch(anchor)
        {
        case 1:
            component.pageSpinner(10,0,70,30,"AUZ",Blue,Blue_100,DOWN);
            break;


        case 2:
            component.flashData(&auzXY[1],auzDataTemp.p_one,Blue_100,Black);
            break;
        case 3:
            component.flashData(&auzXY[2],auzDataTemp.p_two,Blue_100,Black);
            break;
        case 4:
            component.flashData(&auzXY[3],auzDataTemp.p_three,Blue_100,Black);
            break;
        case 5:
            component.flashData(&auzXY[4],auzDataTemp.p_four,Blue_100,Black);
            break;
        case 6:
            component.flashData(&auzXY[5],auzDataTemp.p_five,Blue_100,Black);
            break;
        case 7:
            component.flashData(&auzXY[6],auzDataTemp.p_six,Blue_100,Black);
            break;


        case 8:
            component.flashData(&auzXY[7],userData.p_one,Blue_100,Black);
            break;
        case 9:
            component.flashData(&auzXY[8],userData.p_two,Blue_100,Black);
            break;
        case 10:
            component.flashData(&auzXY[9],userData.p_three,Blue_100,Black);
            break;
        case 11:
            component.flashData(&auzXY[10],userData.p_four,Blue_100,Black);
            break;
        case 12:
            component.flashData(&auzXY[11],userData.p_five,Blue_100,Black);
            break;
        case 13:
            component.flashData(&auzXY[12],userData.p_six,Blue_100,Black);
            break;

        case 14:
            if(freeTime<100)
                component.flashData(&auzXY[13],freeTime,Blue_100,Black);
            else
                component.pageButton(100-5,110,108,20,"MAX",Blue_100,Black);
            break;

        case 15:
            component.pageButton(175,157,40,18,"OK",Blue_100,White);
            break;
        }
    if(anchor!=lastanchor)
        switch(lastanchor)
            {

            case 1:
                component.pageSpinner(10,0,70,30,"AUZ",Blue,White,DOWN);
                break;


            case 2:
                component.flashData(&auzXY[1],auzDataTemp.p_one,White,Black);
                break;
            case 3:
                component.flashData(&auzXY[2],auzDataTemp.p_two,White,Black);
                break;
            case 4:
                component.flashData(&auzXY[3],auzDataTemp.p_three,White,Black);
                break;
            case 5:
                component.flashData(&auzXY[4],auzDataTemp.p_four,White,Black);
                break;
            case 6:
                component.flashData(&auzXY[5],auzDataTemp.p_five,White,Black);
                break;
            case 7:
                component.flashData(&auzXY[6],auzDataTemp.p_six,White,Black);

                break;


            case 8:
                component.flashData(&auzXY[7],userData.p_one,White,Black);
                break;
            case 9:
                component.flashData(&auzXY[8],userData.p_two,White,Black);
                break;
            case 10:
                component.flashData(&auzXY[9],userData.p_three,White,Black);
                break;
            case 11:
                component.flashData(&auzXY[10],userData.p_four,White,Black);
                break;
            case 12:
                component.flashData(&auzXY[11],userData.p_five,White,Black);
                break;
            case 13:
                component.flashData(&auzXY[12],userData.p_six,White,Black);
                break;

            case 14:
                if(freeTime<100)
                    component.flashData(&auzXY[13],freeTime,White,Black);
                else
                    component.pageButton(100-5,110,108,20,"MAX",White,Black);
                break;

            case 15:
                component.pageButton(175,157,40,18,"OK",Blue,White);
                break;

            }

}

u8 checkAUZData(AUZ_Data* auzDataTemep,AUZ_Data* auzData)
{
    u8 k=0;
    if(auzDataTemep->p_one==auzData->p_one) k++;
    if(auzDataTemep->p_two==auzData->p_two) k++;
    if(auzDataTemep->p_three==auzData->p_three) k++;
    if(auzDataTemep->p_four==auzData->p_four) k++;
    if(auzDataTemep->p_five==auzData->p_five) k++;
    if(auzDataTemep->p_six==auzData->p_six) k++;
    return k;
}
void saveAUZData()
{
//刷写userData和freeTime使用次数
    AT24CXX_Write(221,&freeTime,1);
    AT24CXX_Write(244,&userData.p_one,1);
    AT24CXX_Write(245,&userData.p_two,1);
    AT24CXX_Write(246,&userData.p_three,1);
    AT24CXX_Write(247,&userData.p_four,1);
    AT24CXX_Write(248,&userData.p_five,1);
    AT24CXX_Write(249,&userData.p_six,1);

}
void readAUZData()
{

    AT24CXX_Read(221,&freeTime,1);
    AT24CXX_Read(244,&user_Data.p_one,1);
    AT24CXX_Read(245,&user_Data.p_two,1);
    AT24CXX_Read(246,&user_Data.p_three,1);
    AT24CXX_Read(247,&user_Data.p_four,1);
    AT24CXX_Read(248,&user_Data.p_five,1);
    AT24CXX_Read(249,&user_Data.p_six,1);

}
u8 isFreeDayOver()
{
    AT24CXX_Read(221,&freeTime,1);
    if(freeTime==100) //永久使用
        {
            return 1;
        }
    else if(freeTime==0)
        {
            return 2;
        }
    else
        {
            freeTime--;
            AT24CXX_Write(221,&freeTime,1);
            AT24CXX_Read(221,&freeTime,1);
            return 3;
        }
    return 0;
}

void isUsingOneDay(_calendar_obj* calendar) //放在循环中执行
{
    /*用了一天表示使用了一次*/
    u8  static lasthour=0;
    u8  hour=0;
    if(calendar->hour!=lasthour)
        {
            AT24CXX_Read(232,&hour,1);
            if(hour>23)
                {
                    //标记使用一次
                    if(freeTime>0)
                        freeTime--;
                    AT24CXX_Write(221,&freeTime,1);
                    AT24CXX_Read(221,&freeTime,1);
                }
            else
                {
                    hour++;
                    AT24CXX_Write(232,&hour,1);
                }
            lasthour=calendar->hour;
        }



}