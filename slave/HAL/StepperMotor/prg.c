/*
 * prg.c
 *
 *  Created on: 28 Aug 2023
 *      Author: compu market
 */

#include "../../MCAL/DIO/int.h"
#include "../../LIB/Def_Types.h"
#include "int.h"
#include <avr/delay.h>

void initStepperMotor(u8 port, u8 pin_1, u8 pin_2, u8 pin_3, u8 pin_4) {
	SetPinDir(port, pin_1, PIN_OUT);
	SetPinDir(port, pin_2, PIN_OUT);
	SetPinDir(port, pin_3, PIN_OUT);
	SetPinDir(port, pin_4, PIN_OUT);

}
void StepperMotorCW(u8 port, u8 pin_1, u8 pin_2, u8 pin_3, u8 pin_4, u8 angel) {
	u8 cycles = (angel / AngelPerStep) / 4;
	for (int i = 0; i < cycles; i++) {
		//Step 1
		SetPinVal(port, pin_1, PIN_HIGH);
		SetPinVal(port, pin_2, PIN_LOW);
		SetPinVal(port, pin_3, PIN_LOW);
		SetPinVal(port, pin_4, PIN_LOW);
		_delay_ms(50);

		//Step 2
		SetPinVal(port, pin_1, PIN_LOW);
		SetPinVal(port, pin_2, PIN_HIGH);
		SetPinVal(port, pin_3, PIN_LOW);
		SetPinVal(port, pin_4, PIN_LOW);
		_delay_ms(50);

		//Step3
		SetPinVal(port, pin_1, PIN_LOW);
		SetPinVal(port, pin_2, PIN_LOW);
		SetPinVal(port, pin_3, PIN_HIGH);
		SetPinVal(port, pin_4, PIN_LOW);
		_delay_ms(50);

		//Step4
		SetPinVal(port, pin_1, PIN_LOW);
		SetPinVal(port, pin_2, PIN_LOW);
		SetPinVal(port, pin_3, PIN_LOW);
		SetPinVal(port, pin_4, PIN_HIGH);
		_delay_ms(50);

	}

}
void StepperMotorCCW(u8 port, u8 pin_1, u8 pin_2, u8 pin_3, u8 pin_4, u8 angel) {
	u8 cycles = (angel / 10) / 4;
	for (int i = 0; i < cycles; i++) {
		//Step 1
		SetPinVal(port, pin_1, PIN_LOW);
		SetPinVal(port, pin_2, PIN_LOW);
		SetPinVal(port, pin_3, PIN_LOW);
		SetPinVal(port, pin_4, PIN_HIGH);
		_delay_ms(50);

		//Step2
		SetPinVal(port, pin_1, PIN_LOW);
		SetPinVal(port, pin_2, PIN_LOW);
		SetPinVal(port, pin_3, PIN_HIGH);
		SetPinVal(port, pin_4, PIN_LOW);
		_delay_ms(50);

		//Step 3
		SetPinVal(port, pin_1, PIN_LOW);
		SetPinVal(port, pin_2, PIN_HIGH);
		SetPinVal(port, pin_3, PIN_LOW);
		SetPinVal(port, pin_4, PIN_LOW);
		_delay_ms(50);

		//Step 4
		SetPinVal(port, pin_1, PIN_HIGH);
		SetPinVal(port, pin_2, PIN_LOW);
		SetPinVal(port, pin_3, PIN_LOW);
		SetPinVal(port, pin_4, PIN_LOW);
		_delay_ms(50);

	}

}
