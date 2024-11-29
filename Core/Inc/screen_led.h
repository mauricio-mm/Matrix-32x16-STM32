#ifndef SCREEN_LED
#define SCREEN_LED


// #include "main.h"
#include "main.h"
#include <math.h>

#define TEMPO_LEDS_MATRIZ 15

#define E_0 GPIOC->BRR=1<<7
#define E_1 GPIOC->BSRR=1<<7
#define RS_0 GPIOA->BRR=1<<9
#define RS_1 GPIOA->BSRR=1<<9

#define pinoA_1 GPIOB->BSRR=1<<15
#define pinoA_0 GPIOB->BRR=1<<15

#define pinoB_1 GPIOB->BSRR=1<<13
#define pinoB_0 GPIOB->BRR=1<<13

#define pinoC_1 GPIOB->BSRR=1<<14
#define pinoC_0 GPIOB->BRR=1<<14

#define pinoBD_0 GPIOB->BRR=1<<2
#define pinoBD_1 GPIOB->BSRR=1<<2

#define pinoBU_0 GPIOA->BRR=1<<11
#define pinoBU_1 GPIOA->BSRR=1<<11

#define pinoGD_0 GPIOB->BRR=1<<1
#define pinoGD_1 GPIOB->BSRR=1<<1

#define pinoGU_0 GPIOB->BRR=1<<12
#define pinoGU_1 GPIOB->BSRR=1<<12

#define pinoRD_0 GPIOB->BRR=1<<11
#define pinoRD_1 GPIOB->BSRR=1<<11

#define pinoRU_0 GPIOA->BRR=1<<12
#define pinoRU_1 GPIOA->BSRR=1<<12

#define MATRIZCLK_1 GPIOB->BSRR=1<<9
#define MATRIZCLK_0 GPIOB->BRR=1<<9

#define pinoOE_0 GPIOB->BRR=1<<8
#define pinoOE_1 GPIOB->BSRR=1<<8

#define pinoSTB_0 GPIOC->BRR=1<<9
#define pinoSTB_1 GPIOC->BSRR=1<<9

#define LED_WIDTH 32
#define LED_HEIGHT 16

typedef struct
{	
    uint8_t axis[16][32];

}SCREEN;

void screen_init(SCREEN *screen);
void draw_screen(SCREEN *screen);
void clear_screen(SCREEN *screen);
void draw_screen_line(SCREEN *screen, uint8_t linha);

void drawPixel(SCREEN *screen, uint8_t Xaxis, uint8_t Yaxis, uint8_t color);
void set_line(SCREEN *screen, uint8_t linha, uint8_t coluna);
void get_line(uint8_t linha);
void clean_line(uint8_t linha);
void delayUs(uint8_t time);

void drawLine(SCREEN *screen, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void drawRectangle(SCREEN *screen, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color);
void drawLetter(SCREEN *screen, uint8_t letter[][4], uint8_t x, uint8_t y);

#endif