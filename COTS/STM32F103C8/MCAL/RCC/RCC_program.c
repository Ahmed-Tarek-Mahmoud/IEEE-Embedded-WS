/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : RCC_program.c              *****************/
/****************************************************************/

/******************************** LIB ***************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/******************************** MCAL **************************/
#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"


Std_ReturnType MCAL_RCC_InitSysClock()
{
      Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    #if RCC_CLKSYS == RCC_HSE
       /*Select which external clock*/
       #if RCC_CLK_BYPASS == RCC_RC_CLK

             SET_BIT(RCC_CR,RCC_CR_HSEBYP);

       #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK

             CLR_BIT(RCC_CR,RCC_CR_HSEBYP);

       #else

         #error "Wrong Choice !"

       #endif /*RCC_CLK_BYPASS*/  

           /*Enable HSE*/
           SET_BIT(RCC_CR,RCC_CR_HSEON);

           /*Wait for stability*/
           while (! GET_BIT(RCC_CR,RCC_CR_HSERDY));

           /* selection */
           RCC_CFGR = 0x00000001;

           Local_FunctionStatus = E_OK;
           
    #elif  RCC_CLKSYS == RCC_HSI

             /*Enable HSI*/
           SET_BIT(RCC_CR,RCC_CR_HSION);

           /*Wait for stability*/
           while (! GET_BIT(RCC_CR,RCC_CR_HSIRDY));
            /* selection */
           RCC_CFGR = 0x00000000;

           Local_FunctionStatus = E_OK;
    #elif RCC_CLKSYS == RCC_PLL 

         /**< Disable the PLL clock. */
        CLR_BIT(RCC_CR, RCC_CR_PLLON);

         /*choose PLL Input SRC*/
         #if RCC_PLL_INPUT == RCC_PLL_HSE
         
            SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);

             /** choose the division status of the HSE input*/
                   #if PLL_HSEDivStatus == RCC_PLL_DivHSE
            
                       SET_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
            
                   #elif PLL_HSEDivStatus == RCC_PLL_NoDivHSE
              
                       CLR_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
                   #else 

                       #error "Wrong Choice !" 
                   #endif /** PLL_HSEDivStatus*/
    
         #elif RCC_PLL_INPUT == RCC_PLL_HSI
         
            CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
         
         #else
               #error "Wrong Choice !"
         
         #endif /*RCC_PLL_INPUT*/

         /** Set PLL Multiplication Factor */
           #if PLL_MulFactor < 16
        
              RCC_CFGR &= ~((0b1111)<<18);
              RCC_CFGR |= (PLL_MulFactor<<18);
           #else
              #error "Wrong Choice !"
           #endif /**PLL_MulFactor*/
         
           /*Enable PLL*/
             SET_BIT(RCC_CR,RCC_CR_PLLON);

           /*Wait for stability*/
           while (! GET_BIT(RCC_CR,RCC_CR_PLLRDY));

           /* selection */
           CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
           SET_BIT(RCC_CFGR,RCC_CFGR_SW1);

           /** Setting the prescalers
            *  AHB and APB2 buses their max frequency is 72 MHz
            *  APB1 max frequency is 36 MHz
            */
           #if RCC_PLL_INPUT == RCC_PLL_HSE && PLL_HSEDivStatus == RCC_PLL_NoDivHSE  
            /**< output of PLL will be 8 MHz */
              /** read the multiplication factor */
              #if PLL_MulFactor > 7     
               /** AHB prescaler */
                   RCC_CFGR &= ~((0b1111)<< RCC_CFGR_AHB_LSB);
                   RCC_CFGR |= (1000<< RCC_CFGR_AHB_LSB);
                   /** prefetch buffer must be On */
                   SET_BIT(FLASH_ACR,FLASH_ACR_PRFTBE);
                   /** setting latency */
                    u32 SYSCLK = 4 * (PLL_MulFactor + 2);
                    #if PLL_MulFactor < 5
                    /** Zero wait states */
                         FLASH_ACR &= ~((0b111)<< FLASH_ACR_LAT_LSB);
                    #elif PLL_MulFactor < 10
                    /** One wait state */
                         FLASH_ACR &= ~((0b111)<< FLASH_ACR_LAT_LSB);
                         FLASH_ACR |= (001<< FLASH_ACR_LAT_LSB);    
                    #else
                      /** Two wait states */
                         FLASH_ACR &= ~((0b111)<< FLASH_ACR_LAT_LSB);
                         FLASH_ACR |= (010<< FLASH_ACR_LAT_LSB);
                    #endif

               /** APB2 prescaler */
                   RCC_CFGR &= ~((0b111)<< RCC_CFGR_APB2_LSB);
                   RCC_CFGR |= (100<< RCC_CFGR_APB2_LSB);
              #else
                /** AHB prescaler -> Not divided */
               CLR_BIT(RCC_CFGR,RCC_CFGR_AHB_MSB);   

               /** APB2 prescaler -> Not divided */
               CLR_BIT(RCC_CFGR,RCC_CFGR_APB2_MSB);
              #endif
              
               #if PLL_MulFactor > 2 && PLL_MulFactor < 7
                   /** APB1 prescaler -> divide by 2 */
                  RCC_CFGR &= ~((0b111)<< RCC_CFGR_APB1_LSB);
                  RCC_CFGR |= (100<< RCC_CFGR_APB1_LSB);
               #elif PLL_MulFactor > 7
                   /** APB1 prescaler -> divide by 4 */
                  RCC_CFGR &= ~((0b111)<< RCC_CFGR_APB1_LSB);
                  RCC_CFGR |= (101<< RCC_CFGR_APB1_LSB);
               #else
                  /** APB1 prescaler -> No divide */
                  CLR_BIT(RCC_CFGR,RCC_CFGR_APB1_MSB);
               #endif


           #else /**< output of PLL will be 4 MHz */

               /** read the multiplication factor */
               #if PLL_MulFactor > 7      /** APB1 prescaler */
                  RCC_CFGR &= ~((0b111)<< RCC_CFGR_APB1_LSB);
                  RCC_CFGR |= (100<< RCC_CFGR_APB1_LSB);
                #else
                  CLR_BIT(RCC_CFGR,RCC_CFGR_APB1_MSB);
               #endif /** PLL_MulFactor */

               /** AHB prescaler -> Not divided */
               CLR_BIT(RCC_CFGR,RCC_CFGR_AHB_MSB);   

               /** APB2 prescaler -> Not divided */
               CLR_BIT(RCC_CFGR,RCC_CFGR_APB2_MSB); 

           #endif /** setting prescalers */


    #else
      #error "Wrong Choice !"   
 
     #endif /**RCC_SYSCLK*/

     return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_BusId ,u8 Copy_PeripheralId)
{
Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Enable the peripheral on the AHB bus. */
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_BusId ,u8 Copy_PeripheralId)
{
Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Disable the peripheral on the AHB bus. */
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}