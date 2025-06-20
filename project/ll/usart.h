#ifndef LL_USART_H
#define LL_USART_H

#include <stdint.h>
#include "stm32f3.h"
#include "utils.h"
#include "rcc.h"

#define LL_USART_DIRECTION_NONE 0x00000000U                    /* Transmitter and Receiver are disabled */
#define LL_USART_DIRECTION_RX USART_CR1_RE                     /* Transmitter is disabled and Receiver is enabled */
#define LL_USART_DIRECTION_TX USART_CR1_TE                     /* Transmitter is enabled and Receiver is disabled */
#define LL_USART_DIRECTION_TX_RX (USART_CR1_TE | USART_CR1_RE) /* Transmitter and Receiver are enabled */

#define LL_USART_PARITY_NONE 0x00000000U                   /* Parity control disabled */
#define LL_USART_PARITY_EVEN USART_CR1_PCE                 /* Parity control enabled and Even Parity is selected */
#define LL_USART_PARITY_ODD (USART_CR1_PCE | USART_CR1_PS) /* Parity control enabled and Odd Parity is selected */

#define LL_USART_DATAWIDTH_8B 0x00000000U /* 8 bits word length : Start bit, 8 data bits, n stop bits */
#define LL_USART_DATAWIDTH_9B USART_CR1_M /* 9 bits word length : Start bit, 9 data bits, n stop bits */

#define LL_USART_STOPBITS_0_5 USART_CR2_STOP_0                      /* 0.5 stop bit */
#define LL_USART_STOPBITS_1 0x00000000U                             /* 1 stop bit */
#define LL_USART_STOPBITS_1_5 (USART_CR2_STOP_0 | USART_CR2_STOP_1) /* 1.5 stop bits */
#define LL_USART_STOPBITS_2 USART_CR2_STOP_1                        /* 2 stop bits */

#define LL_USART_OVERSAMPLING_16 0x00000000U    /* Oversampling by 16 */
#define LL_USART_OVERSAMPLING_8 USART_CR1_OVER8 /* Oversampling by 8 */

#define LL_USART_HWCONTROL_NONE 0x00000000U                          /* CTS and RTS hardware flow control disabled */
#define LL_USART_HWCONTROL_RTS USART_CR3_RTSE                        /* RTS output enabled, data is only requested when there is space in the receive buffer */
#define LL_USART_HWCONTROL_CTS USART_CR3_CTSE                        /* CTS mode enabled, data is only transmitted when the nCTS input is asserted (tied to 0) */
#define LL_USART_HWCONTROL_RTS_CTS (USART_CR3_RTSE | USART_CR3_CTSE) /* CTS and RTS hardware flow control enabled */

/**
 * @brief  USART Enable
 * @param  usart USART Instance
 * @retval None
 */
static inline void ll_usart_enable(USART_TypeDef *usart)
{
    SET_BIT(usart->CR1, USART_CR1_UE);
}

/**
 * @brief  USART Disable (all USART prescalers and outputs are disabled)
 * @note   When USART is disabled, USART prescalers and outputs are stopped immediately,
 *         and current operations are discarded. The configuration of the USART is kept, but all the status
 *         flags, in the USARTx_ISR are set to their default values.
 * @param  usart USART Instance
 * @retval None
 */
static inline void ll_usart_disable(USART_TypeDef *usart)
{
    CLEAR_BIT(usart->CR1, USART_CR1_UE);
}

/**
 * @brief  Configure simultaneously enabled/disabled states
 *         of Transmitter and Receiver
 * @param  usart USART Instance
 * @param  direction This parameter can be one of the following values:
 *         @arg @ref LL_USART_DIRECTION_NONE
 *         @arg @ref LL_USART_DIRECTION_RX
 *         @arg @ref LL_USART_DIRECTION_TX
 *         @arg @ref LL_USART_DIRECTION_TX_RX
 * @retval None
 */
static inline void ll_usart_set_direction(USART_TypeDef *usart, uint32_t direction)
{
    ATOMIC_MODIFY_REG(usart->CR1, USART_CR1_RE | USART_CR1_TE, direction);
}

/**
 * @brief  Set Word length (i.e. nb of data bits, excluding start and stop bits)
 * @param  usart USART Instance
 * @param  datawidth This parameter can be one of the following values:
 *         @arg @ref LL_USART_DATAWIDTH_8B
 *         @arg @ref LL_USART_DATAWIDTH_9B
 * @retval None
 */
static inline void ll_usart_set_datawidth(USART_TypeDef *usart, uint32_t datawidth)
{
    MODIFY_REG(usart->CR1, USART_CR1_M, datawidth);
}

/**
 * @brief  Configure Parity (enabled/disabled and parity mode if enabled).
 * @note   This function selects if hardware parity control (generation and detection) is enabled or disabled.
 *         When the parity control is enabled (Odd or Even), computed parity bit is inserted at the MSB position
 *         (9th or 8th bit depending on data width) and parity is checked on the received data.
 * @param  usart USART Instance
 * @param  parity This parameter can be one of the following values:
 *         @arg @ref LL_USART_PARITY_NONE
 *         @arg @ref LL_USART_PARITY_EVEN
 *         @arg @ref LL_USART_PARITY_ODD
 * @retval None
 */
static inline void ll_usart_set_parity(USART_TypeDef *usart, uint32_t parity)
{
    MODIFY_REG(usart->CR1, USART_CR1_PS | USART_CR1_PCE, parity);
}

/**
 * @brief  Set the length of the stop bits
 * @param  usart USART Instance
 * @param  stopbits This parameter can be one of the following values:
 *         @arg @ref LL_USART_STOPBITS_0_5
 *         @arg @ref LL_USART_STOPBITS_1
 *         @arg @ref LL_USART_STOPBITS_1_5
 *         @arg @ref LL_USART_STOPBITS_2
 * @retval None
 */
static inline void ll_usart_set_stopbits(USART_TypeDef *usart, uint32_t stopbits)
{
    MODIFY_REG(usart->CR2, USART_CR2_STOP, stopbits);
}

/**
 * @brief  Configure HW Flow Control mode (both CTS and RTS)
 * @note   Macro IS_UART_HWFLOW_INSTANCE(usart) can be used to check whether or not
 *         Hardware Flow control feature is supported by the usart instance.
 * @param  usart USART Instance
 * @param  hwcontrol This parameter can be one of the following values:
 *         @arg @ref LL_USART_HWCONTROL_NONE
 *         @arg @ref LL_USART_HWCONTROL_RTS
 *         @arg @ref LL_USART_HWCONTROL_CTS
 *         @arg @ref LL_USART_HWCONTROL_RTS_CTS
 * @retval None
 */
static inline void ll_usart_set_hwcontrol(USART_TypeDef *usart, uint32_t hwcontrol)
{
    MODIFY_REG(usart->CR3, USART_CR3_RTSE | USART_CR3_CTSE, hwcontrol);
}

/**
 * @brief  Set Oversampling to 8-bit or 16-bit mode
 * @param  usart USART Instance
 * @param  oversampling This parameter can be one of the following values:
 *         @arg @ref LL_USART_OVERSAMPLING_16
 *         @arg @ref LL_USART_OVERSAMPLING_8
 * @retval None
 */
static inline void ll_usart_set_oversampling(USART_TypeDef *usart, uint32_t oversampling)
{
    MODIFY_REG(usart->CR1, USART_CR1_OVER8, oversampling);
}

/**
 * @brief  Return Oversampling mode
 * @param  usart USART Instance
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_USART_OVERSAMPLING_16
 *         @arg @ref LL_USART_OVERSAMPLING_8
 */
static inline uint32_t ll_usart_get_oversampling(const USART_TypeDef *usart)
{
    return READ_BIT(usart->CR1, USART_CR1_OVER8);
}

/**
 * @brief  Configure USART BRR register for achieving expected Baud Rate value.
 * @note   Compute and set USARTDIV value in BRR Register (full BRR content)
 *         according to used Peripheral Clock, Oversampling mode, and expected Baud Rate values
 * @note   In case of oversampling by 16 and 8, BRR content must be greater than or equal to 16d.
 * @param  usart USART Instance
 * @param  baudrate Baud Rate
 * @retval None
 */
static inline void ll_usart_set_baudrate(USART_TypeDef *usart, uint32_t baudrate)
{
    uint16_t usartdiv;
    uint16_t brrtemp;

    if (ll_usart_get_oversampling(usart) == LL_USART_OVERSAMPLING_8)
    {
        usartdiv = ((ll_rcc_get_usart_frequency(usart) * 2U) + (baudrate / 2U)) / baudrate;
        brrtemp = usartdiv & 0xFFF0U;
        brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
        usart->BRR = brrtemp;
    }
    else
    {
        usart->BRR = (ll_rcc_get_usart_frequency(usart) + (baudrate / 2U)) / baudrate;
    }
}

/**
 * @brief  Write in Transmitter Data Register (Transmit Data value, 8 bits)
 * @param  usart USART Instance
 * @param  data between Min_Data=0x00 and Max_Data=0xFF
 * @retval None
 */
static inline void ll_usart_write8(USART_TypeDef *usart, uint8_t data)
{
    usart->TDR = data;
}

/**
 * @brief  Clear Transmission Complete Flag
 * @param  usart USART Instance
 * @retval None
 */
static inline void ll_usart_clear_tc_flag(USART_TypeDef *usart)
{
    usart->ICR = USART_ICR_TCCF;
}

/**
 * @brief  Check if the USART Transmission Complete Flag is set or not
 * @param  usart USART Instance
 * @retval State of bit (1 or 0).
 */
static inline uint32_t ll_usart_is_tc_flag_active(const USART_TypeDef *usart)
{
    return READ_BIT(usart->ISR, USART_ISR_TC) == USART_ISR_TC ? 1UL : 0UL;
}

/**
 * @brief  Check if the USART Transmit Data Register Empty Flag is set or not
 * @param  usart USART Instance
 * @retval State of bit (1 or 0).
 */
static inline uint32_t ll_usart_is_txe_flag_active(const USART_TypeDef *usart)
{
    return READ_BIT(usart->ISR, USART_ISR_TXE) == USART_ISR_TXE ? 1UL : 0UL;
}

/**
 * @brief  Check if the USART Transmit Enable Acknowledge Flag is set or not
 * @param  usart USART Instance
 * @retval State of bit (1 or 0).
 */
static inline uint32_t ll_usart_is_teack_flag_active(const USART_TypeDef *usart)
{
    return ((READ_BIT(usart->ISR, USART_ISR_TEACK) == (USART_ISR_TEACK)) ? 1UL : 0UL);
}

/**
 * @brief  Check if the USART Receive Enable Acknowledge Flag is set or not
 * @param  usart USART Instance
 * @retval State of bit (1 or 0).
 */
static inline uint32_t ll_usart_is_reack_flag_active(const USART_TypeDef *usart)
{
    return ((READ_BIT(usart->ISR, USART_ISR_REACK) == (USART_ISR_REACK)) ? 1UL : 0UL);
}

/**
 * @brief  Enable RX Not Empty Interrupt
 * @param  usart USART Instance
 * @retval None
 */
static inline void ll_usart_enable_rxne_it(USART_TypeDef *usart)
{
    ATOMIC_SET_BIT(usart->CR1, USART_CR1_RXNEIE);
}
/**
 * @brief  Enable Error Interrupt
 * @note   When set, Error Interrupt Enable Bit is enabling interrupt generation in case of a framing
 *         error, overrun error or noise flag (FE=1 or ORE=1 or NF=1 in the USARTx_ISR register).
 *           0: Interrupt is inhibited
 *           1: An interrupt is generated when FE=1 or ORE=1 or NF=1 in the USARTx_ISR register.
 * @param  usart USART Instance
 * @retval None
 */
static inline void ll_usart_enable_error_it(USART_TypeDef *usart)
{
    ATOMIC_SET_BIT(usart->CR3, USART_CR3_EIE);
}

/**
 * @brief  Check if the USART RX Not Empty Interrupt is enabled or disabled.
 * @param  usart USART Instance
 * @retval State of bit (1 or 0).
 */
static inline uint32_t ll_usart_is_rxne_it_enabled(const USART_TypeDef *usart)
{
    return READ_BIT(usart->CR1, USART_CR1_RXNEIE) == (USART_CR1_RXNEIE) ? 1U : 0U;
}

/**
 * @brief  Check if the USART Read Data Register Not Empty Flag is set or not
 * @param  usart USART Instance
 * @retval State of bit (1 or 0).
 */
static inline uint32_t ll_usart_is_rxne_flag_active(const USART_TypeDef *usart)
{
    return READ_BIT(usart->ISR, USART_ISR_RXNE) == (USART_ISR_RXNE) ? 1UL : 0UL;
}

/**
 * @brief  Read Receiver Data register (Receive Data value, 8 bits)
 * @param  USARTx USART Instance
 * @retval Value between Min_Data=0x00 and Max_Data=0xFF
 */
static inline uint8_t ll_usart_read8(const USART_TypeDef *usart)
{
    return READ_BIT(usart->RDR, USART_RDR_RDR) & 0xFFU;
}

void ll_usart_handler(const USART_TypeDef *usart);
uint8_t ll_usart_getc(const USART_TypeDef *usart);
void ll_usart_putc(USART_TypeDef *usart, uint8_t c);

#endif /* LL_USART_H */
