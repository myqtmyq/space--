#ifndef __DRIVER_PROTOCOL_H
#define __DRIVER_PROTOCOL_H
#include "stm32f10x.h"
#include "protocol.h"

typedef struct
{
  uint16_t index;
  uint8_t length;
  uint8_t offset;
} ProtocolInfo;

#endif