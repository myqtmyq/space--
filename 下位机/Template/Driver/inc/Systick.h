#ifndef _SYSTICK_H
#define _SYSTICK_H

#include "stm32f10x.h"
#include "core_cm3.h"

void SystemCLK_Config();
void delay(uint16_t ms);

#endif
