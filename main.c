/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "main.h"

/* -------------------------- Task scheduler structure ------------------------*/
typedef struct {
	void (*TaskFunctionPtr)(void);
	uint16_t interval;
	uint16_t ticks;
} Task;
/* --------------------------------------------------------------------------- */


/* ---------------------- Function prototypes for tasks -----------------------*/
void task1(void);
void task2(void);
void task3(void);
/* --------------------------------------------------------------------------- */



/* ------------------------------------ Define Our tasks --------------------------*/
Task tasks[] = {
		{task1, 1000, 0}, // Task 1: Blink RED LED every 1 sec
		{task2, 500, 0},  // Task 2: Toggle BLUE LED when PB1 is pressed, runs every 500 msec
		{task3, 3000, 0}  // Task 3: Blink GREEN LED every 3 sec
};
/* ---------------------------------------------------------------------------- */


/* ------------------------- -- Ready queue to organize tasks ------------------*/
Task* readyQueue[3];
/* ---------------------------------------------------------------------------- */


/* -------------------------------- Timer0 ISR ----------------------------- */
void Timer0_ovf_ISR(void)
{
	for (int i = 0; i < (sizeof(tasks) / sizeof(tasks[0])); i++) {
		tasks[i].ticks++;
		if (tasks[i].ticks >= tasks[i].interval) {
			tasks[i].ticks = 0;
			if (readyQueue[i] == NULL) {
				readyQueue[i] = &tasks[i];
			}
		}
	}
}
/* -------------------------------------------------------------------------- */


/* ----------------------------------- Error status ------------------------- */
Error_Status_t ret_status = NO_ERROR;
/* -------------------------------------------------------------------------- */


/* ----------------------------------- Timer0 Configurations ----------------- */
timer0_t timer0_obj = {
		.mode = TIMER0_NORMAL_MODE,
		.prescaler_select = TIMER1_PRESCALER_DIV_64, // pre-scaler 64
		.ctc_mode_cfg = TIMER0_NON_PWM_NORMAL_PORT, // no pwm
		.timer0_over_flow_isr = Timer0_ovf_ISR,     // timer0 overflow callback
		.timer0_comp_isr = NULL};                  // not use compare match interrupt
/* --------------------------------------------------------------------------- */


// Task 1: Blink RED LED every 1 second
void task1() {
	Led_Toggle(PORTB_INDEX, PIN7_INDEX);
}

// Task 2: Toggle BLUE LED when PB1 is pressed, runs every 500 ms
void task2() {
	u8 get_logic = 0;
	get_logic = DIO_u8GetPinValue(PORTA_INDEX, PIN0_INDEX);
	if(get_logic == 1)
	{
		Led_Toggle(PORTA_INDEX, PIN5_INDEX);
	}
}

// Task 3: Blink GREEN LED every 3 s
void task3() {
	Led_Toggle(PORTA_INDEX, PIN4_INDEX);
}


int main()
{
	/* --------------- Initialize 3 LED3 blue and green and red ----------- */
	Led_Init(PORTB_INDEX, PIN7_INDEX);
	Led_Init(PORTA_INDEX, PIN4_INDEX);
	Led_Init(PORTA_INDEX, PIN5_INDEX);
	/*----------------------------------------------------------------------*/

	/* --------------------------- Initialize button pin direction -----------------  */
	DIO_voidSetPinDirection(PORTA_INDEX, PIN0_INDEX, GPIO_DIRECTION_INPUT);
	/* ------------------------------------------------------------------------------ */

	/* ------------ Initialize timer0 based on configurations above "timer0_obj" ---- */
	ret_status = Timer0_Init(&timer0_obj);
	/*--------------------------------------------------------------------------------*/

	/* -------------------------- Gloval Interrupt Enable -------------------------- */
	GIE_Enable();
	/*-------------------------------------------------------------------------------*/

	/* -------------------- Enable timer0 overflow interrupt ----------------------- */
	ret_status = Timer0_EnableInt(TIMER0_OVF_INT_ENABLE);
	/* ----------------------------------------------------------------------------- */

	/* ----------------------- Set callbacks of Timer0 ISRs ------------------------- */
	ret_status = Timer0_setCallBack(&timer0_obj);
	/* ------------------------------------------------------------------------------ */

	/* ------------------------------- Start timer0 --------------------------------- */
	ret_status = Timer0_start(&timer0_obj);
	/* ------------------------------------------------------------------------------ */

	/* This considered be Idle task if there is no task in ready queue */
	while (1)
	{
		for (int i = 0; i < (sizeof(readyQueue) / sizeof(readyQueue[0])); i++) {
			if (readyQueue[i] != NULL) {
				readyQueue[i]->TaskFunctionPtr();
				readyQueue[i] = NULL;
			}
		}
	}
	/* --------------------------------------------------------------- */

	return 0;
}
