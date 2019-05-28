/*
	Author: Eajack Lau
	Date: 2019/5/2
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 习题
*/

#include "chapter6_practice.h"
using namespace std;

void practice6_2_3()
{
	int A[] = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};
	int N = sizeof(A) / sizeof(A[0]);

	//debug see
	PQ_bin h = buildHeap_bin(A, N);
	int min1 = deleteMin_bin(h);
	int min2 = deleteMin_bin(h);
	int min3 = deleteMin_bin(h);

}

void pratice()
{
	practice6_2_3();
}