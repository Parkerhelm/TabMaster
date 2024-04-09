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

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

uint16_t to_count = 0;



/* USER CODE END Variables */
/* Definitions for HardwareTask */
osThreadId_t HardwareTaskHandle;
const osThreadAttr_t HardwareTask_attributes = {
  .name = "HardwareTask",
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
/* Definitions for TestTask */
osThreadId_t TestTaskHandle;
const osThreadAttr_t TestTask_attributes = {
  .name = "TestTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartHardwareTask(void *argument);
void StarttouchGFXTask(void *argument);
void StartTestTask(void *argument);

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
  /* creation of HardwareTask */
  HardwareTaskHandle = osThreadNew(StartHardwareTask, NULL, &HardwareTask_attributes);

  /* creation of touchGFXTask */
  touchGFXTaskHandle = osThreadNew(StarttouchGFXTask, NULL, &touchGFXTask_attributes);

  /* creation of TestTask */
  TestTaskHandle = osThreadNew(StartTestTask, NULL, &TestTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartHardwareTask */
/**
  * @brief  Function implementing the HardwareTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartHardwareTask */
void StartHardwareTask(void *argument)
{
  /* USER CODE BEGIN StartHardwareTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartHardwareTask */
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

/* USER CODE BEGIN Header_StartTestTask */
/**
* @brief Function implementing the TestTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTestTask */
void StartTestTask(void *argument)
{
  /* USER CODE BEGIN StartTestTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTestTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

