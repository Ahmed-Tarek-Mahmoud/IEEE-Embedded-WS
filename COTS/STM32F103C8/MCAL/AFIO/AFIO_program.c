/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 12 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : AFIO_program.c             *****************/
/****************************************************************/

/**< LIB */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/**< MCAL */
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

Std_ReturnType AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line > MAX_LINE_NUMBER || Copy_PortMap > MAX_PORT_NUMBER)
    {
        return Local_FunctionStatus;
    }
    
    /**< Calculate The Index */
    u8 Local_RegIndex = Copy_Line / 4;

    /**< Calculate The Offset */
    Copy_Line %= 4;

    /**< Clear The Selected Bits */
    AFIO->AFIO_EXTICR[Local_RegIndex] &= ~((0b1111) << (Copy_Line * 4));

    /**< Assign The Selected Bits To The Port Value */
    AFIO->AFIO_EXTICR[Local_RegIndex] |= Copy_PortMap << (Copy_Line * 4);

    return Local_FunctionStatus;
}