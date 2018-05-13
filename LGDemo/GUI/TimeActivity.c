#include "TimeActivity.h"
TimeActivity timeActivity={timeActivityPage,timeActivityItemSelect};

void timeActivityPage(){
	
	if(activity.activeActivity==activity.TIME){
    component.titleBar();
    component.pageSpinner(10,0,70,30,"TIME",Blue,White,DOWN);
    component.pageButton(5,65,40,20,"YEAR",Blue_200,White);
    component.pageButton(5,90,40,20,"DAY",Blue_200,White);
    component.pageButton(5,115,40,20,"MIN",Blue_200,White);

    component.pageButton(45,65,60,20,"2017",White,Black);
    component.pageButton(45,90,60,20,"2",White,Black);
    component.pageButton(45,115,60,20,"8",White,Black);

    component.pageButton(115,65,40,20,"MON",Blue_200,White);
    component.pageButton(115,90,40,20,"HOUR",Blue_200,White);
    component.pageButton(115,115,40,20,"SEC",Blue_200,White);

    component.pageButton(155,65, 60,20,"5",White,Black);
    component.pageButton(155,90,60,20,"2",White,Black);
    component.pageButton(155,115,60,20,"5",White,Black);

	  component.pageButton(170,150,40,20,"SAVE",Blue_200,White);
		timeActivityAction();
  }
}

void timeActivityAction(){
	
while(activity.activeActivity==activity.TIME){

	timeActivityItemSelect();
	
}

}
void timeActivityItemSelect(){

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
			  component.pageSpinner(10,0,70,30,"TIME",Blue,Blue_100,DOWN);
			}
			break;
		case TURN_R:
			if(anchor==0){
				anchor=1;
			  component.pageSpinner(10,0,70,30,"TIME",Blue,Blue_100,DOWN);
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