#ifndef BITMATH_H //header guard VI
#define BITMATH_H

#define SETBITvalue(VAR , BIT_NO) 			(VAR)|=(1<<(BIT_NO))
#define CLRBITvalue(VAR , BIT_NO)  			(VAR) &= (~(1<<(BIT_NO)))
#define ToggleBitvalue(VAR , BIT_NO)  		(VAR) ^= (1<<(BIT_NO))
#define GetBitvalue(VAR , BIT_NO) 			((VAR)>>(BIT_NO))&1
#endif
