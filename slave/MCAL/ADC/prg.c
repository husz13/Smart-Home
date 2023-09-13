/*
 * prg.c
 *
 *  Created on: 30 Aug 2023
 *      Author: compu market
 */

#include <avr/io.h>
#include "../../LIB/BIT_Math.h"
#include "../../LIB/Def_Types.h"
#include  "int.h"
/*/*
 * prg.c
 *
 *  Created on: Aug 30, 2023
 *      Author: repair
 */

/*
 void ADC_Init(void)
 {
 // 1- select channel  1  -----> 00001
 SET_Bit(ADMUX , 0);
 // 2- Ref voltage
 SET_Bit(ADMUX,6);
 CLR_Bit(ADMUX,7);
 // 3- prescaller
 SET_Bit(ADCSRA , 2);
 SET_Bit(ADCSRA , 1);
 CLR_Bit(ADCSRA , 0);
 // 4- right adjust
 CLR_Bit(ADMUX , 5);
 // 5- auto trigger
 SET_Bit(ADCSRA ,5);
 // 6- Enable ADC
 SET_Bit(ADCSRA ,7);
 }

 u16 ADC_Read(void)
 {
 // Read data
 // 1- start conversion
 SET_Bit(ADCSRA , 6);
 // 2- wait until flag = 1
 while(Get_Bit(ADCSRA,4) == 0);
 // 3- return digital value
 u16 digitalValue=0;
 digitalValue = ADCL;
 digitalValue |= ADCH<<8 ;
 return digitalValue;
 }
 */
void initADC() {
	DDRA = 0x00;
	// 1- Select Channel ;
	ClearBit(ADMUX, 0);

	//2-Reference voltage
	SetBit(ADMUX, 6);
	ClearBit(ADMUX, 7);
	//SET_Bit(ADMUX,6);
	//CLR_Bit(ADMUX,7);
	//3-PreScalar
	ClearBit(ADCSRA, 0);
	SetBit(ADCSRA, 1);
	SetBit(ADCSRA, 2);

	//4-Right Adjust
	ClearBit(ADMUX, 5);
	//5-auto Trigger
	SetBit(ADCSRA, 5);
	//6-Enable ADC
	SetBit(ADCSRA, 7);

}
u16 ADC_Read(void) { // Read Data ;
//1-Start Conversion
	SetBit(ADCSRA, 6);
//2-Until flag == 1 ;
	while (GetBit(ADCSRA,4) == 0) {
	}

//3-Return Data
	//u16 digitalVal = 0;
	//digitalVal = ADCH << 8 | ADCL;
	u16 digitalValue = 0;
	digitalValue = ADCL;
	digitalValue |= ADCH << 8;
	return digitalValue;

}

