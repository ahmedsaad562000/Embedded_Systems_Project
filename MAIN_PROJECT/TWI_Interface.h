/*
 * TWI_Interface.h
 *
 *  Created on: Oct 29, 2021
 *      Author: gerges
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidInitMaster(u8 Copy_u8Address );
void TWI_voidInitSlave(u8 Copy_u8Address );
u8 TWI_u8StartCondition(void);
u8 TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
u8 TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
u8 TWI_u8MasterSendDataByte(u8 Copy_u8Data);
u8 TWI_u8MasterReadDataByte(u8* Copy_Pu8Data);
u8 TWI_u8RepeatedStart(void);
void TWI_voidStopCondtion(void);

#endif /* TWI_INTERFACE_H_ */
