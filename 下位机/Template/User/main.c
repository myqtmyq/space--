#include "stm32f10x.h"

void SystemCLK_Config()
{
    RCC_HSEConfig(RCC_HSE_ON);
}

void BSP_CAN_Init(void)
{
    // ʹ��CANʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

    // ʹ��GPIOʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // ����CAN���ţ�RX (PA11) �� TX (PA12)
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // ��λCAN����
    CAN_DeInit(CAN1);

    CAN_InitTypeDef CAN_InitStructure;
    CAN_FilterInitTypeDef CAN_FilterInitStructure;

    CAN_StructInit(&CAN_InitStructure);

    // CAN��Ԫ��ʼ��
    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = DISABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = ENABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = ENABLE;
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;

    // ���ò�����
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    CAN_InitStructure.CAN_BS1 = CAN_BS1_3tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_2tq;
    CAN_InitStructure.CAN_Prescaler = 12; //  (����PCLK1 = 36MHz)
    CAN_Init(CAN1, &CAN_InitStructure);

    // CAN�˲�����ʼ��
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

// CAN��Ϣ����
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
        return 0; // ����ʧ��
    }

    return 1; // ���ͳɹ�
}

// 系统时钟配置函数
void SystemClock_Config(void)
{
    ErrorStatus HSEStartUpStatus;

    // 1. 启用HSE
    RCC_HSEConfig(RCC_HSE_ON);

    // 2. 等待HSE准备好
    HSEStartUpStatus = RCC_WaitForHSEStartUp();
    if (HSEStartUpStatus == SUCCESS)
    {
        // 3. 配置Flash预取和等待状态
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        FLASH_SetLatency(FLASH_Latency_2);

        // 4. 配置AHB、APB1和APB2总线时钟
        RCC_HCLKConfig(RCC_SYSCLK_Div1); // AHB不分频
        RCC_PCLK2Config(RCC_HCLK_Div1);  // APB2不分频
        RCC_PCLK1Config(RCC_HCLK_Div2);  // APB1分频因子，最大36 MHz

        // 5. 配置PLL
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9); // PLL: 8 MHz * 9 = 72 MHz

        // 6. 启用PLL
        RCC_PLLCmd(ENABLE);

        // 7. 等待PLL准备好
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
            ;

        // 8. 选择PLL作为系统时钟源
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

        // 9. 等待PLL作为系统时钟源生效
        while (RCC_GetSYSCLKSource() != 0x08)
            ;
    }
    else
    {
        // HSE启动失败，处理错误
        while (1)
            ;
    }
}

int main()
{
    SystemClock_Config();
    BSP_CAN_Init();
    uint8_t data[8] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22};

    while (1)
    {
        CAN_SendMessage(0x123, data, 8);
    }
}
