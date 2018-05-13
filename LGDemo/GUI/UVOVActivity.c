#include "UVOVActivity.h"

UVOVActivity uvovActivity= {uvovActivityPage,uvovActivityItemSelect};

void uvovActivityPage()
{

    if(activity.activeActivity==activity.UVOV)
        {
            component.titleBar();
            component.pageSpinner(10,0,70,30,"UVOV",Blue,White,DOWN);
            component.horizontaladderSubtracter(5,55,40,20,50,20,20,"RV","20");
            component.horizontaladderSubtracter(5,85,40,20,50,20,20,"OV","265");
            component.pageswitch(140,85,5,20,"1",Black,Black);
            component.horizontaladderSubtracter(5,115,40,20,50,20,20,"UV","85");
            component.pageswitch(140,115,5,20,"1",Black,Black);
        }
    uvovActivityAction();

}

void uvovActivityAction()
{

    while(activity.activeActivity==activity.UVOV)
        {
            uvovActivityItemSelect();
        }


}

void uvovActivityItemSelect()
{
    u8 state=encoder();
    u8 static anchor=0;
    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    switch(state)
        {
        case TURN_L:
            if(anchor==0)
                {
                    anchor=1;
                    component.pageSpinner(10,0,70,30,"UVOV",Blue,Blue_100,DOWN);
                }
            break;
        case TURN_R:
            if(anchor==0)
                {
                    anchor=1;
                    component.pageSpinner(10,0,70,30,"UVOV",Blue,Blue_100,DOWN);
                }
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
                    anchor=0;
                }
            break;
        }

}
