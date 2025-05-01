/*
 * InterruptControl.c
 *
 *  Created on: Feb 18, 2025
 *      Author: 17205
 */

/* include */
#include "InterruptControl.h"
#include "stm32f4xx_hal.h"
/* define */

/* Function_prototypes */

/* enables an interrupt */
void IRQ_Enable(uint8_t IRQ_Number){
	HAL_NVIC_EnableIRQ(IRQ_Number);
	//if(IRQ_Number < REG_SIZE){
	//	*NVIC_ISER0 |= (SET << IRQ_Number);
	//}
}

/* disables an interrupt */
void IRQ_Disable(uint8_t IRQ_Number){
	HAL_NVIC_DisableIRQ(IRQ_Number);
	//if(IRQ_Number < REG_SIZE){
	//	*NVIC_ICER0 |= (SET << IRQ_Number);
	//}
}

/* Clear pending interrupt */
void IRQ_Clear(uint8_t IRQ_Number){
	HAL_NVIC_ClearPendingIRQ(IRQ_Number);
	//if(IRQ_Number < REG_SIZE){
	//	*NVIC_ICPR0 |= (SET << IRQ_Number);
	//}
}

/* Set pending interrupt */
void IRQ_Set(uint8_t IRQ_Number){
	HAL_NVIC_SetPendingIRQ(IRQ_Number);
	//if(IRQ_Number < REG_SIZE){
	//	*NVIC_ISPR0 |= (SET << IRQ_Number);
	//}
}

/* clear pending irq bit */
// updated for HAL usage if more than EXTI0 is used woudl need to add a switch case based on the line
void IRQ_Clear_Bit(uint8_t IRQ_Pin_Num){
	EXTI_HandleTypeDef EXTI0_H;
	EXTI0_H.Line = EXTI_LINE_0;
	HAL_EXTI_ClearPending(&EXTI0_H, EXTI_TRIGGER_FALLING);
	//EXTI->PR |= (SET << IRQ_Pin_Num);
}




