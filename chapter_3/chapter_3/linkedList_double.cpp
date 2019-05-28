/*
	Author: Eajack Lau
	Date: 2019/3/29
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		单链表, int型
*/

#include "linkedList_double.h"
using namespace std;

//1- 双链表实现
// Attention: 1- 双链表，带表头
// 书本P38
struct node_double
{
	ptrToNode_double previous;
	int value;
	ptrToNode_double next;
};

//生成空表，即仅有表头
//O(1)
linkedList_double produceEmptyList_double()
{
	ptrToNode_double tmpNode = (ptrToNode_double)malloc(sizeof(struct node_double));
	if (tmpNode == NULL)
	{
		cout << "produceEmptyList ERROR: malloc out of space" << endl;
		return NULL;
	}
	tmpNode->previous = NULL;
	tmpNode->value = INT_MIN;
	tmpNode->next = NULL;

	return tmpNode;
}

//insert元素x，在p后面插入x, 返回插入x对应node地址
//O(1)
ptrToNode_double insert_x_double(int x, linkedList_double L, ptrToNode_double p)
{
	// Attention: 不是sizeof(struct node_double*)，或sizeof(ptrToNode_double)，
	//			这是为指针malloc
	ptrToNode_double tmpNode = (ptrToNode_double)malloc(sizeof(struct node_double));
	if (tmpNode == NULL)
	{
		cout << "insert_x ERROR: malloc out of space" << endl;
		return NULL;
	}
	tmpNode->previous = p;
	tmpNode->value = x;
	tmpNode->next = p->next;

	//previous update
	p->next = tmpNode;
	//next update, 注意检查是否为尾节点
	if (tmpNode->next != NULL)
	{
		tmpNode->next->previous = tmpNode;
	}

	return tmpNode;
}

//生成链表
linkedList_double produceList_double(const int A[], int N)
{
	//1- 生成空表
	linkedList_double header = produceEmptyList_double();

	//2- 遍历数组，生成链表
	ptrToNode_double p_now = NULL;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			p_now = insert_x_double(A[i], header, header);
		}
		else
		{
			p_now = insert_x_double(A[i], header, p_now);
		}
	}

	return header;
}

// 测试是否为空表
//O(1)
int isEmptyList_double(linkedList_double L)
{
	return (L->next == NULL && L->previous == NULL);
}

// 测试是否为头节点
// Attention：定义header->previous = NULL; tailer->next = NULL
//O(1)
int isHeaderNode_double(ptrToNode_double p)
{
	return (p->previous == NULL);
}

// 测试是否为尾节点
// Attention：定义header->previous = NULL; tailer->next = NULL
//O(1)
int isTailerNode_double(ptrToNode_double p)
{
	return (p->next == NULL);
}

//获取链表长度，不包括表头
//O(N),N为链表长度
int getListLength_double(linkedList_double L)
{
	ptrToNode_double p = L->next;
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
ptrToNode_double find_x_double(int x, linkedList_double L)
{
	ptrToNode_double p = L->next;

	while (p != NULL && p->value != x)
	{
		p = p->next;
	}

	return p;
}

// 删除find到的第一个x，若无x，L不变；否则L自身改变，删除x
//O(N)
void delete_x_double(int x, linkedList_double L)
{
	ptrToNode_double p=L;

	//O(N)遍历list
	while(p != NULL)
	{
		if(p->value == x)
		{
			//begin delete, O(1)
			//1- next update, 注意检查是否为尾节点
			if (p->next != NULL)
			{
				p->next->previous = p->previous;
			}
			
			//2- previous update, 注意检查是否为头节点
			if (p->previous != NULL)
			{
				p->previous->next = p->next;
			}
			
			free(p);
			break;
		}
		else
		{
			p = p->next;
		}
	}
}

//删除链表，包括表头
//O(N)
void delete_L_double(linkedList_double L)
{
	ptrToNode_double p, tmpNode;
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
void printList_double(linkedList_double L)
{
	if (L->value != INT_MIN)
	{
		cout << "printList EROOR: L's header ERROR" << endl;
		return;
	}

	ptrToNode_double p = L->next;
	cout << "++++++++++++++++++++++++++" << endl;
	cout << "printList: " << endl;
	int listCount = 1;
	while (p != NULL)	//注意，不用next，直接当前p判断
	{
		cout << listCount << "-\tp->value: " << p->value << endl;
		cout << "\tp->previous: " << p->previous << endl;
		cout << "\tp->next: " << p->next << endl;

		p = p->next;
		listCount++;
	}
	cout << "++++++++++++++++++++++++++" << endl;
}
