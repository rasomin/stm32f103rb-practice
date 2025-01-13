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
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

	/*Configure GPIO pin : PA5 */
	GPIO_InitStruct.Pin = GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void apMain(void)
{
	while (1)
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		delay(1500);

		CDC_Transmit_FS("test\n", 6);
	}
}
