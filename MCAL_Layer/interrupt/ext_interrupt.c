

#include "ext_interrupt.h"

void (*INT0_ISR)(void) = NULL;
void (*INT1_ISR)(void) = NULL;
void (*INT2_ISR)(void) = NULL;

Error_Status_t M_EXTI_voidEnable(const EXT_INTERRUPT_T *exti_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == exti_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		GIE_Enable();
		switch (exti_obj->INTx_select) {
			case EXTI_INT0_ID:
				EXT_INT_CONTROL->GICR_CFG.INT0_BIT = EXTI0_ENABLE;
				EXT_INT_CONTROL->MCUCR_CFG.ISC0_BITS = exti_obj->INTx_sense;
				break;
			case EXTI_INT1_ID:
				EXT_INT_CONTROL->GICR_CFG.INT1_BIT = EXTI1_ENABLE;
				EXT_INT_CONTROL->MCUCR_CFG.ISC1_BITS = exti_obj->INTx_sense;
				break;
			case EXTI_INT2_ID:
				EXT_INT_CONTROL->GICR_CFG.INT2_BIT = EXTI2_ENABLE;
				EXT_INT_CONTROL->MCUCSR_CFG.ISC2_BIT = exti_obj->INTx_sense;
				break;
			default:
				ret_status = OUT_OF_RANGE_VALUE;
				break;
		}
	}
	return ret_status;
}
Error_Status_t M_EXTI_voidDisable(const EXT_INTERRUPT_T *exti_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == exti_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		GIE_Disable();
		switch (exti_obj->INTx_select) {
			case EXTI_INT0_ID:
				EXT_INT_CONTROL->GICR_CFG.INT0_BIT = EXTI0_DISABLE;
				break;
			case EXTI_INT1_ID:
				EXT_INT_CONTROL->GICR_CFG.INT1_BIT = EXTI1_DISABLE;
				break;
			case EXTI_INT2_ID:
				EXT_INT_CONTROL->GICR_CFG.INT2_BIT = EXTI2_DISABLE;
				break;
			default:
				ret_status = OUT_OF_RANGE_VALUE;
				break;
		}
	}
	return ret_status;
}
Error_Status_t M_EXTI_voidSet_CallBack(const EXT_INTERRUPT_T *exti_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == exti_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		switch (exti_obj->INTx_select) {
			case EXTI_INT0_ID:
				INT0_ISR = exti_obj->EXT_INT_ISR;
				break;
			case EXTI_INT1_ID:
				INT1_ISR = exti_obj->EXT_INT_ISR;
				break;
			case EXTI_INT2_ID:
				INT2_ISR = exti_obj->EXT_INT_ISR;
				break;
			default:
				ret_status = OUT_OF_RANGE_VALUE;
				break;
		}
	}
	return ret_status;
}


/* ----------------------------------------- External Interrupt ISRs -------------------------- */
// Define the ISR function with attribute
void INT0_VECTOR(void) __attribute__((signal));
void INT0_VECTOR(void)
{
	// Clear flag
	EXT_INT_CONTROL->GIFR_CFG.INTF0_BIT = 0;
	// execute ISR if it existed
	if(INT0_ISR)
	{
		INT0_ISR();
	}
}


// Define the ISR function with attribute
void INT1_VECTOR(void) __attribute__((signal));
void INT1_VECTOR(void)
{
	// clear flag
	EXT_INT_CONTROL->GIFR_CFG.INTF1_BIT = 0;
	// execute ISR if it existed
	if(INT1_ISR)
	{
		INT1_ISR();
	}
}


// Define the ISR function with attribute
void INT2_VECTOR(void) __attribute__((signal));
void INT2_VECTOR(void)
{
	// clear flag
	EXT_INT_CONTROL->GIFR_CFG.INTF2_BIT = 1;
	// execute ISR if it existed
	if(INT2_ISR)
	{
		INT2_ISR();
	}
}
