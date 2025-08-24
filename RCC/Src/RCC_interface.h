/*
 * RCC_interface.h
 *
 *  Created on: Aug 3, 2025
 *      Author: cgame
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* Clock Source Definitions */
#define HSI_CLK         0x00U  // HSI selected as system clock
#define HSE_CLK         0x01U  // HSE selected as system clock
#define PLL_CLK         0x02U  // PLL selected as system clock

/* Clock Status Definitions */
#define CLK_ON          0x01U
#define CLK_OFF         0x00U

/* Peripheral States */
#define ON          0x1U
#define OFF         0x1U

/* Bus Definitions */
#define AHB             0x00U
#define APB1            0x01U
#define APB2            0x02U
/* PLL Source Options */
#define PLL_HSI         0x00U
#define PLL_HSE         0x01U
#define PLL_HSE_DIV_2   0x03U

/* PLL Multiplication Factors */
#define PLL_MUL_2       0x00U
#define PLL_MUL_3       0x01U
/* ... up to PLL_MUL_16 ... */
/*---------------------------------------
  Peripheral Enable Macros (AHB1)
---------------------------------------*/
#define GPIOA_EN        0U   // Bit 0
#define GPIOB_EN        1U   // Bit 1
#define GPIOC_EN        2U   // Bit 2
#define GPIOD_EN        3U   // Bit 3
#define GPIOE_EN        4U   // Bit 4
#define GPIOH_EN        7U   // Bit 7
#define CRC_EN          12U  // Bit 12
#define DMA1_EN         21U  // Bit 21
#define DMA2_EN         22U  // Bit 22

/*---------------------------------------
  Peripheral Enable Macros (APB1)
---------------------------------------*/
#define TIM2_EN         0U   // Bit 0
#define TIM3_EN         1U   // Bit 1
#define TIM4_EN         2U   // Bit 2
#define TIM5_EN         3U   // Bit 3
#define WWDG_EN         11U  // Bit 11
#define SPI2_EN         14U  // Bit 14
#define SPI3_EN         15U  // Bit 15
#define USART2_EN       17U  // Bit 17
#define I2C1_EN         21U  // Bit 21
#define I2C2_EN         22U  // Bit 22
#define I2C3_EN         23U  // Bit 23
#define PWR_EN          28U  // Bit 28

/*---------------------------------------
  Peripheral Enable Macros (APB2)
---------------------------------------*/
#define TIM1_EN         0U   // Bit 0
#define USART1_EN       4U   // Bit 4
#define USART6_EN       5U   // Bit 5
#define ADC1_EN         8U   // Bit 8
#define SDIO_EN         11U  // Bit 11
#define SPI1_EN         12U  // Bit 12
#define SPI4_EN         13U  // Bit 13
#define SYSCFG_EN       14U  // Bit 14
#define TIM9_EN         16U  // Bit 16
#define TIM10_EN        17U  // Bit 17
#define TIM11_EN        18U  // Bit 18
#endif /* RCC_INTERFACE_H_ */
