#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_Interface.h"

#include "DAC_Interface.h"
//#include "DAC_Config.h"
#include "DAC_Private.h"

void HDAC_voidInit()
{
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		MGPIO_voidSetMode(PORTA,Local_u8Iterator,OUTPUT);
		MGPIO_voidSetOutputConfig(PORTA,Local_u8Iterator,Push_Pull,Low_Speed);
	}
}
void HDAC_voidSendSample(const u8*Copy_u8Ptr,u32 Copy_u32Index)
{
	u8 Local_u8Iterator=0;
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		MGPIO_voidSetPinValue(PORTA,Local_u8Iterator,((Copy_u8Ptr[Copy_u32Index]>>Local_u8Iterator)&0x01));
	}
}
