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
#include "../GPIO/GPIO.h"

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
#define TIMER1_NORMAL_MODE                            0
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
#define TIMER1_NON_PWM_NORMAL_PORT      0
#define TIMER1_NON_PWM_TOGGLE_OC1       1
#define TIMER1_NON_PWM_CLEAR_OC1        2
#define TIMER1_NON_PWM_SET_OC1          3


// to configure fast pwm mode
#define TIMER1_FAST_PWM_NORMAL_PORT                  0
#define TIMER1_FAST_PWM_CLEAR_OC1_ON_COMPARE_MATCH   2
#define TIMER1_FAST_PWM_SET_OC1_ON_COMPARE_MATCH     3


// To configure phase correct mode
#define TIMER1_PHASE_CORRECT_PWM_NORMAL_PORT                   0
#define TIMER1_PHASE_CORRECT_PWM_CLEAR_OC1_ON_COMPARE_MATCH    2
#define TIMER1_PHASE_CORRECT_PWM_SET_OC1_ON_COMPARE_MATCH      3


#define TIMER1_INPUT_CAPTURE_FALLING_EDGE            0
#define TIMER1_INPUT_CAPTURE_RISING_EDGE             1

/* ----------------------------------------------- macros functions ----------------------- */
// These two macros to select the edge of triggering if ICU on timer1
#define TIMER1_ICU_TRIGGER_RISING_EDGE()           (TIMER1_CONTROL->TCCR1B_CFG.ICES1_BIT = TIMER1_INPUT_CAPTURE_RISING_EDGE)
#define TIMER1_ICU_TRIGGER_FALLING_EDGE()          (TIMER1_CONTROL->TCCR1B_CFG.ICES1_BIT = TIMER1_INPUT_CAPTURE_FALLING_EDGE)

/* ----------------------------------------------- user data types -------------------------*/

typedef struct{
	void (*timer1_ovf_isr)(void);
	void (*timer1_compA_isr)(void);
	void (*timer1_compB_isr)(void);
	void (*timer1_capt_isr)(void);
	u8 mode               : 4;
	u8 prescaler_select   : 3;
	u8 ctc_mode_A_cfg     : 2;
	u8 ctc_mode_B_cfg     : 2;
	u8 icu_trigger        : 1;
}timer1_t;


/* ------------------------------------------------ APIs ---------------------------------- */
Error_Status_t Timer1_Init(const timer1_t *timer1_obj);
Error_Status_t Timer1_start(const timer1_t *timer1_obj);
Error_Status_t Timer1_stop(const timer1_t *timer1_obj);
Error_Status_t Timer1_GetCounts(u16 *Num_of_count);
Error_Status_t Timer1_setDelayTimeMilliSec(const timer1_t *timer1_obj, u8 Time_ms);
Error_Status_t Timer1_OVF_IntEnable(void);
Error_Status_t Timer1_OCA_IntEnable(void);
Error_Status_t Timer1_OCB_IntEnable(void);
Error_Status_t Timer1_ICU_IntEnable(void);
Error_Status_t Timer1_OVF_IntDisable(void);
Error_Status_t Timer1_OCA_IntDisable(void);
Error_Status_t Timer1_OCB_IntDisabl(void);
Error_Status_t Timer1_ICU_IntDisable(void);
Error_Status_t Timer1_OVF_setCallBack(const timer1_t *timer1_obj);
Error_Status_t Timer1_OCA_setCallBack(const timer1_t *timer1_obj);
Error_Status_t Timer1_OCB_setCallBack(const timer1_t *timer1_obj);
Error_Status_t Timer1_ICU_setCallBack(const timer1_t *timer1_obj);
Error_Status_t Timer1_ICU_SetTrigger(u8 trigger);
Error_Status_t Timer1_ICU_takeReading(u16 *icr_reading);
Error_Status_t Timer1_setFastPWM(const timer1_t *timer1_obj, u8 frequency ,u8 duty);
Error_Status_t Timer1_setphaseCorrectPWM(const timer1_t *timer1_obj,u8 frequency , u8 duty);


#endif /* MCAL_LAYER_TIMER1_TIMER1_H_ */
