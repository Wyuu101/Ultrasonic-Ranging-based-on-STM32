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


void Beep(){
	if(distance>=100){
		HAL_TIM_Base_Stop_IT(&htim1);
	}
	if(distance >=90&& distance <100){
		beep_interval_rounds_tre=500;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=80&& distance <90){
		beep_interval_rounds_tre=250;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=70&& distance <80){
		beep_interval_rounds_tre=167;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=60&& distance <70){
		beep_interval_rounds_tre=125;
	    HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=55&& distance <60){
		beep_interval_rounds_tre=100;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=50&& distance <55){
		beep_interval_rounds_tre=83;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=45&& distance <50){
		beep_interval_rounds_tre=71;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance >=40&& distance <45){
		beep_interval_rounds_tre=62;
		HAL_TIM_Base_Start_IT(&htim1);
	}
	else if(distance <40){
		beep_interval_rounds_tre=1;
		HAL_TIM_Base_Start_IT(&htim1);
	}

}
