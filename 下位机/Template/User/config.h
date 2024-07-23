#ifndef __CONFIG_H
#define __CONFIG_H

/*************************GPIO_Configuration*************************/
/****GPIOA****/
/*Pin*/
#define A0 0
#define A1 0
#define A2 0
#define A3 0
#define A4 0
#define A5 0
#define A6 0
#define A7 0
#define A8 0
#define A9 0
#define A10 0
#define A11 0
#define A12 0
#define A13 0
#define A14 0
#define A15 0
// GPIO_Mode_Out_PP
// GPIO_Mode_Out_OD
// GPIO_Mode_IPU
// GPIO_Mode_IPD
/****GPIOB****/
/*Pin*/
#define B0 0
#define B1 0
#define B2 0
#define B3 0
#define B4 0
#define B5 0
#define B6 0
#define B7 0
#define B8 0
#define B9 0
#define B10 0
#define B11 0
#define B12 0
#define B13 0
#define B14 0
#define B15 0
// GPIO_Mode_Out_PP
// GPIO_Mode_Out_OD
// GPIO_Mode_IPU
// GPIO_Mode_IPD
/****GPIOC****/
/*Pin*/
#define C0 0
#define C1 0
#define C2 0
#define C3 0
#define C4 0
#define C5 0
#define C6 0
#define C7 0
#define C8 0
#define C9 0
#define C10 0
#define C11 0
#define C12 0
#define C13 0
#define C14 0
#define C15 0
// GPIO_Mode_Out_PP
// GPIO_Mode_Out_OD
// GPIO_Mode_IPU
// GPIO_Mode_IPD
/****GPIOD****/
/*Pin*/
#define D0 0
#define D1 0
#define D2 0
#define D3 0
#define D4 0
#define D5 0
#define D6 0
#define D7 0
#define D8 0
#define D9 0
#define D10 0
#define D11 0
#define D12 0
#define D13 0
#define D14 0
#define D15 0
// GPIO_Mode_Out_PP
// GPIO_Mode_Out_OD
// GPIO_Mode_IPU
//
/****EXTI****/
#define Line0 0
#define Line1 0
#define Line2 0
#define Line3 0
#define Line4 0
#define Line5 0
#define Line6 0
#define Line7 0
#define Line8 0
#define Line9 0
#define Line10 0
#define Line11 0
#define Line12 0
#define Line13 0
#define Line14 0
#define Line15 0
// EXTI_Trigger_Rising   EXTI_Trigger_Falling   EXTI_Trigger_Rising_Falling

/*************************UART_Configuration*************************/
// printf
#define printf_port USART1
// UART1
#define UART1_ENABLE 1
#define UART1_BoundRate 115200
#define UART1_ITFLAG 0
// UART2
#define UART2_ENABLE 0
#define UART2_BoundRate 9600
#define UART2_ITFLAG 0
/*****UART_IT_FLAG*****/
// USART_FLAG_CTS:  CTS Change flag (not available for UART4 and UART5)
// USART_FLAG_LBD:  LIN Break detection flag
// USART_FLAG_TXE:  Transmit data register empty flag
// USART_FLAG_TC:   Transmission Complete flag
// USART_FLAG_RXNE: Receive data register not empty flag
// USART_FLAG_IDLE: Idle Line detection flag
// USART_FLAG_ORE:  OverRun Error flag
// USART_FLAG_NE:   Noise Error flag
// USART_FLAG_FE:   Framing Error flag
// USART_FLAG_PE:   Parity Error flag

/*************************SysTick_Configuration*************************/
#define SysTick_EN 0
#define SysTick_Frequency 7200

/***************************I2C_Configuration***************************/
#define SDA_PORT GPIOA
#define SDA_PIN 6
#define SCL_PORT GPIOA
#define SCL_PIN 7

/***************************ADC_Configuration***************************/
#define ADC1_EN 1
#define ADC1_Mode ADC_Mode_Independent
#define ADC1_ExternalTrigConv ADC_ExternalTrigConv_None
#define ADC2_EN 0
#define ADC2_Mode 0
#define ADC2_ExternalTrigConv ADC_ExternalTrigConv_None
#define ADC3_EN 0
#define ADC3_Mode 0
#define ADC3_ExternalTrigConv ADC_ExternalTrigConv_None
#define Channel_0 0
#define Channel_1 1
#define Channel_2 0
#define Channel_3 0
#define Channel_4 0
#define Channel_5 0
#define Channel_6 0
#define Channel_7 0
#define Channel_8 0
#define Channel_9 0
#define Channel_10 0
#define Channel_11 0
#define Channel_12 0
#define Channel_13 0
#define Channel_14 0
#define Channel_15 0
/*ADC_Mode*/
/*
    ADC_Mode_Independent
    ADC_Mode_RegInjecSimult
    ADC_Mode_RegSimult_AlterTrig
    ADC_Mode_InjecSimult_FastInterl
    ADC_Mode_InjecSimult_SlowInterl
    ADC_Mode_InjecSimult
    ADC_Mode_RegSimult
    ADC_Mode_FastInterl
    ADC_Mode_SlowInterl
    ADC_Mode_AlterTrig
*/
/*ADC_ExternalTrigConv*/
/*
ADC_ExternalTrigConv_T1_CC1                 //!< For ADC1 and ADC2
ADC_ExternalTrigConv_T1_CC2                 //!< For ADC1 and ADC2
ADC_ExternalTrigConv_T2_CC2                 //!< For ADC1 and ADC2
ADC_ExternalTrigConv_T3_TRGO                //!< For ADC1 and ADC2
ADC_ExternalTrigConv_T4_CC4                 //!< For ADC1 and ADC2
ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO     //!< For ADC1 and ADC2

ADC_ExternalTrigConv_T1_CC3                 //!< For ADC1, ADC2 and ADC3
ADC_ExternalTrigConv_None                   //!< For ADC1, ADC2 and ADC3

ADC_ExternalTrigConv_T3_CC1                 //!< For ADC3 only
ADC_ExternalTrigConv_T2_CC3                 //!< For ADC3 only
ADC_ExternalTrigConv_T8_CC1                 //!< For ADC3 only
ADC_ExternalTrigConv_T8_TRGO                //!< For ADC3 only
ADC_ExternalTrigConv_T5_CC1                 //!< For ADC3 only
ADC_ExternalTrigConv_T5_CC3                 //!< For ADC3 only
*/

/***************************TIM_Configuration***************************/
#define TIM1_EN 0
#define TIM1_Period 1000
#define TIM1_IT 0
/*
#define TIM1_CounterMode TIM_CounterMode_Up
#define TIM1_ch1_Mode
#define TIM1_ch1_Pulse
#define TIM1_ch1_Polarity
#define TIM1_ch2_Mode
#define TIM1_ch2_Pulse
#define TIM1_ch2_Polarity
#define TIM1_ch3_Mode
#define TIM1_ch3_Pulse
#define TIM1_ch3_Polarity
#define TIM1_ch4_Mode
#define TIM1_ch4_Pulse
#define TIM1_ch4_Polarity*/
#define TIM2_EN 0
#define TIM2_Period 1000
#define TIM2_IT 0
#define TIM3_EN 0
#define TIM3_Period 1000
#define TIM3_IT 0

#endif
