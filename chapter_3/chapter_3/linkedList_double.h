/*
	Author: Eajack Lau
	Date: 2019/3/30
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		双链表, int型
*/
#include <iostream>
#include <limits.h>

#ifndef LINKEDLIST_DOUBLE
#define LINKEDLIST_DOUBLE

// 1- 链表声明
struct node_double;
typedef struct node_double *ptrToNode_double;	// ptrToNode，指代所有node
typedef ptrToNode_double linkedList_double;	//linkedList，特指表头

linkedList_double produceEmptyList_double();
ptrToNode_double insert_x_double(int x, linkedList_double L, ptrToNode_double p);
linkedList_double produceList_double(const int A[], int N);
int isEmptyList_double(linkedList_double L);
int isHeaderNode_double(ptrToNode_double p);
int isTailerNode_double(ptrToNode_double p);
int getListLength_double(linkedList_double L);
ptrToNode_double find_x_double(int x, linkedList_double L);
void delete_x_double(int x, linkedList_double L);
void delete_L_double(linkedList_double L);
void printList_double(linkedList_double L);

#endif
