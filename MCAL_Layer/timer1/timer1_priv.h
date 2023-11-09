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

#define TCCR1B_CS10_BIT_POS     0
#define TCCR1B_CS11_BIT_POS     1
#define TCCR1B_CS12_BIT_POS     2
#define TCCR1B_WGM12_BIT_POS    3
#define TCCR1B_WGM12_BIT_POS    4
#define TCCR1B_ICES1_BIT_POS    6
#define TCCR1B_ICNC1_BIT_POS    7

// TCCR1A register
typedef struct {
	volatile u8 WGM1_0_BIT   : 1;
	volatile u8 WGM1_1_BIT   : 1;
	volatile u8 FOC1B_BIT    : 1;
	volatile u8 FOC1A_BIT    : 1;
	volatile u8 COM1B_BITS   : 2;
	volatile u8 COM1A_BITS   : 2;
}TCCR1A_REG;

#define TCCR1A_WGM10_BIT_POS    0
#define TCCR1A_WGM11_BIT_POS    1
#define TCCR1A_FOC1B_BIT_POS    2
#define TCCR1A_FOC1A_BIT_POS    3
#define TCCR1A_COM1B0_BIT_POS   4
#define TCCR1A_COM1B1_BIT_POS   5
#define TCCR1A_COM1A0_BIT_POS   6
#define TCCR1A_COM1A1_BIT_POS   7


// TIFR register
typedef struct {
	volatile u8 RESERVED11     : 2;
	volatile u8 TOV1_BIT       : 1;
	volatile u8 OCF1B_BIT      : 1;
	volatile u8 OCF1A_BIT      : 1;
	volatile u8 ICF1_BIT       : 1;
	volatile u8 RESERVED12     : 2;
}TIFR1_REG;

#define TIFR1_TOV1_BIT_POS      2
#define TIFR1_OCF1B_BIT_POS     3
#define TIFR1_OCF1A_BIT_POS     4
#define TIFR1_ICF1_BIT_POS      5

// TIMSK register
typedef struct {
	volatile u8 RESERVED11     : 2;
	volatile u8 TOIE1_BIT      : 1;
	volatile u8 OCIE1B_BIT     : 1;
	volatile u8 OCIE1A_BIT     : 1;
	volatile u8 TICIE1_BIT     : 1;
	volatile u8 RESERVED12     : 2;
}TIMSK1_REG;

#define TIMSK1_TOIE1_BIT_POS      2
#define TIMSK1_OCIE1B_BIT_POS     3
#define TIMSK1_OCIE1A_BIT_POS     4
#define TIMSK1_TICIE1_BIT_POS     5


typedef struct {
	volatile u16         ICR1_CFG;
	volatile u8          OCR1BL_CFG;
	volatile u8          OCR1BH_CFG;
	volatile u8          OCR1AL_CFG;
	volatile u8          OCR1AH_CFG;
	volatile u16         TCNT1_CFG;
	volatile TCCR1B_REG  TCCR1B_CFG;
	volatile TCCR1A_REG  TCCR1A_CFG;
	volatile u8          RESERVED[8];
	volatile TIFR1_REG   TIFR1_CFG;
	volatile TIMSK1_REG  TIMSK1_CFG;
}TIMER1_MAP;

typedef struct {
	volatile u16         ICR1_CFG;
	volatile u8          OCR1BL_CFG;
	volatile u8          OCR1BH_CFG;
	volatile u8          OCR1AL_CFG;
	volatile u8          OCR1AH_CFG;
	volatile u16         TCNT1_CFG;
	volatile u8          TCCR1B_CFG;
	volatile u8          TCCR1A_CFG;
	volatile u8          RESERVED[8];
	volatile u8          TIFR1_CFG;
	volatile u8          TIMSK1_CFG;
}TIMER1_MAP_2;



#define TIMER1_CONTROL           ((volatile TIMER1_MAP *)TIMER1_BASE)
#define TIMER1_CONTROL_2           ((volatile TIMER1_MAP_2 *)TIMER1_BASE)


#endif /* MCAL_LAYER_TIMER1_TIMER1_PRIV_H_ */
