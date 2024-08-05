#include "BSP_DMA.h"

void uart1DMA_ENABLE(uint8_t *data, uint8_t length)
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  DMA_DeInit(DMA1_Channel4);
  DMA_InitTypeDef DMA_InitTypeDef_t;
  DMA_InitTypeDef_t.DMA_BufferSize = length;
  DMA_InitTypeDef_t.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitTypeDef_t.DMA_M2M - DMA_M2M_Disable;
  DMA_InitTypeDef_t.DMA_MemoryBaseAddr = data;
  DMA_InitTypeDef_t.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitTypeDef_t.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitTypeDef_t.DMA_Mode = DMA_Mode_Normal;
  DMA_InitTypeDef_t.DMA_PeripheralBaseAddr = &(USART1->DR);
  DMA_InitTypeDef_t.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitTypeDef_t.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitTypeDef_t.DMA_Priority = DMA_Priority_High;
  DMA_Init(DMA1_Channel4, &DMA_InitTypeDef_t);

  DMA_Cmd(DMA1_Channel4, ENABLE);
}

void uart1DMA_DISABLE()
{
  DMA_Cmd(DMA1_Channel4, DISABLE);
}