/*
	Author: Eajack Lau
	Date: 2020.6.15
	Function:
		链表类实现
*/

#include <iostream>
#include "ListEL.h"
using namespace std;


//成员函数定义
SingleList::SingleList(int val){
	head = new SingleListNode(val);
}

SingleList::SingleList()
{
	head = new SingleListNode();
}

SingleList::~SingleList()
{
}


void SingleList::produceList(const int A[], int size){
	SingleListNode* dummy = new SingleListNode(0);
	SingleListNode* cur = dummy;
	for(int i=0; i<size; i++){
		cur->next = new SingleListNode(A[i]);
		cur = cur->next;
	}
	head = dummy->next;
}

int SingleList::size() {
	if (!head) {
		return 0;
	}

	SingleListNode* cur = head;
	int len = 0;
	while (cur) {
		cur = cur->next;
		len++;
	}
	return len;
}

bool SingleList::find(int x) {
	SingleListNode* cur = head;
	while (cur && cur->val != x) {
		cur = cur->next;
	}
	return (cur != nullptr);
}

void SingleList::delete_withIndex(int index) {
	//1
	int len = size();
	if (len <= index) {
		return;
	}

	//2
	if (index == 0) {
		SingleListNode* cur = head;
		head = head->next;
		delete cur;
	}
	else {
		SingleListNode* cur = head;
		SingleListNode* next = head->next;
		for (int i = 1; i < index; i++) {
			cur = next;
			next = next->next;
		}
		cur->next = next->next;
		delete next;
	}
}

void SingleList::insert_x_beforeIndex(int x, int index) {
	int len = size();
	if (index < 0 || index >= len) {
		return;
	}

	//1
	if (index == 0) {
		SingleListNode* newHead = new SingleListNode(x);
		newHead->next = head;
		head = newHead;
	}
	else {
		SingleListNode* cur = head;
		SingleListNode* next = head->next;
		for (int i = 1; i < index; i++) {
			cur = next;
			next = next->next;
		}
		cur->next = new SingleListNode(x);
		cur->next->next = next;
	}
}

void SingleList::clear() {
	SingleListNode* cur = head;
	while (cur) {
		SingleListNode* temp = cur->next;
		delete cur;
		cur = temp;
	}
}

void SingleList::print() {
	SingleListNode* cur = head;
	while (cur->next) {
		cout << cur->val << " -> ";
		cur = cur->next;
	}
	cout << cur->val << endl;
}