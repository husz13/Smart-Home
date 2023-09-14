/*
 * prg.c
 *
 *  Created on: 22 Aug 2023
 *      Author: compu market
 */
#include <avr/io.h>
#include "int.h"
#include "../../LIB/BIT_Math.h"

void SetPortDir(u8 port, u8 dir) {
	switch (port) {
	case DIO_PORTA:
		DDRA = dir;
		break;
	case DIO_PORTB:
		DDRB = dir;
		break;
	case DIO_PORTC:
		DDRC = dir;
		break;
	case DIO_PORTD:
		DDRD = dir;
		break;
	}
}
void SetPortVal(u8 port, u8 val) {
	switch (port) {
	case DIO_PORTA:
		PORTA = val;
		break;
	case DIO_PORTB:
		PORTB = val;
		break;
	case DIO_PORTC:
		PORTC = val;
		break;
	case DIO_PORTD:
		PORTD = val;
		break;

	}
}
void SetPinDir(u8 port, u8 pin, u8 dir) {
	switch (dir) {
	case PIN_IN:
		switch (port) {
		case DIO_PORTA:
			ClearBit(DDRA, pin);
			break;
		case DIO_PORTB:
			ClearBit(DDRB, pin);
			break;
		case DIO_PORTC:
			ClearBit(DDRC, pin);
			break;
		case DIO_PORTD:
			ClearBit(DDRD, pin);
			break;

		}
		break;
	case PIN_OUT:
		switch (port) {
		case DIO_PORTA:
			SetBit(DDRA, pin);
			break;
		case DIO_PORTB:
			SetBit(DDRB, pin);
			break;
		case DIO_PORTC:
			SetBit(DDRC, pin);
			break;
		case DIO_PORTD:
			SetBit(DDRD, pin);
			break;

		}
		break;

	}
}
void SetPinVal(u8 port, u8 pin, u8 val) {
	switch (val) {
	case PIN_LOW:
		switch (port) {
		case DIO_PORTA:
			ClearBit(PORTA, pin);
			break;
		case DIO_PORTB:
			ClearBit(PORTB, pin);
			break;
		case DIO_PORTC:
			ClearBit(PORTC, pin);
			break;
		case DIO_PORTD:
			ClearBit(PORTD, pin);
			break;

		}
		break;
	case PIN_HIGH:
		switch (port) {
		case DIO_PORTA:
			SetBit(PORTA, pin);
			break;
		case DIO_PORTB:
			SetBit(PORTB, pin);
			break;
		case DIO_PORTC:
			SetBit(PORTC, pin);
			break;
		case DIO_PORTD:
			SetBit(PORTD, pin);
			break;

		}
		break;

	}

}
void TogglePin(u8 port, u8 pin) {
	switch (port) {
	case DIO_PORTA:
		ToggleBit(PORTA, pin);
		break;
	case DIO_PORTB:
		ToggleBit(PORTB, pin);
		break;
	case DIO_PORTC:
		ToggleBit(PORTC, pin);
		break;
	case DIO_PORTD:
		ToggleBit(PORTD, pin);
		break;

	}
}
u8 DIO_GetPinVal(u8 port, u8 pin) {
	switch (port) {
	case DIO_PORTA:
		return GetBit(PINA, pin);

	case DIO_PORTB:
		return GetBit(PINB, pin);
	case DIO_PORTC:
		return GetBit(PINC, pin);
	case DIO_PORTD:
		return GetBit(PIND, pin);

	}
}
u8 DIO_GetPortVal(u8 port) {
	switch (port) {
	case DIO_PORTA:
		return PINA;
		break;
	case DIO_PORTB:
		return PINB;
		break;
	case DIO_PORTC:
		return PINC;
		break;
	case DIO_PORTD:
		return PIND;
		break;

	}

}
void DIO_PullUp(u8 port, u8 pin) {
	switch (port) {
	case DIO_PORTA:
		SetBit(PORTA, pin);
		break;
	case DIO_PORTB:
		SetBit(PORTB, pin);
		break;
	case DIO_PORTC:
		SetBit(PORTC, pin);
		break;
	case DIO_PORTD:
		SetBit(PORTD, pin);
		break;
	}
}
u8 getPinOUT(u8 port, u8 pin) {
	switch (port) {
	case DIO_PORTA:
		return GetBit(PORTA, pin);
	case DIO_PORTB:
		return GetBit(PORTB, pin);
	case DIO_PORTC:
		return GetBit(PORTC, pin);
	case DIO_PORTD:
		return GetBit(PORTD, pin);

	}
}

