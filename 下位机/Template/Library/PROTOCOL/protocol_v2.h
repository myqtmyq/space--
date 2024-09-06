#ifndef __PROTOCOL_V2_H
#define __PROTOCOL_V2_H
#include "stm32f10x.h"
#pragma pack(1)

typedef union
{
  struct
  {
    uint16_t index;
    uint8_t finish : 1;
    uint8_t backZeroFinish : 1;
    uint8_t motorRun : 1;
    uint8_t error : 1;
    uint8_t motorEnable : 1;
    uint8_t positiveSoftLimit : 1;
    uint8_t negativeSoftLimit : 1;
  };

  struct
  {
    uint8_t data[4];
  };
} runningStatus;

typedef union
{
  struct
  {
    uint16_t index;
    uint8_t errorCode;
  };

  struct
  {
    uint8_t data[4];
  };

} error;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t realPosition;
  };

  struct
  {
    uint8_t data[4];
  };

} realPosition;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t realSpeed;
  };

  struct
  {
    uint8_t data[4];
  };

} realSpeed;

typedef union
{
  struct
  {
    uint16_t index;
    uint8_t ID;
  };

  struct
  {
    uint8_t data[4];
  };

} ID;

typedef union
{
  struct
  {
    uint16_t index;
    uint8_t dataPackMode;
  };

  struct
  {
    uint8_t data[4];
  };

} dataPackMode;

typedef union
{
  struct
  {
    uint16_t index;
    uint8_t direction;
  };

  struct
  {
    uint8_t data[4];
  };

} defaultDirection;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t fractionize;
  };

  struct
  {
    uint8_t data[4];
  };

} fractionize;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t pStartSpeed;
  };

  struct
  {
    uint8_t data[4];
  };

} pStartSpeed;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t pAccTime;
  };

  struct
  {
    uint8_t data[4];
  };

} pAccTime;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t pDecTime;
  };

  struct
  {
    uint8_t data[4];
  };

} pDecTime;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t pRunSpeed;
  };

  struct
  {
    uint8_t data[4];
  };

} pRunSpeed;

typedef union
{
  struct
  {
    uint16_t index;
    int32_t pTarget;
  };

  struct
  {
    uint8_t data[6];
  };

} pTarget;

typedef union
{
  struct
  {
    uint16_t index;
    uint8_t pCrtl : 1;
    uint8_t pMode : 1;
    uint8_t changeMode : 1;
    uint8_t JOGctrl : 1;
    uint8_t backZeroCtrl : 1;
    uint8_t stopCtrl : 1;
    uint8_t emergStop : 1;
  };

  struct
  {
    uint8_t data[4];
  };

} ctrlBit;

typedef union
{
  struct
  {
    uint16_t index;
    uint16_t cmd;
  };

  struct
  {
    uint8_t data[4];
  };

} subCtrl;

#define protocolInfoList \
  {                      \
    {4, 4},              \
        {5, 4},          \
        {8, 6},          \
        {10, 4},         \
        {32, 4},         \
        {33. 4},         \
        {34, 4},         \
        {35, 4},         \
        {51, 4},         \
        {52, 4},         \
        {53, 4},         \
        {54, 4},         \
        {55, 6},         \
        {78, 4},         \
    {                    \
      79, 4              \
    }                    \
  }

typedef union
{
  struct
  {
    runningStatus runningStatus_t;
    error error_t;
    realPosition realPosition_t;
    realSpeed realSpeed;
    ID ID_t;
    dataPackMode dataPackMode_t;
    defaultDirection defaultDirection_t;
    fractionize fractionize_t;
    pStartSpeed pStartSpeed_t;
    pAccTime pAccTime_t;
    pDecTime pDecTime_t;
    pRunSpeed pRunSpeed_t;
    pTarget pTarget_t;
    ctrlBit ctrlBit_t;
    subCtrl subCtrl_t;
  };

  struct
  {
    uint8_t data[64];
  };
} protocolData;

#endif