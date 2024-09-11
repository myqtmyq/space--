#ifndef __MENU_H
#define __MENU_H
#include "stm32f10x.h"
typedef modulePart *pModulePart;
typedef menu *pMenu;
typedef modulePartData *pModulePartData;
typedef struct
{
  pMenu preMenu;
  pModulePart pModulePartFirst;
  pModulePart CurrentModulePart;
} menu;

typedef struct
{
  uint32_t *pflashData;
  pModulePart NextModulePart;
  pMenu subMenu;
  uint8_t changeEnabled;
} modulePart;

typedef union
{
  struct
  {
    char **charData1;
  };

  struct
  {
    char **charData2;
    float data1;
  };

  struct
  {
    char **charData3;
    uint8_t id;
    float data2;
  };

} modulePartData;

#endif