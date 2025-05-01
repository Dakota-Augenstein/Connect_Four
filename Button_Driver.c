/*
 * Button_Driver.c
 *
 *  Created on: Feb 13, 2025
 *      Author: 17205
 */

/* Includes */
#include "Button_Driver.h"

//Button_S = 0;

/* Function */

/* Initializes the Button */
void Button_Init(void){
	GPIO_InitTypeDef BUTTON_PC;
	BUTTON_PC.Pin = GPIO_PIN_0;
	BUTTON_PC.Mode = GPIO_MODE_INPUT;
	BUTTON_PC.Pull = GPIO_NOPULL;
	BUTTON_PC.Speed = GPIO_SPEED_FREQ_HIGH;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	HAL_GPIO_Init(GPIOA, &BUTTON_PC);
}

/* Returns the state of the button */
uint8_t Button_State(void){
	uint8_t IP_VAL = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	if(IP_VAL == SET){
		return true;
	}
	else{
		return false;
	}
}

/* Initializes The Button for Interrupts */
void Button_IRQ_Init(void){
	GPIO_InitTypeDef BUTTON_PC_IRQ;
	BUTTON_PC_IRQ.Pin = GPIO_PIN_0;
	BUTTON_PC_IRQ.Mode = GPIO_MODE_IT_FALLING;
	BUTTON_PC_IRQ.Pull = GPIO_NOPULL;
	BUTTON_PC_IRQ.Speed = GPIO_SPEED_FREQ_HIGH;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	HAL_GPIO_Init(GPIOA, &BUTTON_PC_IRQ);
	IRQ_Enable(EXTI0_IRQn);
}

/* update button state variable */
//void Button_Pressed(void){
//	 Button_S = 1;
//}

/* update button state variable */
//void Button_unPressed(void){
//	Button_S = 0;
//}

/* return button state */
//uint8_t Button_value(void){
//	return Button_S;
//}

