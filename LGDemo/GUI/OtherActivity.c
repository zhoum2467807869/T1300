#include "OtherActivity.h"

OtherActivity otherActivity= {otherActivityPage};

void otherActivityPage()
{
    component.titleBar();
    component.pageSpinner(10,0,70,30,"OTHER",Blue,White);
	
	  component.pageSpinner(150,0,60,30,"TIME",Blue,White);
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
}

