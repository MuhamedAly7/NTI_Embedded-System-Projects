/*
 * keypad.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "keypad.h"

static const u8 btn_values[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
};

static const u8 btn_values2[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
		{'1', '2', '3', '4'},
		{'5', '6', '7', '8'},
		{'9', '0', '-', 'a'},
		{'b', 'c', 'd', 'e'},
};

// this in case we write a password
static const u8 btn_values2_pass[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
		{'*', '*', '*', '*'},
		{'*', '*', '*', '*'},
		{'*', '*', '-', '*'},
		{'*', '*', '*', '*'},
};

static u8 rows_pins[4] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN};
static u8 cols_pins[4] = {KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN, KEYPAD_C4_PIN};

static u8 rows_ports[4] = {KEYPAD_R1_PORT, KEYPAD_R2_PORT, KEYPAD_R3_PORT, KEYPAD_R4_PORT};
static u8 cols_ports[4] = {KEYPAD_C1_PORT, KEYPAD_C2_PORT, KEYPAD_C3_PORT, KEYPAD_C4_PORT};




void H_KEYPAD_void_Init(void)
{
	// initialize rows to be output mode
	DIO_voidSetPinDirection(KEYPAD_R1_PORT, KEYPAD_R1_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_R2_PORT, KEYPAD_R2_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_R3_PORT, KEYPAD_R3_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_R4_PORT, KEYPAD_R4_PIN, GPIO_DIRECTION_OUTPUT);

	// initialize columns to be output mode
	DIO_voidSetPinDirection(KEYPAD_C1_PORT, KEYPAD_R1_PIN, GPIO_DIRECTION_INPUT);
	DIO_voidSetPinDirection(KEYPAD_C2_PORT, KEYPAD_R2_PIN, GPIO_DIRECTION_INPUT);
	DIO_voidSetPinDirection(KEYPAD_C3_PORT, KEYPAD_R3_PIN, GPIO_DIRECTION_INPUT);
	DIO_voidSetPinDirection(KEYPAD_C4_PORT, KEYPAD_R4_PIN, GPIO_DIRECTION_INPUT);
}



void H_KEYPAD_u8_getPressedKey(u8 * pPressedKey)
{
	u8 l_row_counter = 0;
	u8 l_column_counter = 0;
	u8 l_counter = 0;
	u8 row_logic = 1;
	for(l_row_counter = 0; l_row_counter < KEYPAD_ROWS; l_row_counter++)
	{
		// Set All pins to be low at first
		for(l_counter = 0; l_counter < KEYPAD_ROWS; l_counter++)
		{
			DIO_voidSetPinValue(rows_ports[l_counter], rows_pins[l_counter], GPIO_HIGH);
		}

		DIO_voidSetPinValue(rows_ports[l_row_counter], rows_pins[l_row_counter], GPIO_LOW);

		_delay_ms(10);

		for(l_column_counter = 0; l_column_counter < KEYPAD_COLUMNS; l_column_counter++)
		{
			row_logic = DIO_u8GetPinValue(cols_ports[l_column_counter], cols_pins[l_column_counter]);

			if(row_logic == GPIO_LOW)
			{
				*pPressedKey = btn_values[l_row_counter][l_column_counter];
			}
			else{/* Nothing */}
		}
	}
}



/* -------------------------------------------------------------- Additional functions ----------------------------------------- */

// to initialize digits
void keypad_cursor_init(keypad_digit_t *digits_obj)
{
	uint8_t l_cursor = 0;
	if(NULL != digits_obj)
	{
		digits_obj->cursor = 0;
		for(l_cursor = 0; l_cursor < NUM_OF_DIGITS + 1; l_cursor++)
		{
			digits_obj->digits[l_cursor] = 0;
			digits_obj->pass_digits[l_cursor] = 0;
		}
	}
}



void H_KEYPAD_u8_WriteOnDigits(keypad_digit_t *digits_obj)
{
	u8 l_row_counter = 0;
	u8 l_column_counter = 0;
	u8 l_counter = 0;
	u8 row_logic = 1;
	for(l_row_counter = 0; l_row_counter < KEYPAD_ROWS; l_row_counter++)
	{
		// Set All pins to be low at first
		for(l_counter = 0; l_counter < KEYPAD_ROWS; l_counter++)
		{
			DIO_voidSetPinValue(rows_ports[l_counter], rows_pins[l_counter], GPIO_HIGH);
		}

		DIO_voidSetPinValue(rows_ports[l_row_counter], rows_pins[l_row_counter], GPIO_LOW);

		_delay_ms(20);

		for(l_column_counter = 0; l_column_counter < KEYPAD_COLUMNS; l_column_counter++)
		{
			row_logic = DIO_u8GetPinValue(cols_ports[l_column_counter], cols_pins[l_column_counter]);

			if(row_logic == GPIO_LOW)
			{
				if(digits_obj->cursor < NUM_OF_DIGITS)
				{
					digits_obj->digits[digits_obj->cursor] = btn_values2[l_row_counter][l_column_counter];
					digits_obj->pass_digits[digits_obj->cursor] = btn_values2_pass[l_row_counter][l_column_counter];
					digits_obj->cursor += 1;
				}

				if(btn_values2[l_row_counter][l_column_counter] == '-')
				{
					digits_obj->cursor = 0;
				}

			}
			else{/* Nothing */}
		}
	}
}
