/*
	Author: Eajack Lau
	Date: 2020.6.21
	Function:
		哈希表实现
*/

#include <iostream>
#include "HashMapEL.h"
using namespace std;


//1 方法1
// 解决冲突方法1
//	分离链接法（separate chainning method）：将hashval相同的，保存在1个链表数组中
HashMap1::HashMap1()
{
	hashMap1 = {};
}

HashMap1::HashMap1(int size)
{
	hashMap1 = {};
	int mapSize = nextPrime(size);
	for (int i = 1; i <= mapSize; i++) {
		vector<HashNode1> temp;
		hashMap1.push_back(temp);
	}
}

HashMap1::HashMap1(int size, const int keys[], int N)
{
	//1
	HashMap1(size);

	//2
	for (int i = 0; i<N; i++) {
		insert(keys[i]);
	}
}

HashMap1::~HashMap1()
{
}

int HashMap1::nextPrime(int N)
{
	for (int i = N + 1; i<2 * N; i++) {
		//judge if i is a prime
		if (i < 2)
			continue;
		for (int j = 2; j*j < i; j++) {
			if (i%j == 0) {
				continue;
			}
		}

		return i;
	}
}

int HashMap1::hashFuntion(int key)
{
	if (hashMap1.empty()) {
		return -1;
	}
	else {
		return (key%hashMap1.size());
	}
}

int HashMap1::find(int key)
{
	//1
	int key_index = hashFuntion(key);
	if (key_index == -1) {
		return -1;
	}
	else {
		vector<HashNode1> tempList = hashMap1[key_index];
		for (HashNode1 node : tempList) {
			if (node.val == key) {
				return key_index;
			}
		}
		return -1;
	}
}

void HashMap1::insert(int key)
{
	//1 当发现哈希表中没有key，才插入
	int index = find(key);
	if (index == -1) {
		int keyIndex = hashFuntion(key);
		hashMap1[keyIndex].push_back(HashNode1(key));
	}
}

void HashMap1::erase(int key)
{
	//1
	int keyIndex = find(key);
	if (keyIndex != -1) {
		int eraseIndex = -1;
		for (int i = 0; i < hashMap1[keyIndex].size(); i++) {
			if (hashMap1[keyIndex][i].val == key) {
				eraseIndex = i;
				break;
			}
		}

		if (eraseIndex != -1) {
			hashMap1[keyIndex].erase(hashMap1[keyIndex].begin() + eraseIndex);
		}
	}

}

int HashMap1::size()
{
	return hashMap1.size();
}

void HashMap1::clear()
{
	hashMap1.clear();
}

HashMap2::HashMap2()
{
	hashMap2 = {};
}

HashMap2::HashMap2(int mapSize)
{
	size = nextPrime(mapSize);
	hashMap2 = vector<HashNode2>(size, HashNode2(0));
}

HashMap2::HashMap2(int mapSize, const int keys[], int N, enum detectFlag flag)
{
	//1
	HashMap2(mapSize);

	//2
	for (int i = 0; i<N; i++) {
		insert(keys[i], flag);
	}
}

HashMap2::~HashMap2()
{
}

int HashMap2::nextPrime(int N)
{
	for (int i = N + 1; i<2 * N; i++) {
		//judge if i is a prime
		if (i < 2)
			continue;
		for (int j = 2; j*j < i; j++) {
			if (i%j == 0) {
				continue;
			}
		}

		return i;
	}
}

int HashMap2::hashFuntion(int key)
{
	if (hashMap2.empty()) {
		return -1;
	}
	else {
		return (key%hashMap2.size());
	}
}

int HashMap2::detect(int key, int currentPos, int collisionNum, enum detectFlag flag)
{
	while (hashMap2[currentPos].info == FILLED || hashMap2[currentPos].val == key) {
		if (collisionNum >= size) {
			return -1;
		}
		switch (flag) {
			//（1）线性探查
			case LINE_DETECT: {
				currentPos += (2 * (++collisionNum) - 1);
				break;
			}
			//（2）二次探查
			case TWICE_DETECT: {
				currentPos += (2 * (++collisionNum) - 1);
				break;
			}
			default: {
				break;
			}
		}
		if (currentPos >= size) {
			currentPos -= size;
		}
	}
	return currentPos;
}

int HashMap2::find(int key, enum detectFlag flag)
{
	int currentPos = hashFuntion(key);
	int collisionNum = 0;
	currentPos = detect(key, currentPos, collisionNum, flag);
	if (currentPos != -1 && hashMap2[currentPos].info == FILLED) {
		return currentPos;
	}
	else {
		cout << "find ERROR: currentPos == -1 or hashMap2[currentPos].info == FILLED" << endl;
		return -1;
	}
}

void HashMap2::insert(int key, enum detectFlag flag)
{
	int keyIndex = find(key, flag);
	if (keyIndex != -1 && hashMap2[keyIndex].info == EMPTY) {
		hashMap2[keyIndex].info = FILLED;
		hashMap2[keyIndex].val = key;
	}
}

void HashMap2::erase(int key, enum detectFlag flag)
{
	int keyIndex = find(key, flag);
	if (keyIndex != -1 && hashMap2[keyIndex].info == FILLED) {
		hashMap2[keyIndex].val = INT_MAX;	//删除标志，懒惰删除
		hashMap2[keyIndex].info = EMPTY;
	}
}

void HashMap2::clear()
{
	size = 0;
	hashMap2.clear();
}
