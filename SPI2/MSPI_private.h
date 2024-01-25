/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : SPI                                                 */
/* Version : 1.0                                                 */
/* Date    : 26 Dec 2023                                         */
/*****************************************************************/
#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

#define SPCR_SPIE	7
#define SPCR_SPE	6
#define SPCR_DORD	5
#define SPCR_MSTR	4
#define SPCR_CPOL	3
#define SPCR_CPHA	2
#define SPCR_SPR1	1
#define SPCR_SPR0	0

#define SPSR_SPIF	7
#define SPSR_WCOL	6
#define SPSR_SPI2X	0

#define SPCR	*((volatile uint8*) 0x2D)
#define SPSR	*((volatile uint8*) 0x2E)
#define SPDR	*((volatile uint8*) 0x2F)

#endif
