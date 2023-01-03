/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#define FL_SCK_Pin GPIO_PIN_5
#define FL_SCK_GPIO_Port GPIOA
#define DISP_RS_Pin GPIO_PIN_7
#define DISP_RS_GPIO_Port GPIOE
#define DISP_RW_Pin GPIO_PIN_10
#define DISP_RW_GPIO_Port GPIOE
#define DISP_ENA_Pin GPIO_PIN_11
#define DISP_ENA_GPIO_Port GPIOE
#define DISP_DB4_Pin GPIO_PIN_12
#define DISP_DB4_GPIO_Port GPIOE
#define DISP_DB5_Pin GPIO_PIN_13
#define DISP_DB5_GPIO_Port GPIOE
#define DISP_DB6_Pin GPIO_PIN_14
#define DISP_DB6_GPIO_Port GPIOE
#define DISP_DB7_Pin GPIO_PIN_15
#define DISP_DB7_GPIO_Port GPIOE
#define DHT11_Pin GPIO_PIN_11
#define DHT11_GPIO_Port GPIOD
#define Debug_LED_Pin GPIO_PIN_15
#define Debug_LED_GPIO_Port GPIOD
#define Key_Up_Pin GPIO_PIN_6
#define Key_Up_GPIO_Port GPIOC
#define Key_Up_EXTI_IRQn EXTI9_5_IRQn
#define Key_Down_Pin GPIO_PIN_8
#define Key_Down_GPIO_Port GPIOC
#define Key_Down_EXTI_IRQn EXTI9_5_IRQn
#define Key_Left_Pin GPIO_PIN_9
#define Key_Left_GPIO_Port GPIOC
#define Key_Left_EXTI_IRQn EXTI9_5_IRQn
#define Key_Mid_Pin GPIO_PIN_15
#define Key_Mid_GPIO_Port GPIOA
#define Key_Mid_EXTI_IRQn EXTI15_10_IRQn
#define Key_Right_Pin GPIO_PIN_11
#define Key_Right_GPIO_Port GPIOC
#define Key_Right_EXTI_IRQn EXTI15_10_IRQn
#define FL_CE_Pin GPIO_PIN_7
#define FL_CE_GPIO_Port GPIOD
#define FL_SO_Pin GPIO_PIN_4
#define FL_SO_GPIO_Port GPIOB
#define FL_SI_Pin GPIO_PIN_5
#define FL_SI_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
