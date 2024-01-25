/*
 * HSERVO_interface.h
 *
 *  Created on: Jan 14, 2024
 *      Author: Shady
 */
#ifndef HSERVO_INTERFACE_H_
#define HSERVO_INTERFACE_H_

#define DISABLE_ADC		0
#define ENABLE_ADC		1

#define OCRA1_SERVO_MIN			500
#define OCRA1_SERVO_MAX			2500


void SERVO_voidInit(void);
void SERVO_voidPotControl(void);

#endif /* HSERVO_INTERFACE_H_ */
