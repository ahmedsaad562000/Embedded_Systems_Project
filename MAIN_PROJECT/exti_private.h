/*
 * exti_private.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Ahmed
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_RIS_EDGE 0
#define EXTI_FAL_EDGE 1
#define EXTI_ANY_LOGICAL_CHANGE 2
#define EXTI_LOW_LEVEL 3

#define INT0 5
#define INT1 7
#define INT2 6


#define MCUCR *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR  *((volatile u8*)0x5B)

#endif /* EXTI_PRIVATE_H_ */
