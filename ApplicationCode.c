/*
 * ApplicationCode.c
 *
 *  Created on: Dec 30, 2023 (updated 11/12/2024) Thanks Donavon! 
 *      Author: Xavion
 */

#include "ApplicationCode.h"

/* Static variables */
uint8_t Button_S = 0;

extern void initialise_monitor_handles(void); 

#if COMPILE_TOUCH_FUNCTIONS == 1
static STMPE811_TouchData StaticTouchData;
#endif // COMPILE_TOUCH_FUNCTIONS

void ApplicationInit(void)
{
	initialise_monitor_handles(); // Allows printf functionality
	ButtonIInit();
    LTCD__Init();
    LTCD_Layer_Init(0);
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);
	InitializeLCDTouch();

}

void LCD_Visual_Demo(void)
{
	visualDemo();
}

#if COMPILE_TOUCH_FUNCTIONS == 1
void LCD_Touch_Polling_Demo(void)
{
	LCD_Clear(0,LCD_COLOR_GREEN);
	while (1) {
		/* If touch pressed */
		if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {
			/* Touch valid */
			printf("\nX: %03d\nY: %03d\n", StaticTouchData.x, StaticTouchData.y);
			LCD_Clear(0, LCD_COLOR_RED);
		} else {
			/* Touch not pressed */
			printf("Not Pressed\n\n");
			LCD_Clear(0, LCD_COLOR_GREEN);
		}
	}
}
#endif // COMPILE_TOUCH_FUNCTIONS

/* Returns weather the left = 0 or right = 1 is pressed */
uint8_t LCD_Left_Right_Polling_Loop(void){
	while(1){
		if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {
			if (StaticTouchData.x <= HALF_X_RANGE){
				return RIGHT;
			}
			else{
				return LEFT;
			}
		}
	}


}

/* Returns weather the left = 0 or right = 1 is pressed */
uint8_t LCD_Left_Right_Polling(void){
	if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {
				if (StaticTouchData.x <= HALF_X_RANGE){
					return RIGHT;
				}
				else{
					return LEFT;
				}
	}
	return NA;

}

void ButtonIInit(void){
	Button_IRQ_Init();
}

void EXTI0_IRQHandler(void){
	IRQ_Disable(EXTI0_IRQn);

	//Button_Pressed();
	Button_S++;

	IRQ_Clear_Bit(EXTI0_IRQn);
	IRQ_Enable(EXTI0_IRQn);
}


