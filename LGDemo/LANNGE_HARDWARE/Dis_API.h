#ifndef __Dis_API_H
#define __Dis_API_H

#include "FSMC.H"
#include "delay.h"
#include "math.h"//作为绝对值运算
#include "string.h"
#include "stdlib.h"

//u16 byte[20] = {0xFE41,0x0000,0xFF80,0x78EF,0x8802,0xFBE4,0x2589,0x7479,0xF800,0x051D,0x3A39,
//                0x3A79,0xA254,0xC618,0xBBCA,0xFD79,0xB723,0x9EDD,0x001F,0x07E0
//               };
//u16 buf[20] = {0xF81F,0xFFE0,0x07FF,0xF81F,0x7FFF,0xBC40,0xFC07,0x8430,0x01FC,0x7D7C,0x5458,
//               0x841F,0xEF5B,0xC618,0xA651,0x2B12,0x7FFF,0xFFFF,0xFFFF,0xFFFF
//              };

#define White      0xFFFF
#define Black      0x0000
#define Blue       0x001F
#define Red        0xF800 
#define Green_200  0x2589
#define Blue_200	 0x2B12			
#define Blue_50    0x9EDD
#define Blue_100   0x051D
#define Blue_250   0x3A39
#define Blue_300   0x001F

#define RIGHT      1
#define LEFT       2
#define UP         3
#define DOWN       4

extern const char Font_16X8[95][16];//16号宋体
extern const char Font_24X12[95][36];//24号宋体
extern const char Font_32X16[95][64];//32号字体
extern const char LOGO[];

typedef struct{
	
void (*Fill_Fast_Rec)(u16,u16,u16,u16,u16);
void (*TFT_ShowString)(uint16_t,uint16_t,char*,uint8_t,uint16_t);
void (*Write_Word_Center)(u16 sx,u16 sy,u16 ex,u16 ey,u8 size,char *p,u16 color);
void (*TFT_ShowNum)(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color);
void (*gui_draw_arc)(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,u16 r,u16 color,u8 mode);	
void (*gui_4_yuanhu_EMPTY)(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 color);	
void (*LCD_DrawLtrigo)(u16 x1, u16 y1, u16 x2, u16 y2,u16 color,u8 dir);	
void (*TFT_Show_Any_Picture)(u16 sx,u16 sy,u16 x_wight,u16 y_height,u16 color,const char *Picture);	
	
}_DisAPI;


extern _DisAPI DisAPI;

void TFT_init(void);//液晶初始化
void Mirro_Y(u16 *y_pos);//镜面对称
void OPEN_WINDOW(u16 x,u16 y,u16 x_height,u16 y_width);//开窗
void Fill_Fast_Rec(u16 x,u16 y,u16 x_height,u16 y_width,u16 color);//填充颜色
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2,uint16_t color);
void LCD_Clear(u16 corlor);
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color);
void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color);//描点
u16 TFT_ReadPoint(u16 x,u16 y);//读点
void TFT_Draw_One_Char(uint16_t x,uint16_t y,char word,uint8_t size,uint16_t color);//在指定的位置显示一个字符(x,y,char,size,color)
void TFT_ShowString(uint16_t x,uint16_t y,char *p,uint8_t size,uint16_t color);//显示字符串(x,y,)
void Write_Word_Center(u16 sx,u16 sy,u16 ex,u16 ey,u8 size,char *p,u16 color);//在矩形字框内中间写入不同size的字符

void TFT_ShowNum(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color);//显示数字，高位为0不显示
void TFT_Show_OnePoint_Num(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color);//显示一个带有小数点的数
void TFT_ZF_Num(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color);//显示带有正负号的整数
void TFT_ZF_OnePoint_Num(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color );//显示带有正负号的小数
void Write_Num_Center(u16 sx,u16 sy,u16 ex,u16 ey,u8 size,int Num,u16 color,u8 ZF,u8 Point);//在矩形字框中间写入不同SIZE的Number

void gui_draw_arc(u16 sx,u16 sy,u16 ex,u16 ey,u16 rx,u16 ry,u16 r,u16 color,u8 mode);//在指定位置画一个指定大小的圆
void gui_4_yuanhu(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 color);//根据矩形对角线的坐标画出4角带有圆弧的图形,r为圆弧的半径
void gui_4_yuanhu_EMPTY(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 color);//根据矩形对角线的坐标画出4角带有圆弧的图形,r为圆弧的半径,不填充颜色
void gui_4_yuanhu_CU_EMPTY(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 color);//根据矩形对角线的坐标画出4角带有圆弧的图形,r为圆弧的半径,不填充颜色
void gui_fill_circle(u16 x0,u16 y0,u16 r,u16 color);//画实心圆
void gui_draw_line(u16 x0,u16 y0,u16 x1,u16 y1,u16 color);//画任意线
void gui_draw_hline(u16 x0,u16 y0,u16 len,u16 color);//画水平线
void gui_draw_ellipse(u16 x0, u16 y0, u16 rx, u16 ry,u16 color) ;//画椭圆
void gui_fill_ellipse(u16 x0,u16 y0,u16 rx,u16 ry,u16 color);//填充椭圆
uint16_t rgb24_2_565(int R,int G,int B);//颜色格式转换
void LCD_DrawLtrigo(u16 x1, u16 y1, u16 x2, u16 y2,u16 color,u8 dir);

void TFT_Show_Any_Picture(u16 sx,u16 sy,u16 x_wight,u16 y_height,u16 color,const char *Picture);//显示任意图标

void gui_draw_arcrectangle_(u16 sx,u16 sy,u16 ex,u16 ey,u16 r,u16 left_wight,u16 left_color,u16 right_color,u16 border_color);
void Option_Boarder_NO_Fangxiang_Dis(u16 sx,u16 sy,u16 ex,u16 ey,u16 Left_Long,u16 Options_Left_Color,u16 Options_Font_Color,char *p);//显示选项


void Clear_Word(uint16_t x,uint16_t y,int Num,uint8_t size,uint16_t color);//擦除多少个size字体的区域
void Clear_REC_CENTER(u16 sx,u16 sy,u16 ex,u16 ey,int Num,uint8_t size,uint16_t color);//在一个矩形中间清除多少个字符
void Clear_Write_Data(u16 sx,u16 sy,u16 ex,u16 ey,u8 size,int Num,u16 color,u8 mode,u16 back_color,u8 ZF,u8 Point,int Clear_num);//综合清除旧痕迹，写入新数据的函数



#endif

