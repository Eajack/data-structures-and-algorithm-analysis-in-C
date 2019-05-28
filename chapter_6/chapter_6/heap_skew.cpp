/*
	Author: Eajack Lau
	Date: 2019/5/1
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 斜堆，左式堆的特例
*/

#include "heap_skew.h"
using namespace std;

struct treeNode_skew
{
	int value;
	PQ_skew left;
	PQ_skew right;
};

//isEmpty
// O(1)
bool isEmpty_skew(PQ_skew q)
{
	return(q->value == INT_MIN and q->left == NULL and q->right == NULL);
}

//find min
// O(1)
int findMin_skew(PQ_skew q)
{
	return q->value;
}

//merge_skew
//merge_skew steps:
// step 1- if q1=NULL or q2=NULL, return q2 or q1.
// step 2- if q1≠NULL and q2≠NULL
//		Compare value of q1 & q2 (roots), q_m = min(q1, q2).
//		Here, suppose q_m is q1, i.e. q1->value < q2->value.
// step 3- q_m->left = q1->left.
// step 4- q_m->right = merge_skew(q2, q1->right); (recursion step).
// step 5- swap left&right.
//Compare with merge_skew in heap_left.cpp
//	only step 5 differs
PQ_skew merge_skew(PQ_skew q1, PQ_skew q2)
{
	//step1
	if(q1 == NULL)
		return q2;
	if(q2 == NULL)
		return q1;

	//step2
	if(q1->value < q2->value)
		return subMerge_skew(q1, q2);
	else
		return subMerge_skew(q2, q1);	
}

static PQ_skew subMerge_skew(PQ_skew q1, PQ_skew q2)
{
	if(q1->left == NULL)//single node, i.e. q1->right = NULL, q1->Npl = 0;
		q1->left = q2;
	else
	{
		//step 3&4- merge q1's right & q2
		q1->right = merge_skew(q1->right, q2);

		//step 5- swap left & right child
		PQ_skew left_buffer = q1->left;
		q1->left = q1->right;
		q1->right = left_buffer;
	}
	return q1;
}

//insert x
// O(logN)
PQ_skew insert_skew(int x, PQ_skew q)
{
	PQ_skew singleNode = (PQ_skew)malloc(sizeof(struct treeNode_skew));
	if(singleNode == NULL)
	{
		cout << "insert_skew ERROR: malloc out of space." << endl;
		return NULL;
	}
	else
	{
		singleNode->value = x;
		singleNode->left = singleNode->right = NULL;
		q = merge_skew(singleNode, q);
	}

	return q;
}

//deleteMin, delete root <=> merge left&right
// O(logN)
PQ_skew deleteMin_skew(PQ_skew q)
{
	PQ_skew leftHeap, rightHeap;

	if(isEmpty_skew(q))
	{
		cout << "deleteMin_skew ERROR: q is empty." << endl;
		return NULL;
	}

	leftHeap = q->left;
	rightHeap = q->right;
	free(q);

	return merge_skew(leftHeap, rightHeap);
}

//build heap
// O(NlogN)
PQ_skew buildHeap_skew(const int A[], int N)
{
	//1- create root
	PQ_skew q = (PQ_skew)malloc(sizeof(struct treeNode_skew));
	q->value = A[0];
	q->left = NULL; q->right = NULL;

	//2- build
	for(int i=1; i<N; i++)
	{
		q = insert_skew(A[i], q);
	}

	return q;
}