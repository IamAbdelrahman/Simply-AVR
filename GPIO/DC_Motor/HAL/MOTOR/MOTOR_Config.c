/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file MOTOR_Config.c
 * @brief This module contains the implementation for the Motor configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "MOTOR_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each Motor device.
 * This table is read in by Motor_Init().
 */
const MOTORConfig_t MOTORConfig[] = {
/*   MOTOR_N        PORT			PIN      			*/
    {MOTOR1,         PORTA,           Pin0},
    {MOTOR1,         PORTA,           Pin1},
    {MOTOR2,         PORTA,           Pin2},
    {MOTOR2,         PORTA,           Pin3}
};

vuint32_t MotorConfigSize = sizeof(MOTORConfig) / sizeof(MOTORConfig[0]);

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : Dio_ConfigGet()
 *
 * This function is used to initialize the DIO based on the configuration
 * table defined in dio_config module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const MOTORConfig_t * const MOTOR_ConfigGet(void){
	return (MOTORConfig_t *const)&MOTORConfig[0];
}
