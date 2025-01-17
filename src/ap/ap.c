/*
 * ap.c
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */


#include "ap.h"



void apInit(void)
{
	uartOpen(_DEF_UART1, 115200);
}

void apMain(void)
{
	uint32_t pre_time;
	uint32_t pre_baud;

	pre_baud = uartGetBaud(_DEF_UART1);
	pre_time = millis();

	while (1)
	{
		if (millis() - pre_time >= 500)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);
		}

		if (uartAvailable(_DEF_UART1) > 0)
		{
			uint8_t rx_data;

			rx_data = uartRead(_DEF_UART1);
			
			uartPrintf(_DEF_UART1, "Rx_data : %c 0x%X\n", rx_data, rx_data);
		}

		if (uartGetBaud(_DEF_UART1) != pre_baud)
		{
			pre_baud = uartGetBaud(_DEF_UART1);
			uartPrintf(_DEF_UART1, "ChangedBaud : %d\n", uartGetBaud(_DEF_UART1));
		}
	}
}
