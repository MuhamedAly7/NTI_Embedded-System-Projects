/*
 * keypad.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_KEYPAD_KEYPAD_H_
#define ECU_LAYER_KEYPAD_KEYPAD_H_
/*-------------------------------------Includes---------------------------------*/
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "keypad_cfg.h"
#include <util/delay.h>

/* ------------------------------------Macro declarations --------------------- */
#define KEYPAD_ROWS    4
#define KEYPAD_COLUMNS 4
/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Data types ----------------------------- */

// additional types
/* this type to help us to write things
 * in specific number of digits represented
 * in array of character and we can customize
 * the number of digits, we have two array,
 * one to display the right things that i write it
 * and other array to display wrote digits by '*',
 * in case if we write password and we won't to display
 * the real digits and we have cursor to point to the wanted place
 * to write the digits.  */
typedef struct{
    u8 digits[NUM_OF_DIGITS + 1];
    u8 pass_digits[NUM_OF_DIGITS + 1];
    u8 cursor;
}keypad_digit_t;

/* ------------------------------------Function declarations ------------------- */
void H_KEYPAD_void_Init(void);
void H_KEYPAD_u8_getPressedKey(u8 * pPressedKey);


// additional functions on keypad
void keypad_cursor_init(keypad_digit_t *digits_obj);
void H_KEYPAD_u8_WriteOnDigits(keypad_digit_t *digits_obj);

#endif /* ECU_LAYER_KEYPAD_KEYPAD_H_ */
