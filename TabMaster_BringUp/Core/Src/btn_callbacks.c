/*
 * btn_callbacks.c
 *
 *  Created on: Apr 9, 2024
 *      Author: parke
 */

#include "btn_callbacks.h"
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "stm32f7xx.h"

extern uint16_t to_count; //to_count holds the number of pull tabs that will be counted
extern osThreadId_t countHandle;						  //the following functions define what each button does
extern TIM_HandleTypeDef htim2;

void p50_btn_callback(){

	to_count += 50;

}

void p10_btn_callback(){

	to_count += 10;

}

void p1_btn_callback(){

	to_count++;

}

void reset_btn_callback(){
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	to_count = 0;

}

void start_btn_callback(){
	vTaskResume((TaskHandle_t) countHandle); // resume counting task
}

















