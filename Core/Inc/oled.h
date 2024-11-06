/*
 * oled.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Uu
 */

#ifndef INC_OLED_H_
#define INC_OLED_H_

#include "i2c.h"
void OLED_SendCmd(uint8_t cmd);
void OLED_ClearScreen();
void OLED_Init();
void OLED_ShowDistance_Text();
void OLED_ShowTemperature_Text();
void OLED_SoundSpeed_Text();
void OLED_SoundSpeed_Unit();
void OLED_ShowTemperature(uint8_t* dataString);
void OLED_ShowSoundSpeed(uint8_t* dataString);
void OLED_ShowDistance(uint8_t* dataString);
void OLED_ShowDistance_SoFar();
#endif /* INC_OLED_H_ */
