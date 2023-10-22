/*
 * GPIO.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "GPIO.h"

volatile Peripheral_t *Ports_index[NUM_PORTS] = {GPIO_PINS_A, GPIO_PINS_B, GPIO_PINS_C, GPIO_PINS_D};


PROGRAM_STATUS_T DIO_SetPinDirection(const GPIO_CFG_T *obj)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    if(NULL == obj)
    {
        ret_status = NULL_PTR;
    }
    else
    {
    	if(obj->direction == GPIO_DIRECTION_OUTPUT)
    	{
    		SET_BIT(Ports_index[obj->port]->DDRx, obj->pin);
    	}
    	else if(obj->direction == GPIO_DIRECTION_INPUT)
    	{
    		CLEAR_BIT(Ports_index[obj->port]->DDRx, obj->pin);
    	}
    	else{/* Nothing */}
    }
    return ret_status;
}
PROGRAM_STATUS_T DIO_SetPinValue(const GPIO_CFG_T *obj, Logic_t logic)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    if(NULL == obj)
    {
        ret_status = NULL_PTR;
    }
    else
    {
    	if(logic == GPIO_HIGH)
    	{
    		SET_BIT(Ports_index[obj->port]->PORTx, obj->pin);
    	}
    	else if(logic == GPIO_LOW)
    	{
    		CLEAR_BIT(Ports_index[obj->port]->PORTx, obj->pin);
    	}
    	else{/* Nothing */}
    }
    return ret_status;
}
PROGRAM_STATUS_T DIO_GetPinValue(const GPIO_CFG_T *obj, u8 *pin_value)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    if((NULL == obj) || (NULL == pin_value))
    {
        ret_status = NULL_PTR;
    }
    else
    {
    	*pin_value = READ_BIT(Ports_index[obj->port]->PINx, obj->pin);
    }
    return ret_status;
}


PROGRAM_STATUS_T DIO_SetPortDirection(Port_index_t port_index, u8 directions)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    Ports_index[port_index]->DDRx = directions;
    return ret_status;
}


PROGRAM_STATUS_T DIO_SetPortValues(Port_index_t port_index, u8 values)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    Ports_index[port_index]->PORTx = values;
    return ret_status;
}


PROGRAM_STATUS_T DIO_GetPortValues(Port_index_t port_index, u8 *port_value)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    if(NULL == port_value)
    {
        ret_status = NULL_PTR;
    }
    else
    {
        *port_value = Ports_index[port_index]->PINx;
    }

    return ret_status;
}
