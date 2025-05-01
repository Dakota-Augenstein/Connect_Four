/*
 * InterruptControl.h
 *
 *  Created on: Feb 18, 2025
 *      Author: 17205
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

/* Includes */
//#include "STM32F429i.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdint.h>

/* Define */
//#define EXTI0_IRQ_NUMBER 6  // I thought this would be 0 but even though the EXTI.PR is 0 the NVIC pending register is 6 when EXTI is 1
#define REG_SIZE 0x20



/* Function_prototypes */

/* enables an interrupt */
void IRQ_Enable(uint8_t);

/* disables an interrupt */
void IRQ_Disable(uint8_t);

/* Clear pending interrupt */
void IRQ_Clear(uint8_t);

/* Set pending interrupt */
void IRQ_Set(uint8_t);

/* clear pending irq bit */
void IRQ_Clear_Bit(uint8_t);

#endif /* INTERRUPTCONTROL_H_ */

