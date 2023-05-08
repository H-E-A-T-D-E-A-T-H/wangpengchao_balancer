/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32f4xx_it.h"
#include "MPU6050.h"
#include "PID.h"
#include "math.h"
#include "tim.h"
double right_PWMB=0,left_PWMA=0,PWM,angle_PWM,speed_PWM,turn_PWM;
int mode;
uint8_t rebuf[11];
int right_encoderB,left_encoderA;
int right_encoderB_PN,left_encoderA_PN;
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

/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

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
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityRealtime, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
		angle_PWM=PID_angle_out(angle[1]);
		speed_PWM=PID_speed_out(left_encoderA,right_encoderB,0);
		PWM=angle_PWM+speed_PWM;
		if(PWM>=0)
		{
			HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,GPIO_PIN_SET);
			if(PWM>200)
				PWM=200;
		}
		else
		{
			HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,GPIO_PIN_RESET);
			if(PWM<-200)
				PWM=-200;
		}
		left_PWMA=fabs(PWM);
		right_PWMB=fabs(PWM);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,left_PWMA);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,right_PWMB);
  
    osDelay(1);
	}
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
