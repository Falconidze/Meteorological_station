#ifndef UI_H
#define UI_H

#include "stdint.h"
typedef struct{
	uint8_t x;
	uint8_t y;
}cursor_s_t;

typedef struct{	
	uint8_t page;
	cursor_s_t cursor;
}ui_s_t;


void ui_init();
void ui_set_cursor(uint8_t data_x, uint8_t data_y);
cursor_s_t ui_get_cursor(void);
void ui_set_page(uint8_t data);
uint8_t ui_get_page(void);

#endif /* UI_H */