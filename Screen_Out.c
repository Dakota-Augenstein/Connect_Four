/*
 * Screen_Out.c
 *
 *  Created on: Apr 24, 2025
 *      Author: 17205
 */

/* Includes */
#include "Screen_Out.h"

/* Function */

/* screen one output */
void Screen_One(void){
	LCD_Clear(0, LCD_COLOR_WHITE);
	LCD_Draw_Vertical_Line(120,0,320,LCD_COLOR_BLACK);
	LCD_DisplayChar(45,140,'1');
	LCD_DisplayChar(60,140,'P');
	LCD_DisplayChar(165,140,'2');
	LCD_DisplayChar(180,140,'P');
}

/* screen two 1P output */
void Screen_Two_1P(void){
	LCD_Clear(0, LCD_COLOR_WHITE);
	LCD_Draw_Vertical_Line(15,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(45,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(75,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(105,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(135,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(165,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(195,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(225,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,140,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,170,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,200,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,230,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,260,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,290,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,320,210,LCD_COLOR_BLACK);
	LCD_DisplayChar(5,20,'1');
	LCD_DisplayChar(20,20,'P');
	LCD_DisplayChar(205,20,'2');
	LCD_DisplayChar(220,20,'P');
	LCD_Draw_Circle_Fill(50, 20, 10, LCD_COLOR_BLACK);
	LCD_Draw_Circle_Fill(190, 20, 10, LCD_COLOR_RED);
	//LCD_Draw_Circle_Fill(120, 125, 10, LCD_COLOR_BLACK);
}

/* screen two 2P output */
void Screen_Two_2P(void){
	LCD_Clear(0, LCD_COLOR_WHITE);
	LCD_Draw_Vertical_Line(15,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(45,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(75,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(105,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(135,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(165,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(195,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Vertical_Line(225,140,180,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,140,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,170,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,200,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,230,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,260,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,290,210,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(15,320,210,LCD_COLOR_BLACK);
	LCD_DisplayChar(5,20,'1');
	LCD_DisplayChar(20,20,'P');
	LCD_DisplayChar(205,20,'2');
	LCD_DisplayChar(220,20,'P');
	LCD_Draw_Circle_Fill(50, 20, 10, LCD_COLOR_BLACK);
	LCD_Draw_Circle_Fill(190, 20, 10, LCD_COLOR_RED);
	//LCD_Draw_Circle_Fill(120, 125, 10, LCD_COLOR_RED);
}

/* screen one output */
void Screen_Three(void){
	LCD_Clear(0, LCD_COLOR_WHITE);
	LCD_Draw_Vertical_Line(120,0,320,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(0,110,120,LCD_COLOR_BLACK);
	LCD_Draw_Horizontal_Line(0,210,120,LCD_COLOR_BLACK);
	LCD_DisplayChar(155,160,'R');
	LCD_DisplayChar(170,160,'S');
	LCD_DisplayChar(185,160,'T');
	LCD_DisplayChar(40,25,'1');
	LCD_DisplayChar(55,25,'P');
	LCD_DisplayChar(40,55, P1_Score+48);
	LCD_DisplayChar(40,125,'2');
	LCD_DisplayChar(55,125,'P');
	LCD_DisplayChar(40, 155, P2_Score+48);
	LCD_DisplayChar(25,225,'T');
	LCD_DisplayChar(40,225,'I');
	LCD_DisplayChar(55,225,'M');
	LCD_DisplayChar(70,225,'E');
	LCD_DisplayChar(25,245,'(');
	LCD_DisplayChar(40,245,'S');
	LCD_DisplayChar(55,245,')');
}

/* Update screen with new token */
void Play_Area_Update(void){
	for (int i = NA; i < ROWS; i++) {
	        for (int j = NA; j < COLUMNS; j++) {
	            if(Board_Data[i][j] == P1){
	            	LCD_Draw_Circle_Fill((30 + (30*j)), (155 +(30*i)), 10, LCD_COLOR_BLACK);
	            }
	            if(Board_Data[i][j] == P2){
	            	LCD_Draw_Circle_Fill((30 + (30*j)), (155 +(30*i)), 10, LCD_COLOR_RED);
	            }
	            if(Board_Data[i][j] == NA){
					LCD_Draw_Circle_Fill((30 + (30*j)), (155 +(30*i)), 10, LCD_COLOR_WHITE);
				}
	        }
	}
}

/* Print and update col value for token to be placed */
uint8_t Peice_To_Be(uint8_t col, uint8_t direction, uint8_t player){
	if(direction == NA){
		LCD_Draw_Circle_Fill((30 + (30 * col)), 125, 10, LCD_COLOR_WHITE);
		switch (player) {
		case P1:
			LCD_Draw_Circle_Fill((30 + (30*col)), 125, 10, LCD_COLOR_BLACK);
			break;
		case P2:
			LCD_Draw_Circle_Fill((30 + (30*col)), 125, 10, LCD_COLOR_RED);
			break;
		break;
		}
		return col;
	}
	if(direction == L){
		LCD_Draw_Circle_Fill((30 + (30 * col)), 125, 10, LCD_COLOR_WHITE);
		if(col != COL0)
		col--;
		switch (player) {
		case P1:
			LCD_Draw_Circle_Fill((30 + (30*col)), 125, 10, LCD_COLOR_BLACK);
			break;
		case P2:
			LCD_Draw_Circle_Fill((30 + (30*col)), 125, 10, LCD_COLOR_RED);
			break;
		break;
		}
		return col;
	}
	if(direction == R){
		LCD_Draw_Circle_Fill((30 + (30 * col)), 125, 10, LCD_COLOR_WHITE);
		if(col != COL6)
		col++;
		switch (player) {
		case P1:
			LCD_Draw_Circle_Fill((30 + (30*col)), 125, 10, LCD_COLOR_BLACK);
			break;
		case P2:
			LCD_Draw_Circle_Fill((30 + (30*col)), 125, 10, LCD_COLOR_RED);
			break;
		break;
		}
		return col;
	}
	return col;
}

/*clear last placed peice from above */
void Clear_Circle(uint8_t col){
	LCD_Draw_Circle_Fill((30 + (30 * col)), 125, 10, LCD_COLOR_WHITE);
}
