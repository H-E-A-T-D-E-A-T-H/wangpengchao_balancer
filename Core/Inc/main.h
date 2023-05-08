/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern uint8_t rebuf[11];
extern int right_encoderB,left_encoderA;
extern int right_encoderB_PN,left_encoderA_PN;
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
#define E2A_Pin GPIO_PIN_0
#define E2A_GPIO_Port GPIOA
#define E2B_Pin GPIO_PIN_1
#define E2B_GPIO_Port GPIOA
#define IR1_Pin GPIO_PIN_4
#define IR1_GPIO_Port GPIOA
#define IR2_Pin GPIO_PIN_5
#define IR2_GPIO_Port GPIOA
#define PWMA_Pin GPIO_PIN_6
#define PWMA_GPIO_Port GPIOA
#define PWMB_Pin GPIO_PIN_7
#define PWMB_GPIO_Port GPIOA
#define AIN1_Pin GPIO_PIN_2
#define AIN1_GPIO_Port GPIOB
#define AIN2_Pin GPIO_PIN_10
#define AIN2_GPIO_Port GPIOB
#define BIN1_Pin GPIO_PIN_8
#define BIN1_GPIO_Port GPIOC
#define BIN2_Pin GPIO_PIN_9
#define BIN2_GPIO_Port GPIOC
#define E1A_Pin GPIO_PIN_8
#define E1A_GPIO_Port GPIOA
#define E1B_Pin GPIO_PIN_9
#define E1B_GPIO_Port GPIOA
#define STBY_Pin GPIO_PIN_9
#define STBY_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
