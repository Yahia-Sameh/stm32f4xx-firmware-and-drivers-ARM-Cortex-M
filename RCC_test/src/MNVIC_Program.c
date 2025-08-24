
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MNVIC_Interface.h"
#include "MNVIC_Private.h"
#include "MNVIC_Config.h"

void MNVIC_voidEnable(u8 Copy_u8Position)
{
	NVIC->ISER[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV));
}
void MNVIC_voidDisable(u8 Copy_u8Position)
{
	NVIC->ICER[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV));
}
void MNVIC_voidSetPendingFlag(u8 Copy_u8Position)
{
	NVIC->ISPR[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV));
}
void MNVIC_voidClearPendingFlag(u8 Copy_u8Position)
{
	NVIC->ICPR[Copy_u8Position/REG_DIV]|=(1<<(Copy_u8Position%REG_DIV));
}
u8 MNVIC_u8ReadingActiveState(u8 Copy_u8Position)
{
	return GET_BIT(NVIC->IABR[Copy_u8Position/REG_DIV],(Copy_u8Position%REG_DIV));
}
