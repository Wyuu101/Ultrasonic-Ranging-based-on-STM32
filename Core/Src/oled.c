/*
 * oled.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Uu
 */


#include "oled.h"
#include "string.h"
#include "font.h"

#define OLED_ADDRESS 0x3C<<1 //从机地址00111100  01111000


void OLED_SendCmd(uint8_t cmd){
	uint8_t sendBuffer[2];
	sendBuffer[0]=0x00;
	sendBuffer[1]=cmd;
	HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, 2, HAL_MAX_DELAY);
}

void OLED_CheckOnline(){
	uint8_t command = 0x00;
	uint8_t response;
	HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, &command, 1, HAL_MAX_DELAY);
	HAL_Delay(1);
	if (HAL_I2C_Master_Receive(&hi2c1, OLED_ADDRESS, &response, 1, HAL_MAX_DELAY) != HAL_OK) {
		HAL_GPIO_WritePin(OLEDS_GPIO_Port, OLEDS_Pin, GPIO_PIN_SET);
		while(1){
			//如果OLED不在线，就阻塞主线程
			HAL_Delay(1000);
		}
	}
}


void OLED_Init(){
	HAL_Delay(200);
	//检测OLED是否在线
	OLED_CheckOnline();
	OLED_SendCmd(0xAE); //关闭显示器
	OLED_SendCmd(0xd5); //
	OLED_SendCmd(0x80); //设置时钟分频(1分频)和振荡器频率
	OLED_SendCmd(0xA8); //
	OLED_SendCmd(0x3F); //设置多路复用比例(64)
	OLED_SendCmd(0xD3); //
	OLED_SendCmd(0x00); //设置显示偏移(0)
	OLED_SendCmd(0x40); //设置起始线为(0)
	OLED_SendCmd(0x8D); //
	OLED_SendCmd(0x14); //启用电荷泵
	OLED_SendCmd(0x20); //
	OLED_SendCmd(0x02); //设置内存地址模式(页地址模式)
	OLED_SendCmd(0xB0); //设置起始页地址(0)
	OLED_SendCmd(0x00); //设置列地址低四位
	OLED_SendCmd(0x10); //设置列地址高四位
	OLED_SendCmd(0x81);
	OLED_SendCmd(0xff); //设置对比度
	OLED_SendCmd(0xc8); //设置输出扫描方向(映射模式)
	OLED_SendCmd(0xA7); //设置显示模式(正常显示)
	OLED_SendCmd(0xA1); //设置显示模式(正常显示)
	OLED_SendCmd(0xdb); //
	OLED_SendCmd(0x20); //设置VCOM电压(0.77xVcc)
	OLED_SendCmd(0xd9); //
	OLED_SendCmd(0x22); //设置预充电周(默认)
	OLED_SendCmd(0xda);
	OLED_SendCmd(0x12); //设置引脚硬件配置(128*64)
	OLED_SendCmd(0xAF); //打开显示器
}



void OLED_ClearScreen(){
	uint8_t GRAM[8][128];
	memset(GRAM,0,sizeof(GRAM));
	uint8_t sendBuffer[129];
	sendBuffer[0]=0x40;
	uint8_t i;
	for(i=0;i<8;i++){
		OLED_SendCmd(0xb0+i);
		OLED_SendCmd(0x00); // 设置列地址低四位
		OLED_SendCmd(0x10); // 设置列地址高四位
		memcpy(&sendBuffer[1],GRAM,128);
		HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
	}
}

void OLED_ShowDistance_Text(){
	uint8_t sendBuffer[129];
	memset(sendBuffer,0,sizeof(sendBuffer));
	sendBuffer[0]=0x40;
	uint8_t i,j;
	for(i=0;i<2;i++){
		OLED_SendCmd(0xb0+i);
		OLED_SendCmd(0x00); // 设置列地址低四位
		OLED_SendCmd(0x10); // 设置列地址高四位
		for(j=0;j<8;j++){
			if(i==0){
				memcpy(&sendBuffer[1+j*16],&distance_16x16[j][0],16);
			}
			else{
				memcpy(&sendBuffer[1+j*16],&distance_16x16[j][16],16);
			}
		}
		HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
	}
}

void OLED_ShowTemperature_Text(){
	uint8_t sendBuffer[129];
		memset(sendBuffer,0,sizeof(sendBuffer));
		sendBuffer[0]=0x40;
		uint8_t i,j;
		for(i=0;i<2;i++){
			OLED_SendCmd(0xb3+i);
			OLED_SendCmd(0x00); // 设置列地址低四位
			OLED_SendCmd(0x10); // 设置列地址高四位
			for(j=0;j<7;j++){
				if(i==0){
					memcpy(&sendBuffer[1+j*16],&temperature_16x16[j][0],16);
				}
				else{
					memcpy(&sendBuffer[1+j*16],&temperature_16x16[j][16],16);
				}
			}
			HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
		}
}

void OLED_SoundSpeed_Text(){
	uint8_t sendBuffer[129];
	memset(sendBuffer,0,sizeof(sendBuffer));
	sendBuffer[0]=0x40;
	uint8_t i,j;
	for(i=0;i<2;i++){
		OLED_SendCmd(0xb6+i);
		OLED_SendCmd(0x00); // 设置列地址低四位
		OLED_SendCmd(0x10); // 设置列地址高四位
		for(j=0;j<3;j++){
			if(i==0){
				memcpy(&sendBuffer[1+j*16],&soundSpeed_16x16[j][0],16);
			}
			else{
				memcpy(&sendBuffer[1+j*16],&soundSpeed_16x16[j][16],16);
			}
		}
		HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
	}
}


void OLED_SoundSpeed_Unit(){
	uint8_t sendBuffer[37];
	memset(sendBuffer,0,sizeof(sendBuffer));
	sendBuffer[0]=0x40;
	uint8_t i,j;
	for(i=0;i<2;i++){
		OLED_SendCmd(0xb6+i);
		OLED_SendCmd(0x0A); // 设置列地址低四位
		OLED_SendCmd(0x15); // 设置列地址高四位
		for(j=0;j<3;j++){
			if(i==0){
				memcpy(&sendBuffer[1+j*12],&soundSpeed_unit_12x12[j][0],12);
			}
			else{
				memcpy(&sendBuffer[1+j*12],&soundSpeed_unit_12x12[j][12],12);
			}
		}
		HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
	}
}


void OLED_ShowTemperature(uint8_t* dataString){
	uint8_t i,j;
	int temp[6];
	for (i =0 ;i<6;i++){
		temp[i] =dataString[i]-'0';
	}
	uint8_t sendBuffer[49];
	memset(sendBuffer,0,sizeof(sendBuffer));
	sendBuffer[0]=0x40;
	for(i=0;i<2;i++){
		OLED_SendCmd(0xb3+i);
		OLED_SendCmd(0x00); // 设置列地址低四位
		OLED_SendCmd(0x13); // 设置列地址高四位
		for(j=0;j<6;j++){
			int index;
			if(temp[j]>=0){
				index = temp[j];
			}
			else{
				index = 10;
			}
			if(i==0){
				memcpy(&sendBuffer[1+j*8],&numbers_16x8[index][0],8);
			}
			else{
				memcpy(&sendBuffer[1+j*8],&numbers_16x8[index][8],8);
			}
		}
		HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
	}
}

void OLED_ShowSoundSpeed(uint8_t* dataString){
	uint8_t i,j;
	int temp[5];
	for (i =0 ;i<5;i++){
		temp[i] =dataString[i]-'0';
	}
	uint8_t sendBuffer[41];
	memset(sendBuffer,0,sizeof(sendBuffer));
	sendBuffer[0]=0x40;
	for(i=0;i<2;i++){
		OLED_SendCmd(0xb6+i);
		OLED_SendCmd(0x00); // 设置列地址低四位
		OLED_SendCmd(0x13); // 设置列地址高四位
		for(j=0;j<5;j++){
			int index;
			if(temp[j]>=0){
				index = temp[j];
			}
			else{
				index = 10;
			}
			if(i==0){
				memcpy(&sendBuffer[1+j*8],&numbers_16x8[index][0],8);
			}
			else{
				memcpy(&sendBuffer[1+j*8],&numbers_16x8[index][8],8);
			}
		}
		HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
	}
}

void OLED_ShowDistance(uint8_t* dataString){
	uint8_t i,j;
		int temp[6];
		for (i =0 ;i<6;i++){
			temp[i] =dataString[i]-'0';
		}
		uint8_t sendBuffer[49];
		memset(sendBuffer,0,sizeof(sendBuffer));
		sendBuffer[0]=0x40;
		for(i=0;i<2;i++){
			OLED_SendCmd(0xb0+i);
			OLED_SendCmd(0x00); // 设置列地址低四位
			OLED_SendCmd(0x13); // 设置列地址高四位
			for(j=0;j<6;j++){
				int index;
				if(temp[j]>=0){
					index = temp[j];
				}
				else{
					index = 10;
				}
				if(i==0){
					memcpy(&sendBuffer[1+j*8],&numbers_16x8[index][0],8);
				}
				else{
					memcpy(&sendBuffer[1+j*8],&numbers_16x8[index][8],8);
				}
			}
			HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
		}
}


void OLED_ShowDistance_SoFar(){
	uint8_t sendBuffer[49];
		memset(sendBuffer,0,sizeof(sendBuffer));
		sendBuffer[0]=0x40;
		uint8_t i,j;
		for(i=0;i<2;i++){
			OLED_SendCmd(0xb0+i);
			OLED_SendCmd(0x00); // 设置列地址低四位
			OLED_SendCmd(0x13); // 设置列地址高四位
			for(j=0;j<6;j++){
				if(i==0){
					memcpy(&sendBuffer[1+j*8],&distance_sofar_16x8[j][0],8);
				}
				else{
					memcpy(&sendBuffer[1+j*8],&distance_sofar_16x8[j][8],8);
				}
			}
			HAL_I2C_Master_Transmit(&hi2c1, OLED_ADDRESS, sendBuffer, sizeof(sendBuffer), HAL_MAX_DELAY);
		}
}
