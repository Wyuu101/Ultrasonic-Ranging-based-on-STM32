/*
 * burst.h
 *
 *  Created on: Oct 18, 2024
 *      Author: Uu
 */

#ifndef INC_BURST_H_
#define INC_BURST_H_

#include "tim.h"
#include "delay.h"
#include "distanceProc.h"

//#define THRE_TINY 10
//#define THRE_DISTANCE_DIFF 8
//#define BURST_ROUNDS_TINY 4
#define BURST_ROUNDS_BASE 8	//基础脉冲数
//#define FACTOR 0.06		//动态脉冲数乘性因子
#define BURST_FREQUENCY 11 //每组猝发信号的高低电平反转间隔 us
extern int burst_rounds;	//实际脉冲发射计数值
void Burst_Signal();

#endif /* INC_BURST_H_ */
