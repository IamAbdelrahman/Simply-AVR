/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file 7-SEG.c
 * @brief The implementation for the 7-SEG driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "7-SEG.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/

/**********************************************************************
 * Function : SevenSegment_DisplayDigit()
 *
 *  Description:
 *  This function is used to display a digit on 
 *  a 7-segment connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param digit is the input digit by the user to be displayed from (0:9)

 *  @return void
 **********************************************************************/
void SevenSegment_DisplayDigit(DIOPORTX_t Port, vuint8_t digit) {
    switch (digit) {
        case 0:
            DIO_WritePort(Port, 63);
            break;
        case 1:
            DIO_WritePort(Port, 6);
            break;
        case 2:
            DIO_WritePort(Port, 91);
            break;
        case 3:
            DIO_WritePort(Port, 79);
            break;
        case 4:
            DIO_WritePort(Port, 102);
            break;
        case 5:
            DIO_WritePort(Port, 109);
            break;
        case 6:
            DIO_WritePort(Port, 125);
            break;
        case 7:
            DIO_WritePort(Port, 7);
            break;
        case 8:
            DIO_WritePort(Port, 127);
            break;
        case 9:
            DIO_WritePort(Port, 111);
            break;
        default:
            break;
    }
}

/**********************************************************************
 * Function : SevenSegment_DisplayLetter()
 *
 *  Description:
 *  This function is used to display a capital letter on 
 *  a 7-segment connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param letter is the input letter by the user to be displayed 
 *  the only allowed letters are (A, B, C, E, F, H, L, O, P, S, U)

 *  @return void
 **********************************************************************/
void SevenSegment_DisplayLetter(DIOPORTX_t Port, vuint8_t letter) {
    switch (letter) {
        case 'A':
            DIO_WritePort(Port, 119);
            break;
        case 'B':
            DIO_WritePort(Port, 127);
            break;
        case 'C':
            DIO_WritePort(Port, 57);
            break;
        case 'E':
            DIO_WritePort(Port, 121);
            break;
        case 'F':
            DIO_WritePort(Port, 113);
            break;
        case 'H':
            DIO_WritePort(Port, 118);
            break;
        case 'L':
            DIO_WritePort(Port, 56);
            break;
        case 'O':
            DIO_WritePort(Port, 63);
            break;
        case 'P':
            DIO_WritePort(Port, 115);
            break;
        case 'S':
            DIO_WritePort(Port, 109);
            break;
        case 'U':
            DIO_WritePort(Port, 62);
            break;
        default:
            break;
    }
}

/**********************************************************************
 * Function : SevenSegment_Clear()
 *
 *  Description:
 *  This function is used to clear
 *  a 7-segment connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @return void
 **********************************************************************/
void SevenSegment_Clear(DIOPORTX_t Port) {
    DIO_WritePort(Port, 0);
}