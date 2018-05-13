#include "Component.h"
Component component={titleBar,pageSpinner,clearScreen,virticleadderSubtracter,pageSpinnerItem,pageButton,pageCheckBox,
pageswitch,ShowpageSpinner,pageCircleButton,clearPage,clear,horizontaladderSubtracter};
void titleBar(){//titleBar
    Fill_Fast_Rec(0,0,220,30,0x001F);
}

void pageSpinner(u16 x,u16 y,u16 width,u16 hegiht,char *p,u16 blackground,u16 textCorlor,u8 dir){//draw spinner
	
	  Fill_Fast_Rec(x,y,width,hegiht,blackground);
    LCD_DrawLtrigo(x+width-10,y+(hegiht-10)/2,x+width,y+(hegiht-10)/2+10,textCorlor,dir);
    TFT_ShowString(x,y+(hegiht-16)/2,p,16,textCorlor);
	
}
void pageSpinnerItem(u16 x,u16 y,u16 width,u16 hegiht,char *p[],u8 itemNum){//draw item of spinner
	   u8 i=0;
	   Fill_Fast_Rec(x,y,width,(hegiht+2)*4,Black);
	   for(i=0;i<itemNum;i++){
			 
       Fill_Fast_Rec(x,y+(hegiht+2)*i,width,hegiht,Blue_50);
			 Write_Word_Center(x,y+(hegiht+2)*i,x+width,y+hegiht+(hegiht+2)*i,16,p[i],Black);
			 
		 }	 
}
void virticleadderSubtracter(u8 x,u8 y,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,char* n){//draw adder-subtracter 
		
   Fill_Fast_Rec(x,y+height+2,adderwidth,height,Blue_200);
	 Fill_Fast_Rec(x+adderwidth+2,y+height+2,numberwidth,height,White);
	 Fill_Fast_Rec(x+adderwidth+numberwidth+4,y+height+2,subtracterwidth,height,Blue_200);
	
	 Write_Word_Center(x,y+height+2,x+adderwidth,y+height+height+2,16,"-",White);
	 Write_Word_Center(x+adderwidth+numberwidth+4,y+height+2,x+adderwidth+numberwidth+4+subtracterwidth,y+height+height+2,16,"+",White);
	 Write_Word_Center(x,y+3,x+adderwidth+numberwidth+subtracterwidth+4,y+height,16,p,White);
	 Write_Word_Center(x+adderwidth,y+height+2,x+adderwidth+numberwidth,y+height+height+2,16,n,Black);
	
}
void clearScreen(){//draw screen in black ;
 Fill_Fast_Rec(0,0,220,176,Black);
}
void pageButton(u8 x,u8 y,u8 width,u8 height,char* p,u16 blackground,u16 textCorlor){//draw Button
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
void ShowpageSpinner(u8 spinnertype){//0：前五个spinner 1:后五个spinner
	
  char* itemName[] = {"HOME","DELAY","SWITCH","TIMER","OTHER"};
	char* otherPage[5]={"TIME","PWD","UVOV","IP","AUZ"};
	if(spinnertype==1){
	component.clear(0,32,81,108,Black);
	component.pageSpinnerItem(0,32,80,20,itemName,5);
	DisAPI.LCD_DrawLtrigo(65,125,75,135,Black,RIGHT);	
	}
	if(spinnertype==0){
	component.clear(85,50,71,108,Black);
	component.pageSpinnerItem(85,50,70,20,otherPage,5);
	}
	
}
void pageCircleButton(u8 x,u8 y,u8 width,u8 height,char* p,u8 mode,u16 color,u8 textSize){
	
	   DisAPI.gui_draw_arc(x,y,x+width,y+height,x+width/2,y+height/2,width/2,Black,1);	   
     DisAPI.gui_draw_arc(x,y,x+width,y+height,x+width/2,y+height/2,width/2,color,mode);	   
     Write_Word_Center(x,y,x+width,y+height,textSize,p,White);
	
}
void clearPage(){
Fill_Fast_Rec(0,31,220,145,Black);
}
void clear(u8 x,u8 y,u8 width,u8 height,u16 corlor){//fill screen area
Fill_Fast_Rec(x,y,width,height,corlor);
}
void horizontaladderSubtracter(u8 x,u8 y,u8 textwidth,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,char* n){

	
	 Fill_Fast_Rec(x,y,textwidth-5,height,Blue_200);
   Fill_Fast_Rec(x+textwidth,y,adderwidth,height,Blue_100);
	 Fill_Fast_Rec(x+textwidth+adderwidth+2,y,numberwidth,height,White);
	 Fill_Fast_Rec(x+textwidth+adderwidth+numberwidth+4,y,subtracterwidth,height,Blue_100);	
	
	 Write_Word_Center(x+textwidth,y,x+adderwidth+textwidth,y+height,16,"-",White);
	 Write_Word_Center(x+textwidth+adderwidth+numberwidth+4,y,x+adderwidth+numberwidth+4+subtracterwidth+textwidth,y+height,16,"+",White);		 
	 Write_Word_Center(x+textwidth+adderwidth,y,x+adderwidth+numberwidth+textwidth,y+height,16,n,Black);
	 Write_Word_Center(x,y,x+textwidth-5,y+height,16,p,White);

}

//u16 adderSubtracter(u8 x,u8 y,u8 adderwidth,u8 numberwidth,u8 subtracterwidth){


//}

