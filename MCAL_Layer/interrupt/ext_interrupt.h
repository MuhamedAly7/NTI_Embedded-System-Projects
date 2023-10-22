/*
 * ext_interrupt.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_H_
#define MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_H_

/* ------------------------------------------ includes ------------------------ */
#include "../std_types.h"
#include "../std_libraries.h"

/* ------------------------------------------ macros objects ------------------ */

#define EXTI_LOW_LEVEL     0
#define EXTI_ONCHANGE      1
#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3


#define EXTI_INT0_ID   6
#define EXTI_INT1_ID   7
#define EXTI_INT2_ID   5

#define EXTI_BASE      0x54

/* -------------------------------------------macros functions ---------------- */

/* ------------------------------------------ user types ---------------------- */
typedef struct{
	volatile u8 MCUCSR_REG;
	volatile u8 MCUCR_REG;
	volatile u8 RESERVED[5];
	volatile u8 GICR_REG;
}Ext_Int_Regs;

#define EXTI_REGS    ((volatile Ext_Int_Regs *)EXTI_BASE)

/* -------------------------------------------APIs ---------------------------- */
void M_EXTI_voidEnable(u8 copy_u8intID, u8 trigger);
void M_EXTI_voidDisable(u8 copy_u8IntID);
PROGRAM_STATUS_T M_EXTI_voidSet_CallBack(void(*ptrfun)(void), u8 IntID);
#endif /* MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_H_ */
