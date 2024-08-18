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

void Pump_Maxspeed(int id,int maxspeed,int acceleration){
	protocolData_t.maxSpeed_t.maxSpeed=maxspeed;
    usart1Send(protocolData_t.maxSpeed_t.data, id, writeMutiReg);
    delay(50);
    protocolData_t.acceleration_t.acceleration = acceleration;	
    usart1Send(protocolData_t.acceleration_t.data, id, writeMutiReg);
}
	
void Pump_Zero(int id){
	protocolData_t.controlBit_t.setZero=1;
    usart1Send(protocolData_t.controlBit_t.data, id, writeOneReg);
    delay(50);
	protocolData_t.controlBit_t.setZero=0;
    usart1Send(protocolData_t.controlBit_t.data, id, writeOneReg);
}

void Pump_Location(int id,int location){
	protocolData_t.targetLocation_t.targetLocation=location;
    usart1Send(protocolData_t.targetLocation_t.data, id, writeMutiReg);
	
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
	/*
    Pump_Mode(id, PUMP_SPEED);
    delay(50);
    Pump_Speed(id, 10000, 10000);
	*/ 
	Pump_Mode(id,PUMP_ORI);
    delay(50);
	
    Pump_ModeUnit(id);
    delay(50);

	Pump_Maxspeed(id ,20000,512000);
    delay(50);
	
	Pump_Zero(id);
  	delay(50);
	
}

void Pump_Read()
{
    usart1Send(protocolData_t.realSpeed_t.data, 0x01, readReg_unchan);
}
