/*
	Author: Eajack Lau
	Date: 2019/4/18
	Function:
		《数据结构与算法分析（C语言描述）》第四章
		树
		1- 
*/

#include "tree.h"
using namespace std;

//
void test1()
{
	//1- build_expressionTree test
	int A[] = { 'a','b','+','c','d','e','+','*','*' };
	int N = sizeof(A)/sizeof(A[0]);
	tree_bi T_expression = build_expressionTree(A, N);

	//2- search tree test
	int B[] = {3,1,4,6,9,2,5,7};
	int M = sizeof(B)/sizeof(B[0]);
	searchTree ST = create_ST(B, M);

	//print test
	cout << "=======================preorder print==========================" << endl;
	print_ST(ST, 0, 1);
	cout << "===========================================================" << endl;

	cout << "=======================infix print==========================" << endl;
	print_ST(ST, 0, 2);
	cout << "===========================================================" << endl;

	cout << "=======================post print==========================" << endl;
	print_ST(ST, 0, 3);
	cout << "===========================================================" << endl;

	//delete test
	delete_ST(3,ST);
	cout << "=======================DELETE preorder print==========================" << endl;
	print_ST(ST, 0, 1);
	cout << "===========================================================" << endl;
}

int main()
{
	cout << "====================Chapter 4: Tree====================" << endl;
	cout << "====================Test 1====================" << endl;
	test1();

	return 0;
}