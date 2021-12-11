/*
 * exti_interface.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Ahmed
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#include "exti_private.h"

void EXTI0_voidInit(void);
void EXTI1_voidInit(void);
void EXTI2_voidInit(void);


void EXTI_voidSenseControl(u8 Copy_u8EXTI , u8 Copy_u8SenseControl);

#endif /* EXTI_INTERFACE_H_ */
