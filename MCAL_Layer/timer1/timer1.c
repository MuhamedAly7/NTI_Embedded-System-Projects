/*
 * timer1.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mohamed Aly
 */


#include "timer1.h"

void (*Timer1_Over_Flow_isr)(void) = NULL;
void(*Timer1_CompB_isr)(void) = NULL;
void(*Timer1_CompA_isr)(void) = NULL;
void(*Timer1_Capt_isr)(void) = NULL;

Error_Status_t Timer1_Init(const timer1_t *timer1_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer1_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		// To initialize mode
		TIMER1_CONTROL->TCCR1A_CFG.WGM1_0_BIT = (((timer1_obj->mode) >> 0) & 0x01);
		TIMER1_CONTROL->TCCR1A_CFG.WGM1_1_BIT = (((timer1_obj->mode) >> 1) & 0x01);
		TIMER1_CONTROL->TCCR1B_CFG.WGM1_2_BIT = (((timer1_obj->mode) >> 2) & 0x01);
		TIMER1_CONTROL->TCCR1B_CFG.WGM1_3_BIT = (((timer1_obj->mode) >> 3) & 0x01);


	}
	return ret_status;
}


Error_Status_t Timer1_start(const timer1_t *timer1_obj);
Error_Status_t Timer1_stop(const timer1_t *timer1_obj);
Error_Status_t Timer1_GetCounts(const timer1_t *timer1_obj, u8 *Num_of_count);
Error_Status_t Timer1_setDelayTimeMilliSec(const timer1_t *timer1_obj, u8 Time_ms);
Error_Status_t Timer1_EnableInt(void);
Error_Status_t Timer1_DisableInt(void);
Error_Status_t Timer1_setCallBack(const timer1_t *timer1_obj);
Error_Status_t Timer1_setFastPWM(const timer1_t *timer1_obj, u8 frequency ,u8 duty);
Error_Status_t Timer1_setphaseCorrectPWM(const timer1_t *timer1_obj,u8 frequency , u8 duty);





/* ---------------------------------------- ISRs ---------------------------- */
// Define the ISR function with attribute
void TIMER1_OVF_VECTOR(void) __attribute__((signal, used, externally_visible));
void TIMER1_OVF_VECTOR(void)
{
	// Clear flag
	TIMER1_CONTROL->TIFR1_CFG.TOV1_BIT = 0;

	// execute ISR if it existed
	if(Timer1_Over_Flow_isr)
	{
		Timer1_Over_Flow_isr();
	}
}



// Define the ISR function with attribute
void TIMER1_COMPBVECTOR(void) __attribute__((signal, used, externally_visible));
void TIMER1_COMPBVECTOR(void)
{
	// Clear flag
	TIMER1_CONTROL->TIFR1_CFG.OCF1B_BIT = 0;

	// execute ISR if it existed
	if(Timer1_CompB_isr)
	{
		Timer1_CompB_isr();
	}
}



// Define the ISR function with attribute
void TIMER1_COMPAVECTOR(void) __attribute__((signal, used, externally_visible));
void TIMER1_COMPAVECTOR(void)
{
	// Clear flag
	TIMER1_CONTROL->TIFR1_CFG.OCF1A_BIT = 0;

	// execute ISR if it existed
	if(Timer1_CompA_isr)
	{
		Timer1_CompA_isr();
	}
}


// Define the ISR function with attribute
void TIMER1_CAPTVECTOR(void) __attribute__((signal, used, externally_visible));
void TIMER1_CAPTVECTOR(void)
{
	// Clear flag
	TIMER1_CONTROL->TIFR1_CFG.ICF1_BIT = 0;

	// execute ISR if it existed
	if(Timer1_Capt_isr)
	{
		Timer1_Capt_isr();
	}
}
