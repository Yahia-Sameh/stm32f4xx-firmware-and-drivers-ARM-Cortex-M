#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSTK_Interface.h"

#include "OS_Interface.h"
#include "OS_Private.h"
#include "OS_Config.h"

Task_t System_Task[NO_OF_TASKS]={{0}};
u16 Task_Timing[NO_OF_TASKS]={0};
u8 OS_u8CreateTask(void(*ptr)(void),u16 Copy_u16Periodicity,u16 Copy_u16Priority,u8 Copy_u8FirstDelay)
{
	u8 Copy_u8ErrorState=0;
	if(Copy_u16Priority<NO_OF_TASKS)
	{
		if(ptr!=NULL)
		{
			if(System_Task[Copy_u16Priority].Task_PTR==0)
			{
				System_Task[Copy_u16Priority].Task_PTR=ptr;
				System_Task[Copy_u16Priority].Task_Periodicity=Copy_u16Periodicity;
				Task_Timing[Copy_u16Priority]=Copy_u8FirstDelay;
			}
			else
			{
				Copy_u8ErrorState=3;
			}
		}
		else
		{
			Copy_u8ErrorState=2;
		}
	}
	else
	{
		Copy_u8ErrorState=1;
	}
	return Copy_u8ErrorState;
}

void OS_voidScheduler(void)
{
	u8 Local_u8Iterator;
	for(Local_u8Iterator=0;Local_u8Iterator<NO_OF_TASKS;Local_u8Iterator++)
	{
		if(System_Task[Local_u8Iterator].Task_PTR!=0)
		{
			if(Task_Timing[Local_u8Iterator]==0)
			{
				System_Task[Local_u8Iterator].Task_PTR();
				Task_Timing[Local_u8Iterator]=System_Task[Local_u8Iterator].Task_Periodicity;
			}
			Task_Timing[Local_u8Iterator]--;
		}
	}
}

void OS_voidStart(u32 Copy_u32TickTimeus)
{
	MSTK_voidCallBack(OS_voidScheduler,Copy_u32TickTimeus);
	MSTK_voidCtrlIntState(Systick_IntEnable);
}
