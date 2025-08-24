
#ifndef MEXTI_PRIVATE_H
#define MEXTI_PRIVATE_H

#define SYSCFG_BASE_ADDRESS  (0x40013800)
#define EXTI_BASE_ADDRESS    (0x40013C00)

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 RESERVED[2];
	u32 CMPCR;
}SYSCFG_t;

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

#define SYSCFG    ((volatile SYSCFG_t*)SYSCFG_BASE_ADDRESS)
#define EXTI   ((volatile EXTI_t*)EXTI_BASE_ADDRESS)
#define SYS_DIV   4
#define SYS_MUSK  15

#endif
