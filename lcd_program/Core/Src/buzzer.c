/*
 * buzzer.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Syed Mir Hamza
 */

#include "main.h"
//#include "stm32f1xx_hal.h"

void Beep(void){

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	HAL_Delay(1000);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
    HAL_Delay(1000);
}
