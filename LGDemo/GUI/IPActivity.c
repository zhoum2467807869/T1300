#include "IPActivity.h"

IPActivity ipActivity= {IPActivityPage,ipActivityItemSelect,readIPData,saveIPData};
_ip_data ip_data= {1};
Rectangle ipXY[2];
void IPActivityPage()
{

    if(activity.activeActivity==activity.IP)
        {

            component.titleBar();
            ipXY[0].xyStructuee=component.pageSpinner(10,0,70,30,"IP",Blue,White,DOWN);
            ipXY[1].xyStructuee=component.virticleadderSubtracter(65,65,20,50,20,20,"IP ADDRESS",ip_data.ip);
					  component.clear(0,157,220,18,Blue);
        }
    ipActivityAction();
}

void ipActivityAction()
{

    while(activity.activeActivity==activity.IP)
        {
            activity.flashTime();
            ipActivityItemSelect();

        }

}
void ipActivityItemSelect()
{

    u8 state=encoder();
    u8 static anchor=0;
    u8 static encoderAddSubflag=0;
    u8 static lastanchor=0;
    u8 screenaddsubsatus=activity.scanAddSubstruct(ipXY[1].xyStructuee.sx,ipXY[1].xyStructuee.sy,ipXY[1].xyStructuee.width,ipXY[1].xyStructuee.height);
    u8 addsubsatus=activity.encoderToAddSub(&encoderAddSubflag,&state);
    if(encoderAddSubflag)
        state=0;

    switch(addsubsatus|screenaddsubsatus)
        {
        case ADD:
            if(ip_data.ip<127)
                ip_data.ip++;
            component.flashData(&ipXY[1],ip_data.ip,Blue_100,Black);
						ipActivity.saveIPData();
            break;
        case SUB:
            if(ip_data.ip>1)
                ip_data.ip--;
            component.flashData(&ipXY[1],ip_data.ip,Blue_100,Black);
						ipActivity.saveIPData();
            break;
        }

    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(ipXY[1].xyStructuee.sx,ipXY[1].xyStructuee.sy,ipXY[1].xyStructuee.width,ipXY[1].xyStructuee.height,2)==2)
        {

            anchor=2;
            state=EN_KEY_DOWN;
            delay_ms(100);
        }

    switch(state)
        {
        case TURN_L:
            if(anchor<2)
                flashIpItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashIpItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
                    encoderAddSubflag=0;
                    anchor=0;
                }
            else if(anchor==2)
                {
                    encoderAddSubflag=1;
                    flashIpItem(anchor,lastanchor);
                    lastanchor=anchor;
                }
            break;
        }

}
void flashIpItem(u8 anchor,u8 lastanchor)
{

            switch(anchor)
                {
                case 1:
                    component.pageSpinner(10,0,70,30,"IP",Blue,Blue_100,DOWN);
                    break;
                case 2:
                    component.flashData(&ipXY[1],ip_data.ip,Blue_100,Black);
                    break;
                }
						if(anchor!=lastanchor){		
            switch(lastanchor)
                {
                case 1:
                    component.pageSpinner(10,0,70,30,"IP",Blue,White,DOWN);
                    break;
                case 2:
                    component.flashData(&ipXY[1],ip_data.ip,White,Black);
                    break;

                }
							}
}

void readIPData(){
	
AT24CXX_Read(15,&ip_data.ip,1);

}
void saveIPData(){
  AT24CXX_Write(15,&ip_data.ip,1);
}