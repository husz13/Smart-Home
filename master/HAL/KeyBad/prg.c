/*
 * prg.c
 *
 *  Created on: 24 Aug 2023
 *      Author: compu market
 */
#define F_CPU 8000000
#include "../../LIB/BIT_Math.h"
#include "../../LIB/Def_Types.h"
#include "../../MCAL/DIO/int.h"
#include <avr/io.h>
#include <util/delay.h>
#include "int.h"

const u8 Keys[4][4] = { { '7', '8', '9', '/' }, { '4', '5', '6', '*' }, { '1',
		'2', '3', '-' }, { 'n', '0', '=', '+' } };

void KeypadInit() {

	//Set Column
	SetPinDir(Keypad_Port, Keypad_Col0, PIN_OUT);
	SetPinDir(Keypad_Port, Keypad_Col1, PIN_OUT);
	SetPinDir(Keypad_Port, Keypad_Col2, PIN_OUT);
	SetPinDir(Keypad_Port, Keypad_Col3, PIN_OUT);
	//SetPortDir(Keypad_Port, PIN_OUT);

	SetPinVal(Keypad_Port, Keypad_Col0, PIN_HIGH);
	SetPinVal(Keypad_Port, Keypad_Col1, PIN_HIGH);
	SetPinVal(Keypad_Port, Keypad_Col2, PIN_HIGH);
	SetPinVal(Keypad_Port, Keypad_Col3, PIN_HIGH);
	//Set Row
	SetPinDir(Keypad_Port, Keypad_Row0, PIN_IN);
	SetPinDir(Keypad_Port, Keypad_Row1, PIN_IN);
	SetPinDir(Keypad_Port, Keypad_Row2, PIN_IN);
	SetPinDir(Keypad_Port, Keypad_Row3, PIN_IN);

	DIO_PullUp(Keypad_Port, Keypad_Row0);
	DIO_PullUp(Keypad_Port, Keypad_Row1);
	DIO_PullUp(Keypad_Port, Keypad_Row2);
	DIO_PullUp(Keypad_Port, Keypad_Row3);

}
u8 KeypadGetKey() {
	u8 val = 0;
	for (int i = Keypad_Col0; i <= Keypad_Col3; i++) {
		//TogglePin(Keypad_Port, i);
		SetPinVal(Keypad_Port, i, PIN_LOW);

		for (int j = Keypad_Row0; j <= Keypad_Row3; j++) {
			u8 found = DIO_GetPinVal(Keypad_Port, j);
			if (found == 0) {
				val = Keys[j][i - Keypad_Col0];
				while (found == 0) {
					found = DIO_GetPinVal(Keypad_Port, j);
				}
				_delay_ms(10);
				//return val;

			}

		}

		SetPinVal(Keypad_Port, i, PIN_HIGH);

	}
	return val;

}
