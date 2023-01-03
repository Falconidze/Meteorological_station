#include "stdint.h"
#include "../Status/status.h"
#include "ui.h"

static ui_s_t ui;

void ui_init()
{
	ui.page = 0;
	ui.cursor.x = 0;
	ui.cursor.y = 0;
}


void ui_set_cursor(uint8_t data_x, uint8_t data_y)
{
	ui.cursor.x = data_x;
	ui.cursor.y = data_y;
}

cursor_s_t ui_get_cursor(void)
{	
	return ui.cursor;
}

void ui_set_page(uint8_t data)
{
	ui.page = data;
}

uint8_t ui_get_page(void)
{
	return ui.page;
}
