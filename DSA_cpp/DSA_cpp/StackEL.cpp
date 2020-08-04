/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		’ª¿‡ µœ÷
*/

#include <iostream>
#include "StackEL.h"
using namespace std;


Stack::Stack()
{
	stackBottom = nullptr;
	stackTop = nullptr;
}

Stack::Stack(int val)
{
	stackBottom = new StackNode(val);
	stackTop = stackBottom;
}

Stack::~Stack()
{
}

int Stack::size()
{
	int len = 0;
	StackNode* node = stackBottom;
	while (node != stackTop) {
		len++;
		node = node->next;
	}
	return len;
}

bool Stack::empty()
{
	return stackTop == nullptr;
}

void Stack::push(int x)
{
	StackNode* node = new StackNode(x);
	stackTop->next = node;
	stackTop = stackTop->next;
}

void Stack::pop()
{
	if (empty()) {
		return;
	}
	StackNode* node = stackBottom;
	while (node->next != stackTop) {
		node = node->next;
	}
	delete stackTop;
	node->next = nullptr;
	stackTop = node;
}

int Stack::top()
{
	if (empty()) {
		return INT_MAX;
	}
	return stackTop->val;
}

void Stack::clear()
{
	StackNode* node = stackBottom;
	while (node) {
		StackNode* temp = node;
		node = node->next;
		delete temp;
	}
	stackBottom = nullptr;
	stackTop = nullptr;
}

void Stack::print()
{
	while (!empty()) {
		cout << top() << "\t";
		pop();
	}
	cout << endl;
}
