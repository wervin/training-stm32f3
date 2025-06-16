#include "ll/rcc.h"
#include "ll/flash.h"
#include "ll/systick.h"
#include "ll/bus.h"
#include "ll/io.h"

static void _config_system_clock(void);
static void _config_io(void);

int main(void)
{
    _config_system_clock();
    _config_io();
    while (1)
        ;
}

static void _config_system_clock(void)
{
    ll_flash_set_latency(LL_FLASH_LATENCY_2);
    ll_rcc_enable_hsi();
    while (!ll_rcc_is_hsi_ready())
        ;
    ll_rcc_config_pll(LL_RCC_PLLSOURCE_HSI_DIV_2, LL_RCC_PLL_MUL_16);
    ll_rcc_enable_pll();
    while (!lc_rcc_is_pll_ready())
        ;
    ll_rcc_set_ahb_prescaler(LL_RCC_AHB_DIV_1);
    ll_rcc_set_sysclk_source(LL_RCC_SYS_CLKSOURCE_PLL);
    while (ll_rcc_get_sysclk_source() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
        ;
    ll_rcc_set_apb1_prescaler(LL_RCC_APB1_DIV_2);
    ll_rcc_set_apb2_prescaler(LL_RCC_APB2_DIV_1);

    ll_systick_init(1000);
}

static void _config_io(void)
{
    ll_bus_ahb1_grp1_enable_clock(LL_BUS_AHB1_GRP1_PERIPH_GPIOE);
    ll_io_clear_pin(GPIOE, LL_IO_PIN_15);
    ll_io_set_mode(GPIOE, LL_IO_PIN_15, LL_IO_MODE_OUTPUT);
    ll_io_set_pin(GPIOE, LL_IO_PIN_15);
}
