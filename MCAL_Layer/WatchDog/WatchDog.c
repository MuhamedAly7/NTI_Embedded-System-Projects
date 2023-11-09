/*
 * WatchDog.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Mohamed Aly
 */


#include "WatchDog.h"


void WDT_Enable(void)
{
	WATCHDOG_CONTROL->WDE_BIT = 1;
}


void WDT_Disable(void)
{
	/* Write logic one to WDTOE and WDE  */
	WDTCR_REG |= (1 << WDTOE_POS) | (1 << WDE_POS);
	WDTCR_REG = 0x00;
}


void WDT_sleep(u8 sleepTime)
{
	WDT_Enable();
	WATCHDOG_CONTROL->WDP_BITS = sleepTime;
}

void WDT_refresh(void)
{
	asm volatile ("WDR");
}
