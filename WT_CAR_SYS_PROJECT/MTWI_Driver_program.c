/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : TWI_Driver                                          */
/* Version : 1.0                                                 */
/* Date    : 27 Dec 2023                                         */
/*****************************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "MTWI_Driver_interface.h"
#include "MTWI_Driver_private.h"
#include "MTWI_Driver_config.h"

void TWI_vMasterInit(void)
{
	/* Set Clock configuration TWBR = 2 */
	TWBR = 2;
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);
	/* Enable ACK bit */
	SET_BIT(TWCR, TWCR_TWEA);
	/* Set my own Address */
	TWAR = MASTER_ADDRESS << 1;
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
}
void TWI_vSlaveInit(void)
{
	/* Enable ACK bit */
	SET_BIT(TWCR, TWCR_TWEA);
	/* Set my own Address */
	TWAR = SLAVE_ADDRESS << 1;
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
}
TWI_ErrorState_t TWI_enStartCondition(void)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Enable Start condition */
	SET_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt Flag to start the operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
	/* Wait until the interrupt flag is raised again */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	if((TWSR & 0xF8) != START_CONDITION)
	{
		Local_ErrorState = START_CONDITION_ERR;
	}
	else
	{
		/* Do Nothing */
	}
	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enRepeatStart(void)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Enable Start condition */
	SET_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt Flag to start the operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
	/* Wait until the interrupt flag is raised again */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	if((TWSR & 0xF8) != REPEAT_START_CONDITION)
	{
		Local_ErrorState = REPEAT_START_ERR;
	}
	else
	{
		/* Do Nothing */
	}
	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enSetSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Set Slave Address in TWDR Register */
	TWDR = Copy_u8SlaveAddress;
	/*Clear Start Condition*/
	CLR_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt Flag to start the operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
	/* Wait until the interrupt flag is raised again */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	if((TWSR & 0xF8) == SLA_WITH_W_NOACK)
	{
		Local_ErrorState = SLA_W_NOACK_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enSetSlaveAddressWithRead(uint8 Copy_u8SlaveAddress)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Set Slave Address in TWDR Register */
	TWDR = Copy_u8SlaveAddress | 1;
	/*Clear Start Condition*/
	CLR_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt Flag to start the operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
	/* Wait until the interrupt flag is raised again */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	if((TWSR & 0xF8) == SLA_WITH_R_NOACK)
	{
		Local_ErrorState = SLA_R_NOACK_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enMasterWriteData(uint8 Copy_u8Data)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Write Data to TWDR */
	TWDR = Copy_u8Data;
	/* Clear Interrupt Flag to start the operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
	/* Wait until the interrupt flag is raised again */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	if((TWSR & 0xF8) == MASTER_SEND_DATA_NOACK)
	{
		Local_ErrorState = MASTER_SEND_DATA_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enMasterReadData(uint8 *Copy_u8Data)
{
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Clear Interrupt Flag to start the operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
	/* Wait until the interrupt flag is raised again */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	if((TWSR & 0xF8) == MASTER_RECEIVE_DATA_NOACK)
	{
		Local_ErrorState = MASTER_RECEIVE_DATA_ERR;
	}
	else
	{

	}
	*Copy_u8Data = TWDR;

	return Local_ErrorState;
}
void TWI_vStopCondition(void)
{
	/* Set Stop Condition TWSTO to make stop condition*/
	SET_BIT(TWCR, TWCR_TWSTO);
	/* Clear Interrupt Flag to start the operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);

}
