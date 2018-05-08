#include "FSMC.H"

void TFT_FSMC_INIT(void)//FSMC初始化，配置了读写时序
{
	
		GPIO_InitTypeDef GPIO_InitStructure;
		FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;	
		FSMC_NORSRAMTimingInitTypeDef  p; 
	
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);	//使能FSMC时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);		
		//PORTD复用推挽输出  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15|GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_11|GPIO_Pin_7|GPIO_Pin_4|GPIO_Pin_5;//PORTD复用推挽输出  
 	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //复用推挽输出   
 	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	  GPIO_Init(GPIOD, &GPIO_InitStructure); 
	
		//PORTE复用推挽输出  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;//	//PORTD复用推挽输出  
 	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //复用推挽输出   
 	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	  GPIO_Init(GPIOE, &GPIO_InitStructure);  
	
		//RST
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置成推挽输出  
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO口速度为50MHz
		GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化  
		
		//TFT_ON
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置成推挽输出  
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO口速度为50MHz
		GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化  
	  PDout(13)=1;
		
		p.FSMC_AddressSetupTime = 0x05;	 //地址建立时间
    p.FSMC_AddressHoldTime = 0x00;	 //地址保持时间
    p.FSMC_DataSetupTime = 0x05;		 //数据建立时间
    p.FSMC_BusTurnAroundDuration = 0x00;
    p.FSMC_CLKDivision = 0x00;
    p.FSMC_DataLatency = 0x00;
    p.FSMC_AccessMode = FSMC_AccessMode_B;	 // 
		
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
    FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
		FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
		
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;
		
		FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //初始化FSMC配置
 	  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  // 使能BANK1 		
}
//
//针对8-bit IO口的
//regval:寄存器值
void LCD_WR_REG(u16 regval)
{   
		LCD->LCD_REG=(regval>>8);//先写高8位
		LCD->LCD_REG=(regval&0xFF);//再写低8位
}
//写LCD数据
//data:要写入的值
void LCD_WR_DATA(u16 data)
{	 
	LCD->LCD_RAM=(data>>8);
	LCD->LCD_RAM=(data&0xFF);
}
//读LCD数据
//返回值:读到的值
//针对读取颜色数据的
u16 LCD_RD_DATA(void)
{
//	vu32 ram;			//防止被优化
//	u8 i;
//	for(i=0;i<3;i++)//先读出高位，再读出低位 color[17:0]
//	{
//		ram=LCD->LCD_RAM;	
//		ram<<=8;
//	}
//	return ram;	 
		return LCD->LCD_RAM;
}
//往寄存器里面写入数据
void LCD_WR_REG_DATA(u16 reg,u16 data)
{
		LCD_WR_REG(reg);
		LCD_WR_DATA(data);
}
//





