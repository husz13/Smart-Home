/*
 * prg.c
 *
 *  Created on: 27 Aug 2023
 *      Author: compu market
 */

#include "../../MCAL/DIO/int.h"
#include"../../LIB/Def_Types.h"
void initDCMotor(u8 port, u8 pin_1, u8 pin_2) {
	SetPinDir(port, pin_1, PIN_OUT);
	SetPinDir(port, pin_2, PIN_OUT);

}
void DCMotorCW(u8 port, u8 pin_1, u8 pin_2)

{
	SetPinVal(port, pin_1, PIN_HIGH);
	SetPinVal(port, pin_2, PIN_LOW);

}
void DCMotorCCW(u8 port, u8 pin_1, u8 pin_2) {
	SetPinVal(port, pin_2, PIN_HIGH);
	SetPinVal(port, pin_1, PIN_LOW);

}
