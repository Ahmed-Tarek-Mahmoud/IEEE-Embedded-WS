/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 29 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : GPIO_interface.h           *****************/
/****************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H 

/*******************< Ports Macros ********************/

#define GPIO_PORTA   0  /**< Port A */
#define GPIO_PORTB   1  /**< Port B */
#define GPIO_PORTC   2  /**< Port C */

/*******************< Pin Value Macros ********************/

#define GPIO_LOW            0   /**< GPIO Low value */
#define GPIO_HIGH           1   /**< GPIO High value */

/*******************< Pins Macros ********************/

#define GPIO_PIN0           0  /**< GPIO Pin 0 */
#define GPIO_PIN1           1  /**< GPIO Pin 1 */
#define GPIO_PIN2           2  /**< GPIO Pin 2 */
#define GPIO_PIN3           3  /**< GPIO Pin 3 */
#define GPIO_PIN4           4  /**< GPIO Pin 4 */
#define GPIO_PIN5           5  /**< GPIO Pin 5 */
#define GPIO_PIN6           6  /**< GPIO Pin 6 */
#define GPIO_PIN7           7  /**< GPIO Pin 7 */
#define GPIO_PIN8           8  /**< GPIO Pin 8 */
#define GPIO_PIN9           9  /**< GPIO Pin 9 */
#define GPIO_PIN10          10 /**< GPIO Pin 10 */
#define GPIO_PIN11          11 /**< GPIO Pin 11 */
#define GPIO_PIN12          12 /**< GPIO Pin 12 */
#define GPIO_PIN13          13 /**< GPIO Pin 13 */
#define GPIO_PIN14          14 /**< GPIO Pin 14 */
#define GPIO_PIN15          15 /**< GPIO Pin 15 */

/*******************< Pin Input Modes **********************/

#define GPIO_INPUT_ANALOG                 0b0000
#define GPIO_INPUT_FLOATING               0b0100
#define GPIO_INPUT_Pull_Up_Down           0b1000

/*******************< Pin Output Modes **********************/

#define GPIO_OUTPUT_PP_10MHZ                     0b0001 /**< GPIO Output Push-Pull Mode, 10MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ             0b0101 /**< GPIO Output Open-Drain Mode, 10MHz */
#define GPIO_OUTPUT_AF_PP_10MHZ                  0b1001 /**< GPIO Output Alternate Function Push-Pull Mode, 10MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_10MHZ          0b1101 /**< GPIO Output Alternate Function Open-Drain Mode, 10MHz */

#define GPIO_OUTPUT_PP_2MHZ                      0b0010 /**< GPIO Output Push-Pull Mode, 2MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ              0b0110 /**< GPIO Output Open-Drain Mode, 2MHz */
#define GPIO_OUTPUT_AF_PUSH_PULL_2MHZ            0b1010 /**< GPIO Output Alternate Function Push-Pull Mode, 2MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_2MHZ           0b1110 /**< GPIO Output Alternate Function Open-Drain Mode, 2MHz */

#define GPIO_OUTPUT_PP_50MHZ                     0b0011 /**< GPIO Output Push-Pull Mode, 50MHz */
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ             0b0111 /**< GPIO Output Open-Drain Mode, 50MHz */
#define GPIO_OUTPUT_AF_PP_50MHZ                  0b1011 /**< GPIO Output Alternate Function Push-Pull Mode, 50MHz */
#define GPIO_OUTPUT_AF_OPEN_DRAIN_50MHZ          0b1111 /**< GPIO Output Alternate Function Open-Drain Mode, 50MHz */

Std_ReturnType MCAL_GPIO_SetPinMode(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_PinMode);

Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_PortId,u8 Copy_PinId,u8 Copy_PinValue);

Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_PortId,u8 Copy_PinId,u8 *Copy_PinValue);

Std_ReturnType MCAL_GPIO_TogglePin(u8 Copy_PortId, u8 Copy_PinId);

#endif /* GPIO_INTERFACE_H */