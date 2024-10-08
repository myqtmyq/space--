#ifndef __CANOPEN_H
#define __CANOPEN_H

#include "stm32f10x.h"
#include "can.h"

#define Is_SDO(RxMessage) (RxMessage.StdId&0xf<<7==0x580) ? true : false

void CAN_Send_SDO(int id,uint8_t *data);

#endif