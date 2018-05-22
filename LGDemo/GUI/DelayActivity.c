#include "DelayActivity.h"

Rectangle rectangle[6];
char* subitemName[] = {"OPEN1/2","OPEN2/2","CLOSE1/2","CLOSE2/2"};
_chan_open_data  chan_open_data= {1,2,3,4,5,6,7,8,};
_chan_close_data  chan_close_data= {8,7,6,5,4,3,2,1,};
_chan_data chan_data;
DelayActivity delayActivity= {1,delayPage,0,saveDelayData,readDelayData,&chan_open_data,&chan_close_data};
Rectangle* spinnerxy;
void delayPage()
{

    if(activity.activeActivity==activity.DELAY)
        {
            assignVal(delayActivity.subPageNum);
            component.titleBar();
            component.pageSpinner(10,0,70,30,"DELAY",Blue,White,DOWN);
            flashSubPage(delayActivity.subPageNum);
        }
    delayActivityAction();

}
void delayActivityAction()
{
    u8 pagenumber=1;
    while(activity.activeActivity==activity.DELAY)
        {

            if(delayActivity.isShowSpinner==0)
                delatPageSelectItem();
            if(delayActivity.isShowSpinner==1)
                delaySpinnerItemSelect();
        }


}
void delaySpinnerItemSelect()
{
    u8 state=encoder();
    u8 static anchor=0;
    u8 static lastanchor=0;
    if(activity.toucharea(spinnerxy[0].xyStructuee.sx,spinnerxy[0].xyStructuee.sy,spinnerxy[0].xyStructuee.width,spinnerxy[0].xyStructuee.height,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(spinnerxy[1].xyStructuee.sx,spinnerxy[1].xyStructuee.sy,spinnerxy[1].xyStructuee.width,spinnerxy[1].xyStructuee.height,2)==2)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(spinnerxy[2].xyStructuee.sx,spinnerxy[2].xyStructuee.sy,spinnerxy[2].xyStructuee.width,spinnerxy[2].xyStructuee.height,2)==2)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(spinnerxy[3].xyStructuee.sx,spinnerxy[3].xyStructuee.sy,spinnerxy[3].xyStructuee.width,spinnerxy[3].xyStructuee.height,2)==2)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
    switch(state)
        {
        case TURN_L:
            if(anchor<4)
                flashDelaySpinnerItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashDelaySpinnerItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            switch(anchor)
                {
                case 1:
                    delayActivity.subPageNum=1;
                    delayActivity.isShowSpinner=0;

                    break;
                case 2:
                    delayActivity.subPageNum=2;
                    delayActivity.isShowSpinner=0;
                    break;
                case 3:
                    delayActivity.subPageNum=3;
                    delayActivity.isShowSpinner=0;
                    break;
                case 4:
                    delayActivity.subPageNum=4;
                    delayActivity.isShowSpinner=0;
                    break;
                }
            assignVal(delayActivity.subPageNum);
            flashSubPage(delayActivity.subPageNum);
            break;
        }

}

void flashDelaySpinnerItem(u8 anchor,u8 lastanchor)
{

    switch(anchor)
        {
        case 1:
            SpinnerActivity.showItem(130,33,90,20,subitemName,0,Blue_100);
            break;
        case 2:
            SpinnerActivity.showItem(130,33,90,20,subitemName,1,Blue_100);
            break;
        case 3:
            SpinnerActivity.showItem(130,33,90,20,subitemName,2,Blue_100);
            break;
        case 4:
            SpinnerActivity.showItem(130,33,90,20,subitemName,3,Blue_100);
            break;
        }
    if(anchor!=lastanchor)
        switch(lastanchor)
            {
            case 1:
                SpinnerActivity.showItem(130,33,90,20,subitemName,0,Blue_50);
                break;
            case 2:
                SpinnerActivity.showItem(130,33,90,20,subitemName,1,Blue_50);
                break;
            case 3:
                SpinnerActivity.showItem(130,33,90,20,subitemName,2,Blue_50);
                break;
            case 4:
                SpinnerActivity.showItem(130,33,90,20,subitemName,3,Blue_50);
                break;
            }


}


void delatPageSelectItem()
{
    u8 state=encoder();
    u8 static anchor=0;/*界面上的锚点，每一个锚点代表一个控件*/
    u8 static encoderAddSubflag=0;/*编码器进入数值更改模式标志位*/
    u8 static lastanchor=0;/*记录上一个锚点*/
	  /*加减器点击事件*/
    u8 screenaddsubsatus_1=activity.scanAddSubstruct(rectangle[0].xyStructuee.sx,rectangle[0].xyStructuee.sy,rectangle[0].xyStructuee.width,rectangle[0].xyStructuee.height);
    u8 screenaddsubsatus_2=activity.scanAddSubstruct(rectangle[1].xyStructuee.sx,rectangle[1].xyStructuee.sy,rectangle[1].xyStructuee.width,rectangle[1].xyStructuee.height);
    u8 screenaddsubsatus_3=activity.scanAddSubstruct(rectangle[2].xyStructuee.sx,rectangle[2].xyStructuee.sy,rectangle[2].xyStructuee.width,rectangle[2].xyStructuee.height);
    u8 screenaddsubsatus_4=activity.scanAddSubstruct(rectangle[3].xyStructuee.sx,rectangle[3].xyStructuee.sy,rectangle[3].xyStructuee.width,rectangle[3].xyStructuee.height);
	
    u8 addsubsatus=activity.encoderToAddSub(&encoderAddSubflag,&state);


    if(encoderAddSubflag)
        state=0;

    if(screenaddsubsatus_1==ADD||screenaddsubsatus_1==SUB)anchor=3;
    if(screenaddsubsatus_2==ADD||screenaddsubsatus_2==SUB)anchor=4;
    if(screenaddsubsatus_3==ADD||screenaddsubsatus_3==SUB)anchor=5;
    if(screenaddsubsatus_4==ADD||screenaddsubsatus_4==SUB)anchor=6;

    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(rectangle[5].xyStructuee.sx,rectangle[5].xyStructuee.sy,rectangle[5].xyStructuee.width,rectangle[5].xyStructuee.height,2)==2)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
		 if(activity.toucharea(rectangle[0].xyStructuee.sx,rectangle[0].xyStructuee.sy,rectangle[0].xyStructuee.width,rectangle[0].xyStructuee.height,2)==2)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
		 if(activity.toucharea(rectangle[1].xyStructuee.sx,rectangle[1].xyStructuee.sy,rectangle[1].xyStructuee.width,rectangle[1].xyStructuee.height,2)==2)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
		 if(activity.toucharea(rectangle[2].xyStructuee.sx,rectangle[2].xyStructuee.sy,rectangle[2].xyStructuee.width,rectangle[2].xyStructuee.height,2)==2)
        {
            anchor=5;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(rectangle[3].xyStructuee.sx,rectangle[3].xyStructuee.sy,rectangle[3].xyStructuee.width,rectangle[3].xyStructuee.height,2)==2)
        {
            anchor=6;
            state=EN_KEY_DOWN;
        }
		if(activity.toucharea(rectangle[4].xyStructuee.sx,rectangle[4].xyStructuee.sy,rectangle[4].xyStructuee.width,rectangle[4].xyStructuee.height,2)==2)
        {
            anchor=7;
            state=EN_KEY_DOWN;
        }
    switch(addsubsatus|screenaddsubsatus_1|screenaddsubsatus_2|screenaddsubsatus_3|screenaddsubsatus_4)
        {
        case ADD:

            if((addsubsatus==ADD&&anchor==3)||screenaddsubsatus_1==ADD)
                {

                    if(chan_data.data1<127)
                        chan_data.data1++;
                }

            if((addsubsatus==ADD&&anchor==4)||screenaddsubsatus_2==ADD)
                {

                    if(chan_data.data2<127)
                        chan_data.data2++;
                }

            if((addsubsatus==ADD&&anchor==5)||screenaddsubsatus_3==ADD)
                {

                    if(chan_data.data3<127)
                        chan_data.data3++;
                }
            if((addsubsatus==ADD&&anchor==6)||screenaddsubsatus_4==ADD)
                {
                    if(chan_data.data4<127)
                        chan_data.data4++;
                }
            flashItem(anchor,lastanchor);
            lastanchor=anchor;
            break;
        case SUB:

            if((addsubsatus==SUB&&anchor==3)||screenaddsubsatus_1==SUB)
                {
                    if(chan_data.data1>1)
                        chan_data.data1--;
                }

            if((addsubsatus==SUB&&anchor==4)||screenaddsubsatus_2==SUB)
                {
                    if(chan_data.data2>1)
                        chan_data.data2--;
                }
            if((addsubsatus==SUB&&anchor==5)||screenaddsubsatus_3==SUB)
                {
                    if(chan_data.data3>1)
                        chan_data.data3--;
                }
            if((addsubsatus==SUB&&anchor==6)||screenaddsubsatus_4==SUB)
                {
                    if(chan_data.data4>1)
                        chan_data.data4--;
                }
            flashItem(anchor,lastanchor);
            lastanchor=anchor;
            break;
        }

    switch(state)
        {
        case TURN_L:
            if(anchor<7)
                flashItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
                    encoderAddSubflag=0;
                    anchor=0;
                }
            if(anchor==3||anchor==4||anchor==5||anchor==6) {
									flashItem(anchor,lastanchor);
                 lastanchor=anchor;
							encoderAddSubflag=1;
						}
            if(anchor==2)
                {
                    encoderAddSubflag=0;
                    spinnerxy=component.pageSpinnerItem(130,33,90,20,subitemName,4);//显示delaySPinner
                    delayActivity.isShowSpinner=1;
                    anchor=0;
                }
            if(anchor==7)
                {
									  encoderAddSubflag=0;
                    saveDelayData(delayActivity.subPageNum);
									  component.pageButton(70,157,60,18,"SUCCESS",Blue,White);
									  delay_ms(1000);
									  component.pageButton(70,157,60,18,"SUCCESS",Blue,Blue);
                   
                }
						
            break;
        }
}
void flashSubPage(u8 pageNum)
{

    if(pageNum==1||pageNum==3)
        {

            if(delayActivity.subPageNum==1)
                {
                    rectangle[5].xyStructuee=component.pageSpinner(130,0,80,30,"OPEN1/2",Blue,White,DOWN);
                }
            if(delayActivity.subPageNum==3)
                {
                    rectangle[5].xyStructuee=component.pageSpinner(130,0,80,30,"ClOSE1/2",Blue,White,DOWN);
                }
            component.clearPage();
            rectangle[0].xyStructuee=component.virticleadderSubtracter(5,50,20,50,20,20,"CH1",chan_data.data1);
            rectangle[1].xyStructuee=component.virticleadderSubtracter(115,50,20,50,20,20,"CH2",chan_data.data2);
            rectangle[2].xyStructuee=virticleadderSubtracter(5,90,20,50,20,20,"CH3",chan_data.data3);
            rectangle[3].xyStructuee=component.virticleadderSubtracter(115,90,20,50,20,20,"CH4",chan_data.data4);
								component.clear(0,157,220,18,Blue);
            rectangle[4].xyStructuee=component.pageButton(170,157,40,18,"SAVE",Blue,White);
        }
    else if(pageNum==2||pageNum==4)
        {

            if(delayActivity.subPageNum==2)
                {
                    rectangle[5].xyStructuee=component.pageSpinner(130,0,80,30,"OPEN2/2",Blue,White,DOWN);
                }
            if(delayActivity.subPageNum==4)
                {
                    rectangle[5].xyStructuee=component.pageSpinner(130,0,80,30,"CLOSE2/2",Blue,White,DOWN);
                }
            component.clearPage();
            rectangle[0].xyStructuee=component.virticleadderSubtracter(5,50,20,50,20,20,"CH5",chan_data.data1);
            rectangle[1].xyStructuee=component.virticleadderSubtracter(115,50,20,50,20,20,"CH6",chan_data.data2);
            rectangle[2].xyStructuee=virticleadderSubtracter(5,90,20,50,20,20,"CH7",chan_data.data3);
            rectangle[3].xyStructuee=component.virticleadderSubtracter(115,90,20,50,20,20,"CH8",chan_data.data4);
            		component.clear(0,157,220,18,Blue);
            rectangle[4].xyStructuee=component.pageButton(170,157,40,18,"SAVE",Blue,White);
        }

}
void flashItem(u8 anchor,u8 lastanchor)
{
    switch(anchor)
        {
        case 1:
            component.pageSpinner(10,0,70,30,"DELAY",Blue,Blue_100,DOWN);
            break;
        case 2:
            if(delayActivity.subPageNum==1)
                component.pageSpinner(130,0,80,30,"OPEN1/2",Blue,Blue_100,DOWN);
            if(delayActivity.subPageNum==2)
                component.pageSpinner(130,0,80,30,"OPEN2/2",Blue,Blue_100,DOWN);
            if(delayActivity.subPageNum==3)
                component.pageSpinner(130,0,80,30,"ClOSE1/2",Blue,Blue_100,DOWN);
            if(delayActivity.subPageNum==4)
                component.pageSpinner(130,0,80,30,"CLOSE2/2",Blue,Blue_100,DOWN);
            break;
        case 3:
            component.flashData(&rectangle[0],chan_data.data1,Blue_100,Black);
            break;
        case 4:
            component.flashData(&rectangle[1],chan_data.data2,Blue_100,Black);
            break;
        case 5:
            component.flashData(&rectangle[2],chan_data.data3,Blue_100,Black);
            break;
        case 6:
            component.flashData(&rectangle[3],chan_data.data4,Blue_100,Black);
            break;
        case 7:
            component.flashChar(&rectangle[4],"SAVE",Blue_100,White);
            break;
        }
    if(anchor!=lastanchor)
        switch(lastanchor)
            {
            case 1:
                component.pageSpinner(10,0,70,30,"DELAY",Blue,White,DOWN);
                break;
            case 2:
                if(delayActivity.subPageNum==1)
                    component.pageSpinner(130,0,80,30,"OPEN1/2",Blue,White,DOWN);
                if(delayActivity.subPageNum==2)
                    component.pageSpinner(130,0,80,30,"OPEN2/2",Blue,White,DOWN);
                if(delayActivity.subPageNum==3)
                    component.pageSpinner(130,0,80,30,"ClOSE1/2",Blue,White,DOWN);
                if(delayActivity.subPageNum==4)
                    component.pageSpinner(130,0,80,30,"CLOSE2/2",Blue,White,DOWN);
                break;
            case 3:
                component.flashData(&rectangle[0],chan_data.data1,White,Black);
                break;
            case 4:
                component.flashData(&rectangle[1],chan_data.data2,White,Black);
                break;
            case 5:
                component.flashData(&rectangle[2],chan_data.data3,White,Black);
                break;
            case 6:
                component.flashData(&rectangle[3],chan_data.data4,White,Black);
                break;
            case 7:
                component.flashChar(&rectangle[4],"SAVE",Blue,White);
                break;
            }

}
void assignVal(u8 pageNum)
{
    /*根据不同的子页面赋值中间变量用于刷新数据*/
    switch(pageNum)
        {
        case 1:
            chan_data.data1=chan_open_data.chan1;
            chan_data.data2=chan_open_data.chan2;
            chan_data.data3=chan_open_data.chan3;
            chan_data.data4=chan_open_data.chan4;
            break;
        case 2:
            chan_data.data1=chan_open_data.chan5;
            chan_data.data2=chan_open_data.chan6;
            chan_data.data3=chan_open_data.chan7;
            chan_data.data4=chan_open_data.chan8;
            break;
        case 3:
            chan_data.data1=chan_close_data.chan1;
            chan_data.data2=chan_close_data.chan2;
            chan_data.data3=chan_close_data.chan3;
            chan_data.data4=chan_close_data.chan4;
            break;
        case 4:
            chan_data.data1=chan_close_data.chan5;
            chan_data.data2=chan_close_data.chan6;
            chan_data.data3=chan_close_data.chan7;
            chan_data.data4=chan_close_data.chan8;
            break;
        }
}

void readDelayData()
{

    AT24CXX_Read(22,&chan_open_data.chan1,1);
    AT24CXX_Read(23,&chan_open_data.chan2,1);
    AT24CXX_Read(24,&chan_open_data.chan3,1);
    AT24CXX_Read(25,&chan_open_data.chan4,1);
    AT24CXX_Read(26,&chan_open_data.chan5,1);
    AT24CXX_Read(27,&chan_open_data.chan6,1);
    AT24CXX_Read(28,&chan_open_data.chan7,1);
    AT24CXX_Read(29,&chan_open_data.chan8,1);

    /*关延时数据*/
    AT24CXX_Read(30,&chan_close_data.chan1,1);
    AT24CXX_Read(31,&chan_close_data.chan2,1);
    AT24CXX_Read(32,&chan_close_data.chan3,1);
    AT24CXX_Read(33,&chan_close_data.chan4,1);
    AT24CXX_Read(34,&chan_close_data.chan5,1);
    AT24CXX_Read(35,&chan_close_data.chan6,1);
    AT24CXX_Read(36,&chan_close_data.chan7,1);
    AT24CXX_Read(37,&chan_close_data.chan8,1);

}
void saveDelayData(u8 pageNum)
{
    switch(pageNum)
        {
        case 1:
            chan_open_data.chan1=chan_data.data1;
				    chan_open_data.chan2=chan_data.data2;
				    chan_open_data.chan3=chan_data.data3;
				    chan_open_data.chan4=chan_data.data4;
            AT24CXX_Write(22,&chan_open_data.chan1,1);
            AT24CXX_Write(23,&chan_open_data.chan2,1);
            AT24CXX_Write(24,&chan_open_data.chan3,1);
            AT24CXX_Write(25,&chan_open_data.chan4,1);
            break;
        case 2:
					  chan_open_data.chan5=chan_data.data1;
				    chan_open_data.chan6=chan_data.data2;
				    chan_open_data.chan7=chan_data.data3;
				    chan_open_data.chan8=chan_data.data4;
            AT24CXX_Write(26,&chan_open_data.chan5,1);
            AT24CXX_Write(27,&chan_open_data.chan6,1);
            AT24CXX_Write(28,&chan_open_data.chan7,1);
            AT24CXX_Write(29,&chan_open_data.chan8,1);
            break;
				case 3:
            /*关延时数据*/
				    chan_close_data.chan1=chan_data.data1;
				    chan_close_data.chan2=chan_data.data2;
				    chan_close_data.chan3=chan_data.data3;
				    chan_close_data.chan4=chan_data.data4;
            AT24CXX_Write(30,&chan_close_data.chan1,1);
            AT24CXX_Write(31,&chan_close_data.chan2,1);
            AT24CXX_Write(32,&chan_close_data.chan3,1);
            AT24CXX_Write(33,&chan_close_data.chan4,1);
        case 4:
					  chan_close_data.chan5=chan_data.data1;
				    chan_close_data.chan6=chan_data.data2;
				    chan_close_data.chan7=chan_data.data3;
				    chan_close_data.chan8=chan_data.data4;
            AT24CXX_Write(34,&chan_close_data.chan5,1);
            AT24CXX_Write(35,&chan_close_data.chan6,1);
            AT24CXX_Write(36,&chan_close_data.chan7,1);
            AT24CXX_Write(37,&chan_close_data.chan8,1);
            break;
        }
}

