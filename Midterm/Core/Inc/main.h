/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define RED_Pin GPIO_PIN_5
#define RED_GPIO_Port GPIOA
#define LED7_0_Pin GPIO_PIN_0
#define LED7_0_GPIO_Port GPIOB
#define LED7_1_Pin GPIO_PIN_1
#define LED7_1_GPIO_Port GPIOB
#define LED7_2_Pin GPIO_PIN_2
#define LED7_2_GPIO_Port GPIOB
#define RES_Pin GPIO_PIN_13
#define RES_GPIO_Port GPIOA
#define INC_Pin GPIO_PIN_14
#define INC_GPIO_Port GPIOA
#define DEC_Pin GPIO_PIN_15
#define DEC_GPIO_Port GPIOA
#define LED7_3_Pin GPIO_PIN_3
#define LED7_3_GPIO_Port GPIOB
#define LED7_4_Pin GPIO_PIN_4
#define LED7_4_GPIO_Port GPIOB
#define LED7_5_Pin GPIO_PIN_5
#define LED7_5_GPIO_Port GPIOB
#define LED7_6_Pin GPIO_PIN_6
#define LED7_6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
