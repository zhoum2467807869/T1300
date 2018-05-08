#ifndef __FSMC_H
#define __FSMC_H

#include "sys.h"

#define  FSMC_D7 PEout(10)
#define  FSMC_D6 PEout(9)
#define  FSMC_D5 PEout(8)
#define  FSMC_D4 PEout(7)
#define  FSMC_D3 PDout(1)
#define  FSMC_D2 PDout(0)
#define  FSMC_D1 PDout(15)
#define  FSMC_D0 PDout(14)

#define  FSMC_A16_RS PDout(11)
#define  FSMC_NE1_CS PDout(7)
#define  FSMC_NWE_WR PDout(5)
#define  FSMC_NOE_RD PDout(4)



//LCD地址结构体，
typedef struct
{
	u8 LCD_REG;//0x0000FFFF
	u8 LCD_RAM;//0x00010000
} LCD_TypeDef;
//使用NOR/SRAM的 Bank1.sector1,地址位HADDR[27,26]=00 A16作为数据命令区分线 
//注意设置时STM32内部会右移一位对其! 			   ,RS为1是DATA,RS为0是REG
#define LCD_BASE        ((u32)(0x60000000 | 0x0000FFFF))//NE1,[27:26]=00
#define LCD             ((LCD_TypeDef *) LCD_BASE)

#define Bank_LCD_D ((u32)0X60010000)
#define Bank_LCD_C ((u32)0X60000000)

#define TFT_RST PEout(0)
#define TFT_BK  PDout(0)

//FSMC初始化
void TFT_FSMC_INIT(void);
//regval:寄存器值
void LCD_WR_REG(u16 regval);
//写LCD数据
//data:要写入的值
void LCD_WR_DATA(u16 data);
//读LCD数据
//返回值:读到的值
u16 LCD_RD_DATA(void);
//往寄存器里面写入数据
void LCD_WR_REG_DATA(u16 reg,u16 data);

#endif




