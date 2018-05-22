#include "UVOVActivity.h"

UVOVActivity uvovActivity= {uvovActivityPage,uvovActivityItemSelect,saveUVOVData,readUVOVData,uvovProtection,0};
Rectangle uvovXY[7];
_uv_ov_data uv_ov_data= {10,85,OFF,265,OFF,};
_uv_ov_data _uv_ov_tempdata;
u8 channelStatus=0;//将过压事件发生时，扫描通道保存通道内状态在这个字节里面；
void uvovActivityPage()
{

    if(activity.activeActivity==activity.UVOV)
        {

            _uv_ov_tempdata=uv_ov_data;
            component.titleBar();
            uvovXY[0].xyStructuee=component.pageSpinner(10,0,70,30,"UVOV",Blue,White,DOWN);
            uvovXY[1].xyStructuee=component.horizontaladderSubtracter(5,55,40,20,50,20,20,"RV",_uv_ov_tempdata.rdv);
            uvovXY[2].xyStructuee=component.horizontaladderSubtracter(5,85,40,20,50,20,20,"OV",_uv_ov_tempdata.ov);
            uvovXY[3].xyStructuee=component.pageswitch(140,85,5,20,"1",_uv_ov_tempdata.ov_state,Black,Black);
            uvovXY[4].xyStructuee=component.horizontaladderSubtracter(5,115,40,20,50,20,20,"UV",_uv_ov_tempdata.uv);
            uvovXY[5].xyStructuee=component.pageswitch(140,115,5,20,"1",_uv_ov_tempdata.uv_state,Black,Black);
            component.clear(0,157,220,18,Blue);
            uvovXY[6].xyStructuee=component.pageButton(170,157,40,18,"SAVE",Blue,White);
        }
    uvovActivityAction();

}

void uvovActivityAction()
{

    while(activity.activeActivity==activity.UVOV)
        {
            activity.flashTime();
            uvovActivityItemSelect();
        }


}

void uvovActivityItemSelect()
{
    u8 state=encoder();
    u8 static anchor=0;
    u8 static encoderAddSubflag=0;
    u8 static lastanchor=0;
    u8 screenaddsubsatus_2=activity.scanAddSubstruct(uvovXY[1].xyStructuee.sx,uvovXY[1].xyStructuee.sy,uvovXY[1].xyStructuee.width,uvovXY[1].xyStructuee.height);
    u8 screenaddsubsatus_3=activity.scanAddSubstruct(uvovXY[2].xyStructuee.sx,uvovXY[2].xyStructuee.sy,uvovXY[2].xyStructuee.width,uvovXY[2].xyStructuee.height);
    u8 screenaddsubsatus_5=activity.scanAddSubstruct(uvovXY[4].xyStructuee.sx,uvovXY[4].xyStructuee.sy,uvovXY[4].xyStructuee.width,uvovXY[4].xyStructuee.height);


    u8 addsubsatus=activity.encoderToAddSub(&encoderAddSubflag,&state);
    if(encoderAddSubflag)
        state=0;

    if(screenaddsubsatus_2==ADD||screenaddsubsatus_2==SUB)anchor=2;
    if(screenaddsubsatus_3==ADD||screenaddsubsatus_3==SUB)anchor=3;
    if(screenaddsubsatus_5==ADD||screenaddsubsatus_5==SUB)anchor=5;
    switch(addsubsatus|screenaddsubsatus_2|screenaddsubsatus_3|screenaddsubsatus_5)
        {
        case ADD:

            if((addsubsatus==ADD&&anchor==2)||screenaddsubsatus_2==ADD)
                {

                    if(_uv_ov_tempdata.rdv<20)
                        _uv_ov_tempdata.rdv++;
                }

            if((addsubsatus==ADD&&anchor==3)||screenaddsubsatus_3==ADD)
                {

                    if(_uv_ov_tempdata.ov<265)
                        _uv_ov_tempdata.ov++;
                }

            if((addsubsatus==ADD&&anchor==5)||screenaddsubsatus_5==ADD)
                {

                    if(_uv_ov_tempdata.uv<210)
                        _uv_ov_tempdata.uv++;
                }
            flashUVOVItem(anchor,lastanchor);
            lastanchor=anchor;
            break;
        case SUB:

            if((addsubsatus==SUB&&anchor==2)||screenaddsubsatus_2==SUB)
                {
                    if(_uv_ov_tempdata.rdv>5)
                        _uv_ov_tempdata.rdv--;
                }

            if((addsubsatus==SUB&&anchor==3)||screenaddsubsatus_3==SUB)
                {
                    if(_uv_ov_tempdata.ov>230)
                        _uv_ov_tempdata.ov--;
                }
            if((addsubsatus==SUB&&anchor==5)||screenaddsubsatus_5==SUB)
                {
                    if(_uv_ov_tempdata.uv>85)
                        _uv_ov_tempdata.uv--;
                }
            flashUVOVItem(anchor,lastanchor);
            lastanchor=anchor;
            break;
        }



    if(activity.toucharea(10,0,70,30,1)==1)
        {
            anchor=1;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(uvovXY[1].xyStructuee.sx,uvovXY[1].xyStructuee.sy,
                          uvovXY[1].xyStructuee.width,uvovXY[1].xyStructuee.height,2)==2)
        {
            anchor=2;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(uvovXY[2].xyStructuee.sx,uvovXY[2].xyStructuee.sy,
                          uvovXY[2].xyStructuee.width,uvovXY[2].xyStructuee.height,3)==3)
        {
            anchor=3;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(uvovXY[3].xyStructuee.sx,uvovXY[3].xyStructuee.sy,
                          uvovXY[3].xyStructuee.width,uvovXY[3].xyStructuee.height,4)==4)
        {
            anchor=4;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(uvovXY[4].xyStructuee.sx,uvovXY[4].xyStructuee.sy,
                          uvovXY[4].xyStructuee.width,uvovXY[4].xyStructuee.height,5)==5)
        {
            anchor=5;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(uvovXY[5].xyStructuee.sx,uvovXY[5].xyStructuee.sy,
                          uvovXY[5].xyStructuee.width,uvovXY[5].xyStructuee.height,6)==6)
        {
            anchor=6;
            state=EN_KEY_DOWN;
        }
    if(activity.toucharea(uvovXY[6].xyStructuee.sx,uvovXY[6].xyStructuee.sy,
                          uvovXY[6].xyStructuee.width,uvovXY[6].xyStructuee.height,7)==7)
        {
            anchor=7;
            state=EN_KEY_DOWN;
        }
    switch(state)
        {
        case TURN_L:
            if(anchor<7)
                flashUVOVItem(++anchor,lastanchor);
            lastanchor=anchor;
            break;
        case TURN_R:
            if(anchor>1)
                flashUVOVItem(--anchor,lastanchor);
            lastanchor=anchor;
            break;
        case EN_KEY_DOWN:
            if(anchor==1)
                {
                    activity.activeActivity=activity.SPINNER;
                    anchor=0;
                }
            else if(anchor==2|anchor==3|anchor==5)
                {
                    encoderAddSubflag=1;

                }
            else if(anchor==4)
                {

                    if(_uv_ov_tempdata.ov_state==OFF) _uv_ov_tempdata.ov_state=ON;
                    else if(_uv_ov_tempdata.ov_state==ON) _uv_ov_tempdata.ov_state=OFF;

                    component.emptyRectangle(&(uvovXY[3].xyStructuee),_uv_ov_tempdata.ov_state,White);
                    encoderAddSubflag=0;
                }
            else if(anchor==6)
                {

                    if(_uv_ov_tempdata.uv_state==OFF) _uv_ov_tempdata.uv_state=ON;
                    else if(_uv_ov_tempdata.uv_state==ON) _uv_ov_tempdata.uv_state=OFF;
                    component.emptyRectangle(&(uvovXY[5].xyStructuee),_uv_ov_tempdata.uv_state,White);
                    encoderAddSubflag=0;
                }
            else if(anchor==7)
                {
                    uvovActivity.saveUVOVData();
                    component.pageButton(70,157,60,18,"SUCCESS",Blue,White);//提示保存成功信息
                    delay_ms(1000);
                    component.pageButton(70,157,60,18,"SUCCESS",Blue,Blue);
                    encoderAddSubflag=0;
                }
            if(anchor!=7)
                {
                    flashUVOVItem(anchor,lastanchor);
                    lastanchor=anchor;
                }
            break;
        }

}
void flashUVOVItem(u8 anchor,u8 lastanchor)
{
    switch(anchor)
        {
        case 1:
            component.pageSpinner(10,0,70,30,"UVOV",Blue,Blue_100,DOWN);
            break;
        case 2:
            component.flashData(&uvovXY[1],_uv_ov_tempdata.rdv,Blue_100,Black);
            break;
        case 3:
            component.flashData(&uvovXY[2],_uv_ov_tempdata.ov,Blue_100,Black);
            break;
        case 4:
            component.emptyRectangle(&(uvovXY[3].xyStructuee),_uv_ov_tempdata.ov_state,White);
            break;
        case 5:
            component.flashData(&uvovXY[4],_uv_ov_tempdata.uv,Blue_100,Black);
            break;
        case 6:
            component.emptyRectangle(&(uvovXY[5].xyStructuee),_uv_ov_tempdata.uv_state,White);
            break;
        case 7:
            component.flashChar(&uvovXY[6],"SAVE",Blue_100,White);
            break;
        }
    if(anchor!=lastanchor)
        {
            switch(lastanchor)
                {
                case 1:
                    component.pageSpinner(10,0,70,30,"UVOV",Blue,White,DOWN);
                    break;
                case 2:
                    component.flashData(&uvovXY[1],_uv_ov_tempdata.rdv,White,Black);
                    break;
                case 3:
                    component.flashData(&uvovXY[2],_uv_ov_tempdata.ov,White,Black);
                    break;
                case 4:
                    component.emptyRectangle(&(uvovXY[3].xyStructuee),_uv_ov_tempdata.ov_state,Black);
                    break;
                case 5:
                    component.flashData(&uvovXY[4],_uv_ov_tempdata.uv,White,Black);
                    break;
                case 6:
                    component.emptyRectangle(&(uvovXY[5].xyStructuee),_uv_ov_tempdata.uv_state,Black);
                    break;
                case 7:
                    component.flashChar(&uvovXY[6],"SAVE",Blue,White);
                    break;
                }
        }

}
void saveUVOVData()
{

    uv_ov_data=_uv_ov_tempdata;
    AT24CXX_Write(16,&uv_ov_data.rdv,1);
    AT24CXX_Write(17,&uv_ov_data.uv,1);
    AT24CXX_Write(18,&uv_ov_data.uv_state,1);
    AT24CXX_WriteLenByte(19,(u32*)&uv_ov_data.ov,2);
    AT24CXX_Write(21,&uv_ov_data.ov_state,1);

}
void readUVOVData()
{

    AT24CXX_Read(16,&uv_ov_data.rdv,1);
    AT24CXX_Read(17,&uv_ov_data.uv,1);
    AT24CXX_Read(18,&uv_ov_data.uv_state,1);
    AT24CXX_ReadLenByte(19,(u32*)&uv_ov_data.ov,2);
    AT24CXX_Read(21,&uv_ov_data.ov_state,1);

}


u8 uvovProtection(u32* adcVal)
{
    /*过压欠压函数*/

    u8  tempval;
    /*高压计算模式*/
    tempval=(*adcVal)*236/5440;
    /*低压计算模式*/
    if(tempval<150)
        {
            tempval=(*adcVal)*120/2676;
        }
    /*超过阈值*/
    if(tempval<uv_ov_data.uv)
        {
            /*判断功能状态*/
            if(uv_ov_data.uv_state)
                {
                    uvovActivity.alarmEvent=OVER;//超过阈值标志位
                }
        }

    if(uv_ov_data.ov<tempval)
        {
            /*判断功能状态*/
            if(uv_ov_data.ov_state)
                {
                    uvovActivity.alarmEvent=UNDER;//超过阈值标志位
                }

        }
    if(uv_ov_data.ov_state==OFF&&uv_ov_data.uv_state==OFF)
        {
            uvovActivity.alarmEvent=0;
        }
    if(uvovActivity.alarmEvent==OVER)
        {
            /*回差值满足条件，取消保护功能*/
            if(uv_ov_data.uv_state)
                {
                    if((uv_ov_data.uv+uv_ov_data.rdv)<tempval)
                        {
                            uvovActivity.alarmEvent=0;
                            //relay_key_dev.relay_key_state=RE_KEY_DOWN;//当有警告消除延时打开通道

                        }
                }
        }
    if(uvovActivity.alarmEvent==UNDER)
        {
            if(uv_ov_data.ov_state)
                {
                    if(tempval<(uv_ov_data.ov-uv_ov_data.rdv))
                        {
                            uvovActivity.alarmEvent=0;
                            //relay_key_dev.relay_key_state=RE_KEY_DOWN;//当有警告消除延时打开通道
                        }
                }
        }
    return uvovActivity.alarmEvent;//返回警告事件
}
void protect()
{

//    u8 static lastAlarmstatus=0;//记录是否发生欠压或过压事件
//    switch(uvovActivity.uvovProtection(220))
//        {
//        case OVER:
//            lastAlarmstatus=OVER;
//            break;
//        case UNDER:
//            lastAlarmstatus=UNDER;
//            break;
//        case 0:
//            lastAlarmstatus=0;

//            break;
//        }

}
u8 saveChannel(void)
{
    u8 channelstatus=0;
    if(ReadCH1)
        {
					channelstatus|=0x01;
        }
    if(ReadCH2)
        {
					channelstatus|=0x02;
        }
		if(ReadCH3)
        {
					channelstatus|=0x04;
        }
		if(ReadCH4)
        {
					channelstatus|=0x08;
        }
    if(ReadCH5)
        {
					channelstatus|=0x10;
        }
    if(ReadCH6)
        {
					channelstatus|=0x20;
        }
		if(ReadCH7)
        {
					channelstatus|=0x40;
        }
		if(ReadCH8)
        {
					channelstatus|=0x80;
        }
				return channelstatus;
}

