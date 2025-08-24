

#ifndef MSTK_PRIVATE_H
#define MSTK_PRIVATE_H

#define MSTK_BASE_ADDRESS     (0xE000E010)
typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}MSTK_t;

#define STK   ((volatile MSTK_t*)MSTK_BASE_ADDRESS)

#define COUNT_FLAG     16
#define CLOCK_SOURCE   2
#define TICKINT        1
#define STK_ENABLE         0

#define  STK_AHB    0
#define  STK_AHB_8  1


#endif
