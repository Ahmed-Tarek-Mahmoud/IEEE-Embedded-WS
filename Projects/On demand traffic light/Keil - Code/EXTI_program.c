/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 9 Sept 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : EXTI_program.c             *****************/
/****************************************************************/

/****************************< LIB ******************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
/****************************< MCAL *****************************/

/**<EXTI*/
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/**< AFIO*/
#include "AFIO_interface.h"

/**< GPIO */
#include "GPIO_interface.h"

/*****************************< Function Implementations *****************************/

Std_ReturnType EXTI_Init(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    for (u8 Line = 0; Line < EXTI_LINES_COUNT; Line++)
    {
        if (EXTI_Configurations[Line].LineEnabled == EXTI_LINE_ENABLED)
        {
            EXTI->EXTI_IMR |= (1 << Line);  /**< Enable the EXTI line */ 
            switch (EXTI_Configurations[Line].TriggerType)
            {
            /**< Configure rising edge trigger */
            case EXTI_RISING_EDGE:          
                SET_BIT(EXTI->EXTI_RTSR, Line);
                CLR_BIT(EXTI->EXTI_FTSR, Line);
                break;
            /**< Configure falling edge trigger */ 
            case EXTI_FALLING_EDGE:
                CLR_BIT(EXTI->EXTI_RTSR, Line);
                SET_BIT(EXTI->EXTI_FTSR, Line);
                break;
            /**< Configure both edges trigger */
            case EXTI_BOTH_EDGES:
                SET_BIT(EXTI->EXTI_RTSR, Line);
                SET_BIT(EXTI->EXTI_FTSR, Line);
                break;
            }

             /**< Enable EXTI line for the specified GPIO pin */ 
            AFIO_SetEXTIConfiguration(Line, EXTI_Configurations[Line].GPIO_PortMap);

            Local_FunctionStatus = E_OK;
        }
        else if (EXTI_Configurations[Line].LineEnabled == EXTI_LINE_DISABLED)
        {
            EXTI->EXTI_IMR &= ~(1 << Line);  /**< Disable the EXTI line */ 
            Local_FunctionStatus = E_OK;
        }else
        {
            Local_FunctionStatus = E_NOT_OK;
        }
    }

    return Local_FunctionStatus;
}

Std_ReturnType EXTI_Enable(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < 16)
    {
       SET_BIT(EXTI->EXTI_EMR,Copy_Line); 
       Local_FunctionStatus = E_OK;
    }
    return Local_FunctionStatus;
}

Std_ReturnType EXTI_Disable(u8 Copy_Line)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line < 16)
    {
       CLR_BIT(EXTI->EXTI_EMR,Copy_Line); 
       Local_FunctionStatus = E_OK;
    }
    return Local_FunctionStatus;
}

Std_ReturnType EXTI_SetPinTriggger(u8 Copy_Line, u8 Copy_Mode)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    switch (Copy_Mode)
    {
    case EXTI_RISING_EDGE:
        
        SET_BIT(EXTI->EXTI_RTSR,Copy_Line);
        Local_FunctionStatus = E_OK;
        break;
    
    case EXTI_FALLING_EDGE:
        
        SET_BIT(EXTI->EXTI_FTSR,Copy_Line);
         Local_FunctionStatus = E_OK;
        break;

    case EXTI_BOTH_EDGES:
        
        SET_BIT(EXTI->EXTI_RTSR,Copy_Line);
        SET_BIT(EXTI->EXTI_FTSR,Copy_Line);
         Local_FunctionStatus = E_OK;
        break;

    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }
    return Local_FunctionStatus;
}

void (*ptr)() = NULL;

void EXTI_SetCallBack(void (*pf)(void))
{
    ptr = pf; 
}

void EXTI0_IRQHandler(void)
{
    ptr();
}
/*****************************< End Of Function Implementations *************************/