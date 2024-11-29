/*
 * display_lcd.h
 *
 *  Created on: May 24, 2024
 *      Author: Mauricio
 */

#ifndef DISPLAY_LCD_H
#define DISPLAY_LCD_H

#include "main.h"
#include "stdint.h"
#include "stdbool.h"

#define DISPLAY_4BITS           0x02
#define DISPLAY_5X7             0x28
#define DISPLAY_CLEAR           0x01

#define RETURN_HOME             0x02
#define DISPLAY_2LINES          0x38
#define ACTIVE_SECOND_LINE      0x3c
#define DISPLAY_CURSOR_OFF      0x08

#define DECR_CURSOR             0x04
#define SHIFT_DISPLAY_R         0x05    
#define INCR_CURSOR             0x06
#define SHIFT_DISPLAY_L         0x07

#define CURSOR_BEG_FIRST_LINE   0x80
#define CURSOR_OFF              0x0c
#define CURSOR_ON               0x0e
#define CURSOR_BLINK            0x0f

#define E_0             GPIOC->BRR  = 1 << 7
#define E_1             GPIOC->BSRR = 1 << 7
#define RS_0            GPIOA->BRR  = 1 << 9
#define RS_1            GPIOA->BSRR = 1 << 9

#define BACKLIGHT_0     GPIOB->BRR  = 1 << 7
#define BACKLIGHT_1     GPIOB->BSRR = 1 << 7

void lcd_wrcom(uint8_t com);
void lcd_init(uint8_t cursor);
void lcd_wrchar(char ch);
void lcd_goto(uint8_t x, uint8_t y);
void lcd_progchar(uint8_t *nchar);
void lcd_wrstr(char *str);
void lcd_clear(void);
void lcd_backlight(uint8_t backlight);
void lcd_out(uint8_t data);

void delayus(int time);
#endif /* INC_DISPLAY_LCD_H_ */
