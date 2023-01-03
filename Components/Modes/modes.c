#include "stdint.h"
#include "../Status/status.h"
#include "../Lcd/lcd.h"
#include "modes.h"
#include "gpio.h"
#include "../Timer/timer.h"

static uint8_t mode;

void mode_init()
	{
		mode = 0x04;
	}

void mode_set(uint8_t data)
	{
		mode = data;
	}
	
	
uint8_t mode_get()
	{
		return mode;
	}

void mode_choice_run()
{
	lcd_clear();
	lcd_set_cursor(0, 0);
	lcd_write_string((uint8_t *)"Choose your mode", 16);
	HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_RESET);
	while(Mode_Choice)
	{		
		if (status_get() == (Status_Key_Up))
		{
			mode_set(Mode_Help);
			status_set(0x0000);
			break;
		}
	}
}


void mode_help_run()
{
	lcd_clear();
	lcd_set_cursor(0, 0);
	lcd_write_string((uint8_t *)"    Help test", 13);		
	HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
	
	while(Mode_Help)
	{		
		if (status_get() == (Status_Key_Mid))
		{
			mode_set(Mode_Choice);
			status_set(0x0000);
			break;
		}
	}
}