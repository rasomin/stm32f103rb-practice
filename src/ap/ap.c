/*
 * ap.c
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */


#include "ap.h"


void apInit(void)
{

}

void apMain(void)
{
	while (1)
	{
		ledToggle(_DEF_LED1);
		delay(1500);
	}
}
