/*
 * main.c
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */


#include "main.h"


int main(void)
{
	hwInit();
	apInit();

	apMain();

	return 0;
}
