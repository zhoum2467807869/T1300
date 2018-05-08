#include "TimerActivity.h"

TimerActivity timerActivity= {timerActivityPage};
void timerActivityPage()
{

    component.titleBar();
    component.pageSpinner(10,0,70,30,"TIMER",Blue,White);
    component.pageSpinner(140,0,75,30,"TIMER1",Blue,White);

    component.pageButton(5,35,40,20,"STATE",Blue_200,White);
    component.pageSpinner(50,35,85,20,"FORBIT",White,Black);
    component.pageSpinner(140,35,75,20,"ONCE",White,Black);

    component.pageButton(5,60,40,20,"CH",Blue_200,White);
    component.pageCheckBox(45+5,60,16,20,White,"1");
    component.pageCheckBox(66+5,60,16,20,White,"2");
    component.pageCheckBox(87+5,60,16,20,White,"3");
    component.pageCheckBox(110+5,60,16,20,White,"4");
    component.pageCheckBox(131+5,60,16,20,White,"5");
    component.pageCheckBox(152+5,60,16,20,White,"6");
    component.pageCheckBox(173+5,60,16,20,White,"7");
    component.pageCheckBox(194+5,60,16,20,White,"8");

    component.pageButton(5,85,40,20,"YEAR",Blue_200,White);
    component.pageButton(5,110,40,20,"DAY",Blue_200,White);
		component.pageButton(5,135,40,20,"MIN",Blue_200,White);
		
    component.pageButton(45,85,60,20,"2017",White,Black);
    component.pageButton(45,110,60,20,"2",White,Black);
		component.pageButton(45,135,60,20,"8",White,Black);

    component.pageButton(115,85,40,20,"MON",Blue_200,White);
    component.pageButton(115,110,40,20,"HOUR",Blue_200,White);
		component.pageButton(115,135,40,20,"SEC",Blue_200,White);
		
    component.pageButton(155,85, 60,20,"5",White,Black);
    component.pageButton(155,110,60,20,"2",White,Black);
		component.pageButton(155,135,60,20,"5",White,Black);	
		component.pageButton(175,157,40,18,"SAVE",Blue_200,White);
}