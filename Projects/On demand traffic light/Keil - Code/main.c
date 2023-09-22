/****************************************************************/
/***    **** Author    : Ahmed Tarek Mahmoud        *****************/
/******* Date      : 17 Sept 2023               *****************/
/******* Version   : 0.1                        *****************/
/******* Module    : MiniProject.c              *****************/
/****************************************************************/

/****************************< LIB ******************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
/****************************< MCAL *****************************/
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "SCB_interface.h"
#include "NVIC_interface.h"
/****************************< HAL ******************************/
#include "LED.h"

/****************************< APP ******************************/

void ButtonPressed(void);

void CarGo(void);

void Yellow(void);

void PassGo(void);

u8 prevButtonState = 0;

 u8 Yellow_is_blinking=0;
 u8 buttonClick =0;

int main(void)
{
	/********************< Setup Code ***************************/
	MCAL_RCC_InitSysClock();
    /***< Enable port A */
    MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
    //EXTI0_SetCallBack(ButtonPressed);
    
    /***< Set the modes of Cars Traffic Light LEDS */
    MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_PP_2MHZ);
    MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_PP_2MHZ);
    MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_PP_2MHZ);
    /***< Set the modes of Passengers Traffic Light LEDS */
    MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT_PP_2MHZ);
    MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUT_PP_2MHZ);
    MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUT_PP_2MHZ);
    /***< Set the mode of the button pin */
    EXTI_Init();
    MCAL_NVIC_EnableIRQ(6);
    MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_Pull_Up_Down);
    AFIO_SetEXTIConfiguration(EXTI_LINE0,PORTA);
    EXTI_SetCallBack(ButtonPressed);
    
    /***********************< Body ******************************/
    while(1)
    {
        // Green led for cars & Red led for ped. is on for five seconds
        CarGo();
        // After 5 second  Green led for cars & Red led for ped. switched OFF 
        // And yellow LEDs of both will blinking for five second
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW); // GREEN LED FOR CARS
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW); // RED LED FOR PEDESTRIANS
        Yellow();
        // After yellow blinking for 5 seconds 
        // Red led for cars & green led for ped. is on for five seconds
        // then yellow blinking again 
        PassGo();
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW); // RED LED FOR CARS        
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW); // GREEN LED FOR PEDESTRIANS
        Yellow();

    }   
}
void CarGo(void){
    /*****< Car green */
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
    /*****< Passenger red */
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW);
    /*****< Delay 5 sec */
    STK_SetDelay_ms(5000);
}
void Yellow(void)
{
    Yellow_is_blinking = 1;
    u8 Dur = 8; 
    while(Dur--)
    {  
        HAL_LED_Toggle(LED_PORTA,LED_PIN2);
        HAL_LED_Toggle(LED_PORTA,LED_PIN5);
        STK_SetDelay_ms(500);
    }

    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
    Yellow_is_blinking = 0;
}
void PassGo(void)
{
    /*****< Car Red */
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
    /*****< Passenger Green */
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_HIGH);
    /*****< Delay 5 sec */
    STK_SetDelay_ms(5000); 
}

void ButtonPressed(void) {
   // Debouncing Software Solution
   // // Add a delay for debouncing
   // STK_SetDelay_ms(100);
   //
   // // Read the button state multiple times
   // u8 currButtonState;
   // for (int i = 0; i < 5; i++) {
   //     MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN0, &currButtonState);
   //     if (currButtonState != prevButtonState) {
   //         // Button state changed during debouncing, ignore the press
   //         return;
   //     }
   //     // Add a small delay between each read
   //     STK_SetDelay_ms(100 / 5);
   // }

   // Long Press Detection
   STK_SetDelay_ms(1000);
   u8 currButtonState;
   MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN0, &currButtonState);
   if (currButtonState == 1)
   {
    return;
   }else
   {

     u8 val1;
     u8 val2;
     MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN1,&val1);
     MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN3,&val2);

    /*                  FIRST CASE 
	       If BUTTON is pressed when the cars' Red LED is on
	 the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds
	*/ 
    
     if (val1)
     {
        PassGo();
     }

    /*                  SECOND CASE 
	      If BUTTON is pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
	*/ 
     else if (val2 || Yellow_is_blinking)
     {
        // both Yellow LEDs start to blink for five seconds,
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW); // GREEN LED FOR CARS
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH); // RED LED FOR PEDESTRIANS
        Yellow();
        MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW); // RED LED FOR PEDESTRIANS
        // then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
        PassGo();
     }else
     {
        main();
        return;
     }
     // 	 -------------->>>>>>> At the end of the two states  <<<<<<------------------

     // 	 the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds
     // 	 and the pedestrian's Green LED is still on
     MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW); // RED LED FOR CARS   
     Yellow();
     MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN6,GPIO_LOW); // GREEN LED FOR PEDESTRIANS
     CarGo();
     MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW); // GREEN LED FOR CARS
     MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW); // RED LED FOR PEDESTRIANS
     main();
   }
   
}