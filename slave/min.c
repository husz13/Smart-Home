/*
 * min.c
 *
 *  Created on: 13 Sept 2023
 *      Author: compu market
 */

#include "min.h"
#include <avr/io.h>
#include"MCAL/DIO/int.h"


void setup() {
	//ROOM 1 
	//light
	SetPinDir(ROOM1_LED_PIN, PIN_OUT);
	//door 
	SetPinDir( ROOM1_DOOR_PIN, PIN_OUT);
	//door indicator 
	SetPinDir(DIO_PORTC, PIN_6, PIN_OUT);
	//ROOM  2
	//light
	SetPinDir(ROOM2_LED_PIN, PIN_OUT);
	//door 
	SetPinDir(ROOM2_DOOR_PIN, PIN_OUT);
	//door indicator 
	SetPinDir(DIO_PORTC, PIN_7, PIN_OUT);
	//ROOM 3
	//light
	SetPinDir(ROOM3_LED_PIN, PIN_OUT);
	//door 
	SetPinDir(ROOM3_DOOR_PIN, PIN_OUT);
	//door indicator 
	SetPinDir(DIO_PORTD, PIN_0, PIN_OUT);

	//AC
	SetPinDir(AC_PIN, PIN_OUT);
	//Temperature Control --> Fan Or AC
	SetPinDir(TEMPERATURE_CONTROL_PIN, PIN_OUT);

}
