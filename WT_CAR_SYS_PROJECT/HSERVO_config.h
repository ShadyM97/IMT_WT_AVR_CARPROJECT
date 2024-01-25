/*
 * HSERVO_config.h
 *
 *  Created on: Jan 14, 2024
 *      Author: Shady
 */

#ifndef HSERVO_CONFIG_H_
#define HSERVO_CONFIG_H_

#define SERVO_PWM_FREQUENCY_SETTER 	19999
/**
 * 19999 for CPU Clock 8MHz
 * 39999 for CPU Clock 16MHz
 */

#define ADC_CONTROL		ENABLE_ADC
#define ADC_CHANNEL		Channel_A1

#endif /* HSERVO_CONFIG_H_ */
