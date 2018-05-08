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



//LCD��ַ�ṹ�壬
typedef struct
{
	u8 LCD_REG;//0x0000FFFF
	u8 LCD_RAM;//0x00010000
} LCD_TypeDef;
//ʹ��NOR/SRAM�� Bank1.sector1,��ַλHADDR[27,26]=00 A16��Ϊ�������������� 
//ע������ʱSTM32�ڲ�������һλ����! 			   ,RSΪ1��DATA,RSΪ0��REG
#define LCD_BASE        ((u32)(0x60000000 | 0x0000FFFF))//NE1,[27:26]=00
#define LCD             ((LCD_TypeDef *) LCD_BASE)

#define Bank_LCD_D ((u32)0X60010000)
#define Bank_LCD_C ((u32)0X60000000)

#define TFT_RST PEout(0)
#define TFT_BK  PDout(0)

//FSMC��ʼ��
void TFT_FSMC_INIT(void);
//regval:�Ĵ���ֵ
void LCD_WR_REG(u16 regval);
//дLCD����
//data:Ҫд���ֵ
void LCD_WR_DATA(u16 data);
//��LCD����
//����ֵ:������ֵ
u16 LCD_RD_DATA(void);
//���Ĵ�������д������
void LCD_WR_REG_DATA(u16 reg,u16 data);

#endif




