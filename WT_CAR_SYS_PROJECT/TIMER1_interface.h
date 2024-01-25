/*
 * TIMER1_interface.h
 *
 *  Created on: Oct 14, 2023
 *      Author: ahmed saeed
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define TIMER1_PRESCALER_1          	1
#define TIMER1_PRESCALER_8           	2
#define TIMER1_PRESCALER_64          	3
#define TIMER1_PRESCALER_256         	4
#define TIMER1_PRESCALER_1024       	5
#define TIMER1_EXTERNAL_CLOCK_FALLING 	6
#define TIMER1_EXTERNAL_CLOCK_RISING 	7



void TIMER1_voidInit(void);
void TIMER1_voidEnable(uint8 u8Prescaler);
void TIMER1_voidDisable(void);
void TIMER1_voidEnableOvfInt(void);
void TIMER1_voidDisableOvfInt(void);
void TIMER1_voidEnableComInt(void);
void TIMER1_voidDisableComInt(void);
void TIMER1_voidSetTCNTValue(uint16 u8ValueCpy);
void TIMER1_voidSetOCRAValue(uint16 u8ValueCpy);
void TIMER1_voidSetICRValue(uint16 u8ValueCpy);
uint16 TIMER1_u8ReadTcntReg(void);

void TIMER1_voidSetCallBackOvfInt(pf pfOvfcallbackCpy);
void TIMER1_voidSetCallBackCompareInt(pf pfComcallbackCpy);

#endif /* TIMER1_INTERFACE_H_ */
