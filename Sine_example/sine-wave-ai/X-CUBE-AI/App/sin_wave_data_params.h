/**
  ******************************************************************************
  * @file    sin_wave_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-02-07T04:29:16+0200
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef SIN_WAVE_DATA_PARAMS_H
#define SIN_WAVE_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_SIN_WAVE_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_sin_wave_data_weights_params[1]))
*/

#define AI_SIN_WAVE_DATA_CONFIG               (NULL)


#define AI_SIN_WAVE_DATA_ACTIVATIONS_SIZES \
  { 128, }
#define AI_SIN_WAVE_DATA_ACTIVATIONS_SIZE     (128)
#define AI_SIN_WAVE_DATA_ACTIVATIONS_COUNT    (1)
#define AI_SIN_WAVE_DATA_ACTIVATION_1_SIZE    (128)



#define AI_SIN_WAVE_DATA_WEIGHTS_SIZES \
  { 452, }
#define AI_SIN_WAVE_DATA_WEIGHTS_SIZE         (452)
#define AI_SIN_WAVE_DATA_WEIGHTS_COUNT        (1)
#define AI_SIN_WAVE_DATA_WEIGHT_1_SIZE        (452)



#define AI_SIN_WAVE_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_sin_wave_activations_table[1])

extern ai_handle g_sin_wave_activations_table[1 + 2];



#define AI_SIN_WAVE_DATA_WEIGHTS_TABLE_GET() \
  (&g_sin_wave_weights_table[1])

extern ai_handle g_sin_wave_weights_table[1 + 2];


#endif    /* SIN_WAVE_DATA_PARAMS_H */
