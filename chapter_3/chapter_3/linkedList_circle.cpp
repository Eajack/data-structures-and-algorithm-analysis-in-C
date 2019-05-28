/*
	Author: Eajack Lau
	Date: 2019/3/29
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		单链表, int型
*/

#include "linkedList_circle.h"
using namespace std;

//1- 循环链表实现
// Attention: 
//		1- 带表头，循环链表是双链表特例
//		2- 逻辑上循环则无前后，但为方便，生成链表时分前后。但是无法检测头&尾节点
//		3- 区分：表头L，外部节点，不算是链表部分；头节点&尾节点，链表部分；
// 书本P38
struct node_circle
{
	ptrToNode_circle previous;
	int value;
	ptrToNode_circle next;
};

//生成空表，即仅有表头
//O(1)
linkedList_circle produceEmptyList_circle()
{
	ptrToNode_circle tmpNode = (ptrToNode_circle)malloc(sizeof(struct node_circle));
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
ptrToNode_circle insert_x_circle(int x, linkedList_circle L, ptrToNode_circle p)
{
	// Attention: 不是sizeof(struct node_circle*)，或sizeof(ptrToNode_circle)，
	//			这是为指针malloc
	ptrToNode_circle tmpNode = (ptrToNode_circle)malloc(sizeof(struct node_circle));
	if (tmpNode == NULL)
	{
		cout << "insert_x ERROR: malloc out of space" << endl;
		return NULL;
	}
	//循环链表插入分2种情况
	//1- 空表、非空表p==L、其余情况
	if(isEmptyList_circle(L))//空表
	{
		// 闭环指向自身
		tmpNode->value = x;
		tmpNode->previous = tmpNode;
		tmpNode->next = tmpNode;

		//外部连表头L
		p->next = tmpNode;
	}
	else if(p==L)
	{
		ptrToNode_circle header = L->next;

		tmpNode->value = x;
		tmpNode->next = header;
		tmpNode->previous = header->previous;

		//原尾节点update
		header->previous->next = tmpNode;
		//原头节点update
		header->previous = tmpNode;

		//表头update
		L->next = tmpNode;

	}
	else//其余情况
	{
		tmpNode->value = x;
		tmpNode->previous = p;
		tmpNode->next = p->next;

		//previou update(p)
		p->next = tmpNode;
		//next update
		tmpNode->next->previous = tmpNode;
	}

	return tmpNode;
}

//生成链表
linkedList_circle produceList_circle(const int A[], int N)
{
	//1- 生成空表
	linkedList_circle header = produceEmptyList_circle();

	//2- 遍历数组，生成链表
	ptrToNode_circle p_now = NULL;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			p_now = insert_x_circle(A[i], header, header);
		}
		else
		{
			p_now = insert_x_circle(A[i], header, p_now);
		}
	}

	return header;
}

// 测试是否为空表，即检查是否为表头
//O(1)
int isEmptyList_circle(linkedList_circle L)
{
	return (L->next == NULL && L->previous == NULL);
}

//获取链表长度，不包括表头
//O(N),N为链表长度
// 检测原理：循环1周，检测回到头地址break
int getListLength_circle(linkedList_circle L)
{
	if(isEmptyList_circle(L))	//空表，仅表头
		return 0;

	ptrToNode_circle header = L->next;
	ptrToNode_circle p_countBegin = L->next->next;
	int len = 1;	//因为从节点2开始计算，即默认len

	while (p_countBegin != header)
	{
		len++;
		p_countBegin = p_countBegin->next;
	}
	return len;
}

// 找到value = x的节点地址
//O(N),N为链表长度
// 检测原理：循环1周，遍历
ptrToNode_circle find_x_circle(int x, linkedList_circle L)
{
	if(isEmptyList_circle(L))
	{
		cout << "++++++++++++++++++++++++++" << endl;
		cout << "Empty List" << endl;
		cout << "++++++++++++++++++++++++++" << endl;
		return NULL;
	}

	if(L->next->value == x)	//头节点需要独立检测
		return L->next;

	ptrToNode_circle header = L->next;
	ptrToNode_circle p = L->next->next;	//从节点2开始找

	while (p != header && p->value != x)
	{
		p = p->next;
	}

	if(p != header)
		return p;
	else
		return NULL;	// 代表没找到
}

// 删除find到的第一个x，若无x，L不变；否则L自身改变，删除x
//O(1)，不考虑find_x_circle子函数
void delete_x_circle(int x, linkedList_circle L)
{
	ptrToNode_circle p_x = find_x_circle(x, L);
	ptrToNode_circle header = L->next;

	if(p_x != NULL)
	{
		//delete
		if(p_x == header)
		{
			//update
			L->next = p_x->next;	//表头
			p_x->previous->next = p_x->next;	//previous
			p_x->next->previous = p_x->previous;	//next
			free(p_x);
		}
		else
		{
			p_x->previous->next = p_x->next;	//previous
			p_x->next->previous = p_x->previous;	//next
			free(p_x);
		}
	}
}

// 删除ptrToNode_circle = p_x节点
void delete_px_circle(ptrToNode_circle p_x, linkedList_circle L)
{
	//ptrToNode_circle p_x = find_x_circle(x, L);
	ptrToNode_circle header = L->next;

	if(p_x != NULL)
	{
		//delete
		if(p_x == header)
		{
			//update
			L->next = p_x->next;	//表头
			p_x->previous->next = p_x->next;	//previous
			p_x->next->previous = p_x->previous;	//next
			free(p_x);
		}
		else
		{
			p_x->previous->next = p_x->next;	//previous
			p_x->next->previous = p_x->previous;	//next
			free(p_x);
		}
	}
}

//删除链表，包括表头
// 循环链表delete_L，和普通链表有点不同，需要先转为有NULL链表
//O(N)
void delete_L_circle(linkedList_circle L)
{
	if(isEmptyList_circle(L))
	{
		free(L);	// 释放表头
		return;
	}

	ptrToNode_circle header, tmpNode;
	header = L->next;
	L->next = NULL;
	free(L);	// 释放表头

	//先转为有NULL链表
	header->next->next = NULL;	//尾节点NULL
	header->previous = NULL;	// 头节点NULL

	//此时循环链表 => 双链表，调用双链表delete_L同样代码
	//由于声明分隔了double, circle和单链表，这里直接复制，双链表delete_L代码
	while (header != NULL)	//注意，不用next，直接当前p判断
	{
		tmpNode = header->next;
		free(header);
		header = tmpNode;
	}
}

// 打印链表
void printList_circle(linkedList_circle L)
{
	if (L->value != INT_MIN)
	{
		cout << "printList EROOR: L's header ERROR" << endl;
		return;
	}

	ptrToNode_circle header = L->next;
	if(header == NULL)
	{
		cout << "++++++++++++++++++++++++++" << endl;
		cout << "Empty List" << endl;
		cout << "++++++++++++++++++++++++++" << endl;
		return;
	}

	ptrToNode_circle p = L->next->next;	//循环同上理，从节点2开始
	cout << "++++++++++++++++++++++++++" << endl;
	cout << "printList: " << endl;
	cout << "1-\theader->value: " << header->value << endl;
	cout << "\theader->previous: " << header->previous << endl;
	cout << "\theader->next: " << header->next << endl;

	int listCount = 2;
	while (p != header)	//注意，不用next，直接当前p判断
	{
		cout << listCount << "-\tp->value: " << p->value << endl;
		cout << "\tp->previous: " << p->previous << endl;
		cout << "\tp->next: " << p->next << endl;

		p = p->next;
		listCount++;
	}
	cout << "++++++++++++++++++++++++++" << endl;
}
