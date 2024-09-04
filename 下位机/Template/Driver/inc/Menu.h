#ifndef __MENU_H
#define __MENU_H
#include "stm32f10x.h"

typedef struct
{
  pMenu preMenu;
  pModulePart pModulePartFirst;
  pModulePart CurrentModulePart;
} menu;

typedef menu *pMenu;

typedef struct
{
  uint32_t *pflashData;
  pModulePart NextModulePart;
  pMenu subMenu;
  uint8_t changeEnabled;
} modulePart;

typedef modulePart *pModulePart;

typedef union
{
  struct
  {
    char **charData;
  };

  struct
  {
    char **charData;
    float data;
  };

  struct
  {
    char **charData;
    uint8_t id;
    float data;
  };

} modulePartData;
typedef modulePartData *pModulePartData;

#endif