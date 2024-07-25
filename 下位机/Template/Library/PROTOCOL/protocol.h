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
    uint8_t data[1];
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
    uint8_t data[1];
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
    uint8_t data[1];
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
    uint8_t data[1];
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
    uint8_t data[4];
  };

  struct
  {
    uint8_t data[8];
  };

} param;
