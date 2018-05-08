#include "DelayActivity.h"
DelayActivity delayActivity={delayPage};
void delayPage(){

	char* subitemName[] = {"OPEN1/2","OPEN2/2","CLOSE1/2","CLOSE2/2"};
  component.titleBar();
	component.pageSpinner(10,0,70,30,"DELAY",Blue,White);	
	component.pageSpinner(130,0,80,30,"OPEN1/2",Blue,White);	
	component.adderSubtracter(5,30,20,50,20,20,"CH1","1");
	component.adderSubtracter(115,30,20,50,20,20,"CH2","2");
	component.adderSubtracter(5,70,20,50,20,20,"CH3","3");
	component.adderSubtracter(115,70,20,50,20,20,"CH4","4");
  component.adderSubtracter(5,110,20,50,20,20,"CH5","5");
	component.adderSubtracter(115,110,20,50,20,20,"CH6","6");

	//component.pageSpinnerItem(130,32,90,20,subitemName,4);
	
}


