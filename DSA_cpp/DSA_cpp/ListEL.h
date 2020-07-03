/*
	Author: Eajack Lau
	Date: 2020.6.19
	Function:
		链表类实现
*/

#pragma once

struct SingleListNode
{
	int val;
	SingleListNode* next;
	SingleListNode(int val) : val(val), next(nullptr) {};
	SingleListNode() : val(0), next(nullptr) {};
};
typedef struct SingleListNode StackNode;
typedef struct SingleListNode QueueNode;
typedef struct SingleListNode HashNode1;

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