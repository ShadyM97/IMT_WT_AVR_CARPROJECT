/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : TIMER0                                              */
/* Version : 1.0                                                 */
/* Date    : 20 Dec 2023                                         */
/*****************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

pf TIM0_pfOVFCallBack = NULL_PTR;
pf TIM0_pfCmpCallBack = NULL_PTR;

void TIMER0_voidInit(void)
{
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
#elif TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
#elif TIMER0_MODE == PHASE_CORRECT_PWM
	SET_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
#elif TIMER0_MODE == TIM0_CTC
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
#else
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
#endif

#if TIMER0_OC0 == TOGGLE_OC0
	SET_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
#elif TIMER0_OC0 == CLEAR_OC0
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#elif TIMER0_OC0 == SET_OC0
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#elif TIMER0_OC0 == INVERTING_FAST_PWM
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#elif TIMER0_OC0 == NON_INVERTING_FAST_PWM
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#elif TIMER0_OC0 == INVERTING_PHASE_CORRECT_PWM
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#elif TIMER0_OC0 == NON_INVERTING_PHASE_CORRECT_PWM
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	/* Default is disconnected */
#else
	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
#endif

}
/* Used to Enable and update prescaler */
void TIMER0_voidEnable(uint8 u8Prescaler)
{
	TCCR0 = ((TCCR0 & 0xF8) | u8Prescaler);
}
void TIMER0_voidDisable(void)
{
	TCCR0 = (TCCR0 & 0xF8);
}
void TIMER0_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK, TOIE0);
}
void TIMER0_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK, TOIE0);
}
void TIMER0_voidEnableComInt(void)
{
	SET_BIT(TIMSK, OCIE0);
}
void TIMER0_voidDisableComInt(void)
{
	CLR_BIT(TIMSK, OCIE0);
}
void TIMER0_voidSetTCNTValue(uint8 u8ValueCpy)
{
	TCNT0 = u8ValueCpy;
}
void TIMER0_voidSetOCRValue(uint8 u8ValueCpy)
{
	OCR0 = u8ValueCpy;
}
uint8 TIMER0_u8ReadTcntReg(void)
{
	return TCNT0;
}

void TIMER0_voidSetCallBackOvfInt(pf pfOvfcallbackCpy)
{
	TIM0_pfOVFCallBack = pfOvfcallbackCpy;
}
void TIMER0_voidSetCallBackCompareInt(pf pfComcallbackCpy)
{
	TIM0_pfCmpCallBack = pfComcallbackCpy;
}

void __vector_10 (void)__attribute__ ((signal,used));
void __vector_10 (void)
{
	if (TIM0_pfCmpCallBack != NULL_PTR)
	{
		TIM0_pfCmpCallBack();
	}
	else
	{

	}
}
void __vector_11 (void)__attribute__ ((signal,used));
void __vector_11 (void)
{
	if (TIM0_pfOVFCallBack != NULL_PTR)
	{
		TIM0_pfOVFCallBack();
	}
	else
	{

	}
}

