/*
 * keypad_cfg.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_KEYPAD_KEYPAD_CFG_H_
#define ECU_LAYER_KEYPAD_KEYPAD_CFG_H_

/* --------------------- Number of digits ---------------------*/
#define NUM_OF_DIGITS                  3
/* ----------------------------------------------------------- */

// lcd port configurations
#define KEYPAD_PORTA_POS               0
#define KEYPAD_PORTB_POS               1
#define KEYPAD_PORTC_POS               2
#define KEYPAD_PORTD_POS               3

// lcd pin configurations
#define KEYPAD_PIN0_POS                0
#define KEYPAD_PIN1_POS                1
#define KEYPAD_PIN2_POS                2
#define KEYPAD_PIN3_POS                3
#define KEYPAD_PIN4_POS                4
#define KEYPAD_PIN5_POS                5
#define KEYPAD_PIN6_POS                6
#define KEYPAD_PIN7_POS                7


// keypad pins configurations
#define KEYPAD_R1_PORT                 KEYPAD_PORTC_POS
#define KEYPAD_R2_PORT                 KEYPAD_PORTC_POS
#define KEYPAD_R3_PORT                 KEYPAD_PORTC_POS
#define KEYPAD_R4_PORT                 KEYPAD_PORTC_POS
#define KEYPAD_C1_PORT                 KEYPAD_PORTD_POS
#define KEYPAD_C2_PORT                 KEYPAD_PORTD_POS
#define KEYPAD_C3_PORT                 KEYPAD_PORTD_POS
#define KEYPAD_C4_PORT                 KEYPAD_PORTD_POS

// keypad pins configurations
#define KEYPAD_R1_PIN                 KEYPAD_PIN5_POS
#define KEYPAD_R2_PIN                 KEYPAD_PIN4_POS
#define KEYPAD_R3_PIN                 KEYPAD_PIN3_POS
#define KEYPAD_R4_PIN                 KEYPAD_PIN2_POS
#define KEYPAD_C1_PIN                 KEYPAD_PIN7_POS
#define KEYPAD_C2_PIN                 KEYPAD_PIN6_POS // edited for ICU pin
#define KEYPAD_C3_PIN                 KEYPAD_PIN5_POS
#define KEYPAD_C4_PIN                 KEYPAD_PIN3_POS

#endif /* ECU_LAYER_KEYPAD_KEYPAD_CFG_H_ */
