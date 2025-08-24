#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MSPI_Interface.h"
#include "MSPI_Private.h"
#include "MSPI_Config.h"

void MSPI_voidMasterInit()
{
	SPI1->CR1|=(1<<SSM);
	SPI1->CR1|=(1<<SSI);
	
	SPI1->CR1|=(1<<MSTR);
	SPI1->CR1|=(1<<CPOL);
	
	SPI1->CR1|=(1<<SPE);
	
}
void MSPI_voidSlaveInit()
{
	SPI1->CR1&=~(1<<MSTR);
	SPI1->CR1|=(1<<CPOL);
	
	SPI1->CR1|=(1<<SPE);
}
u16 MSPI_u16Tranceive(u16 Copy_u16Data)
{
	while(!GET_BIT(SPI1->SR,TXE));
	SPI1->DR=Copy_u16Data;
	while(!GET_BIT(SPI1->SR,RXNE));
	return (u16)(SPI1->DR);
}
