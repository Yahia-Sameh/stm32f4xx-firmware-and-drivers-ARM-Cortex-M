
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "MSPI_Interface.h"

#include "HTFT_Interface.h"
#include "HTFT_Config.h"

void HTFT_voidInit()
{
	MGPIO_voidSetMode(TFT_PORT,RST_PIN,OUTPUT);
	MGPIO_voidSetOutputConfig(TFT_PORT,RST_PIN,Push_Pull,Low_Speed);
	MGPIO_voidSetMode(TFT_PORT,CONTROL_PIN,OUTPUT);
	MGPIO_voidSetOutputConfig(TFT_PORT,CONTROL_PIN,Push_Pull,Low_Speed);
	
	//Reset Sequence 
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,HIGH);
	MSTK_voidDelayus(100);
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,LOW);
	MSTK_voidDelayus(1);
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,HIGH);
	MSTK_voidDelayus(100);
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,LOW);
	MSTK_voidDelayus(100);
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,HIGH);
	MSTK_voidDelayms(120);
	
	//Sleep Out
	HTFT_voidWriteCMD(SLEEP_OUT);
	MSTK_voidDelayms(10);
	
	//Select color mode
	HTFT_voidWriteCMD(COLOR_MODE);
	HTFT_voidWriteData(RGB565);
	
	//Diplay on
	HTFT_voidWriteCMD(DISPLAY_ON);
}
void HTFT_voidWriteData(u8 Copy_u8Data)
{
	MGPIO_voidSetPinValue(TFT_PORT,CONTROL_PIN,HIGH);
	(void)MSPI_u16Tranceive(Copy_u8Data);
}
void HTFT_voidWriteCMD(u8 Copy_u8CMD)
{
	MGPIO_voidSetPinValue(TFT_PORT,CONTROL_PIN,LOW);
	(void)MSPI_u16Tranceive(Copy_u8CMD);
}
void HTFT_voidDisplay(const u16*Copy_pu16PTR)
{
	u16 Local_u16Iterator;
	u8 Local_u8HighPart,Local_u8LowPart;
	
	//Set x
	HTFT_voidWriteCMD(X_Direction);
	HTFT_voidWriteData(START_X_B0);
	HTFT_voidWriteData(START_X_B1);
	HTFT_voidWriteData(END_X_B0);
	HTFT_voidWriteData(END_X_B1);
	
	//set y
	HTFT_voidWriteCMD(Y_Direction);
	HTFT_voidWriteData(START_Y_B0);
	HTFT_voidWriteData(START_Y_B1);
	HTFT_voidWriteData(END_Y_B0);
	HTFT_voidWriteData(END_Y_B1);
	
	//Write on screen 
	HTFT_voidWriteCMD(SCREEN_WRITE);
	for(Local_u16Iterator=0;Local_u16Iterator<IMAGE_SIZE;Local_u16Iterator++)
	{
		Local_u8LowPart=(u8)Copy_pu16PTR[Local_u16Iterator];
		Local_u8HighPart=(u8)(Copy_pu16PTR[Local_u16Iterator]>>8);
		HTFT_voidWriteData(Local_u8HighPart);
		HTFT_voidWriteData(Local_u8LowPart);
	}
}
