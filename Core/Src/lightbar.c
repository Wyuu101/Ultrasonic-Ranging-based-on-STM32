/*
 * lightbar.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Uu
 */


#include "lightbar.h"
#include "distanceProc.h"
int too_close=0;		//标志位,防止重复统一电平导致闪烁频率异常



void Change_LightBar(){
	if(distance>=100){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	if(distance >=90&& distance <100){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	else if(distance >=80&& distance <90){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	else if(distance >=70&& distance <80){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	else if(distance >=60&& distance <70){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	else if(distance >=55&& distance <60){
		//停止灯条闪烁
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim3);
	}
	else if(distance >=50&& distance <55){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	else if(distance >=45&& distance <50){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	else if(distance >=40&& distance <45){
		//停止灯条闪烁
		HAL_TIM_Base_Stop_IT(&htim3);
		too_close=0;
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	}
	else if(distance <40){
		//防止重复统一电平导致闪烁频率异常
		if(!too_close){
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_SET);
			too_close=1;
		}
		//启动TIM3用于4Hz闪烁灯条
		HAL_TIM_Base_Start_IT(&htim3);
	}
}

//亮灭灯条
void Toggle_LightBar(){
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
	HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
	HAL_GPIO_TogglePin(LED6_GPIO_Port, LED6_Pin);
	HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);
	HAL_GPIO_TogglePin(LED8_GPIO_Port, LED8_Pin);
	HAL_GPIO_TogglePin(LED9_GPIO_Port, LED9_Pin);
	HAL_GPIO_TogglePin(LED10_GPIO_Port, LED10_Pin);
}

