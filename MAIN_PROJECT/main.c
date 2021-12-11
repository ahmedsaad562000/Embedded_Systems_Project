/*
 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: Ahmed
 */

#include "DIO_interface.h"
#include"TWI_Interface.h"
#include"EEPROM_Interface.h"
#include "Thermo_interface.h" //Thermometer Driver
#include "Timer_interface.h"
#include "GIE_interface.h" //Global_interrupt
#include "exti_interface.h"
#include "H_BRIDGE_Interface.h" //for peltier
#include "H_BRIDGE_Config.h"
#include "util/delay.h"

#define HEATING_LED PIN2
#define COOLING_LED PIN7
#define LED_PORT DIO_PORTC

//Global variables to be used by both program and interrupts

	u8 On_Off_Set_Flag = 0 ; //flag that represnt the mode we are in (0-->off , 1-->On-measuring and showing temp ,2-->On-Setting temp )
	u8 digit; //value that stores the current temperature without decimals
	u16 decimal; //decimal value of temp if needed
	u8 set_temp = 60; //variable to get and store set_temp from e2prom
	u32 current_temp = 16; //current temp
	u8 current_led = 0; //led to be on according to process (no led for off)
	u16 Set_mode_count = 0; //counter for setting temperature mode (exit the mode after 5 sec)
int main(void)
{
	//buttons
	DIO_u8SetPinDirection(PIN2,DIO_PORTD,PIN_INPUT); //ON/OFF button & Interrupt0
	DIO_u8SetPinDirection(PIN6,DIO_PORTD,PIN_INPUT); //inc temp button
	DIO_u8SetPinDirection(PIN0,DIO_PORTB,PIN_INPUT); //dec temp button

	//leds
	DIO_u8SetPinDirection(COOLING_LED,LED_PORT,PIN_OUTPUT); //Cooling Elememt led
	DIO_u8SetPinDirection(HEATING_LED,LED_PORT,PIN_OUTPUT); //Heating Elememt led


	//7-segment pins initialization

	DIO_u8SetPinDirection(PIN4,DIO_PORTA,PIN_OUTPUT);
	DIO_u8SetPinDirection(PIN5,DIO_PORTA,PIN_OUTPUT);
	DIO_u8SetPinDirection(PIN6,DIO_PORTA,PIN_OUTPUT);
	DIO_u8SetPinDirection(PIN7,DIO_PORTA,PIN_OUTPUT);

	DIO_u8SetPinDirection(PIN1,DIO_PORTB,PIN_OUTPUT);
	DIO_u8SetPinDirection(PIN2,DIO_PORTB,PIN_OUTPUT);

	//H-bridge for peltier pins initalization

	DIO_u8SetPinDirection(R_EN_PIN,H_BRIDGE_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(L_EN_PIN,H_BRIDGE_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(RPWM_PIN,H_BRIDGE_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(LPWM_PIN,H_BRIDGE_PORT,PIN_OUTPUT);

	//Timer & external & global interrupt initialization
	TIMER0_voidSetCTCRegister(156);
	TIMER0_voidinit();
	EXTI0_voidInit();
	GIE_voidEnable();

	//I2c initialization
	TWI_voidInitMaster(16);
	EEPROM_voidSendDataByte(16,0,0);
	EEPROM_voidSendDataByte(60,11,0);
	//variables to be used in program
	u8 tenth ,units , current_state = Peltier_OFF , new_state , inc , dec;
	while(1)
	{
		if(On_Off_Set_Flag == 1)
		{
			//test if any of the setting temperature buttons is pressed
			DIO_u8GetPinValue(PIN6,DIO_PORTD,&inc);
			DIO_u8GetPinValue(PIN0,DIO_PORTB,&dec);
			if(dec || inc){inc = 0; dec = 0;On_Off_Set_Flag = 2;_delay_ms(50);Set_mode_count = 0; }
			//-----------------

			// show the current temp.
			tenth = current_temp/10;
			units = current_temp%10;

			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);

			//to go to set temp mode
			DIO_u8GetPinValue(PIN6,DIO_PORTD,&inc);
			DIO_u8GetPinValue(PIN0,DIO_PORTB,&dec);
			if(dec || inc){inc = 0; dec = 0;On_Off_Set_Flag = 2;_delay_ms(50);Set_mode_count = 0; }
			//-----------------

			//choose led to be blinking
			if(current_state == Peltier_Cooling){current_led = COOLING_LED;}
			else if (current_state == Peltier_Heating) {current_led = HEATING_LED;}
			else if (current_state == Peltier_OFF) {current_led = 0;}

			//set the state according to current & setting temperature
			if(current_temp <(set_temp-5)){new_state = Peltier_Heating;}
			else if (current_temp >(set_temp+5)){new_state = Peltier_Cooling;}
			else{new_state = Peltier_OFF;}

			//run the cooler (heating or cooling) or turn it off
			if(current_state != new_state)
			{
				current_state = new_state;
				if(current_state == Peltier_OFF){H_voidPeltier_OFF();}
				else if(current_state == Peltier_Cooling){H_voidPeltier_Cooling();}
				else if(current_state == Peltier_Heating){H_voidPeltier_Heating();}
			}

			// show the current temp.
			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);

			//test if any of the setting temperature buttons is pressed
			DIO_u8GetPinValue(PIN6,DIO_PORTD,&inc);
			DIO_u8GetPinValue(PIN0,DIO_PORTB,&dec);
			if(dec || inc){inc = 0; dec = 0;On_Off_Set_Flag = 2;_delay_ms(50);Set_mode_count = 0; }

		}

		//set_temp
		else if(On_Off_Set_Flag == 2)
		{
			//test to inc or dec the set temp.
			DIO_u8GetPinValue(PIN6,DIO_PORTD,&inc);
			DIO_u8GetPinValue(PIN0,DIO_PORTB,&dec);
			if(inc){if(set_temp<75){set_temp+=5;}_delay_ms(150);Set_mode_count = 0;inc = 0;}
			if(dec){if(set_temp>35){set_temp-=5;}_delay_ms(150);Set_mode_count = 0;dec = 0;}

			set_temp = EEPROM_u8ReadDataByte(11 , 0);
			tenth = set_temp/10;
			units = set_temp%10;

			//show set temp

			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,HIGH);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,tenth);
			_delay_ms(5);
			DIO_u8SetPinValue(PIN1,DIO_PORTB,HIGH);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8Set4PinValue(MSB,DIO_PORTA,units);
			_delay_ms(5);

			//test to inc or dec the set temp.
			DIO_u8GetPinValue(PIN6,DIO_PORTD,&inc);
			DIO_u8GetPinValue(PIN0,DIO_PORTB,&dec);
			if(inc){if(set_temp<75){set_temp+=5;}_delay_ms(150);Set_mode_count = 0;inc = 0;}
			if(dec){if(set_temp>35){set_temp-=5;}_delay_ms(150);Set_mode_count = 0;dec = 0;}


		}
		//offstate
		else if(On_Off_Set_Flag == 0)
		{
			//turn everything off
			DIO_u8SetPinValue(PIN1,DIO_PORTB,LOW);
			DIO_u8SetPinValue(PIN2,DIO_PORTB,LOW);
			DIO_u8SetPinValue(HEATING_LED,LED_PORT,LOW);
			DIO_u8SetPinValue(COOLING_LED,LED_PORT,LOW);
			H_voidPeltier_OFF();
		}





	}





return 0;
}





void __vector_1(void)      __attribute__((signal));	 //External_Interrupt0


void __vector_1(void)
{
if(On_Off_Set_Flag == 0) {On_Off_Set_Flag = 1;}
else  {On_Off_Set_Flag = 0;}
_delay_ms(150);
}

void __vector_10(void)      __attribute__((signal));  //Timer_interrupt
void __vector_10(void)
{
static u8 Count = 0;    	 //used to count time
static u8 i = 0;			 //storing temperatures location variable
static u8 j = 0;			 //getting temperatures location variable
static u8 led_flag = 0 ;	 //used to light the corresponding led to mode
static u8 flicker_set_temp=0;//used to make the set temp flicker

//measuring temperature mode
if(On_Off_Set_Flag ==1)
{
Count++;

//every 100 ms
if(Count%10 == 0)
{
//set new temp
	digit = therm_u8read_temperature(&decimal);
	EEPROM_voidSendDataByte(digit , i , 0);
	i++;
	if(i==10){i=0;}
	if(led_flag){DIO_u8SetPinValue(current_led , LED_PORT , LOW);led_flag = 0;}
}

//Every 1 sec
if((Count%100 == 0))
{
	Count = 0;

if(current_led!=0)
	{
	//to fliker led
	DIO_u8SetPinValue(current_led , LED_PORT , HIGH);led_flag = 1;
	}
	//get sum of the previous temps.
	for(j = 0 ; j<10 ; j++)
	{

		current_temp += EEPROM_u8ReadDataByte(j,0);
	}
	//get the average
	current_temp/=10;

	}
}
//set temperature mode
else if(On_Off_Set_Flag ==2)
{

	//to count the 5 sec so temperature is set
	Set_mode_count++;
	//to flicker the set temperature
	flicker_set_temp++;
	if(flicker_set_temp == 100)
	{


	}
	if(Set_mode_count == 500)
	{
		//set_temp to e2prom
		EEPROM_voidSendDataByte(set_temp , 11 , 0);
		Set_mode_count = 0;
		On_Off_Set_Flag = 1;
	}

}
else
{
	//Nothing;
}

}













