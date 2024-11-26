/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: EXTI.c
 *	@brief The implementation for the EXTI.
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "EXTI.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
/*- DEFINE AN ARRAY OF POINTERS TO VOID FUNCTIONS */
void (*gPf_IRQ_Callback[3])(void);

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
inline void GIC_EnableIRQ(void);
inline void GIC_DisableIRQ(void);
void GIC_ClearPendingIRQ(EN_IRQ_t);

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
/*- DEFINE POINTERS TO EXTI AND GIC */
static ST_EXTI_t *const pEXTI = EXTI;
static ST_GIC_t *const pGIC = GIC;

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint32_t configSizeExti;

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
inline void GIC_EnableIRQ(void) { sei(); }

inline void GIC_DisableIRQ(void) { cli(); }

void GIC_ClearPendingIRQ(EN_IRQ_t IRQn) {
  switch (IRQn) {
  case INT0:
    SET_BIT(pGIC->GIFR, INTF0);
    break;
  case INT1:
    SET_BIT(pGIC->GIFR, INTF1);
    break;
  case INT2:
    SET_BIT(pGIC->GIFR, INTF2);
    break;
  default:
    break;
  }
}

ISR(INT0_VECT) {
  SET_BIT(pGIC->GIFR, INTF0);
  gPf_IRQ_Callback[0]();
}

ISR(INT1_VECT) {
  SET_BIT(pGIC->GIFR, INTF1);
  gPf_IRQ_Callback[1]();
}

ISR(INT2_VECT) {
  SET_BIT(pGIC->GIFR, INTF2);
  gPf_IRQ_Callback[2]();
}

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void EXTI_Init(ST_EXTIConfig_t *configPtr) {
  vuint8_t i = 0;
  for (i = 0; i < configSizeExti; i++) {
    GPIO_Init(configPtr[i].pSetExtiPin, 1);
    CLR_NIBBLE(pEXTI->MCUCR, ISC00);
    CLR_BIT(pEXTI->MCUCSR, ISC2);

    if (configPtr[i].irqNumber == INT0) {
      if (configPtr[i].Trigger == RISING) {
        SET_BIT(pEXTI->MCUCR, ISC00);
        SET_BIT(pEXTI->MCUCR, ISC01);
      } else if (configPtr[i].Trigger == FALLING) {
        CLR_BIT(pEXTI->MCUCR, ISC00);
        SET_BIT(pEXTI->MCUCR, ISC01);
      } else if (configPtr[i].Trigger == RISING_FALLING) {
        SET_BIT(pEXTI->MCUCR, ISC00);
        CLR_BIT(pEXTI->MCUCR, ISC01);
      } else if (configPtr[i].Trigger == LOW_STATE) {
        CLR_BIT(pEXTI->MCUCR, ISC00);
        CLR_BIT(pEXTI->MCUCR, ISC01);
      }
      if (configPtr[i].irqState == IRQ_ENABLE) {
        SET_BIT(pGIC->GICR, INTE0);
        GIC_EnableIRQ();
      } else if (configPtr[i].irqState == IRQ_DISABLE) {
        CLR_BIT(pGIC->GICR, INTE0);
        GIC_DisableIRQ();
      }
    }

    else if (configPtr[i].irqNumber == INT1) {
      if (configPtr[i].Trigger == RISING) {
        SET_BIT(pEXTI->MCUCR, ISC10);
        SET_BIT(pEXTI->MCUCR, ISC11);
      } else if (configPtr[i].Trigger == FALLING) {
        CLR_BIT(pEXTI->MCUCR, ISC10);
        SET_BIT(pEXTI->MCUCR, ISC11);
      } else if (configPtr[i].Trigger == RISING_FALLING) {
        SET_BIT(pEXTI->MCUCR, ISC10);
        CLR_BIT(pEXTI->MCUCR, ISC11);
      } else if (configPtr[i].Trigger == LOW_STATE) {
        CLR_BIT(pEXTI->MCUCR, ISC10);
        CLR_BIT(pEXTI->MCUCR, ISC11);
      }
      if (configPtr[i].irqState == IRQ_ENABLE) {
        SET_BIT(pGIC->GICR, INTE1);
        GIC_EnableIRQ();
      } else if (configPtr[i].irqState == IRQ_DISABLE) {
        CLR_BIT(pGIC->GICR, INTE1);
        GIC_DisableIRQ();
      }
    }

    else if (configPtr[i].irqNumber == INT2) {
      if (configPtr[i].Trigger == RISING) {
        SET_BIT(pEXTI->MCUCSR, ISC2);
      } else if (configPtr[i].Trigger == FALLING) {
        CLR_BIT(pEXTI->MCUCSR, ISC2);
      }
      if (configPtr[i].irqState == IRQ_ENABLE) {
        SET_BIT(pGIC->GICR, INTE2);
        GIC_EnableIRQ();
      } else if (configPtr[i].irqState == IRQ_DISABLE) {
        CLR_BIT(pGIC->GICR, INTE2);
        GIC_DisableIRQ();
      }
    }

    gPf_IRQ_Callback[configPtr[i].inputNumber] = configPtr[i].CallbackFunction;
  }
}

void EXTI_Update(ST_EXTIConfig_t *configPtr) { EXTI_Init(configPtr); }

void EXTI_Reset(void) {
  GIC_DisableIRQ();
  CLR_BIT(pGIC->GICR, INTE0);
  CLR_BIT(pGIC->GICR, INTE1);
  CLR_BIT(pGIC->GICR, INTE2);
  CLR_NIBBLE(pEXTI->MCUCR, ISC00);
  CLR_BIT(pEXTI->MCUCSR, ISC2);
}
