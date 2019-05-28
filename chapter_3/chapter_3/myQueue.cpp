/*
	Author: Eajack Lau
	Date: 2019/4/17
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		队列，这里用了顺序queue，等价于链表了；
*/

#include "myQueue.h"
#include "linkedList.h"
#define MAX_QUEUE_LEN 10
using namespace std;

struct node
{
	int value;
	ptrToNode next;
};

//1- the link_list accomplishment of queue
int isEmpty_queue(queue_header Q)
{
	return (isEmptyList(Q));
}

int isFull_queue(queue_header Q)
{
	if(getListLength(Q) == MAX_QUEUE_LEN)
		return 1;
	else
		return 0;
}

queue_header createEmptyQueue()
{
	queue_header Q = produceEmptyList();
	return Q;
}

void deleteQueue(queue_header Q)
{
	delete_L(Q);
}

void enqueue(int x, queue_header Q)
{
	if(isFull_queue(Q))
	{
		cout << "enqueue ERROR: queue full!" << endl;
		return;
	}

	ptrToNode p = Q->next;
	while (p != NULL)
	{
		if(isLastNode(p))
		{
			ptrToNode trash_p = insert_x(x, Q, p);
			break;
		}
		else
		{
			p = p->next;
		}
	}
}

int dequeue(queue_header Q)
{
	ptrToNode p = Q->next;
	Q->next = p->next;
	int dequeue_value = p->value;
	free(p);

	return dequeue_value;
}

queue_header createQueue(const int A[], int N)
{
	queue_header q = produceList(A, N);
	return q;
}

void print_queue(queue_header Q)
{
	printList(Q);
}