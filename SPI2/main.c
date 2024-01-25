/*
 * main.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Shady
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "MSPI_interface.h"
#include "util/delay.h"

#define CAR_STOP_LED_ON		1
int main(void)
{
	uint8 localu8ReceivedData;
	DIO_voidInit();
	/* Enable Pull up for SS */
	DIO_voidPullUpState(PORT_B, DIO_PIN_NUM_B4, ENABLE_PULLUP);
	SPI_vSLAVEINIT();

	while(1)
	{
		localu8ReceivedData = SPI_u8Transcieve(0);
		if (localu8ReceivedData == CAR_STOP_LED_ON)
		{
			DIO_voidWritePin(PORT_D, DIO_PIN_NUM_D0, DIO_HIGH);
		}
		else
		{
			DIO_voidWritePin(PORT_D, DIO_PIN_NUM_D0, DIO_LOW);
		}
	}
}

