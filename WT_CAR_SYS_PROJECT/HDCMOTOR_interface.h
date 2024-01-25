/*
 * HDCMOTOR_interface.h
 *
 *  Created on: Jan 14, 2024
 *      Author: Shady
 */

#ifndef HDCMOTOR_INTERFACE_H_
#define HDCMOTOR_INTERFACE_H_

#define POT_ON	1
#define POT_OFF	0

void DCMOTOR_voidInit(void);
uint8 DCMOTOR_voidPotControl(uint8 u8potState);
void DCMOTOR_voidStop(void);

#endif

