/*
 * EEPROM_Program.c
 *
 *  Created on: Oct 30, 2021
 *      Author: gerges
 */


#include"STD_LIB.h"
#include"DIO_Interface.h"
#include"TWI_Interface.h"
#include"EEPROM_Private.h"

#include<util/delay.h>

void EEPROM_voidSendDataByte(u8 Copy_u8Data,u8 Copy_u8PageNumber,u8 Copy_u8Location)
{
	u8 Local_u8AddressPacket;
	Local_u8AddressPacket=EEPROM_FIXED_ADDRESS|(Copy_u8PageNumber);
	/*Send Start Condition*/
	TWI_u8StartCondition();

	/*Send slave address*/
	TWI_u8SendSlaveAddressWithWrite(Local_u8AddressPacket);
	/*Send 8 bits Location Data*/
	TWI_u8MasterSendDataByte(Copy_u8Location);
	/*Send 8 bits Data*/
	TWI_u8MasterSendDataByte(Copy_u8Data);
	/*Send Stop Condition*/
	TWI_voidStopCondtion();

	/*Delay until the write cycle is finished*/
	_delay_ms(10);
}
u8 EEPROM_u8ReadDataByte(u8 Copy_u8PageNumber,u8 Copy_u8Location)
{
	u8 Local_u8AddressPacket;
	u8 Local_u8DataByte;
	Local_u8AddressPacket=EEPROM_FIXED_ADDRESS|Copy_u8PageNumber;
	/*Send Start Condition*/
	TWI_u8StartCondition();
	/*Send slave address*/
	TWI_u8SendSlaveAddressWithWrite(Local_u8AddressPacket);
	/*Send 8 bits Location Data*/
	TWI_u8MasterSendDataByte(Copy_u8Location);
	/*Send Repeated Start*/
	TWI_u8RepeatedStart();
	/*Send Slave Address with read*/
	TWI_u8SendSlaveAddressWithRead(Local_u8AddressPacket);
	/*read data byte*/
	TWI_u8MasterReadDataByte(&Local_u8DataByte);
	/*Send Stop Condition*/
	TWI_voidStopCondtion();

	return Local_u8DataByte;
}




