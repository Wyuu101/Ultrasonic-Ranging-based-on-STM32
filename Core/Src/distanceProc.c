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
//float distance_lastTime = 0;//用于缓存上一次循环测得的距离
char distance_msg[20];//用于写入oled显示屏的字段
struct Queue globalQueue;//用于平滑处理的全局队列
int count_abnormal =0;//距离异常统计次数
int count_toofar=0;//距离过远统计次数
uint32_t launch_time;//发射时间
uint32_t receive_time;//接收时间




void Distance_Caculate(){
	//读取TIM4的输入捕获寄存器,即回声接收时瞬间
	  receive_time = HAL_TIM_ReadCapturedValue(&htim4, TIM_CHANNEL_1);
	  //计算耗时(差值*分辨率1us)
	  float pulseWidth = (receive_time - launch_time)*0.000001;
//	  //缓存上次的距离
//	  distance_lastTime = distance;
//	  //计算距离

	  //近距离勾股定理误差修正
	  distance =sqrt( pow(pulseWidth * soundSpeed*100 /2,2)-pow(PROBE_DISTANCE/2,2)) ;
	  count_toofar=0;
	  if(isQueueEmpty(&globalQueue)){
		  enqueue(&globalQueue, distance);
		  return;
	  }
	  float average = queueAverage(&globalQueue);
//	  float average = getEMA(&globalQueue);
	  if(fabs(distance-average)>=5){
		  if(count_abnormal<3){
			  distance=average;
			  count_abnormal++;
			  return;
		  }
		  else{
			  clearQueue(&globalQueue);
//			  initQueue(&globalQueue);
			  enqueue(&globalQueue, distance);
			  count_abnormal=0;
		  }
	  }
	  enqueue(&globalQueue, distance);
	  distance = queueAverage(&globalQueue);
//	  distance = getEMA(&globalQueue);


	  //误差修正部分
	  float offset = 0.0;
	  if((distance-65)>=0&&(distance-65)<=120){
		  offset =- ((0.06)*(distance-65)-0.2);
		  if((distance-112)>=42&&(distance-65)<=53){
			  offset -= 0.8;
		  }
		  else if((distance-65)>=58 &&(distance-65)<=70){
			  offset -= 0.8;
		  }
		  else if((distance-65)>=95 &&(distance-65)<=103){
			  offset += 0.8;
		  }
	  }
	  else if((distance-65)>120){
		  offset = -6.5;
	  }

	  distance += offset;
	  count_abnormal=0;


//	  if(abs(distance-distance_lastTime)<=(1+0.005*distance)){
//		  distance=distance_lastTime;
//	  }

}
