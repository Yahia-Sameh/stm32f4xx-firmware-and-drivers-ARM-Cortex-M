/*
 * STK_config.h
 *
 *  Created on: Aug 5, 2025
 *      Author: cgame
 */

#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_

#include "STK_private.h"

/* System clock frequency (must match your system configuration) */
#define SYSTEM_CLOCK_FREQ_HZ     16000000UL  /* 16 MHz */

/* SysTick Configuration */
#define SYSTICK_CLOCK_SOURCE     SYSTICK_CLKSOURCE_AHB_DIV8
#define SYSTICK_INTERRUPT        SYSTICK_INT_DISABLE

#endif /* STK_CONFIG_H_ */
