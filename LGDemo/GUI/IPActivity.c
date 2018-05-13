#include "IPActivity.h"

IPActivity ipActivity={IPActivityPage,ipActivityItemSelect};
void IPActivityPage(){

	if(activity.activeActivity==activity.IP){ 
  component.titleBar();
  component.pageSpinner(10,0,70,30,"IP",Blue,White,DOWN);
	component.virticleadderSubtracter(65,65,20,50,20,20,"IP ADDRESS","1");
	}
	ipActivityAction();
}

void ipActivityAction(){
	
while(activity.activeActivity==activity.IP){

	ipActivityItemSelect();
	
}

}
void ipActivityItemSelect(){

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
			  component.pageSpinner(10,0,70,30,"IP",Blue,Blue_100,DOWN);
			}
			break;
		case TURN_R:
		if(anchor==0){
				anchor=1;
			  component.pageSpinner(10,0,70,30,"IP",Blue,Blue_100,DOWN);
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

