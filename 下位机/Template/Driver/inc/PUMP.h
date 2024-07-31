#ifndef __PUMP_H__
#define __PUMP_H__

#include "stm32f10x.h"
#include "Can.h"
#include "Canopen.h"
#include "UART.h"
#include "protocol.h"
#include "Systick.h"

typedef enum
{
    PUMP_STOP = 0,
    PUMP_SPEED,
    PUMP_ORI,
    PUMP_TIME
} PumpStateTypeDef;

void Pump_Init(int id);
void Pump_Start(int id);
void Pump_Stop(int id);

#endif