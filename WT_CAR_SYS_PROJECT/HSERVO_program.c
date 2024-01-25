/*
 * HSERVO_program.c
 *
 *  Created on: Jan 14, 2024
 *      Author: Shady
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "TIMER1_interface.h"
#include "HSERVO_config.h"
#include "HSERVO_interface.h"

/**
 * Function: SERVO_voidInit
 * Description: Initialize servo motor by initializing timer1 to PWM
 *
 * Parameters: void
 *
 *
 * Returns: void
 */
void SERVO_voidInit(void)
{
	TIMER1_voidInit();
	TIMER1_voidSetICRValue(SERVO_PWM_FREQUENCY_SETTER);
	TIMER1_voidSetTCNTValue(0);
	TIMER1_voidEnable(TIMER1_PRESCALER_8);
}

/**
 * Function: SERVO_voidPotControl
 * Description: Control servo motor using a potentiometer
 *
 * Parameters: void
 *
 *
 * Returns: void
 */
void SERVO_voidPotControl(void)
{
	static uint16 u16Pot_Position_Reading = 0;
	static uint16 u16OCR1A_CONVERSION = 0;

	u16Pot_Position_Reading = ADC_Read(ADC_CHANNEL);
	u16OCR1A_CONVERSION = ((uint32)u16Pot_Position_Reading * (OCRA1_SERVO_MAX -OCRA1_SERVO_MIN) / (ADC_RESOLUTION)) + OCRA1_SERVO_MIN;
	TIMER1_voidSetOCRAValue(u16OCR1A_CONVERSION);

}
