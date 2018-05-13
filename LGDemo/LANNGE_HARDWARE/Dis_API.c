#include "Dis_API.h"

_DisAPI DisAPI={Fill_Fast_Rec,TFT_ShowString,Write_Word_Center,TFT_ShowNum,gui_draw_arc,gui_4_yuanhu_EMPTY,LCD_DrawLtrigo,TFT_Show_Any_Picture};

//液晶初始化
void TFT_init(void)
{
    TFT_FSMC_INIT();
    delay_ms(50);
    TFT_RST=1;
    delay_ms(100);
    TFT_RST=0;
    delay_ms(300);
    TFT_RST=1;
    delay_ms(100);

    LCD_WR_REG_DATA(0x01, 0x011C); // 0x011c set SS and NL bit    扫描方向,使用多少行
    LCD_WR_REG_DATA(0x02, 0x0100); // set 1 line inversion   扫描模式
    LCD_WR_REG_DATA(0x03, 0x1020); // set GRAM write direction an d BGR=1.    扫描方向
    LCD_WR_REG_DATA(0x08, 0x0808); // set BP and FP?
    LCD_WR_REG_DATA(0x0C, 0x0000); // RGB interface setting R0Ch=0x0110 for RGB 18Bit and R0Ch=0111 for RGB 16Bit
    LCD_WR_REG_DATA(0x0F, 0x0801); // Set frame rate
    LCD_WR_REG_DATA(0x20, 0x0000); // Set GRAM Address
    LCD_WR_REG_DATA(0x21, 0x0000); // Set GRAM Address
    //*************Power On sequence ****************//
    delay_ms(5); // Delay 50ms
    LCD_WR_REG_DATA(0x10, 0x0A00); // Set SAP,DSTB（睡眠模式设置位，控制内部电源）,STB（睡眠模式设置位，控制内部晶振）
    LCD_WR_REG_DATA(0x11, 0x103B); // Set APON,PON,AON,VCI1EN,VC
    delay_ms(5); // Delay 50ms
    LCD_WR_REG_DATA(0x12, 0x6121); // Internal reference voltage= Vci;
    LCD_WR_REG_DATA(0x13, 0x006F); // Set GVDD(VREG1OUT),为什么为4.68V这个电压值
    LCD_WR_REG_DATA(0x14, 0x3745); // 345d ok Set VCOMH/VCOML voltage  4440 4d50，VCOMH=4.1184,VCOM=2.2464,VCOMH，VCOM这两个值与屏的哪些现象有关系
    //------------------------ Set GRAM area --------------------------------//
    LCD_WR_REG_DATA (0x30, 0x0000);//显示起始行设定
    LCD_WR_REG_DATA (0x31, 0x00DB);//垂直滚动显示的结束地址设定
    LCD_WR_REG_DATA (0x32, 0x0000);//垂直滚动显示的开始地址设定
    LCD_WR_REG_DATA (0x33, 0x0000);//

    LCD_WR_REG_DATA (0x34, 0x00DB);//设定显示的结束行，SE1(7:0)
    LCD_WR_REG_DATA (0x35, 0x0000);//设定显示的开始行，SS1(7:0)

    LCD_WR_REG_DATA (0x36, 0x00AF);//设定显示结束的列，HEA(7:0)
    LCD_WR_REG_DATA (0x37, 0x0000);//设定显示开始的列，HSA(7:0)
    LCD_WR_REG_DATA (0x38, 0x00DB);//设定显示结束的行，VEA(7:0)
    LCD_WR_REG_DATA (0x39, 0x0000);//设定显示开始的行，VSA(7:0)
    // ----------- Adjust the Gamma Curve ----------//
    LCD_WR_REG_DATA(0x50, 0x0400);
    LCD_WR_REG_DATA(0x51, 0x080B);
    LCD_WR_REG_DATA(0x52, 0x0E0C);//0x50~0x52,The gamma fine adjustoment register for the positive polarity output
    LCD_WR_REG_DATA(0x53, 0x0103);//The gradient adjustment register for the positive polarity output.(对于阳极梯度调整寄存器）
    LCD_WR_REG_DATA(0x54, 0x0C0E);
    LCD_WR_REG_DATA(0x55, 0x0B08);
    LCD_WR_REG_DATA(0x56, 0x0004);//0x54~0x56,The gamma fine adjustment register for the negative polarity output.
    LCD_WR_REG_DATA(0x57, 0x0301);//The gradient adjustment register for the negative polarity output
    LCD_WR_REG_DATA(0x58, 0x0E00);//The amplitude adjustment register for the negative polarity output
    LCD_WR_REG_DATA(0x59, 0x000E);//The amplitude adjustment register for the negative polarity output, //CMO玻璃
    delay_ms(5); // Delay 50ms
    LCD_WR_REG_DATA(0x07, 0x1017);
    delay_ms(20);

}
//镜面对称
void Mirro_Y(u16 *y_pos)
{
    *y_pos=176-*y_pos;
}
//开窗
void OPEN_WINDOW(u16 x,u16 y,u16 x_width,u16 y_height)
{
    u16 Y_POS,Y_POS_H;

    Y_POS_H=y+y_height;
    Y_POS=y;

    Mirro_Y(&Y_POS_H);
    Mirro_Y(&Y_POS);

    LCD_WR_REG(0x36);
    LCD_WR_DATA(Y_POS);
    LCD_WR_REG(0x37);
    LCD_WR_DATA(Y_POS_H);
    LCD_WR_REG(0x38);
    LCD_WR_DATA(x+x_width);
    LCD_WR_REG(0x39);
    LCD_WR_DATA(x);
}
//填充颜色
void Fill_Fast_Rec(u16 x,u16 y,u16 x_wight,u16 y_height,u16 color)
{
    u8  h,v;
    u16 Y_POS_HEIGHT;
    OPEN_WINDOW(x,y,x_wight,y_height);

    Y_POS_HEIGHT=y+y_height;
    Mirro_Y(&Y_POS_HEIGHT);
    LCD_WR_REG_DATA(0x20,Y_POS_HEIGHT);
    LCD_WR_REG_DATA(0x21,x);
    LCD_WR_REG(0x22);
    for(v=0; v<x_wight+1; v++)
        for(h=0; h<y_height+1; h++)
            LCD_WR_DATA(color);

}
//描点
void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
    OPEN_WINDOW(x,y,1,1);
    Mirro_Y(&y);
    LCD_WR_REG_DATA(0x20,y);
    LCD_WR_REG_DATA(0x21,x);
    LCD_WR_REG(0x22);
    LCD_WR_DATA(color);
}
//读点
u16 TFT_ReadPoint(u16 x,u16 y)
{
    u16 temp1,temp2;
    u16 TFT_COLOR;

    OPEN_WINDOW(x,y,1,1);
    Mirro_Y(&y);
    LCD_WR_REG_DATA(0x20,y);
    LCD_WR_REG_DATA(0x21,x);
    LCD_WR_REG(0x22);

    TFT_COLOR=LCD_RD_DATA();
    TFT_COLOR=LCD_RD_DATA();
    TFT_COLOR=0;
    TFT_COLOR=0;

    TFT_COLOR=LCD_RD_DATA();
    TFT_COLOR<<=8;
    TFT_COLOR|=LCD_RD_DATA();

    temp1=TFT_COLOR;
    temp2=TFT_COLOR;
    TFT_COLOR &= 0X07E0;
    temp1 <<=11;
    temp2 >>=11;
    TFT_COLOR=TFT_COLOR|temp1|temp2;
    return  TFT_COLOR;
}
void LCD_Clear(u16 corlor){
Fill_Fast_Rec(0,0,220,176,corlor);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*显示字符和数字*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//在指定的位置显示一个字符(x,y,char,size,color)
void TFT_Draw_One_Char(uint16_t x,uint16_t y,char word,uint8_t size,uint16_t color)
{
    uint8_t temp,Num,t=0,i,j,START_CHAR=1;

    Num=word-' ';//得到偏移后的值（ASCII字库是从空格开始取模，所以-' '就是对应字符的字库）
    if(size==16)temp=Font_16X8[Num][t]; 	 	//调用3216字体
    else if(size==24)temp=Font_24X12[Num][t];
    else if(size==32)temp=Font_32X16[Num][t];
    else return;//没有的字库
    for(j=0; j<(size/2); j++)
        {
            if((x+j)>=220)   return ;//横向Y超出区域了

            for(i=0; i<size; i++)
                {
                    if((i%8==0))//写好一个字节
                        {
                            if(START_CHAR==0)
                                {
                                    t++;
                                    if(size==16)temp=Font_16X8[Num][t]; 	 	//调用3216字体
                                    else if(size==24)temp=Font_24X12[Num][t];
                                    else if(size==32)temp=Font_32X16[Num][t];
                                }
                            if(START_CHAR)
                                START_CHAR=0;
                        }
                    if((y+i)>=176)   return ;//纵向X超出区域了

                    if(temp&0x01)//低位开始扫面进去
                        TFT_DrawPoint(x+j,y+i,color);
                    temp>>=1;
                }
        }
}
//显示字符串(x,y,)
void TFT_ShowString(uint16_t x,uint16_t y,char *p,uint8_t size,uint16_t color)
{

    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
        {
            TFT_Draw_One_Char(x,y,*p,size,color);
            x+=size/2;
            p++;
        }
}
//在矩形字框内中间写入不同size的字符
void Write_Word_Center(u16 sx,u16 sy,u16 ex,u16 ey,u8 size,char *p,u16 color)
{
	
	 
    u8 length;
    u16 total_len;
    u16 xs,ys;
    length=strlen(p);//测出字符串的长度
    total_len=length*(size/2);//算出字符总长度
    ys=sy+(ey-sy-size)/2;
    xs=sx+(ex-sx-total_len)/2;
    TFT_ShowString(xs,ys,p,size,color);
}
//显示数字，高位为0不显示
void TFT_ShowNum(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color)
{
    uint8_t data[6];
    uint8_t i,j,temp,start;

    data[0]=Num/100000;//十万
    data[1]=(Num%100000)/10000;//万
    data[2]=(Num%10000)/1000;//千
    data[3]=(Num%1000)/100;//百
    data[4]=(Num%100)/10;//十
    data[5]=Num%10;//个
    for(i=0; i<6; i++) //从高位开始，找出非0位置
        {
            if(data[i]==0)
                start=0;
            else
                {
                    start=1;//数据开始标志
                    break;//走出for循环
                }
        }
    temp=i;
    if(start==1)//数据非0
        {
            for(j=0; j<(6-temp); j++)
                TFT_Draw_One_Char(x+j*(size/2),y,data[i+j]+48,size,color);
        }
    else
        TFT_Draw_One_Char(x,y,48,size,color);
}
//显示一个带有小数点的数
void TFT_Show_OnePoint_Num(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color)
{
    uint8_t data[6];
    uint8_t i,j,temp,start;

    data[0]=Num/100000;//十万
    data[1]=(Num%100000)/10000;//万
    data[2]=(Num%10000)/1000;//千
    data[3]=(Num%1000)/100;//百
    data[4]=(Num%100)/10;//十
    data[5]=Num%10;//个
    for(i=0; i<6; i++) //从高位开始，找出非0位置
        {
            if(data[i]==0)
                start=0;
            else
                {
                    start=1;//数据开始标志
                    break;//走出for循环
                }
        }
    temp=i;
    if(start==1)//数据非0
        {
            if(Num>9)//数据大于1
                {
                    for(j=0; j<(5-temp); j++)
                        TFT_Draw_One_Char(x+j*(size/2),y,data[i+j]+48,size,color);//显示小数点前几位有效数据
                    TFT_Draw_One_Char(x+(5-temp)*(size/2),y,'.',size,color);
                    TFT_Draw_One_Char(x+(6-temp)*(size/2),y,data[5]+48,size,color);
                }
            else//数据少于1
                {
                    TFT_ShowString(x,y,"0.",size,color);
                    TFT_Draw_One_Char(x+size,y,data[5]+48,size,color);
                }
        }
    else// 数据为0
        TFT_ShowNum(x,y,Num,size,color);

}
//显示带有正负号的整数
void TFT_ZF_Num(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color)
{
    int JDZ;
    JDZ=abs(Num);
    if(Num>0)//大于0
        {
            TFT_Draw_One_Char(x,y,'+',size,color);
            TFT_ShowNum(x+size/2,y,Num,size,color);
        }
    else if(Num==0)//等于0
        TFT_ShowNum(x,y,Num,size,color);
    else//少于0
        {
            TFT_Draw_One_Char(x,y,'-',size,color);
            TFT_ShowNum(x+size/2,y,JDZ,size,color);
        }
}
//显示带有正负号的小数
void TFT_ZF_OnePoint_Num(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color )
{
    int JDZ;
    JDZ=abs(Num);
    if(Num>0)//大于等于0
        {
            TFT_Draw_One_Char(x,y,'+',size,color);
            TFT_Show_OnePoint_Num(x+size/2,y,Num,size,color);
        }
    else if(Num==0)//等于0
        TFT_ShowNum(x,y,Num,size,color);
    else//少于0
        {
            TFT_Draw_One_Char(x,y,'-',size,color);
            TFT_Show_OnePoint_Num(x+size/2,y,JDZ,size,color);
        }
}
//在矩形字框中间写入不同SIZE的Number
void Write_Num_Center(u16 sx,u16 sy,u16 ex,u16 ey,u8 size,int Num,u16 color,u8 ZF,u8 Point)
{
    u8 length;
    u16 total_len,xs,ys;
    uint8_t data[6];
    uint8_t i;
    int JDZ;

    JDZ=abs(Num);
    data[0]=JDZ/100000;//十万
    data[1]=(JDZ%100000)/10000;//万
    data[2]=(JDZ%10000)/1000;//千
    data[3]=(JDZ%1000)/100;//百
    data[4]=(JDZ%100)/10;//十
    data[5]=JDZ%10;//个
    for(i=0; i<6; i++) //从高位开始，找出非0位置
        {
            if(data[i]==0);
            else
                {
                    break;//走出for循环
                }
        }
    if(i<=5)length=6-i;
    else length=1;//算出多少位数字
    if(ZF==1)length++;//是否正负数
    if(Point==1)//是否小数
        {
            length++;
            if(JDZ<10)
                length++;
        }
    if(Num==0)length=1;
    total_len=length*(size/2);//算出字符总长度
//    xs=sx+(ex-sx-size)/2;
//    ys=sy+(ey-sy-total_len)/2;
    ys=sy+(ey-sy-size)/2;
    xs=sx+(ex-sx-total_len)/2;
    if((ZF==0)&&(Point==0))//一般整数
        TFT_ShowNum(xs,ys,Num,size,color);
    if((ZF==1)&&(Point==0))//带有正负号的整数
        TFT_ZF_Num(xs,ys,Num,size,color);
    if((ZF==0)&&(Point==1))//无符号小数
        TFT_Show_OnePoint_Num(xs,ys,Num,size,color);
    if((ZF==1)&&(Point==1))//带有符号小数
        TFT_ZF_OnePoint_Num(xs,ys,Num,size,color);
}
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*显示图形*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//画线//x1,y1:起点坐标//x2,y2:终点坐标
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2,uint16_t color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;
    delta_x=x2-x1; //计算坐标增量
    delta_y=y2-y1;
    uRow=x1;
    uCol=y1;
    if(delta_x>0)incx=1; //设置单步方向
    else if(delta_x==0)incx=0;//垂直线
    else
        {
            incx=-1;
            delta_x=-delta_x;
        }
    if(delta_y>0)incy=1;
    else if(delta_y==0)incy=0;//水平线
    else
        {
            incy=-1;
            delta_y=-delta_y;
        }
    if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴
    else distance=delta_y;
    for(t=0; t<=distance+1; t++ ) //画线输出
        {
            TFT_DrawPoint(uRow,uCol,color);
            xerr+=delta_x ;
            yerr+=delta_y ;
            if(xerr>distance)
                {
                    xerr-=distance;
                    uRow+=incx;
                }
            if(yerr>distance)
                {
                    yerr-=distance;
                    uCol+=incy;
                }
        }
}
//画圆弧
//在区域内画点
//(sx,sy),(ex,ey):设定的显示范围
//(x,y):点坐标
//color:颜色
void gui_draw_expoint(u16 sx,u16 sy,u16 ex,u16 ey,u16 x,u16 y,u16 color)
{
    if(x<=ex&&x>=sx&&y<=ey&&y>=sy)
        TFT_DrawPoint(x,y,color);
}
//画8点(Bresenham算法)
//(sx,sy),(ex,ey):设定的显示范围
//(rx,ry,a,b):参数
//color:颜色
void gui_draw_circle8(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,int a,int b,u16 color)
{
    gui_draw_expoint(sx,sy,ex,ey,rx+a,ry-b,color);
    gui_draw_expoint(sx,sy,ex,ey,rx+b,ry-a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx+b,ry+a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx+a,ry+b,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-a,ry+b,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-b,ry+a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-b,ry-a,color);
    gui_draw_expoint(sx,sy,ex,ey,rx-a,ry-b,color);
}
//在指定位置画一个指定大小的圆
//(rx,ry):圆心
//(sx,sy),(ex,ey):设定的显示范围
//r    :半径
//color:颜色
//mode :0,不填充;1,填充
void gui_draw_arc(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,u16 r,u16 color,u8 mode)
{
    int a,b,c;
    int di;
    a=0;
    b=r;
    di=3-(r<<1);	//判断下个点位置的标志
    while(a<=b)
        {
            if(mode)
                for(c=a; c<=b; c++)
                    gui_draw_circle8(sx,sy,ex,ey,rx,ry,a,c,color);//画实心圆
            else
                gui_draw_circle8(sx,sy,ex,ey,rx,ry,a,b,color);					   //画空心圆
            a++;
            //使用Bresenham算法画圆
            if(di<0)di +=4*a+6;
            else
                {
                    di+=10+4*(a-b);
                    b--;
                }
        }
}
//画实心圆
//x0,y0:坐标
//r半径
//color:颜色
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color)
{
    u32 i;
    u32 imax = ((u32)r*707)/1000+1;
    u32 sqmax = (u32)r*(u32)r+(u32)r/2;
    u32 x=r;
    gui_draw_hline(x0-r,y0,2*r,color);
    for (i=1; i<=imax; i++)
        {
            if ((i*i+x*x)>sqmax)
                {
                    // draw lines from outside
                    if (x>imax)
                        {
                            gui_draw_hline (x0-i+1,y0+x,2*(i-1),color);
                            gui_draw_hline (x0-i+1,y0-x,2*(i-1),color);
                        }
                    x--;
                }
            // draw lines from inside (center)
            gui_draw_hline(x0-x,y0+i,2*x,color);
            gui_draw_hline(x0-x,y0-i,2*x,color);
        }
}
//根据矩形对角线的坐标画出4角带有圆弧的图形,r为圆弧的半径
void gui_4_yuanhu(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 color)
{
    gui_draw_arc(sx,sy,sx+r,sy+r,sx+r,sy+r,r,color,1);//左上角圆弧
    Fill_Fast_Rec(sx+r,sy-1,ex-sx-2*r,r+1,color);
    gui_draw_arc(ex-r,sy,ex,sy+r,ex-r,sy+r,r,color,1);//左下角
    Fill_Fast_Rec(sx,sy+r,ex-sx+1,ey-sy-2*r,color);
    gui_draw_arc(sx,ey-r,sx+r,ey,sx+r,ey-r,r,color,1);//右上角
    Fill_Fast_Rec(sx+r,ey-r,ex-sx-2*r,r+1,color);
    gui_draw_arc(ex-r,ey-r,ex,ey,ex-r,ey-r,r,color,1);//右下角


}
//根据矩形对角线的坐标画出4角带有圆弧的图形,r为圆弧的半径,不填充颜色
void gui_4_yuanhu_EMPTY(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 color)
{
    LCD_DrawLine(sx+r,sy, ex-r, sy,color);
    LCD_DrawLine(sx,sy+r,sx,ey-r,color);
    LCD_DrawLine(ex,sy+r,ex,ey-r,color);
    LCD_DrawLine(sx+r,ey, ex-r, ey,color);

    gui_draw_arc(sx,sy,sx+r,sy+r,sx+r,sy+r,r,color,0);//左上角圆弧
    gui_draw_arc(ex-r,sy,ex,sy+r,ex-r,sy+r,r,color,0);//左下角
    gui_draw_arc(sx,ey-r,sx+r,ey,sx+r,ey-r,r,color,0);//右上角
    gui_draw_arc(ex-r,ey-r,ex,ey,ex-r,ey-r,r,color,0);//右下角


}
//根据矩形对角线的坐标画出4角带有圆弧的图形,r为圆弧的半径,不填充颜色
void gui_4_yuanhu_CU_EMPTY(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 color)
{
    gui_4_yuanhu_EMPTY(sx, sy, ex, ey, r,color);
    gui_4_yuanhu_EMPTY(sx+1, sy+1, ex-1, ey-1, r-1,color);

}
//画任意线
//x0,y0:起点 x1,y1:终点
//color:颜色
void gui_draw_line(u16 x0,u16 y0,u16 x1,u16 y1,u16 color)
{
    u16 t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;

    delta_x=x1-x0; //计算坐标增量
    delta_y=y1-y0;
    uRow=x0;
    uCol=y0;
    if(delta_x>0)incx=1; //设置单步方向
    else if(delta_x==0)incx=0;//垂直线
    else
        {
            incx=-1;
            delta_x=-delta_x;
        }
    if(delta_y>0)incy=1;
    else if(delta_y==0)incy=0;//水平线
    else
        {
            incy=-1;
            delta_y=-delta_y;
        }
    if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴
    else distance=delta_y;
    for(t=0; t<=distance+1; t++ ) //画线输出
        {
            TFT_DrawPoint(uRow,uCol, color);
            xerr+=delta_x ;
            yerr+=delta_y ;
            if(xerr>distance)
                {
                    xerr-=distance;
                    uRow+=incx;
                }
            if(yerr>distance)
                {
                    yerr-=distance;
                    uCol+=incy;
                }
        }
}
//画水平线
//x0,y0:坐标
//len:线长度
//color:颜色
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color)
{
//	if((len==0)||(x0>gui_phy.lcdwidth)||(y0>gui_phy.lcdheight))return;
    if(len==0)return;
    Fill_Fast_Rec(x0,y0,len,1,color);
}
//画椭圆
//x0,y0:坐标
//rx:x方向半径
//ry:y方向半径
//color:椭圆的颜色
void gui_draw_ellipse(u16 x0, u16 y0, u16 rx, u16 ry,u16 color)
{
    u32 OutConst, Sum, SumY;
    u16 x,y;
    u16 xOld;
    u32 _rx = rx;
    u32 _ry = ry;
    if(rx>x0||ry>y0)return;//非法.
    OutConst = _rx*_rx*_ry*_ry+(_rx*_rx*_ry>>1);  // Constant as explaint above
    // To compensate for rounding
    xOld = x = rx;
    for (y=0; y<=ry; y++)
        {
            if (y==ry)x=0;
            else
                {
                    SumY =((u32)(rx*rx))*((u32)(y*y)); // Does not change in loop
                    while(Sum = SumY + ((u32)(ry*ry))*((u32)(x*x)),(x>0) && (Sum>OutConst)) x--;
                }
            // Since we draw lines, we can not draw on the first iteration
            if (y)
                {
                    gui_draw_line(x0-xOld,y0-y+1,x0-x,y0-y,color);
                    gui_draw_line(x0-xOld,y0+y-1,x0-x,y0+y,color);
                    gui_draw_line(x0+xOld,y0-y+1,x0+x,y0-y,color);
                    gui_draw_line(x0+xOld,y0+y-1,x0+x,y0+y,color);
                }
            xOld = x;
        }
}
//填充椭圆
//x0,y0:坐标
//rx:x方向半径
//ry:y方向半径
//color:椭圆的颜色
void gui_fill_ellipse(u16 x0,u16 y0,u16 rx,u16 ry,u16 color)
{
    u32 OutConst, Sum, SumY;
    u16 x,y;
    u32 _rx = rx;
    u32 _ry = ry;
    OutConst = _rx*_rx*_ry*_ry+(_rx*_rx*_ry>>1);// Constant as explaint above
    // To compensate for rounding
    x = rx;
    for (y=0; y<=ry; y++)
        {
            SumY =((u32)(rx*rx))*((u32)(y*y)); // Does not change in loop
            while (Sum = SumY + ((u32)(ry*ry))*((u32)(x*x)),(x>0) && (Sum>OutConst))x--;
            gui_draw_hline(x0-x,y0+y,2*x,color);
            if(y)gui_draw_hline(x0-x,y0-y,2*x,color);
        }
}
void LCD_DrawLtrigo(u16 x1, u16 y1, u16 x2, u16 y2,u16 color,u8 dir)
{

    u8 i;
    u16 y;
	  u8 x;
    if(dir==DOWN){
    y =y1+(y2-y1)/2;
    for(i=0; i<((y2-y1)/2); i++)
        {
            LCD_DrawLine(x1+i,y+i,x2-i,y+i,color);
        }
			}else if(dir==RIGHT){
			
		  x=x1+(x2-x1)/2;
    for(i=0; i<(y2-y1)/2;i++)
        {
            LCD_DrawLine(x+i,y1+i,x+i,y2-i,color);
        }		
				
			}
				
}
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*颜色处理*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//颜色格式转换
uint16_t rgb24_2_565(int R,int G,int B)
{
    uint16_t color_change;
    color_change=((R<<8)&0xF800)|((G<<3)&0x07E0)|(B>>3);
    return  color_change;
}
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*显示图片*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//显示任意图标
void TFT_Show_Any_Picture(u16 sx,u16 sy,u16 x_wight,u16 y_height,u16 color,const char *Picture)
{
    uint16_t i,j,t=0;
    char temp;
    for(i=0; i<x_wight; i++)
        {
            for(j=0; j<y_height; j++)
                {
                    if(j%8==0)//写好一个字节
                        {
                            temp=*(Picture+t);
                            t++;
                        }
                    if(temp&0x01)
                        TFT_DrawPoint(sx+i,sy+j,color);
                    temp>>=1;
                }
//					if(j%8!=0)
//						t++;
        }
}
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*公用显示函数*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//画圆角矩形/填充圆角矩形
//x,y,width,height:圆角矩形的位置和尺寸
//r:圆角的半径.
//upcolor:上半部分颜色
//downcolor:下半部分颜色
//left_wight左边的宽度
//border_color边框颜色
void gui_draw_arcrectangle_(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 left_wight,u16 left_color,u16 right_color,u16 border_color)
{

    Fill_Fast_Rec(sx,sy,left_wight,ey-sy,left_color);
    Fill_Fast_Rec(sx+left_wight,sy,ex-sx-left_wight,ey-sy,right_color);
    gui_4_yuanhu_EMPTY( sx, sy,ex , ey, r,border_color);

}
//显示选项
void Option_Boarder_NO_Fangxiang_Dis(u16 sx,u16 sy,u16 ex,u16 ey,u16 Left_Long,u16 Options_Left_Color,u16 Options_Font_Color,char *p)
{
    gui_draw_arcrectangle_(sx,sy,ex,ey,1,Left_Long,Options_Left_Color,Black,Options_Left_Color);

    Write_Word_Center(sx,sy,sx+Left_Long,ey,16,p,Options_Font_Color);

}
//
//擦除多少个size字体的区域
void Clear_Word(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color)
{
    Fill_Fast_Rec(x,y,Num*(size/2),size,color);
}
//在一个矩形中间清除多少个字符
void Clear_REC_CENTER(u16 sx,u16 sy,u16 ex,u16 ey,int Num,uint8_t size,uint16_t color)
{
    u16 total_len;
    u16 xs,ys;

    total_len=Num*(size/2);//算出字符总长度

//    xs=sx+(ex-sx-size)/2;
//    ys=sy+(ey-sy-total_len)/2;
    xs=sx+(ex-sx-total_len)/2;
    ys=sy+(ey-sy-size)/2;
    Clear_Word(xs,ys,Num,size,color);
}
//综合清除旧痕迹，写入新数据的函数
void Clear_Write_Data(u16 sx,u16 sy,u16 ex,u16 ey,u8 size,int Num,u16 color,u8 mode,u16 back_color,u8 ZF,u8 Point,int Clear_num)
{
    Clear_REC_CENTER(sx, sy, ex, ey, Clear_num, size,back_color);
    Write_Num_Center( sx, sy, ex, ey, size, Num, color, ZF, Point);
}
//


















