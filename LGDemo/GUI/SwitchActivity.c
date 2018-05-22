#include "SwitchActivity.h"
Rectangle switchItemXY[9];
CHANEN ChanenStructure= {ON,ON,ON,ON,ON,ON,ON,ON};
SwitchActivity switchActivity= {switchActivitypage,&ChanenStructure,saveEnchanData,readEnchanData};
void  switchActivitypage()
{
    if(activity.activeActivity==activity.SWITCH)
        {
					  switchActivity.readEnchanData();
            component.titleBar();
            component.pageSpinner(10,0,70,30,"SWITCH",Blue,White,DOWN);
            switchItemXY[0].xyStructuee=component.pageswitch(10,45,30,20,"CH1",EnCH1,Blue,White);				  
            switchItemXY[1].xyStructuee=component.pageswitch(115,45,30,20,"CH2",EnCH2,Blue,White);			  
            switchItemXY[2].xyStructuee=component.pageswitch(10,70,30,20,"CH3",EnCH3,Blue,White);
            switchItemXY[3].xyStructuee=component.pageswitch(115,70,30,20,"CH4",EnCH4,Blue,White);
            switchItemXY[4].xyStructuee=component.pageswitch(10,95,30,20,"CH5",EnCH5,Blue,White);
            switchItemXY[5].xyStructuee=component.pageswitch(115,95,30,20,"CH6",EnCH6,Blue,White);
            switchItemXY[6].xyStructuee=component.pageswitch(10,120,30,20,"CH7",EnCH7,Blue,White);
            switchItemXY[7].xyStructuee=component.pageswitch(115,120,30,20,"CH8",EnCH8,Blue,White);
					  component.clear(0,157,220,18,Blue);
            switchItemXY[8].xyStructuee=component.pageButton(170,157,40,18,"SAVE",Blue,White);

        }
    switchActivityAction();
}
void switchActivityAction()
{

    while(activity.activeActivity==activity.SWITCH)
        {

            activity.flashTime();
            switchActivitySelectItem();
        }
}

void switchActivitySelectItem()
{

    u8 state=encoder();
    u8 static anchor=0;
	  u8 static lastanchor=0;
    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(switchItemXY[0].xyStructuee.sx,switchItemXY[0].xyStructuee.sy,
			switchItemXY[0].xyStructuee.width,switchItemXY[0].xyStructuee.height,2)==2)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[1].xyStructuee.sx,switchItemXY[1].xyStructuee.sy,
			switchItemXY[1].xyStructuee.width,switchItemXY[1].xyStructuee.height,3)==3)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[2].xyStructuee.sx,switchItemXY[2].xyStructuee.sy,
			switchItemXY[2].xyStructuee.width,switchItemXY[2].xyStructuee.height,4)==4)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[3].xyStructuee.sx,switchItemXY[3].xyStructuee.sy,
			switchItemXY[3].xyStructuee.width,switchItemXY[3].xyStructuee.height,5)==5)
        {
            anchor=5;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[4].xyStructuee.sx,switchItemXY[4].xyStructuee.sy,
			switchItemXY[4].xyStructuee.width,switchItemXY[4].xyStructuee.height,6)==6)
        {
            anchor=6;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[5].xyStructuee.sx,switchItemXY[5].xyStructuee.sy,
			switchItemXY[5].xyStructuee.width,switchItemXY[5].xyStructuee.height,7)==7)
        {
            anchor=7;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[6].xyStructuee.sx,switchItemXY[6].xyStructuee.sy,
			switchItemXY[6].xyStructuee.width,switchItemXY[6].xyStructuee.height,8)==8)
        {
            anchor=8;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[7].xyStructuee.sx,switchItemXY[7].xyStructuee.sy,
			switchItemXY[7].xyStructuee.width,switchItemXY[7].xyStructuee.height,9)==9)
        {
            anchor=9;
            state=EN_KEY_DOWN;
        }
				if(activity.toucharea(switchItemXY[8].xyStructuee.sx,switchItemXY[8].xyStructuee.sy,
			switchItemXY[8].xyStructuee.width,switchItemXY[8].xyStructuee.height,10)==10)
        {
            anchor=10;
            state=EN_KEY_DOWN;
        }
    switch(state)
        {
        case TURN_L:
            if(anchor<10)
            flashSwitchItem(++anchor,lastanchor);
            lastanchor=anchor;        
                
            break;
        case TURN_R:
            if(anchor>1)
            flashSwitchItem(--anchor,lastanchor);                                  
						lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
                    anchor=0;
                }else if(anchor==2){
									
								if(EnCH1==OFF) EnCH1=ON;
							  else if(EnCH1==ON) {EnCH1=OFF; ResetCH1};
							  component.emptyRectangle(&(switchItemXY[0].xyStructuee),EnCH1,White);		
								
								}else if(anchor==3){								
								if(EnCH2==OFF) EnCH2=ON;
							  else if(EnCH2==ON) {EnCH2=OFF; ResetCH2};
							  component.emptyRectangle(&(switchItemXY[1].xyStructuee),EnCH2,White);	
								}
								else if(anchor==4){
								if(EnCH3==OFF) EnCH3=ON;
							  else if(EnCH3==ON) {EnCH3=OFF; ResetCH3};
							  component.emptyRectangle(&(switchItemXY[2].xyStructuee),EnCH3,White);	
							
								}
								else if(anchor==5){
								if(EnCH4==OFF) EnCH4=ON;
							  else if(EnCH4==ON) {EnCH4=OFF; ResetCH4};
							  component.emptyRectangle(&(switchItemXY[3].xyStructuee),EnCH4,White);	
								
								}
								else if(anchor==6){
								if(EnCH5==OFF) EnCH5=ON;
							  else if(EnCH5==ON) {EnCH5=OFF; ResetCH5};
							  component.emptyRectangle(&(switchItemXY[4].xyStructuee),EnCH5,White);	
								
								}
								else if(anchor==7){
								if(EnCH6==OFF) EnCH6=ON;
							  else if(EnCH6==ON) {EnCH6=OFF; ResetCH6};
							  component.emptyRectangle(&(switchItemXY[5].xyStructuee),EnCH6,White);	
								
								}
								else if(anchor==8){
								if(EnCH7==OFF) EnCH7=ON;
							  else if(EnCH7==ON) {EnCH7=OFF; ResetCH7};
							  component.emptyRectangle(&(switchItemXY[6].xyStructuee),EnCH7,White);	
								
								}
								else if(anchor==9){
								if(EnCH8==OFF) EnCH8=ON;
							  else if(EnCH8==ON) {EnCH8=OFF; ResetCH8};
							  component.emptyRectangle(&(switchItemXY[7].xyStructuee),EnCH8,White);	
								
								}else if(anchor==10){
								switchActivity.saveEnchanData();
								component.pageButton(70,157,60,18,"SUCCESS",Blue,White);//提示保存成功信息
							  delay_ms(1000);
								component.pageButton(70,157,60,18,"SUCCESS",Blue,Blue);
								}
                if(anchor!=10){
								flashSwitchItem(anchor,lastanchor);                                  
						    lastanchor=anchor;
								} 
            break;
        }
}
void flashSwitchItem(u8 anchor,u8 lastanchor)
{
    switch(anchor)
        {
					
        case 1:
					component.pageSpinner(10,0,70,30,"SWITCH",Blue,Blue_100,DOWN);
            break;
        case 2:
					component.emptyRectangle(&(switchItemXY[0].xyStructuee),EnCH1,White);
            break;
        case 3:
					component.emptyRectangle(&(switchItemXY[1].xyStructuee),EnCH2,White);
            break;
        case 4:
					component.emptyRectangle(&(switchItemXY[2].xyStructuee),EnCH3,White);
            break;
        case 5:
					component.emptyRectangle(&(switchItemXY[3].xyStructuee),EnCH4,White);
            break;
        case 6:
					component.emptyRectangle(&(switchItemXY[4].xyStructuee),EnCH5,White);
            break;
        case 7:
					component.emptyRectangle(&(switchItemXY[5].xyStructuee),EnCH6,White);
            break;
        case 8:
					component.emptyRectangle(&(switchItemXY[6].xyStructuee),EnCH7,White);
            break;
        case 9:
					component.emptyRectangle(&(switchItemXY[7].xyStructuee),EnCH8,White);
            break;
        case 10:
					component.flashChar(&switchItemXY[8],"SAVE",Blue_100,White);
            break;

        }
		if(anchor!=lastanchor)
    switch(lastanchor)
        {
       case 1:
					component.pageSpinner(10,0,70,30,"SWITCH",Blue,White,DOWN);
            break;
        case 2:
					component.emptyRectangle(&(switchItemXY[0].xyStructuee),EnCH1,Black);
            break;
        case 3:
					component.emptyRectangle(&(switchItemXY[1].xyStructuee),EnCH2,Black);
            break;
        case 4:
					component.emptyRectangle(&(switchItemXY[2].xyStructuee),EnCH3,Black);
            break;
        case 5:
					component.emptyRectangle(&(switchItemXY[3].xyStructuee),EnCH4,Black);
            break;
        case 6:
					component.emptyRectangle(&(switchItemXY[4].xyStructuee),EnCH5,Black);
            break;
        case 7:
					component.emptyRectangle(&(switchItemXY[5].xyStructuee),EnCH6,Black);
            break;
        case 8:
					component.emptyRectangle(&(switchItemXY[6].xyStructuee),EnCH7,Black);
            break;
        case 9:
					component.emptyRectangle(&(switchItemXY[7].xyStructuee),EnCH8,Black);
            break;
        case 10:
					component.flashChar(&switchItemXY[8],"SAVE",Blue,White);
            break;
          
        }
}
void saveEnchanData(){

            AT24CXX_Write(236,&EnCH1,1);
            AT24CXX_Write(237,&EnCH2,1);
            AT24CXX_Write(238,&EnCH3,1);
            AT24CXX_Write(239,&EnCH4,1);

            AT24CXX_Write(240,&EnCH5,1);
            AT24CXX_Write(241,&EnCH6,1);
            AT24CXX_Write(242,&EnCH7,1);
            AT24CXX_Write(243,&EnCH8,1);
}
void readEnchanData(){

            AT24CXX_Read(236,&EnCH1,1);
            AT24CXX_Read(237,&EnCH2,1);
            AT24CXX_Read(238,&EnCH3,1);
            AT24CXX_Read(239,&EnCH4,1);

            AT24CXX_Read(240,&EnCH5,1);
            AT24CXX_Read(241,&EnCH6,1);
            AT24CXX_Read(242,&EnCH7,1);
            AT24CXX_Read(243,&EnCH8,1);
}

