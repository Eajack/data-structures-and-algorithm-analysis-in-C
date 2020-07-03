/*
	Author: Eajack Lau
	Date: 2020/6/24
	Function:
		8大排序算法

	1. 算法复杂度（默认升序）
		冒泡排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
		选择排序，平均O(N ^ 2)，最好O(N ^ 2), 最差O(N ^ 2)
		插入排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
		希尔排序，平均O((NlogN)^2)，最好O(N), 最差O((NlogN)^2)
		堆排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
		归并排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
		快速排序，平均O(NlogN)，最好O(NlogN), 最差O(N^2)
		桶排序，平均O(N+K)，最好O(N+K), 最差O(N^2)
	2. 稳定排序&不稳定排序
		2.1 稳定排序概念：保证2个相等数，排序后原来的顺序不变
		2.2 分类
			（1）稳定：冒泡排序、插入排序、归并排序、桶排序
			（2）不稳定：选择排序、快速排序、希尔排序、堆排序
			只用记住稳定的即可（冒泡排序、插入排序、归并排序、桶排序）
*/

#pragma once
#include <vector>
#include <algorithm>
#include "HeapEL.h"

// 冒泡排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
void bubbleSort(std::vector<int>& nums);
// 选择排序，平均O(N ^ 2)，最好O(N ^ 2), 最差O(N ^ 2)
void selectionSort(std::vector<int>& nums);
// 插入排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
void insertSort(std::vector<int>& nums);
// 希尔排序，平均O((NlogN)^2)，最好O(N), 最差O((NlogN)^2)
void shellSort(std::vector<int>& nums);
// 堆排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
void heapSort(std::vector<int>& nums);
// 归并排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
void mergeSortHelper(vector<int> &nums, int low, int high);
void merge(vector<int> &nums, int low, int mid, int high);
void mergeSort(std::vector<int>& nums);
// 快速排序，平均O(NlogN)，最好O(NlogN), 最差O(N^2)
int paritition(vector<int>& nums, int low, int high);
void quickSortHelper(vector<int>& nums, int low, int high);
void quickSort(std::vector<int>& nums);
// 桶排序，平均O(N+K)，最好O(N+K), 最差O(N^2)
void bucketSort(std::vector<int>& nums, int MAX);