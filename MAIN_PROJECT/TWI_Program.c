/*
 * TWI_Program.c
 *
 *  Created on: Oct 29, 2021
 *      Author: gerges
 */

#include"STD_LIB.h"
#include"bitmath.h"
#include"TWI_Private.h"

void TWI_voidInitMaster(u8 Copy_u8Address )
{
	/*Enable to ACK*/
	SETBITvalue(TWCR,6);
	/*Select prescaler-->1*/
	CLRBITvalue(TWSR,1);
	CLRBITvalue(TWSR,0);
	TWBR=3;
	/*Set Master Address*/
	TWAR=Copy_u8Address<<1;
	/*TWI Enable*/
	SETBITvalue(TWCR,2);
}
void TWI_voidInitSlave(u8 Copy_u8Address )
{
	/*Enable to ACK*/
	SETBITvalue(TWCR,6);
	/*Set own Address*/
	TWAR=Copy_u8Address<<1;
	/*TWI Enable*/
	SETBITvalue(TWCR,2);
}
u8 TWI_u8StartCondition(void)
{
	u8 ErrorState=OK;
	/*Set Start Condition Bit*/
	SETBITvalue(TWCR,5);
	/*Clear TWINT Flag*/
	SETBITvalue(TWCR,7);
	/*wait on flag until the operation is finished */
	while((GetBitvalue(TWCR,7))==0);

	/*check the operation status*/
	if(TWSR==0x08)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	u8 ErrorState=OK;
	/*Send 7bits Slave Address With Write*/
	TWDR=Copy_u8SlaveAddress<<1;
	/*Set the write mode*/
	CLRBITvalue(TWDR,0);
	/*Clear Start Condition Bit*/
	CLRBITvalue(TWCR,5);
	/*Clear TWINT Flag*/
	SETBITvalue(TWCR,7);
	/*wait on flag until the operation is finished */
	while((GetBitvalue(TWCR,7))==0);

	/*check the operation status*/
	if(TWSR==0x18)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	u8 ErrorState=OK;
	/*Send 7bits Slave Address With Write*/
	TWDR=Copy_u8SlaveAddress<<1;
	/*Set the Read mode*/
	SETBITvalue(TWDR,0);
	/*Clear Start Condition Bit*/
	CLRBITvalue(TWCR,5);
	/*Clear TWINT Flag*/
	SETBITvalue(TWCR,7);
	/*wait on flag until the operation is finished */
	while((GetBitvalue(TWCR,7))==0);

	/*check the operation status*/
	if(TWSR==0x40)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8MasterSendDataByte(u8 Copy_u8Data)
{
	u8 ErrorState=OK;
	/*Send 8bits Data*/
	TWDR=Copy_u8Data;
	/*Clear TWINT Flag*/
	SETBITvalue(TWCR,7);
	/*wait on flag until the operation is finished */
	while((GetBitvalue(TWCR,7))==0);

	/*check the operation status*/
	if(TWSR==0x28)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8MasterReadDataByte(u8* Copy_Pu8Data)
{
	u8 ErrorState=OK;
	/*Clear TWINT Flag*/
	SETBITvalue(TWCR,7);
	/*wait on flag until the operation is finished */
	while((GetBitvalue(TWCR,7))==0);
	/*check the operation status*/
	if(TWSR==0x50)
	{
		*Copy_Pu8Data=TWDR;
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
u8 TWI_u8RepeatedStart(void)
{
	u8 ErrorState=OK;
	/*Set Start Condition Bit*/
	SETBITvalue(TWCR,5);
	/*Clear TWINT Flag*/
	SETBITvalue(TWCR,7);
	/*wait on flag until the operation is finished */
	while((GetBitvalue(TWCR,7))==0);

	/*check the operation status*/
	if(TWSR==0x10)
	{
		/*Do Nothing*/
	}
	else
	{
		ErrorState=NOK;
	}
	return ErrorState;
}
void TWI_voidStopCondtion(void)
{
	/*SET Stop Condition Bit*/
	SETBITvalue(TWCR,4);

	/*Clear TWINT Flag*/
	SETBITvalue(TWCR,7);
}
