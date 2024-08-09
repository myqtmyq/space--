#include "PUMP.h"
#include "Handle.h"

void Pump_Enable(int id)
{
    protocolData_t.controlBit_t.enable = 1;
    usart1Send(protocolData_t.controlBit_t.data, id, writeOneReg);
}

void Pump_Mode(int id, PumpStateTypeDef state)
{
    protocolData_t.motorMode_t.motorMode = state;
    usart1Send(protocolData_t.motorMode_t.data, id, writeOneReg);
}

void Pump_ModeUnit(int id)
{
    protocolData_t.motorUnit_t.locationUnit = 0;
    protocolData_t.motorUnit_t.speedUnit = 1;
    protocolData_t.motorUnit_t.timeUnit = 0;
    usart1Send(protocolData_t.motorUnit_t.data, id, writeMutiReg);
}

/* @param speed unit: rpm ; acceleration unit: pulse/s^2*/
void Pump_Speed(int id, int32_t speed, uint32_t acceleration)
{
    protocolData_t.targetSpeed_t.targetSpeed = speed;
    protocolData_t.acceleration_t.acceleration = acceleration;
    usart1Send(protocolData_t.acceleration_t.data, id, writeMutiReg);
    delay(50);
    usart1Send(protocolData_t.targetSpeed_t.data, id, writeMutiReg);
}

void Pump_Start(int id)
{
    protocolData_t.controlBit_t.start = 1;
    usart1Send(protocolData_t.controlBit_t.data, id, writeOneReg);
}

void Pump_Stop(int id)
{
    protocolData_t.controlBit_t.start = 0;
    usart1Send(protocolData_t.controlBit_t.data, id, writeOneReg);
}
void Pump_Init(int id)
{
    Pump_Enable(id);
    delay(50);
    Pump_Mode(id, PUMP_SPEED);
    delay(50);
    Pump_ModeUnit(id);
    delay(50);
    Pump_Speed(id, 10000, 10000);
}
