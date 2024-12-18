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

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
#define TX 1U
#define RX -1
#define UART_MODE TX

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
#if (UART_MODE == RX)
vuint16_t rxData;
ST_LEDConfig_t *pLED;
#elif (UART_MODE == TX)
vuint16_t txData;
ST_BUTTONConfig_t *pBUTTON;
#else
#endif

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
#if (UART_MODE == RX)
  LED_Init();
  pLED = LED_ConfigGet();
#elif (UART_MODE == TX)
  BUTTON_Init();
  pBUTTON = BUTTON_ConfigGet();
#else
#endif
}

void APP_Start(void) {
#if (UART_MODE == RX)
  UART_ReceiveData(&rxData);
  if (rxData == 'N') {
    pLED->ledState = HIGH;
    LED_Control(pLED);
  } else if (rxData == 'F') {
    pLED->ledState = LOW;
    LED_Control(pLED);
  }
#elif (UART_MODE == TX)
  if (!BUTTON_Read(pBUTTON)) {
    txData == 'N';
    UART_SendData(&txData);
  }
  if (!BUTTON_Read(&pBUTTON[1])) {
    txData == 'F';
    UART_SendData(&txData);
  }
#else
#endif
}
