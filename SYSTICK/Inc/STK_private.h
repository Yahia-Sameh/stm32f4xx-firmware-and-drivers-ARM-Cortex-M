/*
 * STK_private.h
 *
 *  Created on: Aug 5, 2025
 *      Author: cgame
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_


#include <stdint.h>

/* SysTick Register Structure */
typedef struct {
    volatile uint32_t CTRL;   /* Control and Status Register */
    volatile uint32_t LOAD;   /* Reload Value Register */
    volatile uint32_t VAL;    /* Current Value Register */
    volatile uint32_t CALIB;  /* Calibration Register */
} SYSTICK_TypeDef;

/* SysTick Base Address */
#define SYSTICK_BASE    0xE000E010UL
#define MSYSTICK        ((SYSTICK_TypeDef *)SYSTICK_BASE)

/* CTRL Register Bit Definitions */
#define SYSTICK_CTRL_ENABLE      (0U)    /* Counter enable */
#define SYSTICK_CTRL_TICKINT     (1U)    /* Interrupt enable */
#define SYSTICK_CTRL_CLKSOURCE   (2U)    /* Clock source selection */
#define SYSTICK_CTRL_COUNTFLAG   (16U)   /* Count flag */

/* Clock Source Selection */
typedef enum {
    SYSTICK_CLKSOURCE_AHB_DIV8 = 0,
    SYSTICK_CLKSOURCE_AHB = 1
} SYSTICK_ClkSource;

/* Interrupt Control */
typedef enum {
    SYSTICK_INT_DISABLE = 0,
    SYSTICK_INT_ENABLE = 1
} SYSTICK_IntControl;

/* Function prototypes for internal use */
static void SYSTICK_Enable(void);
static void SYSTICK_Disable(void);
static void SYSTICK_WaitForCount(void);
#endif /* STK_PRIVATE_H_ */
