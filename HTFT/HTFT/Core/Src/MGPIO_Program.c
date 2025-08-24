#include "STD_TYPES.H"
#include "BIT_MATH.h"

#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"


void MGPIO_voidSetMode(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Modes_t Copy_uddtMode)
{
	if(Copy_uddtPort==PORTA && (Copy_uddtPin==13 ||Copy_uddtPin==14 ||Copy_uddtPin==15))
	{
		return;
	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{
		return;
	}
	else if (Copy_uddtPort < 0 || Copy_uddtPort >= sizeof(ARRAY_BASE_ADDRESS) / sizeof(ARRAY_BASE_ADDRESS[0])) {
        // Handle error (invalid port)
        return;
    }
	else
	{
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->MODER&=~(MUSK<<(Copy_uddtPin*2));
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->MODER|=(Copy_uddtMode<<(Copy_uddtPin*2));
	}
		
}


void MGPIO_voidSetOutputConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Output_t Copy_uddtType,Speed_t Copy_uddtSpeed)
{
	if(Copy_uddtPort==PORTA && (Copy_uddtPin==13 ||Copy_uddtPin==14 ||Copy_uddtPin==15))
	{
		return;
	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{
		return;
	}
	else
	{
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->OTYPER&=~(1<<(Copy_uddtPin));
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->OTYPER|=(Copy_uddtType<<(Copy_uddtPin));
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->OSPEEDER&=~(MUSK<<(Copy_uddtPin*2));
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->OSPEEDER|=(Copy_uddtSpeed<<(Copy_uddtPin*2));
//		switch(Copy_uddtPort)
//		{
//			case PORTA:
//			GPIOA->OTYPER&=~(1<<Copy_uddtPin);
//			GPIOA->OTYPER|=(Copy_uddtType<<Copy_uddtPin);
//			GPIOA->OSPEEDER&=~(MUSK<<(Copy_uddtPin*2));
//			GPIOA->OSPEEDER|=(Copy_uddtSpeed<<(Copy_uddtPin*2));
//			break;
//			case PORTB:
//			GPIOB->OTYPER&=~(1<<Copy_uddtPin);
//			GPIOB->OTYPER|=(Copy_uddtType<<Copy_uddtPin);
//			GPIOB->OSPEEDER&=~(MUSK<<(Copy_uddtPin*2));
//			GPIOB->OSPEEDER|=(Copy_uddtSpeed<<(Copy_uddtPin*2));
//			break;
//			case PORTC:
//			GPIOC->OTYPER&=~(1<<Copy_uddtPin);
//			GPIOC->OTYPER|=(Copy_uddtType<<Copy_uddtPin);
//			GPIOC->OSPEEDER&=~(MUSK<<(Copy_uddtPin*2));
//			GPIOC->OSPEEDER|=(Copy_uddtSpeed<<(Copy_uddtPin*2));
//
//			break;
//		}
	}
}
void MGPIO_voidSetPinValue(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,PinValue_t Copy_uddtPinValue)
{
	if(Copy_uddtPort==PORTA && (Copy_uddtPin==13 ||Copy_uddtPin==14 ||Copy_uddtPin==15))
	{
		
	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{
		
	}
	else
	{
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->ODR&=~(1<<(Copy_uddtPin));
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->ODR|=(Copy_uddtPinValue<<(Copy_uddtPin));
//		switch(Copy_uddtPort)
//		{
//			case PORTA:
//			GPIOA->ODR&=~(1<<Copy_uddtPin);
//			GPIOA->ODR|=(Copy_uddtPinValue<<Copy_uddtPin);
//			break;
//			case PORTB:
//			GPIOB->ODR&=~(1<<Copy_uddtPin);
//			GPIOB->ODR|=(Copy_uddtPinValue<<Copy_uddtPin);
//			break;
//			case PORTC:
//			GPIOC->ODR&=~(1<<Copy_uddtPin);
//			GPIOC->ODR|=(Copy_uddtPinValue<<Copy_uddtPin);
//			break;
//		}
	}
}
void MGPIO_voidSetPinValueAtomic(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,PinValue_t Copy_uddtPinValue)
{
	u32 VAL =0;

	if(Copy_uddtPort==PORTA && (Copy_uddtPin==13 ||Copy_uddtPin==14 ||Copy_uddtPin==15))
	{
		
	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{
		
	}
	else
	{
		if(Copy_uddtPinValue==LOW)
		{
			Copy_uddtPin+=16;
		}
		VAL = (1<<(Copy_uddtPin));
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->BSRR=VAL;
//		switch(Copy_uddtPort)
//		{
//			case PORTA:
//			if(Copy_uddtPinValue==LOW)
//			{
//				Copy_uddtPin+=16;
//			}
//			GPIOA->BSRR=(Copy_uddtPinValue<<Copy_uddtPin);
//			break;
//			case PORTB:
//			if(Copy_uddtPinValue==LOW)
//			{
//				Copy_uddtPin+=16;
//			}
//			GPIOB->BSRR=(Copy_uddtPinValue<<Copy_uddtPin);
//			break;
//			case PORTC:
//			if(Copy_uddtPinValue==LOW)
//			{
//				Copy_uddtPin+=16;
//			}
//			GPIOC->BSRR=(Copy_uddtPinValue<<Copy_uddtPin);
//			break;
//		}
	}
}

void MGPIO_voidSetInputConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Input_t Copy_uddtType)
{
	if(Copy_uddtPort==PORTA && (Copy_uddtPin==13 ||Copy_uddtPin==14 ||Copy_uddtPin==15))
	{
		
	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{
		
	}
	else
	{
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->PUPDR&=~(MUSK<<(Copy_uddtPin*2));
		ARRAY_BASE_ADDRESS[Copy_uddtPort]->PUPDR|=(Copy_uddtType<<(Copy_uddtPin*2));
//		switch(Copy_uddtPort)
//		{
//			case PORTA:
//			GPIOA->PUPDR&=~(MUSK<<(Copy_uddtPin*2));
//			GPIOA->PUPDR|=(Copy_uddtType<<(Copy_uddtPin*2));
//			break;
//			case PORTB:
//			GPIOB->PUPDR&=~(MUSK<<(Copy_uddtPin*2));
//			GPIOB->PUPDR|=(Copy_uddtType<<(Copy_uddtPin*2));
//			break;
//			case PORTC:
//			GPIOC->PUPDR&=~(MUSK<<(Copy_uddtPin*2));
//			GPIOC->PUPDR|=(Copy_uddtType<<(Copy_uddtPin*2));
//			break;
//		}
	}
}
u8 MGPIO_u8GetPinValue(Port_t Copy_uddtPort,PIN_t Copy_uddtPin)
{
	u8 Copy_u8PinValue=0;
	if(Copy_uddtPort==PORTA && (Copy_uddtPin==13 ||Copy_uddtPin==14 ||Copy_uddtPin==15))
	{
		
	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{
		
	}
	else
	{
		Copy_u8PinValue=GET_BIT(ARRAY_BASE_ADDRESS[Copy_uddtPort]->IDR,Copy_uddtPin);
//		switch(Copy_uddtPort)
//		{
//			case PORTA:
//			Copy_u8PinValue=GET_BIT(GPIOA->IDR,Copy_uddtPin);
//			break;
//			case PORTB:
//			Copy_u8PinValue=GET_BIT(GPIOB->IDR,Copy_uddtPin);
//			break;
//			case PORTC:
//			Copy_u8PinValue=GET_BIT(GPIOC->IDR,Copy_uddtPin);
//			break;
//		}
	}
	return Copy_u8PinValue;
}

void MGPIO_voidSetAlternativeConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Alternative_t Copy_uddtType)
{
	if(Copy_uddtPort==PORTA && (Copy_uddtPin==13 ||Copy_uddtPin==14 ||Copy_uddtPin==15))
	{
		
	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{
		
	}
	else
	{
		if(Copy_uddtPin<8)
		{
			ARRAY_BASE_ADDRESS[Copy_uddtPort]->AFRL&=~(ALT_MUSK<<(Copy_uddtPin*4));
			ARRAY_BASE_ADDRESS[Copy_uddtPort]->AFRL|=(Copy_uddtType<<(Copy_uddtPin*4));
		}
		else if(Copy_uddtPin<16)
		{
			Copy_uddtPin-=8;
			ARRAY_BASE_ADDRESS[Copy_uddtPort]->AFRH&=~(ALT_MUSK<<(Copy_uddtPin*4));
			ARRAY_BASE_ADDRESS[Copy_uddtPort]->AFRH|=(Copy_uddtType<<(Copy_uddtPin*4));
		}
//		switch(Copy_uddtPort)
//		{
//			case PORTA:
//			if(Copy_uddtPin<8)
//			{
//				GPIOA->AFRL&=~(ALT_MUSK<< (Copy_uddtPin*4));
//				GPIOA->AFRL|=(Copy_uddtType<<(Copy_uddtPin*4));
//			}
//			else if(Copy_uddtPin<16)
//			{
//				Copy_uddtPin-=8;
//				GPIOA->AFRH&=~(ALT_MUSK<<(Copy_uddtPin*4));
//				GPIOA->AFRH|=(Copy_uddtType<<(Copy_uddtPin*4));
//			}
//			break;
//			case PORTB:
//			if(Copy_uddtPin<8)
//			{
//				GPIOB->AFRL&=~(ALT_MUSK<< (Copy_uddtPin*4));
//				GPIOB->AFRL|=(Copy_uddtType<<(Copy_uddtPin*4));
//			}
//			else if(Copy_uddtPin<16)
//			{
//				Copy_uddtPin-=8;
//				GPIOC->AFRH&=~(ALT_MUSK<<(Copy_uddtPin*4));
//				GPIOC->AFRH|=(Copy_uddtType<<(Copy_uddtPin*4));
//			}
//			break;
//			case PORTC:
//			if(Copy_uddtPin<8)
//			{
//				GPIOC->AFRL&=~(ALT_MUSK<< (Copy_uddtPin*4));
//				GPIOC->AFRL|=(Copy_uddtType<<(Copy_uddtPin*4));
//			}
//			else if(Copy_uddtPin<16)
//			{
//				Copy_uddtPin-=8;
//				GPIOC->AFRH&=~(ALT_MUSK<<(Copy_uddtPin*4));
//				GPIOC->AFRH|=(Copy_uddtType<<(Copy_uddtPin*4));
//			}
//			break;
//		}
	}
}
