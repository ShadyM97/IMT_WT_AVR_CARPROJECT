/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : UART                                                */
/* Version : 1.0                                                 */
/* Date    : 25 Dec 2023                                         */
/*****************************************************************/
#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

#define BUAD_RATE_9600	51
#define INTERRUPT_ENABLE 	1
#define INTERRUPT_DISABLE 	2

#define UDR			*((volatile uint8*) 0x2C)
#define UCSRA		*((volatile uint8*) 0x2B)
#define UCSRB		*((volatile uint8*) 0x2A)
#define UCSRC		*((volatile uint8*) 0x40)
#define UBRRL		*((volatile uint8*) 0x29)

#define UCSRA_RXC		7
#define UCSRA_UDRE		5

#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2		2


#define UCSRC_URSEL		7
#define UCSRC_UMSEL		6
#define UCSRC_UMP1		5
#define UCSRC_UMP0		4
#define UCSRC_USBS		3
#define UCSRC_UCSZ1		2
#define UCSRC_UCSZ0		1
#endif
