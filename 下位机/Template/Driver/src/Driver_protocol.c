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
      protocolData_t->data[sum + 2] = (ProtocolInfo_t[i].index >> 4) & 0xff;
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