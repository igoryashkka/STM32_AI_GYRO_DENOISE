/**
  ******************************************************************************
  * @file    sin_wave_data_params.c
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

#include "sin_wave_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_sin_wave_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_sin_wave_weights_array_u64[57] = {
  0x3f00a757bec8b7b4U, 0xbefef4fc3e607d3fU, 0x3f148f3b3e8ac7e3U, 0x3e8634783e817a0fU,
  0x3e9c09e33f0beed5U, 0xbf0e8ae83d3d6523U, 0xbdfa9704be417dceU, 0x3e55bfb5bdbe9668U,
  0xbf014edd00000000U, 0xbf12bd3eU, 0xbd9bc807bf07b5f5U, 0x3ef175153eeba969U,
  0xbf1e5a29bd6bbba7U, 0x3e94cc14U, 0x0U, 0xbeb3cdc600000000U,
  0xbf59f9aabf6999abU, 0xbf1dc1aebf37ac82U, 0xbece621bbf020bedU, 0xbe5a92efbe9f504dU,
  0xbb2bc623bde53d8fU, 0x3e5b12b13ddf603dU, 0x3ec5e80c3e9b0fceU, 0x3f1735cc3f044c81U,
  0x689b5c9d94cadb7dU, 0x8696cdac6c54c86bU, 0x63dcab85ad1c0bc6U, 0xb9dc8bdd6b99e866U,
  0xdc67575bd7999a98U, 0x86787a7ac876687bU, 0x7f9667bf7accb7ddU, 0xc4d8d8a79a2925cbU,
  0xddaa55b659a69c9dU, 0x9567c77955b6c5c6U, 0xce69855db4bccabaU, 0x8d9db9cd9aa8aa7eU,
  0xc8bbc78d57dd7896U, 0x8a997a7aa8ca7a89U, 0xadc678965ab77c7cU, 0xb89aa739bbb49997U,
  0xbdddf1cdbec330abU, 0xbec7f96a3e9fbebfU, 0xbc43b027bd0ba3b0U, 0x3da91fe8be6fe93fU,
  0xbd109bc9U, 0xbea8d183beab6e84U, 0xbc341a29bd074050U, 0x3e94553e00000000U,
  0x3eae00613f9341c7U, 0x3f8966c23f442effU, 0x3f04ee10beed5ff0U, 0x3f10680bbe92978bU,
  0x3e6564503f084aa3U, 0xbe5a7a6e3f91a0eaU, 0xbda4cc133e08f32cU, 0xbf7f62a9beabed92U,
  0x3cf61054U,
};


ai_handle g_sin_wave_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_sin_wave_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

