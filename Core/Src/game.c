
#include "game.h"

void game_init(GAME *game, JOYSTICK *joystick)
{   

  if(joystick->x >= 4000 && game->nave->position->x < 32)    
    ++game->nave->position->x;

  if(joystick->x <= 200 && game->nave->position->x > 0)
    --game->nave->position->x;

  if(joystick->y >= 4000 && game->nave->position->y > 0)
    --game->nave->position->y;

  if(joystick->y <= 200 && game->nave->position->y < 15)
    ++game->nave->position->y;

  printf("Y: %i  || %i\n", game->nave->position->y, game->nave->position->x);
  printf("Joystick Y: %i  || Joystick X: %i\n", joystick->y, joystick->x);

  clear_screen(game->screen);
  drawBoss(game->screen, boss, game->nave->position->x, game->nave->position->y);
  draw_screen(game->screen);   
  
}

int start_game(GAME *game, uint8_t delta)
{
    uint8_t radius = 0;

    clear_screen(&(game->screen));
    drawLetter(&(game->screen), G, (LED_WIDTH/5), LED_HEIGHT/3);
    drawLetter(&(game->screen), A, (LED_WIDTH/5) + 5, LED_HEIGHT/3);
    drawLetter(&(game->screen), M, (LED_WIDTH/5) + 10, LED_HEIGHT/3);
    drawLetter(&(game->screen), E, (LED_WIDTH/5) + 15, LED_HEIGHT/3);
    
    drawCircle(&(game->screen), LED_WIDTH/2, LED_HEIGHT/2, radius, 0x07);

    if(delta == 0)
    {
        if(radius <= LED_HEIGHT)
        {
            radius++; 
        }else radius = 0;
    }

    return 0;
}

int play_game(GAME *game, NAVE *nave,uint8_t delta)
{
    clear_screen(game->screen);
    
    //drawPixel(game->screen,nave->position->x, nave->position->>y, 0x03);
}

void drawBoss(SCREEN *screen, uint8_t boss[][11], uint8_t x, uint8_t y)
{
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 11; j++) 
		{
      if (i + y < 16 && j + x < 32)
      {
          screen->axis[i + y][j + x] = boss[i][j] * 0x02;
      }
		}
	}
}
