
#ifndef  MRCC_PRIVATE_H
#define  MRCC_PRIVATE_H
/* 
 * RCC (Reset and Clock Control) 
 * Steps to find the RCC base address:
 * 1- Open the Reference Manual
 * 2- Navigate to the Memory Map section
 * 3- Locate the RCC address in the AHB1 section
 */
#define RCC_BASE_ADDRESS      ((u32*)(0x40023800))
typedef struct{
	u32 CR;
    u32 PLLCFGR;
    u32 CFGR;
    u32 CIR;
    u32 AHB1RSTR;
    u32 AHB2RSTR;
    u32 Reserved1;
    u32 Reserved2;
    u32 APB1RSTR;
    u32 APB2RSTR;
    u32 Reserved3;
    u32 Reserved4;
    u32 AHB1ENR;
    u32 AHB2ENR;
    u32 Reserved5;
    u32 Reserved6;
    u32 APB1ENR;
    u32 APB2ENR;
    u32 Reserved7;
    u32 Reserved8;
    u32 AHB1LPENR;
    u32 AHB2LPENR;
    u32 Reserved9;
    u32 Reserved10;
    u32 APB1LPENR;
    u32 APB2LPENR;
    u32 Reserved11;
    u32 Reserved12;
    u32 BDCR;
    u32 CSR;
    u32 Reserved13;
    u32 Reserved14;
    u32 SSCGR;
    u32 PLLI2SCFGR;
    u32 Reserved15;
    u32 DCKCFGR;
}RCC_t;

#define RCC     ((volatile RCC_t*)RCC_BASE_ADDRESS)

#define HSION    0
#define HSIRDY   1

#define PLLON    24
#define PLLRDY   25

typedef enum{
	HSI_Oscillator=0,
	HSE_Oscillator,
	PLL
}System_Clock;

typedef enum{
	PLLM_2=2,
	PLLM_3,
	PLLM_4,
	PLLM_5
}PLL_M;

typedef enum{
	PLLN_2=2,
	PLLN_3,
	PLLN_4,
	PLLN_5
}PLL_N;

typedef enum{
	PLLP_0=0,
	PLLP_1,
	PLLP_2,
	PLLP_3
}PLL_P;

#define MUSK    3
#define SW0     0

#define RC_CLOCK               0
#define Mechanical_CLOCK       1

#define HSEBYP     18

#define HSEON     16
#define HSERDY   17

#endif
