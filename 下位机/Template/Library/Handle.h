#ifndef __HANDLE_H
#define __HANDLE_H
#include "stm32f10x.h"
#include "protocol_v2.h"

#ifdef __HANDLE_GLOBALS
#define __HANDLE_EXT
#else
#define __HANDLE_EXT extern
#endif

__HANDLE_EXT protocolData protocolData_t;
__HANDLE_EXT uint8_t usart3_lock;
__HANDLE_EXT uint8_t USART3_RX_Buffer[32];
__HANDLE_EXT uint8_t USART2_RX_Buffer[48];
__HANDLE_EXT int testAngle;

#endif