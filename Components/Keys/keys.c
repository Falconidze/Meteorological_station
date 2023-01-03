#include "stdint.h"
#include "../Status/status.h"
#include "gpio.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == Key_Up_Pin)
	{
		status_set(status_get() | Status_Key_Up);
	}	
	else if(GPIO_Pin == Key_Down_Pin)
	{
		status_set(status_get() | Status_Key_Down);
	}	
	else if(GPIO_Pin == Key_Mid_Pin)
	{
		status_set(status_get() | Status_Key_Mid);
	}	
	else if(GPIO_Pin == Key_Left_Pin)
	{
		status_set(status_get() | Status_Key_Left);
	}	
	else if(GPIO_Pin == Key_Right_Pin)
	{
		status_set(status_get() | Status_Key_Right);
	}
}