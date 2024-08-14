#define __HANDLE_GLOBALS
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "Systick.h"
#include "Can.h"
#include "Canopen.h"
#include "Pump.h"
#include "UART.h"
#include "Handle.h"

int main()
{
    SystemCLK_Config();
    usart1Init();
    protocolInit(&protocolData_t);
    delay(2000);
    Pump_Init(0x01);
    delay(1000);
    Pump_Init(0x02);
    delay(1000);
    Pump_Init(0x03);
    delay(2000);
    while (1)
    {
        Pump_Start(0x01);
        delay(2000);
        Pump_Start(0x02);
        delay(2000);
        Pump_Start(0x03);
        delay(30000);
        Pump_Stop(0x01);
        delay(2000);
        Pump_Stop(0x02);
        delay(2000);
        Pump_Stop(0x03);
        delay(10000);
    }
}
