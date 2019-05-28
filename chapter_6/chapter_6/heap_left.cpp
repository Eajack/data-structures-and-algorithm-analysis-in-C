/*
	Author: Eajack Lau
	Date: 2019/4/30
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 左式堆
*/

#include "heap_left.h"

struct treeNode_left
{
	int value;
	PQ_left left;
	PQ_left right;
	int Npl;
};

//isEmpty
// O(1)
bool isEmpty_left(PQ_left q)
{
	return(q->value == INT_MIN and q->left == NULL and q->right == NULL and q->Npl == 0);
}

//find min
// O(1)
int findMin_left(PQ_left q)
{
	return q->value;
}

//merge q1&q2
// O(logN)
//merge_left steps:
// step 1- if q1=NULL or q2=NULL, return q2 or q1.
// step 2- if q1≠NULL and q2≠NULL
//		Compare value of q1 & q2 (roots), q_m = min(q1, q2).
//		Here, suppose q_m is q1, i.e. q1->value < q2->value.
// step 3- q_m->left = q1->left.
// step 4- q_m->right = merge_left(q2, q1->right); (recursion step).
// step 5- if(q_m->left->Npl < q_m->right->Npl), swap left&right.
PQ_left merge_left(PQ_left q1, PQ_left q2)
{
	//step 1
	if(q1 == NULL)
		return q2;
	if(q2 == NULL)
		return q1;
/*	if(q1 == q2 == NULL)
	{
		cout << "merge_left ERROR: q1 == q2 == NULL" << endl;
		return NULL;
	}*/
	//step 2
	if(q1->value < q2->value)
		return subMerge_left(q1, q2);
	else
		return subMerge_left(q2, q1);
}

//subMerge_left
static PQ_left subMerge_left(PQ_left q1, PQ_left q2)
{
	if(q1->left == NULL)//single node, i.e. q1->right = NULL, q1->Npl = 0;
		q1->left = q2;
	else
	{
		//step 3&4- q1->left still the same, merge q1's right & q2
		q1->right = merge_left(q1->right, q2);

		//step 5- swap left & right child
		if(q1->left->Npl < q1->right->Npl)
		{
			PQ_left left_buffer = q1->left;
			q1->left = q1->right;
			q1->right = left_buffer;
		}
		q1->Npl = q1->right->Npl + 1;
	}
	return q1;
}

//insert x
// O(logN)
PQ_left insert_left(int x, PQ_left q)
{
	PQ_left singleNode = (PQ_left)malloc(sizeof(struct treeNode_left));
	if(singleNode == NULL)
	{
		cout << "insert_left ERROR: malloc out of space." << endl;
		return NULL;
	}
	else
	{
		singleNode->value = x;
		singleNode->Npl = 0;
		singleNode->left = singleNode->right = NULL;
		q = merge_left(singleNode, q);
	}

	return q;
}

//deleteMin, delete root <=> merge left&right
// O(logN)
PQ_left deleteMin_left(PQ_left q)
{
	PQ_left leftHeap, rightHeap;

	if(isEmpty_left(q))
	{
		cout << "deleteMin_left ERROR: q is empty." << endl;
		return NULL;
	}

	leftHeap = q->left;
	rightHeap = q->right;
	free(q);

	return merge_left(leftHeap, rightHeap);
}

//build heap
// O(NlogN)
PQ_left buildHeap_left(const int A[], int N)
{
	//1- create root
	PQ_left q = (PQ_left)malloc(sizeof(struct treeNode_left));
	q->value = A[0]; q->Npl = 0;
	q->left = NULL; q->right = NULL;

	//2- build
	for(int i=1; i<N; i++)
	{
		q = insert_left(A[i], q);
	}

	return q;
}