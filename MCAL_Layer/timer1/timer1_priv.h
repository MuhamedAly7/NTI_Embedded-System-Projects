/*
 * timer1_priv.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_TIMER1_TIMER1_PRIV_H_
#define MCAL_LAYER_TIMER1_TIMER1_PRIV_H_

#include "../std_types.h"
#include "../interrupt/GIE_interrupt.h"

#define TIMER1_BASE      0x46


// TCCR1B register
typedef struct {
	volatile u8 CS1_BITS     : 3;
	volatile u8 WGM1_2_BIT   : 1;
	volatile u8 WGM1_3_BIT   : 1;
	volatile u8 reserved     : 1;
	volatile u8 ICES1_BIT    : 1;
	volatile u8 ICNC1_BIT    : 1;
}TCCR1B_REG;

// TCCR1A register
typedef struct {
	volatile u8 WGM1_0_BIT   : 1;
	volatile u8 WGM1_1_BIT   : 1;
	volatile u8 FOC1B_BIT    : 1;
	volatile u8 FOC1A_BIT    : 1;
	volatile u8 COM1B_BITS   : 2;
	volatile u8 COM1A_BITS   : 2;
}TCCR1A_REG;


// TIFR register
typedef struct {
	volatile u8 RESERVED11     : 2;
	volatile u8 TOV1_BIT       : 1;
	volatile u8 OCF1B_BIT      : 1;
	volatile u8 OCF1A_BIT      : 1;
	volatile u8 ICF1_BIT       : 1;
	volatile u8 RESERVED12     : 2;
}TIFR1_REG;


// TIMSK register
typedef struct {
	volatile u8 RESERVED11     : 2;
	volatile u8 TOIE1_BIT      : 1;
	volatile u8 OCIE1B_BIT     : 1;
	volatile u8 OCIE1A_BIT     : 1;
	volatile u8 TICIE1_BIT     : 1;
	volatile u8 RESERVED12     : 2;
}TIMSK1_REG;


typedef struct {
	volatile u8          ICR1L_CFG;
	volatile u8          ICR1H_CFG;
	volatile u8          OCR1BL_CFG;
	volatile u8          OCR1BH_CFG;
	volatile u8          OCR1AL_CFG;
	volatile u8          OCR1AH_CFG;
	volatile u8          TCNT1L_CFG;
	volatile u8          TCNT1H_CFG;
	volatile TCCR1B_REG  TCCR1B_CFG;
	volatile TCCR1A_REG  TCCR1A_CFG;
	volatile u8          RESERVED[8];
	volatile TIFR1_REG   TIFR1_CFG;
	volatile TIMSK1_REG  TIMSK1_CFG;
}TIMER1_MAP;



#define TIMER1_CONTROL           ((volatile TIMER1_MAP *)TIMER1_BASE)


#endif /* MCAL_LAYER_TIMER1_TIMER1_PRIV_H_ */
