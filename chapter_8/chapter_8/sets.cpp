/*
	Author: Eajack Lau
	Date: 2019/5/8
	Function:
		《数据结构与算法分析（C语言描述）》第八章
		不相交集
*/
#include "sets.h"
using namespace std;

//create empty set
int* createEmptySet()
{
	int* s = (int*)malloc(sizeof(int) * NUMSETS);
	for(int i=NUMSETS; i>0; i--)
	{
		s[i] = 0;
	}
	return s;
}

//union 2 sets, union-any
void union1_set(int* s, int root1, int root2)
{
	s[root2] = root1;
}

//union 2 sets, union-by-size
void union2_set(int* s, int root1, int root2)
{
	if(root1 < root2)
	{
		s[root1] = root2;
	}
	else
	{
		s[root2] = root1;
	}
}

//union 2 sets, union-by-height
//P205
void union3_set(int* s, int root1, int root2)
{
	if(s[root1] < s[root2])
		s[root1] = root2;
	else
	{
		if(s[root1] == s[root2])
			s[root1]--;
		s[root2] = root1;
	}
}


//find value in s
int find_set(int* s, int value)
{
	if(s[value] <= 0)
		return value;
	else
		return find_set(s, s[value]);
}