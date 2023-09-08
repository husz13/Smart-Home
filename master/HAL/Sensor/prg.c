/*
 * prg.c
 *
 *  Created on: 30 Aug 2023
 *      Author: compu market
 */
#include"../../LIB/BIT_Math.h"
#include"../../LIB/Def_Types.h"
#include "../../MCAL/ADC/int.h"
void initSensor() {
	initADC();

}
u16 Sensor_Read() {
	u16 steps = ADC_Read();
	u16 volt = (steps * 5000.0) / 1024; //--> mv
	u16 Temp = volt / 10; //--> Sensor 10mv/C°
	return Temp;
}
