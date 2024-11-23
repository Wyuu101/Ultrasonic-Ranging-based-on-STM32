/*
 * queue.h
 *
 *  Created on: Nov 21, 2024
 *      Author: Uu
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_



#define MAX_QUEUE_SIZE 10  // 定义队列最大长度
// 队列结构体
struct Queue {
    float data[MAX_QUEUE_SIZE]; // 存储队列数据
    int front;  // 队列前端索引
    int rear;   // 队列后端索引
//    float ema;                   // 当前 EMA 值
//    float alpha;                 // 平滑系数
};
void initQueue(struct Queue* q);
int isQueueEmpty(struct Queue* q);
int isQueueFull(struct Queue* q);
int enqueue(struct Queue* q, float value);
//void enqueue(struct Queue* q, float value);

int dequeue(struct Queue* q);
void clearQueue(struct Queue* q);
int queueLength(struct Queue* q);
float queueAverage(struct Queue* q);
//float getEMA(struct Queue* q);
#endif /* INC_QUEUE_H_ */
