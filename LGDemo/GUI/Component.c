#include "Component.h"
Component component= {titleBar,pageSpinner,clearScreen,virticleadderSubtracter,pageSpinnerItem,pageButton,pageCheckBox,
                      pageswitch,ShowpageSpinner,pageCircleButton,clearPage,clear,horizontaladderSubtracter,assignStructure,flashData,flashChar,emptyRectangle
                     ,pageEditText,getMAXofArray};
Rectangle  spinnerXY[10];//最大存储SpinnerItem的坐标，宽高为10
void titleBar() //titleBar
{
    Fill_Fast_Rec(0,0,220,30,0x001F);
}

RectangleXY pageSpinner(u16 x,u16 y,u16 width,u16 hegiht,char *p,u16 blackground,u16 textCorlor,u8 dir) //draw spinner
{
    RectangleXY rectangle;
    Fill_Fast_Rec(x,y,width,hegiht,blackground);
    LCD_DrawLtrigo(x+width-10,y+(hegiht-10)/2,x+width,y+(hegiht-10)/2+10,textCorlor,dir);
    TFT_ShowString(x,y+(hegiht-16)/2,p,16,textCorlor);
	  rectangle.sx=x;
    rectangle.sy=y;
	  rectangle.width=width;
	  rectangle.height=hegiht;
	  return rectangle;

}
Rectangle* pageSpinnerItem(u16 x,u16 y,u16 width,u16 hegiht,char *p[],u8 itemNum) //draw item of spinner
{

    u8 i=0;
    Fill_Fast_Rec(x,y,width,(hegiht+2)*(itemNum-1),Black);
    for(i=0; i<itemNum; i++)
        {
            Fill_Fast_Rec(x,y+(hegiht+2)*i,width,hegiht,Blue_50);
            Write_Word_Center(x,y+(hegiht+2)*i,x+width,y+hegiht+(hegiht+2)*i,16,p[i],Black);
					spinnerXY[i].xyStructuee.sx=x;
					spinnerXY[i].xyStructuee.sy=y+(hegiht+2)*i;
					spinnerXY[i].xyStructuee.width=width;
					spinnerXY[i].xyStructuee.height=hegiht;
        }
				return spinnerXY;
}
RectangleXY virticleadderSubtracter(u8 x,u8 y,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,u16 Num) //draw adder-subtracter
{

    RectangleXY rectanglexy;
    Fill_Fast_Rec(x,y+height+2,adderwidth,height,Blue_200);
    Fill_Fast_Rec(x+adderwidth+2,y+height+2,numberwidth,height,White);
    Fill_Fast_Rec(x+adderwidth+numberwidth+4,y+height+2,subtracterwidth,height,Blue_200);

    Write_Word_Center(x,y+height+2,x+adderwidth,y+height+height+2,16,"-",White);
    Write_Word_Center(x+adderwidth+numberwidth+4,y+height+2,x+adderwidth+numberwidth+4+subtracterwidth,y+height+height+2,16,"+",White);
    Write_Word_Center(x,y+3,x+adderwidth+numberwidth+subtracterwidth+4,y+height,16,p,White);
    DisAPI.Write_Num_Center(x+adderwidth+2,y+height+2,x+adderwidth+numberwidth,y+height+height+2,16,Num,Black,0,0);
    rectanglexy.sx=x+adderwidth+2;
    rectanglexy.sy=y+height+2;
    rectanglexy.width=numberwidth;
    rectanglexy.height=height;
    return rectanglexy;
}
void clearScreen() //draw screen in black ;
{
    Fill_Fast_Rec(0,0,220,176,Black);
}
RectangleXY pageButton(u8 x,u8 y,u8 width,u8 height,char* p,u16 blackground,u16 textCorlor) //draw Button
{

    RectangleXY rectanglexy;
    Fill_Fast_Rec(x,y,width,height,blackground);
    Write_Word_Center(x,y,x+width,y+height,16,p,textCorlor);
    rectanglexy.sx=x;
    rectanglexy.sy=y;
    rectanglexy.width=width;
    rectanglexy.height=height;

    return rectanglexy;
}
RectangleXY pageEditText(u8 x,u8 y,u8 width,u8 height,u16 num,u16 blackground,u16 textCorlor) 
{

    RectangleXY rectanglexy;
    Fill_Fast_Rec(x,y,width,height,blackground);
    DisAPI.Write_Num_Center(x,y,x+width,y+height,16,num,textCorlor,0,0);
    rectanglexy.sx=x;
    rectanglexy.sy=y;
    rectanglexy.width=width;
    rectanglexy.height=height;

    return rectanglexy;
}
RectangleXY pageswitch(u8 x,u8 y,u8 width,u8 height,char* p,u8 switchStatus,u16 background,u16 textCorlor)
{

    RectangleXY rectangle;
    component.pageButton(x,y,width,height,p,background,textCorlor);
	  
	  if(switchStatus==OFF){
		    component.pageButton(x+width+5,y,30,20,"ON",White,Black);
        component.pageButton(x+width+5+30,y,30,20,"OFF",Blue_100,White);
		}else if(switchStatus==ON){
		    component.pageButton(x+width+5,y,30,20,"ON",Blue_100,White);
        component.pageButton(x+width+5+30,y,30,20,"OFF",White,Black);
		}
    rectangle.sx=x+width+3;
    rectangle.sy=y-2;
    rectangle.height=24;
    rectangle.width=64;

    return rectangle;
}
void pageCheckBox(u8 x,u8 y,u8 width,u8 height,u16 corlor,char* p)
{

    gui_4_yuanhu_CU_EMPTY(x,y,x+width,y+height,2,corlor);
    Write_Word_Center(x,y,x+width,y+height,16,p,White);
}
void ShowpageSpinner(u8 spinnertype) //0：前五个spinner 1:后五个spinner
{

    char* itemName[] = {"HOME","DELAY","SWITCH","TIMER","OTHER"};
    char* otherPage[5]= {"TIME","PWD","UVOV","IP","AUZ"};
    if(spinnertype==1)
        {
            component.clear(0,32,81,108,Black);
            component.pageSpinnerItem(0,32,80,20,itemName,5);
            DisAPI.LCD_DrawLtrigo(65,125,75,135,Black,RIGHT);
        }
    if(spinnertype==0)
        {
            component.clear(85,50,71,108,Black);
            component.pageSpinnerItem(85,50,70,20,otherPage,5);
        }

}
RectangleXY pageCircleButton(u8 x,u8 y,u8 width,u8 height,char* p,u8 mode,u16 color,u8 textSize)
{
	  RectangleXY rectangle;
    DisAPI.gui_draw_arc(x,y,x+width,y+height,x+width/2,y+height/2,width/2,Black,1);
    DisAPI.gui_draw_arc(x,y,x+width,y+height,x+width/2,y+height/2,width/2,color,mode);
    Write_Word_Center(x,y,x+width,y+height,textSize,p,White);
	  rectangle.sx=x;
	  rectangle.sy=y;
	  rectangle.width=x+width;
	  rectangle.height=y+height;	
	  return rectangle;
}
void clearPage()/*清除顶部标题栏以下的区域，用于DELAY页面和TIMMER页面的子页面刷新*/
{
    Fill_Fast_Rec(0,31,220,145,Black);
}
void clear(u8 x,u8 y,u8 width,u8 height,u16 corlor)/*填充函数*/
{
    Fill_Fast_Rec(x,y,width,height,corlor);
}
RectangleXY horizontaladderSubtracter(u8 x,u8 y,u8 textwidth,u8 adderwidth,u8 numberwidth,u8 subtracterwidth,u8 height,char* p,u16 Num)/*画加减器，返回坐标结构体*/
{

    RectangleXY rectanglexy;
    Fill_Fast_Rec(x,y,textwidth-5,height,Blue);
    Fill_Fast_Rec(x+textwidth,y,adderwidth,height,Blue_200);
    Fill_Fast_Rec(x+textwidth+adderwidth+2,y,numberwidth,height,White);
    Fill_Fast_Rec(x+textwidth+adderwidth+numberwidth+4,y,subtracterwidth,height,Blue_200);

    Write_Word_Center(x+textwidth,y,x+adderwidth+textwidth,y+height,16,"-",White);
    Write_Word_Center(x+textwidth+adderwidth+numberwidth+4,y,x+adderwidth+numberwidth+4+subtracterwidth+textwidth,y+height,16,"+",White);
    DisAPI.Write_Num_Center(x+textwidth+adderwidth,y,x+adderwidth+numberwidth+textwidth,y+height,16,Num,Black,0,0);
    Write_Word_Center(x,y,x+textwidth-5,y+height,16,p,White);
    rectanglexy.sx=x+textwidth+adderwidth+2;
    rectanglexy.sy=y;
    rectanglexy.width=numberwidth;
    rectanglexy.height=height;
    return rectanglexy;
}
void assignStructure(u8 x,u8 y,u8 width,u8 height,RectangleXY* rectanglexy)/*将坐标赋值给结构体*/
{
    rectanglexy->sx=x;
    rectanglexy->sy=y;
    rectanglexy->width=width;
    rectanglexy->height=height;
}
void flashData(Rectangle *rectangle,u16 Num,u16 rectangleColor,u16 contentColor)/*用于提示/取消选中数字*/
{
    /*
        刷新矩形框里面的内容
    	  回调函数：disolayfuc()是刷新数据或者字符串
    */
    u8 x=rectangle->xyStructuee.sx;
    u8 y=rectangle->xyStructuee.sy;
    u8 width=rectangle->xyStructuee.width;
    u8 height=rectangle->xyStructuee.height;

    Fill_Fast_Rec(x,y,width,height,rectangleColor);
    DisAPI.Write_Num_Center(x,y,x+width,y+height,16,Num,contentColor,0,0);
}

void flashChar(Rectangle *rectangle,char* p,u16 rectangleColor,u16 contentColor)/*用于提示/取消选中带字符的Button*/
{

    u8 x=rectangle->xyStructuee.sx;
    u8 y=rectangle->xyStructuee.sy;
    u8 width=rectangle->xyStructuee.width;
    u8 height=rectangle->xyStructuee.height;
    Fill_Fast_Rec(x,y,width,height,rectangleColor);

    DisAPI.Write_Word_Center(x,y,x+width,y+height,16,p,contentColor);
}
void emptyRectangle(RectangleXY* rectanglexy,u8 switchStatus,u16 color)/*用于提示/取消选中Switch*/
{
	  /*传入坐标结构体指针，开关状态，方框颜色*/
	  RectangleXY rectangle;
    u8 x=rectanglexy->sx;
    u8 y=rectanglexy->sy;
    u8 width=rectanglexy->width;
    u8 height=rectanglexy->height;
   
	  rectangle.sx=x+2;
    rectangle.sy=y+2;
	
	  if(switchStatus==OFF){
		    component.pageButton(rectangle.sx,rectangle.sy,30,20,"ON",White,Black);
        component.pageButton(rectangle.sx+30,rectangle.sy,30,20,"OFF",Blue_100,White);
		}else if(switchStatus==ON){
		    component.pageButton(rectangle.sx,rectangle.sy,30,20,"ON",Blue_100,White);
        component.pageButton(rectangle.sx+30,rectangle.sy,30,20,"OFF",White,Black);
		}   
		
    DisAPI.gui_4_yuanhu_EMPTY(x,y,x+width,y+height,1,color);//在switch周边画一个方框
}

u8 getMAXofArray(u8 *buf,u8 arrayLen){/*获取数组的最大值，arrayLen为数组长度*/
	/*用在获取长的延时时间*/
   u8 i;
	 u16 MAX;
    for(i=0;i<arrayLen-1;i++){
		   if(buf[i]>buf[i+1])//将最大的数据移到数组末尾
			 buf[i+1]=buf[i];
			 }
		MAX=buf[arrayLen-1];
   return MAX;
}

