/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		栈类实现
*/

#pragma once

#include "ListEL.h"

class Stack
{
public:
	Stack();
	Stack(int val);
	~Stack();

	//1- 获取size，O(1)
	int size();
	//2- 判断空，O(1)
	bool empty();
	//3- push，O(1)
	void push(int x);
	//4- pop，O(N)
	void pop();
	//5- top，O(N)
	int top();
	//6- 清空，O(N)
	void clear();
	//7- 打印，O(N)
	void print();

private:
	StackNode * stackBottom;
	StackNode * stackTop;
};