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
		timer_delay_us(4000);
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_RESET);
	}	
	else if(GPIO_Pin == Key_Down_Pin)
	{
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Down);
		timer_delay_us(4000);
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_RESET);
	}	
	else if(GPIO_Pin == Key_Mid_Pin)
	{	
//		__HAL_TIM_SET_AUTORELOAD(&htim6, 1500000);
//		__HAL_TIM_SET_COUNTER(&timer, 0);
//		__HAL_TIM_ENABLE(&htim6);
//		
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Mid);
		timer_delay_us(4000);
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_RESET);
	}	
	else if(GPIO_Pin == Key_Left_Pin)
	{
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Left);
		timer_delay_us(4000);
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_RESET);
	}	
	else if(GPIO_Pin == Key_Right_Pin)
	{
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
		status_set(status_get() | Status_Key_Right);
		timer_delay_us(4000);
		HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_RESET);
	}
	Timer10_Reset;
	Timer10_Start;
}