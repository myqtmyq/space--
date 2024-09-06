#ifndef __DRIVER_PROTOCOL_H
#define __DRIVER_PROTOCOL_H
#include "stm32f10x.h"
#include "protocol_v2.h"

#define writeOneReg 0x06
#define writeMutiReg 0x10
#define readReg_unchan 0x03
#define readReg_chan 0x04
typedef struct
{
  uint16_t index;
  uint8_t length;
  uint8_t offset;
} ProtocolInfo;

void protocolInit(protocolData *protocolData_t);
uint8_t getOffset(uint16_t index);
void protocolPack(uint8_t *buffer, uint8_t *data, uint8_t id, uint8_t operation);
uint8_t getlength(uint8_t operation);
#endif