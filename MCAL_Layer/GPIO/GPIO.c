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
        switch (obj->pin) {
            case PIN0_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_0 = obj->direction;
            break;
            case PIN1_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_1 = obj->direction;
            break;
            case PIN2_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_2 = obj->direction;
            break;
            case PIN3_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_3 = obj->direction;
            break;
            case PIN4_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_4 = obj->direction;
            break;
            case PIN5_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_5 = obj->direction;
            break;
            case PIN6_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_6 = obj->direction;
            break;
            case PIN7_INDEX:
                Ports_index[obj->port]->DDRx.Port_reg_bits.PIN_7 = obj->direction;
            break;
            default:

            break;
        }
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
        switch (obj->pin) {
            case PIN0_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_0 = logic;
            break;
            case PIN1_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_1 = logic;
            break;
            case PIN2_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_2 = logic;
            break;
            case PIN3_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_3 = logic;
            break;
            case PIN4_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_4 = logic;
            break;
            case PIN5_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_5 = logic;
            break;
            case PIN6_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_6 = logic;
            break;
            case PIN7_INDEX:
                Ports_index[obj->port]->PORTx.Port_reg_bits.PIN_7 = logic;
            break;
            default:

            break;
        }
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
        switch ((u8)obj->pin) {
            case PIN0_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_0;
            break;
            case PIN1_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_1;
            break;
            case PIN2_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_2;
            break;
            case PIN3_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_3;
            break;
            case PIN4_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_4;
            break;
            case PIN5_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_5;
            break;
            case PIN6_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_6;
            break;
            case PIN7_INDEX:
                *pin_value = Ports_index[obj->port]->PINx.Port_reg_bits.PIN_7;
            break;
            default:

            break;
        }
    }
    return ret_status;
}


PROGRAM_STATUS_T DIO_SetPortDirection(Port_index_t port_index, u8 directions)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    Ports_index[port_index]->DDRx.Port_reg = directions;
    return ret_status;
}


PROGRAM_STATUS_T DIO_SetPortValues(Port_index_t port_index, u8 values)
{
    PROGRAM_STATUS_T ret_status = SUCCESS;
    Ports_index[port_index]->PORTx.Port_reg = values;
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
        *port_value = Ports_index[port_index]->PINx.Port_reg;
    }

    return ret_status;
}
