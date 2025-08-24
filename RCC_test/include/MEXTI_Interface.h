
#ifndef MEXTI_INTERFCAE_H
#define MEXTI_INTERFCAE_H

typedef enum{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15
}EXTI_Line_t;

typedef enum{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC
}EXTI_Port_t;
typedef enum{
	EXTI_Falling,
	EXTI_Rising,
	EXTI_OnChange
}EXTI_TriggerMode_t;

void EXTI_voidSetInterruptPort(EXTI_Line_t Copy_uddtLine,EXTI_Port_t Copy_uddtPort);
void MEXTI_voidEnable(EXTI_Line_t Copy_uddtLine);
void MEXTI_voidDisable(EXTI_Line_t Copy_uddtLine);
void MEXTI_voidSetTrigger(EXTI_Line_t Copy_uddtLine,EXTI_TriggerMode_t Copy_uddtMode);
void EXTI0_voidCallBack(void(*ptr)(void));

#endif