/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : DIO                                                 */
/* Version : 1.0                                                 */
/* Date    : 07 Dec 2023                                         */
/*****************************************************************/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#define CONCAT(b7,b6,b5,b4,b3,b2,b1,b0)	         CONCAT_2(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONCAT_2(b7,b6,b5,b4,b3,b2,b1,b0)         0b##b7##b6##b5##b4##b3##b2##b1##b0

#define DDRA	*((volatile uint8*) 0x3A)
#define DDRB	*((volatile uint8*) 0x37)
#define DDRC    *((volatile uint8*) 0x34)
#define DDRD    *((volatile uint8*) 0x31)

#define PORTA   *((volatile uint8*) 0x3B)
#define PORTB   *((volatile uint8*) 0x38)
#define PORTC   *((volatile uint8*) 0x35)
#define PORTD   *((volatile uint8*) 0x32)

#define PINA    *((volatile uint8*) 0x39)
#define PINB    *((volatile uint8*) 0x36)
#define PINC    *((volatile uint8*) 0x33)
#define PIND    *((volatile uint8*) 0x30)

#endif
