#ifndef _UART_H
#define _UART_H

#include "stm32f10x.h"

void BSP_UART1_CFG(uint16_t baudRate,int interruptFlag);
int fputc(int ch, FILE *p);

#endif