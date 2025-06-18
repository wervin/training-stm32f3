#ifndef OS_H
#define OS_H

enum os_thread_status
{
    OS_THREAD_STATUS_IDLE,
    OS_TRHEAD_STATUS_ACTIVE
};

struct os_thread
{
    uint32_t *sp;
    enum os_thread_status status;
};

void os_launch(void);
void os_schedule(void);
struct os_thread *os_get_current_thread(void);
void os_create_thread(void (*task)(void), uint32_t *stack, uint32_t size);

#endif /* OS_H */
