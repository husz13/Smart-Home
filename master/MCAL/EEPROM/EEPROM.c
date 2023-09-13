#include "EEPROM.h"
#include <avr/io.h>
#include <util/delay.h>
#include "../../HAL/LCD/int.h"

u8 EEPROM_ReadByteFromAddress(const u16 address)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1)
	;
	/* Set up address register */
	EEAR = address;
	/* Start EEPROM read by writing EERE */
	EECR |= (1 << EERE);
	/* Return data from data register */
	return EEDR;
}

void EEPROM_ReadBlockFromAddress(const u16 address, u8 dist[], const u16 size)
{
	/* Wait for completion of previous write */
	while (((EECR & (1 << EEWE))>>EEWE)==1)
	;

	u16 counter = 0; //the counter of bytes that are read

	while (counter < size) //loop until move all bytes to the given array
	{
		/* Set up address register */
		EEAR = address + counter;
		/* Start EEPROM read by writing EERE */
		EECR |= (1 << EERE);
		/* move data from data register to the array */
		*(dist + counter) = EEDR;

		counter++;//increase the bytes counter
	}
}

void EEPROM_WriteByteToAddress(const u16 address, const u8 data)
{

	/* Wait for completion of previous write process*/
	while ( ( (EECR & (1 << EEWE) ) >>EEWE ) == 1)
	;
	/* Set up address register */
	EEAR = address;

	/* Read the byte in the address of EEAR */
	EECR |= (1 << EERE);
	if (EEDR != data) //compare the value read to the value to be written
	{//if they are not equal then write the data
		EEDR = data; //move the data to EEDR

		/* Write logical one to EEMWE */
		EECR |= (1 << EEMWE);
		/* Start EEPROM write by setting EEWE */
		EECR |= (1 << EEWE);
	}
	else
	{

	}

}

void EEPROM_WriteBlockToAddress(const u16 address, const u8 data[],
		const u16 size)
{
	u8 i;
	for (i = 0; i < size; i++) {
		LCD_WriteChar(i + '0');
		EEPROM_WriteByteToAddress(address + i, data[i]);
		_delay_ms(1000);
	}
}
