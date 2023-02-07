#include "stdint.h"
#include "../Status/status.h"
#include "gpio.h"
#include "../Timer/timer.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == Key_Up_Pin)
	{
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Up);		
	}	
	else if(GPIO_Pin == Key_Down_Pin)
	{
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Down);	
	}	
	else if(GPIO_Pin == Key_Mid_Pin)
	{	
//		__HAL_TIM_SET_AUTORELOAD(&htim6, 1500000);
//		__HAL_TIM_SET_COUNTER(&timer, 0);
//		__HAL_TIM_ENABLE(&htim6);
		
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Mid);	
	}	
	else if(GPIO_Pin == Key_Left_Pin)
	{
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Left);	
	}	
	else if(GPIO_Pin == Key_Right_Pin)
	{
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Right);
	}
	timer_spy_reset();
	timer_spy_run();
}