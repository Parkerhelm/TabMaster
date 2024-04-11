/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f7xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DISP_EN_Pin GPIO_PIN_15
#define DISP_EN_GPIO_Port GPIOC
#define count_sensor__input_Pin GPIO_PIN_1
#define count_sensor__input_GPIO_Port GPIOC
#define count_sensor__input_EXTI_IRQn EXTI1_IRQn
#define stepper_direction_Pin GPIO_PIN_2
#define stepper_direction_GPIO_Port GPIOC
#define stepper_enable_Pin GPIO_PIN_3
#define stepper_enable_GPIO_Port GPIOC
#define LCD_TOUCH_RST_Pin GPIO_PIN_3
#define LCD_TOUCH_RST_GPIO_Port GPIOB
#define LCD_TOUCH_WAKE_Pin GPIO_PIN_4
#define LCD_TOUCH_WAKE_GPIO_Port GPIOB
#define LCD_TOUCH_INT_Pin GPIO_PIN_5
#define LCD_TOUCH_INT_GPIO_Port GPIOB
#define MCU_LED_Pin GPIO_PIN_7
#define MCU_LED_GPIO_Port GPIOI

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
