/****************************************************************/
/******* Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : RCC_config.c               *****************/
/****************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/**
 * your options for the system clock    RCC_HSI
 *                                      RCC_HSE
 *                                      RCC_PLL
*/

#define RCC_CLKSYS   RCC_HSE


#if  RCC_CLKSYS == RCC_HSE

/**
 * your options for the source of the clock  RCC_RC_CLK        -> RC cicuit will be the source
 *                                           RCC_CRYSTAL_CLK   -> Crystal will be the source
*/

   #define RCC_CLK_BYPASS     RCC_CRYSTAL_CLK 

#endif /* RCC_CLKSYS == RCC_HSE */

#if RCC_CLKSYS == RCC_PLL

/**
 * your options for the source of the PLL   RCC_PLL_HSI    -> HSI oscillator clock / 2 selected as PLL input clock
 *                                          RCC_PLL_HSE    -> HSE oscillator clock selected as PLL input clock
*/

  #define RCC_PLL_INPUT  RCC_PLL_HSE

  #if RCC_PLL_INPUT == RCC_PLL_HSE
   /**
    * your options to choose whether the HSE input yo be divided by 2 or not
    *      RCC_PLL_DivHSE        ->     HSE oscillator clock will be divided by 2 
           RCC_PLL_NoDivHSE      ->     HSE oscillator clock will not be divided
   */
  #define PLL_HSEDivStatus   RCC_PLL_NoDivHSE 

    /**
     * your option to choose the multiplication factor of the PLL input 
     *   PLL_MULLx   where x is the multiplication factor x:[2,16]
     *   x between 2 and 16
    */
   #define PLL_MulFactor    PLL_MULL10

  #endif /**RCC_PLL_INPUT == RCC_PLL_HSI*/
#endif /*RCC_CLKSYS == RCC_PLL*/

#endif /* RCC_config.h */