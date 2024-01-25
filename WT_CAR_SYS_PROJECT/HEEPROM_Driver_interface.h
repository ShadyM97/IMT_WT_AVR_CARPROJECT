/*
 * HEEPROM_Driver_interface.h
 *
 *  Created on: Dec 27, 2023
 *      Author: Shady
 */
#ifndef HEEPROM_DRIVER_INTERFACE_H_
#define HEEPROM_DRIVER_INTERFACE_H_

typedef enum{
	EEPROM_NO_ERROR,
	EEPROM_WRITE_START_CONDITION_ERROR,
	EEPROM_WRITE_SET_ADDRESS_ERROR,
	EEPROM_WRITE_WRITE_DATA_ERROR
}EEPROM_ErrorStats_t;



void EEPROM_vByteWrite(uint8 Copy_u8LocationAddress, uint8 Copy_u8Data);
void EEPROM_vByteRead(uint8 Copy_u8LocationAddress, uint8 *Copy_pData);
void EEPROM_vWritePage(uint8 Copy_u8LocationAddress, uint8 *Copy_u8Data, uint8 u8arrLength);


#endif /* HEEPROM_DRIVER_INTERFACE_H_ */
