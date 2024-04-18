/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.h
 * @brief The interface definition for the application Driver
 *
 * This is the header file for the definition of the interface for
 * the application of toggling leds and turning on a buzzer
 * connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "APP.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function :APP_Init()
 *
 * Description:
 *
 * This function is used to initialize the application of toggling leds
 * in a result of pressing buttons all connected to the MCU's pins.
 *
 * PRE-CONDITION: The MCAL and HAL are configured and initialized
 *
 * POST-CONDITION: The application is initialized

 **********************************************************************/
void APP_Init(void) {
    DIO_Init(DIO_ConfigGet());
}
/**********************************************************************
 * Function :APP_Start()
 *
 * Description: This function is used to start the application
 * if the button1 is pressed, the first led only is on, 
 * if the button2 is pressed, the first and the second led are on
 * and if the button3 is pressed, all leds are on.
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start(void) {
    if (BUTTON_Read(PORTB, Pin0) == LOW) {
        LED_On(PORTA, Pin0);
        LED_Off(PORTA, Pin1);
        LED_Off(PORTA, Pin2);
    }
    
    else if(BUTTON_Read(PORTB, Pin1) == LOW) {
        LED_On(PORTA, Pin0);
        LED_On(PORTA, Pin1);
        LED_Off(PORTA, Pin2);
    }
    else if(BUTTON_Read(PORTB, Pin2) == LOW) {
        LED_On(PORTA, Pin0);
        LED_On(PORTA, Pin1);
        LED_On(PORTA, Pin2);
    }
    else {
        LED_Off(PORTA, Pin0);
        LED_Off(PORTA, Pin1);
        LED_Off(PORTA, Pin2);

    }
}