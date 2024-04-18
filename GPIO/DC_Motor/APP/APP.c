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
    Motor_Init(MOTOR_ConfigGet());
}
/**********************************************************************
 * Function :APP_Start()
 *
 * Description: This function is used to start the application of moving
 * a robot
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start(void) {
    Move(MOVE_FORWARD);
    _delay_ms(5000);
    Move(NO_MOVE);
    _delay_ms(1000);
    
    Move(MOVE_BACKWARD);
    _delay_ms(5000);
    Move(NO_MOVE);
    _delay_ms(1000); 
    
    Move(MOVE_RIGHT);
    _delay_ms(3000);
    Move(NO_MOVE);
    _delay_ms(1000);
    
    Move(MOVE_LEFT);
    _delay_ms(3000);
    Move(NO_MOVE);
    _delay_ms(1000);
}

