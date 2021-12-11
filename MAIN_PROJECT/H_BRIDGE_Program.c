/*
 * H_BRIDGE_Program.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Ahmed
 */
#include "H_BRIDGE_Config.h"
#include "DIO_interface.h"
#include "H_BRIDGE_Interface.h"
void H_voidPeltier_Cooling()
{
	DIO_u8SetPinValue(R_EN_PIN,H_BRIDGE_PORT,HIGH);
	DIO_u8SetPinValue(L_EN_PIN,H_BRIDGE_PORT,HIGH);
	DIO_u8SetPinValue(RPWM_PIN,H_BRIDGE_PORT,HIGH);
	DIO_u8SetPinValue(LPWM_PIN,H_BRIDGE_PORT,LOW);
}
void H_voidPeltier_Heating()
{
	DIO_u8SetPinValue(R_EN_PIN,H_BRIDGE_PORT,HIGH);
	DIO_u8SetPinValue(L_EN_PIN,H_BRIDGE_PORT,HIGH);
	DIO_u8SetPinValue(RPWM_PIN,H_BRIDGE_PORT,LOW);
	DIO_u8SetPinValue(LPWM_PIN,H_BRIDGE_PORT,HIGH);
}
void H_voidPeltier_OFF()
{
	DIO_u8SetPinValue(R_EN_PIN,H_BRIDGE_PORT,LOW);
	DIO_u8SetPinValue(L_EN_PIN,H_BRIDGE_PORT,LOW);
	DIO_u8SetPinValue(RPWM_PIN,H_BRIDGE_PORT,LOW);
	DIO_u8SetPinValue(LPWM_PIN,H_BRIDGE_PORT,HIGH);
}

