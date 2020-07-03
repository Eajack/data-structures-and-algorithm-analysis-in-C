/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		队列类实现
*/
#include <iostream>
#include "queueEL.h"
using namespace std;


Queue::Queue()
{
	queueFront = nullptr;
	queueBack = nullptr;
}

Queue::Queue(int val)
{
	queueFront = new QueueNode(val);
	queueBack = queueFront;
}

Queue::~Queue()
{
}

bool Queue::empty()
{
	return queueFront == nullptr && queueBack == nullptr;
}

int Queue::size()
{
	QueueNode* node = queueFront;
	int len = 0;
	while (node != queueBack) {
		len++;
	}

	return len;
}

void Queue::enqueue(int x)
{
	if (empty()) {
		QueueNode* node = new QueueNode(x);
		queueFront = node;
		queueBack = node;
	}
	else {
		queueBack->next = new QueueNode(x);
		queueBack = queueBack->next;
	}
}

int Queue::dequeue()
{
	if (empty()) {
		return INT_MIN;
	}
	else {
		QueueNode* node = queueFront;
		int ans = queueFront->val;
		if (queueFront == queueBack) {
			queueFront = nullptr;
			queueBack = nullptr;
		}
		else {
			queueFront = queueFront->next;
		}
		delete node;
		return ans;
	}
}

void Queue::clear()
{
	while (!empty()) {
		int trash = dequeue();
	}
}

void Queue::print()
{
	QueueNode* node = queueFront;
	while (node) {
		cout << node->val << "\t";
		node = node->next;
	}
}
