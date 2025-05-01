/*
 * ApplicationCode.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Xavion
 */

#include "LCD_Driver.h"
#include "Screen_Out.h"
#include "Button_Driver.h"
//#include "stm32f4xx_hal.h"

//#include <stdio.h>

/* Define */
#define NAME_LENGTH    6
#define DEF_VALUE      25000
#define HALF_X_RANGE   120
#define LEFT		   1
#define RIGHT          2
//#define NULL           0

extern uint8_t Button_S;
//extern uint8_t Button_S;
//uint8_t Board_Data[6][7];

#ifndef INC_APPLICATIONCODE_H_
#define INC_APPLICATIONCODE_H_

void ApplicationInit(void);
void LCD_Visual_Demo(void);

#if (COMPILE_TOUCH_FUNCTIONS == 1)
void LCD_Touch_Polling_Demo(void);
#endif // (COMPILE_TOUCH_FUNCTIONS == 1)

/* Returns weather the left = 0 or right = 1 is pressed */
uint8_t LCD_Left_Right_Polling_Loop(void);

/* Returns weather the left = 0 or right = 1 is pressed */
uint8_t LCD_Left_Right_Polling(void);

/* Executes a routine to enable the button for interrupts */
void ButtonIInit(void);

#endif /* INC_APPLICATIONCODE_H_ */
