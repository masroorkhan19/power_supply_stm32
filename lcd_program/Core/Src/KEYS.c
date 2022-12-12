/*
 * KEYS.c
 *
 *  Created on: Dec 7, 2022
 *      Author: Syed Mir Hamza
 */


#include "KEYS.h"

TIM_HandleTypeDef htim4;
uint8_t state=1;
uint8_t counter=0;


void start_external_interupt_button(){


	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}
void stop_external_interupt_button(){
	HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_DisableIRQ(EXTI3_IRQn);
	HAL_NVIC_DisableIRQ(EXTI4_IRQn);

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if((GPIO_Pin == KEY1_Pin && state == 1) || (GPIO_Pin == KEY2_Pin && state == 1) || (GPIO_Pin == KEY3_Pin && state == 1) || (GPIO_Pin == KEY4_Pin && state == 1) || (GPIO_Pin == KEY5_Pin && state == 1) || (GPIO_Pin == KEY6_Pin && state == 1)){
		stop_external_interupt_button();
		HAL_TIM_Base_Start_IT(&htim4);
		state = 0;
	}



}

void button_debouncing_delay(){
	HAL_TIM_Base_Stop_IT(&htim4);
	if((HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET) || (HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET) || (HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin) == GPIO_PIN_RESET) ||  (HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin) == GPIO_PIN_RESET) || (HAL_GPIO_ReadPin(KEY5_GPIO_Port, KEY5_Pin) == GPIO_PIN_RESET) ||  (HAL_GPIO_ReadPin(KEY6_GPIO_Port, KEY6_Pin) == GPIO_PIN_RESET)){
	if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){


	}
	if (HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET){



	}
	if (HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin) == GPIO_PIN_RESET){



	}
	if (HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin) == GPIO_PIN_RESET){



	}
	if (HAL_GPIO_ReadPin(KEY5_GPIO_Port, KEY5_Pin) == GPIO_PIN_RESET){


	}
	if (HAL_GPIO_ReadPin(KEY6_GPIO_Port, KEY6_Pin) == GPIO_PIN_RESET){
//		HAL_TIM_Base_Stop_IT(&htim4);
//		state = 1;
//		counter++;
	}
	state = 1;
	counter++;
	key_update_._flag=1;

	}

}
