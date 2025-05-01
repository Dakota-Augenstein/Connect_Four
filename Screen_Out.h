/*
 * Screen_Out.h
 *
 *  Created on: Apr 24, 2025
 *      Author: 17205
 */

#ifndef INC_SCREEN_OUT_H_
#define INC_SCREEN_OUT_H_

/* Includes */
#include "LCD_Driver.h"
#include "Connect_Four.h"

/* Define */

/* Function Prototypes */

/* screen one output */
void Screen_One(void);

/* screen two 1P output */
void Screen_Two_1P(void);

/* screen two 2P output */
void Screen_Two_2P(void);

/* screen one output */
void Screen_Three(void);

/* Update screen with new token */
void Play_Area_Update();

/* Print and update col value for token to be placed */
uint8_t Peice_To_Be(uint8_t, uint8_t, uint8_t);

/*clear last placed peice from above */
void Clear_Circle(uint8_t);

#endif /* INC_SCREEN_OUT_H_ */
