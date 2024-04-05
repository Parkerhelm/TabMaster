/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.22.1. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
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

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>

extern "C" {
#include "GT911.h"
}

void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */

	//GT911_INIT();


}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */

	//GT911_I2C_Read(uint16_t address, uint8_t* buff, uint32_t data_len)
	//GT911_I2C_Write(uint16_t address, uint8_t* buff, uint16_t data_len)


	//Check SR
	static uint8_t REG_ADD[2] = {0};
	uint8_t SREG = 0;
	REG_ADD[0] = 0x81;
	REG_ADD[1] = 0x4E;

	if (GT911_I2C_Write(GT911_ADDRESS, REG_ADD, sizeof(REG_ADD)) != GT911_OK){
		while(1){}
	}
	if (GT911_I2C_Read(GT911_ADDRESS, &SREG, sizeof(SREG)) != GT911_OK){
		while(1){}
	}

	if ((SREG && 0x80) == 0){
		return false;
	}

	//Read coordinates if needed
	uint8_t COOR_BUFF[4] = {0};

	REG_ADD[0] = 0x81;
	REG_ADD[1] = 0x50;//set address

	GT911_I2C_Write(GT911_ADDRESS, REG_ADD, sizeof(REG_ADD));
	GT911_I2C_Read(GT911_ADDRESS, COOR_BUFF, sizeof(COOR_BUFF)); //read coords
																//coordinate bytes are stored in 4 consecutive addresses
																//x low byte, x high byte, y low byte, y high byte
	uint8_t SREG_RST[3] = {0};
	SREG_RST[0] = 0x81;
	SREG_RST[1] = 0x4E;
	SREG_RST[2] = 0;

	GT911_I2C_Write(GT911_ADDRESS, SREG_RST, sizeof(SREG_RST)); //reset SREG

	x = (((uint32_t) COOR_BUFF[1]) << 8) | ((uint32_t)COOR_BUFF[0]);
	y = (((uint32_t) COOR_BUFF[3]) << 8) | ((uint32_t)COOR_BUFF[2]); // return coords

    return true;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
