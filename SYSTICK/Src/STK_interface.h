/*
 * STK_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: cgame
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

#include <stdint.h>

/* Initialize SysTick with configured settings */
void SYSTICK_Init(void);

/* Delay functions */
void SYSTICK_DelayMs(uint32_t milliseconds);
void SYSTICK_DelayUs(uint32_t microseconds);

/* Utility functions */
uint32_t SYSTICK_GetRemainingTicks(void);
void SYSTICK_SetReloadValue(uint32_t value);

#endif /* STK_INTERFACE_H_ */
