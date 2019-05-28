/*
	Author: Eajack Lau
	Date: 2019/4/17
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		课后习题
*/
#include "linkedList.h"
#include "linkedList_circle.h"
using namespace std;

struct node
{
	int value;
	ptrToNode next;
};

struct node_circle
{
	ptrToNode_circle previous;
	int value;
	ptrToNode_circle next;
};

//3.2
void printLots(linkedList L, linkedList P)
{
	ptrToNode l = NULL;
	ptrToNode p = P->next;
	int p_index = 0, p_index_buffer = 0;

	while(p != NULL)
	{
		p_index_buffer = p->value;
		p_index = p->value;
		l = L->next;
		while(--p_index)
		{
			l = l->next;
		}
		cout << "p_index(" << p_index_buffer << "): " << l->value << endl;
		p = p->next;
	}
}

void chapter32_test()
{
	cout << "================chapter32_test================" << endl;
	//1 create P&L
	int P_list[10] = {12,23,34,45,56,67,78,89,91,10};
	int L_list[4] = {1,3,5,7};
	linkedList L = produceList(P_list, 10);
	linkedList P = produceList(L_list, 4);

	//2- test
	printLots(L, P);
}

//3.3
// exchange p1 & p1+1
void exchange2NearPosition(int p1, linkedList L)
{
	if(p1 <= 0 or p1 >= getListLength(L))
	{
		cout << "exchange2Position ERROR: 0 < p1 < (length of L)" << endl;
		return;
	}

	//1- find addr of p1
	ptrToNode p1_previous = L, p1_node = L->next;
	while(--p1)
	{
		p1_previous = p1_node;
		p1_node = p1_node->next;
	}
	ptrToNode p1_next = p1_node->next;

	//2- exchange
	ptrToNode tmpNode = (ptrToNode)malloc(sizeof(struct node));
	if (tmpNode == NULL)
	{
		cout << "exchange2NearPosition ERROR: malloc out of space" << endl;
		return;
	}
	tmpNode->value = 0;	//trash
	tmpNode->next = p1_next->next;	//buffer

	p1_previous->next = p1_next;
	p1_next->next = p1_node;
	p1_node->next = tmpNode->next;
	
	free(tmpNode);
}

void chapter33_test()
{
	cout << "================chapter33_test================" << endl;
	//1- create L
	int L_list[10] = {1,2,3,4,5,6,7,8,9,10};
	linkedList L = produceList(L_list, 10);

	//2- test
	printList(L);
	exchange2NearPosition(4, L);
	printList(L);
}

//3.4
// get intersection of L1&L2, i.e. both the position and value are the same
void getIntersection(linkedList L1, linkedList L2)
{
	//1- get len & pre
	int L1_len = getListLength(L1), L2_len = getListLength(L2);
	int len = ((L1_len >= L2_len) ? L2_len : L1_len);
	ptrToNode l1 = L1->next, l2 = L2->next;
	cout << "getIntersection: " << endl;

	//2- get through the list
	int len_count = 1;
	while(len)
	{
		if(l1->value == l2->value)
			cout << "\tposition(" << len_count << "): " << l1->value << endl;
		l1 = l1->next, l2 = l2->next;
		len--;
		len_count++;
	}
}

// get union of L1&L2, i.e. if both the position and value are not the same, cout value
void getUnion(linkedList L1, linkedList L2)
{
	//1- get len & pre
	int L1_len = getListLength(L1), L2_len = getListLength(L2);
	int len = ((L1_len >= L2_len) ? L1_len : L2_len);
	ptrToNode l1 = L1->next, l2 = L2->next;
	cout << "getUnion: " << endl;

	//2- get through the list
	int l1_value = 0, l2_value = 0;
	while(len)
	{
		if(l1 == NULL)
			l1_value = INT_MIN;
		else
			l1_value = l1->value;

		if(l2 == NULL)
			l2_value = INT_MIN;
		else
			l2_value = l2->value;

		if(l1_value == INT_MIN and l2_value != INT_MIN)
			cout << " " << l2_value;
		else if(l1_value != INT_MIN and l2_value == INT_MIN)
			cout << " " << l1_value;
		else if(l1_value == INT_MIN and l2_value == INT_MIN)
			break;
		else if(l1_value != l2_value)
			cout << " " << l1_value << " " << l2_value;
		else
			cout << " " << l1_value;

		if(l1 != NULL)
			l1 = l1->next;
		if(l2 != NULL)
			l2 = l2->next;
		len--;
	}
}

void chapter34_test()
{
	cout << "================chapter34_test================" << endl;
	//getIntersection
	//1- create L
	int L1_list[10] = {1,2,3,4,5,6,7,8,9,10}, L2_list[5] = {1,2,30,41,5};
	linkedList L1 = produceList(L1_list, 10), L2 = produceList(L2_list, 5);

	//2- test
	getIntersection(L1, L2);

	//getUnion
	getUnion(L1, L2);
}

//josephus problem
void josephus(unsigned int N, unsigned int M)
{
	cout << "===================josephus circle Problem===================" << endl;

	//circle link accomplishment
	//step 1
	//produce circle list
	int* A = (int *)malloc(N * sizeof(int));
	for(int i=0; i<N; i++)
	{
		A[i] = i+1;
	}
	linkedList_circle josephus_header = produceList_circle(A, N);

	//step 2
	// josephus algorithm
	// O(N*M)
	int start_index = 1;
	ptrToNode_circle ptr_now = josephus_header->next, ptr_now_buffer = josephus_header->next;
	cout << "josephus dead:";
	while(getListLength_circle(josephus_header) != 1)
	{
		int M_buffer = M;

		//start 1 round
		//(1) get through M times
		while(--M_buffer >= 0)
		{
			ptr_now = ptr_now->next;
		}
		cout << ptr_now->value << ", ";

		//(2) ptr_now buffer
		ptr_now_buffer = ptr_now->next;

		//(3) delete ptr_now
		delete_px_circle(ptr_now, josephus_header);

		//(4) update ptr_now
		ptr_now = ptr_now_buffer;
	}

	cout << "\njosephus live: " << josephus_header->next->value << endl;
}

void chapter310_test()
{
	cout << "\n================chapter310_test================" << endl;
	josephus(10, 2);
}

// reverse a list, O(N)
void reverseList(linkedList L)
{
	ptrToNode L_buffer = L, ptr_last = NULL;
	ptrToNode p_now = L, p_next = L->next, tmpNode;
	while(p_next != NULL)
	{
		if(p_now->value != INT_MIN)
		{
			tmpNode = p_next->next;
			p_next->next = p_now;
			p_now = p_next;
			p_next = tmpNode;
		}
		else
		{
			p_now = p_next;
			tmpNode = p_next->next;
			p_next->next = NULL;
			p_next = tmpNode;
		}
	}

	//update L
	L_buffer->next = p_now;
}

void chapter312_test()
{
	cout << "================chapter312_test================" << endl;
	int L_list[10] = {1,2,3,4,5,6,7,8,9,10};
	linkedList L = produceList(L_list, 10);

	printList(L);
	reverseList(L);
	printList(L);
}