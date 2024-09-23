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
    testAngle = 1500;
    SystemCLK_Config();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    protocolInit(&protocolData_t);
    usart2Init();
    usart3Init();
    usart3RX_DMA_Init();
    usart3TX_DMA_Init();
    usart3RX_DMA_ENABLE(USART3_RX_Buffer, &(USART3->DR), 32);
    // Key_EXTI_Init();
    Pump_Enable(0x01);
    delay(100);
    Pump_Init(0x01);
    delay(100);
    int last_k2;
    int last_k1;
    while (1)
    {
        if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6))
        {
            delay(50);
            if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) && last_k2)
            {
                Pump_pStart(0x01, testAngle);
                testAngle += 1500;
                last_k2 = 0;
            }
        }
        else
        {
            last_k2 = 1;
        }
        delay(50);

        if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0))
        {
            delay(50);
            if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) && last_k1)
            {
                testAngle = 1500;
                last_k1 = 0;
            }
        }
        else
        {
            last_k1 = 1;
        }
    }
}
