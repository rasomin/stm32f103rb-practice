/*
 * main.c
 *
 *  Created on: Jan 9, 2025
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
