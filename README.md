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
>* 未实现：Chapter 11、Chapter 4.4-4.5

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