/*
 * ap.c
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */


#include "ap.h"



void apInit(void)
{
	uartOpen(_DEF_UART1, 115200); // CDC
	uartOpen(_DEF_UART2, 115200);
}

void apMain(void)
{
	uint32_t pre_time;
	uint8_t rx_buf[128];
	uint32_t rx_len;

	pre_time = millis();

	while (1)
	{
		if (millis() - pre_time >= 500)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);
		}

		if (uartGetBaud(_DEF_UART1) != uartGetBaud(_DEF_UART2))
		{
			uartOpen(_DEF_UART2, uartGetBaud(_DEF_UART1));
		}

		// USB CDC -> UART
		rx_len = uartAvailable(_DEF_UART1);
		if (rx_len > 128)
		{
			rx_len = 128;
		}
		if (rx_len > 0)
		{
			for (int i = 0; i < rx_len; i++)
			{
				rx_buf[i] = uartRead(_DEF_UART1);
			}
			uartWrite(_DEF_UART2, rx_buf, rx_len);
		}

		// UART -> USB CDC
		rx_len = uartAvailable(_DEF_UART2);
		if (rx_len > 128)
		{
			rx_len = 128;
		}
		if (rx_len > 0)
		{
			for (int i = 0; i < rx_len; i++)
			{
				rx_buf[i] = uartRead(_DEF_UART2);
			}
			uartWrite(_DEF_UART1, rx_buf, rx_len);
		}
	}
}
