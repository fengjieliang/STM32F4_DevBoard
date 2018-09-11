#ifndef BSP_LED_H
#define BSP_LED_H

#include "main.h"
#include "stm32f4xx_hal.h"

enum LED_Num
{
	BSP_LED_0=LED0_Pin,
	BSP_LED_1=LED1_Pin
};

void BSP_LED_ON(enum LED_Num led_num);
void BSP_LED_OFF(enum LED_Num led_num);
void BSP_LED_Toggle(enum LED_Num led_num);
void BSP_LED_Blink(enum LED_Num led_num, uint16_t BlinkTimes, uint16_t delay);











#endif
