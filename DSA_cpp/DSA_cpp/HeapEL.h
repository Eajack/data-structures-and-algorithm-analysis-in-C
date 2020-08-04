/*
	Author: Eajack Lau
	Date: 2020/6/22
	Function:
	堆（优先队列,PriorityQueue,PQ）
		1- 二叉堆。即“堆”，数组实现。对应C++标准库的优先队列Priority Queue
		2- 左式堆。属于二叉堆（最小/最大堆），树实现。任意结点的左孩子的Npl大于等于右孩子的Npl
			左倾堆，极不平衡树
*/

#pragma once

#include <vector>
#include <algorithm>


//1 二叉堆
enum HEAP_TYPE {
	MAX=INT_MAX,
	MIN=INT_MIN
};

struct HeapBinary
{
	// heapArray数组长度/容量为（capacity + 1），包括堆顶heapArray[0]
	int capacity;
	// size代表目前堆中已有元素个数
	int size;
	// heapArray[0]默认为INT_MIN（最小堆）,可以设置输入参数flag设置最小/最大
	int *heapArray;

	//
	HeapBinary(enum HEAP_TYPE flag = MIN) :capacity(1), size(0) {
		heapArray = new int[1];
		heapArray[0] = flag;
	}
	HeapBinary(int capacity, enum HEAP_TYPE flag = MIN) :capacity(capacity), size(0) {
		heapArray = new int[capacity];
		heapArray[0] = flag;
	}
	HeapBinary(int capacity, int size, enum HEAP_TYPE flag = MIN) :capacity(capacity), size(size) {
		heapArray = new int[capacity];
		heapArray[0] = flag;
	}
};

class Heap
{
public:
	Heap();
	Heap(std::vector<int> vals, enum HEAP_TYPE flag=MIN);
	~Heap();

	//1 入队，即插入1个值，O(logN)
	void enqueue(int val);
	//2 出队，即删除堆顶，并重新调整堆，O(logN)
	int dequeue();
	//3 获取，O(1)
	int getSize();
	int getHeapTop();
	//4 清空，O(1)
	void clear();
	//5 二叉堆应用1：堆排序/获取TopK的值，O(NlogN)
	std::vector<int> heapSort();

private:
	HeapBinary * heap;
};

//2 左式堆，只实现最小堆版本
struct TreeNodeHeapLeft
{
	int val;
	TreeNodeHeapLeft* left;
	TreeNodeHeapLeft* right;
	//左式堆树节点特有属性Npl
	//	Npl是 null path length 的缩写，
	//	指的是从该结点到达一个没有两个孩子的结点的最短距离（一个孩子的结点或者叶子）。
	//	一般定义NULL的Npl为-1以使计算简便
	int Npl;

	TreeNodeHeapLeft() :val(0), left(nullptr), right(nullptr), Npl(-1) {};
	TreeNodeHeapLeft(int val) :val(val), left(nullptr), right(nullptr), Npl(0) {};
};

class HeapLeft
{
public:
	HeapLeft();
	HeapLeft(std::vector<int> vals);
	~HeapLeft();

	//1 merge合并，O(logN)
	TreeNodeHeapLeft* merge(TreeNodeHeapLeft* h1, TreeNodeHeapLeft* h2);
	//2 入队，即插入1个值，O(logN)
	void enqueue(int val);
	//3 出队，即删除堆顶，并重新调整堆，O(logN)
	int dequeue();
	//3 获取，O(1)
	int getHeapTop();
private:
	TreeNodeHeapLeft * root;
};
