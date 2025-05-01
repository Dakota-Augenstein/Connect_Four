/*
 * Button_Driver.h
 *
 *  Created on: Feb 13, 2025
 *      Author: 17205
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

/* Includes */
//#include "GPIO_Driver.h"
//#include "stm32f4xx_hal.h"
#include "interruptControl.h"
//#include "ErrorHandling.h" // inclued herre and gyro.h where the inclusion is explained

//uint8_t Button_S;

/* Define */
#define USER_BUTTON_PORT      0x40020000
#define USER_BUTTON_PIN       0
#define USER_BUTTON_PRESSED   1
#define USER_BUTTON_UNPRESSED 0
#define true                  1
#define false                 0

//typedef enum {false, true} bool;

/* Function_prototypes */

/* Initializes the Button for Polling */
void Button_Init(void);

/* Returns the state of the button */
uint8_t Button_State(void);

/* Initializes The Button for Interrupts */
void Button_IRQ_Init(void);

/* update button state variable */
//void Button_Pressed(void);

/* update button state variable */
//void Button_unPressed(void);

/* return button state */
//uint8_t Button_value(void);


#endif /* BUTTON_DRIVER_H_ */
