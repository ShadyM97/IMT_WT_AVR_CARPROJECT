/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : TWI_Driver                                          */
/* Version : 1.0                                                 */
/* Date    : 27 Dec 2023                                         */
/*****************************************************************/
#ifndef MTWI_DRIVER_PRIVATE_H_
#define MTWI_DRIVER_PRIVATE_H_


#define TWBR		*((volatile uint8*) 0x20)
#define TWCR		*((volatile uint8*) 0x56)
#define TWCR_TWINT	7
#define TWCR_TWEA	6
#define TWCR_TWSTA	5
#define TWCR_TWSTO	4
#define TWCR_TWEN	2

#define TWSR		*((volatile uint8*) 0x21)
#define TWSR_TWPS0	0
#define TWSR_TWPS1	1

#define TWDR		*((volatile uint8*) 0x23)
#define TWDR_TWD0	0
#define TWAR		*((volatile uint8*) 0x22)

#define START_CONDITION 				0x08
#define REPEAT_START_CONDITION			0x10
#define SLA_WITH_W_NOACK				0x20
#define SLA_WITH_R_NOACK				0x38
#define	MASTER_SEND_DATA_NOACK			0x30
#define MASTER_RECEIVE_DATA_NOACK		0x58
#endif
