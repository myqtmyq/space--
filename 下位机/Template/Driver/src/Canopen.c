#include "Canopen.h"

void CAN_Send_SDO(int id,CtrlWorddef length,uint16_t index,uint8_t subindex,uint32_t data){
    int cobid=0x600+id;
    int data[8];
    data[0]=length;
    data[1]=index;

}

void CAN_Send_NMT(){



}

void CAN_Send_PDO(){



}