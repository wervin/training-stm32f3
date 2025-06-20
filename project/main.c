#include "ll/rcc.h"
#include "ll/flash.h"
#include "ll/bus.h"
#include "ll/io.h"
#include "ll/usart.h"
#include "os.h"
#include <stdio.h>
#include <string.h>

static void _config_system_clock(void);
static void _config_leds(void);
static void _config_usart(void);

static uint32_t stack0[128] = {0};
static uint32_t stack1[128] = {0};
static uint32_t stack2[128] = {0};

void task0(void)
{
    static char buffer[32] = {0};
    static int i = 0;
    while (1)
    {
        __disable_irq();
        uint8_t c = ll_usart_getc(USART1);
        if (c)
            buffer[i++] = c;
      
        if (i > 0 && buffer[i-1] == '\r')
        {
            printf("Final buffer: %s\n", buffer);
            i = 0;
            memset(buffer, 0, 32);
        }

        __enable_irq();
    }
}

void task1(void)
{
    while (1)
    {
        __disable_irq();
        GPIOE->ODR ^= LL_IO_PIN_14;
        printf("task1\r\n");
        __enable_irq();
        os_delay(1000);
    }
}

void task2(void)
{
    while (1)
    {
        __disable_irq();
        GPIOE->ODR ^= LL_IO_PIN_13;
        printf("task2\r\n");
        __enable_irq();
        os_delay(2000);
    }
}

int main(void)
{
    os_init();

    _config_system_clock();
    _config_leds();
    _config_usart();

    os_create_thread(task0, stack0, 128);
    os_create_thread(task1, stack1, 128);
    os_create_thread(task2, stack2, 128);

    os_launch();

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
}

static void _config_leds(void)
{
    ll_bus_ahb1_grp1_enable_clock(LL_BUS_AHB1_GRP1_PERIPH_GPIOE);
    ll_io_clear_pin(GPIOE, LL_IO_PIN_15);
    ll_io_set_mode(GPIOE, LL_IO_PIN_15, LL_IO_MODE_OUTPUT);

    ll_io_clear_pin(GPIOE, LL_IO_PIN_14);
    ll_io_set_mode(GPIOE, LL_IO_PIN_14, LL_IO_MODE_OUTPUT);

    ll_io_clear_pin(GPIOE, LL_IO_PIN_13);
    ll_io_set_mode(GPIOE, LL_IO_PIN_13, LL_IO_MODE_OUTPUT);
}

static void _config_usart(void)
{
    ll_bus_ahb1_grp1_enable_clock(LL_BUS_AHB1_GRP1_PERIPH_GPIOC);

    ll_io_set_mode(GPIOC, LL_IO_PIN_4, LL_IO_MODE_ALTERNATE);
    ll_io_set_speed(GPIOC, LL_IO_PIN_4, LL_IO_SPEED_FREQ_HIGH);
    ll_io_set_output(GPIOC, LL_IO_PIN_4, LL_IO_OUTPUT_PUSHPULL);
    ll_io_set_pull(GPIOC, LL_IO_PIN_4, LL_IO_PULL_UP);
    ll_io_set_af(GPIOC, LL_IO_PIN_4, LL_IO_AF_7);

    ll_io_set_mode(GPIOC, LL_IO_PIN_5, LL_IO_MODE_ALTERNATE);
    ll_io_set_speed(GPIOC, LL_IO_PIN_5, LL_IO_SPEED_FREQ_HIGH);
    ll_io_set_output(GPIOC, LL_IO_PIN_5, LL_IO_OUTPUT_PUSHPULL);
    ll_io_set_pull(GPIOC, LL_IO_PIN_5, LL_IO_PULL_UP);
    ll_io_set_af(GPIOC, LL_IO_PIN_5, LL_IO_AF_7);

    NVIC_SetPriority(USART1_IRQn, 0);
    NVIC_EnableIRQ(USART1_IRQn);

    ll_bus_apb2_grp1_enable_clock(LL_APB2_GRP1_PERIPH_USART1);
    ll_rcc_set_usart1_clock_source(LL_RCC_USART1_CLKSOURCE_PCLK2);

    ll_usart_disable(USART1);
    ll_usart_set_direction(USART1, LL_USART_DIRECTION_TX_RX);
    ll_usart_set_datawidth(USART1, LL_USART_DATAWIDTH_8B);
    ll_usart_set_parity(USART1, LL_USART_PARITY_NONE);
    ll_usart_set_stopbits(USART1, LL_USART_STOPBITS_1);
    ll_usart_set_hwcontrol(USART1, LL_USART_HWCONTROL_NONE);
    ll_usart_set_oversampling(USART1, LL_USART_OVERSAMPLING_16);
    ll_usart_set_baudrate(USART1, 115200);
    ll_usart_enable(USART1);
    while ((!(ll_usart_is_teack_flag_active(USART1))) || (!(ll_usart_is_reack_flag_active(USART1))))
        ;

    ll_usart_enable_rxne_it(USART1);
    ll_usart_enable_error_it(USART1);
}
