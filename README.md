#  data structures and algorithm analysis in C
# 《数据结构与算法分析——C语言描述》

<div align=center><img src="https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/blob/master/book.jpg"/></div>


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
* 最大子序列和问题（3种算法）
* 二分法（binary search）
* 欧几里得算法gcd（求最大公因子）
* 取幂算法

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
	* (1) 栈 **（N为栈元素数量）**
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
* 队列 queue **（N为队列元素数量）**（基于链表）
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
	* 方法2：开放定址法 open addressing **（N为链表个数，tableSize）**
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

5. [Chapter_6](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_6)
* 堆（优先队列）**（N为元素个数）**
	* 二叉堆 heap_bin（数组实现，上小下大）
		* PQ_bin createEmptyPQ_bin(int capacity)：**构建空二叉堆，O(1)**
		* void deletePQ_bin(PQ_bin q)：**删除二叉堆，O(1)**
		* bool isEmpty_bin(PQ_bin q)：**判断q是否为空，O(1)**
		* bool isFull_bin(PQ_bin q)：**判断q是否为满，O(1)**
		* int findMin_bin(PQ_bin q)：**查找最小值，O(1)**
		* void insert_bin(int x, PQ_bin q)：**插入值x，O(logN)**
		* int deleteMin_bin(PQ_bin q)：**删除最小值root，O(logN)**
		* PQ_bin buildHeap_bin(const int A[], int N)：**构建二叉堆，O(NlogN)**
		* int select_k(const int A[], int N, int k)：**选出数组第k大的数值，O(NlogN)**
	* 左式堆 heap_left
		* bool isEmpty_left(PQ_left q)：**判断q是否为空，O(1)**
		* int findMin_left(PQ_left q)：**查找最小值，O(1)**
		* PQ_left merge_left(PQ_left q1, PQ_left q2)：**合并q1 & q2，O(logN)**
		* static PQ_left subMerge_left(PQ_left q1, PQ_left q2)：**merge_left辅助函数**
		* PQ_left insert_left(int x, PQ_left q)：**插入x，O(logN)**
		* PQ_left deleteMin_left(PQ_left q)：**删除最小值root，O(logN)**
		* PQ_left buildHeap_left(const int A[], int N)：**构建左式堆，O(NlogN)**
	* 斜堆 heap_left （属于左式堆，差别：交换Npl无条件）
		* bool isEmpty_skew(PQ_skew q)：**判断q是否为空，O(1)**
		* int findMin_skew(PQ_skew q)：**查找最小值，O(1)**
		* PQ_skew merge_skew(PQ_skew q1, PQ_skew q2)：**合并q1 & q2，O(logN)**
		* static PQ_skew subMerge_skew(PQ_skew q1, PQ_skew q2)：**merge_skew辅助函数**
		* PQ_skew insert_skew(int x, PQ_skew q)：**插入x，O(logN)**
		* PQ_skew deleteMin_skew(PQ_skew q)：**删除最小值root，O(logN)**
		* PQ_skew buildHeap_skew(const int A[], int N)：**构建斜堆，O(NlogN)**

6. [Chapter_7](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_7)
* 排序算法 **（N为元素个数）**（平均大O）
	* void insert_sort(int A[], int N)：**插入排序，O(N^2)**
	* void shell_sort(int A[], int N)：**希尔排序，O(N^1.5-2)**
	* void heap_sort(int A[], int N)：**堆排序，O(NlogN)**
	* void merge_sort(int A[], int N)：**归并排序，O(NlogN)**
	* void quick_sort(int A[], int N)：**快速排序，O(NlogN)**
	* void bubble_sort(int A[], int N)：**冒泡排序，O(N^2)**
	* void selection_sort(int A[], int N)：**选择排序，O(N^2)**

7. [Chapter_8](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_8)
* 并查集（不相交集）**（N为NUMSETS，预设集合size）**
	* int* createEmptySet()：构建空集，O(N)
	* void union1_set(int* s, int root1, int root2)：**union-any，O(1)**
	* void union2_set(int* s, int root1, int root2)：**union-by-size，O(1)**
	* void union3_set(int* s, int root1, int root2)：**union-by-height，O(1)**
	* int find_set(int* s, int value)：**查找value所在集合index，O(value)**

8. [Chapter_9](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_9)
* 图论 **（|V|为点数，|E|为边数）**
	* ptrToAdjList_DAG createGraph_adjList(int option, int v_num)：**建图，邻接表，O(|V|+|E|)**
	* ptrToAdjMatrix_DAG createGraph_adjMatrix(int option, int v_num)：**建图，邻接矩阵，O(|V|^2)**
	* int* getIndegree_adjList(ptrToAdjList_DAG adj_list, int v_num)：**获取入度数组，邻接表，O(|E|)**
	* int* getIndegree_adjMatrix(ptrToAdjMatrix_DAG adj_matrix, int v_num)：**获取入度数组，邻接矩阵，O(|V|^2)**
	* Vertex findNewVertexOfIndegreeZero(IndegreeMap indegree_map)：**找到第一个入度为0的点，O(|V|)**
	* TopSorted_name_vector topSort(ptrToAdjList_DAG adj_list)：**拓扑排序，DAG，O(|E|)**
	* DistVector createDistVector(ptrToAdjList_DAG adj_list, int targetV)：**构建距离表，O(|V|)**
	* DistVector findMinPath_unweighted_1(ptrToAdjList_DAG adj_list, int targetV)：**最短路径算法（uW-DAG）版本1，O(|V|^2)**
	* DistVector findMinPath_unweighted_2(ptrToAdjList_DAG adj_list, int targetV)：**最短路径算法（uW-DAG）版本2，O(|E| + |V|)，BFS**
	* DistVector findMinPath_weighted(ptrToAdjList_DAG adj_list, int targetV)：**最短路径算法（W-DAG），Dijkstra，O(|V|^2 + |E|)**
	* DistVector findMinPath_weighted_negative(ptrToAdjList_DAG adj_list, int targetV)：**最短路径算法（nW-DAG），Bellman-Ford，O(|V| * |E|)**
	* tree_MST_Prim buildMST_Prim(ptrToAdjList_uDAG adj_list, int targetV)：**最小生成树算法Prim，O(|V|^2)**
	* tree_MST_Kruskal buildMST_Kruskal(ptrToAdjList_uDAG adj_list)：**最小生成树算法Kruskal，O(|E|log|E|)**
	* Vertex_vector GraphTraversal_BFS(ptrToAdjList adj_list, int targetV)：**广度优先遍历BFS，O(|E| + |V|)**
	* Vertex_vector GraphTraversal_DFS(ptrToAdjList adj_list, int targetV)：**深度优先遍历DFS，O(|E| + |V|)**

9. [Chapter_10](https://github.com/Eajack/data-structures-and-algorithm-analysis-in-C/tree/master/chapter_10)
* 算法设计技巧
	* (1) Greedy Algorithm 贪婪算法
		* (1.1) 霍夫曼码
			* tree_Huffman buildHuffmanTree(SymbolTable T)：构建霍夫曼树，O(N)
			* HuffmanCodeTable buildHuffmanCodeTable(tree_Huffman treeH)：构建霍夫曼编码表，O(logN)
		* (1.2) 近似装箱问题
			* Bins solveBMPOnline_nextFit(const double A[], int N)：下项适合算法，O(N)
			* Bins solveBMPOnline_firstFit(const double A[], int N)：首次适合算法，O(N^2)
			* Bins solveBMPOnline_bestFit(const double A[], int N)：最佳适合算法，O(N^2)
	* (2) Divide & Conquer 分治算法
		* (2.1) 最近点问题
			* double getMinimumPoints(Points points_vector, Point &a, Point &b)：原算法O(NlogN)，本代码getMinimumPoints_sub未进一步优化；
		* (2.2) 矩阵乘法
			* Matrix matrix_mul_origin(Matrix A, Matrix B, int rowA, int colA, int rowB, int colB)：矩阵乘法定义，O(N^3)
	* (3) 随机化算法 Random Algorithms
		* double getRandom()：获取随机数，O(1)

## 4、ToDo list(may be...)
基本的数据结构和算法实现都过了一遍，然而这东西不多看的话，肯定会忘。所以，刷leetcode也是必须的。考虑以后可能会，每一章按主题来写些总结回顾下，这样也能加深记忆，不过也要看时间吧。。。毕竟总结也十分耗时间，只不过重温的收获应该会多点罢了。
>* 刷leetcode
>* 每一章按主题写总结文