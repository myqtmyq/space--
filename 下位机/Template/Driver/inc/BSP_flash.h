#ifndef __BSP_FLASH_H
#define __BSP_FLASH_H
#include "stm32f10x.h"
#include "BSP_spi.h"

// w25x command
#define writeEnable 0x06
#define writeDisable 0x04
#define readStatusReg 0x05
#define writeStatusReg 0x01
#define readData 0x03
#define fastRead 0x0B
#define FRDO 0x3B
#define pageEdit 0x02
#define blockErase 0xD8
#define sectorErase 0x20
#define chipErase 0xC7
#define powerFail 0xB9
#define freePF_componetID 0xAB
#define makeID 0x90
#define JEDEC_ID 0x9F

// cs macro define
#define flashCS_ENABLE() *(volatile uint32_t *)(GPIOC_BASE + 0x10) = GPIO_Pin_13;
#define flashCS_DISABLE() *(volatile uint32_t *)(GPIOC_BASE + 0x14) = GPIO_Pin_13;
#endif