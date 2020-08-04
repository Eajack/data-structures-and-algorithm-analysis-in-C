/*
	Author: Eajack Lau
	Date: 2020/6/22
	Function:
	堆（优先队列,PriorityQueue,PQ）
		1- 二叉堆，即“堆”，数组实现。最小堆：上小下大/最大堆：上大下小
		2- 斜堆
		3- 左式堆
*/

#include "HeapEL.h"
using namespace std;

//1 二叉堆
Heap::Heap()
{
	heap = new HeapBinary();
}

// 建堆，O(NlogN)
Heap::Heap(std::vector<int> vals, HEAP_TYPE flag)
{
	//1
	int _capacity = 2 * vals.size();
	heap = new HeapBinary(_capacity, 0, flag);
	//2
	for (int v : vals) {
		enqueue(v);
	}
}

Heap::~Heap()
{
}

// 入队，即插入1个值，O(logN)
void Heap::enqueue(int val)
{
	if (heap->size == heap->capacity) {
		return;
	}

	//key code
	int i = (++heap->size);
	if (heap->heapArray[0] == INT_MIN) {
		//最小堆，上小下大 => h->heapArray[i/2] > val
		for (; heap->heapArray[i / 2] > val; i /= 2)	// ++size;
		{
			heap->heapArray[i] = heap->heapArray[i / 2];
		}
	}
	else {
		//最大堆，上大下小 => h->heap_array[i/2] < val; 
		for (; heap->heapArray[i / 2] < val; i /= 2)	// ++size;
		{
			heap->heapArray[i] = heap->heapArray[i / 2];
		}
	}
	heap->heapArray[i] = val;
}

// 出队，即删除堆顶，并重新调整堆，O(logN)
int Heap::dequeue()
{
	if (heap->size == 0) {
		return INT_MIN;
	}

	int i, child;
	int minValue = heap->heapArray[1];
	int lastValue = heap->heapArray[heap->size--];//size--, delete 1 value

	for (i = 1; i * 2 <= heap->size; i = child) {
		//找到下一层节点最小的值
		child = i * 2;
		if (child != heap->size && heap->heapArray[child + 1] < heap->heapArray[child]) {
			child++;
		}

		//下滤
		if (lastValue > heap->heapArray[child]) {
			heap->heapArray[i] = heap->heapArray[child];
		}
		else {
			break;
		}
	}
	heap->heapArray[i] = lastValue;

	return minValue;
}


int Heap::getSize()
{
	if (!heap) {
		return 0;
	}
	return heap->size;
}

int Heap::getHeapTop()
{
	if (!heap) {
		return 0;
	}
	return heap->heapArray[1];
}

void Heap::clear()
{
	if (!heap) {
		heap->capacity = 0;
		heap->size = 0;
		int* temp = heap->heapArray;
		delete temp;
		heap->heapArray = nullptr;
	}
}

// 堆排序，O(NlogN)
//	最小堆 => 升序，最大堆 => 降序
vector<int> Heap::heapSort()
{
	vector<int> ans;
	while (getSize() > 0) {
		ans.push_back(dequeue());
	}
	return ans;
}

HeapLeft::HeapLeft()
{
	root = new TreeNodeHeapLeft();
}

HeapLeft::HeapLeft(vector<int> vals)
{
	if (vals.empty()) {
		HeapLeft();
	}

	//1
	root = new TreeNodeHeapLeft(vals[0]);
	for (int v : vals) {
		enqueue(v);
	}
}

HeapLeft::~HeapLeft()
{
}

// 左式堆基本操作：merge
//	Step1：当输入的两个堆都是空的，输出空堆；当有一个堆是空的，则返回非空的堆
//	Step2：当两个堆非空时，比较两个根节点的大小，设h1为根节点值较小的堆，返回为：
//		堆根节点：h1根节点
//		左子树：h1->left
//		右子树：merge(h1->right, h2)
//	Step3：判断根节点的【左节点Npl】 < 【右节点Npl】，若是，则互换
TreeNodeHeapLeft * HeapLeft::merge(TreeNodeHeapLeft * h1, TreeNodeHeapLeft * h2)
{
	//Step 1
	if (!h1) {
		return h2;
	}
	if (!h2) {
		return h1;
	}

	//Step 2
	if (h1->val > h2->val) {
		swap(h1, h2);
	}
	//h1只有右子树
	if (h1->left == NULL) {
		h1->left = h2;
	}
	else {
		//右子树：merge(h1->right, h2)
		h1->right = merge(h1->right, h2);

		//step 3
		if (h1->left->Npl < h1->right->Npl) {
			TreeNodeHeapLeft* left_buffer = h1->left;
			h1->left = h1->right;
			h1->right = left_buffer;
		}
		h1->Npl = h1->right->Npl + 1;
	}
	return h1;
}


void HeapLeft::enqueue(int val)
{
	//1
	if (!root) {
		root = new TreeNodeHeapLeft(val);
		return;
	}

	//2
	TreeNodeHeapLeft* node = new TreeNodeHeapLeft(val);
	root = merge(node, root);
}

int HeapLeft::dequeue()
{
	if (!root) {
		return INT_MIN;
	}

	int ans = root->val;
	TreeNodeHeapLeft *left = root->left, *right = root->right;
	delete root;
	root = merge(left, right);
}

int HeapLeft::getHeapTop()
{
	return root->val;
}
