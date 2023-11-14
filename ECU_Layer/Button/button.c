/*
 * button.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Mohamed Aly
 */


#include "button.h"

/* Initialize the direction of button pin */
void Button_void_Init(u8 Button_Pin_Port, u8 Button_Pin_Num)
{
	DIO_voidSetPinDirection(Button_Pin_Port, Button_Pin_Num, GPIO_DIRECTION_INPUT);
}


/* read the state of button */
void Button_void_Read_State(u8 Button_Pin_Port, u8 Button_Pin_Num, button_active_t active_type, button_state_t *button_state)
{
	u8 logic_state = 0;
	logic_state = DIO_u8GetPinValue(Button_Pin_Port, Button_Pin_Num);
	if(BUTTON_ACTIVE_HIGH == active_type)
	{
		if(logic_state == GPIO_HIGH)
		{
			*button_state = BUTTON_PRESSED;
		}
		else if(logic_state == GPIO_LOW)
		{
			*button_state = BUTTON_RELEASED;
		}
	}
	else if(BUTTON_ACTIVE_LOW == active_type)
	{
		if(logic_state == GPIO_HIGH)
		{
			*button_state = BUTTON_RELEASED;
		}
		else if(logic_state == GPIO_LOW)
		{
			*button_state = BUTTON_PRESSED;
		}
	}
	else{/* Nothing */}
}
