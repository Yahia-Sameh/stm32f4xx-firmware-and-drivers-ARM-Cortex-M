
#include "STD_TYPES.H"
#include "BIT_MATH.h"

#include "MRCC_Interface.h"
#include "MRCC_Private.h"
#include "MRCC_Config.h"

void MRCC_voidInit(void)
{
	#if (SYSTEM_CLOCK==HSI_CLOCK)
		//HSI ON
	    RCC->CR|=(1<<HSION_BIT);
	    //Wait till HSI ready
		while(!GET_BIT(RCC->CR,HSIRDY_BIT));
		//while(GET_BIT(RCC->CR,HSERDY_BIT)==0);
		//Switch to HSI
	    RCC->CFGR&=~(SW_MASK<<SW0);
		RCC->CFGR|=(HSI_Osillator<<SW0);
    #elif (SYSTEM_CLOCK==HSE_CLOCK)
		#if (HSE_OS==MECHANICAL_CLOCK)
			RCC->CR&=~(1<<HSEBYP_BIT);
		#elif (HSE_OS==RC_CLOCK)
			RCC->CR|=(1<<HSEBYP_BIT);
		#endif

		//HSE ON
	    RCC->CR|=(1<<HSEON_BIT);
	    //Wait till HSE ready
		while(!GET_BIT(RCC->CR,HSERDY_BIT));
		//Switch to HSE
	    RCC->CFGR&=~(SW_MASK<<SW0);
		RCC->CFGR|=(HSE_Osillator<<SW0);
		//Disable HSI
		RCC->CR&=~(1<<HSION_BIT);

	#endif
}

void MRCC_voidEnablePeripheralClock(System_Bus Copy_uddtBus,u32 Copy_u32Peripheral)
{
	if(Copy_u32Peripheral<32)
	{
		switch(Copy_uddtBus)
		{
			case AHB1_BUS:RCC->AHB1ENR|=(1<<Copy_u32Peripheral); break;
			case AHB2_BUS:RCC->AHB2ENR|=(1<<Copy_u32Peripheral); break;
			case APB1_BUS:RCC->APB1ENR|=(1<<Copy_u32Peripheral); break;
			case APB2_BUS:RCC->APB2ENR|=(1<<Copy_u32Peripheral); break;
		}
	}
	else{
		/**/
	}
}
void MRCC_voidDisablePeripheralClock(System_Bus Copy_uddtBus,u32 Copy_u32Peripheral)
{
		if(Copy_u32Peripheral<32)
	{
		switch(Copy_uddtBus)
		{
			case AHB1_BUS:RCC->AHB1ENR&=~(1<<Copy_u32Peripheral); break;
			case AHB2_BUS:RCC->AHB2ENR&=~(1<<Copy_u32Peripheral); break;
			case APB1_BUS:RCC->APB1ENR&=~(1<<Copy_u32Peripheral); break;
			case APB2_BUS:RCC->APB2ENR&=~(1<<Copy_u32Peripheral); break;
		}
	}
	else{
		/**/
	}
}
