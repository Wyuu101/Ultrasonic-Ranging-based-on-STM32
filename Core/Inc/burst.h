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

#define THRE_TINY 8
#define THRE_DISTANCE_DIFF 10
#define BURST_ROUNDS_TINY 4
#define BURST_ROUNDS_BASE 8
#define FACTOR 0.06
#define BURST_FREQUENCY 11 //每组猝发信号的高低电平反转间隔 us
extern int burst_rounds;
void Burst_Signal();

#endif /* INC_BURST_H_ */
