/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 10 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : SCB.program.c              *****************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/*****************************< MCAL *****************************/
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"

Std_ReturnType SCB_SetPriorityGrouping(u32 Copy_PriorityGrouping)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    /* Clear the PRIGROUP bits in AIRCR and set them to the configured value */
    SCB_AIRCR = Copy_PriorityGrouping;

    Local_FunctionStatus = E_OK;
    
    return Local_FunctionStatus;
}