/*
	Author: Eajack Lau
	Date: 2019/3/30
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		链表应用，桶式排序&基数排序
*/
#include <iostream>
#include <limits.h>

#ifndef LINKEDLIST_APPLICATION_SORT
#define LINKEDLIST_APPLICATION_SORT

int* bucketSort(const int A[], int N, int M, bool reverseFlag);
int get_digit(int num, int digit);
void radixSort(int* A, int N, bool reverseFlag=false, int M=10);

#endif
