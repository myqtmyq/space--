#define __HANDLE_GLOBALS
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "Systick.h"
#include "Can.h"
#include "Canopen.h"
#include "Pump.h"
#include "UART.h"
#include "Handle.h"

// �䷽
// ��λ ml
#define Conponent1 1
#define Conponent2 0
#define Conponent3 0

// 100 0.01rpm/51200 pulseһȦ
// 0.125ml/Ȧ
#define conv 433067

int main()
{
    SystemCLK_Config();
    protocolInit(&protocolData_t);
    usart2Init();
    usart3Init();
    usart3RX_DMA_Init();
    usart3TX_DMA_Init();
    while (1)
    {
        Pump_Enable(0x01);
        delay(50);
    }
}
