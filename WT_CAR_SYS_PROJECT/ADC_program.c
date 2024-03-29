#include "BIT_Math.h"
#include "STD_Types.h"
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_interface.h"

void (*ADC_CALLBACK_PTR)(void) = NULL_PTR;

void ADC_Init (void)
{
#if VOLTAGE_REF_SEL == AREF_VREF_OFF
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, REFS0);
#elif VOLTAGE_REF_SEL == AVCC
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
#elif VOLTAGE_REF_SEL == AVCC
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS1);
#endif

#if ADLAR_SEL == ADLAR_OFF
	CLR_BIT(ADMUX, ADLAR);
#elif ADLAR_SEL == ADLAR_ON
	SET_BIT(ADMUX, ADLAR);
#endif

#if ADC_INTERRUPT_SEL == ADC_INTERRUPT_ENABLE
	SET_BIT(ADCSRA, ADIE);
#elif ADC_INTERRUPT_SEL == ADC_INTERRUPT_DISABLE
	CLR_BIT(ADCSRA, ADIE);
#endif

#if ADC_AUTO_TRIG_SEL == ADC_AUTO_TRIG_DISABLE
	CLR_BIT(ADCSRA, ADSC);
#elif ADC_AUTO_TRIG_SEL == ADC_AUTO_TRIG_ENABLE
	SET_BIT(ADCSRA, ADSC);
#endif

#if ADC_PRESCALER_SELECT == ADC_PRESCALER_2
	CLR_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_SELECT == ADC_PRESCALER_4
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_SELECT == ADC_PRESCALER_8
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_SELECT == ADC_PRESCALER_16
	CLR_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_SELECT == ADC_PRESCALER_32
	SET_BIT(ADCSRA, ADPS0);
	CLR_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_SELECT == ADC_PRESCALER_64
	CLR_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#elif ADC_PRESCALER_SELECT == ADC_PRESCALER_128
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
#endif

#if ADC_ENABLE_SEL == ADC_ENABLE
	SET_BIT(ADCSRA, ADEN);
#elif ADC_ENABLE_SEL == ADC_DISABLE
	CLR_BIT(ADCSRA, ADEN);
#endif


}
uint16 ADC_Read (uint8 Channel)
{
	// Select Channel
	//      Bit masking first three bits
	ADMUX = ((ADMUX & 0b11100000)|(Channel));
	SET_BIT(ADCSRA, ADSC);

	while(GET_BIT(ADCSRA, ADIF) == 0);

	SET_BIT(ADCSRA, ADIF);

	return ADC_Reg;

}
void ADC_Start_ASYNC (uint8 Channel)
{
	if (GET_BIT(ADCSRA, ADSC) == 0)
	{
		ADMUX = ((ADMUX & 0b11100000)|(Channel));
		SET_BIT(ADCSRA, ADSC);
	}
}
uint16 ADC_Read_ASYNC(void)
{
	return ADC_Reg;
}
void ADC_void_SET_CALL_BACK(void (*PTR)(void))
{
	ADC_CALLBACK_PTR = PTR;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_16 (void){
	ADC_CALLBACK_PTR();
}
