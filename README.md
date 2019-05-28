#  data structures and algorithm analysis in C
# 《数据结构与算法分析——C语言描述》

![《数据结构与算法分析——C语言描述》](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/blob/master/book.jpg)

## 1、运行环境
> * Windows
> * VS 2017
> * C--

## 2、参考资料
> * 《数据结构与算法分析——C语言描述》
> * Google

## 3、代码说明
C--代码实现（C--入门弱鸡，混C/C--风格），每一章节的文件夹对应1个VS2017 C--工程。实现进度如下：
>* 实现：Chapter 2 ~ 9
>* 基本实现：Chapter 10
>* 未实现：Chapter 11-12、Chapter 4.4-4.5

book章节总结：
>* Chapter 1：数学基本知识、递归介绍
>* Chapter 2：大O分析、大Ω分析、大Θ分析、算法题例子
>* Chapter 3：链表、栈、队列
>* Chapter 4：基本树结构：二叉树、表达式树、二叉查找树、AVL树、伸展树、B树、树的遍历
>* Chapter 5：HashMap哈希表（散列）
>* Chapter 6：堆（优先队列）：二叉堆、d-堆、左式堆、斜堆、二项队列（森林forest）
>* Chapter 7：排序算法：插入、希尔、堆、归并、快排、桶式排序、基数排序；冒泡、选择
>* Chapter 8：并查集（不相交集）
>* Chapter 9：图论：拓扑排序、最短路算法（uW-uDAG、W-DAG、nw-DAG）、网络流问题、最小生成树、BFS & DFS、NP问题介绍
>* Chapter 10：算法设计技巧：贪心、分治、动态规划、回溯
>* Chapter 11：摊还分析（M次总共再M平均），例子：二项队列、斜堆、斐波那契堆、伸展树
>* Chapter 12：高级DS：红黑树、treap树、k-d树、AA-树、配对堆、skip list etc.

以下总结已完成代码：
1. [Chapter_2](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_2)
>* 最大子序列和问题（3种算法）
>* 二分法（binary search）
>* 欧几里得算法gcd（求最大公因子）
>* 取幂算法

2. [Chapter_3](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_3)
* 链表 linkedList
	* (1) 链表（单链表 linkedList、双链表 linkedList_double、循环链表 linkedList_circle）**（N为链表长度）**
		* (1.1) 共同功能（具体代码实现不同）
			* linkedList produceEmptyList()：**生成空单链表，O(1)**
			* linkedList produceList(const int A[], int N)：**生成单链表，O(N)**
			* int isEmptyList(linkedList L)：**判断L是否为空单链表，O(1)**
			* ptrToNode find_x(int x, linkedList L)：**在单链表L中，查找x值位置（线性遍历，第一个碰到的节点），O(N)**
			* int getListLength(linkedList L)：**获取单链表L的长度，O(N)**
			* ptrToNode findPrevious(int x, linkedList L)：**在单链表L中，查找x值前一节点位置（线性遍历，第一个碰到的节点），O(N)**
			* void delete_x(int x, linkedList L)：**在单链表L中，删除x值对应的节点（线性遍历，第一个碰到的节点），O(1)（不考虑findPrevious子函数复杂度）**
			* void delete_L(linkedList L)：**删除链表，包括表头，O(N)**
			* void printList(linkedList L)：**打印链表，O(N)**
			* ptrToNode insert_x(int x, linkedList L, ptrToNode p)：**insert元素x，在p后面插入x, 返回插入x对应node地址，O(1)**
		* (1.2) 独立功能：不同类型链表内部存在独立功能函数，此处不一一展示
	* (2) 链表应用
		* int* bucketSort(const int A[], int N, int M, bool reverseFlag)：**桶式排序，O(N-M)，N个整数，取值范围为0~M-1**
		* int get_digit(int num, int digit)：**radixSort辅助函数，获取num的位digit处值，O(digit)**
		* void radixSort(int* A, int N, bool reverseFlag=false, int M=10)：**基数排序，O(PNM)实现，然而书中是O(P(N-M))...**
* 栈 stack
	* (1) 栈**（N为栈元素数量）**
		* int isEmptyStack(Stack S)：**判断是否为空栈，O(1)**
		* Stack produceEmptyStack()：**生成空栈，O(1)**
		* Stack produceStack(const int A[], int N)：**生成栈，O(N)**
		* void push(int x, Stack S)：**栈push，改变栈内容，O(1)**
		* void pop(Stack S)：**栈pop，改变栈内容，O(1)**
		* int top(Stack S)：**返回栈顶元素值，不栈内容，O(1)**
		* void deleteStack(Stack S)：**删除栈，O(N)**
		* void printStack(Stack S)：**打印栈，O(N)**
	* (2) 栈应用
		* int checkSymbols(string inputText)：**平衡符号检测，编译器检查符号是否成对，O(|inputText|)**
		* int calculatePostfix(const char postfixExpression_array[], int N)：**计算后缀表达式，O(N)**
		* char* transfer_Infix2Postfix(const char postfixExpression_array[], int N)：**中缀表达式 => 后缀表达式，O(N)**
* 队列 queue**（N为队列元素数量）**（基于链表）
	* int isEmpty_queue(queue_header Q)：**判断是否为空队列，O(1)**
	* int isFull_queue(queue_header Q)：**判断是否为满队列，O(1)**
	* queue_header createEmptyQueue()：**生成空队列，O(1)**
	* void deleteQueue(queue_header Q)：**删除队列，O(N)**
	* void enqueue(int x, queue_header Q)：**尾部入队，O(N)**
	* int dequeue(queue_header Q)：**头部出队，O(1)**
	* queue_header createQueue(const int A[], int N)：**生成队列，O(N)**
	* void print_queue(queue_header Q)：**打印队列，O(N)**

3. [Chapter_4](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_4)
* 树 tree（部分基于栈）
	* 二叉树binary tree（表达式树、二叉查找树binary search tree【BST，左小右大】）**（N为节点树数目）**
		* tree_bi createEmptyTree()：**生成空树，O(1)**
		* tree_bi createRoot(int x)：**生成根，O(1)**
		* int getHeight(searchTree T)：**获取树高度，O(N)**
		* void delete_wholeST(searchTree T)：**删除树，O(N)**
		* ptrToNode_bi find_x_ST(int x, searchTree T)：**寻找值为x的节点，O(logN)**
		* ptrToNode_bi find_min_ST(searchTree T)：**寻找最小值的节点，O(logN)**
		* ptrToNode_bi find_max_ST(searchTree T)：**寻找最大值的节点，O(logN)**
		* searchTree insert_ST(int x, searchTree T)：**插入x值的节点，O(logN)**
		* searchTree delete_ST(int x, searchTree T)：**删除x值的节点，O(logN)**
		* searchTree create_ST(const int A[], int N)：**生成BST，O(NlogN)**
		* void printValue_ST(int value, int depth)：**print_ST辅助函数，O(1)**
		* void print_ST(searchTree T, int depth, int option)：**树的遍历，先序preorder, 中序infix & 后序post, O(N)**
		* tree_bi build_expressionTree(const int A[], int N)：**构建表达式树， O(N)**
	* 其余树没实现。。。包括：B树、AVL树、伸展树；红黑树、treap树、k-d树、AA-树（Chapter 12，高级数据结构）

4. [Chapter_4](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_4)
* 树 tree（部分基于栈）
	* 二叉树binary tree（表达式树、二叉查找树binary search tree【BST，左小右大】）**（N为节点树数目）**
		* tree_bi createEmptyTree()：**生成空树，O(1)**
		* tree_bi createRoot(int x)：**生成根，O(1)**
		* int getHeight(searchTree T)：**获取树高度，O(N)**
		* void delete_wholeST(searchTree T)：**删除树，O(N)**
		* ptrToNode_bi find_x_ST(int x, searchTree T)：**寻找值为x的节点，O(logN)**
		* ptrToNode_bi find_min_ST(searchTree T)：**寻找最小值的节点，O(logN)**
		* ptrToNode_bi find_max_ST(searchTree T)：**寻找最大值的节点，O(logN)**
		* searchTree insert_ST(int x, searchTree T)：**插入x值的节点，O(logN)**
		* searchTree delete_ST(int x, searchTree T)：**删除x值的节点，O(logN)**
		* searchTree create_ST(const int A[], int N)：**生成BST，O(NlogN)**
		* void printValue_ST(int value, int depth)：**print_ST辅助函数，O(1)**
		* void print_ST(searchTree T, int depth, int option)：**树的遍历，先序preorder, 中序infix & 后序post, O(N)**
		* tree_bi build_expressionTree(const int A[], int N)：**构建表达式树， O(N)**
	* 其余树没实现。。。包括：B树、AVL树、伸展树；红黑树、treap树、k-d树、AA-树（Chapter 12，高级数据结构）

4. [Chapter_5](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_5)
* 哈希表 HashMap（散列）
	* 方法1：分离链接法 separate chainning method（基于链表）**（N为链表个数，tableSize）**
		* int nextPrime_seq(int N)：**寻找大于N的第一个素数，O(N^1.5)**
		* int hashFuntion_seq(int key, int modValue)：**哈希函数， O(1)**
		* ptrToHashTable_seq createEmptyHashTable_seq(int tableSize)：**构建空哈希表， O(N)**
		* void deleteHashTable_seq(ptrToHashTable_seq H)：**删除哈希表H， O(N)**
		* ptrToNode_seq find_seq(int key, ptrToHashTable_seq H)：**查找H[key]， O(N)**
		* void insert_seq(int key, ptrToHashTable_seq H)：**插入key， O(N)**
		* ptrToHashTable_seq createHashTable_seq(const int key[], int N, int tableSize)：**构建哈希表， O(N * tableSize)**
	* 方法2：开放定址法 open addressing**（N为链表个数，tableSize）**
		* int nextPrime_oa(int N)：**同nextPrime_seq**
		* int hashFuntion_oa(int key, int modValue)：**hashFuntion_seq**
		* ptrToHashTable_oa createEmptyHashTable_oa(int tableSize)：**同createEmptyHashTable_seq**
		* void deleteHashTable_oa(ptrToHashTable_oa H)：**同deleteHashTable_seq**
		* position detect_oa(int key, ptrToHashTable_oa H, position current_pos, int collisionNum, int detectFlag)：**线性检测、平方检测，O(1)/O(N)**
		* position find_oa(int key, ptrToHashTable_oa H, int detectFlag)：**查找key，detect_oa下，O(1)/O(N)**
		* void insert_oa(int key, ptrToHashTable_oa H, int detectFlag)：**插入key，detect_oa下，O(1)/O(N)**
		* void delete_oa(int key, ptrToHashTable_oa H, int detectFlag)：**删除key，O(1)/O(N)**
		* ptrToHashTable_oa createHashTable_oa(const int key[], int N, int tableSize, int detectFlag)：**再散列，O(N)**
		* ptrToHashTable_oa rehash(ptrToHashTable_oa H, int detectFlag)：**再散列，O(N)**
	* others：双散列（2个散列函数）未实现，可扩散列

4. [Chapter_6](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_6)
* 堆（优先队列）
	* 二叉堆 heap_bin
		* PQ_bin createEmptyPQ_bin(int capacity);
		* void deletePQ_bin(PQ_bin q);
		* bool isEmpty_bin(PQ_bin q);
		* bool isFull_bin(PQ_bin q);
		* int findMin_bin(PQ_bin q);
		* void insert_bin(int x, PQ_bin q);
		* int deleteMin_bin(PQ_bin q);
		* PQ_bin buildHeap_bin(const int A[], int N);
		* int select_k(const int A[], int N, int k);