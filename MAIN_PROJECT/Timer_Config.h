/*
 * Timer_Config.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#include "Timer_Private.h"
/*Tim0 mode options*/
/* TIM0_OVERFLOW
 * TIM0_CTC
 * TIM0_FAST_PWM
 * TIM0_PHASE_CORRECT_PWM
 * */
#define TIM0_MODE TIM0_CTC

/*TIMO CTC MODE OC0 PIN OPTION*/ //OC0 B3 ,,T0 B0
/*TIM0_CTC_MODE_OC0_OFF
 * TIM0_CTC_MODE_OC0_TOGGLE
 * TIM0_CTC_MODE_OC0_SET
 * TIM0_CTC_MODE_OC0_CLEAR
 * */

#define TIM0_CTC_MODE_OC0_MODE TIM0_CTC_MODE_OC0_OFF

/*
 * Tim0 Prescalar OPTIONs:
 * TIM0_OFF
 * TIM0_PRESCALAR_OFF
 * TIM0_8_PRESCALAR
 * TIM0_64_PRESCALAR
 * TIM0_256_PRESCALAR
 * TIM0_1024_PRESCALAR
 * TIM0_EXT_SOURCE_FALL
 * TIM0_EXT_SOURCE_RIS
 *
 * */


#define TIM0_PRESCALAR  TIM0_1024_PRESCALAR

/*
 * TIM0_PWM_OC0_PIN_MODE OPTIONS:
 * 1- TIM0_PWM_OC_NON_INV
 * 2- TIM0_PWM_OC_INV
 *
 * */

#define TIM0_PWM_OC0_PIN_MODE TIM0_PWM_OC_NON_INV
#endif /* TIMER_CONFIG_H_ */