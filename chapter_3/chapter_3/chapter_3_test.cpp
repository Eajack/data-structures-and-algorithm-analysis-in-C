/*
	Author: Eajack Lau
	Date: 2019/3/29
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		1- 链表：单链表、双链表&循环链表
			head <=> 表头，headerNode <=> 头节点，tailerNode <=> 尾节点，
*/
#include "linkedList.h"
#include "linkedList_double.h"
#include "linkedList_circle.h"
#include "linkedList_application_sort.h"
#include "stack.h"
#include "stack_application.h"
#include "myQueue.h"
#include "chapter3_practice.h"
using namespace std;

//1- 单链表测试
void linkedList_test()
{
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	int N = 10;
	int emptyFlag, lastNodeFlag, len;
	ptrToNode x_ptr, findX_ptr, trashNode;

	//1.1- 生成空表&测试
	cout << "==============Test 1================" << endl;
	linkedList emptyList = produceEmptyList();
	printList(emptyList);
	emptyFlag = isEmptyList(emptyList);
	lastNodeFlag = isLastNode(emptyList);
	len = getListLength(emptyList);
	cout << "\t emptyFlag: " << emptyFlag << endl;
	cout << "\t lastNodeFlag: " << lastNodeFlag << endl;
	cout << "\t len: " << len << endl;

	x_ptr = find_x(5, emptyList);
	findX_ptr = findPrevious(5, emptyList);
	cout << "\t x_ptr: " << x_ptr << endl;
	cout << "\t findX_ptr: " << findX_ptr << endl;

	delete_x(10, emptyList);
	cout << "delete 10: " << endl;
	printList(emptyList);

	trashNode = insert_x(20, emptyList, emptyList);
	cout << "delete 20 after the head: " << endl;
	printList(emptyList);

	delete_L(emptyList);
	cout << "delete the whole list: " << endl;
	printList(emptyList);

	//1.2- 数组转成链表
	cout << "\n==============Test 2================" << endl;
	linkedList list_test = produceList(A, 10);
	printList(list_test);
	emptyFlag = isEmptyList(list_test);
	lastNodeFlag = isLastNode(list_test);
	len = getListLength(list_test);
	cout << "\t emptyFlag: " << emptyFlag << endl;
	cout << "\t lastNodeFlag: " << lastNodeFlag << endl;
	cout << "\t len: " << len << endl;

	x_ptr = find_x(5, list_test);
	findX_ptr = findPrevious(5, list_test);
	cout << "\t x_ptr: " << x_ptr << endl;
	cout << "\t findX_ptr: " << findX_ptr << endl;

	delete_x(10, list_test);
	cout << "delete 10: " << endl;
	printList(list_test);

	trashNode = insert_x(20, list_test, list_test);
	cout << "insert 20 after the head: " << endl;
	printList(list_test);

	delete_L(list_test);
	cout << "delete the whole list: " << endl;
	printList(list_test);	
}

//2- 双链表测试
void linkedList_double_test()
{
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	int N = 10;
	int emptyFlag, headerNodeFlag, tailerNodeFlag, len;
	ptrToNode_double x_ptr, trashNode;

	//1.1- 生成空表&测试
	cout << "==============Test 1================" << endl;
	linkedList_double emptyList = produceEmptyList_double();
	printList_double(emptyList);
	emptyFlag = isEmptyList_double(emptyList);
	headerNodeFlag = isHeaderNode_double(emptyList);
	tailerNodeFlag = isTailerNode_double(emptyList);
	len = getListLength_double(emptyList);
	cout << "\t emptyFlag: " << emptyFlag << endl;
	cout << "\t headerNodeFlag: " << headerNodeFlag << endl;
	cout << "\t tailerNodeFlag: " << tailerNodeFlag << endl;
	cout << "\t len: " << len << endl;

	x_ptr = find_x_double(5, emptyList);
	cout << "\t x_ptr: " << x_ptr << endl;

	delete_x_double(10, emptyList);
	cout << "delete 10: " << endl;
	printList_double(emptyList);

	trashNode = insert_x_double(20, emptyList, emptyList);
	cout << "insert 20 after the head: " << endl;
	printList_double(emptyList);

	delete_L_double(emptyList);
	cout << "delete the whole list: " << endl;
	printList_double(emptyList);

	//1.2- 数组转成链表
	cout << "\n==============Test 2================" << endl;
	linkedList_double list_test = produceList_double(A, 10);
	printList_double(list_test);
	emptyFlag = isEmptyList_double(list_test);
	headerNodeFlag = isHeaderNode_double(list_test);
	tailerNodeFlag = isTailerNode_double(list_test);
	len = getListLength_double(list_test);
	cout << "\t emptyFlag: " << emptyFlag << endl;
	cout << "\t headerNodeFlag: " << headerNodeFlag << endl;
	cout << "\t talierNodeFlag: " << tailerNodeFlag << endl;
	cout << "\t len: " << len << endl;

	x_ptr = find_x_double(5, list_test);
	cout << "\t x_ptr: " << x_ptr << endl;

	delete_x_double(10, list_test);
	cout << "delete 10: " << endl;
	printList_double(list_test);

	trashNode = insert_x_double(20, list_test, list_test);
	cout << "insert 20 after the head: " << endl;
	printList_double(list_test);

	delete_L_double(list_test);
	cout << "delete the whole list: " << endl;
	printList_double(list_test);	
}

//3- 循环链表测试
void linkedList_circle_test()
{
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	int N = 10;
	int emptyFlag, headerNodeFlag, tailerNodeFlag, len;
	ptrToNode_circle x_ptr, trashNode;

	//1.1- 生成空表&测试
	cout << "==============Test 1================" << endl;
	linkedList_circle emptyList = produceEmptyList_circle();
	printList_circle(emptyList);
	emptyFlag = isEmptyList_circle(emptyList);
	len = getListLength_circle(emptyList);
	cout << "\t emptyFlag: " << emptyFlag << endl;
	cout << "\t len: " << len << endl;

	x_ptr = find_x_circle(5, emptyList);
	cout << "\t x_ptr: " << x_ptr << endl;

	delete_x_circle(10, emptyList);
	cout << "delete 10: " << endl;
	printList_circle(emptyList);

	trashNode = insert_x_circle(20, emptyList, emptyList);
	cout << "insert 20 after the head: " << endl;
	printList_circle(emptyList);

	delete_L_circle(emptyList);
	cout << "delete the whole list: " << endl;
	printList_circle(emptyList);

	//1.2- 数组转成链表
	cout << "\n==============Test 2================" << endl;
	linkedList_circle list_test = produceList_circle(A, 10);
	printList_circle(list_test);
	emptyFlag = isEmptyList_circle(list_test);
	len = getListLength_circle(list_test);
	cout << "\t emptyFlag: " << emptyFlag << endl;
	cout << "\t len: " << len << endl;

	x_ptr = find_x_circle(5, list_test);
	cout << "\t x_ptr: " << x_ptr << endl;

	delete_x_circle(10, list_test);
	cout << "delete 10: " << endl;
	printList_circle(list_test);

	trashNode = insert_x_circle(20, list_test, list_test);
	cout << "insert 20 after the head: " << endl;
	printList_circle(list_test);

	delete_L_circle(list_test);
	cout << "delete the whole list: " << endl;
	printList_circle(list_test);
}

//4-链表应用：排序测试
void linkedList_application_sort_test()
{
	//1- 桶式排序测试
	int A[] = {1,2,45,32,10,33,41,51,78,61};
	int N = sizeof(A)/sizeof(A[0]), M = 100;
	int* sortedA = bucketSort(A, N, M, true);

	//2- 基数排序
	int B[] = {64,8,216,512,27,729,0,1,343,125};
	int N_B = sizeof(B)/sizeof(B[0]);
	radixSort(&B[0], N_B, true);
	cout << "\nRadix sort" << endl;
	for(int i=0; i<10; i++)
	{
		cout << B[i] << " ";
	}
}

//5- 链表测试
void stack_test()
{
	int A[] = {1,2,45,32,10,33,41,51,78,61};
	int N = sizeof(A)/sizeof(A[0]);

	//1- 空栈测试
	Stack S = produceEmptyStack();
	printStack(S);
	int S_emptyFlag = isEmptyStack(S);
	cout << "\t S_emptyFlag: " << S_emptyFlag << endl;
	push(20, S);
	printStack(S);
	pop(S);
	printStack(S);

	//2-建栈
	Stack S1 = produceStack(A,N);
	printStack(S1);
	int S1_emptyFlag = isEmptyStack(S1);
	cout << "\t S1_emptyFlag: " << S1_emptyFlag << endl;
	push(-102, S1);
	printStack(S1);
	pop(S1);
	printStack(S1);
	deleteStack(S1);
	printStack(S1);
}

//6- 栈应用测试
void stack_application_test()
{
	//1- balance symbols
	string inputText = "[[] {TEXT} (}{)]";
	string inputText_2 = "{[] {TEXT} ()}";
	int symbolFlag_1 = checkSymbols(inputText);
	int symbolFlag_2 = checkSymbols(inputText_2);

	cout << "============stack_application_test============" << endl;
	cout << "============1- balance symbols============" << endl;
	cout << "symbolFlag_1: " << symbolFlag_1 << endl;
	cout << "symbolFlag_2: " << symbolFlag_2 << endl;

	//2- postfix expression
	// only used for single char
	cout << "============2- postfix expression============" << endl;
	char postfixExpression_array[] = {'6','5','2','3','+','8','*','+','3','+','*'};
	int N = sizeof(postfixExpression_array) / sizeof(postfixExpression_array[0]);
	int result = calculatePostfix(postfixExpression_array, N);
	cout << "result: " << result << endl;

	//3- transfer infix 2 postfix
	cout << "============3- transfer infix 2 postfix============" << endl;
	char infixExpression_array[] = {'a','+','b','*','c','+','(','d','*','e','+','f',')','*','g'};
	int N1 = sizeof(infixExpression_array) / sizeof(infixExpression_array[0]);
	char* postfix_result = transfer_Infix2Postfix(infixExpression_array, N1);
	cout << "postfix result: ";
	for(int i=0; i < N1; i++)
		cout << postfix_result[i];
}

//7- queue test
void queue_test()
{
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	int N = 10;
	int emptyFlag, fullFlag;

	//1.1- test 1: empty queue 
	cout << "\n==============Test 1================" << endl;
	queue_header q_empty = createEmptyQueue();
	emptyFlag = isEmpty_queue(q_empty);
	fullFlag = isFull_queue(q_empty);
	cout << "emptyFlag: " << emptyFlag << endl;
	cout << "fullFlag: " << fullFlag << endl;
	print_queue(q_empty);

	//1.2- test 2: create queue
	cout << "==============Test 2================" << endl;
	queue_header q_creat = createQueue(A, N);
	emptyFlag = isEmpty_queue(q_creat);
	fullFlag = isFull_queue(q_creat);
	cout << "emptyFlag: " << emptyFlag << endl;
	cout << "fullFlag: " << fullFlag << endl;
	print_queue(q_creat);

	//enqueue
	enqueue(314, q_creat);
	print_queue(q_creat);

	//dequeue
	int de_int = dequeue(q_creat);
	print_queue(q_creat);

	//enqueue
	enqueue(314, q_creat);
	print_queue(q_creat);
}

void chapter3_practice()
{
	chapter32_test();
	chapter33_test();
	chapter34_test();
	chapter310_test();
	chapter312_test();
}


int main()
{
	//1- 单链表测试
	linkedList_test();

	//2- 双链表测试
	linkedList_double_test();

	//3- 循环链表测试
	linkedList_circle_test();

	//4-链表应用：排序测试
	linkedList_application_sort_test();

	//5-栈测试
	stack_test();

	//6- 栈应用测试
	stack_application_test();

	//7-队列ADT
	queue_test();

	//8- chapter 3 practice
	chapter3_practice();

	return 0;
}