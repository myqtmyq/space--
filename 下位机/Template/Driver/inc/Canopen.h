#ifndef __CANOPEN_H
#define __CANOPEN_H

#include "stm32f10x.h"
#include "can.h"

#define Is_SDO(RxMessage) (RxMessage.StdId&0xf<<7==0x580) ? true : false

typedef enum{
    SDO_OneByte=0x2F,
    SDO_Two_Byte=0x2B,
    SDO_Three_Byte=0x27,
    SDO_Four_Byte=0x23
}CtrlWorddef;

#endif