/*
 * sensor.c
 *
 *  Created on: Mar 24, 2024
 *      Author: wolfm
 */

#include "stm32f4xx_hal.h"

// Sensor Pin Definition
#define SENSOR_PIN GPIO_PIN_0
#define SENSOR_GPIO_PORT GPIOA

// Stepper Motor Control Pin Definition
#define STEPPER_MOTOR_ENABLE_PIN GPIO_PIN_X // Adjust this to your actual pin
#define STEPPER_MOTOR_ENABLE_GPIO_PORT GPIOB // Adjust this to your actual GPIO port

// Global Variables
volatile uint32_t cardCount = 0;

// Function Prototypes
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void TurnOnStepperMotor(void);

int main(void) {
    // Initialize the HAL Library
    HAL_Init();

    // Configure the system clock
    SystemClock_Config();

    // Initialize all configured peripherals
    MX_GPIO_Init();

    // Main loop
    while (1) {
        // Here you should include your logic for checking the UI signal.
        // For example, this could be reading a button press or receiving a command over serial.
        if (/* condition to check for UI signal */) {
            TurnOnStepperMotor();
        }

        // Your application's main logic continues here.
        // This could involve processing the counted cards or other tasks.
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == SENSOR_PIN) {
        cardCount++;
        __NOP(); // A placeholder for noise handling; adjust as needed
    }
}

void TurnOnStepperMotor(void) {
    HAL_GPIO_WritePin(STEPPER_MOTOR_ENABLE_GPIO_PORT, STEPPER_MOTOR_ENABLE_PIN, GPIO_PIN_SET);
    // Add here any additional logic needed for stepping the motor.
}

static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // GPIO Ports Clock Enable
    __HAL_RCC_GPIOA_CLK_ENABLE(); // For SENSOR_GPIO_PORT
    __HAL_RCC_GPIOB_CLK_ENABLE(); // For STEPPER_MOTOR_ENABLE_GPIO_PORT; adjust as necessary

    // Sensor Pin Configuration
    GPIO_InitStruct.Pin = SENSOR_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SENSOR_GPIO_PORT, &GPIO_InitStruct);

    // Stepper Motor Control Pin Configuration
    GPIO_InitStruct.Pin = STEPPER_MOTOR_ENABLE_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(STEPPER_MOTOR_ENABLE_GPIO_PORT, &GPIO_InitStruct);

    // NVIC Configuration for EXTI Line (if using external interrupt for the sensor)
    HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0); // Adjust the EXTI line as per your sensor pin
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void SystemClock_Config(void) {
    // Configure the system clock
    // This function must be adapted to your system's clock setup.
}


