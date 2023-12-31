/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 9 Sept 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : EXTI_interface.h           *****************/
/****************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/**
 * @defgroup EXTI_Configurations EXTI Line Configurations
 * @brief Configuration options for EXTI lines.
 * @{
 */

/**
 * @name EXTI Trigger Edge Selection
 * @{
 */
#define EXTI_RISING_EDGE  0   /**< Configure for rising edge trigger. */
#define EXTI_FALLING_EDGE 1   /**< Configure for falling edge trigger. */
#define EXTI_BOTH_EDGES   2   /**< Configure for both rising and falling edge trigger. */
/** @} */

/**
 * @name EXTI Line Numbers
 * @{
 */
#define EXTI_LINE0  0   /**< EXTI line number for GPIO pin 0. */
#define EXTI_LINE1  1   /**< EXTI line number for GPIO pin 1. */
#define EXTI_LINE2  2   /**< EXTI line number for GPIO pin 2. */
#define EXTI_LINE3  3   /**< EXTI line number for GPIO pin 3. */
#define EXTI_LINE4  4   /**< EXTI line number for GPIO pin 4. */
#define EXTI_LINE5  5   /**< EXTI line number for GPIO pin 5. */
#define EXTI_LINE6  6   /**< EXTI line number for GPIO pin 6. */
#define EXTI_LINE7  7   /**< EXTI line number for GPIO pin 7. */
#define EXTI_LINE8  8   /**< EXTI line number for GPIO pin 8. */
#define EXTI_LINE9  9   /**< EXTI line number for GPIO pin 9. */
#define EXTI_LINE10 10  /**< EXTI line number for GPIO pin 10. */
#define EXTI_LINE11 11  /**< EXTI line number for GPIO pin 11. */
#define EXTI_LINE12 12  /**< EXTI line number for GPIO pin 12. */
#define EXTI_LINE13 13  /**< EXTI line number for GPIO pin 13. */
#define EXTI_LINE14 14  /**< EXTI line number for GPIO pin 14. */
#define EXTI_LINE15 15  /**< EXTI line number for GPIO pin 15. */
/** @} */

/** @} */  // End Of EXTI Configurations

/**
 * @name EXTI Port Mapping
 * @{
 */
#define EXTI_GPIO_NONE      ((INVALID_VALUE)-1) /**< A special value indicating no GPIO port is mapped to the EXTI line. */
#define EXTI_PORTMAP_GPIOA  0 /**< Map EXTI line to GPIO Port A. */
#define EXTI_PORTMAP_GPIOB  1 /**< Map EXTI line to GPIO Port B. */
#define EXTI_PORTMAP_GPIOC  2 /**< Map EXTI line to GPIO Port C. */
/** @} */

Std_ReturnType EXTI_Init(void);

Std_ReturnType EXTI_EnableLine(u8 Copy_Line);

Std_ReturnType EXTI_DisableLine(u8 Copy_Line);

/**
 * @brief Set the trigger mode for an external interrupt line.
 *
 * This function sets the trigger mode (e.g., rising edge, falling edge, both edges)
 * for the specified external interrupt line.
 *
 * @param[in] Copy_Line The external interrupt line to configure.
 * @param[in] Copy_Mode The trigger mode to set (e.g., EXTI_TRIGGER_RISING, EXTI_TRIGGER_FALLING, EXTI_BOTH_EDGES).
 */

Std_ReturnType EXTI_SetPinTriggger(u8 Copy_Line, u8 Copy_Mode);

void EXTI_SetCallBack(void (*pf)(void));


#endif /**< EXTI_INTERFACE_H*/