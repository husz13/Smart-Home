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
#include "min.h"
int main(void){
	LCD_Init();
	KeypadInit();
	/*int i = 0;
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

	 LCD_WriteNum(number);*/
	init_SPI_Master();
	LCD_WriteString("HUSSEIN");
	while(1){
		SPI_Start_Trans();
		SPI_Transceive('A');
		_delay_ms(500);
		SPI_Transceive('B');
		_delay_ms(500);
		SPI_Transceive('C');
		_delay_ms(500);
		SPI_Stop_Trans();


	}
}
