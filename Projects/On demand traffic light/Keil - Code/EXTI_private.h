/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 9 Sept 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : EXTI_private.h             *****************/
/****************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS       0x40010400U

typedef struct 
{
   u32 EXTI_IMR;
   u32 EXTI_EMR;
   u32 EXTI_RTSR;
   u32 EXTI_FTSR;
   u32 EXTI_SWIER;
   u32 EXTI_PR;
}volatile EXTI_RegDef_t;

#define EXTI    ((EXTI_RegDef_t *)(EXTI_BASE_ADDRESS))

/**< Total number of EXTI lines available */
#define EXTI_LINES_COUNT        16

/**< EXTI line enabled */
#define EXTI_LINE_ENABLED       1

/**< EXTI line disabled */
#define EXTI_LINE_DISABLED      0

/**< EXTI Configuration Structure */
typedef struct 
{
    u8 GPIO_PortMap: 3;         /**< GPIO port to be used (EXTI_GPIO_PORTA, EXTI_GPIO_PORTB, etc.) */
    u8 TriggerType: 2;          /**< Trigger type (EXTI_TRIGGER_RISING, EXTI_TRIGGER_FALLING, EXTI_TRIGGER_BOTH, etc.) */
    u8 LineEnabled: 1;          /**< EXTI line enabled or disabled (1 or 0) */
    u8 : 2;                     /**< 2 bits of padding */
} EXTI_Configuration;

/**< EXTI line configuration settings */
extern EXTI_Configuration EXTI_Configurations[EXTI_LINES_COUNT];

/**< IRQ Handler */
void (*IRQ_Handler)(void) = NULL;

#endif /**< EXTI_PRIVATE_H*/