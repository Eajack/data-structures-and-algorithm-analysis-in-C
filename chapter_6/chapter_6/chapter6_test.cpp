/*
	Author: Eajack Lau
	Date: 2019/4/29
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列）
*/
#include "heap_bin.h"
#include "heap_left.h"
#include "heap_skew.h"
#include "binTree.h"
#include "chapter6_practice.h"
using namespace std;

void test1()
{
	//1- heap_bin test
	int A[] = {1,12,13,15,18,19,57,87};
	int N = (sizeof(A)) / (sizeof(A[0]));
	PQ_bin A_heap = buildHeap_bin(A, N);

	int k_max = select_k(A, N, 5);
	cout << "k_max: " << k_max << endl;
}

void test2()
{
	//1- heap_left tests
	int A[] = {3,10,8,21,14,17,23,26}, B[] = {33,6,12,7,18,24,37,18};
	int N = (sizeof(A)) / (sizeof(A[0])), M = (sizeof(B)) / (sizeof(B[0]));

	//debug see
	PQ_left A_heap = buildHeap_left(A, N), B_heap = buildHeap_left(B, M);
	A_heap = merge_left(A_heap, B_heap);
	A_heap = deleteMin_left(A_heap);
}

void test3()
{
	//1- heap_left tests
	int A[] = { 3,10,8,21,14,17,23,26 }, B[] = { 33,6,12,7,18,24,37,18 };
	int N = (sizeof(A)) / (sizeof(A[0])), M = (sizeof(B)) / (sizeof(B[0]));

	//debug see
	PQ_skew A_heap = buildHeap_skew(A, N), B_heap = buildHeap_skew(B, M);
	A_heap = merge_skew(A_heap, B_heap);
}

void test4()
{
	int A[] = {16,18,12,51,24,65}, B[] = {13,14,26,23,51,24,65};
	int N = (sizeof(A)) / (sizeof(A[0])), M = (sizeof(B)) / (sizeof(B[0]));

	//debug see
	forest_root f1 = createForest_BT(A, N), f2 = createForest_BT(B, M);
	int f1_min = deleteMin_BT(f1), f2_min = deleteMin_BT(f2);
	f1 = merge_BT(f1, f2);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	pratice();

	return 0;
}