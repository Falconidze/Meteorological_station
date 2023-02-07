#include "mode_settings.h"
#include "../Ui/ui.h"
#include "../Lcd/lcd.h"
#include "tim.h"
#include "string.h"
#include "stdio.h"

void mode_settings_draw(uint8_t page)
{
	char str[5] = {};
	uint8_t state = 0;
	uint16_t symbol;
	switch(ui_get_page())
		{
		case 0:
			lcd_clear();	
			lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);					
			symbol = 0x3E;
			lcd_write_string(&symbol, 1);
			lcd_set_cursor(0, 1);
			lcd_write_string((uint8_t *)"   SETTINGS MENU", 12);
			lcd_set_cursor(1, 1);
			lcd_write_string((uint8_t *)"To move press  ", 15);
			symbol = 0xD9;
			lcd_set_cursor(1, 14);
			lcd_write_string(&symbol, 1);
			symbol = 0xDA;
			lcd_write_string(&symbol, 1);
			break;
		
		case 1:
			if(status_get() == Status_Key_Left && TIM1-> CCR1 > 0x00 && ui_get_cursor().y == 1)
				{
					TIM1->CCR1 = TIM1->CCR1 - 0x100;
				}
				else if (status_get() == Status_Key_Right && TIM1-> CCR1 < 0x400 && ui_get_cursor().y == 1)
				{
					TIM1->CCR1 = TIM1->CCR1 + 0x100;
				}
			lcd_clear();
			lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);
			symbol = 0x3E;
			lcd_write_string(&symbol, 1);
			lcd_set_cursor(0, 1);
			lcd_write_string((uint8_t *)"  Brightness", 12);
			lcd_set_cursor(1, 3);
			symbol = TIM1->CCR1;
			sprintf(str, "%i", symbol);
			lcd_write_string((uint8_t *)&str, strlen(str));	
			break;
//		
//		case 2:
//			lcd_clear();
//			lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);
//			symbol = 0x3E;
//			lcd_write_string(&symbol, 1);
//			lcd_set_cursor(0, 1);
//			lcd_write_string((uint8_t *)"To confirm", 10);
//			lcd_set_cursor(1, 1);
//			lcd_write_string((uint8_t *) "Press mid key", 13);
//			break;
//		
//		case 3:
//		 lcd_clear(); 
//		 lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);     
//		 symbol = 0x3E;
//		 lcd_write_string(&symbol, 1);
//		 break;
		}
}