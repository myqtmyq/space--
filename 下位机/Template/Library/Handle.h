#ifndef __HANDLE_H
#define __HANDLE_H
#include "stm32f10x.h"
#include "Driver_protocol.h"
#include "protocol.h"
#include "Menu.h"

#ifdef __HANDLE_GLOBALS
#define __HANDLE_EXT
#else
#define __HANDLE_EXT extern
#endif

__HANDLE_EXT protocolData protocolData_t;
__HANDLE_EXT uint8_t usart3_lock;
__HANDLE_EXT uint8_t USART3_RX_Buffer[32];
__HANDLE_EXT uint8_t USART2_RX_Buffer[48];

__HANDLE_EXT menu home;
__HANDLE_EXT menu recipe;
__HANDLE_EXT menu customize;
__HANDLE_EXT menu detailRecipe;
__HANDLE_EXT menu RecipeEditor;
#endif