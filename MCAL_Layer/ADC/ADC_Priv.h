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
	volatile u8 ADPS_BITS  : 3;
    volatile u8 ADIE_BIT   : 1;
    volatile u8 ADIF_BIT   : 1;
    volatile u8 ADATE_BIT  : 1;
    volatile u8 ADSC_BIT   : 1;
    volatile u8 ADEN_BIT   : 1;
}ADCSRA_BITS;

typedef struct {
	volatile u8 MUX_BITS   : 5;
    volatile u8 ADLAR_BIT  : 1;
    volatile u8 REFS_BITS  : 2;
}ADMUX_BITS;

typedef struct {
	volatile u8 RESERVED_BITS : 5;
    volatile u8 ADTS_BITS     : 3;
}SFIOR_BITS;


typedef struct {
	volatile u8          ADCL_REG;
	volatile u8          ADCH_REG;
	volatile ADCSRA_BITS ADCSRA_REG;
	volatile ADMUX_BITS  ADMUX_REG;
	volatile u8          reserved[40];
	volatile SFIOR_BITS  SFIOR_REG;
}ADC_MAP_T;

// assign ADC addresses to map
#define ADC_CONTROL      ((volatile ADC_MAP_T*)ADC_REGS_BASE)

#endif /* MCAL_LAYER_ADC_ADC_PRIV_H_ */
