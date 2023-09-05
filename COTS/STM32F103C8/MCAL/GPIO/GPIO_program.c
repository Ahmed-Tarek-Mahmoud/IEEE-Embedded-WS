/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 2 Sept 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : GPIO_program.c             *****************/
/****************************************************************/

/******************************** LIB ***************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/******************************** MCAL **************************/
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"

Std_ReturnType MCAL_GPIO_SetPinMode(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_PinMode)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
  switch (Copy_PortId)
  {
  case GPIO_PORTA:
  if ( Copy_PinId < 8)
  {
    /* Clear the selected bits */
    GPIOA_CRL &= ~((0b1111) << (Copy_PinId*4));
    /* Set the selected bits to the Value of the mode and configuration */
    GPIOA_CRL |= (Copy_PinMode << (Copy_PinId*4));

    Local_FunctionStatus = E_OK;
  }else if ( Copy_PinId < 15)
  {
    /* Clear the selected bits */
    GPIOA_CRH &= ~((0b1111) << (Copy_PinId*4));
    /* Set the selected bits to the Value of the mode and configuration */
    GPIOA_CRH |= (Copy_PinMode << (Copy_PinId*4));

    Local_FunctionStatus = E_OK;
  }else
  {
     Local_FunctionStatus = E_NOT_OK;
  }
  
    break;

  case GPIO_PORTB:
    if ( Copy_PinId < 8)
  {
    /* Clear the selected bits */
    GPIOB_CRL &= ~((0b1111) << (Copy_PinId*4));
    /* Set the selected bits to the Value of the mode and configuration */
    GPIOB_CRL |= (Copy_PinMode << (Copy_PinId*4));

    Local_FunctionStatus = E_OK;
  }else if ( Copy_PinId < 15)
  {
    /* Clear the selected bits */
    GPIOB_CRH &= ~((0b1111) << (Copy_PinId*4));
    /* Set the selected bits to the Value of the mode and configuration */
    GPIOB_CRH |= (Copy_PinMode << (Copy_PinId*4));

    Local_FunctionStatus = E_OK;
  }else
  {
     Local_FunctionStatus = E_NOT_OK;
  }
    break;

  case GPIO_PORTC:
    if ( Copy_PinId < 8)
  {
    /* Clear the selected bits */
    GPIOC_CRL &= ~((0b1111) << (Copy_PinId*4));
    /* Set the selected bits to the Value of the mode and configuration */
    GPIOC_CRL |= (Copy_PinMode << (Copy_PinId*4));

    Local_FunctionStatus = E_OK;
  }else if ( Copy_PinId < 15)
  {
    /* Clear the selected bits */
    GPIOC_CRH &= ~((0b1111) << (Copy_PinId*4));
    /* Set the selected bits to the Value of the mode and configuration */
    GPIOC_CRH |= (Copy_PinMode << (Copy_PinId*4));

    Local_FunctionStatus = E_OK;
  }else
  {
     Local_FunctionStatus = E_NOT_OK;
  }
    break;

  default:
  Local_FunctionStatus = E_NOT_OK;
    break;
  }
  return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_PinValue)
{
   Std_ReturnType Local_FunctionStatus = E_NOT_OK;
   switch (Copy_PortId)
   {
   case GPIO_PORTA:
    if (Copy_PinValue == GPIO_HIGH)
    {
       SET_BIT(GPIOA_ODR, Copy_PinId);Local_FunctionStatus = E_OK;
       Local_FunctionStatus = E_OK;
    }else if (Copy_PinValue == GPIO_LOW)
    {
        CLR_BIT(GPIOA_ODR, Copy_PinId);
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    break;
    case GPIO_PORTB:
    if (Copy_PinValue == GPIO_HIGH)
    {
       SET_BIT(GPIOB_ODR, Copy_PinId);
       Local_FunctionStatus = E_OK;
    }else if (Copy_PinValue == GPIO_LOW)
    {
        CLR_BIT(GPIOB_ODR, Copy_PinId);
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    break;
    case GPIO_PORTC:
    if (Copy_PinValue == GPIO_HIGH)
    {
       SET_BIT(GPIOC_ODR, Copy_PinId);
       Local_FunctionStatus = E_OK;
    }else if (Copy_PinValue == GPIO_LOW)
    {
        CLR_BIT(GPIOC_ODR, Copy_PinId);
        Local_FunctionStatus = E_OK;
    }else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    break;
   default:
    break;
   }
   return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_PortId,u8 Copy_PinId,u8 *Copy_PinValue)
{
 Std_ReturnType Local_FunctionStatus = E_NOT_OK;
if (*Copy_PinValue != NULL)
{
 switch (Copy_PortId)
 {
    case GPIO_PORTA:
            *Copy_PinValue = GET_BIT(GPIOA_IDR, Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
    case GPIO_PORTB:
            *Copy_PinValue= GET_BIT(GPIOB_IDR, Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
    case GPIO_PORTC:
            *Copy_PinValue= GET_BIT(GPIOC_IDR, Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
        
    default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    
    break;
 
 }
}else
{
   Local_FunctionStatus = E_NOT_OK;
}

 return Local_FunctionStatus;
}