#ifndef __MY_INIT_H
#define __MY_INIT_H

#include "stm32f10x.h"
#include "UART.h"
#include "GPIO.h"
#include "SYSTIC.h"
#include "I2C.h"
#include "TIM.h"
#include "ADC.h"
#include "MPU6050.h"

void BSP_GPIO_Init(void);
void stm32f103_config(void);
void SysTick_Init(void);
void UART_Config(void);
void ADC_Configuration(void);
void TIM_Init(void);

#endif
