/*
 * Timer_Privatet.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TIM0_OVERFLOW 0
#define TIM0_CTC      1
#define TIM0_FAST_PWM 2
#define TIM0_PHASE_CORRECT_PWM 3


 #define TIM0_CTC_MODE_OC0_OFF 1
 #define TIM0_CTC_MODE_OC0_TOGGLE 2
 #define TIM0_CTC_MODE_OC0_SET 3
 #define TIM0_CTC_MODE_OC0_CLEAR 4


#define TIM0_OFF             0
#define TIM0_PRESCALAR_OFF   1
#define TIM0_8_PRESCALAR     2
#define TIM0_64_PRESCALAR    3
#define TIM0_256_PRESCALAR   4
#define TIM0_1024_PRESCALAR  5
#define TIM0_EXT_SOURCE_FALL 6
#define TIM0_EXT_SOURCE_RIS  7

#define TCCR0 *((volatile u8*) 0x53)

#define TIMSK *((volatile u8*) 0x59)

#define TCNT0 *((volatile u8*) 0x52)

#define OCR0 *((volatile u8*) 0x5C)

#define TIM0_PWM_OC_NON_INV 0
#define TIM0_PWM_OC_INV 1
#endif /* TIMER_PRIVATE_H_ */
