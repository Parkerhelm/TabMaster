/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "i2c.h"
#include "ltdc.h"
#include "quadspi.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "W25Q32JV.h"
#include "IS42S16400J-6TLI.h"
#include "Test_Image.h"
#include "GT911.h"
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

/* USER CODE BEGIN PV */
/*uint8_t GT911_CONFIG[188] = {0x80, 0x47, 0x90, 0x20, 0x03, 0xE0, 0x01, 0x05, 0x3D, 0x00, 0x01, 0x08, //0x8047-0x8050
								0x28, 0x05, 0x50, 0x32, 0x03, 0x05, 0x00, 0x00, 0x00, 0x00, //0x8051-0x805A
								0x00, 0x00, 0x00, 0x18, 0x1A, 0x1F, 0x14, 0x8C, 0x24, 0x0A, //0x805B-0x8064
								0x1B, 0x19, 0xF4, 0x0A, 0x00, 0x00, 0x00, 0x21, 0x04, 0x1D, //0x8065-0x806E
								0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x64, 0x32, 0x00, 0x00, //0x806F-0x8078
								0x00, 0x11, 0xB2, 0x94, 0xC5, 0x02, 0x07, 0x00, 0x00, 0x04, //0x8079-0x8082
								0x8E, 0x16, 0x00, 0x5D, 0x23, 0x00, 0x3D, 0x38, 0x00, 0x2A, //0x8083-0x808C
								0x5A, 0x00, 0x22, 0x90, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, //0x808D-0x8096
								0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0x8097-0x80A0
								0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0x80A1-0x80AA
								0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0x80AB-0x80B4
								0x00, 0x00, 0x14, 0x12, 0x10, 0x0E, 0x0C, 0x0A, 0x08, 0x06, //0x80B5-0x80BE
								0x04, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, //0x80BF-0x80C8
								0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0x80C9-0x80D2
								0x00, 0x00, 0x1D, 0x1C, 0x18, 0x16, 0x14, 0x13, 0x12, 0x10, //0x80D3-0x80DC
								0x0F, 0x0C, 0x0A, 0x08, 0x06, 0x04, 0x02, 0x00, 0xFF, 0xFF, //0x80DD-0x80E6
								0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, //0x80E7-0x80F0
								0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0x80F1-0x80FA
								0x00, 0x00, 0x00, 0x00, 0xDB, 0x01}; //0x80FB-8100*/
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_QUADSPI_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  FMC_Init(&hsdram1);
  GT911_INIT();

  uint8_t REG_ADD[2] = {0};
  REG_ADD[0] = 0x80;
  REG_ADD[1] = 0x47;

  uint8_t SREG = 0;

 /* if (GT911_I2C_Write( GT911_ADRESS, GT911_CONFIG, sizeof(GT911_CONFIG)) != GT911_OK){
	  while(1){}
  }*/

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if (GT911_I2C_Write( GT911_ADRESS, REG_ADD, sizeof(REG_ADD)) != GT911_OK){
		  while(1){}
	  }

	  if (GT911_I2C_Read(GT911_ADRESS, &SREG, sizeof(SREG)) != GT911_OK){
		  while(1){}
	  }

	  REG_ADD[1]++;

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 276;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
