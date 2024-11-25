/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.c
 *	@brief The implementation of the application driver
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "APP.h"

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint16_t data;
ST_LEDConfig_t* pLED;

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void APP_Init(void) {
    UART_Init(UART_ConfigGet());
    LED_Init();
    pLED = LED_ConfigGet();
}

void APP_Start(void) {
    UART_ReceiveData(&data);
    if (data == 'N') {
        pLED->ledState = HIGH;
        LED_Control(pLED);
    }
    else if (data == 'F') {
        pLED->ledState = LOW;
        LED_Control(pLED);
    }
}