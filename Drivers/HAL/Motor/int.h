/*
 * int.h
 *
 *  Created on: 27 Aug 2023
 *      Author: compu market
 */

#ifndef HAL_MOTOR_INT_H_
#define HAL_MOTOR_INT_H_

void initMotor(u8 port, u8 pin_1, u8 pin_2);
void MotorCW(u8 port, u8 pin_1, u8 pin_2);
void DCMotorCCW(u8 port, u8 pin_1, u8 pin_2);

#endif /* HAL_MOTOR_INT_H_ */
