#ifndef __CAN_H
#define __CAN_H

#include "stm32f10x.h"
#include "config.h"


void BSP_CAN_Init(void);
uint8_t CAN_SendMessage(uint32_t id, uint8_t* data, uint8_t length);
void USB_HP_CAN1_TX_IRQnHandler(void);
#endif
