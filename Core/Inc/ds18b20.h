/*
 * ds18b20.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Uu
 */

#ifndef INC_DS18B20_H_
#define INC_DS18B20_H_

#include "gpio.h"
GPIO_PinState DS18B20_Init();
void DS18B20_WriteData(uint8_t data);
uint8_t DS18B20_ReadData();
void DS18B20_ReadTemperature();

extern uint32_t ds18b20_startTime;
extern char temperature_msg[20];
extern char soundSpeed_msg[20];
extern float temperature;
extern float soundSpeed;
extern int ds18b20_online;

#endif /* INC_DS18B20_H_ */
