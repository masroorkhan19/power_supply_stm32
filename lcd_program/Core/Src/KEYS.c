/*
 * KEYS.c
 *
 *  Created on: Dec 7, 2022
 *      Author: Syed Mir Hamza
 */


#include "KEYS.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if(GPIO_Pin == KEY1_Pin){
		page_load = 1;
	}

	if (GPIO_Pin == KEY2_Pin){
		page_load = 2;
	}

	if (GPIO_Pin == KEY3_Pin){
		page_load = 3;
	}

	if (GPIO_Pin == KEY4_Pin){
		page_load = 4;
	}

	if (GPIO_Pin == KEY5_Pin){
		page_load = 5;
	}

	if (GPIO_Pin == KEY6_Pin){
		page_load = 6;
	}

}

