/*
	Author: Eajack Lau
	Date: 2019/4/23
	Function:
		《数据结构与算法分析（C语言描述）》第五章
		散列（哈希表），method 1
*/
#include <iostream>
#include <climits>

struct listNode_seq;
typedef struct listNode_seq *ptrToNode_seq;	//the List[i] pointer(i>0) 
typedef ptrToNode_seq List;	//the List[0] pointer

struct hashTable_seq;
typedef struct hashTable_seq *ptrToHashTable_seq;

//1- method 1: separate chainning method
int nextPrime_seq(int N);
int hashFuntion_seq(int key, int modValue);
ptrToHashTable_seq createEmptyHashTable_seq(int tableSize);
void deleteHashTable_seq(ptrToHashTable_seq H);
ptrToNode_seq find_seq(int key, ptrToHashTable_seq H);
void insert_seq(int key, ptrToHashTable_seq H);
ptrToHashTable_seq createHashTable_seq(const int key[], int N, int tableSize);