/*
 * button.c
 *
 *  Created on: Jan 15, 2025
 *      Author: solini
 */


#include "button.h"

bool buttonInit(void)
{

    bool ret = true;

    GPIO_InitTypeDef GPIO_InitStruct = {0};

	/*Configure GPIO pin : PA5 */

	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    return ret;
}

bool buttonGetPressed(uint8_t ch)
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET)
    {
        return true;
    }
    else
    {
        return false;
    }
}