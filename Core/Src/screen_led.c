
#include "screen_led.h"

void screen_init(SCREEN *screen)
{
	MATRIZCLK_0;
	pinoSTB_0;
	pinoOE_0;    
	
	HAL_Delay(10);
	
	clear_screen(screen);

}	

void draw_screen(SCREEN *screen)
{	
	for(uint8_t y = 0; y < 8; y++)
	{
		draw_screen_line(screen,y);		
		clean_line(y);	
	}
}

void clear_screen(SCREEN *screen)
{
	for (uint8_t y = 0; y < 16; y++)
	{
		for(uint8_t x = 0;x < 32;x++)
		{		
			drawPixel(screen, x, y, 0x00);
		}		
	}

	for(uint8_t y = 0; y < 8; y++){	
		clean_line(y);
	}
}

void draw_screen_line(SCREEN *screen, uint8_t linha)
{	 
	for(uint8_t x = 0; x < 32; x++){
		set_line(screen, linha,x);
	}

	MATRIZCLK_1;		
	__NOP();
	MATRIZCLK_0;
	

}

void clean_line(uint8_t linha)
{	 
	for(uint8_t k = 0; k <32; k++){
		pinoOE_1;
		pinoSTB_0;

		pinoRU_0;
		pinoRD_0;
		pinoGU_0;
		pinoGD_0;
		pinoBU_0;
		pinoBD_0;

		get_line(linha);

		pinoOE_0;
		pinoSTB_1;		
		delayUs(TEMPO_LEDS_MATRIZ);	
	}

	MATRIZCLK_1;	
	__NOP();
	MATRIZCLK_0;	
}

void set_line(SCREEN *screen, uint8_t linha, uint8_t coluna)
{
	pinoOE_1;
	pinoSTB_0;	

	pinoRU_0;
	pinoRD_0;
	pinoGU_0;
	pinoGD_0;
	pinoBU_0;
	pinoBD_0;
	
	get_line(linha);			

	if( (screen->axis[linha][coluna] & (1 << 0)) != 0 ) pinoRU_1;

	if( (screen->axis[linha + 8][coluna] & (1 << 0)) != 0 )	pinoRD_1;
	
	if( (screen->axis[linha][coluna] & (1 << 1)) != 0 )	pinoGU_1;
	
	if( (screen->axis[linha + 8][coluna] & (1 << 1)) != 0 ) pinoGD_1;	

	if( (screen->axis[linha][coluna] & (1 << 2)) != 0 ) pinoBU_1;
		
	if( (screen->axis[linha + 8][coluna] & (1 << 2)) != 0 ) pinoBD_1;
	
	delayUs(TEMPO_LEDS_MATRIZ);
	pinoOE_0;
	pinoSTB_1;
	delayUs(TEMPO_LEDS_MATRIZ);

}

void get_line(uint8_t linha)
{
	pinoA_0;
	pinoB_0;
	pinoC_0;

	if(( linha & (1<<0)) != 0 ) pinoA_1;

	if(( linha & (1<<1)) != 0 ) pinoB_1;

	if(( linha & (1<<2)) != 0 ) pinoC_1;
}

void drawPixel(SCREEN *screen, uint8_t Xaxis, uint8_t Yaxis, uint8_t color)
{	
	screen->axis[Yaxis][Xaxis] = color;
}

void delayUs(uint8_t time)
{
    do
    {
        time--;
    } while (time > 0);
    
}

void drawLine(SCREEN *screen, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color) 
{	    
	int x = x1;
    int y = y1;
    int err = 0;
	int dx = x2 - x1;
    int dy = y2 - y1;
    int incX, incY;	

    if (dx >= 0) {
        incX = 1;
    } else {
        incX = -1;
        dx = -dx;
    }

    if (dy >= 0) {
        incY = 1;
    } else {
        incY = -1;
        dy = -dy;
    }

    if (dx > dy) {
        for (int i = 0; i <= dx; i++) {
            drawPixel(screen, x, y, color);
            x += incX;
            err += 2 * dy;
            if (err > dx) {
                y += incY;
                err -= 2 * dx;
            }
        }
    } else {
        for (int i = 0; i <= dy; i++) {
            drawPixel(screen, x, y, color);
            y += incY;
            err += 2 * dx;
            if (err > dy) {
                x += incX;
                err -= 2 * dy;
            }
        }
    }
}

void drawRectangle(SCREEN *screen, uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color)
{    
    drawLine(screen, x, y, x + width - 1, y, color);
    drawLine(screen, x, y, x, y + height - 1, color);
    drawLine(screen, x + width - 1, y, x + width - 1,y + height - 1, color);
    drawLine(screen, x, y + height - 1, x + width - 1, y + height - 1, color);
}

void drawCircle(SCREEN *screen, uint8_t centerX, uint8_t centerY, uint8_t radius, uint8_t color) 
{        
    int r_squared = radius * radius;

    for (int x = centerX - radius; x <= centerX + radius; x++) {
        for (int y = centerY - radius; y <= centerY + radius; y++) {
            int distance_squared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
            if (distance_squared <= r_squared && distance_squared >= (r_squared *0.8)) {
                drawPixel(screen, (uint8_t)x, (uint8_t)y, color);
            }
        }
    }
}

void drawLetter(SCREEN *screen, uint8_t letter[][4], uint8_t x, uint8_t y)
{
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (i + y < 5 && j + x < 4)
			{
				screen->axis[i + y][j + x] = letter[i][j] * 0x02;
			}
		}
	}
}
