#include "Canopen.h"

void CAN_Send_SDO(int id,uint8_t *data){
    int cobid=0x600+id;
    CAN_SendMessage(cobid,data,8);

}

void CAN_Send_NMT(){



}

void CAN_Send_PDO(){



}