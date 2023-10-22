/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "MCAL_Layer/GPIO/GPIO.h"
#include "MCAL_Layer/std_types.h"
#include "ECU_Layer/Keypad/keypad.h"
#include "ECU_Layer/SevenSegment/seven_segment.h"
#include <util/delay.h>
#include "./main.h"



PROGRAM_STATUS_T ret_status = SUCCESS;

seven_segment_t my_seg = {.segment_type = SEGMENT_COMMON_ANODE,
						  .segment_pins[0].port = PORTB_INDEX,
						  .segment_pins[0].pin = SEGMENT_PIN0,
						  .segment_pins[0].direction = GPIO_DIRECTION_OUTPUT,
						  .segment_pins[0].logic = GPIO_HIGH,
						  .segment_pins[1].port = PORTB_INDEX,
						  .segment_pins[1].pin = SEGMENT_PIN1,
						  .segment_pins[1].direction = GPIO_DIRECTION_OUTPUT,
						  .segment_pins[1].logic = GPIO_HIGH,
						  .segment_pins[2].port = PORTB_INDEX,
						  .segment_pins[2].pin = SEGMENT_PIN2,
						  .segment_pins[2].direction = GPIO_DIRECTION_OUTPUT,
						  .segment_pins[2].logic = GPIO_HIGH,
						  .segment_pins[3].port = PORTB_INDEX,
						  .segment_pins[3].pin = SEGMENT_PIN3,
						  .segment_pins[3].direction = GPIO_DIRECTION_OUTPUT,
						  .segment_pins[3].logic = GPIO_HIGH};

/* Keypad variables */
keypad_t keypad = {.keypad_rows_pins[0].port = PORTC_INDEX,
                   .keypad_rows_pins[0].pin = PIN5_INDEX,
                   .keypad_rows_pins[0].direction = GPIO_DIRECTION_OUTPUT,
                   .keypad_rows_pins[0].logic = GPIO_LOW,
                   .keypad_rows_pins[1].port = PORTC_INDEX,
                   .keypad_rows_pins[1].pin = PIN4_INDEX,
                   .keypad_rows_pins[1].direction = GPIO_DIRECTION_OUTPUT,
                   .keypad_rows_pins[1].logic = GPIO_LOW,
                   .keypad_rows_pins[2].port = PORTC_INDEX,
                   .keypad_rows_pins[2].pin = PIN3_INDEX,
                   .keypad_rows_pins[2].direction = GPIO_DIRECTION_OUTPUT,
                   .keypad_rows_pins[2].logic = GPIO_LOW,
                   .keypad_rows_pins[3].port = PORTC_INDEX,
                   .keypad_rows_pins[3].pin = PIN2_INDEX,
                   .keypad_rows_pins[3].direction = GPIO_DIRECTION_OUTPUT,
                   .keypad_rows_pins[3].logic = GPIO_LOW,
                   .keypad_columns_pins[0].port = PORTD_INDEX,
                   .keypad_columns_pins[0].pin = PIN7_INDEX,
                   .keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT,
                   .keypad_columns_pins[0].logic = GPIO_LOW,
                   .keypad_columns_pins[1].port = PORTD_INDEX,
                   .keypad_columns_pins[1].pin = PIN6_INDEX,
                   .keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT,
                   .keypad_columns_pins[1].logic = GPIO_LOW,
                   .keypad_columns_pins[2].port = PORTD_INDEX,
                   .keypad_columns_pins[2].pin = PIN5_INDEX,
                   .keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT,
                   .keypad_columns_pins[2].logic = GPIO_LOW,
                   .keypad_columns_pins[3].port = PORTD_INDEX,
                   .keypad_columns_pins[3].pin = PIN3_INDEX,
                   .keypad_columns_pins[3].direction = GPIO_DIRECTION_INPUT,
                   .keypad_columns_pins[3].logic = GPIO_LOW};

GPIO_CFG_T my_pin1 = {.port = PORTA_INDEX,
					 .pin = PIN3_INDEX,
					 .direction = GPIO_DIRECTION_OUTPUT,
					 .logic = GPIO_HIGH};

GPIO_CFG_T my_pin2 = {.port = PORTA_INDEX,
					 .pin = PIN2_INDEX,
					 .direction = GPIO_DIRECTION_OUTPUT,
					 .logic = GPIO_HIGH};

u8 keypad_val_ones = 0;
u8 keypad_val_tens = 0;

int main()
{
	ret_status = DIO_SetPinDirection(&my_pin1);
	ret_status = DIO_SetPinDirection(&my_pin2);

	//ret_status = DIO_SetPinValue(&my_pin1, GPIO_HIGH);

	ret_status = seven_segment_initailize(&my_seg);
	ret_status = keypad_init(&keypad);
	while (1)
	{
		ret_status = keypad_read_value(&keypad, &keypad_val_ones);

		ret_status = DIO_SetPinValue(&my_pin2, GPIO_HIGH);
		ret_status = DIO_SetPinValue(&my_pin1, GPIO_LOW);
		ret_status = seven_segment_write_number(&my_seg, keypad_val_ones%10);
		_delay_ms(30);

		ret_status = DIO_SetPinValue(&my_pin2, GPIO_LOW);
		ret_status = DIO_SetPinValue(&my_pin1, GPIO_HIGH);
		ret_status = seven_segment_write_number(&my_seg, keypad_val_ones/10);
		_delay_ms(30);
	}

	return 0;
}
