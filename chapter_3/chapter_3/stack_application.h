/*
	Author: Eajack Lau
	Date: 2019/4/15
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		栈的应用
*/
#include <iostream>
#include <climits>
#include <cctype>
#include <cstdlib>
using namespace std;

#ifndef STACK_APPLICATION
#define STACK_APPLICATION

// 1- 栈声明
struct node_string;
typedef struct node_string *ptrToNode_string;	// ptrToNode，指代所有node
typedef ptrToNode_string Stack_string;	//linkedList，特指表头，指向栈顶

int isEmptyStack_string(Stack_string S);
Stack_string produceEmptyStack_string();
void push_string(char x, Stack_string S);
void pop_string(Stack_string S);
char top_string(Stack_string S);
void deleteStack_string(Stack_string S);

int checkSymbols(string inputText);
int calculatePostfix(const char postfixExpression_array[], int N);
char* transfer_Infix2Postfix(const char postfixExpression_array[], int N);

#endif