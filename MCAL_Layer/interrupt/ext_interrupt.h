/*
 * ext_interrupt.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_H_
#define MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_H_

/* ------------------------------------------ includes ------------------------ */
#include "ext_interrupt_priv.h"
#include "GIE_interrupt.h"
#include "../std_types.h"
#include "../std_libraries.h"

/* ------------------------------------------ macros objects ------------------ */

#define INT0_VECTOR __vector_1
#define INT1_VECTOR __vector_2
#define INT2_VECTOR __vector_3

#define EXTI_INT0_LOW_LEVEL     0
#define EXTI_INT0_ONCHANGE      1
#define EXTI_INT0_FALLING_EDGE  2
#define EXTI_INT0_RISING_EDGE   3

#define EXTI_INT1_LOW_LEVEL     0
#define EXTI_INT1_ONCHANGE      1
#define EXTI_INT1_FALLING_EDGE  2
#define EXTI_INT1_RISING_EDGE   3


#define EXTI_INT2_RISING_EDGE   1
#define EXTI_INT2_FALLING_EDGE  0


// To enable or disable external interrupt
#define EXTI0_ENABLE       1
#define EXTI0_DISABLE      0

#define EXTI1_ENABLE       1
#define EXTI1_DISABLE      0

#define EXTI2_ENABLE       1
#define EXTI2_DISABLE      0

// to select which one we need
#define EXTI_INT0_ID   0
#define EXTI_INT1_ID   1
#define EXTI_INT2_ID   2


/* -------------------------------------------macros functions ---------------- */

/* ------------------------------------------ user types ---------------------- */


typedef struct {
	void (*EXT_INT_ISR)(void); // callback function
	u8 INTx_select : 2;
	u8 INTx_sense  : 2;
	u8 reserved    : 4;
}EXT_INTERRUPT_T;


/* -------------------------------------------APIs ---------------------------- */
Error_Status_t M_EXTI_voidEnable(const EXT_INTERRUPT_T *exti_obj);
Error_Status_t M_EXTI_voidDisable(const EXT_INTERRUPT_T *exti_obj);
Error_Status_t M_EXTI_voidSet_CallBack(const EXT_INTERRUPT_T *exti_obj);
#endif /* MCAL_LAYER_INTERRUPT_EXT_INTERRUPT_H_ */
