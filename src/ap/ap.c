/*
 * ap.c
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */


#include "ap.h"



void apInit(void)
{
	// uartOpen(_DEF_UART1, 115200); // CDC
	uartOpen(_DEF_UART2, 115200);

	cliOpen(_DEF_UART2, 115200);
	// cliOpenLog(_DEF_UART2, 115200);
}

void apMain(void)
{
	uint32_t pre_time;

	pre_time = millis();

	while (1)
	{
		if (millis() - pre_time >= 500)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);
		}

		// if (uartAvailable(_DEF_UART2) > 0)
		// {
		// uint8_t rx_data;
		// rx_data = uartRead(_DEF_UART2);

		// uartPrintf(_DEF_UART2, "Rx : 0x%X\n", rx_data);
		// }

		cliMain();
		
	}
}
