/*
 * exti_program.c
 *
 *  Created on: Oct 1, 2021
 *      Author: Ahmed
 */
#include "STD_LIB.h"
#include "exti_interface.h"
#include "bitmath.h"
void EXTI0_voidInit(void)
{
#if EXTI_SENSE_CONTROL == EXTI_RIS_EDGE
	SETBITvalue(MCUCR,1);
	SETBITvalue(MCUCR,0);
#elif EXTI_SENSE_CONTROL == EXTI_FAL_EDGE
	SETBITvalue(MCUCR,1);
	CLRBITvalue(MCUCR,0);
#elif EXTI_SENSE_CONTROL == EXTI_ANY_LOGICAL_CHANGE
	SETBITvalue(MCUCR,0);
	CLRBITvalue(MCUCR,1);
#elif EXTI_SENSE_CONTROL == EXTI_LOW_LEVEL
	CLRBITvalue(MCUCR,1);
	CLRBITvalue(MCUCR,0);
#else
#error "Invalid choice"
#endif
/*external interrupt 0 enable*/
	SETBITvalue(GICR,6);
}
void EXTI1_voidInit(void)
{
#if EXTI_SENSE_CONTROL == EXTI_RIS_EDGE
	SETBITvalue(MCUCR,3);
	SETBITvalue(MCUCR,2);
#elif EXTI_SENSE_CONTROL == EXTI_FAL_EDGE
	SETBITvalue(MCUCR,3);
	CLRBITvalue(MCUCR,2);
#elif EXTI_SENSE_CONTROL == EXTI_ANY_LOGICAL_CHANGE
	SETBITvalue(MCUCR,2);
	CLRBITvalue(MCUCR,3);
#elif EXTI_SENSE_CONTROL == EXTI_LOW_LEVEL
	CLRBITvalue(MCUCR,3);
	CLRBITvalue(MCUCR,2);
#else
#error "Invalid choice"
#endif
/*external interrupt 0 enable*/
	SETBITvalue(GICR,7);




}
void EXTI2_voidInit(void)
{
#if EXTI_SENSE_CONTROL == EXTI_RIS_EDGE
	SETBITvalue(MCUCSR,6);
#elif EXTI_SENSE_CONTROL == EXTI_FAL_EDGE
	CLRBITvalue(MCUCSR,6);
#else
#error "Invalid choice"
#endif
/*external interrupt 0 enable*/
	SETBITvalue(GICR,5);
}

void EXTI_voidSenseControl(u8 Copy_u8EXTI , u8 Copy_u8SenseControl)
{
#if Copy_u8SenseControl == EXTI_RIS_EDGE
	SETBITvalue(MCUCR,1);
	SETBITvalue(MCUCR,0);
#elif Copy_u8SenseControl == EXTI_FAL_EDGE
	SETBITvalue(MCUCR,1);
	CLRBITvalue(MCUCR,0);
#elif Copy_u8SenseControl == EXTI_ANY_LOGICAL_CHANGE
	SETBITvalue(MCUCR,0);
	CLRBITvalue(MCUCR,1);
#elif Copy_u8SenseControl == EXTI_LOW_LEVEL
	CLRBITvalue(MCUCR,1);
	CLRBITvalue(MCUCR,0);
#else
#error "Invalid choice"
#endif
	if(Copy_u8EXTI>7 || Copy_u8EXTI<5){return;}
	SETBITvalue(GICR,Copy_u8EXTI);

}
