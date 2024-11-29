/*
 * display_lcd.c
 *
 *  Created on: May 24, 2024
 *      Author: Mauricio
 */

#include "display_lcd.h"

void lcd_init(uint8_t cursor)
{    
    lcd_wrcom(DISPLAY_4BITS);
    lcd_wrcom(DISPLAY_5X7);
    lcd_wrcom(DISPLAY_CLEAR);    
    lcd_wrcom(cursor);

    delayus(20);  
    lcd_clear();

}

void lcd_wrcom(uint8_t com)
{
    lcd_out((com >> 4));
    RS_0;
    E_1;    
    delayus(5);
    E_0;    
    HAL_Delay(5);

    lcd_out((com & 0x0f));
    RS_0;
    E_1;    
    delayus(5);
    E_0;    
    HAL_Delay(5);
}

void lcd_wrchar(char ch)
{
    lcd_out((ch >> 4));
    RS_1;
    E_1;
    delayus(10);
    E_0;
    HAL_Delay(5);
    
    lcd_out((ch & 0x0f));
    RS_1;    
    E_1;
    delayus(10);
    E_0;
    HAL_Delay(5);
}

void lcd_goto(uint8_t x, uint8_t y)
{   
    uint8_t com = 0x80;

    if(y == 0) com = 0x80 + x;
    if(y == 1) com = 0xc0 + x;
    lcd_wrcom(com);    
}

void lcd_progchar(uint8_t *nchar)
{
    lcd_wrchar(0x40);
    for(int i = 0;i < 24;i++)
        lcd_wrchar(nchar[i]);
    lcd_wrcom(CURSOR_BEG_FIRST_LINE);
}

void lcd_wrstr(char *str)
{
    while (*str)
    {   
        lcd_wrchar(*(str++)); 
        delayus(10);       
    }    
}

void lcd_clear(void)
{
    lcd_wrcom(DISPLAY_CLEAR);
    lcd_wrcom(CURSOR_BEG_FIRST_LINE);
}

void lcd_backlight(uint8_t backlight)
{
    if(backlight != false)
    {
        BACKLIGHT_1;
    }else BACKLIGHT_0;
    
}

void lcd_out(uint8_t com)
{
    if((com & (1 << 0)) != 0)  GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5);
    if((com & (1 << 1)) != 0)  GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4);
    if((com & (1 << 2)) != 0)  GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10);
    if((com & (1 << 3)) != 0)  GPIOA->BSRR = (1 << 8); else GPIOA->BRR = (1 << 8);
}

void delayus(int time)
{
    do
    {
        time--;
    } while (time == 0);

    return;        
    
}
