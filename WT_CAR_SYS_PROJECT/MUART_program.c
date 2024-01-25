/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : UART                                                */
/* Version : 1.0                                                 */
/* Date    : 25 Dec 2023                                         */
/*****************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "MUART_interface.h"
#include "MUART_private.h"
#include "MUART_config.h"

volatile uint8 Global_Data = 0;
uint8 Global_Transmit = 0;
void (*UART_TRANSMIT_CALLBACK)(void) = NULL_PTR;
void (*UART_RECEIVE_CALLBACK)(void) = NULL_PTR;


void UART_vInit(void)
{
	uint8 localu8Temp = 0;
#if	UART_INTERRUPT_MODE == INTERRUPT_ENABLE
	/* Enable Receive Interrupt RXCIE*/
	SET_BIT(UCSRB, UCSRB_RXCIE);
	/* Enable Data Register Empty Interrupt Enable UDRIE */
	SET_BIT(UCSRB, UCSRB_UDRIE);
#endif
	/* Select 8-bit Data */
	CLR_BIT(UCSRB, UCSRB_UCSZ2);
	/* Select UCSRC Register*/
	SET_BIT(localu8Temp, UCSRC_URSEL);
	SET_BIT(localu8Temp, UCSRC_UCSZ1);
	SET_BIT(localu8Temp, UCSRC_UCSZ0);
	/* Select UART Mode: Asynchronous Mode */
	CLR_BIT(localu8Temp, UCSRC_UMSEL);
	/* Select Parity Mode: No Parity */
	CLR_BIT(localu8Temp, UCSRC_UMP1);
	CLR_BIT(localu8Temp, UCSRC_UMP0);
	/* Select Stop Bit */
	CLR_BIT(localu8Temp, UCSRC_USBS);
	UCSRC = localu8Temp;
	/* Select BUAD RATE */
	UBRRL = BAUD_RATE;

	/* Enable RX */
	SET_BIT(UCSRB, UCSRB_RXEN);
	/* Enable TX */
	SET_BIT(UCSRB, UCSRB_TXEN);
}
void UART_vDisableEmptyInterrupt(void)
{
	CLR_BIT(UCSRB, UCSRB_UDRIE);
}
void UART_vSendData(const uint8 CpyData)
{
#if UART_INTERRUPT_MODE == INTERRUPT_DISABLE
	while(GET_BIT(UCSRA, UCSRA_UDRE) == 1)
		UDR = CpyData;
#else
	UDR = CpyData;
#endif
}
uint8 UART_u8ReceiveData(void)
{
	uint8 localu8DataReceived;
#if UART_INTERRUPT_MODE == INTERRUPT_DISABLE
	while(GET_BIT(UCSRA, UCSRA_RXC) == 1)
		localu8DataReceived = UDR;
#else
	localu8DataReceived = UDR;
#endif
	return localu8DataReceived;
}

void __vector_13 (void) __attribute__ ((signal, used));
void __vector_13(void)
{
	//Global_Data = UART_u8ReceiveData();
	UART_RECEIVE_CALLBACK();
}

void __vector_14 (void) __attribute__ ((signal, used));
void __vector_14(void)
{
	UART_TRANSMIT_CALLBACK();
}

void SendCallBack(void (*pf)(void))
{
	UART_TRANSMIT_CALLBACK = pf;
}

void ReceiveCallBack(void (*pf)(void))
{
	UART_RECEIVE_CALLBACK = pf;
}
