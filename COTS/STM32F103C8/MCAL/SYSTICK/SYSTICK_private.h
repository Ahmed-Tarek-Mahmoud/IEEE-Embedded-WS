/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 14 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : SYSTICK_private.h          *****************/
/****************************************************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define STK_BASE_ADDRESS          (0xE000E010)

typedef struct 
{
   volatile u32 STK_CTRL;
   volatile u32 STK_LOAD;
   volatile u32 STK_VAL;
   volatile u32 STK_CALIB;
}SYSTICK_RegDef_t;

#define SYSTICK     ((SYSTICK_RegDef_t *)STK_BASE_ADDRESS)


/**********< The following are defines for the bit fields in the STK_CTRL register. ***********/
#define STK_CTRL_ENABLE_MASK             0x00000001      /**< Bit 0 : Counter Enable */
#define STK_CTRL_TICKINT_MASK            0x00000002      /**< Bit 1 : Interrupt Enable */
#define STK_CTRL_CLKSOURCE_MASK          0x00000004      /**< Bit 2 : Clock Source */
#define STK_CTRL_COUNTFLAG_MASK          0x00010000      /**< Bit 16: Count Flag */
/**********************************************************************************************/

#define STK_CTRL_TICKINT_ENABLE          1
#define STK_CTRL_TICKINT_DISABLE         0

#define STK_CTRL_CLKSOURCE_1             1
#define STK_CTRL_CLKSOURCE_8             0

/**
 * @brief Sets the system clock frequency for the SysTick peripheral.
 *
 * This function sets the system clock frequency for the SysTick peripheral. It does not allow changes to the values defined by the STK_CTRL_CLKSOURCE constant.
 *
 * @note
 * The available options for STK_CTRL_CLKSOURCE are:
 * - STK_CTRL_CLKSOURCE_1: Processor clock (AHB clock) divided by 1
 * - STK_CTRL_CLKSOURCE_8: Processor clock (AHB clock) divided by 8
 *
 * @retval None
 */
#if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
    #define STK_AHB_CLK       8000000   /**< Processor clock (AHB clock) divided by 1 */
#elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
    #define STK_AHB_CLK       1000000   /**< Processor clock (AHB clock) divided by 8 */
#else
    #error "You chose a wrong clock source for the SysTick"
#endif


#endif /**< SYSTICK_PRIVATE_H */