/*
 * timer0.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_TIMER0_TIMER0_H_
#define MCAL_LAYER_TIMER0_TIMER0_H_

/* ----------------------------------------------- includes --------------------------------*/
#include "timer0_cfg.h"
#include "timer0_priv.h"
#include "../std_types.h"
#include "../std_libraries.h"
#include "../GPIO/GPIO.h"

/* ----------------------------------------------- macros objects ------------------------- */


// Define the address of the ISR vector for Timer0 Overflow
#define TIMER0_OVF_VECTOR __vector_11

// Define the address of the ISR vector for Timer0 Compare Match
#define TIMER0_COMPA_VECTOR __vector_10

// To select pre-scaler and start the timer0 at the same time
#define TIMER0_STOP_TIMER           0
#define TIMER0_PRESCALER_DIV_1      1
#define TIMER0_PRESCALER_DIV_8      2
#define TIMER0_PRESCALER_DIV_64     3
#define TIMER0_PRESCALER_DIV_256    4
#define TIMER0_PRESCALER_DIV_1024   5

// To make timer0 works in counter mode
#define TIMER0_EXTERNAL_FALLING_EDGE    6
#define TIMER0_EXTERNAL_RISING_EDGE     7


// To select mode of timer0
#define TIMER0_NORMAL_MODE              0
#define TIMER0_PWM_PHASE_CORRECT_MODE   1
#define TIMER0_CTC_MODE                 2
#define TIMER0_FAST_PWM_MODE            3


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


#define TIMER0_OVF_INT_ENABLE             0
#define TIMER0_CTC_INT_ENABLE             1

#define TIMER0_OVF_INT_DISABLE             2
#define TIMER0_CTC_INT_DISABLE             3


#define F_CPU    16
/* ----------------------------------------------- macros functions ----------------------- */


/* ----------------------------------------------- user data types -------------------------*/

typedef struct{
	void (*timer0_over_flow_isr)(void);
	void (*timer0_comp_isr)(void);
	u8 prescaler_select : 3;
	u8 mode             : 2;
	u8 ctc_mode_cfg     : 2;
	u8 reserved         : 1;
}timer0_t;

/* ------------------------------------------------ APIs ---------------------------------- */
Error_Status_t Timer0_Init(const timer0_t *timer0_obj);
Error_Status_t Timer0_start(const timer0_t *timer0_obj);
Error_Status_t Timer0_stop(const timer0_t *timer0_obj);
Error_Status_t Timer0_GetCounts(const timer0_t *timer0_obj, u8 *Num_of_count);
Error_Status_t Timer0_setDelayTimeMilliSec(const timer0_t *timer0_obj , u8 Time_ms, u32 *num_of_ovfs, u32 *rem_counts);
Error_Status_t Timer0_EnableInt(u8 Int_ID);
Error_Status_t Timer0_DisableInt(u8 Int_ID);
Error_Status_t Timer0_setCallBack(const timer0_t *timer0_obj);
Error_Status_t Timer0_setFastPWM(const timer0_t *timer0_obj, u8 frequency ,u8 duty);
Error_Status_t Timer0_setphaseCorrectPWM(const timer0_t *timer0_obj,u8 frequency , u8 duty);

#endif /* MCAL_LAYER_TIMER0_TIMER0_H_ */
