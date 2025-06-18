#ifndef OS_H
#define OS_H

#include "conf.h"

enum os_thread_status
{
    OS_THREAD_STATUS_IDLE,
    OS_TRHEAD_STATUS_ACTIVE
};

struct os_thread
{
    uint32_t *sp;
    uint32_t delay_until;
    enum os_thread_status status;
};

struct os_context
{
    struct os_thread threads[OS_MAX_THREADS];
    uint32_t thread_count;
    struct os_thread *previous_thread;
    struct os_thread *current_thread;
    uint32_t current_thread_index;
};

void os_launch(void);
void os_schedule(void);
void os_delay(uint32_t ticks);
struct os_context *os_get_context(void);
void os_create_thread(void (*task)(void), uint32_t *stack, uint32_t size);

#endif /* OS_H */
