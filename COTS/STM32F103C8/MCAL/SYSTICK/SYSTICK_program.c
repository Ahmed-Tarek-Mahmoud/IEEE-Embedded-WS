/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 14 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : SYSTICK_program.c          *****************/
/****************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/**< MCAL */
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

/**
 * @defgroup Public Functions Implementations
 * @{
 */

void STK_Init(u32 Copy_Ticks)
{
    /**< Disable the peripheral */
    SYSTICK->STK_CTRL &= ~(STK_CTRL_ENABLE_MASK);

    /**< Check on the Clock source configuration */
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1

        SYSTICK->STK_CTRL |= STK_CTRL_CLKSOURCE_MASK;

    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8

        SYSTICK->STK_CTRL &= ~(STK_CTRL_CLKSOURCE_MASK);

    #else
       #error "Wrong Clock Source Configuration!"
    #endif

    /**<Check Interrupt Generator configuration */
    #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE

         SYSTICK->STK_CTRL |= STK_CTRL_COUNTFLAG_MASK;

    #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE

         SYSTICK->STK_CTRL &= ~(STK_CTRL_COUNTFLAG_MASK);

    #else 
       #error "Wrong Tick Interrupt Configure"
    #endif

     /**< Load the initial value into the SysTick timer */
     SYSTICK->STK_LOAD = Copy_Ticks;
}

void STK_Start(void)
{
    SYSTICK->STK_CTRL |= STK_CTRL_ENABLE_MASK;
}

void STK_Stop(void)
{
    SYSTICK->STK_CTRL &= ~(STK_CTRL_ENABLE_MASK);
}

void STK_Reset(void)
{
    /**< Disable SysTick timer */
    SYSTICK->STK_CTRL &= ~STK_CTRL_ENABLE_MASK;

    /**< Clear the current value */
    SYSTICK->STK_CTRL = 0;

    /**< Set the reload value to 0 */
    SYSTICK->STK_LOAD = 0;

    /**< Clear the count flag */
    SYSTICK->STK_CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
}

u32 STK_GetRemainingCounts(void)
{
      return SYSTICK->STK_VAL;
}

u32 STK_GetElapsedCounts(void)
{
     static u32 Local_PreviousValue = 0;  /**< Store the previous SysTick timer value */ 
    u32 Local_CurrentValue = SYSTICK->STK_VAL;   /**< Get the current SysTick timer value */ 
    u32 Local_ElapsedTicks;

    /**< Check if the timer has wrapped around (current value is less than the previous value) */ 
    if (Local_CurrentValue < Local_PreviousValue) 
    {
        /**< Default Count Down */ 
        Local_ElapsedTicks = Local_PreviousValue - Local_CurrentValue;
    } 
    else 
    {
        /**< Calculate elapsed ticks with overflow */ 
        Local_ElapsedTicks = SYSTICK->STK_LOAD - (Local_CurrentValue - Local_PreviousValue);
    }

    /**< Update the previous value for the next call */ 
    Local_PreviousValue = Local_CurrentValue;

    return Local_ElapsedTicks;
}

Std_ReturnType STK_SetDelay_us(u32 Copy_Microseconds)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Calculate No. Of Ticks Required */
    u32 TicksRequired = Copy_Microseconds * (STK_AHB_CLK / 1000000);

     /**< Check if the ticks required is within the valid range */ 
    if (TicksRequired <= 0x00FFFFFF) 
    {

        /**< Set the reload value of the SysTick timer */ 
        SYSTICK->STK_LOAD = TicksRequired;

        /**< Enable the SysTick timer */ 
        SYSTICK->STK_CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
        while (!(SYSTICK->STK_CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable the SysTick timer */ 
        SYSTICK->STK_CTRL &= ~STK_CTRL_ENABLE_MASK;

        /**< Reset the timer value */ 
        SYSTICK->STK_VAL = 0;

        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}

Std_ReturnType STK_SetDelay_ms(f32 Copy_Milliseconds)
{
     Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Calculate No. Of Ticks Required */
    u32 TicksRequired = (u32)(Copy_Milliseconds * (STK_AHB_CLK/1000.0));

    /**< Check wether the entered value is within the range */
    if (TicksRequired <= 0x00FFFFFF)
    {

         /**< Load the required value */
        SYSTICK->STK_LOAD = TicksRequired;

        /**< Enable the SysTick timer */ 
        SYSTICK->STK_CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the COUNTFLAG is set (indicates timer has counted down to zero) */
        while (!(SYSTICK->STK_CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable the SysTick timer */ 
        SYSTICK->STK_CTRL &= ~STK_CTRL_ENABLE_MASK;

        /**< Reset the timer value */ 
        SYSTICK->STK_VAL = 0;

        Local_FunctionStatus = E_OK;
    }
    
     return Local_FunctionStatus;
}

Std_ReturnType STK_xSetDelay_ms(f32 Copy_Milliseconds)
{
        while (Copy_Milliseconds > 0)
        {
            u32 val;
            if (Copy_Milliseconds > 0xFFFFFF)
            {
                val = 0xFFFFFF;
            }else
            {
                val = Copy_Milliseconds;
            }
            STK_SetDelay_ms(val);
            Copy_Milliseconds-=val;
        }
        if (Copy_Milliseconds > 0)
        {
            return E_NOT_OK;
        }else
        {
            return E_OK;
        } 
}

Std_ReturnType STK_SetIntervalSingle(u32 Copy_Microseconds, void (*Copy_Callback)(void))
{

}

Std_ReturnType STK_SetIntervalPeriodic(u32 Copy_Microseconds, void (*Copy_Callback)(void))
{

}

/**
 * @} // End of Public Functions
 */

/**
 * @defgroup IRQ_Handlers IRQ Handlers
 * @{
 */

void SysTick_Handler(void)
{

}

/**
 * @} // End of IRQ_Handlers
 */