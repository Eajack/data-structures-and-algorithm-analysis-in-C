#include "ListEL.h"
#include <climits>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

void ListEL::produceList(const int A[], int N)
{
	//1
	if (A == nullptr || N <= 0) {
		return;
	}

	//2
	ListNode* node = new ListNode(A[0]);
	head = node;
	for (int i = 1; i < N; i++) {
		ListNode* temp = new ListNode(A[i]);
		node->next = temp;
		node = node->next;
	}
}

int ListEL::find_index(int index)
{
	//1
	if (index < 0) {
		return INT_MIN;
	}

	//2
	ListNode* node = head;
	while (node && index > 0) {
		node = node->next;
		index--;
	}
	return (node==nullptr)?(INT_MIN):(node->val);
}

void ListEL::delete_index(int index)
{
	//1
	if (index < 0) {
		return;
	}

	//2
	if (index == 0) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	else {
		ListNode *pre = head, *cur = head->next;
		index--;
		while (cur && index > 0) {
			pre = pre->next;
			cur = cur->next;
		}

		if (cur != nullptr) {
			ListNode *temp = cur;
			cur = cur->next;
			pre->next = cur;
			delete temp;
		}
	}
}

int ListEL::getListLength()
{
	//1
	if (head == nullptr) {
		return 0;
	}

	//2
	int len = 0;
	ListNode* node = head;
	while (node) {
		len++;
		node = node->next;
	}
	return len;
}

ListNode * ListEL::findPrevious(int val)
{
	//1
	if (head == nullptr || head->next == nullptr) {
		return nullptr;
	}

	//2
	ListNode* pre = head, *cur = head->next, *temp = nullptr;
	if (pre->val == val) {
		return nullptr;
	}
	while (cur) {
		if (cur->val != val) {
			temp = cur;
			cur = cur->next;
			pre = temp;
		}
		else {
			break;
		}
	}

	return pre;
}

void ListEL::delete_val(int val)
{
	if (head == nullptr) {
		return;
	}

	//1
	ListNode *pre = head, *cur = head->next;

	//2
	if (pre->val == val) {
		head = cur;
		delete pre;
	}
	else {
		while (cur->val != val) {
			pre = pre->next;
			cur = cur->next;
		}
		if (cur != nullptr) {
			ListNode *temp = cur;
			cur = cur->next;
			pre->next = cur;
			delete temp;
		}
	}
}

void ListEL::delete_L()
{
	ListNode *node = head;
	while (node != nullptr) {
		ListNode *temp = node;
		node = node->next;
		delete temp;
	}
}

void ListEL::printList()
{
	ListNode *node = head;
	cout << "Print List" << endl;
	while (node != nullptr) {
		cout << node->val << " ";
	}
	cout << endl;
}

void ListEL::insert_val(int val, int index)
{
	if (head == nullptr || index < 0) {
		return;
	}

	ListNode *cur = head;
	while (index--) {
		cur = cur->next;
	}
	if (cur) {
		ListNode *temp = new ListNode(val), *next = cur->next;
		temp->next = next;
		cur->next = cur;
	}
}

ListNode * ListEL::find_val(int val)
{
	ListNode *node = head;
	while (node && node->val != val) {
		node = node->next;
	}
	return node;
}

