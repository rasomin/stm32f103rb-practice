/*
 * bsp.h
 *
 *  Created on: Jan 12, 2025
 *      Author: solini
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#include "def.h"

#include "stm32f1xx_hal.h"


#define _UART_LOG_PRINT  1

#if _UART_LOG_PRINT
#define logPrintf(fmt, ...)     printf(fmt, ##__VA_ARGS__)
#else
#define logPrintf(fmt, ...)
#endif


void bspInit(void);

void delay(uint32_t ms);
uint32_t millis(void);

void Error_Handler(void);

#endif /* BSP_BSP_H_ */
