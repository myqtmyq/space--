#include "PUMP.h"
#include "Handle.h"

void Pump_Enable(int id)
{
    protocolData_t.subCtrl_t.cmd = 0x500;
    usart3Send(protocolData_t.subCtrl_t.data, id, writeOneReg);
}

void Pump_Init(int id)
{
    protocolData_t.pStartSpeed_t.pStartSpeed = 10;
    usart3Send(protocolData_t.pStartSpeed_t.data, id, writeOneReg);
    protocolData_t.pAccTime_t.pAccTime = 500;
    usart3Send(protocolData_t.pAccTime_t.data, id, writeOneReg);
    protocolData_t.pDecTime_t.pDecTime = 200;
    usart3Send(protocolData_t.pDecTime_t.data, id, writeOneReg);
    protocolData_t.pRunSpeed_t.pRunSpeed = 200;
    usart3Send(protocolData_t.pRunSpeed_t.data, writeOneReg);
    protocolData_t.ctrlBit_t.pMode = 0;
    protocolData_t.ctrlBit_t.changeMode = 1;
    protocolData_t.ctrlBit_t.JOGctrl = 0;
    protocolData_t.ctrlBit_t.backZeroCtrl = 0;
    protocolData_t.ctrlBit_t.emergStop = 0;
    protocolData_t.ctrlBit_t.stopCtrl = 0;
    usart3Send(protocolData_t.ctrlBit_t.data, id, writeOneReg);
}

void Pump_pStart(int id, int pTarget)
{
    protocolData_t.pTarget_t.pTarget = pTarget;
    usart3send(protocolData_t.pTarget_t.data, id, writeMutiReg);
    protocolData_t.ctrlBit_t.pCrtl = 1;
    usart3Send(protocolData_t.ctrlBit_t.data, id, writeOneReg);
}
