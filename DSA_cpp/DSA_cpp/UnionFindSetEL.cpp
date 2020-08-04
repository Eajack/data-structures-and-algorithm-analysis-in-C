/*
	Author: Eajack Lau
	Date: 2020/6/25
	Function:
		并查集
*/


#include "UnionFindSetEL.h"
using namespace std;


UnionFindSet::UnionFindSet(int NUMSETS)
{
	unionFindSet = vector<int>(NUMSETS, 0);
}

UnionFindSet::~UnionFindSet()
{
}

// union 2 sets, union-any
void UnionFindSet::union1(int root1, int root2)
{
	//超过size
	if (root1 >= unionFindSet.size()) {
		return;
	}
	unionFindSet[root1] = root2;
}

//union 2 sets, union-by-size
void UnionFindSet::union2(int root1, int root2)
{
	//超过size
	if (root1 >= unionFindSet.size()) {
		return;
	}

	if (root1 < root2) {
		unionFindSet[root1] = root2;
	}
	else {
		unionFindSet[root2] = root1;
	}
}

//union 2 sets, union-by-height
void UnionFindSet::union3(int root1, int root2)
{
	//超过size
	if (root1 >= unionFindSet.size()) {
		return;
	}

	if (unionFindSet[root1] < unionFindSet[root2])
		unionFindSet[root1] = root2;
	else {
		if (unionFindSet[root1] == unionFindSet[root2]) {
			unionFindSet[root1]--;
		}	
		unionFindSet[root2] = root1;
	}
}

int UnionFindSet::find(int val)
{
	if (unionFindSet[val] <= 0) {
		return val;
	}
	else {
		return find(unionFindSet[val]);
	}
}
