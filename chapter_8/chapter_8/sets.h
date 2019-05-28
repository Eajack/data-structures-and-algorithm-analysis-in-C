/*
	Author: Eajack Lau
	Date: 2019/5/8
	Function:
		《数据结构与算法分析（C语言描述）》第八章
		不相交集
*/
#include <iostream>
#include <climits>
#define NUMSETS 8

int* createEmptySet();
void union1_set(int* s, int root1, int root2);
void union2_set(int* s, int root1, int root2);
void union3_set(int* s, int root1, int root2);
int find_set(int* s, int value);