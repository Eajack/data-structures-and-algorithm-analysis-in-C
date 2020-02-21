#pragma once

struct ListNode;

class ListEL
{
private:
	ListNode* head;
public:
	ListEL() {
		head = nullptr;
	}
	~ListEL() {
		delete_L();
	}

	//功能函数
	//重构（无表头）
	//1- 生成单链表,又称初始化。O(N)
	void produceList(const int A[], int N);
	//2- 判断L是否为空单链表。O(1)
	bool isEmptyList() { return head == nullptr; };
	//3- 根据索引查找值，表头索引为0。O(N)
	int find_index(int index);
	//4- 根据索引删除节点，表头索引为0。O(N)
	void delete_index(int index);
	//5- 获取链表长度。O(N)
	int getListLength();
	//6- 在单链表L中，查找val值前一节点位置（线性遍历，第一个碰到的节点）。O(N)
	ListNode * findPrevious(int val);
	//7- 在单链表L中，删除x值对应的节点（线性遍历，第一个碰到的节点）。
	//	O(1)（不考虑findPrevious子函数复杂度）
	void delete_val(int val);
	//7- 清空链表。O(N)
	void delete_L();
	//8- 打印链表。O(N)
	void printList();
	//9- insert元素x，在索引后面插入x, 返回插入x对应node地址，O(1)
	void insert_val(int val, int index);

	//新增函数
	//3- 查找L是否有val值，没有返回nullptr。O(N)
	ListNode * find_val(int val);
};

