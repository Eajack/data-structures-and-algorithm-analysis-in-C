/*
	Author: Eajack Lau
	Date: 2019/4/28
	Function:
		《数据结构与算法分析（C语言描述）》第五章
		散列（哈希表），method 2 & 3
*/
#include <iostream>
#include <climits>

typedef unsigned int index;
typedef index position;

struct hashNode_oa;
struct hashTable_oa;
typedef struct hashNode_oa *ptrToNode_oa;
typedef struct hashTable_oa *ptrToHashTable_oa;

//2- method 2: open addressing
//	method 3(omitted) => double hash, P122, hash(i) = hash(i-1) + i * hash_2(i)
int nextPrime_oa(int N);
int hashFuntion_oa(int key, int modValue);
ptrToHashTable_oa createEmptyHashTable_oa(int tableSize);
void deleteHashTable_oa(ptrToHashTable_oa H);
position detect_oa(int key, ptrToHashTable_oa H, position current_pos, int collisionNum, int detectFlag);
position find_oa(int key, ptrToHashTable_oa H, int detectFlag);
void insert_oa(int key, ptrToHashTable_oa H, int detectFlag);
void delete_oa(int key, ptrToHashTable_oa H, int detectFlag);
ptrToHashTable_oa createHashTable_oa(const int key[], int N, int tableSize, int detectFlag);
ptrToHashTable_oa rehash(ptrToHashTable_oa H, int detectFlag);