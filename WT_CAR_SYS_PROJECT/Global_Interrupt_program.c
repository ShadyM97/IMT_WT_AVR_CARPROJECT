#include "STD_Types.h"
#include "BIT_Math.h"
#include "Global_Interrupt_interface.h"
#include "Global_Interrupt_private.h"

void Global_Interrupt_Enable(void)
{
	SET_BIT(SREG,I);
}
void Global_Interrupt_Disable(void)
{
	CLR_BIT(SREG,I);
}
