
#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

typedef enum{
	PORTA,
	PORTB,
	PORTC
}Port_t;
typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;

typedef enum{
	INPUT,
	OUTPUT,
	Alternative_Func,
	Analog
}Modes_t;
typedef enum{
	Push_Pull,
	Open_Drain
}Output_t;
typedef enum{
	Low_Speed,
	Med_Speed,
	High_Speed,
	VHigh_Speed
}Speed_t;
typedef enum{
	LOW,
	HIGH
}PinValue_t;
typedef enum{
	NOPULLUPORPULLDOWN,
	PULLUP,
	PULLDOWN
}Input_t;

typedef enum{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}Alternative_t;

void MGPIO_voidSetMode(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Modes_t Copy_uddtMode);
/*Output Mode*/
void MGPIO_voidSetOutputConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Output_t Copy_uddtType,Speed_t Copy_uddtSpeed);
void MGPIO_voidSetPinValue(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,PinValue_t Copy_uddtPinValue);
void MGPIO_voidSetPinValueAtomic(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,PinValue_t Copy_uddtPinValue);
/*Input Mode*/
void MGPIO_voidSetInputConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Input_t Copy_uddtType);
u8 MGPIO_u8GetPinValue(Port_t Copy_uddtPort,PIN_t Copy_uddtPin);
/*Alternative Mode*/
void MGPIO_voidSetAlternativeConfig(Port_t Copy_uddtPort,PIN_t Copy_uddtPin,Alternative_t Copy_uddtType);


#endif