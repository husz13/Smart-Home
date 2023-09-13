/*
 * min.h
 *
 *  Created on: 12 Sept 2023
 *      Author: compu market
 */

#ifndef MIN_H_
#define MIN_H_
#define ROOM1 0
#define ROOM2 1
#define ROOM3 2
#define AC 3
#define ROOM_DOOR 0
#define ROOM_LED 1
#define ROOM_LED_OFF 0
#define ROOM_LED_ON 1
#define ROOM_DOOR_CLOSED 0
#define ROOM_DOOR_OPEN 1
#define AC_OFF 0
#define AC_ON 1
#define CMD_CLOSE_DOOR 0
#define CMD_OPEN_DOOR 1
#define CMD_LED_OFF 0
#define CMD_LED_ON 1
#define CMD_AC_OFF 0
#define CMD_AC_ON 1
#define ROOM1_LED_PIN  DIO_PORTC, PIN_0
#define ROOM2_LED_PIN  DIO_PORTC, PIN_1
#define ROOM3_LED_PIN  DIO_PORTC, PIN_2
#define ROOM1_DOOR_PIN DIO_PORTC, PIN_3
#define ROOM2_DOOR_PIN DIO_PORTC, PIN_4
#define ROOM3_DOOR_PIN DIO_PORTC, PIN_5
#define AC_PIN DIO_PORTD, PIN_1
#define TEMPERATURE_CONTROL_PIN DIO_PORTD, PIN_3

void setup();

#endif /* MIN_H_ */
