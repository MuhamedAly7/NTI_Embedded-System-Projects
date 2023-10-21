/*
 * seven_segment.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */
#include "seven_segment.h"

PROGRAM_STATUS_T seven_segment_initailize(const seven_segment_t *_segment)
{
	PROGRAM_STATUS_T ret_status = SUCCESS;
	if(NULL == _segment)
	{
		ret_status = NULL_PTR;
	}
	else
	{
		ret_status = DIO_SetPinDirection(&(_segment->segment_pins[0]));
		ret_status = DIO_SetPinDirection(&(_segment->segment_pins[1]));
		ret_status = DIO_SetPinDirection(&(_segment->segment_pins[2]));
		ret_status = DIO_SetPinDirection(&(_segment->segment_pins[3]));


	}
	return ret_status;
}
PROGRAM_STATUS_T seven_segment_write_number(const seven_segment_t *_segment, u8 number)
{
	PROGRAM_STATUS_T ret_status = SUCCESS;
		if((NULL == _segment) || (number > 9))
		{
			ret_status = NULL_PTR;
		}
		else
		{
			ret_status = DIO_SetPinValue(&(_segment->segment_pins[0]), ((number >> 0) & 0x01));
			ret_status = DIO_SetPinValue(&(_segment->segment_pins[1]), ((number >> 1) & 0x01));
			ret_status = DIO_SetPinValue(&(_segment->segment_pins[2]), ((number >> 2) & 0x01));
			ret_status = DIO_SetPinValue(&(_segment->segment_pins[3]), ((number >> 3) & 0x01));
		}
		return ret_status;
}


