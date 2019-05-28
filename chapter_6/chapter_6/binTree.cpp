/*
	Author: Eajack Lau
	Date: 2019/5/1
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 二项队列，二项树
*/
#include "binTree.h"
using namespace std;

struct binTreeNode
{
	int value;
	ptrToNode leftChild;
	ptrToNode nextSibling;
};

struct forest
{
	//currentSize: bin to dec, i.g.
	//	binTrees_array[8] = {NULL,p1,p2,NULL,NULL,NULL,NULL,NULL};
	//  currentSize = (110)_2 = (6)_10
	int currentSize;
	tree_root binTrees_array[MAX_TREE_NUM];
};

//isEmpty_BT
// O(1)
bool isEmpty_BT(forest_root f)
{
	if(f->currentSize == 0)
		return true;
	else
		return false;
}

//createEmptyForest_BT
// O(N)
forest_root createEmptyForest_BT()
{
	forest_root f = (forest_root)malloc(sizeof(struct forest));
	if(f == NULL)
	{
		cout << "createEmptyForest_BT ERROR: malloc out of space." << endl;
		return NULL;
	}

	f->currentSize = 0;
	for(int i=0; i<MAX_TREE_NUM; i++)
	{
		f->binTrees_array[i] = NULL;
	}

	return f;
}

//findMin
// O(logN), N is the num of all the treeNodes;
// O(M), M is the len of forest array
int findMin_BT(forest_root f)
{
	if(isEmpty_BT(f))
	{
		cout << "findMin_BT ERROR: f is empty." << endl;
		return INT_MIN;
	}

	int minValue = INT_MAX;
	for(int i=0; i<MAX_TREE_NUM; i++)
	{
		if(f->binTrees_array[i] and f->binTrees_array[i]->value < minValue)
			minValue = f->binTrees_array[i]->value;
	}

	return minValue;
}

//combineTrees_BT
// O(1)
//Attension: t1 & t2 has the same nodeNum
// combineTrees_BT等价于二进制单位加法器
tree_root combineTrees_BT(tree_root t1, tree_root t2)
{
	if(t1->value > t2->value)
	{
		return combineTrees_BT(t2, t1);
	}
	t2->nextSibling = t1->leftChild;
	t1->leftChild = t2;

	return t1;
}

//merge_BT
// merge_BT等价于2个多位二进制数，加法器
// O(logN)
// nubility code in P157
forest_root merge_BT(forest_root f1, forest_root f2)
{
	tree_root carry = NULL, t1, t2;
	//1- check add size < MAX_TREE_NUM
	if(f1->currentSize + f2->currentSize > MAX_TREE_NUM)
	{
		cout << "merge_BT ERROR: merge will exceed the space." << endl;
		return NULL;
	}

	//2- merge
	f1->currentSize += f2->currentSize;
	for(int i=0, j=1; j <= f1->currentSize; i++, j*=2)
	{
		// i is the index of array, j is the (bin 2 dec) of i-th position, i.e. 2^i
		// i.g.: i = 0, j = 2^0 = 1; i = 1, j = 2^1 = 2
		t1 = f1->binTrees_array[i], t2 = f2->binTrees_array[i];

		switch( 4*!!carry + 2*!!t2 + !!t1 )
		{
			//真值表，学这种方式
			case 0://no trees
			{
				break;
			}
			case 1://only t1
			{
				break;
			}
			case 2://only t2
			{
				f1->binTrees_array[i] = t2;
				f2->binTrees_array[i] = NULL;
				break;
			}
			case 4://only carry
			{
				f1->binTrees_array[i] = carry;
				carry = NULL;
				break;
			}
			case 3://t1 & t2
			{
				carry = combineTrees_BT(t1, t2);
				f1->binTrees_array[i] = f2->binTrees_array[i] = NULL;
				break;
			}
			case 5://t1 & carry
			{
				carry = combineTrees_BT(t1, carry);
				f1->binTrees_array[i] = NULL;
				break;
			}
			case 6://t2 & carry
			{
				carry = combineTrees_BT(t2, carry);
				f2->binTrees_array[i] = NULL;
				break;
			}
			case 7://t1 & t2 & carry
			{
				f1->binTrees_array[i] = carry;
				carry = combineTrees_BT(t1, t2);
				f2->binTrees_array[i] = NULL;
				break;
			}
		}
	}

	f2->currentSize = 0;
	return f1;
}

// delete
int deleteMin_BT(forest_root f)
{
	//1- pre
	int minValue = INT_MAX, minTreeIndex = 0;
	forest_root deletedForest;
	tree_root deletedTree, oldRoot;

	if(isEmpty_BT(f))
	{
		cout << "deleteMin_BT ERROR: f is empty." << endl;
		return INT_MIN;
	}

	//2- find the smallest index
	for(int i=0; i<MAX_TREE_NUM; i++)
	{
		if(f->binTrees_array[i] and f->binTrees_array[i]->value < minValue)
		{
			minValue = f->binTrees_array[i]->value;
			minTreeIndex = i;
		}
	}

	//3- delete binTrees_array[i]
	deletedTree = f->binTrees_array[minTreeIndex];
	oldRoot = deletedTree;
	deletedTree = deletedTree->leftChild;
	free(oldRoot);

	deletedForest = createEmptyForest_BT();
	//key code, place separated tree into deletedForest
	// deletedForest->currentSize 需要想想
	deletedForest->currentSize = (1 << minTreeIndex) - 1;//2*minTreeIndex - 1
	for(int i=minTreeIndex - 1; i>=0; i--)
	{
		deletedForest->binTrees_array[i] = deletedTree;
		deletedTree = deletedTree->nextSibling;
		deletedForest->binTrees_array[i]->nextSibling = NULL;
	}
	f->binTrees_array[minTreeIndex] = NULL;
	f->currentSize -= (deletedForest->currentSize + 1);
	merge_BT(f, deletedForest);

	return minValue;
}

//create forest
forest_root createForest_BT(const int A[], int N)
{
	//1- pre
	forest_root f1 = createEmptyForest_BT(), f2= createEmptyForest_BT();
	tree_root t1 = (tree_root)malloc(sizeof(struct binTreeNode));
	if(t1 == NULL)
	{
		cout << "createForest_BT ERROR 1: t1 malloc out of space." << endl;
		return NULL;
	}
	t1->value = A[0];
	t1->leftChild = t1->nextSibling = NULL;
	f1->currentSize = 1;
	f1->binTrees_array[0] = t1;

	//2- 
	for(int i=1; i<N; i++)
	{
		tree_root t2 = (tree_root)malloc(sizeof(struct binTreeNode));
		if(t2 == NULL)
		{
			cout << "createForest_BT ERROR 2: t2 malloc out of space.\ni = " << i << endl;
			return NULL;
		}
		t2->value = A[i];
		t2->leftChild = t2->nextSibling = NULL;
		f2->currentSize = 1;
		f2->binTrees_array[0] = t2;
		f1 = merge_BT(f1, f2);
	}

	return f1;
}