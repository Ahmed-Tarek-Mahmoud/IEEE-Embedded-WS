/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 9 Sept 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : EXTI_config.h              *****************/
/****************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/**
 * @brief EXTI Configuration Array
 *
 * This array is used to configure the EXTI lines. Each element in the array represents
 * the configuration for a specific EXTI line.
 *
 * To configure an EXTI line, set the appropriate options for LineEnabled and TriggerType.
 *
 * Available options for LineEnabled:
 * - EXTI_LINE_ENABLED: Enable the EXTI line.
 * - EXTI_LINE_DISABLED: Disable the EXTI line.
 *
 * Available options for TriggerType:
 * - EXTI_RISING_EDGE: Configure for rising edge trigger.
 * - EXTI_FALLING_EDGE: Configure for falling edge trigger.
 * - EXTI_BOTH_EDGES: Configure for both rising and falling edge trigger.
 * Available options for GPIO_PortMap:
 * - EXTI_GPIO_NONE: No GPIO port is mapped to the EXTI line.
 * - EXTI_PORTMAP_GPIOA: Map EXTI line to GPIO Port A.
 * - EXTI_PORTMAP_GPIOB: Map EXTI line to GPIO Port B.
 * - EXTI_PORTMAP_GPIOC: Map EXTI line to GPIO Port C.
 */
EXTI_Configuration EXTI_Configurations[EXTI_LINES_COUNT] = {

    /**< Configuration for EXTI Line 0 */
    {
        .LineEnabled   = EXTI_LINE_ENABLED,
        .TriggerType   = EXTI_RISING_EDGE,
        .LineEnabled   = EXTI_LINE_ENABLED,
    },

    /* Configuration for EXTI Line 1 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_FALLING_EDGE,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },

    /* Configuration for EXTI Line 2 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 3 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 4 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
        .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 5 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 6 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 7 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 8 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 9 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 10 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_RISING_EDGE,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 11 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 12 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 13 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 14 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
    /* Configuration for EXTI Line 15 */
    {
        .LineEnabled   = EXTI_LINE_DISABLED,
        .TriggerType   = EXTI_BOTH_EDGES,
         .LineEnabled   = EXTI_LINE_DISABLED,
    },
    
};

#endif /**< EXTI_CONFIG_H*/