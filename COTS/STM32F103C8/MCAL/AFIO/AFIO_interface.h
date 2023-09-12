/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 12 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : AFIO_interface.h           *****************/
/****************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#define PORTA       0
#define PORTB       1
#define PORTC       2

Std_ReturnType AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap);

#endif /**< AFIO_INTERFACE_H*/