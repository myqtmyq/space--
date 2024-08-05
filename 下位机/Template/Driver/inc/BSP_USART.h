#ifndef __BSP_USART_H
#define __BSP_USART_H
#include "stm32f10x.h"
#include "Driver_protocol.h"
#include "BSP_DMA.h"
#include "Handle.h"
void usart1Init();
void usart1Send(uint8_t *data, uint8_t id, uint8_t operation);
#endif