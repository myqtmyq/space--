#include "BSP_spi.h"

void BSP_spi_Init()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitTypeDef GPIO_InitTypeDef_t;
  GPIO_InitTypeDef_t.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitTypeDef_t.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitTypeDef_t.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitTypeDef_t);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
  SPI_InitTypeDef SPI_InitTypeDef_t;
  SPI_InitTypeDef_t.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
  SPI_InitTypeDef_t.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitTypeDef_t.SPI_CPOL = SPI_CPOL_High;
  SPI_InitTypeDef_t.SPI_CRCPolynomial = 7;
  SPI_InitTypeDef_t.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitTypeDef_t.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitTypeDef_t.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitTypeDef_t.SPI_Mode = SPI_Mode_Master;
  SPI_InitTypeDef_t.SPI_NSS = SPI_NSS_Soft;

  SPI_Init(SPI1, &SPI_InitTypeDef_t);
  SPI_Cmd(SPI1, ENABLE);
}