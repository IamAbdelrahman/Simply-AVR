/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file 7-SEG.h
 * @brief The interface definition for the 7-segment Driver
 *
 * This is the header file for the definition of the interface for
 * the 7-segment driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef _SEG_H
#define	_SEG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void SevenSegment_DisplayDigit(DIOPORTX_t Port, vuint8_t digit);
void SevenSegment_DisplayLetter(DIOPORTX_t Port, vuint8_t letter);
void SevenSegment_Clear(DIOPORTX_t Port);

#endif	/* _SEG_H */

