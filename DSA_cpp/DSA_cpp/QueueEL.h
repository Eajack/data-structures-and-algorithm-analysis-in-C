/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		队列类实现
*/

#pragma once
#include "ListEL.h"

class Queue
{
public:
	Queue();
	Queue(int val);
	~Queue();

	//1 判断是否空，O(1)
	bool empty();
	//2 获取队列size，O(1)
	int size();
	//3 尾部入队，O(1)
	void enqueue(int x);
	//4 头部出队，O(1)
	int dequeue();
	//5 清空，O(N)
	void clear();
	//6 打印，O(N)
	void print();

private:
	// 头尾指针同时维护
	QueueNode * queueFront;
	QueueNode* queueBack;
};


