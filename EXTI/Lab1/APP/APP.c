/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.c
 *	@brief The implementation of the application driver
 *  @description: Using an external interrupt to control LEDs
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "APP.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/


/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
ST_LEDConfig_t* pLED;

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
void EXTI0_ISR (void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
void EXTI0_ISR (void) {
    pLED[1].ledState = HIGH;
    LED_Control(&pLED[1]);
}

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void APP_Init(void) {
    EXTI_ConfigGet()->CallbackFunction = EXTI0_ISR;
    EXTI_Init(EXTI_ConfigGet());
    LED_Init();
    pLED = LED_ConfigGet();
}

void APP_Start(void) {
    pLED[0].ledState = TOGGLE;
    LED_Control(&pLED[0]);
    _delay_ms(1000);
}