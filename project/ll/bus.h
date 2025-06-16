#ifndef LL_BUS_H
#define LL_BUS_H

#include <stdint.h>
#include "stm32f3.h"
#include "utils.h"

#define LL_BUS_AHB1_GRP1_PERIPH_ALL 0xFFFFFFFFU
#define LL_BUS_AHB1_GRP1_PERIPH_DMA1 RCC_AHBENR_DMA1EN
#define LL_BUS_AHB1_GRP1_PERIPH_DMA2 RCC_AHBENR_DMA2EN
#define LL_BUS_AHB1_GRP1_PERIPH_SRAM RCC_AHBENR_SRAMEN
#define LL_BUS_AHB1_GRP1_PERIPH_FLASH RCC_AHBENR_FLITFEN
#define LL_BUS_AHB1_GRP1_PERIPH_CRC RCC_AHBENR_CRCEN
#define LL_BUS_AHB1_GRP1_PERIPH_GPIOA RCC_AHBENR_GPIOAEN
#define LL_BUS_AHB1_GRP1_PERIPH_GPIOB RCC_AHBENR_GPIOBEN
#define LL_BUS_AHB1_GRP1_PERIPH_GPIOC RCC_AHBENR_GPIOCEN
#define LL_BUS_AHB1_GRP1_PERIPH_GPIOD RCC_AHBENR_GPIODEN
#define LL_BUS_AHB1_GRP1_PERIPH_GPIOE RCC_AHBENR_GPIOEEN
#define LL_BUS_AHB1_GRP1_PERIPH_GPIOF RCC_AHBENR_GPIOFEN
#define LL_BUS_AHB1_GRP1_PERIPH_TSC RCC_AHBENR_TSCEN
#define LL_BUS_AHB1_GRP1_PERIPH_ADC12 RCC_AHBENR_ADC12EN
#define LL_BUS_AHB1_GRP1_PERIPH_ADC34 RCC_AHBENR_ADC34EN

/**
 * @brief  Enable AHB1 peripherals clock.
 * @param  peripherals This parameter can be a combination of the following values:
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_DMA1
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_DMA2 (*)
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_SRAM
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_FLASH
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_FMC (*)
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_CRC
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_GPIOA
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_GPIOB
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_GPIOC
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_GPIOD
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_GPIOE (*)
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_GPIOF
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_TSC
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_ADC1 (*)
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_ADC12 (*)
 *         @arg @ref LL_BUS_AHB1_GRP1_PERIPH_ADC34 (*)
 * @retval None
 */
static inline void ll_bus_ahb1_grp1_enable_clock(uint32_t peripherals)
{
    SET_BIT(RCC->AHBENR, peripherals);
}

#endif /* LL_BUS_H */
