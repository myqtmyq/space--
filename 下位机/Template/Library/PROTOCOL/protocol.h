#include "stm32f10x.h"

typedef enum
{
  Write1b = (uint8_t)0x2f,
  Write2b = (uint8_t)0x2b,
  Write3b = (uint8_t)0x27,
  Write4b = (uint8_t)0x23,
  Read = (uint8_t)0x40,
} operation;

typedef struct
{
  uint16_t index;
  uint8_t subindex;
} wholeIndex;

/* @attention uint8_t
    value: 0- 8; 0 = 256 fractionize, 1-7 = 128 - 2 , 8 = 1*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2000,
        0x00,
    };
    uint8_t fractionizeMode;
  };

  struct
  {
    uint8_t data[5];
  };
} fractionize;

/* @attention uint8_t
    value: 0 -31; 0 -31  = 1/32 - 32/32*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2001,
        0x00,
    };
    uint8_t statiCurrentMode;
  };

  struct
  {
    uint8_t data[5];
  };
} staticCurrent;

/* @attention uint8_t
    value: 0 -31 default is 10; 0-31 = 1/32 - 32/32 */
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2002,
        0x00,
    };
    uint8_t dynamicCurrentMode;
  };

  struct
  {
    uint8_t data[5];
  };
} dynamicCurrent;

/* @attention uint8_t
    value:1- 255 default is 1; */
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2010,
        0x00,
    };
    uint8_t canID;
  };

  struct
  {
    uint8_t data[5];
  };

} canID;

/* @attention uint32_t
    value: baudrate: bit 0-7 -> 10 = 1M, 5/0 = 500k, 2 = 250k default is 0
    bit 8-31 is 0*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2011,
        0x00,
    };
    uint8_t baudRate;
    uint32_t reserve : 24;
  };

  struct
  {
    uint8_t data[8];
  };

} param;

/* @attention uint16_t
    reserve must be 0
    only read*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x6040,
        0x00,
    };
    uint8_t start : 1;
    uint8_t enable : 1;
    uint8_t emergencyStop : 1;
    uint8_t emergencyStopMode : 1;
    uint8_t faultReset : 1;
    uint8_t setOrigin : 1;
    uint8_t setZero : 1;
    uint8_t dataManagement : 1;
    uint8_t reserve : 8;
  };

  struct
  {
    uint8_t data[6];
  };

} controlBit;

/* @attention uint16_t*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x6041,
        0x00};
    uint8_t start : 1;
    uint8_t enable : 1;
    uint8_t emergencyStop : 1;
    uint8_t run : 1;
    uint8_t fault : 1;
    uint8_t reserve : 11;
  };

  struct
  {
    uint8_t data[6];
  };
} statusBit;

/* @attention uint8_t
    0 = stop
    1 = speedMode
    2 = locationMode
    3 = timeMode
    4 = originBack
    5 = IOspeed
    6 = IOlocation
    7 = IOtime
    8 = IOexternPWM*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2020,
        0x00,
    };
    uint8_t motorMode;
  };

  struct
  {
    uint8_t data[5];
  };

} motorMode;

/* @attention uint32_t
    speed: 0 = pulse/s 1 = 0.01 rpm
    location: 0 = pulse 1 = 0.01 degree
    time: 0 = ms 1 = 0.01 ml
    */
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2023,
        0x00,
    };
    uint8_t speedUnit;
    uint8_t locationUnit;
    uint8_t timeUnit;
    uint8_t reserve;
  };

  struct
  {
    uint8_t data[8];
  };

} motorUnit;

/* @attention uint32_t
    enabled in timeMode
    the unit is 0.000001 (ml/min)/rpm when sportUnit is 1
    default cofficient is 1*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2024,
        0x00,
    };
    uint32_t cofficient;
  };

  struct
  {
    uint8_t data[8];
  };

} physicalChange_TimeCoficient;

/* @attention int32_t*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2021,
        0x00,
    };
    int32_t offset;
  };

  struct
  {
    uint8_t data[8];
  };

} originOffset;

/* @attention uint32_t
    0 = noError
    bit0 = loseStep
    bit1 = stuck
    bit2 = highTemp(>120 `C)
    bit3 = lowVoltage(<10V)
    bit4 = highVoltage(>26V)
    only read*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2022,
        0x00,
    };
    uint32_t errorCode;
  };

  struct
  {
    uint8_t data[8];
  };

} errorCode;

/* @attention uint32_t
    only in locationMode*/
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2030,
        0x00,
    };
    uint32_t maxSpeed;
  };

  struct
  {
    uint8_t data[8];
  };

} maxSpeed;

/* @attention uint32_t
 */
typedef union
{
  struct
  {
    operation operation_t;
    wholeIndex wholeIndex_t = {
        0x2031,
        0x00,
    };
    uint32_t acceleration;
  };

  struct
  {
    uint8_t data[8];
  };
};
