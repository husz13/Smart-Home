/*
 * int.h
 *
 *  Created on: 28 Aug 2023
 *      Author: compu market
 */

#ifndef HAL_STEPPERMOTOR_INT_H_
#define HAL_STEPPERMOTOR_INT_H_
#define AngelPerStep 10

void initStepperMotor(u8 port, u8 pin_1, u8 pin_2, u8 pin_3, u8 pin_4);
void StepperMotorCW(u8 port, u8 pin_1, u8 pin_2, u8 pin_3, u8 pin_4, u8 angel);
void StepperMotorCCW(u8 port, u8 pin_1, u8 pin_2, u8 pin_3, u8 pin_4, u8 angel);
#endif /* HAL_STEPPERMOTOR_INT_H_ */
