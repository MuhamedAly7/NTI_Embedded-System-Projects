/*
 * timer0.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mohamed Aly
 */

#include "timer0.h"

// pointer to function to execute callback function of overflow interrupt
void (*Timer0_Over_Flow_isr)(void) = NULL;

// pointer to function to execute callback function of compare match interrupt
void(*Timer0_Comp_isr)(void) = NULL;

//void (*Timer0_delay_callback)(void) = NULL;
//
//u32 num_of_ovfs = 0;
//u32 rem_counts = 0;
//static u32 countr_ovf = 0;


Error_Status_t Timer0_Init(const timer0_t *timer0_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer0_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		// To select mode
		TIMER0_CONTROL->TCCR0_CFG.WGM00_BIT = (((timer0_obj->mode) >> 0) & 0x01);
		TIMER0_CONTROL->TCCR0_CFG.WGM01_BIT = (((timer0_obj->mode) >> 1) & 0x01);

		// To select the output compare match pin
		TIMER0_CONTROL->TCCR0_CFG.COM0_BITS = timer0_obj->ctc_mode_cfg;
	}
	return ret_status;
}


Error_Status_t Timer0_start(const timer0_t *timer0_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer0_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		if(TIMER0_NORMAL_MODE == timer0_obj->mode){
			TIMER0_CONTROL->TCCR0_CFG.CS0_BITS = timer0_obj->prescaler_select;
		}
		else
		{
			TIMER0_CONTROL->TCCR0_CFG.CS0_BITS = timer0_obj->prescaler_select;
			DIO_voidSetPinDirection(PORTB_INDEX, PIN3_INDEX, GPIO_DIRECTION_OUTPUT);
			TIMER0_CONTROL->OCR0_CFG = 0;
		}

	}
	return ret_status;
}
Error_Status_t Timer0_stop(const timer0_t *timer0_obj)
{

	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer0_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		// assign no pre-scaler to pre-scaler select bits
		TIMER0_CONTROL->TCCR0_CFG.CS0_BITS = TIMER0_STOP_TIMER;
	}
	return ret_status;
}
Error_Status_t Timer0_GetCounts(const timer0_t *timer0_obj, u8 *Num_of_count)
{
	Error_Status_t ret_status = NO_ERROR;
	if((NULL == timer0_obj) || (NULL == Num_of_count))
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		*Num_of_count = TIMER0_CONTROL->TCNT0_CFG;
	}
	return ret_status;
}



Error_Status_t Timer0_setDelayTimeMilliSec(const timer0_t *timer0_obj , u8 Time_ms, u32 *num_of_ovfs, u32 *rem_counts)
{
	Error_Status_t ret_status = NO_ERROR;
	u32 Total_counts = 0;

	if(NULL == timer0_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		if(TIMER0_NORMAL_MODE == timer0_obj->mode)
		{
			switch(timer0_obj->prescaler_select){
			case TIMER0_PRESCALER_DIV_1:
				Total_counts = (F_CPU * Time_ms * 1000) / 1;    // 1 : prescaler
				break;
			case TIMER0_PRESCALER_DIV_8:
				Total_counts = (F_CPU * Time_ms * 1000) / 8;    // 8 : prescaler
				break;
			case TIMER0_PRESCALER_DIV_64:
				Total_counts = (F_CPU * Time_ms * 1000) / 64;   // 64 : prescaler
				break;
			case TIMER0_PRESCALER_DIV_256:
				Total_counts = (F_CPU * Time_ms * 1000) / 256;  // 256 : prescaler
				break;
			case TIMER0_PRESCALER_DIV_1024:
				Total_counts = (F_CPU * Time_ms * 1000) / 1024;  // 1024 : prescaler
				break;
			default:
				ret_status = OUT_OF_RANGE_VALUE;
				break;
			}
			*num_of_ovfs = (u32)(Total_counts / 256);
			*rem_counts = Total_counts % 256;
		}
		else if(TIMER0_CTC_MODE == timer0_obj->mode)
		{

		}
		else{/* Nothing */}
	}
	return ret_status;
}




Error_Status_t Timer0_EnableInt(u8 Int_ID)
{
	// Enable global interrupts

	// Enable timer0 overflow interrupt and compare match interrupt
	switch(Int_ID){
		case TIMER0_OVF_INT_ENABLE:
			TIMER0_CONTROL->TIMSK_CFG.TOIE0_BIT = 1;
			break;
		case TIMER0_CTC_INT_ENABLE:
			TIMER0_CONTROL->TIMSK_CFG.OCIE0_BIT = 1;
			break;
	}
	return NO_ERROR;
}




Error_Status_t Timer0_DisableInt(u8 Int_ID)
{
	// Disable timer0 overflow interrupt and compare match interrupt
	switch(Int_ID){
		case TIMER0_OVF_INT_DISABLE:
			TIMER0_CONTROL->TIMSK_CFG.TOIE0_BIT = 0;
			break;
		case TIMER0_CTC_INT_DISABLE:
			TIMER0_CONTROL->TIMSK_CFG.OCIE0_BIT = 0;
			break;
	}
	return NO_ERROR;
}



Error_Status_t Timer0_setCallBack(const timer0_t *timer0_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer0_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		Timer0_Over_Flow_isr = timer0_obj->timer0_over_flow_isr;
		Timer0_Comp_isr = timer0_obj->timer0_comp_isr;
	}
	return ret_status;
}
Error_Status_t Timer0_setFastPWM(const timer0_t *timer0_obj, u8 frequency ,u8 duty)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer0_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		if(TIMER0_FAST_PWM_MODE == timer0_obj->mode)
		{
			if(TIMER0_FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH == timer0_obj->ctc_mode_cfg)
			{
				TIMER0_CONTROL->OCR0_CFG = (duty * 255) / 100;
			}
			else if(TIMER0_FAST_PWM_SET_OC0_ON_COMPARE_MATCH == timer0_obj->ctc_mode_cfg)
			{
				//TIMER0_CONTROL->TCNT0_CFG =
				TIMER0_CONTROL->OCR0_CFG = 255 - ((duty * 255) / 100);
			}
			else{/* Nothing */}
		}
		else{/* Nothing */}
	}
	return ret_status;
}


Error_Status_t Timer0_setphaseCorrectPWM(const timer0_t *timer0_obj, u8 frequency , u8 duty)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer0_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		if(TIMER0_PWM_PHASE_CORRECT_MODE == timer0_obj->mode)
		{
			if(TIMER0_PHASE_CORRECT_PWM_CLEAR_OC0_ON_COMPARE_MATCH == timer0_obj->ctc_mode_cfg)
			{
				TIMER0_CONTROL->OCR0_CFG = (u8)(((u8)(duty * 255) / 100) / 2);
			}
			else if(TIMER0_PHASE_CORRECT_PWM_SET_OC0_ON_COMPARE_MATCH == timer0_obj->ctc_mode_cfg)
			{
				TIMER0_CONTROL->OCR0_CFG = (u8)(255 - ((u8)((duty * 255) / 100) / 2));
			}
			else{/* Nothing */}
		}
		else{/* Nothing */}
	}
	return ret_status;
}


/* ------------------------------------------------ Timer0 ISRs -------------------------------*/

// Define the ISR function with attribute
void TIMER0_OVF_VECTOR(void) __attribute__((signal, used, externally_visible));
void TIMER0_OVF_VECTOR(void)
{
	// Clear flag
	TIMER0_CONTROL->TIFR_CFG.TOF0_BIT = 0;

	//	countr_ovf++;
	//	if(countr_ovf == num_of_ovfs)
	//	{
	//		TIMER0_CONTROL->TCNT0_CFG = 256 - rem_counts;
	//		countr_ovf = 0;
	//		if(Timer0_delay_callback)
	//		{
	//			Timer0_delay_callback();
	//		}
	//	}

	// execute ISR if it existed
	if(Timer0_Over_Flow_isr)
	{
		Timer0_Over_Flow_isr();
	}
}



// Define the ISR function with attribute
void TIMER0_COMPA_VECTOR(void) __attribute__((signal, used, externally_visible));
void TIMER0_COMPA_VECTOR(void)
{
	// clear flag
	TIMER0_CONTROL->TIFR_CFG.OCF0_BIT = 0;

	// execute ISR if it existed
	if(Timer0_Comp_isr)
	{
		Timer0_Comp_isr();
	}
}

