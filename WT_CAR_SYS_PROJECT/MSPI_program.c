/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : SPI                                                 */
/* Version : 1.0                                                 */
/* Date    : 26 Dec 2023                                         */
/*****************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "MSPI_interface.h"
#include "MSPI_private.h"

void SPI_vMSTRInit(void)
{
	// Master Select
	SET_BIT(SPCR, SPCR_MSTR);
	// Select SPI Clock
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	// Enable SPI
	SET_BIT(SPCR, SPCR_SPE);
}
void SPI_vSLAVEINIT(void)
{

		// Slave Select
		CLR_BIT(SPCR, SPCR_MSTR);
		// Enable SPI
		SET_BIT(SPCR, SPCR_SPE);

}
uint8 SPI_u8Transcieve(uint8 Copy_u8Data)
{
	/* Send Data */
	SPDR = Copy_u8Data;
	/* Wait for SPIF */
	while (!GET_BIT(SPSR, SPSR_SPIF));
	/* Receive Data */
	return SPDR;
}
