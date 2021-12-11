/*
 * GIE_program.c
 *
 *  Created on: Oct 1, 2021
 *      Author: Ahmed
 */
#include "GIE_interface.h"
#include "STD_LIB.h"
#include "bitmath.h"

void GIE_voidEnable(void)
{
	SETBITvalue(SREG,7);
}
//void GIE_voidDisable(void);

