#ifndef __PUMP_H__
#define __PUMP_H__

#include "stm32f10x.h"
#include "Can.h"
#include "UART.h"

typedef enum{
    PUMP_STOP = 0,
    PUMP_SPEED,
    PUMP_ORI,
    PUMP_TIME
}PumpStateTypeDef;

typedef struct{
    int speed;
    int 

}PumpTypeDef;

#endif