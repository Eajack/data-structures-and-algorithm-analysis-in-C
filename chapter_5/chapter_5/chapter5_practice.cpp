/*
	Author: Eajack Lau
	Date: 2019/4/25
	Function:
		《数据结构与算法分析（C语言描述）》第五章
		散列（哈希表）,习题
*/

#include "chapter5_practice.h"
using namespace std;

//5.1
void chapter5_1()
{
	int A[] = {4371,1323,6173,4199,4344,9679,1989};
	int N = (sizeof(A)) / (sizeof(A[0]));

	//debug see
	ptrToHashTable_seq H_seq = createHashTable_seq(A, N, 10);
	ptrToHashTable_oa H_oa_1 = createHashTable_oa(A, N, 10, 1);//linear
	ptrToHashTable_oa H_oa_2 = createHashTable_oa(A, N, 10, 2);//Square
	ptrToHashTable_oa H_oa_1_re = rehash(H_oa_1, 1);
	ptrToHashTable_oa H_oa_2_re = rehash(H_oa_2, 2);
}