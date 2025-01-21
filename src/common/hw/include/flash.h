/*
 * flash.h
 *
 *  Created on: Jan 21, 2025
 *      Author: solini
 */

#ifndef COMMON_HW_INCLUDE_FLASH_H_
#define COMMON_HW_INCLUDE_FLASH_H_

#include "hw_def.h"

#ifdef _USE_HW_FLASH

bool flashInit(void);
bool flashErase(uint32_t addr, uint32_t length);
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t length);

#endif

#endif /* COMMON_HW_INCLUDE_FLASH_H_ */
