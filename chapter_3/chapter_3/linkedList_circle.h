/*
	Author: Eajack Lau
	Date: 2019/3/30
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		循环链表, int型
*/
#include <iostream>
#include <climits>

#ifndef LINKEDLIST_CIRCLE
#define LINKEDLIST_CIRCLE

// 1- 链表声明
struct node_circle;
typedef struct node_circle *ptrToNode_circle;	// ptrToNode，指代所有node
typedef ptrToNode_circle linkedList_circle;	//linkedList，特指表头

linkedList_circle produceEmptyList_circle();
ptrToNode_circle insert_x_circle(int x, linkedList_circle L, ptrToNode_circle p);
linkedList_circle produceList_circle(const int A[], int N);
int isEmptyList_circle(linkedList_circle L);
int getListLength_circle(linkedList_circle L);
ptrToNode_circle find_x_circle(int x, linkedList_circle L);
void delete_x_circle(int x, linkedList_circle L);
void delete_px_circle(ptrToNode_circle p_x, linkedList_circle L);
void delete_L_circle(linkedList_circle L);
void printList_circle(linkedList_circle L);

#endif
