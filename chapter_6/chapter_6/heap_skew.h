/*
	Author: Eajack Lau
	Date: 2019/5/1
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 斜堆
*/
#include <iostream>
#include <climits>

struct treeNode_skew;
typedef struct treeNode_skew *PQ_skew;

bool isEmpty_skew(PQ_skew q);
int findMin_skew(PQ_skew q);
PQ_skew merge_skew(PQ_skew q1, PQ_skew q2);
static PQ_skew subMerge_skew(PQ_skew q1, PQ_skew q2);
PQ_skew insert_skew(int x, PQ_skew q);
PQ_skew deleteMin_skew(PQ_skew q);
PQ_skew buildHeap_skew(const int A[], int N);