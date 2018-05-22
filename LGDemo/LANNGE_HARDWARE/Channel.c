#include "Channel.h"
#include "sys.h"


Channel channel= {initChannel,sequenceToDelayOpenClose,0,getflashChannel,CLOSE};
void initChannel()
{

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				 //控制继电器的三极管
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

}
void setCH(u8 CHEN)
{
    switch(CHEN)
        {
        case 1:
            if(EnCH1) SetCH1;
            break;
        case 2:
            if(EnCH2) SetCH2;
            break;
        case 3:
            if(EnCH3) SetCH3;
            break;
        case 4:
            if(EnCH4) SetCH4;
            break;
        case 5:
            if(EnCH5) SetCH5;
            break;
        case 6:
            if(EnCH6) SetCH6;
            break;
        case 7:
            if(EnCH7) SetCH7;
            break;
        case 8:
            if(EnCH8) SetCH8;
            break;
        }
}
void resetCH(u8 CHEN)
{
    switch(CHEN)
        {
        case 1:
            ResetCH1;
            break;
        case 2:
            ResetCH2;
            break;
        case 3:
            ResetCH3;
            break;
        case 4:
            ResetCH4;
            break;
        case 5:
            ResetCH5;
            break;
        case 6:
            ResetCH6;
            break;
        case 7:
            ResetCH7;
            break;
        case 8:
            ResetCH8;
            break;
        }
}

u8 sequenceToDelayOpenClose(u8* actionStatus) //
{
    u8 static sec=0;
    u8 static openAnchor=0;
    u8 static openLastAnchor=0;
    u8 static closeAnchor=0;
    u8 static closeLastAnchor=0;
	  u8 buf[8];
	  u8 closebuf[8];
	  buf[0]=delayActivity.chan_open_data->chan1+1;
	  buf[1]=delayActivity.chan_open_data->chan2+1;
	  buf[2]=delayActivity.chan_open_data->chan3+1;
	  buf[3]=delayActivity.chan_open_data->chan4+1;
		buf[4]=delayActivity.chan_open_data->chan5+1;
	  buf[5]=delayActivity.chan_open_data->chan6+1;
	  buf[6]=delayActivity.chan_open_data->chan7+1;
	  buf[7]=delayActivity.chan_open_data->chan8+1;
	
	  closebuf[0]=delayActivity.chan_close_data->chan1+1;
	  closebuf[1]=delayActivity.chan_close_data->chan2+1;
	  closebuf[2]=delayActivity.chan_close_data->chan3+1;
	  closebuf[3]=delayActivity.chan_close_data->chan4+1;
		closebuf[4]=delayActivity.chan_close_data->chan5+1;
	  closebuf[5]=delayActivity.chan_close_data->chan6+1;
	  closebuf[6]=delayActivity.chan_close_data->chan7+1;
	  closebuf[7]=delayActivity.chan_close_data->chan8+1;
	if(calendar.flag_one_sec==1&&(*actionStatus&0xF0)==0x10)
        {
            calendar.flag_one_sec=0;
            sec++;
        }
    if(relay_key()==RE_KEY_DOWN)
        {
            if((*actionStatus&0x0F)==CLOSE)
                {
                    *actionStatus=OPEN|0x10;//标记进入通道延时打开
									  openAnchor=0;
                    sec=0;
                }
            else if((*actionStatus&0x0F)==OPEN)
                {
                    *actionStatus=CLOSE|0x10;//标记进入通道延时关闭
									  closeAnchor=0;
                    sec=0;
                }
        }

    if((*actionStatus&0x0F)==OPEN)
        {
            if((*actionStatus&0xF0)==0x10)
                {

                    if(buf[0]==sec)
                        {
                            setCH(1);
                            openAnchor=1;
                        }
                      if(buf[1]==sec)
                        {
                            setCH(2);
                            openAnchor=2;
                        }
                     if(buf[2]==sec)
                        {
                            setCH(3);
                            openAnchor=3;
                        }
                     if(buf[3]==sec)
                        {
                            setCH(4);
                            openAnchor=4;
                        }
                     if(buf[4]==sec)
                        {
                            setCH(5);
                            openAnchor=5;
                        }
                     if(buf[5]==sec)
                        {
                            setCH(6);
                            openAnchor=6;
                        }
                     if(buf[6]==sec)
                        {
                            setCH(7);
                            openAnchor=7;

                        }
                    if(buf[7]==sec)
                        {
                            setCH(8);
                            openAnchor=8;
                      

                        }
											if(component.getMAXofArray(buf,sizeof(buf)/sizeof(buf[0]))==sec){/*当延时时间最长的CHANNEL执行后取消标记进入通道延时打开*/
											     // component.pageEditText(35,70,40,20,sec,White,Black);
											      *actionStatus=OPEN;
											}
												
                    if(openAnchor!=openLastAnchor)
                        {
                            openLastAnchor=openAnchor;
                             return sec;//返回秒数
                        }
                    else return 0;
                }

        }

    if((*actionStatus&0x0F)==CLOSE)
        {
            if((*actionStatus&0xF0)==0x10)
                {
                    if(delayActivity.chan_close_data->chan1+1==sec)
                        {

                            resetCH(1);
                            closeAnchor=1;
                        }
                    if(delayActivity.chan_close_data->chan2+1==sec)
                        {
                            resetCH(2);
                            closeAnchor=2;
                        }
                    if(delayActivity.chan_close_data->chan3+1==sec)
                        {
                            resetCH(3);
                            closeAnchor=3;
                        }
                    if(delayActivity.chan_close_data->chan4+1==sec)
                        {
                            resetCH(4);
                            closeAnchor=4;
                        }
                    if(delayActivity.chan_close_data->chan5+1==sec)
                        {
                            resetCH(5);
                            closeAnchor=5;
                        }
                    if(delayActivity.chan_close_data->chan6+1==sec)
                        {
                            resetCH(6);
                            closeAnchor=6;
                        }
                    if(delayActivity.chan_close_data->chan7+1==sec)
                        {
                            resetCH(7);
                            closeAnchor=7;
                        }
                    if(delayActivity.chan_close_data->chan8+1==sec)
                        {
                            resetCH(8);
                            closeAnchor=8;
                        }
									 if(component.getMAXofArray(closebuf,sizeof(closebuf)/sizeof(closebuf[0]))==sec){/*当延时时间最长的CHANNEL执行后取消标记进入通道延时打开*/
											//component.pageEditText(35,35,40,20,sec,White,Black);
											                *actionStatus=CLOSE;
										
											}
									  
                    if(closeAnchor!=closeLastAnchor)
                        {
                            closeLastAnchor=closeAnchor;
                            return sec;//返回秒数
                        }
												
                    else return 0;

                }
        }
    return 0;
}
u8 getflashChannel() //返回需要刷新的CHANNEL
{
    return channel.flashChannel;
}

