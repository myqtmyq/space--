#ifndef __PROTOCOL_H
#define __PROTOCOL_H
#include "stm32f10x.h"
#pragma pack(1)

/* @attention uint8_t
    value: 0- 8; 0 = 256 fractionize, 1-7 = 128 - 2 , 8 = 1*/
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t fractionizeMode;
  };

  struct
  {
    uint8_t data[4];
  };
} fractionize;

/* @attention uint8_t
    value: 0 -31; 0 -31  = 1/32 - 32/32*/
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t statiCurrentMode;
  };

  struct
  {
    uint8_t data[4];
  };
} staticCurrent;

/* @attention uint8_t
    value: 0 -31 default is 10; 0-31 = 1/32 - 32/32 */
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t dynamicCurrentMode;
  };

  struct
  {
    uint8_t data[4];
  };
} dynamicCurrent;

/* @attention uint8_t
    value:1- 255 default is 1; */
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t nodeID;
  };

  struct
  {
    uint8_t data[4];
  };

} nodeID;

/* @attention uint32_t
    value: baudrate: 0 - 115200 1 - 19200 2 - 9600
           stopbit: 0 - 1bit  1 - 2bit
           checkbit: 0 - none 1 - even 2 - odd
           default is 0
    bit 8-31 is 0*/
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t baudRate;
    uint8_t stopBit;
    uint8_t checkBit;
  };

  struct
  {
    uint8_t data[6];
  };

} param;

/* @attention uint16_t
    reserve must be 0
    only read*/
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t start : 1;
    uint8_t enable : 1;
    uint8_t emergencyStop : 1;
    uint8_t emergencyStopMode : 1;
    uint8_t faultReset : 1;
    uint8_t setOrigin : 1;
    uint8_t setZero : 1;
    uint8_t dataManagement : 1;
  };

  struct
  {
    uint8_t data[4];
  };

} controlBit;

/* @attention uint16_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t start : 1;
    uint8_t enable : 1;
    uint8_t emergencyStop : 1;
    uint8_t run : 1;
    uint8_t fault : 1;
  };

  struct
  {
    uint8_t data[4];
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
    uint16_t index;
    uint8_t motorMode;
  };

  struct
  {
    uint8_t data[4];
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
    uint16_t index;
    uint8_t speedUnit;
    uint8_t locationUnit;
    uint8_t timeUnit;
  };

  struct
  {
    uint8_t data[6];
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
    uint16_t index;
    uint32_t cofficient;
  };

  struct
  {
    uint8_t data[6];
  };

} physicalChange_TimeCoficient;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t offset;
  };

  struct
  {
    uint8_t data[6];
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
    uint16_t index;
    uint32_t errorCode;
  };

  struct
  {
    uint8_t data[6];
  };

} errorCode;

/* @attention uint32_t
    only in locationMode*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t maxSpeed;
  };

  struct
  {
    uint8_t data[6];
  };

} maxSpeed;

/* @attention uint32_t
 */
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t acceleration;
  };

  struct
  {
    uint8_t data[6];
  };
} acceleration;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t deceleration;
  };

  struct
  {
    uint8_t data[6];
  };
} deceleration;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t targetSpeed;
  };

  struct
  {
    uint8_t data[6];
  };

} targetSpeed;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t targetLocation;
  };

  struct
  {
    uint8_t data[6];
  };
} targetLocation;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t locationChange;
  };

  struct
  {
    uint8_t data[6];
  };

} locationChange;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t targetTime;
  };

  struct
  {
    uint8_t data[6];
  };

} targetTime;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t realSpeed;
  };

  struct
  {
    uint8_t data[6];
  };

} realSpeed;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t realLocation;
  };

  struct
  {
    uint8_t data[6];
  };

} realLocation;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t realTime;
  };

  struct
  {
    uint8_t data[6];
  };

} realTime;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t realVoltage;
  };

  struct
  {
    uint8_t data[6];
  };

} realVoltage;

/* @attention uint8_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint8_t closedCtrlEnabled;
  };

  struct
  {
    uint8_t data[4];
  };

} closedCtrlEnabled;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t lossSteps;
  };

  struct
  {
    uint8_t data[6];
  };

} lossSteps;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t lossWarnThreshold;
  };

  struct
  {
    uint8_t data[6];
  };

} lossWarnThreshold;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t lossStopThreshold;
  };

  struct
  {
    uint8_t data[6];
  };

} lossStopThreshold;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t targetSpeedIO;
  };

  struct
  {
    uint8_t data[6];
  };

} targetSpeedIO;

/* @attention int32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    int32_t locationChangeIO;
  };

  struct
  {
    uint8_t data[6];
  };

} locationChangeIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t timeChangeIO;
  };

  struct
  {
    uint8_t data[6];
  };

} timeChangeIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t accelerationIO;
  };

  struct
  {
    uint8_t data[6];
  };

} accelerationIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t decelerationIO;
  };

  struct
  {
    uint8_t data[6];
  };

} decelerationIO;

/* @attention uint32_t*/
typedef union
{
  struct
  {
    uint16_t index;
    uint32_t maxSpeedIO;
  };

  struct
  {
    uint8_t data[6];
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
    uint16_t index;
    uint8_t emergencyStop;
    uint8_t direction;
    uint8_t triggerORpwm;
    uint8_t runningStatus;
  };

  struct
  {
    uint8_t data[6];
  };

} IOmode;

#define ProtocolListInfo \
  {                      \
      {0x2000, 4},       \
      {0x2001, 4},       \
      {0x2002, 4},       \
      {0x2003, 4},       \
      {0x2004, 6},       \
      {0x2006, 4},       \
      {0x1000, 4},       \
      {0x2007, 4},       \
      {0x2008, 6},       \
      {0x200A, 6},       \
      {0x200C, 6},       \
      {0x1001, 6},       \
      {0x2010, 6},       \
      {0x2012, 6},       \
      {0x2014, 6},       \
      {0x2016, 6},       \
      {0x2018, 6},       \
      {0x201A, 6},       \
      {0x201C, 6},       \
      {0x1003, 6},       \
      {0x1005, 6},       \
      {0x1007, 6},       \
      {0x1009, 6},       \
      {0x2020, 4},       \
      {0x2021, 6},       \
      {0x2023, 6},       \
      {0x2025, 6},       \
      {0x2030, 6},       \
      {0x2032, 6},       \
      {0x2034, 6},       \
      {0x2036, 6},       \
      {0x2038, 6},       \
      {0x203A, 6},       \
      {0x203C, 6},       \
  }

typedef union
{
  struct
  {
    fractionize fractionize_t;
    staticCurrent staticCurrent_t;
    dynamicCurrent dynamicCurrent_t;
    nodeID nodeID_t;
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
    uint8_t data[188];
  };
} protocolData;

#endif