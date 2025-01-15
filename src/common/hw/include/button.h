/*
 * button.h
 *
 *  Created on: Jan 15, 2025
 *      Author: solini
 */

#ifndef COMMON_HW_INCLUDE_BUTTON_H_
#define COMMON_HW_INCLUDE_BUTTON_H_

#include "hw_def.h"

bool buttonInit(void);

bool buttonGetPressed(uint8_t ch);

#endif /* COMMON_HW_INCLUDE_BUTTON_H_ */
