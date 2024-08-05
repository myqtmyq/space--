#include "Driver_protocol.h"
#define writeOneReg 0x06
#define writeMutiReg 0x10
#define readReg_unchan 0x03
#define readReg_chan 0x04

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
      protocolData_t->data[sum] = ProtocolInfo_t[i].index & 0xff;
      protocolData_t->data[sum + 1] = (ProtocolInfo_t[i].index >> 8) & 0xff;
      for (int j = 0; j < ProtocolInfo_t[i].length - 2; j++)
      {
        protocolData_t->data[sum + 2 + j] = 0;
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

uint8_t *protocolPack(uint8_t *data, uint8_t id, uint8_t operation)
{
  uint8_t length = getlength(operation);
  uint8_t data_re[length];
  data_re[0] = id;
  data_re[1] = operation;
  data_re[2] = data[0];
  data_re[3] = data[1];
  if (operation == writeMutiReg)
  {
    data_re[4] = 0x02;
    data_re[5] = 0x00;
    data_re[6] = 0x04;
    for (int i = 1; i < 5; i++)
    {
      data_re[6 + i] = data[1 + i];
    }
  }
  else
  {
    for (int i = 1; i < 3; i++)
    {
      data_re[3 + i] = data[1 + i];
    }
  }
  reverse(data_re, length - 2);
  getCRC16(data_re, length - 2);
  return data_re;
}

uint8_t getlength(uint8_t operation)
{
  switch (operation)
  {
  case writeOneReg:
    return 0x08;
    break;
  case writeMutiReg:
    return 0x0D;
    break;
  default:
    return -1;
    break;
  }
}