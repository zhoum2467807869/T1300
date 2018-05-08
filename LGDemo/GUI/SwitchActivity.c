#include "SwitchActivity.h"

SwitchActivity switchActivity={switchActivitypage};

void  switchActivitypage(){

  component.titleBar();
  component.pageSpinner(10,0,70,30,"SWITCH",Blue,White);  
	component.pageswitch(0,45,40,20,"CH1",Black,White);
  component.pageswitch(105,45,40,20,"CH2",Black,White);
  component.pageswitch(0,70,40,20,"CH3",Black,White);
  component.pageswitch(105,70,40,20,"CH4",Black,White);
	
	component.pageswitch(0,95,40,20,"CH5",Black,White);
  component.pageswitch(105,95,40,20,"CH6",Black,White);
  component.pageswitch(0,120,40,20,"CH7",Black,White);
  component.pageswitch(105,120,40,20,"CH8",Black,White);
	component.pageButton(170,150,40,20,"SAVE",Blue_200,White);
	
}

