/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 9 Sept 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : NVIC_interface.h           *****************/
/****************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

Std_ReturnType NVIC_EnableIRQ(u8 Copy_IRQn);

Std_ReturnType NVIC_DisableIRQ(u8 Copy_IRQn);

Std_ReturnType MCAL_NVIC_SetPendingIRQ(u8 Copy_IRQn);

Std_ReturnType MCAL_NVIC_ClearPendingIRQ(u8 Copy_IRQn);

Std_ReturnType MCAL_NVIC_GetPendingIRQ(u8 Copy_IRQn, u8 *Copy_ReturnPendingFlag);

Std_ReturnType MCAL_NVIC_GetActiveIRQ(u8 Copy_IRQn, u8 *Copy_ReturnActiveFlag);

Std_ReturnType MCAL_NVIC_xSetPriority(u8 Copy_IRQn, u8 Copy_Priority);

Std_ReturnType MCAL_NVIC_vSetPriority(u8 Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority);

#endif /**<NVIC_INTERFACE_H*/