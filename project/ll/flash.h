#ifndef LL_FLASH_H
#define LL_FLASH_H

#include <stdint.h>
#include "stm32f3.h"
#include "utils.h"

#define LL_FLASH_LATENCY_0 0x00000000U         /* FLASH Zero Latency cycle */
#define LL_FLASH_LATENCY_1 FLASH_ACR_LATENCY_0 /* FLASH One Latency cycle */
#define LL_FLASH_LATENCY_2 FLASH_ACR_LATENCY_1 /* FLASH Two Latency cycles */

/**
 * @brief  Set FLASH Latency
 * @param  latency This parameter can be one of the following values:
 *         @arg @ref LL_FLASH_LATENCY_0
 *         @arg @ref LL_FLASH_LATENCY_1
 *         @arg @ref LL_FLASH_LATENCY_2
 * @retval None
 */
static inline void ll_flash_set_latency(uint32_t latency)
{
    MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, latency);
}

#endif /* LL_FLASH_H */
