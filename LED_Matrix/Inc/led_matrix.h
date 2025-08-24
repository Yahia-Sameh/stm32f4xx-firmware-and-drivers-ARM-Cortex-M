#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include <stdint.h>

// Memory-mapped register addresses for STM32F401
#define PERIPH_BASE           0x40000000UL
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define APB1PERIPH_BASE       (PERIPH_BASE + 0x00000000UL)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)

// GPIO registers structure
typedef struct {
    volatile uint32_t MODER;    // GPIO port mode register
    volatile uint32_t OTYPER;   // GPIO port output type register
    volatile uint32_t OSPEEDR;  // GPIO port output speed register
    volatile uint32_t PUPDR;    // GPIO port pull-up/pull-down register
    volatile uint32_t IDR;      // GPIO port input data register
    volatile uint32_t ODR;      // GPIO port output data register
    volatile uint32_t BSRR;     // GPIO port bit set/reset register
    volatile uint32_t LCKR;     // GPIO port configuration lock register
    volatile uint32_t AFR[2];   // GPIO alternate function registers
} GPIO_TypeDef;

// RCC registers structure
typedef struct {
    volatile uint32_t CR;       // Clock control register
    volatile uint32_t PLLCFGR;  // PLL configuration register
    volatile uint32_t CFGR;     // Clock configuration register
    volatile uint32_t CIR;      // Clock interrupt register
    volatile uint32_t AHB1RSTR; // AHB1 peripheral reset register
    volatile uint32_t AHB2RSTR; // AHB2 peripheral reset register
    volatile uint32_t AHB3RSTR; // AHB3 peripheral reset register
    uint32_t      RESERVED0;
    volatile uint32_t APB1RSTR; // APB1 peripheral reset register
    volatile uint32_t APB2RSTR; // APB2 peripheral reset register
    uint32_t      RESERVED1[2];
    volatile uint32_t AHB1ENR;  // AHB1 peripheral clock enable register
    volatile uint32_t AHB2ENR;  // AHB2 peripheral clock enable register
    volatile uint32_t AHB3ENR;  // AHB3 peripheral clock enable register
    uint32_t      RESERVED2;
    volatile uint32_t APB1ENR;  // APB1 peripheral clock enable register
    volatile uint32_t APB2ENR;  // APB2 peripheral clock enable register
    uint32_t      RESERVED3[2];
    volatile uint32_t AHB1LPENR;// AHB1 peripheral clock enable in low power mode register
    volatile uint32_t AHB2LPENR;// AHB2 peripheral clock enable in low power mode register
    volatile uint32_t AHB3LPENR;// AHB3 peripheral clock enable in low power mode register
    uint32_t      RESERVED4;
    volatile uint32_t APB1LPENR;// APB1 peripheral clock enable in low power mode register
    volatile uint32_t APB2LPENR;// APB2 peripheral clock enable in low power mode register
    uint32_t      RESERVED5[2];
    volatile uint32_t BDCR;     // Backup domain control register
    volatile uint32_t CSR;      // Clock control & status register
    uint32_t      RESERVED6[2];
    volatile uint32_t SSCGR;    // Spread spectrum clock generation register
    volatile uint32_t PLLI2SCFGR;// PLLI2S configuration register
} RCC_TypeDef;

// Peripheral base addresses
#define GPIOA_BASE           (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE           (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE           (AHB1PERIPH_BASE + 0x0800UL)
#define RCC_BASE             (AHB1PERIPH_BASE + 0x3800UL)

// Peripheral declarations
#define GPIOA               ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *)GPIOC_BASE)
#define RCC                 ((RCC_TypeDef *)RCC_BASE)

// RCC AHB1ENR bits
#define RCC_AHB1ENR_GPIOAEN (1 << 0)
#define RCC_AHB1ENR_GPIOBEN (1 << 1)
#define RCC_AHB1ENR_GPIOCEN (1 << 2)

// GPIO modes
#define GPIO_MODE_INPUT     0x00
#define GPIO_MODE_OUTPUT    0x01
#define GPIO_MODE_AF        0x02
#define GPIO_MODE_ANALOG    0x03

// LED Matrix configuration
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

typedef struct {
    GPIO_TypeDef* row_ports[MATRIX_ROWS];
    uint16_t row_pins[MATRIX_ROWS];
    GPIO_TypeDef* col_ports[MATRIX_COLS];
    uint16_t col_pins[MATRIX_COLS];
    uint8_t buffer[MATRIX_ROWS];
    uint8_t current_row;
} LED_Matrix;

// Function prototypes
void LEDMX_Init(LED_Matrix* matrix);
void LEDMX_Clear(LED_Matrix* matrix);
void LEDMX_SetPixel(LED_Matrix* matrix, uint8_t x, uint8_t y, uint8_t state);
void LEDMX_Refresh(LED_Matrix* matrix);
void LEDMX_LoadFrame(LED_Matrix* matrix, const uint8_t frame[MATRIX_ROWS]);

#endif // LED_MATRIX_H
