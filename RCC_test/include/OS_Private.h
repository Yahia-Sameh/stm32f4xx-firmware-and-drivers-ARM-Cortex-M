
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct{
	//Action
	void(*Task_PTR)(void);
	//Periodicity
	u16 Task_Periodicity;
}Task_t;

#endif