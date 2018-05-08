#include "FSMC.H"

void TFT_FSMC_INIT(void)//FSMC��ʼ���������˶�дʱ��
{
	
		GPIO_InitTypeDef GPIO_InitStructure;
		FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;	
		FSMC_NORSRAMTimingInitTypeDef  p; 
	
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);	//ʹ��FSMCʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);		
		//PORTD�����������  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15|GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_11|GPIO_Pin_7|GPIO_Pin_4|GPIO_Pin_5;//PORTD�����������  
 	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //�����������   
 	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	  GPIO_Init(GPIOD, &GPIO_InitStructure); 
	
		//PORTE�����������  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;//	//PORTD�����������  
 	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 		 //�����������   
 	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	  GPIO_Init(GPIOE, &GPIO_InitStructure);  
	
		//RST
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //���ó��������  
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHz
		GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��  
		
		//TFT_ON
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //���ó��������  
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO���ٶ�Ϊ50MHz
		GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��  
	  PDout(13)=1;
		
		p.FSMC_AddressSetupTime = 0x05;	 //��ַ����ʱ��
    p.FSMC_AddressHoldTime = 0x00;	 //��ַ����ʱ��
    p.FSMC_DataSetupTime = 0x05;		 //���ݽ���ʱ��
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
		
		FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  //��ʼ��FSMC����
 	  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  // ʹ��BANK1 		
}
//
//���8-bit IO�ڵ�
//regval:�Ĵ���ֵ
void LCD_WR_REG(u16 regval)
{   
		LCD->LCD_REG=(regval>>8);//��д��8λ
		LCD->LCD_REG=(regval&0xFF);//��д��8λ
}
//дLCD����
//data:Ҫд���ֵ
void LCD_WR_DATA(u16 data)
{	 
	LCD->LCD_RAM=(data>>8);
	LCD->LCD_RAM=(data&0xFF);
}
//��LCD����
//����ֵ:������ֵ
//��Զ�ȡ��ɫ���ݵ�
u16 LCD_RD_DATA(void)
{
//	vu32 ram;			//��ֹ���Ż�
//	u8 i;
//	for(i=0;i<3;i++)//�ȶ�����λ���ٶ�����λ color[17:0]
//	{
//		ram=LCD->LCD_RAM;	
//		ram<<=8;
//	}
//	return ram;	 
		return LCD->LCD_RAM;
}
//���Ĵ�������д������
void LCD_WR_REG_DATA(u16 reg,u16 data)
{
		LCD_WR_REG(reg);
		LCD_WR_DATA(data);
}
//





