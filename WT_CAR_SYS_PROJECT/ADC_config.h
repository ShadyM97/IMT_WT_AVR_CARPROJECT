/*
 * ADC_config.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Shady
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define	AREF_VREF_OFF		0
#define AVCC				1
#define	INTERAL_V_VREF    	2

#define ADLAR_OFF			0
#define ADLAR_ON			1

#define ADC_PRESCALER_2		0
#define ADC_PRESCALER_4		1
#define ADC_PRESCALER_8		2
#define ADC_PRESCALER_16	3
#define ADC_PRESCALER_32	4
#define ADC_PRESCALER_64	5
#define ADC_PRESCALER_128	6

#define ADC_ENABLE			1
#define ADC_DISABLE			0

#define ADC_INTERRUPT_ENABLE		1
#define ADC__INTERRUPT_DISABLE		0

#define ADC_AUTO_TRIG_DISABLE		0
#define ADC_AUTO_TRIG_ENABLE		1


#define VOLTAGE_REF_SEL 	AVCC
/* Choose one
 * AREF_VREF_OFF
 * AVCC
 * INTERAL_2.56V_VREF
 * */


#define ADLAR_SEL	ADLAR_OFF
/*
 * Choose one
 * ADLAR_OFF
 * ADLAR_ON
 * */

#define ADC_ENABLE_SEL	ADC_ENABLE
/*
 * Choose one
 * ADC_ENABLE
 * ADC_DISABLE
 * */

#define ADC_INTERRUPT_SEL ADC_INTERRUPT_DISABLE
/*
 * Choose one
 * ADC_INTERRUPT_ENABLE
 * ADC_INTERRUPT_DISABLE
 * */

#define ADC_AUTO_TRIG_SEL ADC_AUTO_TRIG_DISABLE
/*
 * Choose one
 * ADC_AUTO_TRIG_DISABLE
 * ADC_AUTO_TRIG_ENABLE
 * */

#define ADC_PRESCALER_SELECT ADC_PRESCALER_128
/*
 * Choose one
 * ADC_PRESCALER_2
 * ADC_PRESCALER_4
 * ADC_PRESCALER_8
 * ADC_PRESCALER_16
 * ADC_PRESCALER_32
 * ADC_PRESCALER_64
 * ADC_PRESCALER_128
 * */

#endif /* ADC_CONFIG_H_ */
