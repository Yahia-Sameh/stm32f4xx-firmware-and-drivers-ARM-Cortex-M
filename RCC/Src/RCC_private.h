/*
 * RCC_private.h
 *
 *  Created on: Aug 3, 2025
 *      Author: cgame
 */

#include "stdint.h"
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_Base_Address  (0x40023800)

typedef struct {
    uint32_t CR;            /* RCC clock control register,                  Address offset: 0x00 */
    uint32_t PLLCFGR;       /* RCC PLL configuration register,              Address offset: 0x04 */
    uint32_t CFGR;          /* RCC clock configuration register,            Address offset: 0x08 */
    uint32_t CIR;           /* RCC clock interrupt register,                Address offset: 0x0C */
    uint32_t AHB1RSTR;      /* RCC AHB1 peripheral reset register,          Address offset: 0x10 */
    uint32_t AHB2RSTR;      /* RCC AHB2 peripheral reset register,          Address offset: 0x14 */
    uint32_t      RESERVED0[2];  /* Reserved,                                    0x18-0x1C */
    uint32_t APB1RSTR;      /* RCC APB1 peripheral reset register,          Address offset: 0x20 */
    uint32_t APB2RSTR;      /* RCC APB2 peripheral reset register,          Address offset: 0x24 */
    uint32_t      RESERVED1[2];  /* Reserved,                                    0x28-0x2C */
   uint32_t AHB1ENR;       /* RCC AHB1 peripheral clock enable register,   Address offset: 0x30 */
   uint32_t AHB2ENR;       /* RCC AHB2 peripheral clock enable register,   Address offset: 0x34 */
    uint32_t      RESERVED2[2];  /* Reserved,                                    0x38-0x3C */
    uint32_t APB1ENR;       /* RCC APB1 peripheral clock enable register,   Address offset: 0x40 */
    uint32_t APB2ENR;       /* RCC APB2 peripheral clock enable register,   Address offset: 0x44 */
    uint32_t      RESERVED3[2];  /* Reserved,                                    0x48-0x4C */
    uint32_t AHB1LPENR;     /* RCC AHB1 peripheral clock enable in low power mode register, 0x50 */
    uint32_t AHB2LPENR;     /* RCC AHB2 peripheral clock enable in low power mode register, 0x54 */
    uint32_t      RESERVED4[2];  /* Reserved,                                    0x58-0x5C */
    uint32_t APB1LPENR;     /* RCC APB1 peripheral clock enable in low power mode register, 0x60 */
    uint32_t APB2LPENR;     /* RCC APB2 peripheral clock enable in low power mode register, 0x64 */
    uint32_t      RESERVED5[2];  /* Reserved,                                    0x68-0x6C */
     uint32_t BDCR;          /* RCC Backup domain control register,          Address offset: 0x70 */
     uint32_t CSR;           /* RCC clock control & status register,         Address offset: 0x74 */
    uint32_t      RESERVED6[2];  /* Reserved,                                    0x78-0x7C */
     uint32_t SSCGR;         /* RCC spread spectrum clock generation register, 0x80 */
     uint32_t PLLI2SCFGR;    /* RCC PLLI2S configuration register,           Address offset: 0x84 */
     uint32_t DCKCFGR;       /* RCC Dedicated Clocks Configuration Register, Address offset: 0x8C */
} RCC_TypeDef;

#define MRCC ((RCC_TypeDef *) RCC_Base_Address)

void RCC_vEnableClock(uint8_t Copy_u8Bus, uint8_t Copy_u8Peripheral);
void RCC_vDisableClock(uint8_t Copy_u8Bus, uint8_t Copy_u8Peripheral);
void RCC_vSetSysClk(uint8_t Copy_u8ClkSource);
void RCC_vHSICmd(uint8_t Copy_u8State);
void RCC_vHSECmd(uint8_t Copy_u8State);
void RCC_vPLLCmd(uint8_t Copy_u8State);
void RCC_vConfigurePLL(uint8_t Copy_u8PllSrc, uint8_t Copy_u8PllM, uint8_t Copy_u8PllN, uint8_t Copy_u8PllP);


#endif /* RCC_PRIVATE_H_ */
