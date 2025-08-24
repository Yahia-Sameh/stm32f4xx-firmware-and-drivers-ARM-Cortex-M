/*
 * SYSCFG_Private.h
 *
 *  Created on: Aug 4, 2025
 *      Author: cgame
 */

#ifndef SYSCFG_PRIVATE_H_
#define SYSCFG_PRIVATE_H_

#include <stdint.h>

/* SYSCFG Base Address (STM32F4) */
#define SYSCFG_BASE        0x40013800UL

/* EXTI Configuration Registers */
typedef struct {
    volatile uint32_t MEMRMP;      // Memory remap register
    volatile uint32_t PMC;         // Peripheral mode configuration
    volatile uint32_t EXTICR[4];   // EXTI configuration registers (4 registers)
    volatile uint32_t RESERVED[2];
    volatile uint32_t CMPCR;       // Compensation cell control register
} SYSCFG_TypeDef;

/* Macro to access SYSCFG registers */
#define SYSCFG             ((SYSCFG_TypeDef *)SYSCFG_BASE)

/* GPIO Port Selection (for EXTICR) */
typedef enum {
   PORTA = 0,
   PORTB,
   PORTC,
   PORTD,
   PORTE,
   PORTF,
   PORTG,
   PORTH
} SYSCFG_Port;

/* Function Prototype */
void syscfg_exti_map(uint8_t exti_line, SYSCFG_Port port);


#endif /* SYSCFG_PRIVATE_H_ */
