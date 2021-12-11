/*
 * DIO_PROGRAM.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed
 */

#ifndef DIO_PROGRAM_C_
#define DIO_PROGRAM_C_

#include "DIO_interface.h"
#include "DIO_PRIVATE.h"
#include "bitmath.h"
#include "avr/io.h"



u8 DIO_u8SetPinDirection(u8 Copy_u8PinNumber , u8 Copy_u8PortNumber , u8 Copy_u8Direction)
{
	  u8 Error_state = OK;

	 if(Copy_u8PinNumber<8)
	  {
  switch (Copy_u8PortNumber)
  {
  case DIO_PORTA:
	  if(Copy_u8Direction == PIN_OUTPUT)
	  {
		 SETBITvalue(DDRA, Copy_u8PinNumber);

	  }
	  else if(Copy_u8Direction == PIN_INPUT)
	  {
		  CLRBITvalue(DDRA, Copy_u8PinNumber);

	  }
	  else{  Error_state = NOK;}
	  break;
  case DIO_PORTB:

	  if(Copy_u8Direction == PIN_OUTPUT)
	  	  {
	  		 SETBITvalue(DDRB, Copy_u8PinNumber);

	  	  }
	  	  else if(Copy_u8Direction == PIN_INPUT)
	  	  {
	  		  CLRBITvalue(DDRB, Copy_u8PinNumber);

	  	  }
	  	  else{  Error_state = NOK;}


  	  break;
  case DIO_PORTC:

	  if(Copy_u8Direction == PIN_OUTPUT)
	  	  {
	  		 SETBITvalue(DDRC, Copy_u8PinNumber);

	  	  }
	  	  else if(Copy_u8Direction == PIN_INPUT)
	  	  {
	  		  CLRBITvalue(DDRC, Copy_u8PinNumber);

	  	  }
	  	  else{  Error_state = NOK;}


  	  break;
  case DIO_PORTD:

	  if(Copy_u8Direction == PIN_OUTPUT)
	  	  {
	  		 SETBITvalue(DDRD, Copy_u8PinNumber);

	  	  }
	  	  else if(Copy_u8Direction == PIN_INPUT)
	  	  {
	  		  CLRBITvalue(DDRD, Copy_u8PinNumber);

	  	  }
	  	  else{  Error_state = NOK;}


  	  break;
  default:
	  Error_state = NOK;
	  }
	  }
  else
  {
	  Error_state = NOK;

  }
	 return Error_state;

}
u8 DIO_u8SetPinValue(u8 Copy_u8PinNumber , u8 Copy_u8PortNumber , u8 Copy_u8Value)
{
	  u8 Error_state = OK;

	 if(Copy_u8PinNumber<8)
	  {
switch (Copy_u8PortNumber)
{
case DIO_PORTA:
	  if(Copy_u8Value == HIGH)
	  	  {
	  		 SETBITvalue(PORTA, Copy_u8PinNumber);

	  	  }
	  	  else if(Copy_u8Value == LOW)
	  	  {
	  		  CLRBITvalue(PORTA, Copy_u8PinNumber);

	  	  }
	  	  else{  Error_state = NOK;}
	  break;
case DIO_PORTB:

	  if(Copy_u8Value == HIGH)
	  	  {
	  		 SETBITvalue(PORTB, Copy_u8PinNumber);

	  	  }
	  	  else if(Copy_u8Value == LOW)
	  	  {
	  		  CLRBITvalue(PORTB, Copy_u8PinNumber);

	  	  }
	  	  else{  Error_state = NOK;}

	  break;
case DIO_PORTC:

	  if(Copy_u8Value == HIGH)
	  	  {
	  		 SETBITvalue(PORTC, Copy_u8PinNumber);

	  	  }
	  	  else if(Copy_u8Value == LOW)
	  	  {
	  		  CLRBITvalue(PORTC, Copy_u8PinNumber);

	  	  }
	  	  else{  Error_state = NOK;}


	  break;
case DIO_PORTD:

	  if(Copy_u8Value == HIGH)
	  	  {
	  		 SETBITvalue(PORTD, Copy_u8PinNumber);

	  	  }
	  	  else if(Copy_u8Value == LOW)
	  	  {
	  		  CLRBITvalue(PORTD, Copy_u8PinNumber);

	  	  }
	  	  else{  Error_state = NOK;}


	  break;
default:
	Error_state = NOK;
	  }
	  }
else
{
	  Error_state = NOK;

}
	 return Error_state;




}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortNumber , u8 Copy_u8Direction)
{
	u8 Error_state = OK ;
	switch (Copy_u8PortNumber)
	{
	case DIO_PORTA:
		  if(Copy_u8Direction == PORT_OUTPUT || Copy_u8Direction == PORT_INPUT)
		  	  {
		  		 DDRA = Copy_u8Direction;
		  	  }
		  else
		  {
			  Error_state = NOK;
		  }
		break;
	case DIO_PORTB:
		  if(Copy_u8Direction == PORT_OUTPUT || Copy_u8Direction == PORT_INPUT)
		  	  {
		  		 DDRB = Copy_u8Direction;
		  	  }
		  else
		  {
			  Error_state = NOK;
		  }
		  break;
	case DIO_PORTC:
		  if(Copy_u8Direction == PORT_OUTPUT || Copy_u8Direction == PORT_INPUT)
		  	  {
		  		 DDRC = Copy_u8Direction;
		  	  }
		  else
		  {
			  Error_state = NOK;
		  }
			break;
	case DIO_PORTD:
		  if(Copy_u8Direction == PORT_OUTPUT || Copy_u8Direction == PORT_INPUT)
		  	  {
		  		 DDRD = Copy_u8Direction;
		  	  }
		  else
		  {
			  Error_state = NOK;
		  }
			break;
	default:
		Error_state = NOK;
		break;
	}
return Error_state;

}
u8 DIO_u8SetPortValue(u8 Copy_u8PortNumber , u8 Copy_u8Value)
{
	u8 Error_state = OK ;
	if(Copy_u8Value<0 && Copy_u8Value>255){Error_state = NOK;}
	else
	{
	switch (Copy_u8PortNumber)
	{
	case DIO_PORTA:
		  		 DDRA = Copy_u8Value;
		  		 break;

	case DIO_PORTB:

		  		 DDRB = Copy_u8Value;

		  break;
	case DIO_PORTC:

		  		 DDRC = Copy_u8Value;

			break;
	case DIO_PORTD:

		  		 DDRD = Copy_u8Value;
		  		 break;
	default:
		Error_state = NOK;
		break;
	}
	}
return Error_state;


}

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber , u8 Copy_u8PortNumber , u8* PtrToValue)
{

	 u8 Error_state = OK;

		 if((Copy_u8PinNumber<8)&& (PtrToValue !=NULL_POINTER))
		  {
	  switch (Copy_u8PortNumber)
	  {
	  case DIO_PORTA:
		  *PtrToValue = GetBitvalue(PINA ,Copy_u8PinNumber );
		  break;
	  case DIO_PORTB:
		  *PtrToValue = GetBitvalue(PINB ,Copy_u8PinNumber );
	  	  break;
	  case DIO_PORTC:
		  *PtrToValue = GetBitvalue(PINC ,Copy_u8PinNumber );
	  	  break;
	  case DIO_PORTD:
		  *PtrToValue = GetBitvalue(PIND ,Copy_u8PinNumber );
	  	  break;
	  default:
		  Error_state = NOK;
		  }
		  }
	  else
	  {
		  Error_state = NOK;

	  }
		 return Error_state;


}

u8 DIO_u8Set4PinDirection(u8 Copy_u8PinMode , u8 Copy_u8PortNumber , u8 Copy_u8Direction)
{
u8 Error_state = OK;
switch(Copy_u8PortNumber)
{
case DIO_PORTA:
if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRA = (DDRA|0xf0) ;
}
else if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRA = (DDRA&0x0f) ;

}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRA = (DDRA|0x0f) ;
}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRA = (DDRA&0xf0) ;
}
else
{
	Error_state = NOK;

}


break;
case DIO_PORTB:
if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRB = (DDRB|0xf0) ;
}
else if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRB = (DDRB&0x0f) ;

}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRB = (DDRB|0x0f) ;
}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRB = (DDRB&0xf0) ;
}
else
{
	Error_state = NOK;

}


break;
case DIO_PORTC:
if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRC = (DDRC|0xf0) ;
}
else if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRC = (DDRC&0x0f) ;

}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRC = (DDRC|0x0f) ;
}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRC = (DDRC&0xf0) ;
}
else
{
	Error_state = NOK;

}


break;
case DIO_PORTD:
if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRD = (DDRD|0xf0) ;
}
else if((Copy_u8PinMode == MSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRD = (DDRD&0x0f) ;

}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_OUTPUT))
{
	DDRD = (DDRD|0x0f) ;
}
else if((Copy_u8PinMode == LSB)&&(Copy_u8Direction == PIN_INPUT))
{
	DDRD = (DDRD	&0xf0) ;
}
else
{
	Error_state = NOK;

}


break;
default:
	Error_state = NOK;
	break;
}


return Error_state;


}


u8 DIO_u8Set4PinValue(u8 Copy_u8PinMode , u8 Copy_u8PortNumber , u8 Copy_u8Value)
{
	u8 Error_state = OK;
	switch(Copy_u8PortNumber)
	{
	case DIO_PORTA:
		if(Copy_u8PinMode == LSB)
		{
			Copy_u8Value&=0xf0;
			PORTA&=0x0f;
			PORTA|=Copy_u8Value;

		}
		else if (Copy_u8PinMode == MSB)
		{
			PORTA&=0x0f;

			PORTA|=(Copy_u8Value<<4);
		}
		else
		{
			Error_state = NOK;

		}

		break;
	case DIO_PORTB:
		if(Copy_u8PinMode == LSB)
		{
			Copy_u8Value&=0xf0;
			PORTB&=0x0f;
			PORTB|=Copy_u8Value;

		}
		else if (Copy_u8PinMode == MSB)
		{
			PORTB&=0x0f;
			PORTB|=(Copy_u8Value<<4);
		}
		else
		{
			Error_state = NOK;

		}

		break;
	case DIO_PORTC:
		if(Copy_u8PinMode == LSB)
		{
			Copy_u8Value&=0xf0;
			PORTC&=0x0f;
			PORTC|=Copy_u8Value;

		}
		else if (Copy_u8PinMode == MSB)
		{

			PORTC&=0x0f;
			PORTC|=(Copy_u8Value<<4);
		}
		else
		{
			Error_state = NOK;

		}

		break;

	case DIO_PORTD:
		if(Copy_u8PinMode == LSB)
		{
			Copy_u8Value&=0xf0;
			PORTD&=0x0f;
			PORTD|=Copy_u8Value;

		}
		else if (Copy_u8PinMode == MSB)
		{

			PORTD&=0x0f;
			PORTD|=(Copy_u8Value<<4);
		}
		else
		{
			Error_state = NOK;

		}

		break;
	default:
		Error_state =NOK;
		break;


	}
	return Error_state;


}

#endif /* DIO_PROGRAM_C_ */
