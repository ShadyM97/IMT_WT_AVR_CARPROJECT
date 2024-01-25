/*
 * HDCMOTOR_program.c
 *
 *  Created on: Jan 14, 2024
 *      Author: Shady
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "EXTI_interface.h"
#include "TIMER0_interface.h"
#include "HDCMOTOR_config.h"
#include "HDCMOTOR_interface.h"

// Using 7 Segment
#define SPEED_DISPLAY_MAX	9

/**
 * Function: DCMOTOR_voidInit
 * Description: Initialize motor by initializing timer PWM
 *
 * Parameters: void
 *
 * Returns: void
 */
void DCMOTOR_voidInit(void)
{
	TIMER0_voidInit();
	TIMER0_voidEnable(TIMER0_PRESCALER_1);
}

/**
 * Function: DCMOTOR_voidPotControl
 * Description: Controls motor speed using a potentiometer
 *
 * Parameters:
 * @u8potState: To enable and disable the potentiometer
 *
 * Returns: Motor Speed
 */
uint8 DCMOTOR_voidPotControl(uint8 u8potState)
{
	static uint16 u16Pot_Speed_Reading = 0;
	static uint8 u8OCR_CONVERSION = 0;
	uint8 u8Speed_Display = 0;
	if (u8potState == POT_ON)
	{
		u16Pot_Speed_Reading = ADC_Read(Channel_A0);
	}
	else
	{
		u16Pot_Speed_Reading = 0;
	}
	// Make Calculations to set the Timer OCR Value and get motor speed to display
	u8Speed_Display =	(uint16)u16Pot_Speed_Reading * SPEED_DISPLAY_MAX / (ADC_RESOLUTION);
	u8OCR_CONVERSION = 	(uint32)u16Pot_Speed_Reading * OCR0_MAX_VALUE / (ADC_RESOLUTION);
	TIMER0_voidSetOCRValue(u8OCR_CONVERSION);

	return u8Speed_Display;
}
