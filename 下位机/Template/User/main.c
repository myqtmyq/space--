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
    // Pump_Init(0x01);

    while (1)
    {
        Pump_Start(0x01);
        delay(50);
    }

    while (1)
    {
        /* code */
    }
}
