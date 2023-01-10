#include "mode_help.h"
#include "../Ui/ui.h"
#include "../Lcd/lcd.h"


void mode_help_draw(uint8_t page)
{
	uint8_t symbol; 
	uint8_t page_check;
	switch(ui_get_page())
		{
		case 0:
			page_check = 0;
			lcd_clear();	
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
		
		case 1:
			lcd_clear();
			lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);
			symbol = 0x3E;
			lcd_write_string(&symbol, 1);
			lcd_set_cursor(0, 1);
			lcd_write_string((uint8_t *)"In choice mode:", 15);
			lcd_set_cursor(1, 1);
			symbol = 0xD9;
			lcd_write_string(&symbol, 1);
			symbol = 0xDA;
			lcd_write_string(&symbol, 1);
			lcd_write_string((uint8_t *)" Mode select", 12);
			break;
		case 2:
			lcd_clear();
			lcd_set_cursor(ui_get_cursor().y, ui_get_cursor().x);
			symbol = 0x3E;
			lcd_write_string(&symbol, 1);
			lcd_set_cursor(0, 1);
			lcd_write_string((uint8_t *)"In choice mode:", 15);
			lcd_set_cursor(1, 1);
			break;
		
		default:
			ui_set_page(0);
			ui_set_cursor(0,0);
			lcd_clear();			
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
		}
}