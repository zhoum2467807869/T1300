#include "PWDActivity.h"

PWDActivity pwdActivity={pwdActivityPage,pwdActivityItemSelect};

void pwdActivityPage(){
if(activity.activeActivity==activity.PWD){
	  component.titleBar();
    component.pageSpinner(10,0,70,30,"PWD",Blue,White,DOWN);
	    
	  component.pageButton(40,65,60,20,"OLD PWD",Blue_200,White);
    component.pageButton(40,90,60,20,"NEW PWD",Blue_200,White);

    component.pageButton(100,65,80,20,"* * * *",White,Black);
    component.pageButton(100,90,80,20,"* * * *",White,Black);
	
		pwdActivityAction();
  }
}

void pwdActivityAction(){
	
while(activity.activeActivity==activity.PWD){

	pwdActivityItemSelect();
	
}

}
void pwdActivityItemSelect(){

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
			  component.pageSpinner(10,0,70,30,"PWD",Blue,Blue_100,DOWN);
			}
			break;
		case TURN_R:
						if(anchor==0){
				anchor=1;
			 component.pageSpinner(10,0,70,30,"PWD",Blue,Blue_100,DOWN);
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



