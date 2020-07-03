/*
	Author: Eajack Lau
	Date: 2020/6/25
	Function:
		²¢²é¼¯
*/

#pragma once
#include <vector>

class UnionFindSet
{
public:
	UnionFindSet(int NUMSETS = 8);
	~UnionFindSet();
	void union1(int root1, int root2);
	void union2(int root1, int root2);
	void union3(int root1, int root2);
	int find(int value);
private:
	std::vector<int> unionFindSet;
};