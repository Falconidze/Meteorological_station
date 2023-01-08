#ifndef TIMER_H
#define TIMER_H

#include "stdint.h"

#define Timer10_Stop TIM10->CR1 &= 0x00
#define Timer10_Reset TIM10->CNT &= 0x00
#define Timer10_Start TIM10->CR1 |= 0x01

void timer_delay_us(uint16_t time);

#endif /* LCD_H */
