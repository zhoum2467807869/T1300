#include "SwitchActivity.h"

SwitchActivity switchActivity={switchActivitypage};

void  switchActivitypage(){
  if(activity.activeActivity==activity.SWITCH){
  component.titleBar();
  component.pageSpinner(10,0,70,30,"SWITCH",Blue,White,DOWN);  
	component.pageswitch(10,45,30,20,"CH1",Blue,White);
  component.pageswitch(115,45,30,20,"CH2",Blue,White);
  component.pageswitch(10,70,30,20,"CH3",Blue,White);
  component.pageswitch(115,70,30,20,"CH4",Blue,White);
	
	component.pageswitch(10,95,30,20,"CH5",Blue,White);
  component.pageswitch(115,95,30,20,"CH6",Blue,White);
  component.pageswitch(10,120,30,20,"CH7",Blue,White);
  component.pageswitch(115,120,30,20,"CH8",Blue,White);
	component.pageButton(170,150,40,20,"SAVE",Blue,White);
	}
	switchActivityAction();
}
void switchActivityAction(){
	
while(activity.activeActivity==activity.SWITCH){


switchActivitySelectItem();
}
}

void switchActivitySelectItem(){

  u8 state=encoder();
	u8 static anchor=0;	
	    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
	switch(state){
		case TURN_L:
			if(anchor==0){
			  anchor=1;
				component.pageSpinner(10,0,70,30,"SWITCH",Blue,Blue_100,DOWN);
			}
			break;
		case TURN_R:
			if(anchor==0){
			  anchor=1;
				component.pageSpinner(10,0,70,30,"SWITCH",Blue,Blue_100,DOWN);
			}
			break;
	  case EN_KEY_DOWN:
			if(anchor==1){
			  activity.activeActivity=activity.SPINNER;
				anchor=0;
			}
			break;
	}
	


}