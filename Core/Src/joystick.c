#include "joystick.h"

int joystick_init(ADC_HandleTypeDef *hadc, uint8_t channel)
{   
    ADC_ChannelConfTypeDef adc_s_config;
    int value;

    adc_s_config.Rank = ADC_RANK_CHANNEL_NUMBER;
    adc_s_config.Channel = channel;
    while(HAL_ADC_Init(hadc) != HAL_OK) HAL_Delay(1);
    while(HAL_ADC_ConfigChannel(hadc, &adc_s_config) != HAL_OK) HAL_Delay(1);

    HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, 1000);

    value = HAL_ADC_GetValue(hadc);

    HAL_ADC_Stop(hadc);
    HAL_ADC_DeInit(hadc);

    return value;
    
}