#include "SortFunctionsEL.h"
#include <vector>
#include <iostream>

using namespace std;

void print(vector<int>& nums) {
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
}

int main() {
	vector<int> nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 冒泡排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
	bubbleSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 选择排序，平均O(N ^ 2)，最好O(N ^ 2), 最差O(N ^ 2)
	selectionSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 插入排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
	insertSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 希尔排序，平均O((NlogN)^2)，最好O(N), 最差O((NlogN)^2)
	shellSort(nums);
	print(nums);


	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 堆排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
	heapSort(nums);
	print(nums);
	

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 归并排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
	mergeSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 快速排序，平均O(NlogN)，最好O(NlogN), 最差O(N^2)
	quickSort(nums);
	print(nums);

	nums = { 6, 5, 1, 2, 3, 90, 56, 32, 12 };
	// 桶排序，平均O(N+K)，最好O(N+K), 最差O(N^2)
	bucketSort(nums, 10000);
	print(nums);
}