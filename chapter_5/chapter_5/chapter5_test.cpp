/*
	Author: Eajack Lau
	Date: 2019/4/25
	Function:
		《数据结构与算法分析（C语言描述）》第五章
		散列（哈希表）
*/

#include "hash_seq.h"
#include "hash_oa.h"
#include "chapter5_practice.h"
using namespace std;

//1- method 1 test
void test1()
{
	int key[] = {0, 1, 81, 4, 64, 25, 16, 36, 9, 49};
	ptrToHashTable_seq H = createHashTable_seq(key, 10, 10);
	ptrToNode_seq target_p = find_seq(25, H);
	// debug see
	//cout << H->tableSize << endl;
}

//2- method 2 test
void test2()
{
	int key[] = {0, 1, 81, 4, 64, 25, 16, 36, 9, 49};
	ptrToHashTable_oa H = createHashTable_oa(key, 10, 10, 1);//linear
	position target_p = find_oa(25, H, 1);
	delete_oa(25, H, 1);
	position target_p_1 = find_oa(25, H, 1);

	// debug see
	cout << target_p << " " << target_p_1 << endl;
}

//3- practice test
void test3()
{
	cout << "==========================chapter5_1==========================" << endl;
	chapter5_1();
	cout << "==============================================================" << endl;
}


int main()
{
	test1();
	test2();
	test3();
	return 0;
}