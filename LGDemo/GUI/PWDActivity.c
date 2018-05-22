#include "PWDActivity.h"


Rectangle pwdXY[10];
pwd_data pwdData= {1,2,3,4};
pwd_data rawPwdData= {1,3,0,0};
pwd_data oldPwdDataTemp= {0,0,0,0};
pwd_data newPwdDataTemp= {0,0,0,0};
PWDActivity pwdActivity= {pwdActivityPage,pwdActivityItemSelect,savePwdData,readPwdData,checkPwd,&pwdData};
void pwdActivityPage()
{
    if(activity.activeActivity==activity.PWD)
        {
            component.titleBar();

            pwdXY[0].xyStructuee=component.pageSpinner(10,0,70,30,"PWD",Blue,White,DOWN);
            component.pageButton(40,65,60,20,"OLD PWD",Blue_200,White);
            component.pageButton(40,90,60,20,"NEW PWD",Blue_200,White);

            pwdXY[1].xyStructuee=component.pageEditText(100,65,20,20,oldPwdDataTemp.p_one,White,Black);
            pwdXY[2].xyStructuee=component.pageEditText(120,65,20,20,oldPwdDataTemp.p_two,White,Black);
            pwdXY[3].xyStructuee=component.pageEditText(140,65,20,20,oldPwdDataTemp.p_three,White,Black);
            pwdXY[4].xyStructuee=component.pageEditText(160,65,20,20,oldPwdDataTemp.p_four,White,Black);

            pwdXY[5].xyStructuee=component.pageEditText(100,90,20,20,newPwdDataTemp.p_one,White,Black);
            pwdXY[6].xyStructuee=component.pageEditText(120,90,20,20,newPwdDataTemp.p_two,White,Black);
            pwdXY[7].xyStructuee=component.pageEditText(140,90,20,20,newPwdDataTemp.p_three,White,Black);
            pwdXY[8].xyStructuee=component.pageEditText(160,90,20,20,newPwdDataTemp.p_four,White,Black);
					  component.clear(0,157,220,18,Blue);
            pwdXY[9].xyStructuee=component.pageButton(175,157,40,18,"OK",Blue,White);
            pwdActivityAction();

        }
}

void pwdActivityAction()
{

    while(activity.activeActivity==activity.PWD)
        {
            activity.flashTime();
            pwdActivityItemSelect();

        }

}
void pwdActivityItemSelect()
{

    u8 state=encoder();
    u8 static anchor=0;
    u8 static encoderAddSubflag=0;
    u8 static lastanchor=0;

    u8 addsubsatus=activity.encoderToAddSub(&encoderAddSubflag,&state);
    if(encoderAddSubflag)
        state=0;

    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }

		 if(activity.toucharea(pwdXY[1].xyStructuee.sx,pwdXY[1].xyStructuee.sy,pwdXY[1].xyStructuee.width,pwdXY[1].xyStructuee.height,2)==2)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
		 if(activity.toucharea(pwdXY[2].xyStructuee.sx,pwdXY[2].xyStructuee.sy,pwdXY[2].xyStructuee.width,pwdXY[2].xyStructuee.height,2)==2)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(pwdXY[3].xyStructuee.sx,pwdXY[3].xyStructuee.sy,pwdXY[3].xyStructuee.width,pwdXY[3].xyStructuee.height,2)==2)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(pwdXY[4].xyStructuee.sx,pwdXY[4].xyStructuee.sy,pwdXY[4].xyStructuee.width,pwdXY[4].xyStructuee.height,2)==2)
        {
            anchor=5;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(pwdXY[5].xyStructuee.sx,pwdXY[5].xyStructuee.sy,pwdXY[5].xyStructuee.width,pwdXY[5].xyStructuee.height,2)==2)
        {
            anchor=6;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(pwdXY[6].xyStructuee.sx,pwdXY[6].xyStructuee.sy,pwdXY[6].xyStructuee.width,pwdXY[6].xyStructuee.height,2)==2)
        {
            anchor=7;
            state=EN_KEY_DOWN;
        }
			if(activity.toucharea(pwdXY[7].xyStructuee.sx,pwdXY[7].xyStructuee.sy,pwdXY[7].xyStructuee.width,pwdXY[7].xyStructuee.height,2)==2)
        {
            anchor=8;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(pwdXY[8].xyStructuee.sx,pwdXY[8].xyStructuee.sy,pwdXY[8].xyStructuee.width,pwdXY[8].xyStructuee.height,2)==2)
        {
            anchor=9;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(pwdXY[9].xyStructuee.sx,pwdXY[9].xyStructuee.sy,pwdXY[9].xyStructuee.width,pwdXY[9].xyStructuee.height,2)==2)
        {
            anchor=10;
            state=EN_KEY_DOWN;
        }	
    switch(addsubsatus)
        {
        case ADD:
            if(oldPwdDataTemp.p_one<9&&anchor==2)
                {
                    oldPwdDataTemp.p_one++;
                    component.flashData(&pwdXY[1],oldPwdDataTemp.p_one,Blue_100,Black);
                }
            if(oldPwdDataTemp.p_two<9&&anchor==3)
                {
                    oldPwdDataTemp.p_two++;
                    component.flashData(&pwdXY[2],oldPwdDataTemp.p_two,Blue_100,Black);
                }
            if(oldPwdDataTemp.p_three<9&&anchor==4)
                {
                    oldPwdDataTemp.p_three++;
                    component.flashData(&pwdXY[3],oldPwdDataTemp.p_three,Blue_100,Black);
                }
            if(oldPwdDataTemp.p_four<9&&anchor==5)
                {
                    oldPwdDataTemp.p_four++;
                    component.flashData(&pwdXY[4],oldPwdDataTemp.p_four,Blue_100,Black);
                }


            if(newPwdDataTemp.p_one<9&&anchor==6)
                {
                    newPwdDataTemp.p_one++;
                    component.flashData(&pwdXY[5],newPwdDataTemp.p_one,Blue_100,Black);
                }
            if(newPwdDataTemp.p_two<9&&anchor==7)
                {
                    newPwdDataTemp.p_two++;
                    component.flashData(&pwdXY[6],newPwdDataTemp.p_two,Blue_100,Black);
                }
            if(newPwdDataTemp.p_three<9&&anchor==8)
                {
                    newPwdDataTemp.p_three++;
                    component.flashData(&pwdXY[7],newPwdDataTemp.p_three,Blue_100,Black);
                }
            if(newPwdDataTemp.p_four<9&&anchor==9)
                {
                    newPwdDataTemp.p_four++;
                    component.flashData(&pwdXY[8],newPwdDataTemp.p_four,Blue_100,Black);
                }
            break;
        case SUB:
            if(oldPwdDataTemp.p_one>0&&anchor==2)
                {
                    oldPwdDataTemp.p_one--;
                    component.flashData(&pwdXY[1],oldPwdDataTemp.p_one,Blue_100,Black);
                }
            if(oldPwdDataTemp.p_two>0&&anchor==3)
                {
                    oldPwdDataTemp.p_two--;
                    component.flashData(&pwdXY[2],oldPwdDataTemp.p_two,Blue_100,Black);
                }
            if(oldPwdDataTemp.p_three>0&&anchor==4)
                {
                    oldPwdDataTemp.p_three--;
                    component.flashData(&pwdXY[3],oldPwdDataTemp.p_three,Blue_100,Black);
                }
            if(oldPwdDataTemp.p_four>0&&anchor==5)
                {
                    oldPwdDataTemp.p_four--;
                    component.flashData(&pwdXY[4],oldPwdDataTemp.p_four,Blue_100,Black);
                }




            if(newPwdDataTemp.p_one>0&&anchor==6)
                {
                    newPwdDataTemp.p_one--;
                    component.flashData(&pwdXY[5],newPwdDataTemp.p_one,Blue_100,Black);
                }
            if(newPwdDataTemp.p_two>0&&anchor==7)
                {
                    newPwdDataTemp.p_two--;
                    component.flashData(&pwdXY[6],newPwdDataTemp.p_two,Blue_100,Black);
                }
            if(newPwdDataTemp.p_three>0&&anchor==8)
                {
                    newPwdDataTemp.p_three--;
                    component.flashData(&pwdXY[7],newPwdDataTemp.p_three,Blue_100,Black);
                }
            if(newPwdDataTemp.p_four>0&&anchor==9)
                {
                    newPwdDataTemp.p_four--;
                    component.flashData(&pwdXY[8],newPwdDataTemp.p_four,Blue_100,Black);
                }
            break;
        }

    switch(state)
        {
        case TURN_L:
            if(anchor<10)
                flashPwdItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashPwdItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
                    encoderAddSubflag=0;
                    anchor=0;
                }
            else if(anchor==2||anchor==3||anchor==4||anchor==5||anchor==6|anchor==7||anchor==8||anchor==9)
                {
                    encoderAddSubflag=1;
                    flashPwdItem(anchor,lastanchor);
                    lastanchor=anchor;
                }
            else if(anchor==10)
                {
									  encoderAddSubflag=0;
                    
									  if(checkPwd(&oldPwdDataTemp,&pwdData)==4||checkPwd(&oldPwdDataTemp,&rawPwdData)==4){
										anchor=0;
										component.pageButton(70,157,80,18,"SUCCESS",Blue,White);
										delay_ms(1000);	
										component.pageButton(70,157,80,18,"SUCCESS",Blue,Blue);
										pwdData=newPwdDataTemp;		
										savePwdData();//±£´æÃÜÂë	
										activity.activeActivity=activity.HOME;
										}else{
											
										component.pageButton(70,157,80,18,"PWD ERROR",Blue,White);
										delay_ms(1000);	
										component.pageButton(70,157,80,18,"PWD ERROR",Blue,Blue);								
										}
                    
                }
             
            break;
        }
}
void flashPwdItem(u8 anchor,u8 lastanchor)
{
    switch(anchor)
        {
        case 1:
            component.pageSpinner(10,0,70,30,"PWD",Blue,Blue_100,DOWN);
            break;
        case 2:
            component.flashData(&pwdXY[1],oldPwdDataTemp.p_one,Blue_100,Black);
            break;
        case 3:
            component.flashData(&pwdXY[2],oldPwdDataTemp.p_two,Blue_100,Black);
            break;
        case 4:
            component.flashData(&pwdXY[3],oldPwdDataTemp.p_three,Blue_100,Black);
            break;
        case 5:
            component.flashData(&pwdXY[4],oldPwdDataTemp.p_four,Blue_100,Black);
            break;
        case 6:
            component.flashData(&pwdXY[5],newPwdDataTemp.p_one,Blue_100,Black);
            break;
        case 7:
            component.flashData(&pwdXY[6],newPwdDataTemp.p_two,Blue_100,Black);
            break;
        case 8:
            component.flashData(&pwdXY[7],newPwdDataTemp.p_three,Blue_100,Black);
            break;
        case 9:
            component.flashData(&pwdXY[8],newPwdDataTemp.p_four,Blue_100,Black);
            break;
        case 10:
            component.pageButton(175,157,40,18,"OK",Blue_100,White);
            break;

        }
    if(anchor!=lastanchor)
        switch(lastanchor)
            {
            case 1:
                component.pageSpinner(10,0,70,30,"PWD",Blue,White,DOWN);
                break;
            case 2:
                component.flashData(&pwdXY[1],oldPwdDataTemp.p_one,White,Black);
                break;
            case 3:
                component.flashData(&pwdXY[2],oldPwdDataTemp.p_two,White,Black);
                break;
            case 4:
                component.flashData(&pwdXY[3],oldPwdDataTemp.p_three,White,Black);
                break;
            case 5:
                component.flashData(&pwdXY[4],oldPwdDataTemp.p_four,White,Black);
                break;
            case 6:
                component.flashData(&pwdXY[5],newPwdDataTemp.p_one,White,Black);
                break;
            case 7:
                component.flashData(&pwdXY[6],newPwdDataTemp.p_two,White,Black);
                break;
            case 8:
                component.flashData(&pwdXY[7],newPwdDataTemp.p_three,White,Black);
                break;
            case 9:
                component.flashData(&pwdXY[8],newPwdDataTemp.p_four,White,Black);
                break;
            case 10:
                component.pageButton(175,157,40,18,"OK",Blue,White);
                break;
            }
}

u8 checkPwd(pwd_data* data,pwd_data* pwddata){
	
	u8 ok=0;
  if(data->p_one==pwddata->p_one) ok++;
	if(data->p_two==pwddata->p_two) ok++;
	if(data->p_three==pwddata->p_three) ok++;
	if(data->p_four==pwddata->p_four) ok++;
	
  return ok;
	
	
}
void savePwdData(){

            AT24CXX_Write(38,&pwdData.p_one,1);
            AT24CXX_Write(39,&pwdData.p_two,1);
            AT24CXX_Write(40,&pwdData.p_three,1);
            AT24CXX_Write(41,&pwdData.p_four,1);
}
void readPwdData(){
	
            AT24CXX_Read(38,&pwdData.p_one,1);
            AT24CXX_Read(39,&pwdData.p_two,1);
            AT24CXX_Read(40,&pwdData.p_three,1);
            AT24CXX_Read(41,&pwdData.p_four,1);
	
}
