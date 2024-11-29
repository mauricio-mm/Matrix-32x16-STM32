#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "main.h"

typedef struct
{
    int x;
    int y;

}JOYSTICK;

int joystick_init(ADC_HandleTypeDef *hadc, uint8_t channel);

#endif