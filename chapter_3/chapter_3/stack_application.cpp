/*
	Author: Eajack Lau
	Date: 2019/4/15
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		栈的应用
*/
#include "stack.h"
#include "stack_application.h"
#include <map>
using namespace std;

struct node_string
{
	char value;
	ptrToNode_string next;
};

// test if S is |value = EMPTY_STRING, next = NULL|
//O(1)
int isEmptyStack_string(Stack_string S)
{
	return (S->value == '0' && S->next == NULL);
}

//produce empty stack, which is |value = INT_MIN, next = NULL|
//O(1)
Stack_string produceEmptyStack_string()
{
	ptrToNode_string tmpNode = (ptrToNode_string)malloc(sizeof(struct node_string));
	if (tmpNode == NULL)
	{
		cout << "produceEmptyStack ERROR: malloc out of space" << endl;
		return NULL;
	}
	tmpNode->value = '0';
	tmpNode->next = NULL;

	return tmpNode;
}

//push x to S，meanwhile S = the addr of 'x'
// Attention: the addr of S is always the same, only S->next changes
//O(1)
void push_string(char x, Stack_string S)
{
	ptrToNode_string tmpNode = (ptrToNode_string)malloc(sizeof(struct node_string));
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
void pop_string(Stack_string S)
{
	ptrToNode_string tmpNode;
	if( !isEmptyStack_string(S) )
	{
		//pop
		tmpNode = S->next;
		S->next = S->next->next;
		free(tmpNode);
	}
}

//top, get the top number
//O(1)
char top_string(Stack_string S)
{
	if (!isEmptyStack_string(S))
		return S->next->value;
	else
	{
		cout << "top ERROR: Empty Stack_string" <<  endl;
		return '0';
	}
}

void deleteStack_string(Stack_string S)
{
	if( !isEmptyStack_string(S) )
	{
		while( !isEmptyStack_string(S) )
			pop_string(S);
	}
	else
	{
		cout << "deleteStack ERROR: Empty Stack" << endl;
	}
}

//1- balance symbols
// only check "([{"
int checkSymbols(string inputText)
{
	//step 1
	Stack_string header = produceEmptyStack_string();

	//step 2
	char popOut_char;
	for(auto it = inputText.begin(); it!=inputText.end(); it++)
	{
		char symbol_now = *it;
		if( (symbol_now == '(') or (symbol_now == '{') or (symbol_now == '[') )
		{
			push_string(symbol_now, header);
		}
		else if( (symbol_now == ')') or (symbol_now == '}') or (symbol_now == ']') )
		{
			if(isEmptyStack_string(header))
			{
				// check over, bad return
				return -1;
			}
			else
			{
				popOut_char = top_string(header);
				switch(symbol_now){
					case ')':{
						if(popOut_char != '(')
						{
							return -1;
						}
						break;
					}
					case '}':{
						if(popOut_char != '{')
						{
							return -1;
						}
						break;
					}
					case ']':{
						if(popOut_char != '[')
						{
							return -1;
						}
						break;
					}
				}
				pop_string(header);
			}
		}
	}

	//step 3
	if(isEmptyStack_string(header))
	{
		return 1;
	}
	else
	{
		return -1;
	}

	deleteStack_string(header);
}

//2- postfix expression
//	calculate a postfix expression
//  e.g. 6 5 2 3 + 8 * + 3 + *
int calculatePostfix(const char postfixExpression_array[], int N)
{
	//step 1
	Stack header = produceEmptyStack();

	//step 2
	int popOut_int_1, popOut_int_2, result_of_12;
	for(int i=0; i < N; i++)
	{
		char symbol_now = postfixExpression_array[i];
		if(isdigit(symbol_now))
		{
			push( (int)symbol_now - 48, header );
		}
		else if( (symbol_now == '+') or (symbol_now == '-') or (symbol_now == '*') or (symbol_now == '/') )
		{
			popOut_int_1 = top(header);
			pop(header);
			popOut_int_2 = top(header);
			pop(header);

			switch(symbol_now)
			{
				case '+':
				{
					result_of_12 = popOut_int_1 + popOut_int_2;
					push(result_of_12, header);
					break;
				}
				case '-':
				{
					result_of_12 = popOut_int_1 - popOut_int_2;
					push(result_of_12, header);
					break;
				}
				case '*':
				{
					result_of_12 = popOut_int_1 * popOut_int_2;
					push(result_of_12, header);
					break;
				}
				case '/':
				{
					result_of_12 = popOut_int_1 / popOut_int_2;
					push(result_of_12, header);
					break;
				}
			}
		}
	}

	//step 3
	if(isEmptyStack(header))
	{
		cout << "calculatePostfix ERROR: postfix expression error" << endl;
		return -1;
	}
	else
	{
		int result = top(header);
		return result;
	}
}

//3- transfer infix 2 postfix
// only for symbols: +, *, (, )
//	prior level: '(' = ')' > '*' > '+'
char* transfer_Infix2Postfix(const char postfixExpression_array[], int N)
{
	//step 1
	char *output = new char[N]();
	for(int i=0; i < N; i++)
		output[i] = 255;

	char symbol_now;
	Stack_string header = produceEmptyStack_string();
	map<char, int> prior_level = {
		{'+',1}, {'*',2}, {'(',3}
	};

	//step 2
	int output_count = 0;
	for(int i=0; i < N; i++)
	{
		symbol_now = postfixExpression_array[i];
		if( (symbol_now != '+') and (symbol_now != '*') and (symbol_now != '(') and \
			(symbol_now != ')') )
		{
			output[output_count] = symbol_now;
			output_count++;
		}
		else
		{
			//step 3
			if(symbol_now == ')')
			{
				int continueFlag = 1;
				if( !isEmptyStack_string(header) )
				{
					while(continueFlag)
					{
						char popOut_char = top_string(header);
						if(popOut_char != '(')
						{
							output[output_count] = popOut_char;
							output_count++;
							pop_string(header);
						}
						else
						{
							pop_string(header);
							continueFlag = 0;
						}
					}
				}
				else
				{
					cout << "infix ERROR: symbol_now == )" << endl;
					return NULL;
				}
			}
			else	//+, *, (
			{
				char popOut_char = top_string(header);
				while( (popOut_char != '0') and (prior_level[symbol_now] <= prior_level[popOut_char]) and\
					(popOut_char != '(') )
				{
					output[output_count] = popOut_char;
					output_count++;
					pop_string(header);
					popOut_char = top_string(header);
				}
				push_string(symbol_now, header);
			}
		}
	}

	//step 3
	while( !isEmptyStack_string(header) )
	{
		char popOut_char = top_string(header);
		output[output_count] = popOut_char;
		output_count++;
		pop_string(header);
	}

	return &output[0];
}
