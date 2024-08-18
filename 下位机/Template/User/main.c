#define __HANDLE_GLOBALS
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "Systick.h"
#include "Can.h"
#include "Canopen.h"
#include "Pump.h"
#include "UART.h"
#include "Handle.h"


//配方
//单位 ml
#define Conponent1 1
#define Conponent2 0
#define Conponent3 0

//100 0.01rpm/51200 pulse一圈
//0.125ml/圈
#define conv 433067

int main()
{
    SystemCLK_Config();
    usart1Init();
    protocolInit(&protocolData_t);
    delay(100);
	/*
    Pump_Init(0x01);
    delay(1000);
    Pump_Init(0x02);
    delay(1000);
    Pump_Init(0x03);
    delay(2000);
	*/
    Pump_Init(0x01);
    delay(1000);
    Pump_Init(0x02);
    delay(1000);
    Pump_Init(0x03);
    delay(1000);
	
	
	Pump_Location(1,Conponent1*conv);
    delay(50);
	Pump_Location(2,Conponent2*conv);
    delay(50);
	Pump_Location(3,Conponent3*conv);
    delay(50);
	
	
	Pump_Zero(1);
    delay(50);
	Pump_Zero(2);
    delay(50);
	Pump_Zero(3);
    delay(50);
		
		
    Pump_Start(0x01);
    delay(50);
    Pump_Start(0x02);
    delay(50);
    Pump_Start(0x03);
    delay(50);
	
    while (1)
    {
		/*
        Pump_Start(0x01);
        delay(2000);
        Pump_Start(0x02);
        delay(2000);
        Pump_Start(0x03);
        delay(30000);
        Pump_Stop(0x01);
        delay(2000);
        Pump_Stop(0x02);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        delay(2000);
        Pump_Stop(0x03);
        delay(10000);
		*/
    }
}
