#include "rcc.h"

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
