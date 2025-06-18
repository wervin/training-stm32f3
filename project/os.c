#include <stdlib.h>
#include <stdint.h>
#include "os.h"
#include "conf.h"
#include "stm32f3.h"
#include "ll/rcc.h"

#define IDLE_STACK_SIZE 64U

static void _update_thread_status(void);
static void _update_current_thread(void);
static void _idle_task(void);
static void _thread_exit_trap(void);

struct os_context _context = {0};
static volatile uint64_t _ticks = 0;
static struct os_thread _idle_thread = {0};
static uint32_t _idle_thread_stack[IDLE_STACK_SIZE] = {0};

void os_launch(void)
{
  _idle_thread.sp = &_idle_thread_stack[IDLE_STACK_SIZE - 1];
  *(_idle_thread.sp--) = 0x01000000;                  /* xPSR (Thumb bit) */
  *(_idle_thread.sp--) = (uint32_t)_idle_task;        /* PC */
  *(_idle_thread.sp--) = (uint32_t)_thread_exit_trap; /* LR */
  *(_idle_thread.sp--) = 0x12121212;                  /* R12 */
  *(_idle_thread.sp--) = 0x03030303;                  /* R3 */
  *(_idle_thread.sp--) = 0x02020202;                  /* R2 */
  *(_idle_thread.sp--) = 0x01010101;                  /* R1 */
  *(_idle_thread.sp--) = 0x00000000;                  /* R0 */
  *(_idle_thread.sp--) = 0x11111111;                  /* R11 */
  *(_idle_thread.sp--) = 0x10101010;                  /* R10 */
  *(_idle_thread.sp--) = 0x09090909;                  /* R9 */
  *(_idle_thread.sp--) = 0x08080808;                  /* R8 */
  *(_idle_thread.sp--) = 0x07070707;                  /* R7 */
  *(_idle_thread.sp--) = 0x06060606;                  /* R6 */
  *(_idle_thread.sp--) = 0x05050505;                  /* R5 */
  *(_idle_thread.sp) = 0x04040404;                    /* R4 */

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

  _context.current_thread = &_idle_thread;
  __set_PSP((uint32_t)_context.current_thread->sp);
  __set_CONTROL(__get_CONTROL() | 2U);

  __enable_irq();

  __asm volatile("svc #0");

  while (1)
    ;
}

void os_schedule(void)
{
  _update_thread_status();
  _update_current_thread();
  _ticks++;
}

void os_delay(uint32_t ticks)
{
  _context.current_thread->delay_until = _ticks + ticks;
  _context.current_thread->status = OS_THREAD_STATUS_IDLE;
  _update_thread_status();
  _update_current_thread();
  SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}

struct os_context *os_get_context(void)
{
  return &_context;
}

void os_create_thread(void (*task)(void), uint32_t *stack, uint32_t size)
{
  struct os_thread *thread;

  if (_context.thread_count >= OS_MAX_THREADS)
    return;

  thread = &_context.threads[_context.thread_count];
  thread->status = OS_THREAD_STATUS_IDLE;
  thread->sp = &stack[size - 1];
  *(thread->sp--) = 0x01000000;                  /* xPSR (Thumb bit) */
  *(thread->sp--) = (uint32_t)task;              /* PC */
  *(thread->sp--) = (uint32_t)_thread_exit_trap; /* LR */
  *(thread->sp--) = 0x12121212;                  /* R12 */
  *(thread->sp--) = 0x03030303;                  /* R3 */
  *(thread->sp--) = 0x02020202;                  /* R2 */
  *(thread->sp--) = 0x01010101;                  /* R1 */
  *(thread->sp--) = 0x00000000;                  /* R0 */
  *(thread->sp--) = 0x11111111;                  /* R11 */
  *(thread->sp--) = 0x10101010;                  /* R10 */
  *(thread->sp--) = 0x09090909;                  /* R9 */
  *(thread->sp--) = 0x08080808;                  /* R8 */
  *(thread->sp--) = 0x07070707;                  /* R7 */
  *(thread->sp--) = 0x06060606;                  /* R6 */
  *(thread->sp--) = 0x05050505;                  /* R5 */
  *(thread->sp) = 0x04040404;                    /* R4 */

  _context.thread_count++;
}

static void _update_thread_status(void)
{
  _context.previous_thread = _context.current_thread;

  for (uint32_t i = 0; i < _context.thread_count; i++)
  {
    if (_context.threads[i].status == OS_THREAD_STATUS_IDLE && _ticks >= _context.threads[i].delay_until)
      _context.threads[i].status = OS_TRHEAD_STATUS_ACTIVE;
  }
}

static void _update_current_thread(void)
{
  for (uint32_t i = 1; i <= _context.thread_count; i++)
  {
    uint32_t j = (_context.current_thread_index + i) % _context.thread_count;
    if (_context.threads[j].status == OS_TRHEAD_STATUS_ACTIVE)
    {
      _context.current_thread_index = j;
      _context.current_thread = &_context.threads[j];
      return;
    }
  }
  _context.current_thread = &_idle_thread;
}

static void _idle_task(void)
{
  while (1)
  {
    __WFI();
  }
}

static void _thread_exit_trap(void)
{
  while (1)
    ;
}
