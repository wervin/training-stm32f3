#include <stdlib.h>
#include <stdint.h>
#include "os.h"
#include "conf.h"
#include "stm32f3.h"
#include "ll/rcc.h"

#define STACK_SIZE 128U // Must be multiple of 8

static void task_exit_trap(void);

struct os_thread _threads[OS_MAX_THREADS] = {0};
uint32_t _thread_count = 0;
volatile uint32_t _current_thread_index = 0;

void os_launch(void)
{
  struct os_thread *thread;

  __disable_irq();

  __NVIC_SetPriorityGrouping(7 - __NVIC_PRIO_BITS); // Use all bits for preemptive priority (no subpriority), enabling 2^__NVIC_PRIO_BITS priority levels
  __NVIC_SetPriority(PendSV_IRQn, 15);
  __NVIC_SetPriority(SVCall_IRQn, 14);
  __NVIC_SetPriority(SysTick_IRQn, 13);

  /* Configure the SysTick to have interrupt in 1ms time base */
  SysTick->LOAD = (uint32_t)((ll_rcc_get_sysclk_frequency() / OS_TICK_FREQUENCY) - 1UL); /* set reload register */
  SysTick->VAL = 0UL;                                                                    /* Load the SysTick Counter Value */
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                  SysTick_CTRL_ENABLE_Msk |
                  SysTick_CTRL_TICKINT_Msk;

  thread = &_threads[_current_thread_index];
  thread->status = OS_TRHEAD_STATUS_ACTIVE;
  __set_PSP((uint32_t)thread->sp);
  __set_CONTROL(__get_CONTROL() | 2U);

  __enable_irq();

  __asm volatile("svc #0");

  while (1)
    ;
}

void os_schedule(void)
{
  struct os_thread *thread;
  thread = &_threads[_current_thread_index];
  thread->status = OS_THREAD_STATUS_IDLE;
  _current_thread_index = (_current_thread_index + 1) % _thread_count;
  thread = &_threads[_current_thread_index];
  thread->status = OS_TRHEAD_STATUS_ACTIVE;
}

struct os_thread *os_get_current_thread(void)
{
  return &_threads[_current_thread_index];
}

void os_create_thread(void (*task)(void), uint32_t *stack, uint32_t size)
{
  struct os_thread *thread;

  if (_thread_count >= OS_MAX_THREADS)
    return;

  thread = &_threads[_thread_count];
  thread->status = OS_THREAD_STATUS_IDLE;
  thread->sp = &stack[size - 1];
  *(thread->sp--) = 0x01000000;               /* xPSR (Thumb bit) */
  *(thread->sp--) = (uint32_t)task;           /* PC */
  *(thread->sp--) = (uint32_t)task_exit_trap; /* LR */
  *(thread->sp--) = 0x12121212;               /* R12 */
  *(thread->sp--) = 0x03030303;               /* R3 */
  *(thread->sp--) = 0x02020202;               /* R2 */
  *(thread->sp--) = 0x01010101;               /* R1 */
  *(thread->sp--) = 0x00000000;               /* R0 */
  *(thread->sp--) = 0x11111111;               /* R11 */
  *(thread->sp--) = 0x10101010;               /* R10 */
  *(thread->sp--) = 0x09090909;               /* R9 */
  *(thread->sp--) = 0x08080808;               /* R8 */
  *(thread->sp--) = 0x07070707;               /* R7 */
  *(thread->sp--) = 0x06060606;               /* R6 */
  *(thread->sp--) = 0x05050505;               /* R5 */
  *(thread->sp) = 0x04040404;                 /* R4 */

  _thread_count++;
}

static void task_exit_trap(void)
{
  while (1)
    ;
}
