
#ifndef  MRCC_CONFIG_H
#define  MRCC_CONFIG_H

/* Choose Between:
 * 1-HSI_CLOCK
 * 2-HSE_CLOCK
 * 3-PLL 
 */

#define SYSTEM_CLOCK   HSI_CLOCK
#define PLLM			3
#define PLLN			3
#define PLLP			3

/* Choose Between:
 * 1-RC_CLOCK
 * 2-Mechanical_CLOCK
 */
#define HSE_OS     Mechanical_CLOCK
#endif

