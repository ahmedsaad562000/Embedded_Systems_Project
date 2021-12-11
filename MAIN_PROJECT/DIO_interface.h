/*
 * DIO_interface.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed
 */

#include "STD_LIB.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_LIB.h"
#define PIN_OUTPUT 1
#define PIN_INPUT 0
#define HIGH 1
#define LOW 0
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define PORT_OUTPUT 255
#define PORT_INPUT 0
#define MSB 1
#define LSB 0
enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7


}PinType;
//naming rules

u8 DIO_u8SetPinDirection(u8 Copy_u8PinNumber , u8 Copy_u8PortNumber , u8 Copy_u8Direction);
u8 DIO_u8SetPinValue(u8 Copy_u8PinNumber , u8 Copy_u8PortNumber , u8 Copy_u8Value);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortNumber , u8 Copy_u8Direction);
u8 DIO_u8SetPortValue(u8 Copy_u8PortNumber , u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber , u8 Copy_u8PortNumber , u8* PtrToValue);

u8 DIO_u8Set4PinDirection(u8 Copy_u8PinMode , u8 Copy_u8PortNumber , u8 Copy_u8Direction);
u8 DIO_u8Set4PinValue(u8 Copy_u8PinMode , u8 Copy_u8PortNumber , u8 Copy_u8Value);
#endif /* DIO_INTERFACE_H_ */
