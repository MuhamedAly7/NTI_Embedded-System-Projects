/*
 * ADC.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Mohamed Aly
 */

#include "ADC.h"

void ADC_voidInit(const ADC_cfg_t *ADC_obj)
{
	if(NULL != ADC_obj)
	{
		ADC_DISABLE_CFG();
		/* Make ADC port as input */
		DIO_voidSetPortDirection(PORTA_INDEX, 0x00);
		ADC_SELECT_VOLTAGE_REF_CFG(ADC_obj->voltage_reference_select);
		ADC_SELECT_PRESCALER(ADC_obj->prescaler_select);
		ADC_AUTO_TRIGGER_ENABLE_CONFIG();
		ADC_SELECT_TRIGGER_SOURCE_EVENT(ADC_obj->select_trigger_source);
		/* Enable ADC */
		ADC_ENABLE_CFG();
	}
	else{/* Nothing */}
}

void ADC_getDigitalValueSynchNonBlocking(u8 Copy_u8Channel)
{
	// select the channel
	ADC_SELECT_CHANNEL_CFG(Copy_u8Channel);

	// start conversion
	ADC_START_CONVERSION_CFG();


}
