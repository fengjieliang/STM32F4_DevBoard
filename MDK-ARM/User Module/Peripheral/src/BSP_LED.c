#include "bsp_led.h"


void BSP_LED_ON(enum LED_Num led_num)
{
	HAL_GPIO_WritePin(GPIOF,led_num,GPIO_PIN_RESET);
}


void BSP_LED_OFF(enum LED_Num led_num)
{
	HAL_GPIO_WritePin(GPIOF,led_num,GPIO_PIN_SET);
}




void BSP_LED_Toggle(enum LED_Num led_num)
{
	HAL_GPIO_TogglePin(GPIOF,led_num);
}


void BSP_LED_Blink(enum LED_Num led_num, uint16_t BlinkTimes, uint16_t delay)
{
	for(int i=BlinkTimes;i>0;i--)
	{
		BSP_LED_Toggle(led_num);
		HAL_Delay(delay);
		BSP_LED_Toggle(led_num);
		HAL_Delay(delay);
	}
	
}



