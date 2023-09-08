/*
 * int.h
 *
 *  Created on: 22 Aug 2023
 *      Author: compu market
 */
#ifndef MCAL_DIO_INT_H_
#define MCAL_DIO_INT_H_
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
#define PORT_IN 0x00
#define PORT_OUT 0xff
#define PIN_IN 0
#define PIN_OUT 1
#define PIN_LOW 0
#define PIN_HIGH 1
#define PIN_0	0
#define PIN_1	1
#define PIN_2	2
#define PIN_3	3
#define PIN_4	4
#define PIN_5	5
#define PIN_6	6
#define PIN_7	7
#include "../../LIB/Def_Types.h"

void SetPortDir(u8 port, u8 dir);
void SetPortVal(u8 port, u8 val);
void SetPinDir(u8 port, u8 pin, u8 dir);
void SetPinVal(u8 port, u8 pin, u8 val);
void TogglePin(u8 port, u8 pin);
u8 DIO_GetPinVal(u8 port, u8 pin);
u8 DIO_GetPortVal(u8 port);
void DIO_PullUp(u8 port, u8 pin);
#endif /* MCAL_DIO_INT_H_ */
