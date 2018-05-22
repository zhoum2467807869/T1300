#include "TimeActivity.h"
TimeActivity timeActivity= {timeActivityPage,timeActivityItemSelect};
_calendar_obj tempCalender;
Rectangle timeXY[8];
void timeActivityPage()
{

    if(activity.activeActivity==activity.TIME)
        {
            tempCalender=calendar;
            component.titleBar();
            timeXY[0].xyStructuee=component.pageSpinner(10,0,70,30,"TIME",Blue,White,DOWN);
            component.pageButton(5,65,40,20,"YEAR",Blue_200,White);
            component.pageButton(5,90,40,20,"DAY",Blue_200,White);
            component.pageButton(5,115,40,20,"MIN",Blue_200,White);

            timeXY[1].xyStructuee=component.pageEditText(45,65,60,20,tempCalender.w_year,White,Black);
            timeXY[2].xyStructuee=component.pageEditText(45,90,60,20,tempCalender.w_date,White,Black);
            timeXY[3].xyStructuee=component.pageEditText(45,115,60,20,tempCalender.min,White,Black);

            component.pageButton(115,65,40,20,"MON",Blue_200,White);
            component.pageButton(115,90,40,20,"HOUR",Blue_200,White);
            component.pageButton(115,115,40,20,"SEC",Blue_200,White);

            timeXY[4].xyStructuee=component.pageEditText(155,65,60,20,tempCalender.w_month,White,Black);
            timeXY[5].xyStructuee=component.pageEditText(155,90,60,20,tempCalender.hour,White,Black);
            timeXY[6].xyStructuee=component.pageEditText(155,115,60,20,tempCalender.sec,White,Black);
            component.clear(0,157,220,18,Blue);
            timeXY[7].xyStructuee=component.pageButton(170,157,40,18,"SAVE",Blue,White);
            timeActivityAction();
        }
}

void timeActivityAction()
{

    while(activity.activeActivity==activity.TIME)
        {
            activity.flashTime();
            timeActivityItemSelect();

        }

}
void timeActivityItemSelect()
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
		if(activity.toucharea(timeXY[1].xyStructuee.sx,timeXY[1].xyStructuee.sy,
			timeXY[1].xyStructuee.width,timeXY[1].xyStructuee.height,2)==2)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(timeXY[2].xyStructuee.sx,timeXY[2].xyStructuee.sy,
			timeXY[2].xyStructuee.width,timeXY[2].xyStructuee.height,3)==3)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(timeXY[3].xyStructuee.sx,timeXY[3].xyStructuee.sy,
			timeXY[3].xyStructuee.width,timeXY[3].xyStructuee.height,4)==4)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(timeXY[4].xyStructuee.sx,timeXY[4].xyStructuee.sy,
			timeXY[4].xyStructuee.width,timeXY[4].xyStructuee.height,5)==5)
        {
            anchor=5;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(timeXY[5].xyStructuee.sx,timeXY[5].xyStructuee.sy,
			timeXY[5].xyStructuee.width,timeXY[5].xyStructuee.height,6)==6)
        {
            anchor=6;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(timeXY[6].xyStructuee.sx,timeXY[6].xyStructuee.sy,
			timeXY[6].xyStructuee.width,timeXY[6].xyStructuee.height,7)==7)
        {
            anchor=7;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(timeXY[7].xyStructuee.sx,timeXY[7].xyStructuee.sy,
			timeXY[7].xyStructuee.width,timeXY[7].xyStructuee.height,8)==8)
        {
            anchor=8;
            state=EN_KEY_DOWN;
        }
    switch(addsubsatus)
        {
        case ADD:
            if(anchor==2)
                {
                  if(tempCalender.w_year<2099){
									tempCalender.w_year++;
									} 
									
                }
            if(anchor==3)
                {
                  if(tempCalender.w_date<31)
										tempCalender.w_date++;
									
                }
            if(anchor==4)
                {
                      if(tempCalender.min<59){
											tempCalender.min++;
											}
                }
						if(anchor==5)
                {
                   if(tempCalender.w_month<12)
										 tempCalender.w_month++;
                }
            if(anchor==6)
                {
                    if(tempCalender.hour<23)
									  tempCalender.hour++;
                }
            if(anchor==7)
                {
                    if(tempCalender.sec<59)
	                   tempCalender.sec++;
                }
            flashTimeItem(anchor,lastanchor);
            lastanchor=anchor;
            break;
        case SUB:
       if(anchor==2)
                {
                  if(tempCalender.w_year>2018){
									tempCalender.w_year--;
									} 
									
                }
            if(anchor==3)
                {
                  if(tempCalender.w_date>1)
										tempCalender.w_date--;
									
                }
            if(anchor==4)
                {
                      if(tempCalender.min>0){
											tempCalender.min--;
											}
                }
						if(anchor==5)
                {
                   if(tempCalender.w_month>1)
										 tempCalender.w_month--;
                }
            if(anchor==6)
                {
                    if(tempCalender.hour>0)
									  tempCalender.hour--;
                }
            if(anchor==7)
                {
                    if(tempCalender.sec>0)
	                   tempCalender.sec--;
                }
            flashTimeItem(anchor,lastanchor);
            lastanchor=anchor;
            break;
        }
    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    switch(state)
        {
        case TURN_L:
            if(anchor<8)
               flashTimeItem(++anchor,lastanchor);
                lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashTimeItem(--anchor,lastanchor);
                lastanchor=anchor;
                
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
									  encoderAddSubflag=0;
                    anchor=0;
                }
            else if(anchor==2||anchor==3||anchor==4||anchor==5||anchor==6||anchor==7)
                {
                    encoderAddSubflag=1;
									  flashTimeItem(anchor,lastanchor);
                    lastanchor=anchor;								
                }
								else if(anchor==8){	
									encoderAddSubflag=0;
								 component.pageButton(70,157,60,18,"SUCCESS",Blue,White);
									  delay_ms(1000);
								component.pageButton(70,157,60,18,"SUCCESS",Blue,Blue);
                 RTC_Set(tempCalender.w_year,tempCalender.w_month,tempCalender.w_date,tempCalender.hour,tempCalender.min,tempCalender.sec);									
								}
            break;
        }


}
void flashTimeItem(u8 anchor,u8 lastanchor)
{
    switch(anchor)
        {
        case 1:
            component.pageSpinner(10,0,70,30,"TIME",Blue,Blue_100,DOWN);
            break;
        case 2:
            component.flashData(&timeXY[1],tempCalender.w_year,Blue_100,Black);
            break;
        case 3:
            component.flashData(&timeXY[2],tempCalender.w_date,Blue_100,Black);
            break;
        case 4:
            component.flashData(&timeXY[3],tempCalender.min,Blue_100,Black);
            break;
        case 5:
            component.flashData(&timeXY[4],tempCalender.w_month,Blue_100,Black);
            break;
        case 6:
            component.flashData(&timeXY[5],tempCalender.hour,Blue_100,Black);
            break;
        case 7:
            component.flashData(&timeXY[6],tempCalender.sec,Blue_100,Black);
            break;
        case 8:
            component.flashChar(&timeXY[7],"SAVE",Blue_100,White);
            break;
        }
    if(anchor!=lastanchor)
        {
            switch(lastanchor)
                {
                case 1:
                    component.pageSpinner(10,0,70,30,"TIME",Blue,White,DOWN);
                    break;
                case 2:
                    component.flashData(&timeXY[1],tempCalender.w_year,White,Black);
                    break;
                case 3:
                    component.flashData(&timeXY[2],tempCalender.w_date,White,Black);
                    break;
                case 4:
                    component.flashData(&timeXY[3],tempCalender.min,White,Black);
                    break;
                case 5:
                    component.flashData(&timeXY[4],tempCalender.w_month,White,Black);
                    break;
                case 6:
                    component.flashData(&timeXY[5],tempCalender.hour,White,Black);
                    break;
                case 7:
                    component.flashData(&timeXY[6],tempCalender.sec,White,Black);
                    break;
                case 8:
                    component.flashChar(&timeXY[7],"SAVE",Blue,White);
                    break;
                }
        }

}
