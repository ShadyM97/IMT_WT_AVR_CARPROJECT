/*
 * HEEPROM_Driver_program.c
 *
 *  Created on: Dec 27, 2023
 *      Author: Shady
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "HEEPROM_Driver_config.h"
#include "HEEPROM_Driver_interface.h"
#include "MTWI_Driver_interface.h"
#include <util/delay.h>

void EEPROM_vByteWrite(uint8 Copy_u8LocationAddress, uint8 Copy_u8Data)
{
	/* Start Condition */
	TWI_enStartCondition();
	/* Send SLA with Write*/
	TWI_enSetSlaveAddressWithWrite(EEPROM_SLAVE_ADDRESS);
	/* Send Memory location */
	TWI_enMasterWriteData(Copy_u8LocationAddress);
	/* Master Send Data */
	TWI_enMasterWriteData(Copy_u8Data);
	/* Stop Condition */
	TWI_vStopCondition();

	_delay_ms(10);
}
void EEPROM_vByteRead(uint8 Copy_u8LocationAddress, uint8 *Copy_pData)
{
	/* Start Condition */
	TWI_enStartCondition();
	/* Send SLA with Write*/
	TWI_enSetSlaveAddressWithWrite(EEPROM_SLAVE_ADDRESS);
	/* Send Memory location */
	TWI_enMasterWriteData(Copy_u8LocationAddress);
	/* Repeated Start */
	TWI_enRepeatStart();
	/* Send Read */
	TWI_enSetSlaveAddressWithRead(EEPROM_SLAVE_ADDRESS);
	/* Master Read */
	TWI_enMasterReadData(Copy_pData);
	/* Stop Condition */
	TWI_vStopCondition();
}

void EEPROM_vWritePage(uint8 Copy_u8LocationAddress, uint8 *Copy_u8Data, uint8 u8arrLength)
{
	uint8 i = 0;

	/* Start Condition */
	TWI_enStartCondition();
	/* Send SLA with Write*/
	TWI_enSetSlaveAddressWithWrite(EEPROM_SLAVE_ADDRESS);
	/* Send Memory location */
	TWI_enMasterWriteData(Copy_u8LocationAddress);
	/* Master Send Data */
	for (i = 0; i < u8arrLength; i++)
	{
		TWI_enMasterWriteData(Copy_u8Data[i]);
		_delay_ms(10);
	}
	/* Stop Condition */
	TWI_vStopCondition();

	_delay_ms(10);
}
