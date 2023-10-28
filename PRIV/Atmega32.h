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



//typedef union{
//	// To control as one byte
//	volatile u8 ADC_REG;
//	// to access ADC low register
//	volatile u8 ADCL;
//	// to access ADC high register
//	volatile u8 ADCH;
//
//    // to control by ADMUX register container of bits
//    struct {
//    	volatile u8 MUX   : 5;
//    	volatile u8 ADLAR : 1;
//    	volatile u8 REFS  : 2;
//    }ADMUX_BITS;
//
//    // to control by ADMUX register container of bits
//    struct {
//    	volatile u8 ADPS  : 3;
//    	volatile u8 ADIE  : 1;
//    	volatile u8 ADIF  : 1;
//    	volatile u8 ADATE : 1;
//    	volatile u8 ADSC  : 1;
//    	volatile u8 ADEN  : 1;
//    }ADCSRA_BITS;
//
//    struct {
//    	volatile u8 RESERVED : 5;
//    	volatile u8 ADTS     : 3;
//    }SFIOR_BITS;
//
//}ADC_REGS_TYPE;

typedef struct {
	volatile u8 ADPS  : 3;
    volatile u8 ADIE  : 1;
    volatile u8 ADIF  : 1;
    volatile u8 ADATE : 1;
    volatile u8 ADSC  : 1;
    volatile u8 ADEN  : 1;
}ADCSRA_BITS;

typedef struct {
	volatile u8 MUX   : 5;
    volatile u8 ADLAR : 1;
    volatile u8 REFS  : 2;
}ADMUX_BITS;

typedef struct {
	volatile u8 RESERVED : 5;
    volatile u8 ADTS     : 3;
}SFIOR_BITS;


typedef struct {
	volatile u8 ADCL_REG;
	volatile u8 ADCH_REG;
	volatile ADCSRA_BITS ADCSRA_REG;
	volatile ADMUX_BITS ADMUX_REG;
	volatile u8 reserved[41];
	volatile SFIOR_BITS SFIOR_REG;
}ADC_MAP_T;

// assign port addresses to map
#define GPIO_PINS_D  ((volatile DIO_t*)PORTD_BASE)
#define GPIO_PINS_C  ((volatile DIO_t*)PORTC_BASE)
#define GPIO_PINS_B  ((volatile DIO_t*)PORTB_BASE)
#define GPIO_PINS_A  ((volatile DIO_t*)PORTA_BASE)


// assign ADC addresses to map
#define ADC_MAP      ((volatile ADC_MAP_T*)ADC_REGS_BASE)

/*----------------------------------------- Macros functions ----------------------------------*/


/*------------------------------------------API's------------------------------------------------*/



#endif /* PRIV_ATMEGA32_H_ */
