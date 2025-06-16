#ifndef LL_CORTEX_H
#define LL_CORTEX_H

#include <stdint.h>
#include "stm32f3.h"
#include "utils.h"
#include "rcc.h"

/**
 * @brief  This function configures the Cortex-M SysTick source of the time base.
 * @param  frequency Frequency of Ticks (Hz)
 * @retval None
 */
static inline void ll_systick_init(uint32_t frequency)
{
  /* Configure the SysTick to have interrupt in 1ms time base */
  SysTick->LOAD = (uint32_t)((ll_rcc_get_sysclk_frequency() / frequency) - 1UL); /* set reload register */
  SysTick->VAL = 0UL;                                                            /* Load the SysTick Counter Value */
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk; /* Enable the Systick Timer */
}

#endif /* LL_CORTEX_H */
