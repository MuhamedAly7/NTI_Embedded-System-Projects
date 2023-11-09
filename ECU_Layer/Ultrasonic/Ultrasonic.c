/*
 * Ultrasonic.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Mohamed Aly
 */


#include "Ultrasonic.h"

volatile u32 ovf_counter = 0;
volatile u32 ovf = 0;
volatile u8 state_machine_counter = 0;
volatile u32 reading_1 = 0;
volatile u32 reading_2 = 0;



/* ------------------------------ Timer1 Overflow ISR ------------------------- */
void Timer1_ovf_isr(void)
{
	ovf_counter++;
}
/* ---------------------------------------------------------------------------- */


/* ------------------------------ ICU ISR ------------------------------------- */
void Timer1_icu_isr(void)
{
	Error_Status_t ret_status = NO_ERROR;
	if(state_machine_counter == 0) // to detect rising edge
	{
		ret_status = Timer1_ICU_takeReading(&reading_1); // take value of current TCNT1 register

		ret_status = Timer1_ICU_SetTrigger(TIMER1_INPUT_CAPTURE_FALLING_EDGE);

		ovf_counter = 0;
	}
	else if(state_machine_counter == 1) // to detect falling edge
	{
		ret_status = Timer1_ICU_takeReading(&reading_2); // take value of current TCNT1 register
		ovf = ovf_counter;
		ret_status = Timer1_OVF_IntDisable();
		ret_status = Timer1_ICU_IntDisable();
	}
	state_machine_counter++;
}
/* ---------------------------------------------------------------------------- */



void Ultrasonic_Init(u8 Trig_Pin_Port, u8 Trig_Pin_PinNum, u8 Echo_Pin_Port, u8 Echo_Pin_Num)
{
	Error_Status_t ret_status = NO_ERROR;

	/* ---------------------------- Initialize Echo pin and Trig pin directions --------*/
	DIO_voidSetPinDirection(Trig_Pin_Port, Trig_Pin_PinNum, GPIO_DIRECTION_OUTPUT); // TRIG pin
	DIO_voidSetPinDirection(Echo_Pin_Port, Echo_Pin_Num, GPIO_DIRECTION_INPUT);  // ICU pin (ECHO pin)

	/* ---------------------------------- Timer1 Configurations ------------------------ */
	timer1_t timer1_obj = {
			.mode = TIMER1_NORMAL_MODE, // at normal mode
			.prescaler_select = TIMER1_PRESCALER_DIV_64,  // pre-scaler /64
			.ctc_mode_A_cfg = TIMER1_NON_PWM_NORMAL_PORT,
			.ctc_mode_B_cfg = TIMER1_NON_PWM_NORMAL_PORT,
			.icu_trigger = TIMER1_INPUT_CAPTURE_RISING_EDGE, // Trigger On rising edge
			.timer1_ovf_isr = Timer1_ovf_isr, // Set CallBack for Timer1 overflow
			.timer1_capt_isr = Timer1_icu_isr, // Set CallBack for ICU of Timer1
			.timer1_compA_isr = NULL,
			.timer1_compB_isr = NULL};

	/* ---------------------------------- Initialize Timer1 ----------------------------- */
	ret_status = Timer1_Init(&timer1_obj);

	/* ---------------------------------- Enable Overflow Interrupt of Timer1 ----------- */
	ret_status = Timer1_OVF_IntEnable();
	/* ---------------------------------- Enable ICU Interrupt of Timer1 ---------------- */
	ret_status = Timer1_ICU_IntEnable();

	/* ----------------------------------- Global Interrupt Enable ---------------------- */
	GIE_Enable();

	/* ---------------------------------- Set CallBacks --------------------------------- */
	ret_status = Timer1_OVF_setCallBack(&timer1_obj);
	ret_status = Timer1_ICU_setCallBack(&timer1_obj);

	/* ---------------------------------- Start Timer1 ---------------------------------- */
	ret_status = Timer1_start(&timer1_obj);
}



void Ultrasonic_SetTrigger(u8 Trig_Pin_Port, u8 Trig_Pin_Num)
{
	DIO_voidSetPinValue(Trig_Pin_Port, Trig_Pin_Num, GPIO_HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(Trig_Pin_Port, Trig_Pin_Num, GPIO_LOW);
}



void Ultrasonic_Read_Distance(u16 *distance)
{
	u32 counts = 0;
	Error_Status_t ret_status = NO_ERROR;

	if(state_machine_counter == 2)
	{
		state_machine_counter = 0;
		counts = ((u32)reading_2 + (u32)(ovf * 65535)) - (u32)reading_1;
		*distance = counts / 7.37;

		_delay_ms(300);
		ovf = 0;
		ovf_counter = 0;
		ret_status = Timer1_ICU_SetTrigger(TIMER1_INPUT_CAPTURE_RISING_EDGE);
		TIMER1_CONTROL->TIFR1_CFG.ICF1_BIT = 0;
		TIMER1_CONTROL->TIFR1_CFG.TOV1_BIT = 0;
		ret_status = Timer1_ICU_IntEnable();
		ret_status = Timer1_OVF_IntEnable();
	}
	else{ /* Nothing */ }

}
