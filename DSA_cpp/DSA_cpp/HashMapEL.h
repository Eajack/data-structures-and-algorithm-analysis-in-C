/*
	Author: Eajack Lau
	Date: 2020.6.21
	Function:
		哈希表实现
*/
#pragma once
#include <vector>
#include "ListEL.h"


//1 方法1
// 解决冲突方法1 基于链表
//	分离链接法（separate chainning method）：将hashval相同的，保存在1个链表数组中
class HashMap1
{
public:
	HashMap1();
	HashMap1(int size);
	// 建表，O(N*M)
	HashMap1(int size, const int keys[], int N);
	~HashMap1();

	// N为链表个数，M为哈希表大小size
	//1 下一个质数，用来更新size，O(N^1.5)
	int nextPrime(int N);
	//2 自定义哈希函数，O(1)
	int hashFuntion(int key);
	//3 哈希表查找，O(N)（最坏）
	int find(int key);
	//4 哈希表插入，O(N)（最坏）
	void insert(int key);
	//5 哈希表删除，O(N)（最坏）
	void erase(int key);
	//6 获取哈希表size，O(1)
	int size();
	//7 哈希表清空，O(N)
	void clear();
private:
	std::vector<std::vector<HashNode1>> hashMap1;
};


//1 方法2
// 解决冲突方法2
//	开放定址法
enum kindOfEntry{
	EMPTY = 0,
	FILLED
};
struct HashNode2{
	int val;
	enum kindOfEntry info;
	HashNode2(int val) : val(val), info(EMPTY) {};
	HashNode2() : val(0), info(EMPTY) {};
};
enum detectFlag {
	LINE_DETECT = 1,
	TWICE_DETECT,
	//REHASS_DETECT
};


class HashMap2
{
public:
	HashMap2();
	HashMap2(int mapSize);
	// 建表，O(N)
	HashMap2(int mapSize, const int keys[], int N, enum detectFlag flag=LINE_DETECT);
	~HashMap2();

	//N为哈希表大小
	//1 下一个质数，用来更新size，O(N^1.5)
	int nextPrime(int N);
	//2 自定义哈希函数，O(1)
	int hashFuntion(int key);
	//3 哈希表查找，O(1)/O(N)（线性/二次）
	int detect(int key, int currentPos, int collisionNum, enum detectFlag flag = LINE_DETECT);
	int find(int key, enum detectFlag flag = LINE_DETECT);
	//4 哈希表插入，O(1)/O(N)（线性/二次）
	void insert(int key, enum detectFlag flag = LINE_DETECT);
	//5 哈希表删除，O(1)/O(N)（线性/二次）
	void erase(int key, enum detectFlag flag = LINE_DETECT);
	//6 哈希表清空，O(N)
	void clear();
private:
	int size;
	std::vector<HashNode2> hashMap2;
};