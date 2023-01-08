#include "stdint.h"
#include "../Status/status.h"
#include "../Lcd/lcd.h"
#include "modes.h"
#include "gpio.h"
#include "../Timer/timer.h"
#include "../Ui/ui.h"

static uint8_t mode;

void mode_init()
	{
		mode = 0x08;
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
	uint8_t choice = 0x10;	
	lcd_clear();
	lcd_set_cursor(0, 1);
	lcd_write_string((uint8_t *)"Choose mode:", 12);
	lcd_set_cursor(1, 1);
	lcd_write_string((uint8_t *)"Current data", 12);
	HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_RESET);
	
	while(Mode_Choice)
	{		
		if (status_get() == (Status_Key_Up) && choice < 0x80)
		{
			choice <<= 1;
			lcd_clear();
			lcd_set_cursor(0, 1);
			lcd_write_string((uint8_t *)"Choose mode:", 12);
			lcd_set_cursor(1, 1);
			
			if (choice == 0x10)
				{
					lcd_write_string((uint8_t *)"Current data", 12);
				}
			else if (choice == 0x20)
				{
					lcd_write_string((uint8_t *)"Saved data", 10);
				}
			else if (choice == 0x40)
				{
					lcd_write_string((uint8_t *)"Help", 4);
				}
			else if (choice == 0x80)
				{
					lcd_write_string((uint8_t *)"Settings", 8);
				}			
				status_set(0x0000);
		}
		
		else if (status_get() == (Status_Key_Down) && choice > 0x10)
		{
			choice >>= 1;
			lcd_clear();
			lcd_set_cursor(0, 1);
			lcd_write_string((uint8_t *)"Choose mode:", 12);
			lcd_set_cursor(1, 1);
			
			if (choice == 0x10)
				{
					lcd_write_string((uint8_t *)"Current data", 12);
				}
			else if (choice == 0x20)
				{
					lcd_write_string((uint8_t *)"Saved data", 10);
				}
			else if (choice == 0x40)
				{
					lcd_write_string((uint8_t *)"Help", 4);
				}
			else if (choice == 0x80)
				{
					lcd_write_string((uint8_t *)"Settings", 8);
				}					
				status_set(0x0000);
		}
		
		else if (status_get() == (Status_Key_Mid))
		{
			mode_set(choice);
			status_set(0x0000);
			break;
		}		
	}
	
}


void mode_help_run()
{
	ui_set_page(0);
	ui_set_cursor(0, 0);
	lcd_clear();
	lcd_set_cursor(0, 0);
	uint8_t symbol;
	lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);					
	symbol = 0x3E;
	lcd_write_string(&symbol, 1);
	lcd_set_cursor(0, 1);
	lcd_write_string((uint8_t *)"   HELP MENU", 12);
	lcd_set_cursor(1, 1);
	lcd_write_string((uint8_t *)"To move press  ", 15);
	symbol = 0xD9;
	lcd_set_cursor(1, 14);
	lcd_write_string(&symbol, 1);
	symbol = 0xDA;
	lcd_write_string(&symbol, 1);
	HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);	
	
	while(Mode_Help)
	{
		if (status_get() == Status_Key_Up)
			{
			if(ui_get_cursor().y == 1)
				{
					ui_set_cursor(0, 0);
				}
			else if (ui_get_cursor().y == 0)
				{
					ui_set_page(ui_get_page() - 1);
					ui_set_cursor(0, 1);
				}
			}
			else if(status_get() == Status_Key_Down)
				{
					if(ui_get_cursor().y == 0)
					{
						ui_set_cursor(0, 1);
					}
					else if (ui_get_cursor().y == 1)
					{
						ui_set_page(ui_get_page() + 1);
						ui_set_cursor(0, 0);
					}
				}
					
			switch(ui_get_page())
			{
				case(0):
					lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);					
					symbol = 0x3E;
					lcd_write_string(&symbol, 1);
					lcd_set_cursor(0, 1);
					lcd_write_string((uint8_t *)"   HELP MENU", 12);
					lcd_set_cursor(1, 1);
					lcd_write_string((uint8_t *)"To move press  ", 15);
					symbol = 0xD9;
					lcd_set_cursor(1, 14);
					lcd_write_string(&symbol, 1);
					symbol = 0xDA;
					lcd_write_string(&symbol, 1);
				break;
				default:
					ui_set_page(0);
					ui_set_cursor(0,0);
				break;
			}	
		if (status_get() == (Status_Key_Mid))
		{
			mode_set(Mode_Choice);
			status_set(0x0000);
			break;
		}
	}
}

void mode_settings_run()
{
	ui_set_page(0);
	ui_set_cursor(0, 0);
	lcd_clear();
	lcd_set_cursor(0, 0);
	lcd_write_string((uint8_t *)"Tipo settings", 13);		
	HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
	
	while(Mode_Settings)
	{			
					
		if (status_get() == (Status_Key_Mid))
		{
			mode_set(Mode_Choice);
			status_set(0x0000);
			break;
		}
	}
}

void mode_current_data_run()
{
	lcd_clear();
	lcd_set_cursor(0, 0);
	lcd_write_string((uint8_t *)"16", 2);
	uint8_t symbol = 0xEF;
	lcd_write_string(&symbol, 1);
	lcd_write_string((uint8_t *)"celsium", 7);
	HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
	
	while(Mode_Current_Data)
	{		
		if (status_get() == (Status_Key_Mid))
		{
			mode_set(Mode_Choice);
			status_set(0x0000);
			break;
		}
	}
}

void mode_saved_data_run()
{
	lcd_clear();
	lcd_set_cursor(0, 0);
	lcd_write_string((uint8_t *)"menshe degrees", 14);
	HAL_GPIO_WritePin(Debug_LED_GPIO_Port, Debug_LED_Pin, GPIO_PIN_SET);
	
	while(Mode_Saved_Data)
	{		
		if (status_get() == (Status_Key_Mid))
		{
			mode_set(Mode_Choice);
			status_set(0x0000);
			break;
		}
	}
}