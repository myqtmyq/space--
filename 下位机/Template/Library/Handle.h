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
#endif