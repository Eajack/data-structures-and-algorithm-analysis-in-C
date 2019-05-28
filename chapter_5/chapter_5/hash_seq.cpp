/*
	Author: Eajack Lau
	Date: 2019/4/23
	Function:
		《数据结构与算法分析（C语言描述）》第五章
		散列（哈希表），method 1
*/

#include "hash_seq.h"
using namespace std;

//1- hash table
// 解决冲突方法1
//	分离链接法（separate chainning method）：将hashval相同的，保存在1个链表数组中
//  hash table(H) = linked lists array, with table headers as "linkedList.h"
struct listNode_seq
{
	int value;
	ptrToNode_seq next;
};

struct hashTable_seq
{
	int tableSize;		//the length of H
	List *listArray;	//the pointer of H
};

//find next prime of N
int nextPrime_seq(int N)
{
	for(int i=N+1; i<2*N; i++)
	{
		//judge if i is a prime
		if(i < 2)
			continue;
		for(int j=2; j*j < i; j++)
		{
			if(i%j == 0)
			{
				continue;
			}
		}

		return i;
	}
}

//the definition of hashFuntion_seq
int hashFuntion_seq(int key, int modValue = 10)
{
	return (key%modValue);
}

// create H[tableSize], only headers, save ptrToNode_seq(pointers)
ptrToHashTable_seq createEmptyHashTable_seq(int tableSize)
{
	ptrToHashTable_seq H;
	int i;

	H = (ptrToHashTable_seq)malloc(sizeof(struct hashTable_seq));
	if(H == NULL)
	{
		cout << "createEmptyHashTable_seq ERROR 1: malloc out of space" << endl;
		return NULL;
	}
	H->tableSize = nextPrime_seq(tableSize);	//find the next prime

	//allocate space for array, save pointers of headers
	H->listArray = (List *)malloc(sizeof(ptrToNode_seq) * (H->tableSize));
	if(H->listArray == NULL)
	{
		cout << "createEmptyTable_seq ERROR 2: malloc out of space" << endl;
		return NULL;
	}
	for(int i=0; i < H->tableSize; i++)
	{
		H->listArray[i] = (List)malloc(sizeof(struct listNode_seq));
		if(H->listArray[i] == NULL)
		{
			cout << "createEmptyTable_seq ERROR 3: malloc out of space" << endl;
			return NULL;
		}
		else
		{
			H->listArray[i]->value = INT_MIN;
			H->listArray[i]->next = NULL;
		}
	}

	return H;
}

//delete H
void deleteHashTable_seq(ptrToHashTable_seq H)
{
	//1- free listArray
	for(int i=0; i<H->tableSize; i++)
	{
		List L = H->listArray[i];
		ptrToNode_seq p = L->next;
		while(p != NULL)
		{
			free(p);
			p = p->next;
		}
		free(L);
	}
	free(H->listArray);
	//2- free H
	free(H);
}

//find H[key](dict as Python)
ptrToNode_seq find_seq(int key, ptrToHashTable_seq H)
{
	ptrToNode_seq p;
	List L = H->listArray[hashFuntion_seq(key)];
	p = L->next;
	while(p != NULL and p->value != key)
	{
		p = p->next;
	}
	return p;
}

//insert at the first place
void insert_seq(int key, ptrToHashTable_seq H)
{
	ptrToNode_seq p, tmpNode;
	List L;

	p = find_seq(key, H);
	if(p == NULL)//key 404
	{
		tmpNode = (ptrToNode_seq)malloc(sizeof(struct listNode_seq));
		if(tmpNode == NULL)
		{
			cout << "insert_seq ERROR: malloc out of space" << endl;
			return;
		}
		else
		{
			L = H->listArray[hashFuntion_seq(key)];
			tmpNode->next = L->next;
			tmpNode->value = key;
			L->next = tmpNode;
		}
	}
}

//create H
ptrToHashTable_seq createHashTable_seq(const int key[], int N, int tableSize)
{
	ptrToHashTable_seq H = createEmptyHashTable_seq(tableSize);
	for(int i=0; i<N; i++)
	{
		int current_key = key[i];
		insert_seq(current_key, H);
	}

	return H;
}
