#ifndef LL_RCC_H
#define LL_RCC_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32f3.h"
#include "utils.h"

#define LL_RCC_HSE_VALUE 8000000U /*!< Value of the HSE oscillator in Hz */
#define LL_RCC_HSI_VALUE 8000000U /*!< Value of the HSI oscillator in Hz */
#define LL_RCC_LSE_VALUE 32768U   /*!< Value of the LSE oscillator in Hz */
#define LL_RCC_LSI_VALUE 40000U   /*!< Value of the LSI oscillator in Hz */

#define LL_RCC_PLLSOURCE_NONE 0x00000000U                                                 /*!< No clock selected as main PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE RCC_CFGR_PLLSRC_HSE_PREDIV                                   /*!< HSE/PREDIV clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSI_DIV_2 RCC_CFGR_PLLSRC_HSI_DIV2                               /*!< HSI clock divided by 2 selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_1 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV1)   /*!< HSE clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_2 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV2)   /*!< HSE/2 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_3 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV3)   /*!< HSE/3 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_4 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV4)   /*!< HSE/4 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_5 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV5)   /*!< HSE/5 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_6 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV6)   /*!< HSE/6 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_7 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV7)   /*!< HSE/7 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_8 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV8)   /*!< HSE/8 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_9 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV9)   /*!< HSE/9 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_10 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV10) /*!< HSE/10 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_11 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV11) /*!< HSE/11 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_12 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV12) /*!< HSE/12 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_13 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV13) /*!< HSE/13 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_14 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV14) /*!< HSE/14 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_15 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV15) /*!< HSE/15 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE_DIV_16 (RCC_CFGR_PLLSRC_HSE_PREDIV | RCC_CFGR2_PREDIV_DIV16) /*!< HSE/16 clock selected as PLL entry clock source */

#define LL_RCC_PLL_MUL_2 RCC_CFGR_PLLMUL2   /*!< PLL input clock*2 */
#define LL_RCC_PLL_MUL_3 RCC_CFGR_PLLMUL3   /*!< PLL input clock*3 */
#define LL_RCC_PLL_MUL_4 RCC_CFGR_PLLMUL4   /*!< PLL input clock*4 */
#define LL_RCC_PLL_MUL_5 RCC_CFGR_PLLMUL5   /*!< PLL input clock*5 */
#define LL_RCC_PLL_MUL_6 RCC_CFGR_PLLMUL6   /*!< PLL input clock*6 */
#define LL_RCC_PLL_MUL_7 RCC_CFGR_PLLMUL7   /*!< PLL input clock*7 */
#define LL_RCC_PLL_MUL_8 RCC_CFGR_PLLMUL8   /*!< PLL input clock*8 */
#define LL_RCC_PLL_MUL_9 RCC_CFGR_PLLMUL9   /*!< PLL input clock*9 */
#define LL_RCC_PLL_MUL_10 RCC_CFGR_PLLMUL10 /*!< PLL input clock*10 */
#define LL_RCC_PLL_MUL_11 RCC_CFGR_PLLMUL11 /*!< PLL input clock*11 */
#define LL_RCC_PLL_MUL_12 RCC_CFGR_PLLMUL12 /*!< PLL input clock*12 */
#define LL_RCC_PLL_MUL_13 RCC_CFGR_PLLMUL13 /*!< PLL input clock*13 */
#define LL_RCC_PLL_MUL_14 RCC_CFGR_PLLMUL14 /*!< PLL input clock*14 */
#define LL_RCC_PLL_MUL_15 RCC_CFGR_PLLMUL15 /*!< PLL input clock*15 */
#define LL_RCC_PLL_MUL_16 RCC_CFGR_PLLMUL16 /*!< PLL input clock*16 */

#define LL_RCC_APB1_DIV_1 RCC_CFGR_PPRE1_DIV1   /*!< HCLK not divided */
#define LL_RCC_APB1_DIV_2 RCC_CFGR_PPRE1_DIV2   /*!< HCLK divided by 2 */
#define LL_RCC_APB1_DIV_4 RCC_CFGR_PPRE1_DIV4   /*!< HCLK divided by 4 */
#define LL_RCC_APB1_DIV_8 RCC_CFGR_PPRE1_DIV8   /*!< HCLK divided by 8 */
#define LL_RCC_APB1_DIV_16 RCC_CFGR_PPRE1_DIV16 /*!< HCLK divided by 16 */

#define LL_RCC_APB2_DIV_1 RCC_CFGR_PPRE2_DIV1   /*!< HCLK not divided */
#define LL_RCC_APB2_DIV_2 RCC_CFGR_PPRE2_DIV2   /*!< HCLK divided by 2 */
#define LL_RCC_APB2_DIV_4 RCC_CFGR_PPRE2_DIV4   /*!< HCLK divided by 4 */
#define LL_RCC_APB2_DIV_8 RCC_CFGR_PPRE2_DIV8   /*!< HCLK divided by 8 */
#define LL_RCC_APB2_DIV_16 RCC_CFGR_PPRE2_DIV16 /*!< HCLK divided by 16 */

#define LL_RCC_AHB_DIV_1 RCC_CFGR_HPRE_DIV1     /*!< SYSCLK not divided */
#define LL_RCC_AHB_DIV_2 RCC_CFGR_HPRE_DIV2     /*!< SYSCLK divided by 2 */
#define LL_RCC_AHB_DIV_4 RCC_CFGR_HPRE_DIV4     /*!< SYSCLK divided by 4 */
#define LL_RCC_AHB_DIV_8 RCC_CFGR_HPRE_DIV8     /*!< SYSCLK divided by 8 */
#define LL_RCC_AHB_DIV_16 RCC_CFGR_HPRE_DIV16   /*!< SYSCLK divided by 16 */
#define LL_RCC_AHB_DIV_64 RCC_CFGR_HPRE_DIV64   /*!< SYSCLK divided by 64 */
#define LL_RCC_AHB_DIV_128 RCC_CFGR_HPRE_DIV128 /*!< SYSCLK divided by 128 */
#define LL_RCC_AHB_DIV_256 RCC_CFGR_HPRE_DIV256 /*!< SYSCLK divided by 256 */
#define LL_RCC_AHB_DIV_512 RCC_CFGR_HPRE_DIV512 /*!< SYSCLK divided by 512 */

#define LL_RCC_SYS_CLKSOURCE_HSI RCC_CFGR_SW_HSI /*!< HSI selection as system clock */
#define LL_RCC_SYS_CLKSOURCE_HSE RCC_CFGR_SW_HSE /*!< HSE selection as system clock */
#define LL_RCC_SYS_CLKSOURCE_PLL RCC_CFGR_SW_PLL /*!< PLL selection as system clock */

#define LL_RCC_SYS_CLKSOURCE_STATUS_HSI RCC_CFGR_SWS_HSI /*!< HSI used as system clock */
#define LL_RCC_SYS_CLKSOURCE_STATUS_HSE RCC_CFGR_SWS_HSE /*!< HSE used as system clock */
#define LL_RCC_SYS_CLKSOURCE_STATUS_PLL RCC_CFGR_SWS_PLL /*!< PLL used as system clock */

/**
 * @brief  Enable HSI oscillator
 * @retval None
 */
static inline void ll_rcc_enable_hsi(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSION);
}

/**
 * @brief  Check if HSI clock is ready
 * @retval State of bit (1 or 0).
 */
static inline bool ll_rcc_is_hsi_ready(void)
{
  return READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RCC_CR_HSIRDY;
}

/**
 * @brief  Configure PLL used for SYSCLK Domain
 * @param  source This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLSOURCE_HSI_DIV_2
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_1
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_2
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_3
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_4
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_5
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_6
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_7
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_8
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_9
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_10
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_11
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_12
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_13
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_14
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_15
 *         @arg @ref LL_RCC_PLLSOURCE_HSE_DIV_16
 * @param  pll_mul This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLL_MUL_2
 *         @arg @ref LL_RCC_PLL_MUL_3
 *         @arg @ref LL_RCC_PLL_MUL_4
 *         @arg @ref LL_RCC_PLL_MUL_5
 *         @arg @ref LL_RCC_PLL_MUL_6
 *         @arg @ref LL_RCC_PLL_MUL_7
 *         @arg @ref LL_RCC_PLL_MUL_8
 *         @arg @ref LL_RCC_PLL_MUL_9
 *         @arg @ref LL_RCC_PLL_MUL_10
 *         @arg @ref LL_RCC_PLL_MUL_11
 *         @arg @ref LL_RCC_PLL_MUL_12
 *         @arg @ref LL_RCC_PLL_MUL_13
 *         @arg @ref LL_RCC_PLL_MUL_14
 *         @arg @ref LL_RCC_PLL_MUL_15
 *         @arg @ref LL_RCC_PLL_MUL_16
 * @retval None
 */
static inline void ll_rcc_config_pll(uint32_t source, uint32_t pll_mul)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLSRC | RCC_CFGR_PLLMUL, (source & RCC_CFGR_PLLSRC) | pll_mul);
  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV, (source & RCC_CFGR2_PREDIV));
}

/**
 * @brief  Enable PLL
 * @retval None
 */
static inline void ll_rcc_enable_pll(void)
{
  SET_BIT(RCC->CR, RCC_CR_PLLON);
}

/**
 * @brief  Check if PLL Ready
 * @retval State of bit (1 or 0).
 */
static inline bool lc_rcc_is_pll_ready(void)
{
  return READ_BIT(RCC->CR, RCC_CR_PLLRDY) == (RCC_CR_PLLRDY);
}

/**
 * @brief  Set APB1 prescaler
 * @param  prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB1_DIV_1
 *         @arg @ref LL_RCC_APB1_DIV_2
 *         @arg @ref LL_RCC_APB1_DIV_4
 *         @arg @ref LL_RCC_APB1_DIV_8
 *         @arg @ref LL_RCC_APB1_DIV_16
 * @retval None
 */
static inline void ll_rcc_set_apb1_prescaler(uint32_t prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, prescaler);
}

/**
 * @brief  Set APB2 prescaler
 * @param  prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB2_DIV_1
 *         @arg @ref LL_RCC_APB2_DIV_2
 *         @arg @ref LL_RCC_APB2_DIV_4
 *         @arg @ref LL_RCC_APB2_DIV_8
 *         @arg @ref LL_RCC_APB2_DIV_16
 * @retval None
 */
static inline void ll_rcc_set_apb2_prescaler(uint32_t prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, prescaler);
}

/**
 * @brief  Set AHB prescaler
 * @param  prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_AHB_DIV_1
 *         @arg @ref LL_RCC_AHB_DIV_2
 *         @arg @ref LL_RCC_AHB_DIV_4
 *         @arg @ref LL_RCC_AHB_DIV_8
 *         @arg @ref LL_RCC_AHB_DIV_16
 *         @arg @ref LL_RCC_AHB_DIV_64
 *         @arg @ref LL_RCC_AHB_DIV_128
 *         @arg @ref LL_RCC_AHB_DIV_256
 *         @arg @ref LL_RCC_AHB_DIV_512
 * @retval None
 */
static inline void ll_rcc_set_ahb_prescaler(uint32_t prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, prescaler);
}

/**
 * @brief  Configure the system clock source
 * @param  Source This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_PLL
 * @retval None
 */
static inline void ll_rcc_set_sysclk_source(uint32_t Source)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, Source);
}

/**
 * @brief  Get the system clock source
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_HSI
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_HSE
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_PLL
 */
static inline uint32_t ll_rcc_get_sysclk_source(void)
{
  return READ_BIT(RCC->CFGR, RCC_CFGR_SWS);
}

/**
 * @brief  Get the oscillator used as PLL clock source.
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_PLLSOURCE_NONE
 *         @arg @ref LL_RCC_PLLSOURCE_HSI (*)
 *         @arg @ref LL_RCC_PLLSOURCE_HSI_DIV_2 (*)
 *         @arg @ref LL_RCC_PLLSOURCE_HSE
 */
static inline uint32_t ll_rcc_get_pll_source(void)
{
  return READ_BIT(RCC->CFGR, RCC_CFGR_PLLSRC);
}

/**
 * @brief  Get PREDIV division factor for the main PLL
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_PREDIV_DIV_1
 *         @arg @ref LL_RCC_PREDIV_DIV_2
 *         @arg @ref LL_RCC_PREDIV_DIV_3
 *         @arg @ref LL_RCC_PREDIV_DIV_4
 *         @arg @ref LL_RCC_PREDIV_DIV_5
 *         @arg @ref LL_RCC_PREDIV_DIV_6
 *         @arg @ref LL_RCC_PREDIV_DIV_7
 *         @arg @ref LL_RCC_PREDIV_DIV_8
 *         @arg @ref LL_RCC_PREDIV_DIV_9
 *         @arg @ref LL_RCC_PREDIV_DIV_10
 *         @arg @ref LL_RCC_PREDIV_DIV_11
 *         @arg @ref LL_RCC_PREDIV_DIV_12
 *         @arg @ref LL_RCC_PREDIV_DIV_13
 *         @arg @ref LL_RCC_PREDIV_DIV_14
 *         @arg @ref LL_RCC_PREDIV_DIV_15
 *         @arg @ref LL_RCC_PREDIV_DIV_16
 */
static inline uint32_t ll_rcc_get_pll_prediv(void)
{
  return READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV);
}

/**
 * @brief  Get PLL multiplication Factor
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_PLL_MUL_2
 *         @arg @ref LL_RCC_PLL_MUL_3
 *         @arg @ref LL_RCC_PLL_MUL_4
 *         @arg @ref LL_RCC_PLL_MUL_5
 *         @arg @ref LL_RCC_PLL_MUL_6
 *         @arg @ref LL_RCC_PLL_MUL_7
 *         @arg @ref LL_RCC_PLL_MUL_8
 *         @arg @ref LL_RCC_PLL_MUL_9
 *         @arg @ref LL_RCC_PLL_MUL_10
 *         @arg @ref LL_RCC_PLL_MUL_11
 *         @arg @ref LL_RCC_PLL_MUL_12
 *         @arg @ref LL_RCC_PLL_MUL_13
 *         @arg @ref LL_RCC_PLL_MUL_14
 *         @arg @ref LL_RCC_PLL_MUL_15
 *         @arg @ref LL_RCC_PLL_MUL_16
 */
static inline uint32_t ll_rcc_get_pll_multiplicator(void)
{
  return READ_BIT(RCC->CFGR, RCC_CFGR_PLLMUL);
}

uint32_t ll_rcc_get_pll_frequency(void)
{
  uint32_t input, source, multiplicator, prediv;

  source = ll_rcc_get_pll_source();
  prediv = (ll_rcc_get_pll_prediv() >> RCC_CFGR2_PREDIV_Pos) + 1U;
  multiplicator = (ll_rcc_get_pll_multiplicator() >> RCC_CFGR_PLLMUL_Pos) + 2U;
  multiplicator = multiplicator > 16 ? 16 : multiplicator; 

  switch (source)
  {
  case LL_RCC_PLLSOURCE_HSI_DIV_2:
    input = LL_RCC_HSI_VALUE / 2U;
    break;

  case LL_RCC_PLLSOURCE_HSE:
    input = LL_RCC_HSE_VALUE;
    break;

  default:
    input = LL_RCC_HSI_VALUE / 2U;
    break;
  }

  return (input / prediv) * multiplicator;
}

uint32_t ll_rcc_get_sysclk_frequency(void)
{
  switch (ll_rcc_get_sysclk_source())
  {
  case LL_RCC_SYS_CLKSOURCE_STATUS_HSI: /* HSI used as system clock  source */
    return LL_RCC_HSI_VALUE;

  case LL_RCC_SYS_CLKSOURCE_STATUS_HSE: /* HSE used as system clock  source */
    return LL_RCC_HSE_VALUE;

  case LL_RCC_SYS_CLKSOURCE_STATUS_PLL: /* PLL used as system clock  source */
    return ll_rcc_get_pll_frequency();

  default:
    return LL_RCC_HSI_VALUE;
  }
}

#endif /* LL_RCC_H */
