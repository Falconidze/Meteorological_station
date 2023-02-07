#ifndef TIMER_H
#define TIMER_H

#include "stdint.h"

void timer_delay_us(uint16_t time);

void timer_spy_run();
void timer_spy_reset();
void timer_spy_stop();
void timer_spy_init();

void timer_dht_init();
#endif /* LCD_H */
