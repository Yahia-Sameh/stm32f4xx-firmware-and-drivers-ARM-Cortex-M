
#ifndef MGPIO_PRIVATE_H
#define MGPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS      (0x40020000)
#define GPIOB_BASE_ADDRESS      (0x40020400)
#define GPIOC_BASE_ADDRESS      (0x40020800)

typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDER;
	u32 PUPDR;
    u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_t;

volatile GPIO_t* ARRAY_BASE_ADDRESS[3] = {
    GPIOA_BASE_ADDRESS,
    GPIOB_BASE_ADDRESS,
    GPIOC_BASE_ADDRESS
};

#define GPIOA      ((volatile GPIO_t*)GPIOA_BASE_ADDRESS)
#define GPIOB      ((volatile GPIO_t*)GPIOB_BASE_ADDRESS)
#define GPIOC      ((volatile GPIO_t*)GPIOC_BASE_ADDRESS)

#define MUSK   3
#define ALT_MUSK   15


#endif
