/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: EXTI.h
 * 	@brief The interface definition for the EXTI.
 *
 *	@details: This is the header file for the definition of the interface
 *      for a EXTI peripheral on a standard microcontroller.
 *****************************************************************************/
#ifndef EXTI_H_
#define EXTI_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "EXTI_Cfg.h"
#include "GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/* SET THE GLOBAL INTERRUPT */
#define sei() __asm__ __volatile__("sei" ::: "memory")

/* CLEAR THE GLOBAL INTERRUPT */
#define cli() __asm__ __volatile__("cli" ::: "memory")

/*- DEFINE ISR */
#define ISR(INT_VECT)                                                          \
  void INT_VECT(void) __attribute__((signal, used));                           \
  void INT_VECT(void)

#define INT0_VECT __vector_1
#define INT1_VECT __vector_2
#define INT2_VECT __vector_3

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- DEFINE MCUCR REGISTER BITS */
typedef enum { ISC00, ISC01, ISC10, ISC11, SM0, SM1, SM2, SE } EN_MCUCR_t;

/*- DEFINE MCUCSR REGISTER BITS */
typedef enum {
  PORF,
  EXTRF,
  BORF,
  WDRF,
  JTRF,
  ISC2 = 6,
  JTD,
} EN_MCUCSR_t;

/*- DEFINE GICR REGISTER BITS */
typedef enum { IVCE, IVSEL, INTE2 = 5, INTE0, INTE1 } EN_GICR_t;

/*- DEFINE GIFR REGISTER BITS */
typedef enum { INTF2 = 5, INTF0, INTF1 } EN_GIFR_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: EXTI_Init
 * Syntax: void EXTI_Init(ST_EXTIConfig_t *configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize the EXTI
 * @param (in): configPtr a pointer to EXTIConfig_t struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void EXTI_Init(ST_EXTIConfig_t *configPtr);

/************************************************************************
 * Service Name: EXTI_Update
 * Syntax: void EXTI_Update(ST_EXTIConfig_t *configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Update the state of EXTI
 * @param (in): configPtr a pointer to EXTIConfig_t struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void EXTI_Update(ST_EXTIConfig_t *configPtr);

/************************************************************************
 * Service Name: EXTI_Reset
 * Syntax: void EXTI_Reset(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset the state of EXTI
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void EXTI_Reset(void);

#endif /* EXTI_H_ */