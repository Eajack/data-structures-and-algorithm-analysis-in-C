/*
	Author: Eajack Lau
	Date: 2019/3/29
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		单链表, int型
*/
#include <iostream>
#include <climits>

#ifndef LINKEDLIST
#define LINKEDLIST

// 1- 链表声明
struct node;
typedef struct node *ptrToNode;	// ptrToNode，指代所有node
typedef ptrToNode linkedList;	//linkedList，特指表头

//used for queue
typedef ptrToNode queue_header;

linkedList produceEmptyList();
linkedList produceList(const int A[], int N);
int isEmptyList(linkedList L);
int isLastNode(ptrToNode p);
int getListLength(linkedList L);
ptrToNode find_x(int x, linkedList L);
ptrToNode findPrevious(int x, linkedList L);
void delete_x(int x, linkedList L);
ptrToNode insert_x(int x, linkedList L, ptrToNode p);
void delete_L(linkedList L);
void printList(linkedList L);
void push_x(int x, linkedList L);


#endif
