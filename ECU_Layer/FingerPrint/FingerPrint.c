/*
 * FingerPrint.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Mohamed Aly
 */

#include "FingerPrint.h"



u8 FingerPS_handShake(void)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 handshakeCommand[] = {0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x03, 0x40, 0x00, 0x44};
	u8 handshakeResponse[] = {0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x03, 0x00, 0x00, 0x0A};

	for(u8 i = 0; i < sizeof(handshakeCommand); i++)
	{
		ret_status = UART_SendByte(handshakeCommand[i]);
	}

	// Receive and verify the response
	for (u8 i = 0; i < sizeof(handshakeResponse); ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);

		if (rec_byte != handshakeResponse[i])
		{
			operation_status = ERROR;
			break;
		}

	}
	return operation_status;
}



u8 FingerPS_AuraNormal(void)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 AuraNormal[] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x07,0x35,0x01,0xF0,0x03,0x00,0x01,0x31}; // Purple
	u8 AuraNormalResponse[] = {0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x03, 0x00, 0x00, 0x0A};

	for(u8 i = 0; i < sizeof(AuraNormal); i++)
	{
		ret_status = UART_SendByte(AuraNormal[i]);
	}

	// Receive and verify the response
	for (u8 i = 0; i < sizeof(AuraNormalResponse); ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);

		if (rec_byte != AuraNormalResponse[i])
		{
			operation_status = ERROR;
			break;
		}

	}
	return operation_status;
}



u8 FingerPS_AuraSuccess(void)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 AuraSuccess[] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x07,0x35,0x01,0xF0,0x02,0x00,0x01,0x30}; // Blue
	u8 AuraSuccessResponse[] = {0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x03, 0x00, 0x00, 0x0A};

	for(u8 i = 0; i < sizeof(AuraSuccess); i++)
	{
		ret_status = UART_SendByte(AuraSuccess[i]);
	}

	// Receive and verify the response
	for (u8 i = 0; i < sizeof(AuraSuccessResponse); ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);

		if (rec_byte != AuraSuccessResponse[i])
		{
			operation_status = ERROR;
			break;
		}

	}
	return operation_status;
}



u8 FingerPS_AuraError(void)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 AuraError[] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x07,0x35,0x01,0xF0,0x01,0x00,0x01,0x2F}; // Red
	u8 AuraErrorResponse[] = {0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x03, 0x00, 0x00, 0x0A};

	for(u8 i = 0; i < sizeof(AuraError); i++)
	{
		ret_status = UART_SendByte(AuraError[i]);
	}

	// Receive and verify the response
	for (u8 i = 0; i < sizeof(AuraErrorResponse); ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);

		if (rec_byte != AuraErrorResponse[i])
		{
			operation_status = ERROR;
			break;
		}
	}
	return operation_status;
}



u8 FingerPS_genImg(void)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 num_of_success = 0;

	u8 GenImg_Command[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x01,0x00,0x05};
	u8 GenImg_Right_response[] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x03,0x00,0x00,0x0A};

	for(u8 i = 0; i < sizeof(GenImg_Command); i++)
	{
		ret_status = UART_SendByte(GenImg_Command[i]);
	}

	// Receive and verify the response
	for (u8 i = 0; i < sizeof(GenImg_Right_response); ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);

		if(rec_byte == GenImg_Right_response[i])
		{
			num_of_success++;
		}
	}
	if(num_of_success == sizeof(GenImg_Right_response))
	{
		operation_status = FingerPS_AuraSuccess();
		_delay_ms(200);
	}
	else
	{
		operation_status = FingerPS_AuraError();
		_delay_ms(200);
		operation_status = ERROR;
	}
	operation_status &= FingerPS_AuraNormal();
	return operation_status;
}



u8 FingerPS_convertImg2CharFile(u8 BufferId)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 num_of_success = 0;

	u8 Img2Tz_1 []={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x02,BufferId,0x00,0x08};
	u8 Img2Tz_2 []={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x04,0x02,BufferId,0x00,0x09};
	u8 Img2Tz_Right_response[] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x03,0x00,0x00,0x0A};

	switch(BufferId)
	{
	case 0x01: // case if buffer id == 1
		for(u8 i = 0; i < sizeof(Img2Tz_1); i++)
		{
			ret_status = UART_SendByte(Img2Tz_1[i]);
		}

		// Receive and verify the response
		for (u8 i = 0; i < sizeof(Img2Tz_Right_response); ++i)
		{
			ret_status = UART_ReceiveByte(&rec_byte);

			if(rec_byte == Img2Tz_Right_response[i])
			{
				num_of_success++;
			}
		}
		if(num_of_success == sizeof(Img2Tz_Right_response))
		{
			operation_status = FingerPS_AuraSuccess();
			_delay_ms(200);
		}
		else
		{
			operation_status = FingerPS_AuraError();
			_delay_ms(200);
			operation_status = ERROR;
		}
		operation_status &= FingerPS_AuraNormal();
		break;
	case 0x02: // case if buffer id == 2
		for(u8 i = 0; i < sizeof(Img2Tz_2); i++)
		{
			ret_status = UART_SendByte(Img2Tz_2[i]);
		}

		// Receive and verify the response
		for (u8 i = 0; i < sizeof(Img2Tz_Right_response); ++i)
		{
			ret_status = UART_ReceiveByte(&rec_byte);

			if(rec_byte == Img2Tz_Right_response[i])
			{
				num_of_success++;
			}
		}
		if(num_of_success == sizeof(Img2Tz_Right_response))
		{
			operation_status = FingerPS_AuraSuccess();
			_delay_ms(200);
		}
		else
		{
			operation_status = FingerPS_AuraError();
			_delay_ms(200);
			operation_status = ERROR;
		}
		operation_status &= FingerPS_AuraNormal();
		break;
	}
	return operation_status;
}



u8 FingerPS_genTemplate(void)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 num_of_success = 0;

	u8 RegModel[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x03,0x05,0x00,0x09};
	u8 RegModel_Right_response[] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x03,0x00,0x00,0x0A};

	// send frame
	for(u8 i = 0; i < sizeof(RegModel); i++)
	{
		ret_status = UART_SendByte(RegModel[i]);
	}

	// Receive and verify the response
	for (u8 i = 0; i < sizeof(RegModel_Right_response); ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);

		if(rec_byte == RegModel_Right_response[i])
		{
			num_of_success++;
		}
	}

	if(num_of_success == sizeof(RegModel_Right_response))
	{
		operation_status = FingerPS_AuraSuccess();
		_delay_ms(200);
	}
	else
	{
		operation_status = FingerPS_AuraError();
		_delay_ms(200);
		operation_status = ERROR;
	}
	operation_status &= FingerPS_AuraNormal();
	return operation_status;
}




u8 FingerPS_strTemplate(u8 Page_ID)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 num_of_success = 0;

	u8 Store[]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x06,0x06,0x01,0x00,Page_ID,0x00,0x0E + Page_ID};
	u8 Store_response[] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x03,0x00,0x00,0x0A};

	// send frame
	for(u8 i = 0; i < sizeof(Store); i++)
	{
		ret_status = UART_SendByte(Store[i]);
	}

	// Receive and verify the response
	for (u8 i = 0; i < sizeof(Store_response); ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);

		if(rec_byte == Store_response[i])
		{
			num_of_success++;
		}
	}
	if(num_of_success == sizeof(Store_response))
	{
		operation_status = FingerPS_AuraSuccess();
		_delay_ms(200);
	}
	else
	{
		operation_status = FingerPS_AuraError();
		_delay_ms(200);
		operation_status = ERROR;
	}
	operation_status &= FingerPS_AuraNormal();
	return operation_status;
}



u8 FingerPS_searchFinger(u16 *ret_pageid)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 operation_status = SUCCESS;
	u8 rec_byte = 0;
	u8 num_of_success = 0;

	u8 Search_Command[]={0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x08, 0x04, 0x01, 0x00, 0x01 ,0x00 ,0x01 ,0x00, 0x10};
	u8 Search_response[16]; // to receive response search response frame

	// send frame
	for(u8 i = 0; i < sizeof(Search_Command); i++)
	{
		ret_status = UART_SendByte(Search_Command[i]);
	}


	// Receive and verify the response
	for (u8 i = 0; i < 16; ++i)
	{
		ret_status = UART_ReceiveByte(&rec_byte);
		Search_response[i] = rec_byte;
	}
	/*here we only check the confirmation code because check sum and PID is not fixed on response 9 here is the position of confirmation code */
	if(Search_response[9] == 0x00)
	{
		operation_status = FingerPS_AuraSuccess();
		*ret_pageid = (Search_response[10] << 8) + Search_response[11];
		_delay_ms(200);
	}
	else
	{
		operation_status = FingerPS_AuraError();
		_delay_ms(200);
		operation_status = ERROR;
	}
	operation_status &= FingerPS_AuraNormal();
	return operation_status;
}


u8 FingerPS_Enrollment(u8 page_id, u16 *ret_id)
{
	u8 fp_status = SUCCESS;
	u16 searched_ID = 0;

	/* Search */
	fp_status &= FingerPS_genImg();
	_delay_ms(5);
	fp_status &= FingerPS_convertImg2CharFile(0x01);
	_delay_ms(5);
	fp_status &= FingerPS_genImg();
	_delay_ms(5);
	fp_status &= FingerPS_convertImg2CharFile(0x02);
	_delay_ms(5);
	fp_status &= FingerPS_genTemplate();
	_delay_ms(5);
	fp_status &= FingerPS_searchFinger(ret_id);

	if(fp_status == ERROR) // image not found before so i can start enrollment stage here
	{
		/* Enrollment */
		fp_status &= FingerPS_genImg();
		_delay_ms(5);
		fp_status &= FingerPS_convertImg2CharFile(0x01);
		_delay_ms(5);
		fp_status &= FingerPS_genImg();
		_delay_ms(5);
		fp_status &= FingerPS_convertImg2CharFile(0x02);
		_delay_ms(5);
		fp_status &= FingerPS_genTemplate();
		_delay_ms(5);
		fp_status &= FingerPS_strTemplate(page_id);
		*ret_id = NULL;
	}
	else // this case mean the image existed before and we can not enroll same finger in other location
	{
		fp_status = 0; // that mean image already existed
	}


	return fp_status;
}


void FingerPS_Attendance(u16 *ret_pageid)
{
	u8 fp_status = SUCCESS;

	/* attendance */
	fp_status = FingerPS_genImg();
	_delay_ms(5);
	fp_status = FingerPS_convertImg2CharFile(0x01);
	_delay_ms(5);
	fp_status = FingerPS_genImg();
	_delay_ms(5);
	fp_status = FingerPS_convertImg2CharFile(0x02);
	_delay_ms(5);
	fp_status = FingerPS_genTemplate();
	_delay_ms(5);
	fp_status = FingerPS_searchFinger(ret_pageid);
}

