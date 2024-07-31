#include "Can.h"

void BSP_CAN_Init(void)
{
    // ???CAN???
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

    // ???GPIO???
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // ????CAN?????RX (PA11) ?? TX (PA12)
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // ??��CAN????
    CAN_DeInit(CAN1);

    CAN_InitTypeDef CAN_InitStructure;
    CAN_FilterInitTypeDef CAN_FilterInitStructure;

    CAN_StructInit(&CAN_InitStructure);

    // CAN????????
    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = DISABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = ENABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = ENABLE;
    CAN_InitStructure.CAN_Mode = CAN_Mode_LoopBack;

    // ???��?????
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    CAN_InitStructure.CAN_BS1 = CAN_BS1_3tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_2tq;
    CAN_InitStructure.CAN_Prescaler = 12; //  (????PCLK1 = 36MHz)
    CAN_Init(CAN1, &CAN_InitStructure);

    // CAN??????????
    CAN_FilterInitStructure.CAN_FilterNumber = 0;
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
    CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FilterFIFO0;
    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CAN_FilterInitStructure);
}

// CAN???????
uint8_t CAN_SendMessage(uint32_t id, uint8_t *data, uint8_t length)
{
    CanTxMsg TxMessage;
    TxMessage.StdId = id;
    TxMessage.ExtId = 0x00;
    TxMessage.IDE = CAN_Id_Standard;
    TxMessage.RTR = CAN_RTR_Data;
    TxMessage.DLC = length;
    for (uint8_t i = 0; i < length; i++)
    {
        TxMessage.Data[i] = data[i];
    }

    uint8_t mailbox = CAN_Transmit(CAN1, &TxMessage);
    uint32_t timeout = 0xFFFF;

    // while((CAN_TransmitStatus(CAN1, mailbox) != CAN_TxStatus_Ok) && (timeout--));

    if (timeout == 0)
    {
        return 0; // ???????
    }

    return 1; // ??????
}
