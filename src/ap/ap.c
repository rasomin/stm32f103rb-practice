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

	pre_time = millis();

	while (1)
	{
		if (millis() - pre_time >= 500)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);
		}

		if (uartAvailable(_DEF_UART2) > 0)
		{
			uint8_t rx_data;

			rx_data = uartRead(_DEF_UART2);

			if (rx_data == '1')
			{
				uint8_t buf[32];

				logPrintf("Read...\n");

				flashRead(0x8000000 + (100*1024), buf, 32);

				for (int i = 0; i < 32; i++)
				{
					logPrintf("0x%X : 0x%X\n", 0x8000000 + (100*1024)+i, buf[i]);
				}
			}

			if (rx_data == '2')
			{
				logPrintf("Erase...\n");

				if (flashErase(0x8000000 + (100*1024), 32) == true)
				{
					logPrintf("Erase OK\n");
				}
				else
				{
					logPrintf("Erase Fail\n");
				}
			}

			if (rx_data == '3')
			{
				uint8_t buf[32];

				for (int i = 0; i < 32; i++)
				{
					buf[i] = i;
				}

				logPrintf("Write...\n");

				if (flashWrite(0x8000000 + (100*1024), buf, 32) == true)
				{
					logPrintf("Write OK\n");
				}
				else
				{
					logPrintf("Write Fail\n");
				}
			}
		}
	}
}
