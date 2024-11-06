/*
 * ds18b20.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Uu
 */


#include "ds18b20.h"
#include "delay.h"
#include "oled.h"
#include "stdio.h"

typedef enum {
    STATE_START,
    STATE_WAIT,
    STATE_READ,
	STATE_SHOW
} DS18B20_State;

DS18B20_State currentState = STATE_START;
uint32_t ds18b20_startTime = 0;
char temperature_msg[20];
char soundSpeed_msg[20];
float temperature;
float soundSpeed;
int ds18b20_online = 1;

GPIO_PinState DS18B20_Init(){
	HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_RESET);
	Delay_us(600);
	HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_SET);
	Delay_us(60);
	GPIO_PinState ack = HAL_GPIO_ReadPin(DS18B20_GPIO_Port, DS18B20_Pin);
	Delay_us(240);
	return ack;
}

void DS18B20_WriteData(uint8_t data){
	uint8_t mask=0x01;
	while(mask!=0x00){
		HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_RESET);
		Delay_us(2);
		if((mask & data) !=0x00){
			HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_SET);
		}
		else{
			HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_RESET);
		}
		Delay_us(60);
		mask=mask<<1;
		HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_SET);
	}
}


uint8_t DS18B20_ReadData(){
	uint8_t mask=0x01,data = 0x00;
	while(mask!=0x00){
		HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_RESET);
		Delay_us(2);
		HAL_GPIO_WritePin(DS18B20_GPIO_Port, DS18B20_Pin, GPIO_PIN_SET);
		Delay_us(2);
		if(HAL_GPIO_ReadPin(DS18B20_GPIO_Port, DS18B20_Pin)==GPIO_PIN_SET){
			data = data | mask;
		}
		else{
			data = data &(~mask);//读取到0
		}
		Delay_us(60);
		mask = mask<<1;
	}
	return data;
}

void DS18B20_ReadTemperature(){
	 switch (currentState) {
	        case STATE_START:
	        	if(DS18B20_Init()==GPIO_PIN_SET){
					HAL_GPIO_WritePin(DS18B20S_GPIO_Port, DS18B20S_Pin, GPIO_PIN_SET);
					ds18b20_online = 0 ;
				}
				DS18B20_WriteData(0xCC);
				DS18B20_WriteData(0x44);
				ds18b20_startTime = HAL_GetTick();
				currentState = STATE_WAIT;
				break;

	        case STATE_WAIT:
	        	//状态机编程
	        	if(HAL_GetTick()-ds18b20_startTime >=750){
	        		if(DS18B20_Init()==GPIO_PIN_SET){
	        			HAL_GPIO_WritePin(DS18B20S_GPIO_Port, DS18B20S_Pin, GPIO_PIN_SET);
						ds18b20_online = 0 ;
	        		}
					currentState = STATE_READ;
	        	}
	        	break;

	        case STATE_READ:
				DS18B20_WriteData(0xCC);
				DS18B20_WriteData(0xBE);
				uint8_t tempLow = DS18B20_ReadData();
				uint8_t tempHigh = DS18B20_ReadData();
				uint8_t sign = tempHigh & 0xF8;
				int res_proc = (int)(tempLow | (int)(tempHigh & 0x07)<< 8);
				temperature = res_proc*0.0625;
				if(sign!=0){
					temperature= -temperature;
				}
				soundSpeed = 331.4+temperature*0.6;
				currentState = STATE_SHOW;
				break;

	        case STATE_SHOW:
				sprintf(temperature_msg,"%.3f\n",temperature);
				sprintf(soundSpeed_msg,"%.3f\n",soundSpeed);
				OLED_ShowTemperature((uint8_t*)temperature_msg);
				OLED_ShowSoundSpeed((uint8_t*)soundSpeed_msg);
				currentState = STATE_START;
				break;
	 }
}


