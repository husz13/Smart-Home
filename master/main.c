#include <avr/io.h>
#include "MCAL/DIO/int.h"
#include "HAL/LCD/int.h"
#include "HAL/KeyBad/int.h"
#include <util/delay.h>
int main(void){
	LCD_Init();
	KeypadInit();
	int i = 0;
	int number = 0;
	for(; i < 4; i++){
		while(1){
			int val = KeypadGetKey();
			if(val){
				number = number * 10 + val - '0';
				break;
			}
		}
	}

	LCD_WriteNum(number);
	while(1){

	}
}
