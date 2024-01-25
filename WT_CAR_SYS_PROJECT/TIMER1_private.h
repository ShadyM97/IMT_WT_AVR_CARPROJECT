/*
 * TIMER1_private.h
 *
 *  Created on: Oct 14, 2023
 *      Author: ahmed saeed
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define NORMAL_MODE         1
#define CTC_MODE            2
#define FAST_PWM_OCR1A_TOP  3
#define FAST_PWM_ICR1_TOP	4
#define PHASE_CORRECT_PWM   5

#define CLEAR_OC1A           1
#define SET_OC1A             2
#define TOGGLE_OC1A          3

#define CLEAR_OC1B           1
#define SET_OC1B             2
#define TOGGLE_OC1B          3

#define INVERTING_FAST_PWM_OC1A                       1
#define NON_INVERTING_FAST_PWM_OC1A                   2
#define INVERTING_PHASE_CORRECT_PWM_OC1A              3
#define NON_INVERTING_PHASE_CORRECT_PWM_OC1A          4

#define INVERTING_FAST_PWM_OC1B                       1
#define NON_INVERTING_FAST_PWM_OC1B                   2
#define INVERTING_PHASE_CORRECT_PWM_OC1B              3
#define NON_INVERTING_PHASE_CORRECT_PWM_OC1B          4

#define DISCONNECT_OC1A                           0
#define DISCONNECT_OC1B                           0

#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1B1	5
#define	TCCR1A_COM1B0	4
#define	TCCR1A_FOC1A	3
#define TCCR1A_FOC1B	2
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10	1

#define TCCR1B_ICNC1	7
#define TCCR1B_ICES1	6
#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3
#define TCCR1B_CS12		2
#define TCCR1B_CS11		1
#define TCCR1B_CS10		0

#define TIMSK_TICIE1	5
#define TIMSK_OCIE1A	4
#define TIMSK_OCIE1B	3
#define TIMSK_TOIE1		2

#define TCCR1A      *((volatile  uint8*) 0x4F)
#define TCCR1B		*((volatile  uint8*) 0x4E)
#define TCNT1       *((volatile  uint16*) 0x4C)
#define OCR1A       *((volatile  uint16*) 0x4A)
#define OCR1B       *((volatile  uint16*) 0x48)
#define ICR1		*((volatile  uint16*) 0x46)
#define TIMSK       *((volatile  uint8*) 0x59)
#define TIFR        *((volatile  uint8*) 0x58)

#endif /* TIMER1_PRIVATE_H_ */
