#include "PUMP.h"
#include "Handle.h"


void Pump_Enable(int id){
    protocolData_t.controlBit_t.enable = 1;
    CAN_Send_SDO(id,protocolData_t.controlBit_t.data);
}

void Pump_Mode(int id, PumpStateTypeDef state){
    protocolData_t.motorMode_t.motorMode = state;
    CAN_Send_SDO(id,protocolData_t.motorMode_t.data);
}

void Pump_Speed(int id, uint8_t speed){
    protocolData_t.targetSpeed_t.targetSpeed = speed;
    CAN_Send_SDO(id,protocolData_t.targetSpeed_t.data);
}

void Pump_Init(int id)
{
    Pump_Enable(id);
    Pump_Mode(id,PUMP_STOP);
}
