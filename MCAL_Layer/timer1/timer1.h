/*
 * timer1.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_TIMER1_TIMER1_H_
#define MCAL_LAYER_TIMER1_TIMER1_H_

/* ----------------------------------------------- includes --------------------------------*/
#include "timer1_cfg.h"
#include "timer1_priv.h"
#include "../std_types.h"
#include "../std_libraries.h"

/* ----------------------------------------------- macros objects ------------------------- */


// Define the address of the ISR vector for Timer0 Overflow
#define TIMER1_OVF_VECTOR __vector_9

// Define the address of the ISR vector for Timer0 Compare Match
#define TIMER1_COMPBVECTOR __vector_8

// Define the address of the ISR vector for Timer0 Compare Match
#define TIMER1_COMPAVECTOR __vector_7

// Define the address of the ISR vector for Timer0 Compare Match
#define TIMER1_CAPTVECTOR __vector_6


// To select pre-scaler and start the timer0 at the same time
#define TIMER1_STOP_TIMER           0
#define TIMER1_PRESCALER_DIV_1      1
#define TIMER1_PRESCALER_DIV_8      2
#define TIMER1_PRESCALER_DIV_64     3
#define TIMER1_PRESCALER_DIV_256    4
#define TIMER1_PRESCALER_DIV_1024   5

// To make timer0 works in counter mode
#define TIMER1_EXTERNAL_FALLING_EDGE    6
#define TIMER1_EXTERNAL_RISING_EDGE     7


// To select mode of timer1
#define TIMER0_NORMAL_MODE                            0
#define TIMER1_PWM_PHASE_CORRECT_8BIT_MODE            1
#define TIMER1_PWM_PHASE_CORRECT_9BIT_MODE            2
#define TIMER1_PWM_PHASE_CORRECT_10BIT_MODE           3
#define TIMER1_CTC_MODE_OCR1A                         4
#define TIMER1_FAST_PWM_8BIT_MODE                     5
#define TIMER1_FAST_PWM_9BIT_MODE                     6
#define TIMER1_FAST_PWM_10BIT_MODE                    7
#define TIMER1_PWM_PHASE_FEQUENCY_CORRECT_ICR1_MODE   8
#define TIMER1_PWM_PHASE_FEQUENCY_CORRECT_OCR1A_MODE  9
#define TIMER1_PWM_PHASE_CORRECT_ICR1                 10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A                11
#define TIMER1_CTC_MODE_ICR1                          12
#define TIMER1_FAST_PWM_ICR1                          14
#define TIMER1_FAST_PWM_OCR1A                         15


// to configure pin in non_pwm mode
#define TIMER0_NON_PWM_NORMAL_PORT      0
#define TIMER0_NON_PWM_TOGGLE_OC0       1
#define TIMER0_NON_PWM_CLEAR_OC0        2
#define TIMER0_NON_PWM_SET_OC0          3


// to configure fast pwm mode
#define TIMER0_FAST_PWM_NORMAL_PORT                  0
#define TIMER0_FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH   2
#define TIMER0_FAST_PWM_SET_OC0_ON_COMPARE_MATCH     3


// To configure phase correct mode
#define TIMER0_PHASE_CORRECT_PWM_NORMAL_PORT                   0
#define TIMER0_PHASE_CORRECT_PWM_CLEAR_OC0_ON_COMPARE_MATCH    2
#define TIMER0_PHASE_CORRECT_PWM_SET_OC0_ON_COMPARE_MATCH      3
/* ----------------------------------------------- macros functions ----------------------- */


/* ----------------------------------------------- user data types -------------------------*/

typedef struct{
	void (*timer1_over_flow_isr)(void);
	void (*timer1_compA_isr)(void);
	void (*timer1_compB_isr)(void);
	void (*timer1_capt_isr)(void);
	u8 mode             : 4;
	u8 prescaler_select : 3;
	u8 ctc_mode_cfg     : 2;
}timer1_t;

/* ------------------------------------------------ APIs ---------------------------------- */
Error_Status_t Timer1_Init(const timer1_t *timer1_obj);
Error_Status_t Timer1_start(const timer1_t *timer1_obj);
Error_Status_t Timer1_stop(const timer1_t *timer1_obj);
Error_Status_t Timer1_GetCounts(const timer1_t *timer1_obj, u8 *Num_of_count);
Error_Status_t Timer1_setDelayTimeMilliSec(const timer1_t *timer1_obj, u8 Time_ms);
Error_Status_t Timer1_EnableInt(void);
Error_Status_t Timer1_DisableInt(void);
Error_Status_t Timer1_setCallBack(const timer1_t *timer1_obj);
Error_Status_t Timer1_setFastPWM(const timer1_t *timer1_obj, u8 frequency ,u8 duty);
Error_Status_t Timer1_setphaseCorrectPWM(const timer1_t *timer1_obj,u8 frequency , u8 duty);


#endif /* MCAL_LAYER_TIMER1_TIMER1_H_ */
