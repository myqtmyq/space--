#include "PUMP.h"
#include "Handle.h"

void Pump_Enable(int id)
{
    protocolData_t.controlBit_t.enable = 1;
    protocolData_t.controlBit_t.operation = Write2b;
    CAN_Send_SDO(id, protocolData_t.controlBit_t.data);
}

void Pump_Mode(int id, PumpStateTypeDef state)
{
    protocolData_t.motorMode_t.motorMode = state;
    protocolData_t.motorMode_t.operation = Write1b;
    CAN_Send_SDO(id, protocolData_t.motorMode_t.data);
}

void Pump_ModeUnit(int id)
{
    protocolData_t.motorUnit_t.locationUnit = 1;
    protocolData_t.motorUnit_t.speedUnit = 1;
    protocolData_t.motorUnit_t.timeUnit = 0;
    protocolData_t.motorUnit_t.operation = Write4b;
    CAN_Send_SDO(id, protocolData_t.motorUnit_t.data);
}

/* @param speed unit: rpm ; acceleration unit: pulse/s^2*/
void Pump_Speed(int id, int32_t speed, uint32_t acceleration)
{
    protocolData_t.targetSpeed_t.targetSpeed = speed;
    protocolData_t.targetSpeed_t.operation = Write4b;
    CAN_Send_SDO(id, protocolData_t.targetSpeed_t.data);
    //delay(50);
    protocolData_t.acceleration_t.acceleration = acceleration;
    protocolData_t.acceleration_t.operation = Write4b;
    CAN_Send_SDO(id, protocolData_t.acceleration_t.data);
}

void Pump_Start(int id)
{
    protocolData_t.controlBit_t.start = 1;
    protocolData_t.controlBit_t.operation = Write2b;
    CAN_Send_SDO(id, protocolData_t.controlBit_t.data);
}

void Pump_Stop(int id)
{
    protocolData_t.controlBit_t.start = 0;
    protocolData_t.controlBit_t.operation = Write2b;
    CAN_Send_SDO(id, protocolData_t.controlBit_t.data);
}
void Pump_Init(int id)
{
    Pump_Enable(id);
    //delay(50);
    Pump_Mode(id, PUMP_SPEED);
    //delay(50);
    Pump_ModeUnit(id);
    //delay(5);
    Pump_Speed(id, 60, 400);
}
