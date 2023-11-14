/*
 * LM35.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Mohamed Aly
 */


#include "LM35.h"


void LM35_Init(void)
{
	ADC_cfg_t my_adc = {
			.select_trigger_source = ADC_SELECT_TRIGGER_FREE_SOURCE,
			.voltage_reference_select = ADC_AVCC_EXTERNAL_AT_AREF,
			.adjustification_select = ADC_RIGHT_JUSTIFY,
			.prescaler_select = ADC_PRESCALER_DIV_16};

	ADC_voidInit(&my_adc);
}

void LM35_Reading(u8 Copy_u8Channel, float *celsius)
{
	u16 adc_res = 0;

	ADC_cfg_t my_adc = {
			.select_trigger_source = ADC_SELECT_TRIGGER_FREE_SOURCE,
			.voltage_reference_select = ADC_AVCC_EXTERNAL_AT_AREF,
			.adjustification_select = ADC_RIGHT_JUSTIFY,
			.prescaler_select = ADC_PRESCALER_DIV_16};
	/* Tack readings of ADC */
	ADC_getDigitalValueSynchNonBlocking(&my_adc, Copy_u8Channel, &adc_res);

	/* Calibrate readings to be in celsius degree */
	*celsius = adc_res * 4.88;
	*celsius = (*celsius/10.00);
}
