/*
 * burst.c
 *
 *  Created on: Oct 18, 2024
 *      Author: Uu
 */

#include "burst.h"
int burst_rounds = BURST_ROUNDS_BASE;


void Burst_Signal(){
	if(fabs((distance - distance_lastTime))>=THRE_DISTANCE_DIFF){
		//如果距离变化速度过快，复位发射的脉冲轮数
		burst_rounds = BURST_ROUNDS_BASE;
	}else{
		//如果距离变化较慢，可以判定为连续变化，则遵循预定算法。
		if(distance>=1100){
			//如果收不到回声，就复位发射轮数
			burst_rounds = BURST_ROUNDS_BASE;
		}
		else if(distance<=THRE_TINY){
			//如果距离小于微距离阈值，就把发射轮数设置为对应轮数
			burst_rounds = BURST_ROUNDS_TINY;
		}
		else{
			//其他距离下就根据乘性因子设置发射轮数
			burst_rounds = BURST_ROUNDS_BASE+ (int)( distance*FACTOR+0.5);
		}
	}

	int i;
	launch_time=__HAL_TIM_GET_COUNTER(&htim4);//发射信号时获取TIM4当前的计数值
	for(i=0;i<burst_rounds*2;i++){
		HAL_GPIO_TogglePin(BURST_GPIO_Port, BURST_Pin);
		HAL_GPIO_TogglePin(BURSTN_GPIO_Port, BURSTN_Pin);
		Delay_us(BURST_FREQUENCY);
	}
}
