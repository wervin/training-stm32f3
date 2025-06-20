#include "stm32f3.h"
#include "os.h"
#include "ll/usart.h"

extern uint32_t *task_sp;

void irq_handler_nmi(void)
{
    while (1)
        ;
}

void irq_handler_hard_fault(void)
{
    while (1)
        ;
}

void irq_handler_mem_mngmt(void)
{
    while (1)
        ;
}

void irq_handler_bus_fault(void)
{
    while (1)
        ;
}

void irq_handler_usage_fault(void)
{
    while (1)
        ;
}

__attribute__((naked)) void irq_handler_pend_sv(void)
{
    __asm volatile("push    {lr}");
    __asm volatile("mrs     r3, psp");
    __asm volatile("stmdb   r3!, {r4-r11}");

    __asm volatile("bl      os_get_context");
    __asm volatile("ldr     r1, [r0, #0x64]");
    __asm volatile("ldr     r2, [r0, #0x68]");
    __asm volatile("str     r3, [r1]");
    __asm volatile("ldr     r3, [r2]");

    __asm volatile("ldmia   r3!, {r4-r11}");
    __asm volatile("msr     psp, r3");
    __asm volatile("pop     {pc}");
}

__attribute__((naked)) void irq_handler_sv_call(void)
{
    __asm volatile("push    {lr}");
    __asm volatile("bl      os_get_context");
    __asm volatile("ldr     r0, [r0, #0x68]");
    __asm volatile("ldr     r1, [r0]");
    __asm volatile("ldmia   r1!, {r4-r11}");
    __asm volatile("msr     psp, r1");
    __asm volatile("pop     {pc}");
}

void irq_handler_sys_tick(void)
{
    os_schedule();
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}

void irq_handler_usart1(void)
{
    ll_usart_handler(USART1);
}
