#include "DelayActivity.h"
DelayActivity delayActivity={delayPage};
void delayPage(){

if(activity.activeActivity==activity.DELAY){
  component.titleBar();
	component.pageSpinner(10,0,70,30,"DELAY",Blue,White,DOWN);	
	component.pageSpinner(130,0,80,30,"OPEN1/2",Blue,White,DOWN);	
	component.virticleadderSubtracter(5,30,20,50,20,20,"CH1","1");
	component.virticleadderSubtracter(115,30,20,50,20,20,"CH2","2");
	component.virticleadderSubtracter(5,70,20,50,20,20,"CH3","3");
	component.virticleadderSubtracter(115,70,20,50,20,20,"CH4","4");
  component.virticleadderSubtracter(5,110,20,50,20,20,"CH5","5");
	component.virticleadderSubtracter(115,110,20,50,20,20,"CH6","6");
 }
	//component.pageSpinnerItem(130,32,90,20,subitemName,4);
 delayActivityAction();
	
}
void delayActivityAction(){
	
  while(activity.activeActivity==activity.DELAY){
	
		 delatPageSelectItem();
		
	
	}


}

void delatPageSelectItem(){
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
		  component.pageSpinner(10,0,70,30,"DELAY",Blue,Blue_100,DOWN);
			 anchor=1;
		 }	
			break;
		case TURN_R:
				 if(anchor==0){
		  component.pageSpinner(10,0,70,30,"DELAY",Blue,Blue_100,DOWN);
			 anchor=1;
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

