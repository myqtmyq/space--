#include "BSP_flash.h"
void writeEnable_f()
{
  flashCS_ENABLE();
  uint8_t command = writeEnable;
  spi1_send(&command, 0x01, DISABLE, 0x00, 0x00);
  flashCS_DISABLE();
}

uint8_t readStatus_f()
{
  flashCS_ENABLE();
  uint8_t command = readStatusReg;
  uint8_t status;
  spi1_send(&command, 0x01, ENABLE, &status, 0x01);
  return status;
}

void writeData_f(uint8_t *data, uint16_t length, uint32_t flashAddr)
{
  uint8_t pageLen = 256 - flashAddr % 256;
  if (length + 3 <= pageLen)
  {
    pageLen = length + 3;
  }
  while (1)
  {
    uint8_t buffer[pageLen + 3];
    for (int i = 0; i < pageLen + 3; i++)
    {
      if (i < 3)
      {
        *(buffer + i) = (flashAddr >> i) & 0xFF;
      }
      else
      {
        *(buffer + i) = *(data + i - 3);
      }
    }
    uint8_t *bufferTX = buffer;
    while (readStatus_f() & 0x01)
    {
      /* code */
    }
    writeEnable_f();
    flashCS_ENABLE();
    uint8_t command = pageEdit;
    spi1_send(&command, 0x01, DISABLE, 0x00, 0x00);
    spi1_send(bufferTX, pageLen + 3, DISABLE, 0x00, 0x00);
    flashCS_DISABLE();
    if (pageLen == length)
    {
      break;
    }
    else
    {
      data += pageLen;
      flashAddr += pageLen;
      length -= pageLen;
      if (length > 256)
      {
        pageLen = 256;
      }
      else
      {
        pageLen = length;
      }
    }
  }
}

void readData_f(uint8_t *bufferRX, uint16_t length, uint32_t flashAddr)
{
  while (readStatus_f() & 0x01)
  {
    /* code */
  }
  flashCS_ENABLE();
  uint8_t command = readData;
  spi1_send(&command, 0x01, DISABLE, 0x00, 0x00);
  spi1_send(&flashAddr, 0x03, ENABLE, bufferRX, length);
  flashCS_DISABLE();
}