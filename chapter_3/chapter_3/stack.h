/*
	Author: Eajack Lau
	Date: 2019/4/5
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		栈, int型，和单链表基本一致，指针实现
*/
#include <iostream>
#include <limits.h>

#ifndef STACK
#define STACK

// 1- 栈声明
struct node;
typedef struct node *ptrToNode;	// ptrToNode，指代所有node
typedef ptrToNode Stack;	//linkedList，特指表头，指向栈顶

int isEmptyStack(Stack S);
Stack produceEmptyStack();
Stack produceStack(const int A[], int N);
void push(int x, Stack S);
void pop(Stack S);
int top(Stack S);
void deleteStack(Stack S);
void printStack(Stack S);



#endif
