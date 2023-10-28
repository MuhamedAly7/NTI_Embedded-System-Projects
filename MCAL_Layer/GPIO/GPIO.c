/*
 * GPIO.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "GPIO.h"

volatile DIO_t *Ports_index[NUM_PORTS] = {GPIO_PINS_A, GPIO_PINS_B, GPIO_PINS_C, GPIO_PINS_D};


void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId,  u8 Copy_u8Direction)
{
	if((Copy_u8PortId <= NUM_PORTS-1) && Copy_u8PinId <= NUM_PINS-1)
	{
		switch(Copy_u8Direction){
			case(GPIO_DIRECTION_OUTPUT):
				SET_BIT(Ports_index[Copy_u8PortId]->DDRx, Copy_u8PinId);
			break;
			case(GPIO_DIRECTION_INPUT):
				CLEAR_BIT(Ports_index[Copy_u8PortId]->DDRx, Copy_u8PinId);
			break;
		}
	}
	else{/* Nothing */}
}


void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	if((Copy_u8PortId <= NUM_PORTS-1) && (Copy_u8PinId <= NUM_PINS-1))
	{
		switch(Copy_u8Value){
		case(GPIO_HIGH):
		SET_BIT(Ports_index[Copy_u8PortId]->PORTx, Copy_u8PinId);
		break;
		case(GPIO_LOW):
		CLEAR_BIT(Ports_index[Copy_u8PortId]->PORTx, Copy_u8PinId);
		break;
		}
	}
	else{/* Nothing */}
}


u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 ret_val = 0;
	if((Copy_u8PortId <= NUM_PORTS-1) && (Copy_u8PinId <= NUM_PINS-1)){
		ret_val = READ_BIT(Ports_index[Copy_u8PortId]->PINx, Copy_u8PinId);
	}else{/* Nothing */}
	return ret_val;
}


void DIO_voidSetPortDirection(u8 Copy_u8PortId,  u8 Copy_u8Direction)
{
	if(Copy_u8PortId <= NUM_PORTS-1){
		Ports_index[Copy_u8PortId]->DDRx = Copy_u8Direction;
	}
	else{/* Nothing */}
}


void DIO_voidSetPortValues(u8 Copy_u8PortId, u8 Copy_u8Value)
{
	if(Copy_u8PortId <= NUM_PORTS-1){
    Ports_index[Copy_u8PortId]->PORTx = Copy_u8Value;
	}
	else{/* Nothing */}
}


u8 DIO_u8GetPortValues(u8 Copy_u8PortId)
{
	u8 ret_val = 0;
	if(Copy_u8PortId <= NUM_PORTS-1){
		ret_val = (Ports_index[Copy_u8PortId]->PINx);
	}else{/* Nothing */}
	return ret_val;
}
