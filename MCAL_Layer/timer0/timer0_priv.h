/*
 * timer0_priv.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_TIMER0_TIMER0_PRIV_H_
#define MCAL_LAYER_TIMER0_TIMER0_PRIV_H_

#include "../std_types.h"
#include "../interrupt/GIE_interrupt.h"

#define TIMER0_BASE      0x52

// TCCR0 register
typedef struct {
	volatile u8 CS0_BITS  : 3;
	volatile u8 WGM01_BIT : 1;
	volatile u8 COM0_BITS : 2;
	volatile u8 WGM00_BIT : 1;
	volatile u8 F0C0_BIT  : 1;
}TCCR0_REG;


// TIFR register
typedef struct {
	volatile u8 TOF0_BIT      : 1;
	volatile u8 OCF0_BIT      : 1;
	volatile u8 RESERVED_BITS : 6;
}TIFR_REG;

// TIMSK register
typedef struct {
	volatile u8 TOIE0_BIT      : 1;
	volatile u8 OCIE0_BIT      : 1;
	volatile u8 RESERVED_BITS  : 6;
}TIMSK_REG;


typedef struct {
	volatile u8        TCNT0_CFG;
	volatile TCCR0_REG TCCR0_CFG;
	volatile u8        RESERVED1[4];
	volatile TIFR_REG  TIFR_CFG;
	volatile TIMSK_REG TIMSK_CFG;
	volatile u8        RESERVED2[2];
	volatile u8        OCR0_CFG;
}TIMER0_MAP;




#define TIMER0_CONTROL           ((volatile TIMER0_MAP *)TIMER0_BASE)

#endif /* MCAL_LAYER_TIMER0_TIMER0_PRIV_H_ */
