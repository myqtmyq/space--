#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "Systick.h"
#include "Can.h"
#include "Canopen.h"
#include "Pump.h"
#include "UART.h"
#include "handle.h"



int main()
{
    SystemCLK_Config();
    BSP_UART1_CFG(9600, 0);
    BSP_CAN_Init();
	protocolInit(protocolData_t);
    while (1)
    {
        Pump_Init(1);
    }
}
