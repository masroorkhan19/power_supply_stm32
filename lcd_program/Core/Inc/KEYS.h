/*
 * KEYS.h
 *
 *  Created on: Dec 7, 2022
 *      Author: Syed Mir Hamza
 */

#ifndef INC_KEYS_H_
#define INC_KEYS_H_
#include "main.h"

extern uint8_t page_load,state, counter;
extern TIM_HandleTypeDef htim4;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
extern void button_debouncing_delay();

#endif /* INC_KEYS_H_ */
