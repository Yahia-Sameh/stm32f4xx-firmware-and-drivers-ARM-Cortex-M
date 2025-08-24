#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MEXTI_Interface.h"
#include "MEXTI_Private.h"
#include "MEXTI_Config.h"

static void(*Global_PtrEXTI0)(void)=NULL;
void EXTI_voidSetInterruptPort(EXTI_Line_t Copy_uddtLine,EXTI_Port_t Copy_uddtPort)
{
	SYSCFG->EXTICR[Copy_uddtLine/SYS_DIV]&=~(SYS_MUSK<<((Copy_uddtLine%SYS_DIV)*4));
	SYSCFG->EXTICR[Copy_uddtLine/SYS_DIV]|=(Copy_uddtPort<<((Copy_uddtLine%SYS_DIV)*4));
}

void MEXTI_voidEnable(EXTI_Line_t Copy_uddtLine)
{
	EXTI->IMR|=(1<<Copy_uddtLine);
}
void MEXTI_voidDisable(EXTI_Line_t Copy_uddtLine)
{
	EXTI->IMR&=~(1<<Copy_uddtLine);
}
void MEXTI_voidSetTrigger(EXTI_Line_t Copy_uddtLine,EXTI_TriggerMode_t Copy_uddtMode)
{
	switch(Copy_uddtMode)
	{
		case EXTI_Falling:
		EXTI->RTSR&=~(1<<Copy_uddtLine);
		EXTI->FTSR|=(1<<Copy_uddtLine);
		break;
		case EXTI_Rising:
		EXTI->RTSR|=(1<<Copy_uddtLine);
		EXTI->FTSR&=~(1<<Copy_uddtLine);
		break;
		case EXTI_OnChange:
		EXTI->RTSR|=(1<<Copy_uddtLine);
		EXTI->FTSR|=(1<<Copy_uddtLine);
		break;
		default:
		break;
	}
}

void EXTI0_voidCallBack(void(*ptr)(void))
{
	Global_PtrEXTI0=ptr;
}

void EXTI0_IRQHandler()
{
	if(Global_PtrEXTI0!=NULL)
	{
		Global_PtrEXTI0();
		EXTI->PR|=(1<<0);
	}
}