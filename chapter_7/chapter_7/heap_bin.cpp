/*
	Author: Eajack Lau
	Date: 2019/4/29
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 二叉堆，即“堆”，数组实现
		// 二叉堆(堆)：上小下大/上大下小；二叉查找树：左小右大
		// 上小下大 <=> createEmptyPQ_bin INT_MIN; q->heap_array[i/2] > x; 
		// 上大下小 <=> createEmptyPQ_bin INT_MAX; q->heap_array[i/2] < x;
*/
#include "heap_bin.h"
using namespace std;

struct heap_bin
{
	//attention: heap_array[0] is INT_MIN, only (capacity) place can be filled with value;
	//	the whole length of heap_array is (capacity + 1);
	int capacity;
	int size;
	int *heap_array;
};

//createEmptyPQ
// O(1)
PQ_bin createEmptyPQ_bin(int capacity)
{
	PQ_bin q = (PQ_bin)malloc(sizeof(struct heap_bin));
	if(q == NULL)
	{
		cout << "createEmptyPQ ERROR: malloc out of space" << endl;
		return NULL;
	}

	// heap_array[0] is empty
	q->heap_array = (int *)malloc(sizeof(int) * (capacity+1));
	q->capacity = capacity;
	q->size = 0;
	q->heap_array[0] = INT_MIN;//上小下大 => INT_MIN; 上大下小 => INT_MAX; 

	return q;
}

//delete q
// O(1)
void deletePQ_bin(PQ_bin q)
{
	free(q->heap_array);
	free(q);
}

//isEmpty
// O(1)
bool isEmpty_bin(PQ_bin q)
{
	if(q->size == 0)
		return true;
	else
		return false;
}

//isFull
// O(1)
bool isFull_bin(PQ_bin q)
{
	if(q->size == q->capacity)
		return true;
	else
		return false;
}

//findMin
// O(1)
int findMin_bin(PQ_bin q)
{
	return q->heap_array[1];
}

//insert x, percolate up(上滤)
// O(logN)
void insert_bin(int x, PQ_bin q)
{
	int i;
	if(isFull_bin(q))
	{
		cout << "insert_bin ERROR: q is full" << endl;
		return;
	}

	//key code
	//上小下大 => q->heap_array[i/2] > x; 上大下小 => q->heap_array[i/2] < x; 
	for(i=(++q->size); q->heap_array[i/2] > x; i /= 2)	// ++size;
	{
		q->heap_array[i] = q->heap_array[i/2];
	}
	q->heap_array[i] = x;
}

//delete min, percolate down(下滤)
// O(logN)
int deleteMin_bin(PQ_bin q)
{
	int i,child;
	int minValue, lastValue;

	if(isEmpty_bin(q))
	{
		cout << "deleteMin_bin ERROR: q is empty." << endl;
		return INT_MIN;
	}
	minValue = q->heap_array[1];
	lastValue = q->heap_array[q->size--];//size--, delete 1 value

	for(i=1; i*2 <= q->size; i=child)
	{
		//find the smaller child
		child = i*2;
		if(child != q->size and q->heap_array[child+1] < q->heap_array[child])
			child++;

		//percolate down
		if(lastValue > q->heap_array[child])
			q->heap_array[i] = q->heap_array[child];
		else
			break;
	}
	q->heap_array[i] = lastValue;

	return minValue;
}

//build heap
// O(N)
PQ_bin buildHeap_bin(const int A[], int N)
{
	PQ_bin q = createEmptyPQ_bin(N);
	for(int i=0; i<N; i++)
	{
		insert_bin(A[i], q);
	}

	return q;
}

//6.4 heap application
//6.4.1 select the k-th largest num in A[N], heap sort
// O(N) + O((N-k) * logN) = O(N + (N-k)*logN)
int select_k(const int A[], int N, int k)
{
	//1- build heap
	PQ_bin q = buildHeap_bin(A, N);
	int value_k;

	//2- select k
	for(int i=0; i<=N-k; i++)
	{
		value_k = deleteMin_bin(q);
	}

	return value_k;
}