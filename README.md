#  data structures and algorithm analysis in C
# 《数据结构与算法分析——C语言描述》

<div align=center><img src="https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/blob/master/book.jpg"/></div>


## 1、运行环境
> * Windows
> * VS 2017
> * cpp

## 2、参考资料
> * 《数据结构与算法分析——C语言描述》
> * Google
> * 个人的C/C++混合实现：[Eajack/data-structures-and-algorithm-analysis-in-C](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C)

## 3、代码说明
CPP复现代码。

注意，由于时间关系

- 图论Graph算法，未复现。沿用Master分支的C/C++混合代码
- 未实现测试样例test.cpp代码

> 以下为代码说明

- List：链表

```c++
struct SingleListNode
{
	int val;
	SingleListNode* next;
	SingleListNode(int val) : val(val), next(nullptr) {};
	SingleListNode() : val(0), next(nullptr) {};
};

class SingleList
{
private:
	SingleListNode * head = nullptr;
public:
	SingleList(int val);
	SingleList();
	~SingleList();

	//1 初始化链表，O(N)
	void produceList(const int A[], int size);
	//2 获取链表长度，O(N)
	int size();
	//3 查找，O(N)
	bool find(int x);
	//4 删除（index，从0开始），O(N)
	void delete_withIndex(int index);
	//5 插入（index，从0开始），O(N)
	void insert_x_beforeIndex(int x, int index);
	//6 清空链表，O(N)
	void clear();
	//7 打印链表，O(N)
	void print();
};
```



- Queue：队列

```c++
class Queue
{
public:
	Queue();
	Queue(int val);
	~Queue();

	//1 判断是否空，O(1)
	bool empty();
	//2 获取队列size，O(1)
	int size();
	//3 尾部入队，O(1)
	void enqueue(int x);
	//4 头部出队，O(1)
	int dequeue();
	//5 清空，O(N)
	void clear();
	//6 打印，O(N)
	void print();

private:
	// 头尾指针同时维护
	QueueNode * queueFront;
	QueueNode* queueBack;
};
```



- Stack：栈

```c++
class Stack
{
public:
	Stack();
	Stack(int val);
	~Stack();

	//1- 获取size，O(1)
	int size();
	//2- 判断空，O(1)
	bool empty();
	//3- push，O(1)
	void push(int x);
	//4- pop，O(N)
	void pop();
	//5- top，O(N)
	int top();
	//6- 清空，O(N)
	void clear();
	//7- 打印，O(N)
	void print();

private:
	StackNode * stackBottom;
	StackNode * stackTop;
};
```



- Tree：树

```c++
struct TreeNodeBinary{
	int val;
	TreeNodeBinary *left;
	TreeNodeBinary *right;
	TreeNodeBinary(): val(0), left(nullptr), right(nullptr) {};
	TreeNodeBinary(int val): val(0), left(nullptr), right(nullptr) {};
};
enum TraversalFlag {
	PRE_ORDER=1,
	MID_ORDER,
	AFTER_ORDER,
	LEVEL_ORDER
};

//1 普通二叉树
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int val);
	~BinaryTree();

	//N为节点总数
	//1 获取树的高度，O(N)
	int height();
	//2 前序/中序/后序/层序遍历，O(N)
	std::vector<int> Traversal(enum TraversalFlag flag);
	//3 DFS应用1：树的查找，O(N)
	TreeNodeBinary* find(int val);
	//4 DFS应用2：打印所有【根 => 叶节点】路径，O(N)
	std::vector<std::string> getPath();
	//5 DFS应用3：树清空，O(N)
	void clear();

private:
	TreeNodeBinary* root;
	std::vector<int> traversalVals;
	std::vector<std::string> paths;
	std::vector<std::vector<int>> levelVals;

	//1 获取树的高度
	int _height(TreeNodeBinary* r);
	//2 前序/中序/后序/层序遍历
	void _preOrder(TreeNodeBinary* r);
	void _midOrder(TreeNodeBinary* r);
	void _afterOrder(TreeNodeBinary* r);
	void _levelOrder(TreeNodeBinary* r);
	void _Traversal(TreeNodeBinary* r, enum TraversalFlag flag);
	//3 DFS应用1：树的查找
	void _find(TreeNodeBinary* r, int val, TreeNodeBinary* &ans);
	//4 DFS应用2：打印所有【根 => 叶节点】路径
	void _getPath(TreeNodeBinary * r, std::string cur);
	//5 DFS应用3：树清空
	void _clear(TreeNodeBinary* r);
};

//2 二叉查找树（左小右大）
class BinarySearchTree:public BinaryTree
{
public:
	BinarySearchTree();
	BinarySearchTree(std::vector<int> vals);
	~BinarySearchTree();

	//1 插入，O(logN)
	void insert(int val);
	//2 查找，O(logN)
	bool find(int val);
	int findMax();
	int findMin();
	//3 删除，O(logN)
	void erase(int val);
private:
	TreeNodeBinary * root;

	//1 插入
	TreeNodeBinary* _insert(int val, TreeNodeBinary* r);
	//2 查找
	TreeNodeBinary* _find(int val, TreeNodeBinary* r);
	TreeNodeBinary* _findMax(TreeNodeBinary* r);
	TreeNodeBinary* _findMin(TreeNodeBinary* r);
	//3 删除
	TreeNodeBinary* _erase(int val, TreeNodeBinary* r);
};
```



- Heap：堆

```c++
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
		heapArray = new int[1];
		heapArray[0] = flag;
	}
	HeapBinary(int capacity, int size, enum HEAP_TYPE flag = MIN) :capacity(capacity), size(size) {
		heapArray = new int[1];
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
```



- HashMap：哈希表

```c++
//1 方法1
// 解决冲突方法1 基于链表
//	分离链接法（separate chainning method）：将hashval相同的，保存在1个链表数组中
class HashMap1
{
public:
	HashMap1();
	HashMap1(int size);
	// 建表，O(N*M)
	HashMap1(int size, const int keys[], int N);
	~HashMap1();

	// N为链表个数，M为哈希表大小size
	//1 下一个质数，用来更新size，O(N^1.5)
	int nextPrime(int N);
	//2 自定义哈希函数，O(1)
	int hashFuntion(int key);
	//3 哈希表查找，O(N)（最坏）
	int find(int key);
	//4 哈希表插入，O(N)（最坏）
	void insert(int key);
	//5 哈希表删除，O(N)（最坏）
	void erase(int key);
	//6 获取哈希表size，O(1)
	int size();
	//7 哈希表清空，O(N)
	void clear();
private:
	std::vector<std::vector<HashNode1>> hashMap1;
};


//1 方法2
// 解决冲突方法2
//	开放定址法
enum kindOfEntry{
	EMPTY = 0,
	FILLED
};
struct HashNode2{
	int val;
	enum kindOfEntry info;
	HashNode2(int val) : val(val), info(EMPTY) {};
	HashNode2() : val(0), info(EMPTY) {};
};
enum detectFlag {
	LINE_DETECT = 1,
	TWICE_DETECT,
	//REHASS_DETECT
};


class HashMap2
{
public:
	HashMap2();
	HashMap2(int mapSize);
	// 建表，O(N)
	HashMap2(int mapSize, const int keys[], int N, enum detectFlag flag=LINE_DETECT);
	~HashMap2();

	//N为哈希表大小
	//1 下一个质数，用来更新size，O(N^1.5)
	int nextPrime(int N);
	//2 自定义哈希函数，O(1)
	int hashFuntion(int key);
	//3 哈希表查找，O(1)/O(N)（线性/二次）
	int detect(int key, int currentPos, int collisionNum, enum detectFlag flag = LINE_DETECT);
	int find(int key, enum detectFlag flag = LINE_DETECT);
	//4 哈希表插入，O(1)/O(N)（线性/二次）
	void insert(int key, enum detectFlag flag = LINE_DETECT);
	//5 哈希表删除，O(1)/O(N)（线性/二次）
	void erase(int key, enum detectFlag flag = LINE_DETECT);
	//6 哈希表清空，O(N)
	void clear();
private:
	int size;
	std::vector<HashNode2> hashMap2;
};
```



- UnionFindSet：并查集

```c++
class UnionFindSet
{
public:
	UnionFindSet(int NUMSETS = 8);
	~UnionFindSet();
	void union1(int root1, int root2);
	void union2(int root1, int root2);
	void union3(int root1, int root2);
	int find(int value);
private:
	std::vector<int> unionFindSet;
};
```



- Graph：图（未复现，直接用C/C++混合版本）

```c++
//general functions
struct listNode;
typedef struct listNode *ptrToNode;	//the List[i] pointer(i>0)
typedef ptrToNode List;	//the List[0] pointer

struct adjList_DAG;
typedef struct adjList_DAG *ptrToAdjList_DAG;//directed acyclic graph
typedef struct adjList_DAG *ptrToAdjList_uDAG;//undirected acyclic graph
typedef struct adjList_DAG *ptrToAdjList;//double, ud & d
typedef int** ptrToAdjMatrix_DAG;

typedef int* ptrToIndegreeArray;
typedef string Vertex;
typedef int Vertex_int;
typedef vector<Vertex_int> Vertex_vector;
typedef map<string, int> IndegreeMap;
typedef vector<string> TopSorted_name_vector;

struct distNode;
typedef struct distNode *DistNode;
typedef vector<DistNode> DistVector;

typedef DistVector tree_MST_Prim;
typedef pair<int, int> Edge;
typedef pair<Edge, int> Edge_info;
typedef vector<Edge_info> Edges;
typedef Edges tree_MST_Kruskal;


//1- createGraph
// uW-DAG(无权有向无圈图)|W-DAG(正权有向无圈图)|nW-DAG(负权有向无圈图)|W-uDAG(正权无向无圈图)
ptrToAdjList_DAG createGraph_adjList(int option, int v_num);
ptrToAdjMatrix_DAG createGraph_adjMatrix(int option, int v_num);
//2- getIndegree
// DG(有向图)
int* getIndegree_adjList(ptrToAdjList_DAG adj_list, int v_num);
int* getIndegree_adjMatrix(ptrToAdjMatrix_DAG adj_matrix, int v_num);
//3- findNewVertexOfIndegreeZero
Vertex findNewVertexOfIndegreeZero(IndegreeMap indegree_map);
//4- topolopy sort
// DAG(有向无圈图)
IndegreeMap transfer_array2map(ptrToIndegreeArray indegree_array, int v_num);
TopSorted_name_vector topSort(ptrToAdjList_DAG adj_list);
//5- findMinPath algorithms
//5.1 Unweighted Graph(uW-DAG)
void print_DistVector(DistVector dist_vector, int targetV);
DistVector createDistVector(ptrToAdjList_DAG adj_list, int targetV);
DistVector findMinPath_unweighted_1(ptrToAdjList_DAG adj_list, int targetV);
DistVector findMinPath_unweighted_2(ptrToAdjList_DAG adj_list, int targetV);
//5.2 Weighted Graph(Dijkstra)(W-DAG)
int getSmallestDist_unknowV(vector<int>& unknown_v, DistVector dist_vector);
DistVector findMinPath_weighted(ptrToAdjList_DAG adj_list, int targetV);
//5.3 Weighted Graph(negative)(nW-DAG)
bool isInq(int w_int, vector<int> q);
DistVector findMinPath_weighted_negative(ptrToAdjList_DAG adj_list, int targetV);
//6- minimum spanning tree(MST)
// W-uDAG(正权无向无圈图)
//(1)- Prim
tree_MST_Prim buildMST_Prim(ptrToAdjList_uDAG adj_list, int targetV);
//(2)- Kruskal
bool cmp(const Edge_info &e_info1, const Edge_info &e_info2);
void Edges_sort(Edges &edges);
//tree_MST_Kruskal buildMST_Kruskal(ptrToAdjList_uDAG adj_list);
//7- Graph Traversal
// (1)breadth-first search(BFS)
// (2)depth-first search(DFS)
Vertex_vector GraphTraversal_BFS(ptrToAdjList adj_list, int targetV);
void DFS(ptrToAdjList adj_list, int* nodeFlag_array, Vertex_vector &vertexs, int v_int);
Vertex_vector GraphTraversal_DFS(ptrToAdjList adj_list, int targetV);
```



- SortFunctions：8大排序算法

```c++
// 冒泡排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
void bubbleSort(std::vector<int>& nums);
// 选择排序，平均O(N ^ 2)，最好O(N ^ 2), 最差O(N ^ 2)
void selectionSort(std::vector<int>& nums);
// 插入排序，平均O(N ^ 2)，最好O(N), 最差O(N ^ 2)
void insertSort(std::vector<int>& nums);
// 希尔排序，平均O((NlogN)^2)，最好O(N), 最差O((NlogN)^2)
void shellSort(std::vector<int>& nums);
// 堆排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
void heapSort(std::vector<int>& nums);
// 归并排序，平均O(NlogN)，最好O(NlogN), 最差O(NlogN)
void mergeSortHelper(vector<int> &nums, int low, int high);
void merge(vector<int> &nums, int low, int mid, int high);
void mergeSort(std::vector<int>& nums);
// 快速排序，平均O(NlogN)，最好O(NlogN), 最差O(N^2)
int paritition(vector<int>& nums, int low, int high);
void quickSortHelper(vector<int>& nums, int low, int high);
void quickSort(std::vector<int>& nums);
// 桶排序，平均O(N+K)，最好O(N+K), 最差O(N^2)
void bucketSort(std::vector<int>& nums, int MAX);
```

