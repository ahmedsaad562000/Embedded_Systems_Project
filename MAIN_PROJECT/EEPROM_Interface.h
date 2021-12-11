/*
 * EEPROM_Interface.h
 *
 *  Created on: Oct 30, 2021
 *      Author: gerges
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(u8 Copy_u8Data,u8 Copy_u8PageNumber,u8 Copy_u8Location);
u8 EEPROM_u8ReadDataByte(u8 Copy_u8PageNumber,u8 Copy_u8Location);

#endif /* EEPROM_INTERFACE_H_ */
