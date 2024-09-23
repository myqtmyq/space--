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
    usart3Send(protocolData_t.pRunSpeed_t.data, id, writeOneReg);
    protocolData_t.ctrlBit_t.pMode = 0;
    protocolData_t.ctrlBit_t.changeMode = 1;
    protocolData_t.ctrlBit_t.JOGctrl = 0;
    protocolData_t.ctrlBit_t.backZeroCtrl = 0;
    protocolData_t.ctrlBit_t.emergStop = 0;
    protocolData_t.ctrlBit_t.stopCtrl = 0;
    usart3Send(protocolData_t.ctrlBit_t.data, id, writeOneReg);
    protocolData_t.fractionize_t.fractionize = 450;
    usart3Send(protocolData_t.fractionize_t.data, id, writeOneReg);
}

void Pump_pStart(int id, int pTarget)
{
    protocolData_t.pTarget_t.pTarget = pTarget;
    usart3Send(protocolData_t.pTarget_t.data, id, writeMutiReg);
    protocolData_t.ctrlBit_t.pCrtl = 1;
    usart3Send(protocolData_t.ctrlBit_t.data, id, writeOneReg);
}

void Pump_setId(int id)
{
    protocolData_t.ID_t.ID = id;
    usart3Send(protocolData_t.ID_t.data, 0x00, writeOneReg);
    delay(1);
    protocolData_t.subCtrl_t.cmd = 0x200;
    usart3Send(protocolData_t.subCtrl_t.data, 0x00, writeOneReg);
}

void Key_EXTI_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitTypeDef_t;
    GPIO_InitTypeDef_t.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitTypeDef_t.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_0;
    GPIO_InitTypeDef_t.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitTypeDef_t);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);

    EXTI_InitTypeDef EXTI_InitTypeDef_t;
    EXTI_InitTypeDef_t.EXTI_Line = EXTI_Line0;
    EXTI_InitTypeDef_t.EXTI_LineCmd = ENABLE;
    EXTI_InitTypeDef_t.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitTypeDef_t.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitTypeDef_t);
    EXTI_InitTypeDef_t.EXTI_Line = EXTI_Line6;
    EXTI_Init(&EXTI_InitTypeDef_t);

    NVIC_InitTypeDef NVIC_InitTypeDef_t;
    NVIC_InitTypeDef_t.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitTypeDef_t.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitTypeDef_t.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitTypeDef_t.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVIC_InitTypeDef_t);
    NVIC_InitTypeDef_t.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_Init(&NVIC_InitTypeDef_t);
}