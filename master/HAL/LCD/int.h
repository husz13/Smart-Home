/*
 * int.h
 *
 *  Created on: 23 Aug 2023
 *      Author: compu market
 */

#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_
#define LCD_CTRL_PORT DIO_PORTC
#define LCD_DATA_PORT DIO_PORTA
#define LCD_RS_PIN PIN_0
#define LCD_RW_PIN PIN_1
#define LCD_En_PIN PIN_2
void LCD_Init();
void LCD_SendCMD(u8 cmd);
void LCD_WriteChar(u8 Char);
void LCD_WriteString(u8 *str);
void LCD_WriteNum(u32 num);
void LCD_Clear(void);
#endif /* HAL_LCD_INT_H_ */
