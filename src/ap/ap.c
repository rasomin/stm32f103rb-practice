/*
 * ap.c
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */


#include "ap.h"


extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);

void apInit(void)
{

}

void apMain(void)
{
	while (1)
	{
		ledToggle(_DEF_LED1);
		delay(500);

		CDC_Transmit_FS("test\n", 6);
	}
}
