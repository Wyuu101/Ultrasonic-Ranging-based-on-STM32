/*
 * delay.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Uu
 */
#include "delay.h"
void Delay_us(uint32_t us) {
    HAL_TIM_Base_Start(&htim2);
    __HAL_TIM_SET_COUNTER(&htim2, 0); // 重置计数器
	while (__HAL_TIM_GET_COUNTER(&htim2) < us); // 等待直到计数达到指定值
	HAL_TIM_Base_Stop(&htim2); // 停止定时器
}

