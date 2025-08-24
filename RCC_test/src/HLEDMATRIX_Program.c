#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSTK_Interface.h"
#include "MGPIO_Interface.h"

#include "HLEDMATRIX_Interface.h"
#include "HLEDMATRIX_Config.h"

void HLEDMATRIX_voidInit()
{
	u8 Local_u8Iterator;
	for(Local_u8Iterator=0;Local_u8Iterator<13;Local_u8Iterator++)
	{
		MGPIO_voidSetMode(PORTA,Local_u8Iterator,OUTPUT);
		MGPIO_voidSetOutputConfig(PORTA,Local_u8Iterator,Push_Pull,Low_Speed);
	}
	for(Local_u8Iterator=0;Local_u8Iterator<3;Local_u8Iterator++)
	{
		MGPIO_voidSetMode(PORTB,Local_u8Iterator,OUTPUT);
		MGPIO_voidSetOutputConfig(PORTB,Local_u8Iterator,Push_Pull,Low_Speed);
	}

}

static void HLEDMATRIX_voidSetRowValue(u8 Copy_u8Row)
{
	for(u8 i=0;i<8;i++)
	{
		MGPIO_voidSetPinValue(PORTA,i,GET_BIT(Copy_u8Row,i));
	}
}
static void HLEDMATRIX_voidDeactivateAllColumns()
{
	u8 i;
	for(i=8;i<13;i++)
	{
		MGPIO_voidSetPinValue(PORTA,i,HIGH);
	}
	for(i=0;i<3;i++)
	{
		MGPIO_voidSetPinValue(PORTB,i,HIGH);
	}
}
void HLEDMATRIX_voidDisplay(u8*Copy_pu8Arr)
{
	u8 i=0;
	for(i=0;i<5;i++)
	{
		//Set Row Value
	    HLEDMATRIX_voidSetRowValue(Copy_pu8Arr[i]);
	    //Activate Columns
	    MGPIO_voidSetPinValue(PORTA,PIN8+i,LOW);
	    //delay
	    MSTK_voidDelayus(2500);
	    //Deactivate Colimns
	    HLEDMATRIX_voidDeactivateAllColumns();
	}
	for(i=0;i<3;i++)
	{
		//Set Row Value
	    HLEDMATRIX_voidSetRowValue(Copy_pu8Arr[i+5]);
	    //Activate Columns
	    MGPIO_voidSetPinValue(PORTB,PIN0+i,LOW);
	    //delay
	    MSTK_voidDelayus(2500);
	    //Deactivate Colimns
	    HLEDMATRIX_voidDeactivateAllColumns();
	}
	
}
