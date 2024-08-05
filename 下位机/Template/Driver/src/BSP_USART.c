#include "BSP_USART.h"

void usart1Init()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

  GPIO_InitTypeDef GPIO_InitTypeDef_t;
  GPIO_DeInit(GPIOB);
  GPIO_InitTypeDef_t.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitTypeDef_t.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitTypeDef_t.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOB, &GPIO_InitTypeDef_t);

  GPIO_InitTypeDef_t.GPIO_Pin = GPIO_Pin_7;
  GPIO_InitTypeDef_t.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitTypeDef_t);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  USART_InitTypeDef USART_InitTypeDef_t;
  USART_InitTypeDef_t.USART_BaudRate = 115200;
  USART_InitTypeDef_t.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitTypeDef_t.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitTypeDef_t.USART_Parity = USART_Parity_No;
  USART_InitTypeDef_t.USART_StopBits = USART_StopBits_1;
  USART_InitTypeDef_t.USART_WordLength = USART_WordLength_8b;
  USART_Init(USART1, &USART_InitTypeDef_t);

  USART_Cmd(USART1, ENABLE);
}

void usart1Send(uint8_t *data, uint8_t id, uint8_t operation)
{
  uart1DMA_DISABLE();
  uint8_t length = getlength(operation);
  uint8_t buffer[length];
  protocolPack(buffer, data, id, operation);
  uart1DMA_ENABLE(
      buffer,
      length);
  while (!DMA_GetFlagStatus(DMA1_FLAG_TC4))
  {
    /* code */
  }
}