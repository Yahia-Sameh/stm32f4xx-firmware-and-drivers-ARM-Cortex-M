
#ifndef  MRCC_INTERFACE_H
#define  MRCC_INTERFACE_H

typedef enum{
	AHB1_BUS=0,
	AHB2_BUS,
	APB1_BUS,
	APB2_BUS
}System_Bus;

void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(System_Bus Copy_uddtBus,u32 Copy_u32Peripheral);
void MRCC_voidDisablePeripheralClock(System_Bus Copy_uddtBus,u32 Copy_u32Peripheral);

#define HSI_CLOCK  0
#define HSE_CLOCK  1
#define PLL_HSI_CLOCK  2
#define PLL_HSE_CLOCK  3

/*****************AHB1***************/

#define AHB1_GPIOA    0
#define AHB1_GPIOB    1
#define AHB1_GPIOC    2
#define AHB1_DMA1     21
#define AHB1_DMA2     22

/*****************APB1***************/
#define APB1_SPI2     14
#define APB1_SPI3     15
#define APB1_USART2   17
#define APB1_I2C1     21  
#define APB1_I2C2     22 
#define APB1_I2C3     23    

/*****************APB2***************/
#define APB2_USART1   4
#define APB2_USART6   5
#define APB2_SPI1     12    

#endif
