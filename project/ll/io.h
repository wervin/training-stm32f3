#ifndef LL_IO_H
#define LL_IO_H

#include <stdint.h>
#include "stm32f3.h"
#include "utils.h"

#define LL_IO_PIN_0 GPIO_BSRR_BS_0   /*!< Select pin 0 */
#define LL_IO_PIN_1 GPIO_BSRR_BS_1   /*!< Select pin 1 */
#define LL_IO_PIN_2 GPIO_BSRR_BS_2   /*!< Select pin 2 */
#define LL_IO_PIN_3 GPIO_BSRR_BS_3   /*!< Select pin 3 */
#define LL_IO_PIN_4 GPIO_BSRR_BS_4   /*!< Select pin 4 */
#define LL_IO_PIN_5 GPIO_BSRR_BS_5   /*!< Select pin 5 */
#define LL_IO_PIN_6 GPIO_BSRR_BS_6   /*!< Select pin 6 */
#define LL_IO_PIN_7 GPIO_BSRR_BS_7   /*!< Select pin 7 */
#define LL_IO_PIN_8 GPIO_BSRR_BS_8   /*!< Select pin 8 */
#define LL_IO_PIN_9 GPIO_BSRR_BS_9   /*!< Select pin 9 */
#define LL_IO_PIN_10 GPIO_BSRR_BS_10 /*!< Select pin 10 */
#define LL_IO_PIN_11 GPIO_BSRR_BS_11 /*!< Select pin 11 */
#define LL_IO_PIN_12 GPIO_BSRR_BS_12 /*!< Select pin 12 */
#define LL_IO_PIN_13 GPIO_BSRR_BS_13 /*!< Select pin 13 */
#define LL_IO_PIN_14 GPIO_BSRR_BS_14 /*!< Select pin 14 */
#define LL_IO_PIN_15 GPIO_BSRR_BS_15 /*!< Select pin 15 */
#define LL_IO_PIN_ALL (GPIO_BSRR_BS_0 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_2 |    \
                       GPIO_BSRR_BS_3 | GPIO_BSRR_BS_4 | GPIO_BSRR_BS_5 |    \
                       GPIO_BSRR_BS_6 | GPIO_BSRR_BS_7 | GPIO_BSRR_BS_8 |    \
                       GPIO_BSRR_BS_9 | GPIO_BSRR_BS_10 | GPIO_BSRR_BS_11 |  \
                       GPIO_BSRR_BS_12 | GPIO_BSRR_BS_13 | GPIO_BSRR_BS_14 | \
                       GPIO_BSRR_BS_15) /*!< Select all pins */

#define LL_IO_MODE_INPUT 0x00000000U             /*!< Select input mode */
#define LL_IO_MODE_OUTPUT GPIO_MODER_MODER0_0    /*!< Select output mode */
#define LL_IO_MODE_ALTERNATE GPIO_MODER_MODER0_1 /*!< Select alternate function mode */
#define LL_IO_MODE_ANALOG GPIO_MODER_MODER0      /*!< Select analog mode */

#define LL_IO_OUTPUT_PUSHPULL 0x00000000U       /*!< Select push-pull as output type */
#define LL_IO_OUTPUT_OPENDRAIN GPIO_OTYPER_OT_0 /*!< Select open-drain as output type */

#define LL_IO_SPEED_FREQ_LOW 0x00000000U                 /*!< Select I/O low output speed    */
#define LL_IO_SPEED_FREQ_MEDIUM GPIO_OSPEEDER_OSPEEDR0_0 /*!< Select I/O medium output speed */
#define LL_IO_SPEED_FREQ_HIGH GPIO_OSPEEDER_OSPEEDR0     /*!< Select I/O high output speed   */

#define LL_IO_PULL_NO 0x00000000U           /*!< Select I/O no pull */
#define LL_IO_PULL_UP GPIO_PUPDR_PUPDR0_0   /*!< Select I/O pull up */
#define LL_IO_PULL_DOWN GPIO_PUPDR_PUPDR0_1 /*!< Select I/O pull down */

/**
 * @brief  Configure gpio mode for a dedicated pin on dedicated port.
 * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
 * @note   Warning: only one pin can be passed as parameter.
 * @param  port GPIO Port
 * @param  pin This parameter can be one of the following values:
 *         @arg @ref LL_IO_PIN_0
 *         @arg @ref LL_IO_PIN_1
 *         @arg @ref LL_IO_PIN_2
 *         @arg @ref LL_IO_PIN_3
 *         @arg @ref LL_IO_PIN_4
 *         @arg @ref LL_IO_PIN_5
 *         @arg @ref LL_IO_PIN_6
 *         @arg @ref LL_IO_PIN_7
 *         @arg @ref LL_IO_PIN_8
 *         @arg @ref LL_IO_PIN_9
 *         @arg @ref LL_IO_PIN_10
 *         @arg @ref LL_IO_PIN_11
 *         @arg @ref LL_IO_PIN_12
 *         @arg @ref LL_IO_PIN_13
 *         @arg @ref LL_IO_PIN_14
 *         @arg @ref LL_IO_PIN_15
 * @param  mode This parameter can be one of the following values:
 *         @arg @ref LL_IO_MODE_INPUT
 *         @arg @ref LL_IO_MODE_OUTPUT
 *         @arg @ref LL_IO_MODE_ALTERNATE
 *         @arg @ref LL_IO_MODE_ANALOG
 * @retval None
 */
static inline void ll_io_set_mode(GPIO_TypeDef *port, uint32_t pin, uint32_t mode)
{
    MODIFY_REG(port->MODER, (GPIO_MODER_MODER0 << (POSITION_VAL(pin) * 2U)), (mode << (POSITION_VAL(pin) * 2U)));
}

/**
 * @brief  Configure gpio output type for several pins on dedicated port.
 * @note   Output type as to be set when gpio pin is in output or
 *         alternate modes. Possible type are Push-pull or Open-drain.
 * @param  port GPIO Port
 * @param  pin This parameter can be a combination of the following values:
 *         @arg @ref LL_IO_PIN_0
 *         @arg @ref LL_IO_PIN_1
 *         @arg @ref LL_IO_PIN_2
 *         @arg @ref LL_IO_PIN_3
 *         @arg @ref LL_IO_PIN_4
 *         @arg @ref LL_IO_PIN_5
 *         @arg @ref LL_IO_PIN_6
 *         @arg @ref LL_IO_PIN_7
 *         @arg @ref LL_IO_PIN_8
 *         @arg @ref LL_IO_PIN_9
 *         @arg @ref LL_IO_PIN_10
 *         @arg @ref LL_IO_PIN_11
 *         @arg @ref LL_IO_PIN_12
 *         @arg @ref LL_IO_PIN_13
 *         @arg @ref LL_IO_PIN_14
 *         @arg @ref LL_IO_PIN_15
 *         @arg @ref LL_IO_PIN_ALL
 * @param  output This parameter can be one of the following values:
 *         @arg @ref LL_IO_OUTPUT_PUSHPULL
 *         @arg @ref LL_IO_OUTPUT_OPENDRAIN
 * @retval None
 */
static inline void ll_io_set_output(GPIO_TypeDef *port, uint32_t pin, uint32_t output)
{
    MODIFY_REG(port->OTYPER, pin, (pin * output));
}

/**
 * @brief  Configure gpio speed for a dedicated pin on dedicated port.
 * @note   I/O speed can be Low, Medium, Fast or High speed.
 * @note   Warning: only one pin can be passed as parameter.
 * @note   Refer to datasheet for frequency specifications and the power
 *         supply and load conditions for each speed.
 * @param  port GPIO Port
 * @param  pin This parameter can be one of the following values:
 *         @arg @ref LL_IO_PIN_0
 *         @arg @ref LL_IO_PIN_1
 *         @arg @ref LL_IO_PIN_2
 *         @arg @ref LL_IO_PIN_3
 *         @arg @ref LL_IO_PIN_4
 *         @arg @ref LL_IO_PIN_5
 *         @arg @ref LL_IO_PIN_6
 *         @arg @ref LL_IO_PIN_7
 *         @arg @ref LL_IO_PIN_8
 *         @arg @ref LL_IO_PIN_9
 *         @arg @ref LL_IO_PIN_10
 *         @arg @ref LL_IO_PIN_11
 *         @arg @ref LL_IO_PIN_12
 *         @arg @ref LL_IO_PIN_13
 *         @arg @ref LL_IO_PIN_14
 *         @arg @ref LL_IO_PIN_15
 * @param  speed This parameter can be one of the following values:
 *         @arg @ref LL_IO_SPEED_FREQ_LOW
 *         @arg @ref LL_IO_SPEED_FREQ_MEDIUM
 *         @arg @ref LL_IO_SPEED_FREQ_HIGH
 * @retval None
 */
static inline void ll_io_set_speed(GPIO_TypeDef *port, uint32_t pin, uint32_t speed)
{
    MODIFY_REG(port->OSPEEDR, (GPIO_OSPEEDER_OSPEEDR0 << (POSITION_VAL(pin) * 2U)),
               (speed << (POSITION_VAL(pin) * 2U)));
}

/**
 * @brief  Configure gpio pull-up or pull-down for a dedicated pin on a dedicated port.
 * @note   Warning: only one pin can be passed as parameter.
 * @param  port GPIO Port
 * @param  pin This parameter can be one of the following values:
 *         @arg @ref LL_IO_PIN_0
 *         @arg @ref LL_IO_PIN_1
 *         @arg @ref LL_IO_PIN_2
 *         @arg @ref LL_IO_PIN_3
 *         @arg @ref LL_IO_PIN_4
 *         @arg @ref LL_IO_PIN_5
 *         @arg @ref LL_IO_PIN_6
 *         @arg @ref LL_IO_PIN_7
 *         @arg @ref LL_IO_PIN_8
 *         @arg @ref LL_IO_PIN_9
 *         @arg @ref LL_IO_PIN_10
 *         @arg @ref LL_IO_PIN_11
 *         @arg @ref LL_IO_PIN_12
 *         @arg @ref LL_IO_PIN_13
 *         @arg @ref LL_IO_PIN_14
 *         @arg @ref LL_IO_PIN_15
 * @param  pull This parameter can be one of the following values:
 *         @arg @ref LL_IO_PULL_NO
 *         @arg @ref LL_IO_PULL_UP
 *         @arg @ref LL_IO_PULL_DOWN
 * @retval None
 */
static inline void ll_io_set_pull(GPIO_TypeDef *port, uint32_t pin, uint32_t pull)
{
    MODIFY_REG(port->PUPDR, (GPIO_PUPDR_PUPDR0 << (POSITION_VAL(pin) * 2U)), (pull << (POSITION_VAL(pin) * 2U)));
}

/**
 * @brief  Set several pins to high level on dedicated gpio port.
 * @param  gpio GPIO Port
 * @param  pin This parameter can be a combination of the following values:
 *         @arg @ref LL_IO_PIN_0
 *         @arg @ref LL_IO_PIN_1
 *         @arg @ref LL_IO_PIN_2
 *         @arg @ref LL_IO_PIN_3
 *         @arg @ref LL_IO_PIN_4
 *         @arg @ref LL_IO_PIN_5
 *         @arg @ref LL_IO_PIN_6
 *         @arg @ref LL_IO_PIN_7
 *         @arg @ref LL_IO_PIN_8
 *         @arg @ref LL_IO_PIN_9
 *         @arg @ref LL_IO_PIN_10
 *         @arg @ref LL_IO_PIN_11
 *         @arg @ref LL_IO_PIN_12
 *         @arg @ref LL_IO_PIN_13
 *         @arg @ref LL_IO_PIN_14
 *         @arg @ref LL_IO_PIN_15
 *         @arg @ref LL_IO_PIN_ALL
 * @retval None
 */
__STATIC_INLINE void ll_io_set_pin(GPIO_TypeDef *gpio, uint32_t pin)
{
    gpio->BSRR = pin;
}

/**
 * @brief  Set several pins to low level on dedicated gpio port.
 * @param  gpio GPIO Port
 * @param  pin This parameter can be a combination of the following values:
 *         @arg @ref LL_IO_PIN_0
 *         @arg @ref LL_IO_PIN_1
 *         @arg @ref LL_IO_PIN_2
 *         @arg @ref LL_IO_PIN_3
 *         @arg @ref LL_IO_PIN_4
 *         @arg @ref LL_IO_PIN_5
 *         @arg @ref LL_IO_PIN_6
 *         @arg @ref LL_IO_PIN_7
 *         @arg @ref LL_IO_PIN_8
 *         @arg @ref LL_IO_PIN_9
 *         @arg @ref LL_IO_PIN_10
 *         @arg @ref LL_IO_PIN_11
 *         @arg @ref LL_IO_PIN_12
 *         @arg @ref LL_IO_PIN_13
 *         @arg @ref LL_IO_PIN_14
 *         @arg @ref LL_IO_PIN_15
 *         @arg @ref LL_IO_PIN_ALL
 * @retval None
 */
__STATIC_INLINE void ll_io_clear_pin(GPIO_TypeDef *gpio, uint32_t pin)
{
    gpio->BRR = pin;
}

/**
 * @brief  Toggle several pins to low level on dedicated gpio port.
 * @param  gpio GPIO Port
 * @param  pin This parameter can be a combination of the following values:
 *         @arg @ref LL_IO_PIN_0
 *         @arg @ref LL_IO_PIN_1
 *         @arg @ref LL_IO_PIN_2
 *         @arg @ref LL_IO_PIN_3
 *         @arg @ref LL_IO_PIN_4
 *         @arg @ref LL_IO_PIN_5
 *         @arg @ref LL_IO_PIN_6
 *         @arg @ref LL_IO_PIN_7
 *         @arg @ref LL_IO_PIN_8
 *         @arg @ref LL_IO_PIN_9
 *         @arg @ref LL_IO_PIN_10
 *         @arg @ref LL_IO_PIN_11
 *         @arg @ref LL_IO_PIN_12
 *         @arg @ref LL_IO_PIN_13
 *         @arg @ref LL_IO_PIN_14
 *         @arg @ref LL_IO_PIN_15
 *         @arg @ref LL_IO_PIN_ALL
 * @retval None
 */
__STATIC_INLINE void ll_io_toggle_pin(GPIO_TypeDef *gpio, uint32_t pin)
{
    gpio->ODR ^= pin;
}

#endif /* LL_IO_H */
