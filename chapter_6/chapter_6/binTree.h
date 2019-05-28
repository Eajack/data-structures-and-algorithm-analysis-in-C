/*
	Author: Eajack Lau
	Date: 2019/5/1
	Function:
		《数据结构与算法分析（C语言描述）》第六章
		堆（优先队列,PriorityQueue,PQ）
		1- 二项队列，二项树
*/

#include <iostream>
#include <climits>
#define MAX_TREE_NUM 16

struct binTreeNode;
struct forest;
typedef struct binTreeNode *ptrToNode;
typedef ptrToNode tree_root;
typedef struct forest *ptrToForest;
typedef ptrToForest forest_root;

bool isEmpty_BT(forest_root f);
forest_root createEmptyForest_BT();
int findMin_BT(forest_root f);
tree_root combineTrees_BT(tree_root t1, tree_root t2);
forest_root merge_BT(forest_root f1, forest_root f2);
int deleteMin_BT(forest_root f);
forest_root createForest_BT(const int A[], int N);