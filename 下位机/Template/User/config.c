#include "My_Init.h"

void stm32f103_config() {
    BSP_GPIO_Init();
    SysTick_Init();
    UART_Config();
    ADC_Configuration();
    TIM_Init();
}

void SysTick_Init() {
    if (SysTick_EN == 1) SysTick_Init();
}

void BSP_GPIO_Init() {
    BSP_GPIOA_Config();
    BSP_GPIOB_Config();
    BSP_GPIOC_Config();
    BSP_GPIOD_Config();
}

void UART_Config() {
    // UART1 Config
    if (UART1_ENABLE) USART1_Configuration(UART1_BoundRate, UART1_ITFLAG);
    // UART2 Config
    if (UART2_ENABLE) USART2_Configuration(UART2_BoundRate, UART2_ITFLAG);
}

void ADC_Configuration() {
    if (ADC1_EN) ADC1_Configuration();
    if (ADC2_EN) ADC2_Configuration();
    if (ADC3_EN) ADC3_Configuration();
}
void TIM_Init() {
    if (TIM1_EN) TIM1_Config(TIM1_Period, TIM1_IT);
    if (TIM2_EN) TIM2_Config(TIM2_Period, TIM2_IT);
    if (TIM3_EN) TIM3_Config(TIM3_Period, TIM3_IT);
}
