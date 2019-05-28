/*
	Author: Eajack Lau
	Date: 2019/4/17
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		队列
*/

#include <iostream>
#include <limits.h>
#include "linkedList.h"
using namespace std;

#ifndef MYQUEUE
#define MYQUEUE

//
int isEmpty_queue(queue_header Q);
int isFull_queue(queue_header Q);
queue_header createEmptyQueue();
void deleteQueue(queue_header Q);
void enqueue(int x, queue_header Q);
int dequeue(queue_header Q);
queue_header createQueue(const int A[], int N);
void print_queue(queue_header Q);

#endif