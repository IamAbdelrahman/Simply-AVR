/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file MOTOR.c
 * @brief The implementation for the MOTOR driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "MOTOR.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
extern vuint32_t MotorConfigSize;
/**********************************************************************
 * Function Definitions
 **********************************************************************/

/**********************************************************************
 * Function : Motor_Init()
 *
 *  Description:
 *  This function is used to initialize the motors to make sure they are stopped
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 * @param Config is a pointer to the configuration table that
 * contains the initialization for the motor.

 *  @return void
 **********************************************************************/
void Motor_Init(const MOTORConfig_t * const Config) {
    vuint8_t i = 0;
    vuint8_t PortNumber = 0;
    vuint8_t PinNumber = 0;
    for (i = 0; i < MotorConfigSize; i++) {
        PortNumber = Config[i].Port % NUMBER_OF_PORTS;
        PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
        if (Config[i].Motor_Number == MOTOR1) {
            DIO_PinWrite(PortNumber, PinNumber, LOW);
        } else if (Config[i].Motor_Number == MOTOR2) {
            DIO_PinWrite(PortNumber, PinNumber, LOW);
        }
    }
}

/**********************************************************************
 * Function : Motor1_State()
 *
 *  Description:
 *  This function is used to configure the state of the motors
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 * @param Config is a pointer to the configuration table that
 * contains the initialization for the motor.
 * @param State is the motor state whether it moves or not

 *  @return void
 **********************************************************************/
void Motor1_State(const MOTORConfig_t * const Config, MOTORState_t State) {
    vuint8_t i = 0;
    vuint8_t PortNumber = 0;
    vuint8_t PinNumber = 0;
    switch (State) {
        case STOP:
            for (i = 0; i < MotorConfigSize; i++) {
                PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                if (Config[i].Motor_Number == MOTOR1) {
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                    i++;
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                } else break;
            }
            break;
        case FORWARD:
            for (i = 0; i < MotorConfigSize; i++) {
                if (Config[i].Motor_Number == MOTOR1) {
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, HIGH);
                    i++;
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                } else break;
            }
            break;

        case BACKWARD:
            for (i = 0; i < MotorConfigSize; i++) {
                PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                if (Config[i].Motor_Number == MOTOR1) {
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                    i++;
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, HIGH);
                } else break;
            }
            break;
        default:
            break;
    }
}

/**********************************************************************
 * Function : Motor2_State()
 *
 *  Description:
 *  This function is used to configure the state of the motors
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition
 * 
 * POST-CONDITION: The motor will have an obvious state
 * @param Config is a pointer to the configuration table that
 * contains the initialization for the motor.
 * @param State is the motor state whether it moves or not

 *  @return void
 **********************************************************************/
void Motor2_State(const MOTORConfig_t * const Config, MOTORState_t State) {
    vuint8_t i = 0;
    vuint8_t PortNumber = 0;
    vuint8_t PinNumber = 0;
    switch (State) {
        case STOP:
            for (i = 2; i < MotorConfigSize; i++) {
                PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                if (Config[i].Motor_Number == MOTOR2) {
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                    i++;
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                } else break;
            }

            break;
        case FORWARD:
            for (i = 2; i < MotorConfigSize; i++) {
                if (Config[i].Motor_Number == MOTOR2) {
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, HIGH);
                    i++;
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                } else break;
            }
            break;

        case BACKWARD:
            for (i = 2; i < MotorConfigSize; i++) {
                PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                if (Config[i].Motor_Number == MOTOR2) {
                    DIO_PinWrite(PortNumber, PinNumber, LOW);
                    i++;
                    PortNumber = Config[i].Port % NUMBER_OF_PORTS;
                    PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;
                    DIO_PinWrite(PortNumber, PinNumber, HIGH);
                } else break;
            }
            break;
        default:
            break;
    }
}

/**********************************************************************
 * Function : Move()
 *
 *  Description:
 *  This function is used to move the robot
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition
 *  PRE-CONDITION: The motor1 is connected to the right wheel of the robot.
 *  PRE-CONDITION: The motor2 is connected to the left wheel of the robot.
 * 
 *  POST-CONDITION: The robot moves to right.

 *  @return void
 **********************************************************************/
void Move(MOVE_t State) {
    switch(State) {
        case NO_MOVE:
            Motor1_State(MOTOR_ConfigGet(), STOP);
            Motor2_State(MOTOR_ConfigGet(), STOP);
            break;
        case MOVE_FORWARD:
            Motor1_State(MOTOR_ConfigGet(), FORWARD);
            Motor2_State(MOTOR_ConfigGet(), FORWARD); 
            Speed(PORTA, Pin4);
            break;
        case MOVE_BACKWARD:
            Motor1_State(MOTOR_ConfigGet(), BACKWARD);
            Motor2_State(MOTOR_ConfigGet(), BACKWARD);  
            Speed(PORTA, Pin4);
            break;
        case MOVE_RIGHT:
            Motor1_State(MOTOR_ConfigGet(), STOP);
            Motor2_State(MOTOR_ConfigGet(), FORWARD); 
            Speed(PORTA, Pin4);
            break;
        case MOVE_LEFT:
            Motor1_State(MOTOR_ConfigGet(), FORWARD);
            Motor2_State(MOTOR_ConfigGet(), STOP);
            Speed(PORTA, Pin4);
            break;
        default:
            break;
    }

}

/**********************************************************************
 * Function : Speed()
 *
 *  Description:
 *  This function is used to determine the speed of the robot
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param Pin is the pin to write using the DIOPin_t enum definition

 *  @return void
 **********************************************************************/
void Speed(DIOPORTX_t Port, DIOPin_t Pin) {
    DIO_PinWrite(Port, Pin, HIGH);
}