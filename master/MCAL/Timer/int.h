/*
 * int.h
 *
 *  Created on: 31 Aug 2023
 *      Author: compu market
 */

#ifndef MCAL_TIMER_INT_H_
#define MCAL_TIMER_INT_H_
//Normal mode
void initTimer0(void);
void Timer0_Start(void);
void Timer0_Stop(void);
void Timer0_wait_ms(u32 desiredTime);
//PWM0
void initPWM0(void);
void PWM0_Start(void);
void PWM0_Stop(void);
void PWM0_Generator(u8 DC);
//CLC
void initTimer1(void);
void Timer1_Start(void);
void Timer1_Stop(void);
void Timer1_wait_ms(u32 desiredTime);
//

#endif /* MCAL_TIMER_INT_H_ */
