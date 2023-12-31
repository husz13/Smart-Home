/*
 * main.c
 *
 *  Created on: 22 Aug 2023
 *      Author: compu market
 */
#define SlavePin DIO_PORTB,PIN_4
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "MCAL/DIO/int.h"
#include "HAL/LCD/int.h"
#include "HAL/KeyBad/int.h"
#include "HAL/Sensor/int.h"
#include "HAL/Motor/int.h"
#include "HAL/StepperMotor/int.h"
#include <avr/interrupt.h>
#include"LIB/BIT_Math.h"
#include "MCAL/Interrupt/int.h"
#include "MCAL/ADC/int.h"
#include "MCAL/Timer/int.h"
#include "MCAL/SPI/int.h"
extern u32 overflowNum, initialVal;

void main(void) {
	//LCD_Init();
	//KeypadInit();

//initSensor();

	//initTimer1();
	//Timer1_wait_ms(500);
	//Timer1_Start();
//init_SPI_Slave();
	SetPinDir(DIO_PORTC, PIN_0, PIN_OUT);
	SetPinDir(DIO_PORTC, PIN_1, PIN_OUT);
	SetPinDir(DIO_PORTC, PIN_2, PIN_OUT);
	SetPinDir(DIO_PORTC, PIN_6, PIN_OUT);

	SetPinVal(DIO_PORTC, PIN_0, PIN_HIGH);
	SetPinVal(DIO_PORTC, PIN_1, PIN_HIGH);
	SetPinVal(DIO_PORTC, PIN_2, PIN_HIGH);
	SetPinVal(DIO_PORTC, PIN_6, PIN_HIGH);
	_delay_us(300);
	SetPinVal(DIO_PORTC, PIN_6, PIN_LOW);


	while (1) {


	}

}

ISR( INT0_vect) {
	TogglePin(DIO_PORTA, PIN_0);
}

ISR( TIMER0_OVF_vect) {
	static u32 counter = 0;
	counter++;
	if (counter == overflowNum) {
		TogglePin(DIO_PORTA, 0);
		counter = 0;
		TCNT0 = initialVal;

	}

}
ISR( TIMER1_COMPA_vect) {
	TogglePin(DIO_PORTB, PIN_2);
}
