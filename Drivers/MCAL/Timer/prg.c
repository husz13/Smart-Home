/*
 * prg.c
 *
 *  Created on: 31 Aug 2023
 *      Author: compu market
 */

#include <avr/io.h>
#include "../../LIB/BIT_Math.h"
#include "../../LIB/Def_Types.h"
u32 overflowNum = 0, initialVal = 0;
//set prescalar
void initTimer0(void) {
	//Set Mode Normal /
	ClearBit(TCCR0, 3);
	ClearBit(TCCR0, 6);
	//GIE
	SetBit(SREG, 7);
	//PIE
	SetBit(TIMSK, 0);
}
void Timer0_Start(void) {
	//Select Timer Freq with Prescalar
	//
	SetBit(TCCR0, 0);
	ClearBit(TCCR0, 1);
	SetBit(TCCR0, 2);

}
void Timer0_Stop(void) {
	//Set Timer Freq to 0
	ClearBit(TCCR0, 0);
	ClearBit(TCCR0, 1);
	ClearBit(TCCR0, 2);
}
void Timer0_wait_ms(u32 desiredTime) {
	//Calac Number of OverFlow Interrupts & Preload
	//Time in Micro Sec ;
	u32 tik_time = 1024 / 8;
	u32 desiredTiks = (desiredTime * 1000) / tik_time;
	overflowNum = (desiredTiks / 256);
	initialVal = 256 - (desiredTiks % 256);
	TCNT0 = initialVal;
	overflowNum++;
}

void initTimer1(void) {
	//Set CTC mode
	SetBit(TCCR1B, 3);
	//GIE
	SetBit(SREG, 7);
	//PIE
	SetBit(TIMSK, 4);
}
void Timer1_Start(void) {
	SetBit(TCCR1B, 0);
	ClearBit(TCCR1B, 1);
	SetBit(TCCR1B, 2);

}
void Timer1_Stop(void) {
	ClearBit(TCCR1B, 0);
	ClearBit(TCCR1B, 1);
	ClearBit(TCCR1B, 2);
}
void Timer1_wait_ms(u32 desiredTime) {

	if (desiredTime <= 8400) {
		u32 tik_time = 1024 / 8;
		u32 desiredTiks = (desiredTime * 1000) / tik_time;
		OCR1A = desiredTiks - 1;
	}
}
