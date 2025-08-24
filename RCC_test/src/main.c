
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "MSPI_Interface.h"
#include "HTFT_Interface.h"
#include "HTFT_Image.h"


int main()
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(AHB1_BUS,AHB1_GPIOA);
	MRCC_voidEnablePeripheralClock(APB2_BUS,APB2_SPI1);
	MSTK_voidInit();

	MGPIO_voidSetMode(PORTA,PIN4,Alternative_Func);
	MGPIO_voidSetAlternativeConfig(PORTA,PIN4,AF5);

	MGPIO_voidSetMode(PORTA,PIN5,Alternative_Func);
	MGPIO_voidSetAlternativeConfig(PORTA,PIN5,AF5);

	MGPIO_voidSetMode(PORTA,PIN6,Alternative_Func);
	MGPIO_voidSetAlternativeConfig(PORTA,PIN6,AF5);

	MGPIO_voidSetMode(PORTA,PIN7,Alternative_Func);
	MGPIO_voidSetAlternativeConfig(PORTA,PIN7,AF5);

	MSPI_voidMasterInit();
	HTFT_voidInit();
	HTFT_voidDisplay(arr);
	while(1)
	{

	}
}


