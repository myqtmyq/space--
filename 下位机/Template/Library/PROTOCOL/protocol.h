#ifndef __PROTOCOL_H
#define __PROTOCOL_H
#include "stm32f10x.h"

#define Write1b 0x2f
#define Write2b 0x2b
#define Write3b 0x27
#define Write4b 0x23
#define Read 0x40

/* @attention uint8_t
    value: 0- 8; 0 = 256 fractionize, 1-7 = 128 - 2 , 8 = 1*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint8_t start : 1;
    uint8_t enable : 1;
    uint8_t emergencyStop : 1;
    uint8_t run : 1;
    uint8_t fault : 1;
    uint16_t reserve : 11;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
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
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t acceleration;
  };

  struct
  {
    uint8_t data[8];
  };
} acceleration;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t deceleration;
  };

  struct
  {
    uint8_t data[8];
  };
} deceleration;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    int32_t targetSpeed;
  };

  struct
  {
    uint8_t data[8];
  };

} targetSpeed;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    int32_t targetLocation;
  };

  struct
  {
    uint8_t data[8];
  };
} targetLocation;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    int32_t locationChange;
  };

  struct
  {
    uint8_t data[8];
  };

} locationChange;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t targetTime;
  };

  struct
  {
    uint8_t data[8];
  };

} targetTime;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    int32_t realSpeed;
  };

  struct
  {
    uint8_t data[8];
  };

} realSpeed;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    int32_t realLocation;
  };

  struct
  {
    uint8_t data[8];
  };

} realLocation;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t realTime;
  };

  struct
  {
    uint8_t data[8];
  };

} realTime;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t realVoltage;
  };

  struct
  {
    uint8_t data[8];
  };

} realVoltage;

/* @attention uint8_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint8_t closedCtrlEnabled;
  };

  struct
  {
    uint8_t data[5];
  };

} closedCtrlEnabled;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t lossSteps;
  };

  struct
  {
    uint8_t data[8];
  };

} lossSteps;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t lossWarnThreshold;
  };

  struct
  {
    uint8_t data[8];
  };

} lossWarnThreshold;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t lossStopThreshold;
  };

  struct
  {
    uint8_t data[8];
  };

} lossStopThreshold;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    int32_t targetSpeedIO;
  };

  struct
  {
    uint8_t data[8];
  };

} targetSpeedIO;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    int32_t locationChangeIO;
  };

  struct
  {
    uint8_t data[8];
  };

} locationChangeIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t timeChangeIO;
  };

  struct
  {
    uint8_t data[8];
  };

} timeChangeIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t accelerationIO;
  };

  struct
  {
    uint8_t data[8];
  };

} accelerationIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t decelerationIO;
  };

  struct
  {
    uint8_t data[8];
  };

} decelerationIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint32_t maxSpeedIO;
  };

  struct
  {
    uint8_t data[8];
  };

} maxSpeedIO;

/* @attention uint32_t
    input_1 emergStop; input_2 direction; input_3 triggerORpwm
    0 = raising edge
    1 = falling edge
    2 = high
    3 = low
    output_1_2(1:run 2:error)
    0 = high
    1 = low*/
typedef union
{
  struct
  {
    uint8_t operation;
    uint16_t index;
    uint8_t subIndex;
    uint8_t emergencyStop;
    uint8_t direction;
    uint8_t triggerORpwm;
    uint8_t runningStatus;
  };

  struct
  {
    uint8_t data[8];
  };

} IOmode;

#define ProtocolListInfo \
  {                      \
      {0x2000, 5},       \
      {0x2001, 5},       \
      {0x2002, 5},       \
      {0x2010, 5},       \
      {0x2011, 8},       \
      {0x6040, 6},       \
      {0x6041, 6},       \
      {0x2020, 5},       \
      {0x2023, 8},       \
      {0x2024, 8},       \
      {0x2021, 8},       \
      {0x2022, 8},       \
      {0x2030, 8},       \
      {0x2031, 8},       \
      {0x2032, 8},       \
      {0x2040, 8},       \
      {0x2041, 8},       \
      {0x2042, 8},       \
      {0x2043, 8},       \
      {0x2050, 8},       \
      {0x2051, 8},       \
      {0x2052, 8},       \
      {0x2053, 8},       \
      {0x2060, 5},       \
      {0x2061, 8},       \
      {0x2062, 8},       \
      {0x2063, 8},       \
      {0x2070, 8},       \
      {0x2071, 8},       \
      {0x2072, 8},       \
      {0x2073, 8},       \
      {0x2074, 8},       \
      {0x2075, 8},       \
      {0x2076, 8},       \
  }

typedef union
{
  struct
  {
    fractionize fractionize_t;
    staticCurrent staticCurrent_t;
    dynamicCurrent dynamicCurrent_t;
    canID canID_t;
    param param_t;
    controlBit controlBit_t;
    statusBit statusBit_t;
    motorMode motorMode_t;
    motorUnit motorUnit_t;
    physicalChange_TimeCoficient physicalChange_TimeCoficient_t;
    originOffset originOffset_t;
    errorCode errorCode_t;
    maxSpeed maxSpeed_t;
    acceleration acceleration_t;
    deceleration deceleration_t;
    targetSpeed targetSpeed_t;
    targetLocation targetLocation_t;
    locationChange locationChange_t;
    targetTime targetTime_t;
    realSpeed realSpeed_t;
    realLocation realLocation_t;
    realTime realTime_t;
    realVoltage realVoltage_t;
    closedCtrlEnabled closedCtrlEnabled_t;
    lossSteps lossSteps_t;
    lossWarnThreshold lossWarnThreshold_t;
    lossStopThreshold lossStopThreshold_t;
    targetSpeedIO targetSpeedIO_t;
    locationChangeIO locationChangeIO_t;
    timeChangeIO timeChangeIO_t;
    accelerationIO accelerationIO_t;
    decelerationIO decelerationIO_t;
    maxSpeedIO maxSpeedIO_t;
    IOmode IOmode_t;
  };

  struct
  {
    uint8_t data[250];
  };
} protocolData;

#endif