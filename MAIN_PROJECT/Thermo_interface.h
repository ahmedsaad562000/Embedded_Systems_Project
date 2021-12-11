/*
 * Thermo_interface.h

 *
 *  Created on: Dec 4, 2021
 *      Author: Ahmed
 */

/*DS18B20 waterproof thermometer driver*/



#ifndef THERMO_INTERFACE_H_
#define THERMO_INTERFACE_H_
#include "Thermo_Config.h"
#include "Thermo_Private.h"
#define THERM_INPUT_MODE()  DIO_u8SetPinDirection(THERM_DQ,THERM_PORT,PIN_INPUT);
#define THERM_OUTPUT_MODE() DIO_u8SetPinDirection(THERM_DQ,THERM_PORT,PIN_OUTPUT);
#define THERM_LOW() 		DIO_u8SetPinValue(THERM_DQ,THERM_PORT,LOW);
#define THERM_HIGH() 		DIO_u8SetPinValue(THERM_DQ,THERM_PORT,HIGH);

u8 therm_u8reset();
void therm_write_bit(u8 bit);
u8 therm_u8read_bit(void);
u8 therm_u8read_byte(void);
void therm_write_byte(u8 byte);
u8 therm_u8read_temperature(u16* Decimal);










#endif /* THERMO_INTERFACE_H_ */
