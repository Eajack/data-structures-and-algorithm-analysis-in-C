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
#include "sort_algorithms.h"
using namespace std;

//7.2 insert sort
// https://visualgo.net/en/sorting
// O(N^2)
void insert_sort(int A[], int N)
{
	int tmp, j;
	for(int i=1; i<N; i++)
	{
		tmp = A[i];
		for(j=i; j>0 and A[j-1]>tmp; j--)
		{
			A[j] = A[j-1];
		}
		A[j] = tmp;
	}
}

//7.4  Shell sort
// diminishing increment sort
// http://www.cnblogs.com/chengxiao/p/6104371.html
// O(N^1.5-2)
void shell_sort(int A[], int N)
{
	int i,j,increment,tmp;

	for(increment = N/2; increment>0; increment /= 2)
	{
		for(i=increment; i<N; i++)
		{
			tmp = A[i];
			for(j=i; j>=increment; j -= increment)
			{
				if(tmp < A[j-increment])
					A[j] = A[j-increment];
				else
					break;
			}
			A[j] = tmp;
		}
	}
}

//7.5 heap sort, with "heap_bin.h"
// O(N*logN)
void heap_sort(int A[], int N)
{
	PQ_bin q = buildHeap_bin(A, N);
	for(int i=0; i<N; i++)
	{
		A[i] = deleteMin_bin(q);
	}
}

//7.6 merge sort
// O(N*logN)
// recursion
// https://www.cnblogs.com/chengxiao/p/6194356.html
void merge(int A[], int tmp[], int leftBegin, int rightBegin, int rightEnd)
{
	int leftEnd = rightBegin - 1, N = rightEnd - leftBegin + 1, tmpPos = leftBegin;

	// key codes
	while(leftBegin <= leftEnd and rightBegin <= rightEnd)
	{
		if(A[leftBegin] <= A[rightBegin])
			tmp[tmpPos++] = A[leftBegin++];
		else
			tmp[tmpPos++] = A[rightBegin++];
	}

	//deal with the rest
	while(leftBegin <= leftEnd)
		tmp[tmpPos++] = A[leftBegin++];
	while(rightBegin <= rightEnd)
		tmp[tmpPos++] = A[rightBegin++];

	//copy tmp to A
	for(int i=0; i<N; i++, rightEnd--)
		A[rightEnd] = tmp[rightEnd];
}

void sub_merge_sort(int A[], int tmp[], int left, int right)
{
	int center;

	if(left < right)
	{
		center = (left + right)/2;
		sub_merge_sort(A, tmp, left, center);
		sub_merge_sort(A, tmp, center+1, right);
		merge(A, tmp, left, center+1, right);
	}
}

void merge_sort(int A[], int N)
{
	int* tmp = (int*)malloc(N * sizeof(int));
	if(tmp != NULL)
	{
		sub_merge_sort(A, tmp, 0, N-1);
		free(tmp);
	}
	else
	{
		cout << "merge_sort ERROR: malloc out of space." << endl;
		return;
	}
}

//7.6 quick sort
// O(N*logN)
//the median value of A[left], A[center], A[right]
int getPivot(int A[], int left, int right)
{
	int tmp;
	int center = (left+right) / 2;

	if(A[left] > A[center])
	{
		tmp = A[left];
		A[left] = A[center];
		A[center] = tmp;
	}
	if(A[left] > A[right])
	{
		tmp = A[left];
		A[left] = A[right];
		A[right] = tmp;
	}
	if(A[center] > A[right])
	{
		tmp = A[center];
		A[center] = A[right];
		A[right] = tmp;
	}
	//now, A[left] <= A[center] <= A[right]

	//swap A[center] & A[right-1]
	tmp = A[center];
	A[center] = A[right-1];
	A[right-1] = tmp;

	return A[right-1];
}

void sub_quick_sort(int A[], int left, int right)
{
	int i,j, pivot, tmp;

	if(left + 3 <= right)
	{
		pivot = getPivot(A, left, right);
		i = left;
		j = right-1;
		for(;;)
		{
			while(A[++i] < pivot){}
			while(A[--j] > pivot){}
			if(i < j)
			{
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
			else
				break;
		}
		tmp = A[i];
		A[i] = A[right-1];
		A[right-1] = tmp;

		sub_quick_sort(A, left, i-1);
		sub_quick_sort(A, i+1, right);
	}
	else
	{
		insert_sort(A+left, right-left+1);
	}
}

void quick_sort(int A[], int N)
{
	sub_quick_sort(A, 0, N-1);
}

//bubble sort
// O(N^2)
void bubble_sort(int A[], int N)
{
	bool swapped;
	int tmp;
	do
	{
		swapped = false;
		for(int i=0; i<N-1; i++)
		{
			if(A[i] > A[i+1])
			{
				tmp = A[i];
				A[i] = A[i+1];
				A[i+1] = tmp;
				swapped = true;
			}
		}
	} while (swapped);
}

//selection sort
// O(N^2)
void selection_sort(int A[], int N)
{
	int minValue, minIndex, tmp;
	for(int i=0; i<N-1; i++)
	{
		minValue = A[i];
		for(int j=i+1; j<N; j++)
		{
			if(A[j] < minValue)
			{
				minIndex = j;
				minValue = A[j];
			}
		}

		tmp = A[i];
		A[i] = A[minIndex];
		A[minIndex] = tmp;
	}
}