/*
 * main.c
 *
 *  Created on: Jan 12, 2024
 *      Author: Shady
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"
#include "seven_segment_interface.h"
#include "MSPI_interface.h"
#include "MUART_interface.h"
#include "EXTI_interface.h"
#include "MTWI_Driver_interface.h"
#include "Global_Interrupt_interface.h"
#include "HEEPROM_Driver_interface.h"
#include "HDCMOTOR_interface.h"
#include "HSERVO_interface.h"
#include <util/delay.h>

#define CAR_STOP		1
#define CAR_RUNNING		0

#define CAR_ON			1
#define CAR_OFF			0

#define CAR_STOP_LED_OFF	0
#define CAR_STOP_LED_ON		1

uint8 u8Carstop = CAR_RUNNING;
void APP_voidCarStop(void)
{
	if (u8Carstop == CAR_RUNNING)
	{
		u8Carstop = CAR_STOP;
	}
	else
	{
		u8Carstop = CAR_RUNNING;
	}
}

int main(void)
{
	uint8 UART_u8Data = 0;
	uint8 car_u8State = 0;
	uint8 u8Speed_Display = 0;
	uint8 u8I2CData = 0;

	// Initialize Peripherals and Electronic Components
	DIO_voidInit();
	DIO_voidPullUpState(PORT_D, DIO_PIN_NUM_D2, ENABLE_PULLUP);
	ADC_Init();
	UART_vInit();
	SPI_vMSTRInit();
	//TWI_vMasterInit();
	EXT_INTERRUPT_VID_INIT();
	EXT_INTERRUPT_VID_ENABLE(EXT0);
	EXT0_VID_SET_CALL_BACK(APP_voidCarStop);
	DCMOTOR_voidInit();
	SERVO_voidInit();
	Global_Interrupt_Enable();
	while(1)
	{
		UART_u8Data = UART_u8ReceiveData();

		// Commented as more PINS are needed
		//EEPROM_vByteRead(0xE5, &u8I2CData);
		//if (UART_u8Data == 'A' && u8I2CData)
		if (UART_u8Data == 'A')
		{
			car_u8State = CAR_ON;
		}
		else if (UART_u8Data == 'B')
		{
			car_u8State = CAR_OFF;
		}
		if (car_u8State == CAR_ON)
		{
			if (u8Carstop == CAR_RUNNING)
			{
				u8Speed_Display = DCMOTOR_voidPotControl(POT_ON);
				SPI_u8Transcieve(CAR_STOP_LED_OFF);
			}
			else
			{
				u8Speed_Display = DCMOTOR_voidPotControl(POT_OFF);
				SPI_u8Transcieve(CAR_STOP_LED_ON);
				_delay_ms(50);
			}
			SERVO_voidPotControl();
		}
		else
		{
			u8Speed_Display = DCMOTOR_voidPotControl(POT_OFF);
		}
		SevSeg_voidDisplay(u8Speed_Display, SEVEN_SEGMENT_PORT_NAME);
	}

	return 0;
}


