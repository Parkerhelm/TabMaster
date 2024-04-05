/*
 * GT911.c
 *
 *  Created on: Mar 28, 2024
 *      Author: parke
 */

#include "main.h"
#include "GT911.h"
#include "i2c.h"

void GT911_INIT(void){ //only call after power on otherwise use reset

	HAL_Delay(10);

	HAL_GPIO_WritePin(LCD_TOUCH_RST_GPIO_Port, LCD_TOUCH_RST_Pin, GPIO_PIN_SET); //Write RST pin high

	HAL_Delay(55);

	Set_GT911_INT_Input();

	HAL_Delay(50);

	return;
}

void Set_GT911_INT_Output(void){

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = LCD_TOUCH_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LCD_TOUCH_INT_GPIO_Port, &GPIO_InitStruct);

	return;
}

void Set_GT911_INT_Input(void){

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = LCD_TOUCH_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(LCD_TOUCH_INT_GPIO_Port, &GPIO_InitStruct);
	return;
}

GT911_Status GT911_I2C_Read(uint16_t address, uint8_t* buff, uint32_t data_len){

	if ( HAL_I2C_Master_Receive( &hi2c1, address << 1, buff, data_len, HAL_MAX_DELAY) != HAL_OK ) {
		return GT911_ERROR;
	}
	return GT911_OK;

}

GT911_Status GT911_I2C_Write(uint16_t address, uint8_t* buff, uint16_t data_len){


	if ( HAL_I2C_Master_Transmit( &hi2c1, address << 1, buff, data_len, HAL_MAX_DELAY) != HAL_OK){
		return GT911_ERROR;
	}
	return GT911_OK;

}

void GT911_RESET(void){

	Set_GT911_INT_Output();

	HAL_GPIO_WritePin(LCD_TOUCH_RST_GPIO_Port, LCD_TOUCH_RST_Pin, GPIO_PIN_RESET); //Write RST pin low

	HAL_Delay(2);

	HAL_GPIO_WritePin(LCD_TOUCH_RST_GPIO_Port, LCD_TOUCH_RST_Pin, GPIO_PIN_SET); //Write RST pin high


	HAL_Delay(55);

	Set_GT911_INT_Input();

	HAL_Delay(50);

	return;
}




















