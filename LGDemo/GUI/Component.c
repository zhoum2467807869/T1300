#include "Component.h"
Component component={titleBar,pageSpinner,subPageSpinner,clearScreen,adderSubtracter,pageSpinnerItem,pageButton,pageCheckBox,
pageswitch,ShowpageSpinner,pageCircleButton};
void titleBar(){
    Fill_Fast_Rec(0,0,220,30,0x001F);
}

void pageSpinner(u16 x,u16 y,u16 width,u16 hegiht,char *p,u16 blackground,u16 textCorlor){
	  Fill_Fast_Rec(x,y,width,hegiht,blackground);
    LCD_DrawLtrigo(x+width-10,y+(hegiht-10)/2,x+width,y+(hegiht-10)/2+10,textCorlor);
    TFT_ShowString(x,y+(hegiht-16)/2,p,16,textCorlor);
	
}
void pageSpinnerItem(u16 x,u16 y,u16 width,u16 hegiht,char *p[],u8 itemNum){
	   u8 i=0;
	   Fill_Fast_Rec(x,y,width,(hegiht+2)*4,Black);
	   for(i=0;i<itemNum;i++){
			 
       Fill_Fast_Rec(x,y+(hegiht+2)*i,width,hegiht,Blue_200);
			 Write_Word_Center(x,y+(hegiht+2)*i,x+width,y+hegiht+(hegiht+2)*i,16,p[i],White);
			 
		 }	 
}
void subPageSpinner(){
    LCD_DrawLtrigo(64,10,74,20,White);
    TFT_ShowString(10,7,"HOME",16,White);
}
void adderSubtracter(u8 x,u8 y,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,char* n){
	
	
   Fill_Fast_Rec(x,y+height+2,adderwidth,height,Blue_100);
	 Fill_Fast_Rec(x+adderwidth+2,y+height+2,numberwidth,height,White);
	 Fill_Fast_Rec(x+adderwidth+numberwidth+4,y+height+2,subtracterwidth,height,Blue_100);
	 Write_Word_Center(x,y+height+2,x+adderwidth,y+height+height+2,16,"-",White);
	 Write_Word_Center(x+adderwidth+numberwidth+4,y+height+2,x+adderwidth+numberwidth+4+subtracterwidth,y+height+height+2,16,"+",White);
	 Write_Word_Center(x,y,x+adderwidth+numberwidth+subtracterwidth+4,y+height,16,p,White);
	 Write_Word_Center(x+adderwidth,y+height+2,x+adderwidth+numberwidth,y+height+height+2,16,n,Black);
}
 
void clearScreen(){
 Fill_Fast_Rec(0,0,220,176,Black);
}
void pageButton(u8 x,u8 y,u8 width,u8 height,char* p,u16 blackground,u16 textCorlor){
	 Fill_Fast_Rec(x,y,width,height,blackground);
   Write_Word_Center(x,y,x+width,y+height,16,p,textCorlor);
	
}
void pageswitch(u8 x,u8 y,u8 width,u8 height,char* p,u16 background,u16 textCorlor){

  component.pageButton(x,y,width,height,p,background,textCorlor);
	component.pageButton(x+width+5,y,30,20,"ON",White,Black);
	component.pageButton(x+width+5+30,y,30,20,"OFF",Blue_100,White);
	
}
void pageCheckBox(u8 x,u8 y,u8 width,u8 height,u16 corlor,char* p){
	
     gui_4_yuanhu_CU_EMPTY(x,y,x+width,y+height,2,corlor);
	   Write_Word_Center(x,y,x+width,y+height,16,p,White);
}
void ShowpageSpinner(){
  char* itemName[] = {"HOME","DELAY","SWITCH","TIMER","OTHER"};
	component.pageSpinnerItem(0,32,80,20,itemName,5);
}
void pageCircleButton(u8 x,u8 y,u8 width,u8 height,char* p,u8 mode,u16 color,u8 textSize){
	
	   DisAPI.gui_draw_arc(x,y,x+width,y+height,x+width/2,y+height/2,width/2,Black,1);	   
     DisAPI.gui_draw_arc(x,y,x+width,y+height,x+width/2,y+height/2,width/2,color,mode);	   
     Write_Word_Center(x,y,x+width,y+height,textSize,p,White);
	
}



