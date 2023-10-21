/*
 * Atmega32.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef PRIV_ATMEGA32_H_
#define PRIV_ATMEGA32_H_

/*------------------------------------------ Includes -----------------------------------------*/
#include "../MCAL_Layer/std_types.h"

/*------------------------------------------ Includes -----------------------------------------*/


/*----------------------------------------- Macros objects ------------------------------------*/

#define PORTA_BASE        0x39
#define PORTB_BASE        0x36
#define PORTC_BASE        0x33
#define PORTD_BASE        0x30



/*----------------------------------------- User types -----------------------------------------*/

typedef union{
	volatile u8 Port_reg; // To access 1 byte
    struct {
        volatile u8 PIN_0 : 1;
        volatile u8 PIN_1 : 1;
        volatile u8 PIN_2 : 1;
        volatile u8 PIN_3 : 1;
        volatile u8 PIN_4 : 1;
        volatile u8 PIN_5 : 1;
        volatile u8 PIN_6 : 1;
        volatile u8 PIN_7 : 1;
    }Port_reg_bits; // To access bit by bit
}Port_one_reg;

typedef struct {
    volatile Port_one_reg PINx;
    volatile Port_one_reg DDRx;
    volatile Port_one_reg PORTx;
} Peripheral_t;

/*----------------------------------------- Macros functions ----------------------------------*/

#define GPIO_PINS_D  ((volatile Peripheral_t*)PORTD_BASE)
#define GPIO_PINS_C  ((volatile Peripheral_t*)PORTC_BASE)
#define GPIO_PINS_B  ((volatile Peripheral_t*)PORTB_BASE)
#define GPIO_PINS_A  ((volatile Peripheral_t*)PORTA_BASE)

/*------------------------------------------API's------------------------------------------------*/



#endif /* PRIV_ATMEGA32_H_ */
