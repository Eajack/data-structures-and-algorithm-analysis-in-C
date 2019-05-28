/*
	Author: Eajack Lau
	Date: 2019/4/29
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 二叉堆，即“堆”，数组实现
*/
#include <iostream>
#include <climits>

struct heap_bin;
typedef struct heap_bin *PQ_bin;

PQ_bin createEmptyPQ_bin(int capacity);
void deletePQ_bin(PQ_bin q);
bool isEmpty_bin(PQ_bin q);
bool isFull_bin(PQ_bin q);
int findMin_bin(PQ_bin q);
void insert_bin(int x, PQ_bin q);
int deleteMin_bin(PQ_bin q);
PQ_bin buildHeap_bin(const int A[], int N);
int select_k(const int A[], int N, int k);