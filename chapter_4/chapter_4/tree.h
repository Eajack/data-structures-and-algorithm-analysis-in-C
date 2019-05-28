/*
	Author: Eajack Lau
	Date: 2019/4/18
	Function:
		《数据结构与算法分析（C语言描述）》第四章
		树
		1- 
*/
#include <iostream>
#include <climits>

//0- public
struct node_stack;
typedef struct node_stack *ptrToNode_stack;	// ptrToNode，指代所有node
typedef ptrToNode_stack Stack;	//linkedList，特指表头，指向栈顶

struct treeNode_bi;
typedef struct treeNode_bi *ptrToNode_bi;
typedef ptrToNode_bi tree_bi;
typedef ptrToNode_bi searchTree;

//1- stack
int isEmptyStack(Stack S);
Stack produceEmptyStack();
void push(ptrToNode_bi p, Stack S);
void pop(Stack S);
ptrToNode_bi top(Stack S);
void deleteStack(Stack S);

//2- tree
tree_bi createEmptyTree();
tree_bi createRoot(int x);
int getHeight(searchTree T);
void delete_wholeST(searchTree T);
ptrToNode_bi find_x_ST(int x, searchTree T);
ptrToNode_bi find_min_ST(searchTree T);
ptrToNode_bi find_max_ST(searchTree T);
searchTree insert_ST(int x, searchTree T);
searchTree delete_ST(int x, searchTree T);
searchTree create_ST(const int A[], int N);
void printValue_ST(int value, int depth);
void print_ST(searchTree T, int depth, int option);
tree_bi build_expressionTree(const int A[], int N);


//binary search tree

