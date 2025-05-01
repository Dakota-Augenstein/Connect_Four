/*
 * Connect_Four.c
 *
 *  Created on: Apr 23, 2025
 *      Author: 17205
 */

/* Includes */
#include "Connect_Four.h"

//static uint8_t Board_Data[6][7];
volatile uint8_t Board_Data[6][7];
RNG_HandleTypeDef hrng;
volatile uint8_t P1_Score = 0;
volatile uint8_t P2_Score = 0;
/* Function_prototypes */

/* Random number generation */
uint8_t RNG_Pos(void){
	uint32_t rand_num;
	//
	//RNG_HandleTypeDef hrng1;
	//hrng1.Instance = RNG;
	//
	HAL_RNG_GenerateRandomNumber(&hrng, &rand_num);
	uint8_t Position = (rand_num % RNG_REMAINDER_VALUE);
	return Position;
}

/* Win check */
uint8_t Win_Check(void){
	int directions[4][2] = {
			{0, 1}, //Horiz
			{1, 0}, //Vert
			{1, 1}, //Diag D-R
			{1, -1} //Diag D-L
	};
	//check for connect four
	for(int i = NA; i < ROWS; i++){
		for(int j = NA; j < COLUMNS; j++){  //check whole array
			int Player_Check = Board_Data[i][j]; // sets player currently being checked
			if (Player_Check == NA){
				continue; // skip if no player coin
			}
				for(int d = NA; d < FOUR_IN_A_ROW; d++){ // determine direction we are checking
					int d_x = directions[d][COL0]; //set x direction currently checking
					int d_y = directions[d][COL1]; //set y direction currently checking
					int count = 1; // count variable
					for(int k = NA; k < FOUR_IN_A_ROW; k++){
						int row = i + d_x * k;
						int col = j + d_y * k;
						if(row < 0 || row >= ROWS || col < 0 || col >= COLUMNS)
							break; // check if our check is checking out of bounds data
						if(Board_Data[row][col] != Player_Check)
							break; // check if next spot is not the player and end if so
						count++; //increase count as checked spot must be in a row
					}
						if (count == 5)
							return Player_Check;

				}
		}
	}
	// check for board filled
	for(int I = NA; I < ROWS; I++){
		for(int J = NA; J < COLUMNS; J++){
			if(Board_Data[I][J] == NA){
				return NA;
			}
		}
	}
	return TIE;
}

/* Game_Timer_Start */
void Game_Timer_Start(void){
 //call to timer function to start timer
}

/* Game_Timer_Stop*/
void Game_Timer_End(void){
 //call to timer function to stop timer
}

/* update matrix to 0 */
void Game_Data_Init(void){
	for (int i = NA; i < ROWS; i++) {
	        for (int j = NA; j < COLUMNS; j++) {
	            Board_Data[i][j] = NA;
	        }
	}
}

/* Update Game Data */
uint8_t Update_Game_Data(uint8_t Col, uint8_t Player){
	if (Board_Data[ROW5][Col] == NA){
		Board_Data[ROW5][Col] = Player;
		return NA;
	}
	if (Board_Data[ROW4][Col] == NA){
		Board_Data[ROW4][Col] = Player;
		return NA;
	}
	if (Board_Data[ROW3][Col] == NA){
		Board_Data[ROW3][Col] = Player;
		return NA;
	}
	if (Board_Data[ROW2][Col] == NA){
		Board_Data[ROW2][Col] = Player;
		return NA;
	}
	if (Board_Data[ROW1][Col] == NA){
		Board_Data[ROW1][Col] = Player;
		return NA;
	}
	if (Board_Data[ROW0][Col] == NA){
		Board_Data[ROW0][Col] = Player;
		return NA;
	}
	return COL_FULL;
}

/* return Board data */
//uint8_t Return_Game_Data(void){
//	uint8_t (*Board_Data_ptr)[7] = Board_Data;
//	return (*Board_Data_ptr)[7];
//}






