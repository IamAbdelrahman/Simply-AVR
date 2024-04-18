/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file MOTOR.h
 * @brief The interface definition for the MOTOR Driver
 *
 * This is the header file for the definition of the interface for
 * the MOTOR driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef MOTOR_H
#define	MOTOR_H
/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"
#include "MOTOR_Config.h"
/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void Motor_Init(const MOTORConfig_t * const Config);
void Motor1_State(const MOTORConfig_t * const Config, MOTORState_t State);
void Motor2_State(const MOTORConfig_t * const Config, MOTORState_t State);
void Move(MOVE_t State);
void Speed(DIOPORTX_t Port, DIOPin_t Pin);

#endif	/* MOTOR_H */

