#include "AUZActivity.h"

AUZActivity auzActivity={auzActivityPage,auzActivityItemSelect};
	
void auzActivityPage(){
	 if(activity.activeActivity==activity.AUZ){
	  component.titleBar();
    component.pageSpinner(10,0,70,30,"AUZ",Blue,White,DOWN);
	
		component.pageButton(30,85,80,20,"AUZ CODE",Blue_200,White);
    component.pageButton(110,85,80,20,"* * * *",White,Black);
	 }
	 auzActivityAction();
 }

void auzActivityAction(){
	
while(activity.activeActivity==activity.AUZ){

	auzActivityItemSelect();
	
}

}
void auzActivityItemSelect(){

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
			  component.pageSpinner(10,0,70,30,"AUZ",Blue,Blue_100,DOWN);
			}
			break;
		case TURN_R:
					if(anchor==0){
				anchor=1;
			  component.pageSpinner(10,0,70,30,"AUZ",Blue,Blue_100,DOWN);
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

