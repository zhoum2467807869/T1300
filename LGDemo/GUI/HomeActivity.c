#include "HomeActivity.h"
u8 vol[28] = {220,218,230,234,232,228,226,225,223,226,231,232,230,239,235,236,234,229,226,227,226,223,224,225,221,220,218,232};
HomeActivity homeActivity= {mainPage,mainOpenSplash,showVolAndTime};
void mainOpenSplash()
{

    Fill_Fast_Rec(0,0,220,176,Black);//Ë¢ºÚÆÁ
    TFT_Show_Any_Picture(33,73,155,30,Blue_50,LOGO);	//ÏÔÊ¾LOGO
    delay_ms(1000);
    TFT_Show_Any_Picture(33,73,155,30,Blue_100,LOGO);	//ÏÔÊ¾LOGO
    delay_ms(1000);
    TFT_Show_Any_Picture(33,73,155,30,Blue_250,LOGO);	//ÏÔÊ¾LOGO
    delay_ms(1000);
    TFT_Show_Any_Picture(33,73,155,30,Blue_300,LOGO);	//ÏÔÊ¾LOGO
    delay_ms(1000);
    Fill_Fast_Rec(0,0,220,176,Black);//Ë¢ºÚÆÁ

}
void showVolAndTime()
{
    u8 static i;

    Fill_Fast_Rec(100,48,50,25,Black);
    TFT_ShowNum(110,48,vol[i],24,White);
    Fill_Fast_Rec(175,0,45,30,Blue);
    TFT_ShowNum(175,13,calendar.hour,16,White);
    TFT_ShowNum(198,13,calendar.min,16,White);
    TFT_ShowString(190,13,":",16,White);
    i++;
    if(i==28)
        i=0;


}

void mainPage()
{

    component.titleBar();
    component.pageSpinner(10,0,70,30,"HOME",Blue,White);
    TFT_ShowString(10,48,"VOLT:       V",24,White);
    gui_4_yuanhu_CU_EMPTY(5,35,215,85,5,White);
    
	if(ReadCH1)
	  component.pageCircleButton(5,90,40,40,"1",1,Blue_200,24);
	else
		component.pageCircleButton(5,90,40,40,"1",0,Blue_200,24);
	if(ReadCH5)
	  component.pageCircleButton(5,135,40,40,"5",1,Blue_200,24);
	else 
		component.pageCircleButton(5,135,40,40,"5",0,Blue_200,24);
  if(ReadCH2)
    component.pageCircleButton(61,90,40,40,"2",1,Blue_200,24);
	else
		component.pageCircleButton(61,90,40,40,"2",0,Blue_200,24);
	if(ReadCH6)
	  component.pageCircleButton(61,135,40,40,"6",1,Blue_200,24);
	else
		component.pageCircleButton(61,135,40,40,"6",0,Blue_200,24);
	if(ReadCH3)
		component.pageCircleButton(117,90,40,40,"3",1,Blue_200,24);
	else 
		component.pageCircleButton(117,90,40,40,"3",0,Blue_200,24);
	if(ReadCH7)
	  component.pageCircleButton(117,135,40,40,"7",1,Blue_200,24);
	else
		component.pageCircleButton(117,135,40,40,"7",0,Blue_200,24);
	if(ReadCH4)
		component.pageCircleButton(173,90,40,40,"4",1,Blue_200,24);
	else
		component.pageCircleButton(173,90,40,40,"4",0,Blue_200,24);
	if(ReadCH8)
	  component.pageCircleButton(173,135,40,40,"8",1,Blue_200,24);
	else 
		component.pageCircleButton(173,135,40,40,"8",0,Blue_200,24);
		
};

