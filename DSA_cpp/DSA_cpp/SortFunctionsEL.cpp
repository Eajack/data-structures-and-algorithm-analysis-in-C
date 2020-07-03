/*
	Author: Eajack Lau
	Date: 2020/6/24
	Function:
		8大排序算法
*/

#include "SortFunctions.h"
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
		int j = i;
		for (; j > 0 && nums[j - 1] > temp; j++) {
			nums[j] = nums[j - 1];
		}
		nums[j] = temp;
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

void merge(vector<int> &nums, int low, int mid, int high) {
	// preconditions:
	// nums[low...mid] is sorted
	// nums[mid+1 ... high] is sorted
	// Copy nums[low ... mid] to leftSubNums
	// Copy nums[mid+1 ... high] to rightSubNums
	vector<int> leftSubNums(nums.begin() + low, nums.begin() + mid + 1);
	vector<int> rightSubNums(nums.begin() + mid + 1, nums.begin() + high + 1);
	int idxLeft = 0, idxRight = 0;
	leftSubNums.insert(leftSubNums.end(), numeric_limits<int>::max());
	rightSubNums.insert(rightSubNums.end(), numeric_limits<int>::max());
	// Pick min of leftSubNums[idxLeft] and rightSubNums[idxRight], and put into nums[i]
	for (int i = low; i <= high; i++) {
		if (leftSubNums[idxLeft] < rightSubNums[idxRight]) {
			nums[i] = leftSubNums[idxLeft];
			idxLeft++;
		}
		else {
			nums[i] = rightSubNums[idxRight];
			idxRight++;
		}
	}
}

void mergeSortHelper(vector<int> &nums, int low, int high) {
	if (low >= high) {
		return;
	}

	int mid = (low + high) / 2;
	mergeSortHelper(nums, low, mid);
	mergeSortHelper(nums, mid + 1, high);
	merge(nums, low, mid, high);
}

void mergeSort(vector<int> &nums) {
	mergeSortHelper(nums, 0, nums.size() - 1);
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
	vector<vector<int>> bucket(MAX, vector<int>());
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		bucket[nums[i]].push_back(i);
	}

	int index = 0;
	for (vector<int> b : bucket) {
		for (int i : b) {
			nums[index++] = nums[i];
		}
	}
}
