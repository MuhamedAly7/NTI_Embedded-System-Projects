/*
 * timer1.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mohamed Aly
 */


#include "timer1.h"

// callbcaks for ISRs
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


		// To select the output compare match pin
		TIMER1_CONTROL->TCCR1A_CFG.COM1A_BITS = timer1_obj->ctc_mode_A_cfg;
		TIMER1_CONTROL->TCCR1A_CFG.COM1B_BITS = timer1_obj->ctc_mode_B_cfg;


		// Set trigger of ICU
		switch(timer1_obj->icu_trigger) {
			case TIMER1_INPUT_CAPTURE_RISING_EDGE:
				TIMER1_ICU_TRIGGER_RISING_EDGE();
				break;
			case TIMER1_INPUT_CAPTURE_FALLING_EDGE:
				TIMER1_ICU_TRIGGER_FALLING_EDGE();
				break;
		}
	}
	return ret_status;
}


Error_Status_t Timer1_start(const timer1_t *timer1_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer1_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		if(TIMER1_NORMAL_MODE == timer1_obj)
		{
			TIMER1_CONTROL->TCCR1B_CFG.CS1_BITS = timer1_obj->prescaler_select;
		}
		else
		{
			TIMER1_CONTROL->TCCR1B_CFG.CS1_BITS = timer1_obj->prescaler_select;
			DIO_voidSetPinDirection(PORTD_INDEX, PIN4_INDEX, GPIO_DIRECTION_OUTPUT);
			DIO_voidSetPinDirection(PORTD_INDEX, PIN5_INDEX, GPIO_DIRECTION_OUTPUT);
			DIO_voidSetPinDirection(PORTD_INDEX, PIN6_INDEX, GPIO_DIRECTION_INPUT);
			TIMER1_CONTROL->OCR1AL_CFG = 0;
			TIMER1_CONTROL->OCR1AH_CFG = 0;
			TIMER1_CONTROL->OCR1BL_CFG = 0;
			TIMER1_CONTROL->OCR1BH_CFG = 0;
		}
	}
	return ret_status;
}


Error_Status_t Timer1_stop(const timer1_t *timer1_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer1_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		TIMER1_CONTROL->TCCR1B_CFG.CS1_BITS = TIMER1_STOP_TIMER;
	}
	return ret_status;
}


Error_Status_t Timer1_GetCounts(const timer1_t *timer1_obj, u16 *Num_of_count)
{
	Error_Status_t ret_status = NO_ERROR;
	if((NULL == timer1_obj) || (NULL == Num_of_count))
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		*Num_of_count = (u16)(((TIMER1_CONTROL->TCNT1H_CFG) << 8) + (TIMER1_CONTROL->TCNT1L_CFG));
	}
	return ret_status;
}


Error_Status_t Timer1_setDelayTimeMilliSec(const timer1_t *timer1_obj, u8 Time_ms);


Error_Status_t Timer1_OVF_IntEnable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.TOIE1_BIT = 1;
	return ret_status;
}


Error_Status_t Timer1_OCA_IntEnable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.OCIE1A_BIT = 1;
	return ret_status;
}


Error_Status_t Timer1_OCB_IntEnable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.OCIE1B_BIT = 1;
	return ret_status;
}


Error_Status_t Timer1_ICU_IntEnable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.TICIE1_BIT = 1;
	return ret_status;
}


Error_Status_t Timer1_OVF_IntDisable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.TOIE1_BIT = 0;
	return ret_status;
}


Error_Status_t Timer1_OCA_IntDisable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.OCIE1A_BIT = 0;
	return ret_status;
}


Error_Status_t Timer1_OCB_IntDisable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.OCIE1B_BIT = 0;
	return ret_status;
}


Error_Status_t Timer1_ICU_IntDisable(void)
{
	Error_Status_t ret_status = NO_ERROR;
	TIMER1_CONTROL->TIMSK1_CFG.TICIE1_BIT = 0;
	return ret_status;
}


Error_Status_t Timer1_OVF_setCallBack(const timer1_t *timer1_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer1_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		Timer1_Over_Flow_isr = timer1_obj->timer1_ovf_isr;
	}
	return ret_status;
}


Error_Status_t Timer1_OCA_setCallBack(const timer1_t *timer1_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer1_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		Timer1_CompA_isr = timer1_obj->timer1_compA_isr;
	}
	return ret_status;
}
Error_Status_t Timer1_OCB_setCallBack(const timer1_t *timer1_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer1_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		Timer1_CompB_isr = timer1_obj->timer1_compB_isr;
	}
	return ret_status;
}
Error_Status_t Timer1_ICU_setCallBack(const timer1_t *timer1_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == timer1_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		Timer1_Capt_isr = timer1_obj->timer1_capt_isr;
	}
	return ret_status;
}

Error_Status_t Timer1_setFastPWM(const timer1_t *timer1_obj, u8 frequency ,u8 duty);
Error_Status_t Timer1_setphaseCorrectPWM(const timer1_t *timer1_obj,u8 frequency , u8 duty);


Error_Status_t Timer1_ICU_SetTrigger(u8 trigger)
{
	Error_Status_t ret_status = NO_ERROR;
	switch(trigger){
	case TIMER1_INPUT_CAPTURE_RISING_EDGE:
		TIMER1_ICU_TRIGGER_RISING_EDGE();
		break;
	case TIMER1_INPUT_CAPTURE_FALLING_EDGE:
		TIMER1_ICU_TRIGGER_FALLING_EDGE();
		break;
	default:
		ret_status = OUT_OF_RANGE_VALUE;
		break;
	}
	return ret_status;
}


Error_Status_t Timer1_ICU_takeReading(u16 *icr_reading)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == icr_reading)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		*icr_reading = (u16)(((TIMER1_CONTROL->ICR1H_CFG) << 8) + TIMER1_CONTROL->ICR1L_CFG);
	}
	return ret_status;
}


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
