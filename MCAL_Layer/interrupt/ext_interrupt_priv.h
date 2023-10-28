/*
 * ext_interrupt_priv.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_PRIV_H_
#define MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_PRIV_H_

#include "../std_types.h"

#define EXTI_BASE      0x54


// MCUCSR register
typedef struct {
	volatile u8 RESERVED1 : 6;
	volatile u8 ISC2_BIT  : 1;
	volatile u8 RESERVED2 : 1;
}MCUCSR_REG;

// MCUCR register
typedef struct {
	volatile u8 ISC0_BITS : 2;
	volatile u8 ISC1_BITS : 2;
	volatile u8 RESERVED  : 4;
}MCUCR_REG;

typedef struct {
	volatile u8 RESERVED  : 5;
	volatile u8 INT2_BIT : 1;
	volatile u8 INT0_BIT : 1;
	volatile u8 INT1_BIT : 1;
}GICR_REG;

typedef struct {
	volatile u8 RESERVED  : 5;
	volatile u8 INTF2_BIT : 1;
	volatile u8 INTF0_BIT : 1;
	volatile u8 INTF1_BIT : 1;
}GIFR_REG;


typedef struct {
	volatile MCUCSR_REG MCUCSR_CFG;
	volatile MCUCR_REG MCUCR_CFG;
	volatile u8 RESERVED[4];
	volatile GIFR_REG GIFR_CFG;
	volatile GICR_REG GICR_CFG;
}EXT_INT_MAP;


#define EXT_INT_CONTROL         ((volatile EXT_INT_MAP *)EXTI_BASE)

#endif /* MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_PRIV_H_ */
