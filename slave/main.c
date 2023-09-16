/*
 * main.c
 *
 *  Created on: 12 Sept 2023
 *      Author: compu market
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "MCAL/DIO/int.h"
#include "HAL/Sensor/int.h"
#include <avr/interrupt.h>
#include"LIB/BIT_Math.h"
#include "MCAL/Interrupt/int.h"
#include "MCAL/ADC/int.h"
#include "MCAL/Timer/int.h"
#include "MCAL/SPI/int.h"
#include "min.h"
u8 getRoomStatus(u8 room);
void setup();
extern u32 overflowNum, initialVal;
void main(void) {
	//u8 cmd1 = 0;
	//u8 cmd2 = 1;
	u8 cmd;
	u8 OPT;
	u8 roomStatus;
	setup();
	EXTI0();


	init_SPI_Slave();
	initSensor();
	initTimer0();
	Timer0_wait_ms(50);
	Timer0_Start();
	while (1) {

		//receive order
		OPT = SPI_Transceive(1);
		switch (OPT) {
		/////////////////////////////////---ROOM 1----////////////////////////////////////////////////////
		case ROOM1: {
			//send status
			roomStatus = getRoomStatus(ROOM1);
			SPI_Transceive(roomStatus);
			//receive Order
			cmd = SPI_Transceive(roomStatus);
			switch (cmd) {
			case ROOM_DOOR: {
				//send status

				//receive order
				cmd = SPI_Transceive(roomStatus);
				switch (cmd) {
				case CMD_OPEN_DOOR: {
					//Check Door Status
					if (!getPinOUT(ROOM1_DOOR_LED_PIN)) {
						SetPinVal(ROOM1_DOOR_PIN, PIN_HIGH);
						_delay_us(2000);
						SetPinVal(ROOM1_DOOR_PIN, PIN_LOW);
						_delay_us(1000);
						SetPinVal(ROOM1_DOOR_PIN, PIN_HIGH);
						_delay_us(2000);
						SetPinVal(ROOM1_DOOR_PIN, PIN_LOW);
						SetPinVal(DIO_PORTC, PIN_6, PIN_HIGH);
						//	cmd2 = 0;

					}


				}
					break;
				case CMD_CLOSE_DOOR: {
					//Check Door Status
					if (getPinOUT(ROOM1_DOOR_LED_PIN)) {
						SetPinVal(ROOM1_DOOR_PIN, PIN_HIGH);
						_delay_us(50);
						SetPinVal(ROOM1_DOOR_PIN, PIN_LOW);
						_delay_us(50);
						SetPinVal(ROOM1_DOOR_PIN, PIN_HIGH);
						_delay_us(50);
						SetPinVal(ROOM1_DOOR_PIN, PIN_LOW);
						SetPinVal(DIO_PORTC, PIN_6, PIN_LOW);
						//cmd2 = 1;

					}

				}
					break;
				}

			}
				break;
			case ROOM_LED: {
				//cmd = 1;
				//send status
				//receive order
				cmd = SPI_Transceive(roomStatus);

				switch (cmd) {
				case CMD_LED_ON:
					SetPinVal(ROOM1_LED_PIN, PIN_HIGH);
					break;
				case CMD_LED_OFF:
					SetPinVal(ROOM1_LED_PIN, PIN_LOW);
					break;
				}

			}
				break;
			}

		}
			break;
			/////////////////////////////////---ROOM 2----////////////////////////////////////////////////////
		case ROOM2: {
			//send status
			roomStatus = getRoomStatus(ROOM2);
			SPI_Transceive(roomStatus);
			//receive Order
			cmd = SPI_Transceive(roomStatus);
			switch (cmd) {
			case ROOM_DOOR: {
				//send status
				//receive order
				cmd = SPI_Transceive(roomStatus);

				switch (cmd) {
				case CMD_OPEN_DOOR: {
					//Check Door Status
					if (!getPinOUT(ROOM2_DOOR_LED_PIN)) {
						SetPinVal(ROOM2_DOOR_PIN, PIN_HIGH);
						_delay_us(1500);
						SetPinVal(ROOM2_DOOR_PIN, PIN_LOW);
						_delay_us(1500);
						SetPinVal(ROOM2_DOOR_PIN, PIN_HIGH);
						_delay_us(1500);
						SetPinVal(ROOM2_DOOR_PIN, PIN_LOW);
						SetPinVal(DIO_PORTC, PIN_7, PIN_HIGH);
						//	cmd2 = 0;

					}

				}
					break;
				case CMD_CLOSE_DOOR: {
					//Check Door Status
					if (getPinOUT(ROOM2_DOOR_LED_PIN)) {
						SetPinVal(ROOM2_DOOR_PIN, PIN_HIGH);
						_delay_us(50);
						SetPinVal(ROOM2_DOOR_PIN, PIN_LOW);
						_delay_us(50);
						SetPinVal(ROOM2_DOOR_PIN, PIN_HIGH);
						_delay_us(50);
						SetPinVal(ROOM2_DOOR_PIN, PIN_LOW);
						SetPinVal(DIO_PORTC, PIN_7, PIN_LOW);
						//cmd2 = 1;

					}
				}
					break;
				}

			}
				break;
			case ROOM_LED: {
				cmd = 1;
				//send status
				//receive order
				cmd = SPI_Transceive(roomStatus);

				switch (cmd) {
				case CMD_LED_ON:
					SetPinVal(ROOM2_LED_PIN, PIN_HIGH);
					break;
				case CMD_LED_OFF:
					SetPinVal(ROOM2_LED_PIN, PIN_LOW);
					break;
				}

			}
				break;
			}
		}
			break;
			/////////////////////////////////---ROOM 3----////////////////////////////////////////////////////
		case ROOM3: {
			//send status
			roomStatus = getRoomStatus(ROOM3);
			SPI_Transceive(roomStatus);
			//receive Order
			cmd = SPI_Transceive(roomStatus);
			switch (cmd) {
			case ROOM_DOOR: {
				//send status
				//receive order
				cmd = SPI_Transceive(roomStatus);
				switch (cmd) {
				case CMD_OPEN_DOOR: {
					//Check Door Status
					if (!getPinOUT(ROOM3_DOOR_LED_PIN)) {
						SetPinVal(ROOM3_DOOR_PIN, PIN_HIGH);
						_delay_us(1500);
						SetPinVal(ROOM3_DOOR_PIN, PIN_LOW);
						_delay_us(1500);
						SetPinVal(ROOM3_DOOR_PIN, PIN_HIGH);
						_delay_us(1500);
						SetPinVal(ROOM3_DOOR_PIN, PIN_LOW);
						SetPinVal(DIO_PORTD, PIN_0, PIN_HIGH);
						//cmd2 = 0;

					}

				}
					break;
				case CMD_CLOSE_DOOR: {
					//Check Door Status
					if (getPinOUT(ROOM3_DOOR_LED_PIN)) {
						SetPinVal(ROOM3_DOOR_PIN, PIN_HIGH);
						_delay_us(50);
						SetPinVal(ROOM3_DOOR_PIN, PIN_LOW);
						_delay_us(50);
						SetPinVal(ROOM3_DOOR_PIN, PIN_HIGH);
						_delay_us(50);
						SetPinVal(ROOM3_DOOR_PIN, PIN_LOW);
						SetPinVal(DIO_PORTD, PIN_0, PIN_LOW);
						//cmd2 = 1;

					}
				}
					break;
				}

			}
				break;
			case ROOM_LED: {
				cmd = 1;
				//send status
				//receive order
				cmd = SPI_Transceive(roomStatus);

				switch (cmd) {
				case CMD_LED_ON:
					SetPinVal(ROOM3_LED_PIN, PIN_HIGH);
					break;
				case CMD_LED_OFF:
					SetPinVal(ROOM3_LED_PIN, PIN_LOW);
					break;
				}

			}
				break;
			}
		}
			break;
			/////////////////////////////////---  AC ----////////////////////////////////////////////////////
		case AC: {
			//send status
			SPI_Transceive(getPinOUT(AC_PIN));
			//receive order
			cmd = SPI_Transceive(roomStatus);
			switch (cmd) {
			case CMD_AC_ON:
				SetPinVal(AC_PIN, PIN_HIGH);

				break;
			case CMD_AC_OFF:
				SetPinVal(AC_PIN, PIN_LOW);
				break;
			}

		}

		}

	}

}
ISR(INT0_vect) {
	//SetPinDir(DIO_PORTA, PIN_5, PIN_OUT);
	//SetPinVal(DIO_PORTA, PIN_5, PIN_HIGH);
	if (!getPinOUT(ROOM3_DOOR_LED_PIN)) {
		SetPinVal(ROOM3_DOOR_PIN, PIN_HIGH);
		_delay_us(1500);
		SetPinVal(ROOM3_DOOR_PIN, PIN_LOW);

		//cmd2 = 0;

	}
	if (!getPinOUT(ROOM2_DOOR_LED_PIN)) {
		SetPinVal(ROOM2_DOOR_PIN, PIN_HIGH);
		_delay_us(1500);
		SetPinVal(ROOM2_DOOR_PIN, PIN_LOW);

		//	cmd2 = 0;

	}
	if (!getPinOUT(ROOM1_DOOR_LED_PIN)) {
		SetPinVal(ROOM1_DOOR_PIN, PIN_HIGH);
		_delay_us(1500);
		SetPinVal(ROOM1_DOOR_PIN, PIN_LOW);

		//	cmd2 = 0;

	}
}
ISR(TIMER0_OVF_vect) {
	static u32 cnt = 0;
	cnt++;
	if (cnt == overflowNum) {

	u8 sensorRead;
	sensorRead = Sensor_Read();
	if (sensorRead >= 27 && getPinOUT(AC_PIN)) {
		//SetPinVal(AC_PIN, PIN_HIGH);
		SetPinVal(TEMPERATURE_CONTROL_PIN, PIN_HIGH);

	} else {
		SetPinVal(TEMPERATURE_CONTROL_PIN, PIN_LOW);
	}
		cnt = 0;
		TCNT0 = initialVal;
	}
}

u8 getRoomStatus(u8 room) {
	switch (room) {
	case ROOM1:
		return (getPinOUT(ROOM1_LED_PIN) + (getPinOUT(ROOM1_DOOR_LED_PIN) << 7));
	case ROOM2:
		return (getPinOUT(ROOM2_LED_PIN) + (getPinOUT(ROOM2_DOOR_LED_PIN) << 7));
	case ROOM3:
		return (getPinOUT(ROOM3_LED_PIN) + (getPinOUT(ROOM3_DOOR_LED_PIN) << 7));
	}
}
void setup() {
	//ROOM 1
	//light
	SetPinDir(ROOM1_LED_PIN, PIN_OUT);
	//door
	SetPinDir(ROOM1_DOOR_PIN, PIN_OUT);
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
	//Check Doors
	SetPinVal(ROOM3_DOOR_PIN, PIN_HIGH);
	_delay_us(50);
	SetPinVal(ROOM3_DOOR_PIN, PIN_LOW);

	SetPinVal(ROOM2_DOOR_PIN, PIN_HIGH);
	_delay_us(50);
	SetPinVal(ROOM2_DOOR_PIN, PIN_LOW);

	SetPinVal(ROOM1_DOOR_PIN, PIN_HIGH);
	_delay_us(50);
	SetPinVal(ROOM1_DOOR_PIN, PIN_LOW);

}



