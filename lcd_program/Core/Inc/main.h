/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */




/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY3_Pin GPIO_PIN_13
#define KEY3_GPIO_Port GPIOC
#define KEY3_EXTI_IRQn EXTI15_10_IRQn
#define KEY2_Pin GPIO_PIN_14
#define KEY2_GPIO_Port GPIOC
#define KEY2_EXTI_IRQn EXTI15_10_IRQn
#define KEY1_Pin GPIO_PIN_15
#define KEY1_GPIO_Port GPIOC
#define KEY1_EXTI_IRQn EXTI15_10_IRQn
#define buck_current_sense_Pin GPIO_PIN_2
#define buck_current_sense_GPIO_Port GPIOA
#define buck_voltage_sensor_Pin GPIO_PIN_3
#define buck_voltage_sensor_GPIO_Port GPIOA
#define buck_temperature_Pin GPIO_PIN_4
#define buck_temperature_GPIO_Port GPIOA
#define pwm_1_Pin GPIO_PIN_6
#define pwm_1_GPIO_Port GPIOA
#define pwm_2_Pin GPIO_PIN_7
#define pwm_2_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_0
#define LD2_GPIO_Port GPIOB
#define LCD_RD_Pin GPIO_PIN_1
#define LCD_RD_GPIO_Port GPIOB
#define LCD_D2_Pin GPIO_PIN_10
#define LCD_D2_GPIO_Port GPIOB
#define LCD_D3_Pin GPIO_PIN_11
#define LCD_D3_GPIO_Port GPIOB
#define LCD_D4_Pin GPIO_PIN_12
#define LCD_D4_GPIO_Port GPIOB
#define LCD_D5_Pin GPIO_PIN_13
#define LCD_D5_GPIO_Port GPIOB
#define LCD_D6_Pin GPIO_PIN_14
#define LCD_D6_GPIO_Port GPIOB
#define LCD_D7_Pin GPIO_PIN_15
#define LCD_D7_GPIO_Port GPIOB
#define LCD_WR_Pin GPIO_PIN_8
#define LCD_WR_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_11
#define LCD_DC_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_12
#define LCD_CS_GPIO_Port GPIOA
#define KEY6_Pin GPIO_PIN_3
#define KEY6_GPIO_Port GPIOB
#define KEY6_EXTI_IRQn EXTI3_IRQn
#define KEY5_Pin GPIO_PIN_4
#define KEY5_GPIO_Port GPIOB
#define KEY5_EXTI_IRQn EXTI4_IRQn
#define KEY4_Pin GPIO_PIN_5
#define KEY4_GPIO_Port GPIOB
#define KEY4_EXTI_IRQn EXTI9_5_IRQn
#define LCD_D0_Pin GPIO_PIN_8
#define LCD_D0_GPIO_Port GPIOB
#define LCD_D1_Pin GPIO_PIN_9
#define LCD_D1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
