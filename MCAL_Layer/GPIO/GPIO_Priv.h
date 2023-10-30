/*
 * GPIO_Priv.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_GPIO_GPIO_PRIV_H_
#define MCAL_LAYER_GPIO_GPIO_PRIV_H_

#include "../std_types.h"

/* gpio ports base */
#define PORTA_BASE        0x39
#define PORTB_BASE        0x36
#define PORTC_BASE        0x33
#define PORTD_BASE        0x30

// ADC address base
#define ADC_REGS_BASE     0x24



/*----------------------------------------- User types -----------------------------------------*/


typedef struct {
    volatile u8 PINx;
    volatile u8 DDRx;
    volatile u8 PORTx;
} DIO_t;



// assign port addresses to map
#define GPIO_PINS_D  ((volatile DIO_t*)PORTD_BASE)
#define GPIO_PINS_C  ((volatile DIO_t*)PORTC_BASE)
#define GPIO_PINS_B  ((volatile DIO_t*)PORTB_BASE)
#define GPIO_PINS_A  ((volatile DIO_t*)PORTA_BASE)

#endif /* MCAL_LAYER_GPIO_GPIO_PRIV_H_ */
