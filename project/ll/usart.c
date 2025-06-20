#include "usart.h"

#define USART_BUFFER_SIZE 32U

struct _usart_context {
    USART_TypeDef *handle;
    volatile uint8_t buffer[USART_BUFFER_SIZE];
    volatile uint32_t write_idx;
    volatile uint32_t read_idx;
};

static void _error_trap(void);

static void _usart_rxne_handler(const USART_TypeDef *usart);
static void _usart_rxne_cb(struct _usart_context *usart_context);
static uint8_t _usart_getc_cb(struct _usart_context *usart_context);

static struct _usart_context _usart1_context = {
    .handle = USART1,
    .buffer = {0},
    .read_idx = 0,
    .write_idx = 0};

static struct _usart_context _usart2_context = {
    .handle = USART2,
    .buffer = {0},
    .read_idx = 0,
    .write_idx = 0};

static struct _usart_context _usart3_context = {
    .handle = USART3,
    .buffer = {0},
    .read_idx = 0,
    .write_idx = 0};

void ll_usart_handler(const USART_TypeDef *usart)
{
    /* Check RXNE flag value in ISR register */
    if (ll_usart_is_rxne_flag_active(usart) && ll_usart_is_rxne_it_enabled(usart))
    {
        /* RXNE flag will be cleared by reading of RDR register (done in call) */
        /* Call function in charge of handling Character reception */
        _usart_rxne_handler(usart);
    }
    else
        _error_trap();
}

uint8_t ll_usart_getc(const USART_TypeDef *usart)
{
    if (usart == USART1)
    {
        return _usart_getc_cb(&_usart1_context);
    }
    else if (usart == USART2)
    {
        return _usart_getc_cb(&_usart2_context);
    }
    else if (usart == USART3)
    {
        return _usart_getc_cb(&_usart3_context);
    }
    else
        _error_trap();

    return 0;
}

void ll_usart_putc(USART_TypeDef *usart, uint8_t c)
{
    while (!ll_usart_is_txe_flag_active(usart))
        ;
    ll_usart_write8(usart, c);
}

static void _error_trap(void)
{
    while (1)
        ;
}

static void _usart_rxne_handler(const USART_TypeDef *usart)
{
    if (usart == USART1)
    {
        _usart_rxne_cb(&_usart1_context);
    }
    else if (usart == USART2)
    {
        _usart_rxne_cb(&_usart2_context);
    }
    else if (usart == USART3)
    {
        _usart_rxne_cb(&_usart3_context);
    }
    else
        _error_trap();
}

static void _usart_rxne_cb(struct _usart_context *ctx) {
    uint32_t next = (ctx->write_idx + 1) & (USART_BUFFER_SIZE - 1);
    uint8_t c = ll_usart_read8(ctx->handle);
    if (next != ctx->read_idx) {
        ctx->buffer[ctx->write_idx] = c;
        ctx->write_idx = next;
    }
}

static uint8_t _usart_getc_cb(struct _usart_context *ctx) {
    if (ctx->write_idx == ctx->read_idx) return 0;
    uint8_t c = ctx->buffer[ctx->read_idx];
    ctx->read_idx = (ctx->read_idx + 1) & (USART_BUFFER_SIZE - 1);
    return c;
}
