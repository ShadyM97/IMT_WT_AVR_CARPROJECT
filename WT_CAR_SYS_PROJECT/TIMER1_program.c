/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : TIMER1                                              */
/* Version : 1.0                                                 */
/* Date    : 20 Dec 2023                                         */
/*****************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

pf TIM1_pfOVFCallBack = NULL_PTR;
pf TIM1_pfCmpCallBack = NULL_PTR;

void TIMER1_voidInit(void)
{
#if TIMER1_MODE == NORMAL_MODE
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);
#elif TIMER1_MODE == FAST_PWM_OCR1A_TOP
	SET_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);
#elif TIMER1_MODE == FAST_PWM_ICR1_TOP
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);
#elif TIMER1_MODE == PHASE_CORRECT_PWM
	SET_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);
#elif TIMER1_MODE == TIM1_CTC
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);
#else
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);
#endif

#if TIMER1_OC1A == TOGGLE_OC1A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	CLR_BIT(TCCR1A, TCCR1A_COM1A1);
#elif TIMER1_OC1A == CLEAR_OC1A
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
#elif TIMER1_OC1A == SET_OC1A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
#elif TIMER1_OC1A == INVERTING_FAST_PWM_OC1A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
#elif TIMER1_OC1A == NON_INVERTING_FAST_PWM_OC1A
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
#elif TIMER1_OC1A == INVERTING_PHASE_CORRECT_PWM_OC1A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
#elif TIMER1_OC1A == NON_INVERTING_PHASE_CORRECT_PWM_OC1A
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
	/* Default is disconnected */
#else
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	CLR_BIT(TCCR1A, TCCR1A_COM1A1);
#endif

#if TIMER1_OC1B == TOGGLE_OC1B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	CLR_BIT(TCCR1A, TCCR1A_COM1B1);
#elif TIMER1_OC1B == CLEAR_OC1B
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
#elif TIMER1_OC1B == SET_OC1B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
#elif TIMER1_OC1B == INVERTING_FAST_PWM_OC1B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
#elif TIMER1_OC1B == NON_INVERTING_FAST_PWM_OC1B
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
#elif TIMER1_OC1B == INVERTING_PHASE_CORRECT_PWM_OC1B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
#elif TIMER1_OC1B == NON_INVERTING_PHASE_CORRECT_PWM_OC1B
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
	/* Default is disconnected */
#else
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	CLR_BIT(TCCR1A, TCCR1A_COM1B1);
#endif
}
/* Used to Enable and update prescaler */
void TIMER1_voidEnable(uint8 u8Prescaler)
{
	TCCR1B = ((TCCR1B & 0xF8) | u8Prescaler);
}
void TIMER1_voidDisable(void)
{
	TCCR1B = (TCCR1B & 0xF8);
}
void TIMER1_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK, TIMSK_TOIE1);
}
void TIMER1_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK, TIMSK_TOIE1);
}
void TIMER1_voidEnableComInt(void)
{
	SET_BIT(TIMSK, TIMSK_OCIE1A);
	SET_BIT(TIMSK, TIMSK_OCIE1B);
}
void TIMER1_voidDisableComInt(void)
{
	CLR_BIT(TIMSK, TIMSK_OCIE1A);
	CLR_BIT(TIMSK, TIMSK_OCIE1B);
}
void TIMER1_voidSetTCNTValue(uint16 u8ValueCpy)
{
	TCNT1 = u8ValueCpy;
}
void TIMER1_voidSetOCRAValue(uint16 u8ValueCpy)
{
	OCR1A = u8ValueCpy;
}
void TIMER1_voidSetOCRBValue(uint16 u8ValueCpy)
{
	OCR1B = u8ValueCpy;
}
void TIMER1_voidSetICRValue(uint16 u8ValueCpy)
{
	ICR1 = u8ValueCpy;
}
uint16 TIMER1_u8ReadTcntReg(void)
{
	return TCNT1;
}

void TIMER1_voidSetCallBackOvfInt(pf pfOvfcallbackCpy)
{
	TIM1_pfOVFCallBack = pfOvfcallbackCpy;
}
void TIMER1_voidSetCallBackCompareInt(pf pfComcallbackCpy)
{
	TIM1_pfCmpCallBack = pfComcallbackCpy;
}

/*
void __vector_10 (void)__attribute__ ((signal,used));
void __vector_10 (void)
{
	if (TIM1_pfCmpCallBack != NULL_PTR)
	{
		TIM1_pfCmpCallBack();
	}
	else
	{

	}
}
void __vector_11 (void)__attribute__ ((signal,used));
void __vector_11 (void)
{
	if (TIM1_pfOVFCallBack != NULL_PTR)
	{
		TIM1_pfOVFCallBack();
	}
	else
	{

	}
}
 */

