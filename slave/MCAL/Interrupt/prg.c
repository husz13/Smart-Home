/*
 * prg.c
 *
 *  Created on: 29 Aug 2023
 *      Author: compu market
 */

#include <avr/interrupt.h>
#include "../../LIB/BIT_Math.h"
#include "../../LIB/Def_Types.h"
void EXTI0(void) {
	//GIE
	SetBit(SREG, 7);
	//Falling Edge
	SetBit(MCUCR, 0);
	SetBit(MCUCR, 1);

	SetBit(GICR, 6);

}
void EXTI1(void) {
	//GIE
	SetBit(SREG, 7);
	//Falling Edge
	ClearBit(MCUCR, 2);
	SetBit(MCUCR, 3);
	SetBit(GICR, 7);
}
void EXTI2(void) {
	//GIE
	SetBit(SREG, 7);
	//Falling Edge
	ClearBit(MCUCSR, 6);
	SetBit(MCUCSR, 7);
	// PIE

	SetBit(GICR, 5);

}
