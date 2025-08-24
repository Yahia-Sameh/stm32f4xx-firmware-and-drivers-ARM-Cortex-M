
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

u8 OS_u8CreateTask(void(*ptr)(void),u16 Copy_u16Periodicity,u16 Copy_u16Priority,u8 Copy_u8FirstDelay);
void OS_voidStart(u32 Copy_u32TickTimeus);

#endif
