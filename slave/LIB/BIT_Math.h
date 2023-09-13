/*
 * BIT_Math.h
 *
 *  Created on: 22 Aug 2023
 *      Author: compu market
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define GetBit(bits, bitNo) ((bits >> (bitNo)) & 0x01)//((var >> bit) & (0x01))
#define SetBit(bits, bitNo) (bits |= (1 << bitNo))
#define ToggleBit(bits, bitNo) (bits ^= (1 << bitNo))
#define ClearBit(bits, bitNo) (bits &=~(1 << bitNo))//#define CLR_Bit(var , bit)    	(var &=~ (1<<bit))

#endif /* LIB_BIT_MATH_H_ */
