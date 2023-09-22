/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 19 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : LED_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
/*****************************< MCAL *****************************/
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
/*****************************< HAL *****************************/
#include "LED.h"

/**
 * @defgroup Public_Functions LED Driver
 * @{
 */

Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    /**< Init LED to be output */  
    return MCAL_GPIO_SetPinMode(Copy_LedPortId, Copy_LedPinId, GPIO_OUTPUT_PP_2MHZ);
}

Std_ReturnType HAL_LED_On(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_HIGH);
}

Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_LOW);
}

Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId)
{
    return MCAL_GPIO_TogglePin(Copy_LedPortId, Copy_LedPinId);
}

Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime)
{
    if(MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_HIGH) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    if(STK_SetDelay_ms(Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    if(MCAL_GPIO_SetPinValue(Copy_LedPortId, Copy_LedPinId, GPIO_LOW) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    return E_OK;
}

Std_ReturnType HAL_LED_xBlink(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_BlinkTime,u32 Copy_BlinkNumber)
{
  while (Copy_BlinkNumber)
  {
    if(HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    STK_SetDelay_ms(Copy_BlinkTime);

    HAL_LED_BlinkOnce(Copy_LedPortId, Copy_LedPinId, Copy_BlinkTime);
    Copy_BlinkNumber--;
  }
    return E_OK;
}

Std_ReturnType HAL_LED_BlinkDuration(LED_Port_t Copy_LedPortId, LED_Pin_t Copy_LedPinId, LED_Delay_ms_t Copy_TotalTime,LED_Delay_ms_t Copy_BlinkTime)
{
    if (HAL_LED_xBlink(Copy_LedPortId,Copy_LedPinId,Copy_BlinkTime,Copy_TotalTime/Copy_BlinkTime) == E_OK)
    {
        return E_OK;
    }else
    {
        return E_NOT_OK;
    }  
}
/**
 * @} // End of Public_Functions
 */

