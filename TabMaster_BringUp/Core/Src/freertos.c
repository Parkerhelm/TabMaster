/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "app_touchgfx.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define max_stepper_speed 13375
#define stepper_start_speed 267500
#define acceleration_step 254 //Values are calculated based on timer frequency and desired acceleration
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

volatile uint16_t to_count = 0;
volatile uint16_t curr_count = 0;
extern TIM_HandleTypeDef htim2;


/* USER CODE END Variables */
/* Definitions for count */
osThreadId_t countHandle;
const osThreadAttr_t count_attributes = {
  .name = "count",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for touchGFXTask */
osThreadId_t touchGFXTaskHandle;
const osThreadAttr_t touchGFXTask_attributes = {
  .name = "touchGFXTask",
  .stack_size = 8192 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void start_count(void *argument);
void StarttouchGFXTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of count */
  countHandle = osThreadNew(start_count, NULL, &count_attributes);

  /* creation of touchGFXTask */
  touchGFXTaskHandle = osThreadNew(StarttouchGFXTask, NULL, &touchGFXTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_start_count */
/**
  * @brief  Function implementing the count thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_start_count */
void start_count(void *argument)
{
  /* USER CODE BEGIN start_count */

	vTaskSuspend(NULL); //Suspend itself immediately

  /* Infinite loop */
  for(;;)
  {
	  uint32_t period = stepper_start_speed; //Initialize Variables
	  uint32_t duty_cycle = period / 2;
	  curr_count = 0;

	  __HAL_TIM_SET_AUTORELOAD(&htim2, period);
	  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty_cycle); //Double check period and duty cycle
	  __NVIC_EnableIRQ(EXTI1_IRQn); //enable the count interrupt

	  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

	  while(period >= max_stepper_speed){        //Acceleration loop

		  __HAL_TIM_SET_AUTORELOAD(&htim2, period);
		  duty_cycle = period / 2;
		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty_cycle);
		  period -= acceleration_step;
		  osDelay(1);
	  }

	  vTaskSuspend(NULL);  //Suspends itself when done

  }
  /* USER CODE END start_count */
}

/* USER CODE BEGIN Header_StarttouchGFXTask */
/**
* @brief Function implementing the touchGFXTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StarttouchGFXTask */
void StarttouchGFXTask(void *argument)
{
  /* USER CODE BEGIN StarttouchGFXTask */
	MX_TouchGFX_Process();
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StarttouchGFXTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

