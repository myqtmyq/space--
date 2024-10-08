#include "BSP_DMA.h"

void uart1DMA_ENABLE(uint8_t *data, uint8_t length)
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  DMA_DeInit(DMA1_Channel4);
  DMA_InitTypeDef DMA_InitTypeDef_t;
  DMA_InitTypeDef_t.DMA_BufferSize = length;
  DMA_InitTypeDef_t.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitTypeDef_t.DMA_M2M = DMA_M2M_Disable;
  DMA_InitTypeDef_t.DMA_MemoryBaseAddr = data;
  DMA_InitTypeDef_t.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitTypeDef_t.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitTypeDef_t.DMA_Mode = DMA_Mode_Normal;
  DMA_InitTypeDef_t.DMA_PeripheralBaseAddr = &(USART1->DR);
  DMA_InitTypeDef_t.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitTypeDef_t.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitTypeDef_t.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel4, &DMA_InitTypeDef_t);
  USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);

  DMA_Cmd(DMA1_Channel4, ENABLE);
}

void uart1DMA_DISABLE()
{
  DMA_Cmd(DMA1_Channel4, DISABLE);
}

void uart1RX_DMA_ENABLE(uint8_t *data)
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  DMA_DeInit(DMA1_Channel5);
  DMA_InitTypeDef DMA_InitTypeDef_t;
  DMA_InitTypeDef_t.DMA_BufferSize = 32;
  DMA_InitTypeDef_t.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitTypeDef_t.DMA_M2M = DMA_M2M_Disable;
  DMA_InitTypeDef_t.DMA_MemoryBaseAddr = data;
  DMA_InitTypeDef_t.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitTypeDef_t.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitTypeDef_t.DMA_Mode = DMA_Mode_Normal;
  DMA_InitTypeDef_t.DMA_PeripheralBaseAddr = &(USART1->DR);
  DMA_InitTypeDef_t.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitTypeDef_t.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitTypeDef_t.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel4, &DMA_InitTypeDef_t);
  USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);

  DMA_Cmd(DMA1_Channel5, ENABLE);
}

void uart1RX_DMA_DISABLE()
{
  DMA_Cmd(DMA1_Channel5, DISABLE);
}

void spi1TX_DMA_Init()
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  DMA_InitTypeDef DMA_InitTypeDef_t;
  DMA_InitTypeDef_t.DMA_M2M = DMA_M2M_Disable;
  DMA_InitTypeDef_t.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitTypeDef_t.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitTypeDef_t.DMA_Mode = DMA_Mode_Normal;
  DMA_InitTypeDef_t.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitTypeDef_t.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitTypeDef_t.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel3, &DMA_InitTypeDef_t);
  SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Tx, ENABLE);
}

void spi1TX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length)
{
  DMA1_Channel3->CNDTR = length;
  DMA1_Channel3->CMAR = data;
  DMA1_Channel3->CPAR = perAddr;
  DMA1_Channel3->CCR |= DMA_DIR_PeripheralDST;
  DMA_Cmd(DMA1_Channel3, ENABLE);
}

void spi1RX_DMA_Init()
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  DMA_InitTypeDef DMA_InitTypeDef_t;
  DMA_InitTypeDef_t.DMA_M2M = DMA_M2M_Disable;
  DMA_InitTypeDef_t.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitTypeDef_t.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitTypeDef_t.DMA_Mode = DMA_Mode_Normal;
  DMA_InitTypeDef_t.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitTypeDef_t.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitTypeDef_t.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel2, &DMA_InitTypeDef_t);
  SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Rx, ENABLE);
}

void spi1RX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length)
{
  DMA1_Channel2->CNDTR = length;
  DMA1_Channel2->CMAR = data;
  DMA1_Channel2->CPAR = perAddr;
  DMA1_Channel2->CCR |= DMA_DIR_PeripheralSRC;
  DMA_Cmd(DMA1_Channel2, ENABLE);
}

void spi1_DMA_DISABLE()
{
  DMA_Cmd(DMA1_Channel2, DISABLE);
}

void usart3TX_DMA_Init()
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  DMA_InitTypeDef DMA_InitTypeDef_t;
  DMA_InitTypeDef_t.DMA_M2M = DMA_M2M_Disable;
  DMA_InitTypeDef_t.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitTypeDef_t.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitTypeDef_t.DMA_Mode = DMA_Mode_Normal;
  DMA_InitTypeDef_t.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitTypeDef_t.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitTypeDef_t.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel2, &DMA_InitTypeDef_t);
  USART_DMACmd(USART3, USART_DMAReq_Tx, ENABLE);
}

void usart3RX_DMA_Init()
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
  DMA_InitTypeDef DMA_InitTypeDef_t;
  DMA_InitTypeDef_t.DMA_M2M = DMA_M2M_Disable;
  DMA_InitTypeDef_t.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitTypeDef_t.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitTypeDef_t.DMA_Mode = DMA_Mode_Normal;
  DMA_InitTypeDef_t.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitTypeDef_t.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitTypeDef_t.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel2, &DMA_InitTypeDef_t);
  USART_DMACmd(USART3, USART_DMAReq_Rx, ENABLE);
}

void usart3TX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length)
{
  DMA1_Channel2->CNDTR = length;
  DMA1_Channel2->CMAR = data;
  DMA1_Channel2->CPAR = perAddr;
  DMA1_Channel2->CCR |= DMA_DIR_PeripheralDST;
  DMA_Cmd(DMA1_Channel2, ENABLE);
}

void usart3RX_DMA_ENABLE(uint8_t *data, uint8_t *perAddr, uint16_t length)
{
  DMA1_Channel2->CNDTR = length;
  DMA1_Channel2->CMAR = data;
  DMA1_Channel2->CPAR = perAddr;
  DMA1_Channel2->CCR |= DMA_DIR_PeripheralSRC;
  DMA_Cmd(DMA1_Channel2, ENABLE);
}

void usart3_DMA_DISABLE()
{
  DMA_Cmd(DMA1_Channel2, DISABLE);
}