#ifndef __HANDLE_H
#define __HANDLE_H
#include "stm32f10x.h"
#include "Driver_protocol.h"
#include "protocol.h"

#ifdef __HANDLE_GLOBALS
#define __HANDLE_EXT
#else
#define __HANDLE_EXT extern
#endif

__HANDLE_EXT protocolData protocolData_t;
__HANDLE_EXT uint8_t usart1_lock;
__HANDLE_EXT uint8_t USART1_RX_Buffer[32];
#endif