/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 9 Sept 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : NVIC_program.c             *****************/
/****************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/***************************< MCAL ****************************/
/***< NVIC */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/***< SCB */
#include "SCB_interface.h"

Std_ReturnType MCAL_NVIC_EnableIRQ(u8 Copy_IRQn)
{
     Std_ReturnType Local_FunctionStatus = E_NOT_OK;
     
    if(Copy_IRQn < 32)
    {
        NVIC_ISER0 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ISER1 = (1 << (Copy_IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISER2 = (1 << (Copy_IRQn - 64));
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

     return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_DisableIRQ(u8 Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_IRQn < 32)
    {
        NVIC_ICER0 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ICER1 = (1 << (Copy_IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICER2 = (1 << (Copy_IRQn - 64));
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

     return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_SetPendingIRQ(u8 Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

     if(Copy_IRQn < 32)
    {
        NVIC_ISPR0 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ISPR1 = (1 << (Copy_IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISPR2 = (1 << (Copy_IRQn - 64));
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

     return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_ClearPendingIRQ(u8 Copy_IRQn)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
     if(Copy_IRQn < 32)
    {
        NVIC_ICPR0 = (1 << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ICPR1 = (1 << (Copy_IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICPR2 = (1 << (Copy_IRQn - 64));
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

     return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_GetPendingIRQ(u8 Copy_IRQn, u8 *Copy_ReturnPendingFlag)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_ReturnPendingFlag != NULL)
    {
        /**< See in which register the interrupt is loacted */
        if (Copy_IRQn < 32) 
        {
            if (NVIC_ISPR0 & (1U << Copy_IRQn))
            {
                *Copy_ReturnPendingFlag = 1; /**<Set to 1 if the flag is Pending */
            }else
            {
                *Copy_ReturnPendingFlag = 0; /**<Set to 0 if the flag is not Pending */
            }
            Local_FunctionStatus = E_OK;
        }else if (Copy_IRQn < 64)
        {
           if (NVIC_ISPR1 & (1U << (Copy_IRQn-32)))
            {
                *Copy_ReturnPendingFlag = 1; /**<Set to 1 if the flag is Pending */
            }else
            {
                *Copy_ReturnPendingFlag = 0; /**<Set to 0 if the flag is not Pending */
            }
            Local_FunctionStatus = E_OK;
        }else if (Copy_IRQn < 96)
        {
            if (NVIC_ISPR2 & (1U << (Copy_IRQn-64)))
            {
                *Copy_ReturnPendingFlag = 1; /**<Set to 1 if the flag is Pending */
            }else
            {
                *Copy_ReturnPendingFlag = 0; /**<Set to 0 if the flag is not Pending */
            }
            Local_FunctionStatus = E_OK;
        }
        else
        {
            Local_FunctionStatus = E_NOT_OK;
        }
            
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
     return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_GetActiveIRQ(u8 Copy_IRQn, u8 *Copy_ReturnActiveFlag)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_ReturnActiveFlag != NULL)
    {
        /**< See in which register the interrupt is loacted */
        if (Copy_IRQn < 32) 
        {
            if (NVIC_IABR0 & (1U << Copy_IRQn))
            {
                *Copy_ReturnActiveFlag = 1; /**<Set to 1 if the flag is Active */
            }else
            {
                *Copy_ReturnActiveFlag = 0; /**<Set to 0 if the flag is not Active */
            }
            Local_FunctionStatus = E_OK;
        }else if (Copy_IRQn < 64)
        {
           if (NVIC_IABR1 & (1U << (Copy_IRQn-32)))
            {
                *Copy_ReturnActiveFlag = 1; /**<Set to 1 if the flag is Active */
            }else
            {
                *Copy_ReturnActiveFlag = 0; /**<Set to 0 if the flag is not Active */
            }
            Local_FunctionStatus = E_OK;
        }else if (Copy_IRQn < 96)
        {
            if (NVIC_IABR2 & (1U << (Copy_IRQn-64)))
            {
                *Copy_ReturnActiveFlag = 1; /**<Set to 1 if the flag is Active */
            }else
            {
                *Copy_ReturnActiveFlag = 0; /**<Set to 0 if the flag is not Active */
            }
            Local_FunctionStatus = E_OK;
        }
        else
        {
            Local_FunctionStatus = E_NOT_OK;
        }      
        
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
     return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_xSetPriority(u8 Copy_IRQn, u8 Copy_Priority)   /**< This function sets the system block control to be 0 groups and 16 SubPriority*/
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

      if (Copy_IRQn < 0 || Copy_IRQn >= MAX_NUMBER_OF_INTERRUPTS)
      {
        Local_FunctionStatus = E_NOT_OK;

      }else if (Copy_Priority <= NVIC_MAX_PRIORITY)
      {
        u32 IPR_Index = Copy_IRQn / 4;
        u32 IPR_Offset = Copy_IRQn % 4;
        
        /**< Clear the selected register */
        NVIC_IPR_BASE_ADDRESS[IPR_Index] = ~(0xFF << IPR_Offset);

        /**< Set the selected register to the corresponding priority value */
        NVIC_IPR_BASE_ADDRESS[IPR_Index] = ((Copy_Priority << IPR_Offset) << 4);

         /**< Set the group and sub-group priority for interrupt handling in SCB_AIRCR register */
        SCB_SetPriorityGrouping(NVIC_0GROUP_16SUB);
      }

      return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_vSetPriority(u8 Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    u8 NVIC_MAX_Group_Priority;
    u8 NVIC_MAX_Sub_Priority;

    #if (PRIORITY_GROUPING == NVIC_16GROUP_0SUB)
        NVIC_MAX_Group_Priority = 15;
        NVIC_MAX_Sub_Priority = NONE;
    #elif (PRIORITY_GROUPING == NVIC_8GROUP_2SUB)
        NVIC_MAX_Group_Priority = 7;
        NVIC_MAX_Sub_Priority = 1;
    #elif (PRIORITY_GROUPING == NVIC_4GROUP_4SUB)
        NVIC_MAX_Group_Priority = 3;
        NVIC_MAX_Sub_Priority = 3;
    #elif (PRIORITY_GROUPING == NVIC_2GROUP_8SUB)
        NVIC_MAX_Group_Priority = 1;
        NVIC_MAX_Sub_Priority = 7;
    #elif (PRIORITY_GROUPING == NVIC_0GROUP_16SUB)
        NVIC_MAX_Group_Priority = NVIC_INVALID_PRIORITY;
        NVIC_MAX_Sub_Priority = 15;
    #else
        #error "Invalid PRIORITY_GROUPING value. Please choose from _16GROUP_SUB0, _8GROUP_SUB2, _4GROUP_SUB4, _2GROUP_SUB8, or _0GROUP_SUB16."
    #endif

    if (Copy_GroupPriority > NVIC_MAX_Group_Priority || Copy_SubPriority > NVIC_MAX_Sub_Priority)
    {
        /**< Invalid priority value */
        return Local_FunctionStatus;
    }

    u8 Local_Priority = (Copy_SubPriority | (Copy_GroupPriority << (PRIORITY_GROUPING - NVIC_16GROUP_0SUB) / 0x100));

    if (Copy_IRQn > MAX_NUMBER_OF_INTERRUPTS)
    {
        /**< Check if IRQn is within valid range */
        return Local_FunctionStatus;
    }

    u32 IPR_Index = Copy_IRQn / 4;
    u32 IPR_Offset = Copy_IRQn % 4;

    u32 PrReg = NVIC_IPR_BASE_ADDRESS[IPR_Index];
    
        /**< Clear the 8 bits in the selected register */
        PrReg &= ~(0xFF << IPR_Offset);

        /**< Set the 8 bits in the selected register to the corresponding priority value */
        PrReg |= ((Local_Priority << IPR_Offset) << 4);

        /**< Write back the modified value in the register */
        NVIC_IPR_BASE_ADDRESS[IPR_Index] = PrReg;

        Local_FunctionStatus = E_OK;

        /**< Configure the priority grouping for the Nested Vectored Interrupt Controller (NVIC) */
        SCB_SetPriorityGrouping(PRIORITY_GROUPING);

        return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_GetPriority(u8 Copy_IRQn, u8 *Copy_ReturnPriority)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_IRQn > MAX_NUMBER_OF_INTERRUPTS)
    {
        /**< Check if IRQn is within valid range */
        return Local_FunctionStatus;
    }

    u32 IPR_Index = Copy_IRQn / 4;
    u32 IPR_Offset = Copy_IRQn % 4;

    /**< Pointer which points to the selected IPR */
    u8 *PriorityRegister = (u8 *)&NVIC_IPR_BASE_ADDRESS[IPR_Index];

    *Copy_ReturnPriority = (PriorityRegister[IPR_Offset] >> (IPR_Offset*8)) & 0xFF;

    Local_FunctionStatus = E_OK;

    return Local_FunctionStatus;
}