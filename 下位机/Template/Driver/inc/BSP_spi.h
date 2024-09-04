#ifndef __BSP_SPI_H
#define __BSP_SPI_H
#include "stm32f10x.h"
#include "BSP_DMA.h"

void BSP_spi_Init();
void spi1_send(uint8_t *bufferTX, uint16_t lengthTX, uint8_t receiveEnable, uint8_t *bufferRX, uint16_t lengthRX);

#endif