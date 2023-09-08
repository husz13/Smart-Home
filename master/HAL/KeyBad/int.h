/*
 * int.h
 *
 *  Created on: 24 Aug 2023
 *      Author: compu market
 */

#ifndef HAL_KEYBAD_INT_H_
#define HAL_KEYBAD_INT_H_
#define Keypad_Port DIO_PORTD
#define Keypad_Row0 PIN_0
#define Keypad_Row1 PIN_1
#define Keypad_Row2 PIN_2
#define Keypad_Row3 PIN_3
#define Keypad_Col0 PIN_4
#define Keypad_Col1 PIN_5
#define Keypad_Col2 PIN_6
#define Keypad_Col3 PIN_7

void KeypadInit();
u8 KeypadGetKey();

#endif /* HAL_KEYBAD_INT_H_ */
