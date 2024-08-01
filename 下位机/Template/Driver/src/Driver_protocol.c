#include "Driver_protocol.h"

ProtocolInfo ProtocolInfo_t[] = ProtocolListInfo;
int protocolListSize = sizeof(ProtocolInfo_t) / sizeof(ProtocolInfo);

void protocolInit(protocolData *protocolData_t)
{
  int sum = 0;
  if (ProtocolInfo_t[1].offset == 0)
  {
    for (int i = 0; i < protocolListSize; i++)
    {
      ProtocolInfo_t[i].offset = sum;
      protocolData_t->data[sum] = 0x40;
      protocolData_t->data[sum + 1] = ProtocolInfo_t[i].index & 0xff;
      protocolData_t->data[sum + 2] = (ProtocolInfo_t[i].index >> 8) & 0xff;
      protocolData_t->data[sum + 3] = 0x00;
      for (int j = 0; j < 4; j++)
      {
        protocolData_t->data[sum + 4 + j] = 0;
      }
      sum += ProtocolInfo_t[i].length;
    }
  }
}

uint8_t getOffset(uint16_t index)
{
  for (int i = 0; i < protocolListSize; i++)
  {
    if (ProtocolInfo_t[i].index == index)
    {
      return ProtocolInfo_t[i].offset;
    }
  }
}

/* @param length -> exclusive CRC's 2 bytes*/
void getCRC16(uint8_t *data, uint8_t length)
{
  uint16_t CRC16 = 0xffff;
  uint16_t ploy = 0x8005;
  int i = length;
  while (i--)
  {
    CRC16 ^= (*(data + length - i) << 8);
    for (int i = 0; i < 8; i++)
    {
      if (CRC16 & 0x8000)
      {
        CRC16 = (CRC16 << 1) ^ ploy;
      }
      else
      {
        CRC16 << 1;
      }
    }
  }
  *(data + length) = CRC16 & 0xff;
  *(data + length + 1) = (CRC16 >> 8) & 0xff;
}

/* @param length -> exclusive CRC's 2 bytes*/
void reverse(uint8_t *data, uint8_t length)
{
  uint8_t temp;
  // index
  temp = *(data + 2);
  *(data + 2) = *(data + 3);
  *(data + 3) = temp;
  // data or register numbers
  temp = *(data + 4);
  *(data + 4) = *(data + 5);
  *(data + 5) = temp;
  //
  if (length > 6)
  {
    // data
    int i = (length - 7) / 2;
    for (int j = 0; j < i; j++)
    {
      temp = *(data + 7 + j);
      *(data + 7 + j) = *(data + length - j);
      *(data + length - 1 - j) = temp;
    }
  }
}