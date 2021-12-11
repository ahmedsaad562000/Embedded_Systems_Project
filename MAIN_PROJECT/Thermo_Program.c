/*
 * Thermo_Program.c

 *
 *  Created on: Dec 4, 2021
 *      Author: Ahmed
 */
#include "DIO_interface.h"
#include "Thermo_interface.h"
#include "util/delay.h"
#include "bitmath.h"

u8 therm_u8reset()
{
	u8 i;
	THERM_LOW();
	THERM_OUTPUT_MODE();
	_delay_us(480);
	THERM_INPUT_MODE();
	_delay_us(60);
	DIO_u8GetPinValue(THERM_DQ , THERM_PORT , &i);
	_delay_us(420);
	return i;
}
void therm_voidwrite_bit(u8 bit)
{
	THERM_LOW();
	THERM_OUTPUT_MODE();
	_delay_us(1);
	//If we want to write 1, release the line
	if(bit) THERM_INPUT_MODE();
	//Wait for 60uS and release the line
	_delay_us(60);
	THERM_INPUT_MODE();
}
u8 therm_u8read_bit(void)
{
	u8 bit=0;
	u8 i;
	//Pull line low for 1uS
	THERM_LOW();
	THERM_OUTPUT_MODE();
	_delay_us(1);
	//Release line and wait for 14uS
	THERM_INPUT_MODE();
	_delay_us(14);
	//Read line value
	DIO_u8GetPinValue(THERM_DQ , THERM_PORT , &i);
	if(i) {bit=1;}
	//Wait for 45uS to end and return read value
	_delay_us(45);
	return bit;
}
u8 therm_u8read_byte(void)
{
	u8 i=8, n=0;
	while(i){
		n>>=1;
		n|=(therm_u8read_bit()<<7);
	i--	;
	}
	return n;
}
void therm_voidwrite_byte(u8 byte)
{
	u8 i=8;
	while(i){
	//Write actual bit and shift one position right to make the next bit ready
	therm_voidwrite_bit(byte&1);
	byte>>=1;
	i--;
	}

}
u8 therm_u8read_temperature(u16* decimal)
{
	u8 temperature[2];
	u8 digit;
	//Reset, skip ROM and start temperature conversion
	therm_u8reset();
	therm_voidwrite_byte(THERM_CMD_SKIPROM);
	therm_voidwrite_byte(THERM_CMD_CONVERTTEMP);
	//Wait until conversion is complete
	while(!therm_u8read_bit());
	//Reset, skip ROM and send command to read Scratchpad
	therm_u8reset();
	therm_voidwrite_byte(THERM_CMD_SKIPROM);
	therm_voidwrite_byte(THERM_CMD_RSCRATCHPAD);
	//Read Scratchpad (only 2 first bytes)
	temperature[0]=therm_u8read_byte();
	temperature[1]=therm_u8read_byte();
	therm_u8reset();
	//Store temperature integer digits and decimal digits
	digit|=(temperature[1]&0x7)<<4;
	//Store decimal digits
	*decimal=temperature[0]&0xf;
	*decimal*=625;
	return digit;
}

