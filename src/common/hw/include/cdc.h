/*
 * cdc.h
 *
 *  Created on: Jan 18, 2025
 *      Author: solini
 */

#ifndef COMMON_HW_INCLUDE_CDC_H_
#define COMMON_HW_INCLUDE_CDC_H_

#include "hw_def.h"

#ifdef _USE_HW_CDC


bool cdcInit(void);
uint32_t cdcAvailable(void);
uint8_t cdcRead(void);
void cdcDataIn(uint8_t rx_data);
uint32_t cdcWrite(uint8_t *p_data, uint32_t length);
uint32_t cdcGetBaud(void);

#endif

#endif /* COMMON_HW_INCLUDE_CDC_H_ */
