#include "EEPROM.h"
#include <avr/io.h>
#include <util/delay.h>
#include "../../HAL/LCD/int.h"
#include <avr/eeprom.h>


unsigned char EEPROM_read(unsigned int uiAddress)
{
	eeprom_busy_wait();
	u8 value;
	__EEGET(value , uiAddress);
	return value;
}



void EEPROM_write(unsigned int uiAddress, unsigned char ucData)
{
	eeprom_busy_wait();
	__EEPUT(uiAddress , ucData);
}


void EEPROM_WriteBlockToAddress(const u16 address, const u8* data,
		const u16 size){
	u8 i;
	for(i = 0; i < size; i++){
		eeprom_busy_wait();

		__EEPUT(address + i , *(data + i));
	}
}


void EEPROM_ReadBlockFromAddress(const u16 address, u8 dist[], const u16 size)
{
	u8 i;
	for(i = 0; i < size; i++){
		eeprom_busy_wait();
		dist[i] = EEPROM_read(address + i);
	}
}
