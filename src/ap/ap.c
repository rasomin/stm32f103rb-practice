/*
 * ap.c
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */


#include "ap.h"


extern uint32_t cdcAvailable(void);
extern uint8_t cdcRead(void);
extern void cdcDataIn(uint8_t rx_data);
extern uint32_t cdcWrite(uint8_t *p_data, uint32_t length);

void apInit(void)
{

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

		if (cdcAvailable() > 0)
		{
			uint8_t rx_data;

			rx_data = cdcRead();
			cdcWrite((uint8_t *)"RxData : ", 10);
			cdcWrite(&rx_data, 1);
			cdcWrite((uint8_t *)"\n", 2);
		}
	}
}
