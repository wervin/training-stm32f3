#ifndef LL_UTILS_H
#define LL_UTILS_H

#define SET_BIT(REG, BIT) ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT) ((REG) & (BIT))

#define CLEAR_REG(REG) ((REG) = 0x0U)

#define MODIFY_REG(REG, CLEARMASK, SETMASK) ((REG) = (((REG) & ~(CLEARMASK)) | (SETMASK)))

#define POSITION_VAL(VAL) (__CLZ(__RBIT(VAL)))

/* Use of CMSIS compiler intrinsics for register exclusive access */
/* Atomic 32-bit register access macro to set one or several bits */
#define ATOMIC_SET_BIT(REG, BIT)                                  \
    do                                                            \
    {                                                             \
        uint32_t val;                                             \
        do                                                        \
        {                                                         \
            val = __LDREXW((__IO uint32_t *)&(REG)) | (BIT);      \
        } while ((__STREXW(val, (__IO uint32_t *)&(REG))) != 0U); \
    } while (0)

/* Atomic 32-bit register access macro to clear one or several bits */
#define ATOMIC_CLEAR_BIT(REG, BIT)                                \
    do                                                            \
    {                                                             \
        uint32_t val;                                             \
        do                                                        \
        {                                                         \
            val = __LDREXW((__IO uint32_t *)&(REG)) & ~(BIT);     \
        } while ((__STREXW(val, (__IO uint32_t *)&(REG))) != 0U); \
    } while (0)

/* Atomic 32-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK)                                \
    do                                                                           \
    {                                                                            \
        uint32_t val;                                                            \
        do                                                                       \
        {                                                                        \
            val = (__LDREXW((__IO uint32_t *)&(REG)) & ~(CLEARMSK)) | (SETMASK); \
        } while ((__STREXW(val, (__IO uint32_t *)&(REG))) != 0U);                \
    } while (0)

/* Atomic 16-bit register access macro to set one or several bits */
#define ATOMIC_SETH_BIT(REG, BIT)                                 \
    do                                                            \
    {                                                             \
        uint16_t val;                                             \
        do                                                        \
        {                                                         \
            val = __LDREXH((__IO uint16_t *)&(REG)) | (BIT);      \
        } while ((__STREXH(val, (__IO uint16_t *)&(REG))) != 0U); \
    } while (0)

/* Atomic 16-bit register access macro to clear one or several bits */
#define ATOMIC_CLEARH_BIT(REG, BIT)                               \
    do                                                            \
    {                                                             \
        uint16_t val;                                             \
        do                                                        \
        {                                                         \
            val = __LDREXH((__IO uint16_t *)&(REG)) & ~(BIT);     \
        } while ((__STREXH(val, (__IO uint16_t *)&(REG))) != 0U); \
    } while (0)

/* Atomic 16-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFYH_REG(REG, CLEARMSK, SETMASK)                               \
    do                                                                           \
    {                                                                            \
        uint16_t val;                                                            \
        do                                                                       \
        {                                                                        \
            val = (__LDREXH((__IO uint16_t *)&(REG)) & ~(CLEARMSK)) | (SETMASK); \
        } while ((__STREXH(val, (__IO uint16_t *)&(REG))) != 0U);                \
    } while (0)

#endif /* LL_UTILS_H*/
