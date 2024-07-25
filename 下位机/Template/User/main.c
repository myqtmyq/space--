#include "stm32f10x.h"
#include "Systick.h"
#include "Can.h"
#include "Canopen.h"

int main()
{
    SystemCLK_Config();
    BSP_CAN_Init();
    uint8_t data[8] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22};

    while (1)
    {
        CAN_SendMessage(0x123, data, 8);
    }
}
