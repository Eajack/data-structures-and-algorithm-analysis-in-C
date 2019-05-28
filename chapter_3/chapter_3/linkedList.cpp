/*
	Author: Eajack Lau
	Date: 2019/3/29
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		单链表, int型
*/

#include "linkedList.h"
using namespace std;

//1- 链表实现
// Attention: 带表头操作，list仅有表头时，代表是空链表
//			表头为linkedList L L->value=INT_MIN; L->next=L1node地址
//			-314仅为垃圾值
// 书本P33-P34
struct node
{
	int value;
	ptrToNode next;
};

//生成空表，即仅有表头
//O(1)
linkedList produceEmptyList()
{
	ptrToNode tmpNode = (ptrToNode)malloc(sizeof(struct node));
	if (tmpNode == NULL)
	{
		cout << "produceEmptyList ERROR: malloc out of space" << endl;
		return NULL;
	}
	tmpNode->value = INT_MIN;
	tmpNode->next = NULL;

	return tmpNode;
}

//insert元素x，在p后面插入x, 返回插入x对应node地址
//O(1)
ptrToNode insert_x(int x, linkedList L, ptrToNode p)
{
	// Attention: 不是sizeof(struct node*)，或sizeof(ptrTONode)，
	//			这是为指针malloc
	ptrToNode tmpNode = (ptrToNode)malloc(sizeof(struct node));
	if (tmpNode == NULL)
	{
		cout << "insert_x ERROR: malloc out of space" << endl;
		return NULL;
	}
	tmpNode->value = x;
	tmpNode->next = p->next;
	p->next = tmpNode;

	return tmpNode;
}

//push操作，append
void push_x(int x, linkedList L)
{
	ptrToNode push_node;
	ptrToNode p = L->next;
	while(p->next != NULL)
	{
		p = p->next;
	}
	push_node = insert_x(x, L, p);
}

//生成链表
// O(N)
linkedList produceList(const int A[], int N)
{
	//1- 生成空表
	linkedList header = produceEmptyList();

	//2- 遍历数组，生成链表
	ptrToNode p_now = NULL;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			p_now = insert_x(A[i], header, header);
		}
		else
		{
			p_now = insert_x(A[i], header, p_now);
		}
	}

	return header;
}

// 测试是否为空表
//O(1)
int isEmptyList(linkedList L)
{
	return (L->next == NULL);
}

// 测试是否为最后节点
//O(1)
int isLastNode(ptrToNode p)
{
	return (p->next == NULL);
}

//获取链表长度，不包括表头
//O(N),N为链表长度
int getListLength(linkedList L)
{
	ptrToNode p = L->next;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

// 找到value = x的节点地址
//O(N),N为链表长度
ptrToNode find_x(int x, linkedList L)
{
	ptrToNode p = L->next;

	while (p != NULL && p->value != x)
	{
		p = p->next;
	}

	return p;
}

// 为delete_x服务
//O(N),N为链表长度
ptrToNode findPrevious(int x, linkedList L)
{
	// 注意：可能x为L1的value（L1前面是表头）
	//	因此，此处p即为目标x的前1个节点地址
	// NULL <=> 404 NOT FOUND
	ptrToNode p = L;

	while (p->next != NULL && p->next->value != x)
	{
		p = p->next;
	}

	if(p == L)
		cout << "WARNING: L is an empty list!!!" << endl;

	return p;
}

// 删除find到的第一个x，若无x，L不变；否则L自身改变，删除x
//O(1),不考虑findPrevious子函数复杂度
void delete_x(int x, linkedList L)
{
	ptrToNode p_previous = findPrevious(x,L);
	ptrToNode tmpNode;
	
	if (!isLastNode(p_previous))//防止p_previous为尾节点
	{
		tmpNode = p_previous->next;
		p_previous->next = tmpNode->next;
		free(tmpNode);	//注意，要free
	}
}


//删除链表，包括表头
//O(N)
void delete_L(linkedList L)
{
	ptrToNode p, tmpNode;
	p = L->next;
	L->next = NULL;
	free(L);	// 释放表头
	while (p != NULL)	//注意，不用next，直接当前p判断
	{
		tmpNode = p->next;
		free(p);
		p = tmpNode;
	}
}

// 打印链表
void printList(linkedList L)
{
	if (L->value != INT_MIN)
	{
		cout << "printList EROOR: L's header ERROR" << endl;
		return;
	}

	ptrToNode p = L->next;
	cout << "++++++++++++++++++++++++++" << endl;
	cout << "printList: " << endl;
	int listCount = 1;
	while (p != NULL)	//注意，不用next，直接当前p判断
	{
		cout << listCount << "-\tp->value: " << p->value << endl;
		cout << "\tp->next: " << p->next << endl;

		p = p->next;
		listCount++;
	}
	cout << "++++++++++++++++++++++++++" << endl;
}
