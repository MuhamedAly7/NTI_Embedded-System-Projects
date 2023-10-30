/*
 * ADC_Priv.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_ADC_ADC_PRIV_H_
#define MCAL_LAYER_ADC_ADC_PRIV_H_

#include "../std_types.h"

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

// assign ADC addresses to map
#define ADC_MAP      ((volatile ADC_MAP_T*)ADC_REGS_BASE)

#endif /* MCAL_LAYER_ADC_ADC_PRIV_H_ */
