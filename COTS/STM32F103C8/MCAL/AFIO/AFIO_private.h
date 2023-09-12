/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 12 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : AFIO_private.h             *****************/
/****************************************************************/

#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_

#define AFIO_BASE_ADDRESS     0x40010000

typedef struct 
{
   volatile u32 AFIO_EVCR;
   volatile u32 AFIO_MAPR;
   volatile u32 AFIO_EXTICR[4];
   volatile u32 AFIO_MAPR2;
    } AFIO_RegDef_t;

#define AFIO    ((AFIO_RegDef_t *)(AFIO_BASE_ADDRESS))

#define  MAX_LINE_NUMBER        15
#define  MAX_PORT_NUMBER        2

#endif /**< SCB_PRIVATE_H_ */