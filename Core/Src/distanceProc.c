/*
 * distanceProc.c
 *
 *  Created on: Oct 22, 2024
 *      Author: Uu
 */


#include "distanceProc.h"

int timeout = 0 ;//超时标志
int success =0; //测距成功标志
float distance= 1100; //距离，全局变量
float distance_lastTime = 0;//用于缓存上一次循环测得的距离
char distance_msg[20];//用于写入oled显示屏的字段
uint32_t launch_time;//发射时间
uint32_t receive_time;//接收时间
void Distance_Caculate(){
	//读取TIM4的CCR1寄存器,即回声接收时瞬间
	  receive_time = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
	  //计算耗时(差值*分辨率1us)
	  float pulseWidth = (receive_time - launch_time)*0.000001;
	  //缓存上次的距离
	  distance_lastTime = distance;
	  //计算距离
	  distance =sqrt( pow(pulseWidth * soundSpeed*100 /2,2)+pow(PROBE_DISTANCE,2)) ;
}
