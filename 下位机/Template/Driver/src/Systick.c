#include "Systick.h"

void SystemCLK_Config()
{
    RCC_HSEConfig(RCC_HSE_ON);

    uint8_t HSEStartUpStatus = RCC_WaitForHSEStartUp();
    if (HSEStartUpStatus == SUCCESS)
    {

        RCC_HCLKConfig(RCC_SYSCLK_Div1); // AHB不分频
        RCC_PCLK2Config(RCC_HCLK_Div1);  // APB2不分频
        RCC_PCLK1Config(RCC_HCLK_Div2);  // APB1分频因子，最大36 MHz

        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9); // PLL: 8 MHz * 9 = 72 MHz

        RCC_PLLCmd(ENABLE);

        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
            ;

        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

        while (RCC_GetSYSCLKSource() != 0x08)
            ;
    }
    else
    {
        // HSE启动失败，处理错误
        while (1)
            ;
    }
}