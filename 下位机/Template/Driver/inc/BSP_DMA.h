#ifndef __BSP_DMA_H
#define __BSP_DMA_H
#include "stm32f10x.h"

void uart1DMA_ENABLE(uint8_t *data, uint8_t length);
void uart1DMA_DISABLE();
void uart1RX_DMA_DISABLE();
void uart1RX_DMA_ENABLE(uint8_t *data);
#endif