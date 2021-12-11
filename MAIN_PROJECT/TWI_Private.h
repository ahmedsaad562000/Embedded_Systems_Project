/*
 * TWI_Private.h
 *
 *  Created on: Oct 29, 2021
 *      Author: gerges
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define TWDR    *((volatile u8*)0x23)
#define TWAR    *((volatile u8*)0x22)
#define TWSR    *((volatile u8*)0x21)
#define TWBR    *((volatile u8*)0x20)
#define TWCR    *((volatile u8*)0x56)

#endif /* TWI_PRIVATE_H_ */
