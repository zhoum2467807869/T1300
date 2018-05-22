#include "TimerActivity.h"

TimerActivity timerActivity= {timerActivityPage};
void timerActivityPage()
{
    if(activity.activeActivity==activity.TIMER){
    component.titleBar();
    component.pageSpinner(10,0,70,30,"TIMER",Blue,White,DOWN);
    component.pageSpinner(140,0,75,30,"TIMER1",Blue,White,DOWN);

    component.pageButton(5,35-2,40,20,"STATE",Blue_200,White);
    component.pageSpinner(50,35-2,85,20,"FORBIT",White,Black,DOWN);
    component.pageSpinner(140,35-2,75,20,"ONCE",White,Black,DOWN);

    component.pageButton(5,60-2,40,20,"CH",Blue_200,White);
    component.pageCheckBox(45+5,60-2,16,20,White,"1");
    component.pageCheckBox(66+5,60-2,16,20,White,"2");
    component.pageCheckBox(87+5,60-2,16,20,White,"3");
    component.pageCheckBox(110+5,60-2,16,20,White,"4");
    component.pageCheckBox(131+5,60-2,16,20,White,"5");
    component.pageCheckBox(152+5,60-2,16,20,White,"6");
    component.pageCheckBox(173+5,60-2,16,20,White,"7");
    component.pageCheckBox(194+5,60-2,16,20,White,"8");

    component.pageButton(5,85-2,40,20,"YEAR",Blue_200,White);
    component.pageButton(5,110-2,40,20,"DAY",Blue_200,White);
		component.pageButton(5,135-2,40,20,"MIN",Blue_200,White);
		
    component.pageButton(45,85-2,65,20,"2017",White,Black);
    component.pageButton(45,110-2,65,20,"2",White,Black);
		component.pageButton(45,135-2,65,20,"8",White,Black);

    component.pageButton(115,85-2,40,20,"MON",Blue_200,White);
    component.pageButton(115,110-2,40,20,"HOUR",Blue_200,White);
		component.pageButton(115,135-2,40,20,"SEC",Blue_200,White);
		
    component.pageButton(155,85-2, 60,20,"5",White,Black);
    component.pageButton(155,110-2,60,20,"2",White,Black);
		component.pageButton(155,135-2,60,20,"5",White,Black);	
		component.clear(0,157,220,18,Blue);
		component.pageButton(175,157,40,18,"SAVE",Blue,White);
		
	}
		timerActivityAction();
}

void timerActivityAction(){
	
while(activity.activeActivity==activity.TIMER){


timerActivitySelectItem();
}
}

void timerActivitySelectItem(){

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
			component.pageSpinner(10,0,70,30,"TIMER",Blue,Blue_100,DOWN);
			}
			break;
		case TURN_R:
			if(anchor==0){
				anchor=1;
			component.pageSpinner(10,0,70,30,"TIMER",Blue,Blue_100,DOWN);
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

