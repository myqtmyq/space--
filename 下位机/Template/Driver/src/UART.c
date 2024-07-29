#include "UART.h"

void BSP_UART1_CFG(uint16_t baudRate,int interruptFlag){
    // 配置 USART1 的引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9; // USART_TX
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10; // USART_RX
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置 USART1 参数
    USART_InitTypeDef USART_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); // 使能时钟

    USART_InitStructure.USART_BaudRate            = baudRate;
    USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits            = USART_StopBits_1;
    USART_InitStructure.USART_Parity              = 2;
    USART_InitStructure.USART_Mode                = USART_Mode_Tx | USART_Mode_Rx;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART1, &USART_InitStructure);

    // 使能 USART1
    USART_Cmd(USART1, ENABLE); // 使能串口
    // NVIC
    if (interruptFlag != 0) {
        NVIC_InitTypeDef NVIC_InitStructure;
        NVIC_InitStructure.NVIC_IRQChannel                   = USART1_IRQn; // 串口中断通道
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;    // 抢占优先级
        NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;           // 子优先级
        NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;      // IRQ通道使能
        NVIC_Init(&NVIC_InitStructure);                                     // 根据指定的参数初始化VIC寄存器
        USART_ITConfig(USART1, interruptFlag, ENABLE);                      // 开启相关中断
    }
}

int fputc(int ch, FILE *p) {

    USART_SendData(USART1, (u8) ch);

    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
        ;

    return ch;
}

