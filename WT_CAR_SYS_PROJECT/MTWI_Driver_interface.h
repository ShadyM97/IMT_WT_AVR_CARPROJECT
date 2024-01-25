/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : TWI_Driver                                          */
/* Version : 1.0                                                 */
/* Date    : 27 Dec 2023                                         */
/*****************************************************************/
#ifndef MTWI_DRIVER_INTERFACE_H_
#define MTWI_DRIVER_INTERFACE_H_

typedef enum{
	NO_ERROR,
	START_CONDITION_ERR,
	REPEAT_START_ERR,
	SLA_W_NOACK_ERR,
	SLA_R_NOACK_ERR,
	MASTER_SEND_DATA_ERR,
	MASTER_RECEIVE_DATA_ERR,
	MAX_ERR

}TWI_ErrorState_t;

void TWI_vMasterInit(void);
void TWI_vSlaveInit(void);
TWI_ErrorState_t TWI_enStartCondition(void);
TWI_ErrorState_t TWI_enRepeatStart(void);
TWI_ErrorState_t TWI_enSetSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress);
TWI_ErrorState_t TWI_enSetSlaveAddressWithRead(uint8 Copy_u8SlaveAddress);
TWI_ErrorState_t TWI_enMasterWriteData(uint8 Copy_u8Data);
TWI_ErrorState_t TWI_enMasterReadData(uint8 *Copy_u8Data);
void TWI_vStopCondition(void);


#endif
