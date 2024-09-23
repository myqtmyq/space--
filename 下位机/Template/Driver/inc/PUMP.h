#ifndef __PUMP_H__
#define __PUMP_H__

#include "stm32f10x.h"
#include "Can.h"
#include "Canopen.h"
#include "UART.h"
#include "protocol.h"
#include "Systick.h"
#include "BSP_USART.h"

typedef enum
{
    PUMP_STOP = 0,
    PUMP_SPEED,
    PUMP_ORI,
    PUMP_TIME
} PumpStateTypeDef;

void Pump_Init(int id);
void Pump_Enable(int id);
void Pump_pStart(int id, int pTarget);
void Pump_setId(int id);
void Key_EXTI_Init();
#endif