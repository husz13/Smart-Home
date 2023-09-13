/*
 * prg.c
 *
 *  Created on: 9 Sept 2023
 *      Author: compu market
 */
#include <avr/io.h>
#include "../../LIB/BIT_Math.h"
#include "../../LIB/Def_Types.h"
#include "../../MCAL/DIO/int.h"
#include "int.h"
void init_SPI_Master() {

	SetPinDir(DIO_PORTB, PIN_6, PIN_IN); //Set MISO dir

	SetPinDir(DIO_PORTB, PIN_5, PIN_OUT); //Set MOSI dir

	SetPinDir(DIO_PORTB, PIN_7, PIN_OUT); //Set SCK dir

	SetPinDir(DIO_PORTB, PIN_4, PIN_OUT); //Set Slave Select dir

	SetPinVal(DIO_PORTB, PIN_4, PIN_HIGH); //Set Slave to High
	//Set to Master
	SetBit(SPCR, 4);
	//Set CLK
	SetBit(SPCR, 0);
	SetBit(SPCR, 1);
	//Enable SPI
	SetBit(SPCR, 6);


}

void init_SPI_Slave() {
	SetPinDir(DIO_PORTB, PIN_6, PIN_OUT); //Set MISO dir

	SetPinDir(DIO_PORTB, PIN_5, PIN_IN); //Set MOSI dir

	SetPinDir(DIO_PORTB, PIN_7, PIN_IN); //Set SCK dir

	SetPinDir(DIO_PORTB, PIN_4, PIN_IN); //Set Slave Select dir
	//Set to Slave
	ClearBit(SPCR, 4);
	//Enable SPI
	SetBit(SPCR, 6);
}
void SPI_Start_Trans() {
	SetPinVal(DIO_PORTB, PIN_4, PIN_LOW);
}
void SPI_Stop_Trans() {
	SetPinVal(DIO_PORTB, PIN_4, PIN_LOW);
}
u8 SPI_Transceive(u8 data) {
	SPDR = data;
	while (GetBit(SPSR, 7) == 0)
		;
	return SPDR;

}


