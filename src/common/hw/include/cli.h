/*
 * cli.h
 *
 *  Created on: Jan 23, 2025
 *      Author: solini
 */

#ifndef COMMON_HW_INCLUDE_CLI_H_
#define COMMON_HW_INCLUDE_CLI_H_

#include "hw_def.h"


#ifdef _USE_HW_CLI


#define CLI_LINE_HIS_MAX        HW_CLI_LINE_HIS_MAX
#define CLI_LINE_BUF_MAX        HW_CLI_LINE_BUF_MAX

bool cliInit(void);
bool cliOpen(uint8_t ch, uint32_t baud);
bool cliOpenLog(uint8_t ch, uint32_t baud);
bool cliMain(void);


#endif


#endif /* COMMON_HW_INCLUDE_CLI_H_ */
