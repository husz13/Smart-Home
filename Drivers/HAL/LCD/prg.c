/*
 * prg.c
 *
 *  Created on: 23 Aug 2023
 *      Author: Hussein
 */
#define F_CPU 8000000
#include "../../LIB/BIT_Math.h"
#include "../../LIB/Def_Types.h"
#include "../../MCAL/DIO/int.h"
#include <avr/io.h>
#include <util/delay.h>
#include "int.h"
u8 arr[100];
u8 getLen(u32 x) {
	u8 len = 0;
	do {
		x /= 10;
		len++;
	} while (x != 0);
	return len;
}

void IntoString(u32 x) {
	int len = getLen(x);
	int i = 0;
	while (x != 0) {
		//u8 dig = (u8) x % 10;
		arr[len - i - 1] = (u8) ('0' + x % 10);
		x /= 10;
		i++;
	}
	arr[i] = '\0';

}
//Initialisation
void LCD_Init() {
	SetPortDir(LCD_DATA_PORT, PORT_OUT);
	SetPinDir(LCD_CTRL_PORT, LCD_RS_PIN, PIN_OUT);
	 SetPinDir(LCD_CTRL_PORT, LCD_RW_PIN, PIN_OUT);
	SetPinDir(LCD_CTRL_PORT, LCD_En_PIN, PIN_OUT);
	_delay_ms(30);
	LCD_SendCMD(0b00111100);
	_delay_ms(1);
	LCD_SendCMD(0b00001111);
	_delay_ms(1);
	LCD_SendCMD(0b00000001);
	_delay_ms(2);
	LCD_SendCMD(0b00000011);
	_delay_ms(2);

}
//Send Command
void LCD_SendCMD(u8 cmd) {

	//set rs to send command
	SetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, PIN_LOW);
	//set rw to write
	SetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);
	SetPortVal(LCD_DATA_PORT, cmd);
	SetPinVal(LCD_CTRL_PORT, LCD_En_PIN, PIN_HIGH);
	_delay_ms(1);
	SetPinVal(LCD_CTRL_PORT, LCD_En_PIN, PIN_LOW);
	_delay_ms(1);

}
// Send Character
void LCD_WriteChar(u8 Char) {
	//set rs to send Data
	SetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, PIN_HIGH);
	//set rw to write
	SetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);
	SetPortVal(LCD_DATA_PORT, Char);
	SetPinVal(LCD_CTRL_PORT, LCD_En_PIN, PIN_HIGH);
	_delay_ms(1);
	SetPinVal(LCD_CTRL_PORT, LCD_En_PIN, PIN_LOW);

}
void LCD_WriteString(u8 *str) {
	while (*str != '\0') {
		LCD_WriteChar(*str);
		str++;
	}
}
void LCD_WriteNum(u32 num) {
	IntoString(num);
	LCD_WriteString(arr);
}
void LCD_Clear(void) {
	LCD_SendCMD(0b00000001);
}
