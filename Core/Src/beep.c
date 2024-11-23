/*
 * beep.c
 *
 *  Created on: Oct 22, 2024
 *      Author: Uu
 */

#include "beep.h"

//蜂鸣器脉冲频率
int beep_rounds =0;
//蜂鸣器频率-实时轮数
int beep_interval_rounds=0;
//蜂鸣器频率-阈值轮数
int beep_interval_rounds_tre;
//距离过近标志位
int beep_too_close=0;

void Beep(){
	if(distance>=100){
		beep_too_close=0;
		HAL_TIM_Base_Stop_IT(&htim1);
	}
	else if(distance >=90&& distance <100){
		beep_too_close=0;
		beep_interval_rounds_tre=250;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=80&& distance <90){
		beep_too_close=0;
		beep_interval_rounds_tre=125;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=70&& distance <80){
		beep_too_close=0;
		beep_interval_rounds_tre=83;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=60&& distance <70){
		beep_too_close=0;
		beep_interval_rounds_tre=63;
	    HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=55&& distance <60){
		beep_too_close=0;
		beep_interval_rounds_tre=50;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=50&& distance <55){
		beep_too_close=0;
		beep_interval_rounds_tre=42;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=45&& distance <50){
		beep_too_close=0;
		beep_interval_rounds_tre=36;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=40&& distance <45){
		beep_too_close=0;
		beep_interval_rounds_tre=31;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance <40){
		beep_too_close=1;
		//设置为长鸣
		__HAL_TIM_SET_AUTORELOAD(&htim1,BEEP_FREQUENCY_AUTORELOAD);
		beep_interval_rounds_tre=1;
		HAL_TIM_Base_Start_IT(&htim1);
	}

}
