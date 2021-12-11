/*
 * Timer_program.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Ahmed
 */
#include "bitmath.h"
#include "STD_LIB.h"
#include "Timer_Config.h"
#include "Timer_Private.h"

void TIMER0_voidinit(void)
{
	/*Set TIM0 Mode*/
#if TIM0_MODE == TIM0_OVERFLOW

		CLRBITvalue(TCCR0 , 3);
		CLRBITvalue(TCCR0 , 6);
/*OVERLOW INTERRUT ENABLE*/
		SETBITvalue(TIMSK ,0);

#elif TIM0_MODE == TIM0_CTC

		SETBITvalue(TCCR0 , 3);
		CLRBITvalue(TCCR0 , 6);
		/*CTC INTERRUPT ENABLE*/
		SETBITvalue(TIMSK ,1);
	#if TIM0_CTC_MODE_OC0_MODE == TIM0_CTC_MODE_OC0_OFF

			CLRBITvalue(TCCR0 , 5);
			CLRBITvalue(TCCR0 , 4);
	#elif TIM0_CTC_MODE_OC0_MODE == TIM0_CTC_MODE_OC0_TOGGLE

			SETBITvalue(TCCR0 , 4);
			CLRBITvalue(TCCR0 , 5);
	#elif TIM0_CTC_MODE_OC0_MODE == TIM0_CTC_MODE_OC0_CLEAR

			CLRBITvalue(TCCR0 , 4);
			SETBITvalue(TCCR0 , 5);
	#elif TIM0_CTC_MODE_OC0_MODE == TIM0_CTC_MODE_OC0_SET

			SETBITvalue(TCCR0 , 5);
			SETBITvalue(TCCR0 , 4);
	#else
	#error "TIMER 0 CTC MODE OC0 INVALID"
	#endif
#elif TIM0_MODE == TIM0_FAST_PWM

			SETBITvalue(TCCR0 , 3);
			SETBITvalue(TCCR0 , 6);
	#if  TIM0_PWM_OC0_PIN_MODE == TIM0_PWM_OC_NON_INV
				CLRBITvalue(TCCR0 , 4);
				SETBITvalue(TCCR0 , 5);
	#elif TIM0_PWM_OC0_PIN_MODE == TIM0_PWM_OC_INV
				SETBITvalue(TCCR0 , 4);
				SETBITvalue(TCCR0 , 5);
	#else
	#error "invalid"
	#endif

#elif TIM0_MODE == TIM0_PHASE_CORRECT_PWM
		SETBITvalue(TCCR0 , 6);
		CLRBITvalue(TCCR0 , 3);

	#if  TIM0_PWM_OC0_PIN_MODE == TIM0_PWM_OC_NON_INV
				CLRBITvalue(TCCR0 , 4);
				SETBITvalue(TCCR0 , 5);
	#elif TIM0_PWM_OC0_PIN_MODE == TIM0_PWM_OC_INV
				SETBITvalue(TCCR0 , 4);
				SETBITvalue(TCCR0 , 5);
	#else
	#error "invalid"
	#endif

#else
#error "TIMER 0 INVALID"
#endif

/*SET SUITABLE PRESCALAR*/
		TCCR0 &=0xf8;
		TCCR0 |=TIM0_PRESCALAR;

}
void TIMER0_voidSetPreLoadValue(u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload;



}
void TIMER0_voidSetCTCRegister(u8 Copy_u8CTCValue)
{

	OCR0 = Copy_u8CTCValue;

}
