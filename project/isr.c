#include "stm32f3.h"
#include "os.h"

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
    __asm volatile("mrs     r2, psp");
    __asm volatile("stmdb   r2!, {r4-r11}"); 

    __asm volatile("bl      os_get_current_thread");
    __asm volatile("str     r2, [r0]");

    __asm volatile("bl      os_schedule");

    __asm volatile("bl      os_get_current_thread");
    __asm volatile("ldr     r2, [r0]");

    __asm volatile("ldmia   r2!, {r4-r11}");
    __asm volatile("msr     psp, r2");
    __asm volatile("pop     {pc}");
}

__attribute__((naked)) void irq_handler_sv_call(void)
{
    __asm volatile("push    {lr}");
    __asm volatile("bl      os_get_current_thread");
    __asm volatile("ldr     r1, [r0]");
    __asm volatile("ldmia   r1!, {r4-r11}");
    __asm volatile("msr     psp, r1");
    __asm volatile("pop     {pc}");
}

void irq_handler_sys_tick(void)
{
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}
