/*
 * distanceProc.h
 *
 *  Created on: Oct 22, 2024
 *      Author: Uu
 */

#ifndef INC_DISTANCEPROC_H_
#define INC_DISTANCEPROC_H_

//探头间隔,单位(cm)
#define PROBE_DISTANCE 5
#include "ds18b20.h"
#include "tim.h"
#include "math.h"
#include "queue.h"
#include "stdlib.h"

extern int timeout;
extern int success;
extern float distance;
//extern float distance_lastTime;
extern char distance_msg[20];
extern struct Queue globalQueue;
extern int count_toofar;
extern uint32_t launch_time;//发射时间
extern uint32_t receive_time;//接收时间
void Distance_Caculate();
#endif /* INC_DISTANCEPROC_H_ */
