#include "PageSpinnerActivity.h"

PageSpinnerActivity SpinnerActivity= {pageSpinnerActivity,pageSpinnerActivityAction,showotherItem};
char* otherPage[5]={"TIME","PWD","UVOV","IP","AUZ"};
char* itemName[] = {"HOME","DELAY","SWITCH","TIMER","OTHER"};
void pageSpinnerActivity()
{

    if(activity.activeActivity==activity.SPINNER)
        {
            component.ShowpageSpinner(1);
        }
      pageSpinnerActivityAction();
}

void pageSpinnerActivityAction()
{


    while(activity.activeActivity==activity.SPINNER)
        {
            //系统必要执行函数
					 activity.executeInWhile();
            spinnerAction();
        }

}
void spinnerAction()
{

    u8 actionSta=encoder();
    u8 static anchor=0;
    u8 static spinner_0=0;//标志otherSpinner是否已经打开
    if(activity.toucharea(0,32,80,20,1)==1)
        {
            anchor=1;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(0,54,80,20,2)==2)
        {
            anchor=2;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(0,76,80,20,3)==3)
        {
            anchor=3;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(0,98,80,20,4)==4)
        {
            anchor=4;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(0,120,80,20,5)==5)
        {
            anchor=5;
            actionSta=EN_KEY_DOWN;
        }
		if(activity.toucharea(85,50,70,20,6)==6&&spinner_0==1)
        {
            anchor=6;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(85,72,70,20,7)==7&&spinner_0==1)
        {
            anchor=7;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(85,94,70,20,8)==8&&spinner_0==1)
        {
            anchor=8;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(85,116,70,20,9)==9&&spinner_0==1)
        {
            anchor=9;
            actionSta=EN_KEY_DOWN;
        }
    if(activity.toucharea(85,136,70,20,10)==10&&spinner_0==1)
        {
            anchor=10;
            actionSta=EN_KEY_DOWN;
        }
   	
    switch(actionSta)
        {

        case TURN_L:
            if(anchor==0)
                {
                    anchor=1;
									  showItem(0,32,80,20,itemName,0,Blue_100);								 
                }
            else if(anchor==1)
                {
                    anchor=2;
									  showItem(0,32,80,20,itemName,0,Blue_50);	
									  showItem(0,32,80,20,itemName,1,Blue_100);	
                }
            else if(anchor==2)
                {
                    anchor=3;
									  showItem(0,32,80,20,itemName,1,Blue_50);	
									  showItem(0,32,80,20,itemName,2,Blue_100);	
                }
            else if(anchor==3)
                {
                    anchor=4;
									  showItem(0,32,80,20,itemName,2,Blue_50);	
									  showItem(0,32,80,20,itemName,3,Blue_100);	
                }
            else if(anchor==4)
                {																	  
                    anchor=5;
									  showItem(0,32,80,20,itemName,3,Blue_50);	
									  showItem(0,32,80,20,itemName,4,Blue_100);	
									  
                }
						else if(anchor==5&&spinner_0==1)
                {
									  showotherItem(85,50,70,20,otherPage,0,Blue_100);
									  showItem(0,32,80,20,itemName,4,Blue_50);	
                    anchor=6;
                }
            else if(anchor==6)
                {
                    anchor=7;
									  showotherItem(85,50,70,20,otherPage,0,Blue_50);
					          showotherItem(85,50,70,20,otherPage,1,Blue_100);
                }
            else if(anchor==7)
                {								  
                    anchor=8;
									  showotherItem(85,50,70,20,otherPage,1,Blue_50);
					          showotherItem(85,50,70,20,otherPage,2,Blue_100);
									
                }
            else if(anchor==8)
                {
                    anchor=9;
										showotherItem(85,50,70,20,otherPage,2,Blue_50);
				          	showotherItem(85,50,70,20,otherPage,3,Blue_100);
									
                }
            else if(anchor==9)
                {
                    anchor=10;
									  showotherItem(85,50,70,20,otherPage,3,Blue_50);
					          showotherItem(85,50,70,20,otherPage,4,Blue_100);								
                }

            break;
        case TURN_R:
            if(anchor==0)
                {
                    anchor=1;
									  showItem(0,32,80,20,itemName,0,Blue_100);
                }
            else if(anchor==2)
                {
                    anchor=1;
									 showItem(0,32,80,20,itemName,0,Blue_100);	
									 showItem(0,32,80,20,itemName,1,Blue_50);	
                }
            else if(anchor==3)
                {
                    anchor=2;
									  showItem(0,32,80,20,itemName,2,Blue_50);	
									  showItem(0,32,80,20,itemName,1,Blue_100);	
                }
            else if(anchor==4)
                {
                    anchor=3;
									  showItem(0,32,80,20,itemName,3,Blue_50);	
									  showItem(0,32,80,20,itemName,2,Blue_100);	
                }
            else if(anchor==5)
                {
									  showItem(0,32,80,20,itemName,4,Blue_50);	
									  showItem(0,32,80,20,itemName,3,Blue_100);	
                    anchor=4;
                }
            else if(anchor==6)
                {
									  showotherItem(85,50,70,20,otherPage,0,Blue_50);
									  showItem(0,32,80,20,itemName,4,Blue_100);	
                    anchor=5;
                }
            else if(anchor==7)
                {
									 	showotherItem(85,50,70,20,otherPage,1,Blue_50);
					          showotherItem(85,50,70,20,otherPage,0,Blue_100);
                    anchor=6;
                }
            else if(anchor==8)
                {
									 	showotherItem(85,50,70,20,otherPage,2,Blue_50);
					          showotherItem(85,50,70,20,otherPage,1,Blue_100);
                    anchor=7;
                }
            else if(anchor==9)
                {
										showotherItem(85,50,70,20,otherPage,3,Blue_50);
					          showotherItem(85,50,70,20,otherPage,2,Blue_100);
                    anchor=8;
                }
            else if(anchor==10)
                {
										showotherItem(85,50,70,20,otherPage,4,Blue_50);
					          showotherItem(85,50,70,20,otherPage,3,Blue_100);
                    anchor=9;
                }
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                   activity.activeActivity=activity.HOME;
									 anchor=0;
									 spinner_0=0;
                }
            else if(anchor==2)
                {
                   activity.activeActivity=activity.DELAY;
									 anchor=0;
									 spinner_0=0;
                }
            else if(anchor==3)
                {
                   activity.activeActivity=activity.SWITCH;
									 anchor=0;
									spinner_0=0;
                }
            else if(anchor==4)
                {
                 activity.activeActivity=activity.TIMER;
									 anchor=0;
									spinner_0=0;
                }
            else if(anchor==5)
                {
									
									  showItem(0,32,80,20,itemName,4,Blue_50);		
           								
									  component.ShowpageSpinner(0);
									           showotherItem(85,50,70,20,otherPage,0,Blue_100);	
									  spinner_0=1;
                    anchor=6;
									  delay_ms(400);
                }
            else if(anchor==6)
                {
                   activity.activeActivity=activity.TIME;
									 anchor=0;
									spinner_0=0;
                }
            else if(anchor==7)
                {
                   activity.activeActivity=activity.PWD;
									 anchor=0;
									spinner_0=0;
                }
            else if(anchor==8)
                {
                   activity.activeActivity=activity.UVOV;
									 anchor=0;
									spinner_0=0;
                }
            else if(anchor==9)
                {
                   activity.activeActivity=activity.IP;
									 anchor=0;
									spinner_0=0;
                }
            else if(anchor==10)
                {
                   activity.activeActivity=activity.AUZ;
									 anchor=0;
									spinner_0=0;
                }
            break;
							
        }
}

void showotherItem(u8 x,u8 y,u8 width,u8 height,char* itemName[],u8 index,u16 corlor)
{
    Fill_Fast_Rec(x,y+(height+2)*index,width,height,corlor);
    Write_Word_Center(x,y+(height+2)*index,x+width,y+height+(height+2)*index,16,itemName[index],Black);
}

void showItem(u8 x,u8 y,u8 width,u8 height,char* itemName[],u8 index,u16 corlor)
{

    Fill_Fast_Rec(x,y+(height+2)*index,width,height,corlor);
    Write_Word_Center(x,y+(height+2)*index,x+width,y+height+(height+2)*index,16,itemName[index],Black);
    if(index==4)
        {
            DisAPI.LCD_DrawLtrigo(65,125,75,135,Black,RIGHT);
        }

}
