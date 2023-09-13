/*
 * EEPROM.h
 *
 *  Created on: Apr 12, 2018
 *      Author: User
 */

#ifndef HEADERS_EEPROM_H_
#define HEADERS_EEPROM_H_

#include "../../LIB/Def_Types.h"

/*
	Function Name        : EEPROM_ui8ReadByteFromAddress
	Function Returns     : uint8
	Function Arguments   : const uint16 uiAddress
	Function Description :  Read one byte from the given  address.
*/
unsigned char EEPROM_read(unsigned int uiAddress);

/*
	Function Name        : EEPROM_vReadBlockFromAddress
	Function Returns     : void
	Function Arguments   : const uint16 uiAddress, uint8* dist,const uint16 size
	Function Description : Read block of bytes of the given size (size) and save the result to given array(dist array).
*/
void EEPROM_ReadBlockFromAddress(const u16 address, u8* dist, const u16 size);

/*
	Function Name        : EEPROM_vWriteByteToAddress
	Function Returns     : void
	Function Arguments   : const uint16 uiAddress, const uint8 uiData
	Function Description : Write one byte to given address.
*/
void EEPROM_write(unsigned int uiAddress, unsigned char ucData);

/*
	Function Name        : EEPROM_vWriteBlockToAddress
	Function Returns     : void
	Function Arguments   : const uint16 uiAddress, const uint8* uiData,const uint16 size
	Function Description : Write block of bytes  of the given size (size) to EEPROM at the given address(u16Address) from the given array (u8Data).
*/
void EEPROM_WriteBlockToAddress(const u16 address, const u8* data,
		const u16 size);

#endif /* HEADERS_EEPROM_H_ */
