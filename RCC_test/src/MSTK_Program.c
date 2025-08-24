#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MSTK_Interface.h"
#include "MSTK_Private.h"
#include "MSTK_Config.h"

static void (*Global_ptr)(void)=NULL;

void MSTK_voidInit()
{
	#if (STK_SYSTEM_CLK==STK_AHB_8)
		STK->CTRL&=~(1<<CLOCK_SOURCE);
	    STK->CTRL&=~(1<<STK_ENABLE);
	#elif (STK_SYSTEM_CLK==STK_AHB)
		STK->CTRL|=(1<<CLOCK_SOURCE);
	STK->CTRL&=~(1<<STK_ENABLE);
	#endif
}
void MSTK_voidStartTimer(u32 Copy_u32ReloadValue)
{
	STK->LOAD=Copy_u32ReloadValue;
	STK->VAL=0;
	STK->CTRL|=(1<<STK_ENABLE);
}
void MSTK_voidCtrlIntState(STK_IntState Copy_uddtIntState)
{
	STK->CTRL|=(Copy_uddtIntState<<TICKINT);
}
u8 MSTK_u8ReadFlag()
{
	return GET_BIT(STK->CTRL,COUNT_FLAG);
}
/*Function in Single shot*/
u32 MSTK_u32GetElapsedTickSingleShot()
{
	return ((STK->LOAD)-(STK->VAL));
}
u32 MSTK_u32GetRemainingTickSingleShot()
{
	return (STK->VAL);
}

void MSTK_voidDelayms(u32 Copy_u32Delayms)
{
	MSTK_voidCtrlIntState(Systick_IntDisable);
	MSTK_voidStartTimer(Copy_u32Delayms*2000);
	while(MSTK_u8ReadFlag()==0);
	STK->CTRL&=~(1<<STK_ENABLE);
}
void MSTK_voidDelayus(u32 Copy_u32Delayus)
{
	MSTK_voidCtrlIntState(Systick_IntDisable);
	MSTK_voidStartTimer(Copy_u32Delayus*2);
	while(MSTK_u8ReadFlag()==0);
	STK->CTRL&=~(1<<STK_ENABLE);
}

void MSTK_voidCallBack(void(*ptr)(void), u32 Copy_u32TickTime)
{
	Global_ptr=ptr;
	MSTK_voidStartTimer(Copy_u32TickTime*2);
}

void SysTick_Handler()
{
	if(Global_ptr!=NULL)
	{
		Global_ptr();
	}
}
