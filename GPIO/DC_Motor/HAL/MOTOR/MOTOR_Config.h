/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file MOTOR_Config.h
 * @brief This module contains interface definitions for the
 *  MOTOR driver.
 * 
 * @author Abdelrahman Kamal
 *
 */

#ifndef MOTOR_CONFIG_H
#define	MOTOR_CONFIG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "ATmega32.h"
#include "DIO_Config.h"

/**********************************************************************
 * Typedefs
 **********************************************************************/

/**
 * Defines an enumerated list of all states of a motor
 * device.
 */
typedef enum {
    STOP = 0, FORWARD, BACKWARD

} MOTORState_t;

/**
 * Defines an enumerated list of number of motors used
 */
typedef enum {
    MOTOR1 = 1, MOTOR2
} MOTORNumber_t;

/**
 * Defines an enumerated list of all moving states
 *  of a robot device.
 */
typedef enum {
    NO_MOVE, MOVE_FORWARD, MOVE_BACKWARD, MOVE_RIGHT, MOVE_LEFT

}MOVE_t;
/**
 * Defines Motor configuration table elements that are
 used by Motor_Init() to configure the Motor device.
 */
typedef struct {
    MOTORNumber_t Motor_Number;
    DIOPORTX_t Port;
    DIOPin_t Pin;
} MOTORConfig_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const MOTORConfig_t * const MOTOR_ConfigGet(void);


#endif	/* MOTOR_CONFIG_H */

