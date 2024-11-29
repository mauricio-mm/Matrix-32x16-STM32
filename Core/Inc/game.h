#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "screen_led.h"
#include "patterns.h"
#include "display_lcd.h"
#include "joystick.h"

#define FRAME_RATE 10

static const uint8_t boss[8][11] =
{
    {0,0,1,0,0,0,0,0,1,0,0},
    {0,0,0,1,0,0,0,1,0,0,0},
    {0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,0,1,1,1,0,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,1},
    {0,0,0,1,1,0,1,1,0,0,0}
};

static const uint8_t nave[3][5] =
{
    {0,0,1,0,0},
	{0,1,1,1,0},
	{1,1,1,1,1}
};

typedef struct
{
    uint8_t x;
    uint8_t y;

}POSITION;

typedef struct
{   
    POSITION *position;     
    uint8_t life;
         
}NAVE;

typedef struct
{
    SCREEN *screen;
    NAVE *nave;
    
}GAME;



void game_init(GAME *game, JOYSTICK *joystick);

int start_game(GAME *game ,uint8_t delta);
int play_game(GAME *game, NAVE *nave, uint8_t delta);
void drawBoss(SCREEN *screen, uint8_t boss[][11], uint8_t x, uint8_t y);

#endif
