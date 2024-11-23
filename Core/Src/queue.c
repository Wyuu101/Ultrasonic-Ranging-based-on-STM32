/*
 * queue.c
 *
 *  Created on: Nov 21, 2024
 *      Author: Uu
 */


#include "queue.h"

// 初始化队列
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
//    q->ema = 0.0f;   // 初始 EMA 值
//    q->alpha = 0.1;  // 设置平滑系数
}

// 判断队列是否为空
int isQueueEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// 判断队列是否满
int isQueueFull(struct Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

 //入队操作
int enqueue(struct Queue* q, float value) {
    if (isQueueFull(q)) {
        // 出队一个元素
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }

    // 将新元素加入队列
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;  // 循环队列
    return 0;
}

// 出队操作
int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        return -1;
    }
    // 直接移除队头元素
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;  // 循环队列
    return 0;
}

// 清除队列
void clearQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// 计算队列长度
int queueLength(struct Queue* q) {
    return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// 计算队列内所有元素的平均值
float queueAverage(struct Queue* q) {
    if (isQueueEmpty(q)) {
        return 0.0f;
    }

    int sum = 0;
    int count = queueLength(q);
    int i = q->front;

    while (i != q->rear) {
        sum += q->data[i];
        i = (i + 1) % MAX_QUEUE_SIZE;
    }


    return (float)sum / count;
}

//// 入队操作
//void enqueue(struct Queue* q, float value) {
//    // 如果队列满了，移除队头元素
//    if (isQueueFull(q)) {
//        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
//    }
//
//    // 将新元素加入队列
//    q->data[q->rear] = value;
//    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
//
//    // 更新 EMA
//    if(q->ema!=0){
//    	q->ema = q->alpha * value + (1 - q->alpha) * q->ema;
//    }
//    else{
//    	q->ema = value;
//    }
//
//
//}

//// 计算队列的 EMA
//float getEMA(struct Queue* q) {
//    return q->ema;
//}

