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
uint8_t GT911_CONFIG1[186] = { 0x83,0x00,0x04,0x58,0x02,0x05,0x3D,0x00,0x01,0x08,
						0x28,0x08,0x5A,0x3C,0x03,0x05,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x18,0x1A,0x1E,0x14,0x8C,0x28,0x0C,
						0x9B,0x9D,0xB2,0x04,0x00,0x00,0x00,0x40,0x02,0x1D,
						0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0x00,0x78,0xC8,0x94,0xD5,0x02,0x07,0x00,0x00,0x04,
						0x95,0x7E,0x00,0x8A,0x8C,0x00,0x80,0x9B,0x00,0x77,
						0xAB,0x00,0x6F,0xBE,0x00,0x6F,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0x00,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,0x10,
						0x12,0x14,0x16,0x18,0xFF,0xFF,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0x00,0x00,0x21,0x20,0x1F,0x1E,0x1D,0x1C,0x18,0x16,
						0x14,0x13,0x12,0x10,0x0F,0x0C,0x0A,0x08,0x06,0x04,
						0x02,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0xE1,0x01 };
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

  uint8_t config_num = 0;

  /*uint8_t RST_REG_ADD[3] = {0};
  RST_REG_ADD[0] = 0x81;
  RST_REG_ADD[1] = 0x4E;
  RST_REG_ADD[2] = 0x00;

  uint8_t COOR_ADD[2] = {0};
  COOR_ADD[0] = 0x81;
  COOR_ADD[1] = 0x50;

  uint8_t COOR[2] = {0};

  uint8_t SREG = 0;

  uint16_t XCOOR = 0;*/


  if (GT911_I2C_Write( GT911_ADRESS, GT911_CONFIG1, sizeof(GT911_CONFIG1)) != GT911_OK){
  		  while(1){}
  	  }

  if (GT911_I2C_Write( GT911_ADRESS, REG_ADD, sizeof(REG_ADD)) != GT911_OK){
  		  while(1){}
  	  }

  if (GT911_I2C_Read(GT911_ADRESS, &config_num, sizeof(config_num)) != GT911_OK){
	  while(1){}
  }



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	 /* if (GT911_I2C_Write( GT911_ADRESS, REG_ADD, sizeof(REG_ADD)) != GT911_OK){
		  while(1){}
	  }

	  if (GT911_I2C_Read(GT911_ADRESS, &SREG, sizeof(SREG)) != GT911_OK){
		  while(1){}
	  }

	  if (GT911_I2C_Write( GT911_ADRESS, RST_REG_ADD, sizeof(RST_REG_ADD)) != GT911_OK){
		  while(1){}
	  }

	  if (GT911_I2C_Write( GT911_ADRESS, COOR_ADD, sizeof(COOR_ADD)) != GT911_OK){
		  while(1){}
	  }

	  if (GT911_I2C_Read(GT911_ADRESS, COOR, sizeof(COOR)) != GT911_OK){
		  while(1){}
	  }

	  XCOOR = (COOR[1]<<8) | COOR[0];*/



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
