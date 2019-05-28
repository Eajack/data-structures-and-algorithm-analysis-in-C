/*
	Author: Eajack Lau
	Date: 2019/4/5
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		栈, int型，和单链表基本一致，指针实现
		栈结构如下：
								   stack 				addr
		Stack S ------> |value = X(3), next = 2|      	 3
						|value = X(2), next = 1|		 2
						|value = X(1), next = 0|		 1
						|value = X(0), next = NULL|		 0

		S = |value = INT_MIN, next = 3|
*/

#include "stack.h"
using namespace std;

//1- Stack implementation
// pointer
struct node
{
	int value;
	ptrToNode next;
};

// test if S is |value = INT_MIN, next = NULL|
//O(1)
int isEmptyStack(Stack S)
{
	return (S->value == INT_MIN && S->next == NULL);
}

//produce empty stack, which is |value = INT_MIN, next = NULL|
//O(1)
Stack produceEmptyStack()
{
	ptrToNode tmpNode = (ptrToNode)malloc(sizeof(struct node));
	if (tmpNode == NULL)
	{
		cout << "produceEmptyStack ERROR: malloc out of space" << endl;
		return NULL;
	}
	tmpNode->value = INT_MIN;
	tmpNode->next = NULL;

	return tmpNode;
}

//produce Stack, return S
//O(N)
Stack produceStack(const int A[], int N)
{
	//1- 生成空表
	Stack header = produceEmptyStack();

	//2- 遍历数组，生成链表
	ptrToNode p_now = NULL;
	for (int i = 0; i < N; i++)
	{
		push(A[i], header);
	}

	return header;
}


//push x to S，meanwhile S = the addr of 'x'
// Attention: the addr of S is always the same, only S->next changes
//O(1)
void push(int x, Stack S)
{
	ptrToNode tmpNode = (ptrToNode)malloc(sizeof(struct node));
	if (tmpNode == NULL)
	{
		cout << "push ERROR: malloc out of space" << endl;
		return;
	}
	tmpNode->value = x;
	tmpNode->next = S->next;
	S->next = tmpNode;
}

//pop, return the top number, and change S ---> lastNode
// Attention: the addr of S is always the same, only S->next changes
//O(1)
void pop(Stack S)
{
	ptrToNode tmpNode;
	if( !isEmptyStack(S) )
	{
		//pop
		tmpNode = S->next;
		S->next = S->next->next;
		free(tmpNode);
	}
}

//top, get the top number
//O(1)
int top(Stack S)
{
	if( !isEmptyStack(S) )
		return S->next->value;
	else
	{
		cout << "top ERROR: Empty Stack" <<  endl;
		return INT_MIN;
	}
}

void deleteStack(Stack S)
{
	if( !isEmptyStack(S) )
	{
		while( !isEmptyStack(S) )
			pop(S);
	}
	else
	{
		cout << "deleteStack ERROR: Empty Stack" << endl;
	}
}

//print Stack
void printStack(Stack S)
{
	if (S->value != INT_MIN)
	{
		cout << "printStack EROOR: S's header ERROR" << endl;
		return;
	}

	ptrToNode p = S->next;
	cout << "++++++++++++++++++++++++++" << endl;
	cout << "printStack: " << endl;
	int stackCount = 1;
	while (p != NULL)	//注意，不用next，直接当前p判断
	{
		cout << stackCount << "-\tp->value: " << p->value << endl;
		cout << "\tp->next: " << p->next << endl;

		p = p->next;
		stackCount++;
	}
	cout << "++++++++++++++++++++++++++" << endl;
}
