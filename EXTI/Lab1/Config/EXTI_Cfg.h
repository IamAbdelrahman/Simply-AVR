/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: EXTI_Cfg.h
 *	@brief This module contains interface definitions for the
 *	EXTI configuration related to the ATmega32 MCU.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the external interrupt peripheral configuration
 *****************************************************************************/
#ifndef INCLUDES_EXTI_CFG_H_
#define INCLUDES_EXTI_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- DEFINE EXTI NUMBERS */
#define EXTI0 0U
#define EXTI1 1U
#define EXTI2 2U

/*- CONFIGURE EXTI PINS */
#define EXTI0_CFG                                                              \
  (ST_EXTIConfig_t) { &GPIOD2, FALLING, EXTI0, INT0, IRQ_ENABLE }
#define EXTI1_CFG                                                              \
  (ST_EXTIConfig_t) { &GPIOD3, FALLING, EXTI1, INT1, IRQ_ENABLE }
#define EXTI2_CFG                                                              \
  (ST_EXTIConfig_t) { &GPIOB2, FALLING, EXTI2, INT2, IRQ_ENABLE }

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
/*- DEFINE TRIGGER STATE */
typedef enum { LOW_STATE, RISING, FALLING, RISING_FALLING } EN_EXTI_Trigger_t;

/*- DEFINE EXTI PINS NUMBERS */
typedef enum { INT0, INT1, INT2 } EN_IRQ_t;

/*- DEFINE IRQ STATE */
typedef enum { IRQ_DISABLE, IRQ_ENABLE } EN_EXTI_IRQ_State_t;

/*- DEFINE EXTI Configuration */
typedef struct {
  ST_GPIOConfig_t *const pSetExtiPin;
  EN_EXTI_Trigger_t Trigger;
  vuint8_t inputNumber;
  EN_IRQ_t irqNumber;
  EN_EXTI_IRQ_State_t irqState;
  void (*CallbackFunction)(void);
} ST_EXTIConfig_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: EXTI_ConfigGet
 * Syntax: const ST_EXTIConfig_t* const EXTI_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the EXTI based on a config
 * table.
 * PRE-CONDITION: Config table needs to populated (configEXTI > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: A const pointer to the first member of the config table is
 * returned
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_EXTIConfig_t* const
 *************************************************************************/
ST_EXTIConfig_t *const EXTI_ConfigGet(void);

#endif /* INCLUDES_EXTI_CFG_H_ */