/*
Author: Eajack Lau
Date: 2020/6/24
Function:
8大排序算法
*/

#include "SortFunctionsEL.h"
using namespace std;

void bubbleSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}

void selectionSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i<n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j<n; j++) {
			if (nums[j] < nums[minIndex]) {
				minIndex = j;
			}
		}
		swap(nums[i], nums[minIndex]);
	}
}

void insertSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 1; i < n; i++) {
		int temp = nums[i];
		int j = i - 1;
		while ((j >= 0) && (temp < nums[j])) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = temp;
	}
}

void shellSort(vector<int>& nums)
{
	int n = nums.size();
	for (int increment = n / 2; increment > 0; increment /= 2) {
		for (int i = increment; i < n; i++) {
			int temp = nums[i];
			int j = i;
			for (; j >= increment; j -= increment) {
				if (temp < nums[j - increment]) {
					nums[j] = nums[j - increment];
				}
				else {
					break;
				}
			}
			nums[j] = temp;
		}
	}
}

void heapSort(vector<int>& nums)
{
	Heap heap(nums);
	vector<int> ans = heap.heapSort();
	nums = ans;
}


void mergeSort(vector<int>& nums) {
	vector<int> ans = mergeSortHelper(nums);
	nums = ans;
}

vector<int> mergeSortHelper(vector<int>& nums) {
	//1
	int n = nums.size();
	if (n < 2) {
		return nums;
	}

	vector<int> nums1, nums2;
	int i = 0;
	for (; i<n / 2; i++) {
		nums1.push_back(nums[i]);
	}
	for (; i<n; i++) {
		nums2.push_back(nums[i]);
	}

	//2
	vector<int> t1 = mergeSortHelper(nums1), t2 = mergeSortHelper(nums2);
	return merge(t1, t2);
}

vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	while (!nums1.empty() && !nums2.empty()) {
		if (nums1[0] <= nums2[0]) {
			ans.push_back(nums1[0]);
			nums1.erase(nums1.begin());
		}
		else {
			ans.push_back(nums2[0]);
			nums2.erase(nums2.begin());
		}
	}
	while (!nums1.empty()) {
		ans.push_back(nums1[0]);
		nums1.erase(nums1.begin());
	}
	while (!nums2.empty()) {
		ans.push_back(nums2[0]);
		nums2.erase(nums2.begin());
	}

	return ans;
}


int paritition(vector<int>& nums, int low, int high) {
	int pivot = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= pivot) {
			--high;
		}
		nums[low] = nums[high];
		while (low < high && nums[low] <= pivot) {
			++low;
		}
		nums[high] = nums[low];
	}
	nums[low] = pivot;
	return low;
}

//快排母函数
void quickSortHelper(vector<int>& nums, int low, int high) {
	if (low < high) {
		int pivot = paritition(nums, low, high);
		quickSortHelper(nums, low, pivot - 1);
		quickSortHelper(nums, pivot + 1, high);
	}
}

void quickSort(vector<int>& nums) {
	quickSortHelper(nums, 0, nums.size() - 1);
}


void bucketSort(vector<int>& nums, int MAX)
{
	vector<int> bucket(MAX, 0);
	for (int n : nums) {
		bucket[n]++;
	}

	int index = 0;
	for (int i = 0; i<bucket.size(); i++) {
		while (bucket[i] > 0) {
			nums[index++] = i;
			bucket[i]--;
		}
	}
}
