#include "stm32f3.h"

#define DEFAULT __attribute__((weak, alias("irq_handler_default")))

void irq_handler_reset(void);

DEFAULT void irq_handler_nmi(void);
DEFAULT void irq_handler_hard_fault(void);
DEFAULT void irq_handler_mem_mngmt(void);
DEFAULT void irq_handler_bus_fault(void);
DEFAULT void irq_handler_usage_fault(void);
DEFAULT void irq_handler_sv_call(void);
DEFAULT void irq_handler_pend_sv(void);
DEFAULT void irq_handler_sys_tick(void);

DEFAULT void irq_handler_wwdg(void);
DEFAULT void irq_handler_pvd(void);
DEFAULT void irq_handler_tamper_stamp(void);
DEFAULT void irq_handler_rtc_wakeup(void);
DEFAULT void irq_handler_flash(void);
DEFAULT void irq_handler_rcc(void);
DEFAULT void irq_handler_exti0(void);
DEFAULT void irq_handler_exti1(void);
DEFAULT void irq_handler_exti2_ts(void);
DEFAULT void irq_handler_exti3(void);
DEFAULT void irq_handler_exti4(void);
DEFAULT void irq_handler_dma1_channel1(void);
DEFAULT void irq_handler_dma1_channel2(void);
DEFAULT void irq_handler_dma1_channel3(void);
DEFAULT void irq_handler_dma1_channel4(void);
DEFAULT void irq_handler_dma1_channel5(void);
DEFAULT void irq_handler_dma1_channel6(void);
DEFAULT void irq_handler_dma1_channel7(void);
DEFAULT void irq_handler_adc1_2(void);
DEFAULT void irq_handler_usb_hp_can_tx(void);
DEFAULT void irq_handler_usb_lp_can_rx0(void);
DEFAULT void irq_handler_can_rx1(void);
DEFAULT void irq_handler_can_sce(void);
DEFAULT void irq_handler_exti9_5(void);
DEFAULT void irq_handler_tim1_brk_tim15(void);
DEFAULT void irq_handler_tim1_up_tim16(void);
DEFAULT void irq_handler_tim1_trg_com_tim17(void);
DEFAULT void irq_handler_tim1_cc(void);
DEFAULT void irq_handler_tim2(void);
DEFAULT void irq_handler_tim3(void);
DEFAULT void irq_handler_tim4(void);
DEFAULT void irq_handler_i2c1_ev(void);
DEFAULT void irq_handler_i2c1_er(void);
DEFAULT void irq_handler_i2c2_ev(void);
DEFAULT void irq_handler_i2c2_er(void);
DEFAULT void irq_handler_spi1(void);
DEFAULT void irq_handler_spi2(void);
DEFAULT void irq_handler_usart1(void);
DEFAULT void irq_handler_usart2(void);
DEFAULT void irq_handler_usart3(void);
DEFAULT void irq_handler_exti15_10(void);
DEFAULT void irq_handler_rtc_alarm(void);
DEFAULT void irq_handler_usb_wakeup(void);
DEFAULT void irq_handler_tim8_brk(void);
DEFAULT void irq_handler_tim8_up(void);
DEFAULT void irq_handler_tim8_trg_com(void);
DEFAULT void irq_handler_tim8_cc(void);
DEFAULT void irq_handler_adc3(void);
DEFAULT void irq_handler_fmc(void);
DEFAULT void irq_handler_spi3(void);
DEFAULT void irq_handler_uart4(void);
DEFAULT void irq_handler_uart5(void);
DEFAULT void irq_handler_tim6_dac(void);
DEFAULT void irq_handler_tim7(void);
DEFAULT void irq_handler_dma2_channel1(void);
DEFAULT void irq_handler_dma2_channel2(void);
DEFAULT void irq_handler_dma2_channel3(void);
DEFAULT void irq_handler_dma2_channel4(void);
DEFAULT void irq_handler_dma2_channel5(void);
DEFAULT void irq_handler_adc4(void);
DEFAULT void irq_handler_comp123(void);
DEFAULT void irq_handler_comp456(void);
DEFAULT void irq_handler_comp7(void);
DEFAULT void irq_handler_hrtim1_master(void);
DEFAULT void irq_handler_hrtim1_tima(void);
DEFAULT void irq_handler_hrtim1_timb(void);
DEFAULT void irq_handler_hrtim1_timc(void);
DEFAULT void irq_handler_hrtim1_timd(void);
DEFAULT void irq_handler_hrtim1_time(void);
DEFAULT void irq_handler_hrtim1_fault(void);
DEFAULT void irq_handler_dfsdm1_flt0(void);
DEFAULT void irq_handler_dfsdm1_flt1(void);
DEFAULT void irq_handler_dfsdm1_flt2(void);
DEFAULT void irq_handler_dfsdm1_flt3(void);
DEFAULT void irq_handler_sai1(void);
DEFAULT void irq_handler_tim20_brk(void);
DEFAULT void irq_handler_tim20_up(void);
DEFAULT void irq_handler_tim20_trg_com(void);
DEFAULT void irq_handler_tim20_cc(void);
DEFAULT void irq_handler_fpu(void);
DEFAULT void irq_handler_spi4(void);
DEFAULT void irq_handler_reserved81(void);

extern int main(void);

extern void _msp(void);
extern uint32_t _etext;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _bss;
extern uint32_t _ebss;

__attribute__((used, section(".vectors"))) void (*const vectors[])(void) =
    {
        &_msp,                          // 0 - Initial Stack Pointer Value
        irq_handler_reset,              // 1 - Reset
        irq_handler_nmi,                // 2 - NMI
        irq_handler_hard_fault,         // 3 - Hard Fault
        irq_handler_mem_mngmt,          // 4 - Memory Management
        irq_handler_bus_fault,          // 5 - Bus Fault
        irq_handler_usage_fault,        // 6 - Usage Fault
        0,                              // 7 - Reserved
        0,                              // 8 - Reserved
        0,                              // 9 - Reserved
        0,                              // 10 - Reserved
        irq_handler_sv_call,            // 11 - SVCall
        0,                              // 12 - Reserved
        0,                              // 13 - Reserved
        irq_handler_pend_sv,            // 14 - PendSV
        irq_handler_sys_tick,           // 15 - SysTick
        irq_handler_wwdg,               // 0 - Window watchdog interrupt
        irq_handler_pvd,                // 1 - PVD through EXTI Line16 detection interrupt
        irq_handler_tamper_stamp,       // 2 - Tamper and TimeStamp interrupts through EXTI Line19
        irq_handler_rtc_wakeup,         // 3 - RTC wakeup timer interrupt through EXTI Line20
        irq_handler_flash,              // 4 - FLASH global interrupt
        irq_handler_rcc,                // 5 - RCC global interrupt
        irq_handler_exti0,              // 6 - EXTI Line0 interrupt
        irq_handler_exti1,              // 7 - EXTI Line1 interrupt
        irq_handler_exti2_ts,           // 8 - EXTI Line2 and Touch Sense interrupt
        irq_handler_exti3,              // 9 - EXTI Line3 interrupt
        irq_handler_exti4,              // 10 - EXTI Line4 interrupt
        irq_handler_dma1_channel1,      // 11 - DMA1 Channel1 global interrupt
        irq_handler_dma1_channel2,      // 12 - DMA1 Channel2 global interrupt
        irq_handler_dma1_channel3,      // 13 - DMA1 Channel3 global interrupt
        irq_handler_dma1_channel4,      // 14 - DMA1 Channel4 global interrupt
        irq_handler_dma1_channel5,      // 15 - DMA1 Channel5 global interrupt
        irq_handler_dma1_channel6,      // 16 - DMA1 Channel6 global interrupt
        irq_handler_dma1_channel7,      // 17 - DMA1 Channel7 global interrupt
        irq_handler_adc1_2,             // 18 - ADC1 and ADC2 global interrupt
        irq_handler_usb_hp_can_tx,      // 19 - USB High Priority or CAN TX interrupts
        irq_handler_usb_lp_can_rx0,     // 20 - USB Low Priority or CAN RX0 interrupts
        irq_handler_can_rx1,            // 21 - CAN RX1 interrupt
        irq_handler_can_sce,            // 22 - CAN SCE interrupt
        irq_handler_exti9_5,            // 23 - EXTI Line[9:5] interrupts
        irq_handler_tim1_brk_tim15,     // 24 - TIM1 Break and TIM15 global interrupts
        irq_handler_tim1_up_tim16,      // 25 - TIM1 Update and TIM16 global interrupts
        irq_handler_tim1_trg_com_tim17, // 26 - TIM1 Trigger and Commutation and TIM17 global interrupts
        irq_handler_tim1_cc,            // 27 - TIM1 Capture Compare interrupt
        irq_handler_tim2,               // 28 - TIM2 global interrupt
        irq_handler_tim3,               // 29 - TIM3 global interrupt
        irq_handler_tim4,               // 30 - TIM4 global interrupt
        irq_handler_i2c1_ev,            // 31 - I2C1 Event interrupt
        irq_handler_i2c1_er,            // 32 - I2C1 Error interrupt
        irq_handler_i2c2_ev,            // 33 - I2C2 Event interrupt
        irq_handler_i2c2_er,            // 34 - I2C2 Error interrupt
        irq_handler_spi1,               // 35 - SPI1 global interrupt
        irq_handler_spi2,               // 36 - SPI2 global interrupt
        irq_handler_usart1,             // 37 - USART1 global interrupt
        irq_handler_usart2,             // 38 - USART2 global interrupt
        irq_handler_usart3,             // 39 - USART3 global interrupt
        irq_handler_exti15_10,          // 40 - EXTI Line[15:10] interrupts
        irq_handler_rtc_alarm,          // 41 - RTC Alarms (A and B) through EXTI Line18 interrupt
        irq_handler_usb_wakeup,         // 42 - USB Wakeup from suspend through EXTI Line interrupt
        irq_handler_tim8_brk,           // 43 - TIM8 Break interrupt
        irq_handler_tim8_up,            // 44 - TIM8 Update interrupt
        irq_handler_tim8_trg_com,       // 45 - TIM8 Trigger and Commutation interrupt
        irq_handler_tim8_cc,            // 46 - TIM8 Capture Compare interrupt
        irq_handler_adc3,               // 47 - ADC3 global interrupt
        irq_handler_fmc,                // 48 - FMC interrupt (or reserved)
        irq_handler_spi3,               // 49 - SPI3 global interrupt
        irq_handler_uart4,              // 50 - UART4 global interrupt
        irq_handler_uart5,              // 51 - UART5 global interrupt
        irq_handler_tim6_dac,           // 52 - TIM6 and DAC1, DAC2 underrun errors
        irq_handler_tim7,               // 53 - TIM7 global interrupt
        irq_handler_dma2_channel1,      // 54 - DMA2 Channel1 global interrupt
        irq_handler_dma2_channel2,      // 55 - DMA2 Channel2 global interrupt
        irq_handler_dma2_channel3,      // 56 - DMA2 Channel3 global interrupt
        irq_handler_dma2_channel4,      // 57 - DMA2 Channel4 global interrupt
        irq_handler_dma2_channel5,      // 58 - DMA2 Channel5 global interrupt
        irq_handler_adc4,               // 59 - ADC4 global interrupt
        irq_handler_comp123,            // 60 - COMP1/2/3 interrupts
        irq_handler_comp456,            // 61 - COMP4/5/6 interrupts
        irq_handler_comp7,              // 62 - COMP7 interrupt
        irq_handler_hrtim1_master,      // 63 - HRTIM Master Timer global interrupt
        irq_handler_hrtim1_tima,        // 64 - HRTIM Timer A global interrupt
        irq_handler_hrtim1_timb,        // 65 - HRTIM Timer B global interrupt
        irq_handler_hrtim1_timc,        // 66 - HRTIM Timer C global interrupt
        irq_handler_hrtim1_timd,        // 67 - HRTIM Timer D global interrupt
        irq_handler_hrtim1_time,        // 68 - HRTIM Timer E global interrupt
        irq_handler_hrtim1_fault,       // 69 - HRTIM Fault global interrupt
        irq_handler_dfsdm1_flt0,        // 70 - DFSDM1 Filter0 global interrupt
        irq_handler_dfsdm1_flt1,        // 71 - DFSDM1 Filter1 global interrupt
        irq_handler_dfsdm1_flt2,        // 72 - DFSDM1 Filter2 global interrupt
        irq_handler_dfsdm1_flt3,        // 73 - DFSDM1 Filter3 global interrupt
        irq_handler_sai1,               // 74 - SAI1 global interrupt
        irq_handler_tim20_brk,          // 75 - TIM20 Break interrupt
        irq_handler_tim20_up,           // 76 - TIM20 Update interrupt
        irq_handler_tim20_trg_com,      // 77 - TIM20 Trigger and Commutation interrupt
        irq_handler_tim20_cc,           // 78 - TIM20 Capture Compare interrupt
        irq_handler_fpu,                // 79 - Floating point unit interrupt
        irq_handler_spi4,               // 80 - SPI4 global interrupt
};

void irq_handler_reset(void)
{
    uint32_t *src, *dst;

    src = &_etext;
    dst = &_data;
    while (dst < &_edata)
        *dst++ = *src++;

    dst = &_bss;
    while (dst < &_ebss)
        *dst++ = 0;

    SCB->VTOR = (uint32_t)vectors;

    main();

    while (1)
        ;
}

void irq_handler_default(void)
{
    while (1)
        ;
}
