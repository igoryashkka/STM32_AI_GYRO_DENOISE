/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ai_platform.h"
#include "ai_datatypes_defines.h"

#include "sin_wave.h"
#include "sin_wave_data.h"
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

/* @brief Statically allocated buffers.
 * Buffers can be dynamically allocated using malloc and size information
 * given by the report in ai_network_get_report().
 */
ai_u8 activations[AI_SIN_WAVE_DATA_ACTIVATIONS_SIZE];
ai_u8 in_data[AI_SIN_WAVE_IN_1_SIZE_BYTES];
ai_u8 out_data[AI_SIN_WAVE_OUT_1_SIZE_BYTES];

char TX_Buffer[128] = {0,};
int StrLen = 0;

/* AI buffer IO handlers */
ai_buffer *ai_input;
ai_buffer *ai_output;

float x_val = 2.0f;
float y_val = 0.0f;

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
  /* USER CODE BEGIN 2 */
  ai_handle network = AI_HANDLE_NULL;
  	ai_error err;
  	ai_network_report report;


	/** @brief Initialize network */
	const ai_handle acts[] = { activations };
	err = ai_sin_wave_create_and_init(&network, acts, NULL);
	if (err.type != AI_ERROR_NONE)
	{
		return -1;
	}

	/** @brief {optional} for debug/log purpose */
	if (ai_sin_wave_get_report(network, &report) != true)
	{
		return -1;
	}

	ai_input = &report.inputs[0];
	ai_output = &report.outputs[0];
	/** @brief Fill input buffer with random values */
	for (uint32_t i = 0; i < AI_SIN_WAVE_IN_1_SIZE; i++)
	{
		((ai_float*) in_data)[i] = (ai_float) x_val;
	}

	/** @brief Normalize, convert and/or quantize inputs if necessary... */

	/** @brief Perform inference */
	ai_i32 n_batch;

	/** @brief Create the AI buffer IO handlers
	 *  @note  ai_inuput/ai_output are already initilaized after the
	 *         ai_network_get_report() call. This is just here to illustrate
	 *         the case where get_report() is not called.
	 */
	ai_input = ai_sin_wave_inputs_get(network, NULL);
	ai_output = ai_sin_wave_outputs_get(network, NULL);

	/** @brief Set input/output buffer addresses */
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  for (uint32_t i = 0; i < AI_SIN_WAVE_IN_1_SIZE; i++)
	  		{
	  			((ai_float*) in_data)[i] = (ai_float) x_val;
	  		}

	  		/** @brief Perform the inference */
	  		n_batch = ai_sin_wave_run(network, &ai_input[0], &ai_output[0]);
	  		if (n_batch != 1)
	  		{
	  			err = ai_sin_wave_get_error(network);
	  			return -1;
	  		}

	  		/** @brief Post-process the output results/predictions */
	  		y_val = ((float*) out_data)[0];



	  		if (x_val > 6.0f)
	  		{
	  			x_val = 0.0f;
	  		}
	  		else
	  		{
	  			x_val = x_val + 0.1f;
	  		}

	  		HAL_Delay(500);

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
