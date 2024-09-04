#ifndef __BSP_DMA_H
#define __BSP_DMA_H
#include "stm32f10x.h"

void uart1DMA_ENABLE(uint8_t *data, uint8_t length);
void uart1DMA_DISABLE();
void uart1RX_DMA_DISABLE();
void uart1RX_DMA_ENABLE(uint8_t *data);
void spi1TX_DMA_Init();
void spi1RX_DMA_Init();
void spi1TX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length);
void spi1RX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length);
void spi1_DMA_DISABLE();
void usart3TX_DMA_Init();
void usart3RX_DMA_Init();
void usart3TX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length);
void usart3RX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length);
void usart3_DMA_DISABLE();

#endif