/*
	Author: Eajack Lau
	Date: 2019/5/3
	Function:
		《数据结构与算法分析（C语言描述）》第七章
		排序（升序）
		7种排序：insert_sort、shell_sort、heap_sort、
				merge_sort、quick_sort、bubble_sort、selection_sort
		radix_sort（基数排序）&bucket_sort（桶式排序）
			在chapter_3的“linkedList_application_sort.cpp”
*/
#include <iostream>
#include <climits>
#include "heap_bin.h"

void insert_sort(int A[], int N);
void shell_sort(int A[], int N);
void heap_sort(int A[], int N);

void merge(int A[], int tmp[], int leftBegin, int rightBegin, int rightEnd);
void sub_merge_sort(int A[], int tmp[], int left, int right);
void merge_sort(int A[], int N);

int getPivot(int A[], int left, int right);
void sub_quick_sort(int A[], int left, int right);
void quick_sort(int A[], int N);

void bubble_sort(int A[], int N);
void selection_sort(int A[], int N);