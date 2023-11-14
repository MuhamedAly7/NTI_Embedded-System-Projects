/*
 * FingerPrint.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_FINGERPRINT_FINGERPRINT_H_
#define ECU_LAYER_FINGERPRINT_FINGERPRINT_H_

/* -------------------------------------------- Include -------------------------------- */
#include "FingerPrint_cfg.h"
#include "FingerPrint_Priv.h"
#include "../../MCAL_Layer/UART/UART.h"
#include <util/delay.h>

/* ------------------------------------------- Macros Objects -------------------------- */
#define SUCCESS  1
#define ERROR    0

/* ------------------------------------------- Macros Functions ------------------------ */


/* --------------------------------------------- APIs ----------------------------------- */
u8 FingerPS_handShake(void);
u8 FingerPS_genImg(void); // done
u8 FingerPS_convertImg2CharFile(u8 BufferId);
u8 FingerPS_genTemplate(void);
u8 FingerPS_strTemplate(u8 Page_ID);
u8 FingerPS_searchFinger(u16 *ret_pageid); /* 1:n must be done at  each enrollment to ensure that the template doesn't allocated */
u8 FingerPS_emptyLibrary(void);
u8 FingerPS_deleteFinger(void); // not frequently used on our case
u8 FingerPS_LoadCharFile(void); // not frequently used on our case
static u16  FingerPS_calcCheckSum(u8 *frame);
u8 FingerPS_match(void); /* Used for attendance mode */
u8 FingerPS_AuraNormal(void);
u8 FingerPS_AuraSuccess(void);
u8 FingerPS_AuraError(void);

/* Implementing enrollment procedure */
u8 FingerPS_Enrollment(u8 page_id, u16 *ret_id);
/* Implement attendance procedure */
u8 FingerPS_Attendance(u16 *ret_pageid);

#endif /* ECU_LAYER_FINGERPRINT_FINGERPRINT_H_ */
