/*
 * TIMER0_interface.h
 *
 *  Created on: Oct 14, 2023
 *      Author: ahmed saeed
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TIMER0_PRESCALER_1          	1
#define TIMER0_PRESCALER_8           	2
#define TIMER0_PRESCALER_64          	3
#define TIMER0_PRESCALER_256         	4
#define TIMER0_PRESCALER_1024       	5
#define TIMER0_EXTERNAL_CLOCK_FALLING 	6
#define TIMER0_EXTERNAL_CLOCK_RISING 	7
#define OCR0_MAX_VALUE			255


void TIMER0_voidInit(void);
void TIMER0_voidEnable(uint8 u8Prescaler);
void TIMER0_voidDisable(void);
void TIMER0_voidEnableOvfInt(void);
void TIMER0_voidDisableOvfInt(void);
void TIMER0_voidEnableComInt(void);
void TIMER0_voidDisableComInt(void);
void TIMER0_voidSetTCNTValue(uint8 u8ValueCpy);
void TIMER0_voidSetOCRValue(uint8 u8ValueCpy);
uint8 TIMER0_u8ReadTcntReg(void);

void TIMER0_voidSetCallBackOvfInt(pf pfOvfcallbackCpy);
void TIMER0_voidSetCallBackCompareInt(pf pfComcallbackCpy);

#endif /* TIMER0_INTERFACE_H_ */
