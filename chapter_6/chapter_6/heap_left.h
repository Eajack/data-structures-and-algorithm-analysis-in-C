/*
	Author: Eajack Lau
	Date: 2019/4/30
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 左式堆
*/

#include <iostream>
#include <climits>
using namespace std;

struct treeNode_left;
typedef struct treeNode_left *PQ_left;

bool isEmpty_left(PQ_left q);
int findMin_left(PQ_left q);
PQ_left merge_left(PQ_left q1, PQ_left q2);
static PQ_left subMerge_left(PQ_left q1, PQ_left q2);
PQ_left insert_left(int x, PQ_left q);
PQ_left deleteMin_left(PQ_left q);
PQ_left buildHeap_left(const int A[], int N);