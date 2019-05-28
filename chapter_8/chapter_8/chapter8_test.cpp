/*
	Author: Eajack Lau
	Date: 2019/5/8
	Function:
		《数据结构与算法分析（C语言描述）》第八章
		不相交集
*/

#include "sets.h"
using namespace std;

int main()
{
	//debug see
	//1- create empty set
	int* set1 = createEmptySet();
	int* set2 = createEmptySet();
	int* set3 = createEmptySet();
	int value_index = find_set(set1, 5);

	union1_set(set1, 5, 6);
	union2_set(set2, 5, 6);
	union3_set(set3, 5, 6);

	return 0;
}