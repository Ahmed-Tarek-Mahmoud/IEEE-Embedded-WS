/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 10 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : SCB_private.h              *****************/
/****************************************************************/

#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_

/**
 * @defgroup SCB Registers addresses
 * @brief  Macros for addresses of system block control registers
 * @{
*/

#define  SCB_CPUID           *((volatile u32 *) 0xE000ED00 )
#define  SCB_ICSR            *((volatile u32 *) 0xE000ED04 )
#define  SCB_VTOR            *((volatile u32 *) 0xE000ED08 )
#define  SCB_AIRCR           *((volatile u32 *) 0xE000ED0C )
#define  SCB_SCR             *((volatile u32 *) 0xE000ED10 )
#define  SCB_CCR             *((volatile u32 *) 0xE000ED14 )
#define  SCB_SHPR1           *((volatile u32 *) 0xE000ED18 )
#define  SCB_SHPR2           *((volatile u32 *) 0xE000ED1C )
#define  SCB_SHPR3           *((volatile u32 *) 0xE000ED20 )

/** @} end of SCB Registers addresses */

/**
 * @brief Priority Grouping Values
 * @{
 */

#define SCB_16GROUP_0SUB   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define SCB_8GROUP_2SUB    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define SCB_4GROUP_4SUB    0x05FA0500U /**< 4 Priority Levels, 4 Sub-priority Levels */
#define SCB_2GROUP_8SUB    0x05FA0600U /**< 2 Priority Levels, 8 Sub-priority Levels */
#define SCB_0GROUP_16SUB   0x05FA0700U /**< No Grouping, 16 Sub-priority Levels */

/** @} end of Priority Grouping Values*/

#endif /** SCB_PRIVATE_H_ */