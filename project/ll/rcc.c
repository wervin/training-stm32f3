#include "rcc.h"

static uint32_t _get_usart1_frequency(void);
static uint32_t _get_usart2_frequency(void);
static uint32_t _get_usart3_frequency(void);

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

const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8] = {0, 0, 0, 0, 1, 2, 3, 4};

uint32_t ll_rcc_get_hclk_frequency(void)
{
  uint32_t sysclk_frequency = ll_rcc_get_sysclk_frequency();
  uint32_t ahb_prescaler = ll_rcc_get_ahb_prescaler();
  return sysclk_frequency >> AHBPrescTable[(ahb_prescaler & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos];
}

uint32_t ll_rcc_get_pclk1_frequency(void)
{
  uint32_t hclk_frequency = ll_rcc_get_hclk_frequency();
  uint32_t apb1_prescaler = ll_rcc_get_apb1_prescaler();
  return hclk_frequency >> APBPrescTable[(apb1_prescaler & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos];
}

uint32_t ll_rcc_get_pclk2_frequency(void)
{
  uint32_t hclk_frequency = ll_rcc_get_hclk_frequency();
  uint32_t apb2_prescaler = ll_rcc_get_apb2_prescaler();
  return hclk_frequency >> APBPrescTable[(apb2_prescaler & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos];
}

uint32_t ll_rcc_get_usart_frequency(USART_TypeDef *usart)
{
    if (usart == USART1)
      return _get_usart1_frequency();
    else if (usart == USART2)
      return _get_usart2_frequency();
    else if (usart == USART3)
      return _get_usart3_frequency();
    else
        return 0;
}

uint32_t _get_usart1_frequency(void)
{
  switch (ll_rcc_get_usart1_clock_source())
  {
  case LL_RCC_USART1_CLKSOURCE_SYSCLK:
    return ll_rcc_get_sysclk_frequency();

  case LL_RCC_USART1_CLKSOURCE_HSI:
    return LL_RCC_HSI_VALUE;

  case LL_RCC_USART1_CLKSOURCE_LSE:
    return LL_RCC_LSE_VALUE;

  case LL_RCC_USART1_CLKSOURCE_PCLK2:
  default:
    return ll_rcc_get_pclk2_frequency();
  }
}

uint32_t _get_usart2_frequency(void)
{
  switch (ll_rcc_get_usart2_clock_source())
  {
  case LL_RCC_USART2_CLKSOURCE_SYSCLK:
    return ll_rcc_get_sysclk_frequency();

  case LL_RCC_USART2_CLKSOURCE_HSI:
    return LL_RCC_HSI_VALUE;

  case LL_RCC_USART2_CLKSOURCE_LSE:
    return LL_RCC_LSE_VALUE;

  case LL_RCC_USART2_CLKSOURCE_PCLK1:
  default:
    return ll_rcc_get_pclk1_frequency();
  }
}

uint32_t _get_usart3_frequency(void)
{
  switch (ll_rcc_get_usart3_clock_source())
  {
  case LL_RCC_USART3_CLKSOURCE_SYSCLK:
    return ll_rcc_get_sysclk_frequency();

  case LL_RCC_USART3_CLKSOURCE_HSI:
    return LL_RCC_HSI_VALUE;

  case LL_RCC_USART3_CLKSOURCE_LSE:
    return LL_RCC_LSE_VALUE;

  case LL_RCC_USART3_CLKSOURCE_PCLK1:
  default:
    return ll_rcc_get_pclk1_frequency();
  }
}
