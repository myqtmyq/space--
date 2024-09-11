#include "Driver_protocol.h"

ProtocolInfo ProtocolInfo_t[] = protocolInfoList;
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
  uint16_t ploy = 0xA001;
  for (int i = 0; i < length; i++)
  {
    CRC16 ^= *(data + i);
    for (int j = 0; j < 8; j++)
    {
      if (CRC16 & 0x0001)
      {
        CRC16 = (CRC16 >> 1) ^ ploy;
      }
      else
      {
        CRC16 >>= 1;
      }
    }
  }
  *(data + length) = (CRC16 & 0xff00) >> 8;
  *(data + length + 1) = CRC16 & 0xff;
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
      *(data + 7 + j) = *(data + length - 1 - j);
      *(data + length - 1 - j) = temp;
    }
  }
}

void protocolPack(uint8_t *buffer, uint8_t *data, uint8_t id, uint8_t operation)
{
  uint8_t length = getlength(operation);
  buffer[0] = id;
  buffer[1] = operation;
  buffer[2] = data[0];
  buffer[3] = data[1];
  if (operation == writeMutiReg)
  {
    buffer[4] = 0x02;
    buffer[5] = 0x00;
    buffer[6] = 0x04;
    for (int i = 1; i < 5; i++)
    {
      buffer[6 + i] = data[1 + i];
    }
  }
  else if (operation == readReg_chan || operation == readReg_unchan)
  {
    if (!(0x1000 ^ id))
    {
      buffer[4] = 0x00;
      buffer[5] = 0x01;
    }
    else
    {
      buffer[4] = 0x00;
      buffer[5] = 0x02;
    }
  }
  else
  {
    for (int i = 1; i < 3; i++)
    {
      buffer[3 + i] = data[1 + i];
    }
  }
  reverse(buffer, length - 2);
  getCRC16(buffer, length - 2);
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
  case readReg_chan:
    return 0x08;
    break;
  case readReg_unchan:
    return 0x08;
    break;
  default:
    return -1;
    break;
  }
}