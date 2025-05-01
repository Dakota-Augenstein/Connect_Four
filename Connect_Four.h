/*
 * Connect_Four.h
 *
 *  Created on: Apr 23, 2025
 *      Author: 17205
 */

#ifndef INC_CONNECT_FOUR_H_
#define INC_CONNECT_FOUR_H_

/* Includes */
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

/* Define */
#define COL_FULL            1
#define TIE					3
#define P1					1
#define P2					2
#define NA                  0
#define RNG_OFFSET_VALUE    1
#define RNG_REMAINDER_VALUE 7
#define ROWS				6
#define COLUMNS				7
#define ROW0				0
#define ROW1				1
#define ROW2				2
#define ROW3				3
#define ROW4				4
#define ROW5				5
#define FOUR_IN_A_ROW       4
#define COL0				0
#define COL1				1
#define COL2				2
#define COL3				3
#define COL4				4
#define COL5				5
#define COL6                6
#define L					1
#define R 					2

extern volatile uint8_t Board_Data[6][7];
extern RNG_HandleTypeDef hrng;
extern volatile uint8_t P1_Score;
extern volatile uint8_t P2_Score;
/* Function_prototypes */

/* Random number generation */
uint8_t RNG_Pos(void);

/* Win check */
uint8_t Win_Check(void);

/* Game_Timer_Start */
void Game_Timer_Start(void);

/* Game_Timer_Stop*/
void Game_Timer_End(void);

/* update matrix to 0 */
void Game_Data_Init(void);

/* Update Game Data */
uint8_t Update_Game_Data(uint8_t, uint8_t);

/* return Board data */
//uint8_t Return_Game_Data(void);

#endif /* INC_CONNECT_FOUR_H_ */
