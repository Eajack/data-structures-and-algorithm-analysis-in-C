/*
	Author: Eajack Lau
	Date: 2019/4/28
	Function:
		《数据结构与算法分析（C语言描述）》第五章
		散列（哈希表），method 2 & 3
*/
#include "hash_oa.h"
using namespace std;

enum kindOfEntry{FILLED=0, EMPTY};

struct hashNode_oa
{
	int value;
	enum kindOfEntry info;
};

struct hashTable_oa
{
	int tableSize;
	ptrToNode_oa header;
};

//find next prime of N
int nextPrime_oa(int N)
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

//the definition of hashFuntion
int hashFuntion_oa(int key, int modValue = 10)
{
	return (key%modValue);
}

//create Empty HashTable
ptrToHashTable_oa createEmptyHashTable_oa(int tableSize)
{
	ptrToHashTable_oa H = (ptrToHashTable_oa)malloc(sizeof(struct hashTable_oa));
	if(H == NULL)
	{
		cout << "createHashTable ERROR 1: malloc out of space!!!" << endl;
		return NULL;
	}
	H->tableSize = nextPrime_oa(tableSize);

	H->header = (ptrToNode_oa)malloc(sizeof(struct hashNode_oa) * H->tableSize);
	if(H->header == NULL)
	{
		cout << "createHashTable ERROR 2: malloc out of space!!!" << endl;
		return NULL;
	}

	for(int i=0; i<H->tableSize; i++)
	{
		H->header[i].value = INT_MIN;	//EMPTY symbol
		H->header[i].info = EMPTY;
	}
}

//delete H
void deleteHashTable_oa(ptrToHashTable_oa H)
{
	//1- free header
	free(H->header);

	//2- free H
	free(H);
}

// open addressing(detect method)
position detect_oa(int key, ptrToHashTable_oa H, position current_pos, int collisionNum, int detectFlag)
{
	if (detectFlag == 1)
	{
		while (H->header[current_pos].info != EMPTY and H->header[current_pos].value != key)
		{
			current_pos += (++collisionNum);
			if (current_pos >= H->tableSize)
				current_pos -= H->tableSize;
		}
		return current_pos;
	}
	else if (detectFlag == 2)
	{
		while (H->header[current_pos].info != EMPTY and H->header[current_pos].value != key)
		{
			current_pos += (2 * (++collisionNum) - 1);
			if (current_pos >= H->tableSize)
				current_pos -= H->tableSize;
		}
		return current_pos;
	}
	else
	{
		cout << "detect_oa ERROR: detectFlag = 1 or detectFlag = 2." << endl;
		return INT_MAX;
	}
}

//find key
position find_oa(int key, ptrToHashTable_oa H, int detectFlag)
{
	position current_pos = hashFuntion_oa(key, H->tableSize);
	int collisionNum = 0;
	current_pos = detect_oa(key, H, current_pos, collisionNum, detectFlag);
	//detect_oa(key, H, current_pos, 2);
	if(current_pos != INT_MAX and H->header[current_pos].value != INT_MAX)
	{
		return current_pos;
	}
	else
	{
		cout << "find_oa ERROR: current_pos == INT_MAX or H->header[current_pos].value == INT_MAX" << endl;
		return INT_MAX;
	}
}

//insert key
void insert_oa(int key, ptrToHashTable_oa H, int detectFlag)
{
	position p = find_oa(key, H, detectFlag);

	if(H->header[p].info != FILLED)
	{
		H->header[p].info = FILLED;
		H->header[p].value = key;
	}
}

//delete key, lazy
void delete_oa(int key, ptrToHashTable_oa H, int detectFlag)
{
	position p = find_oa(key, H, detectFlag);

	if(H->header[p].info == FILLED)
	{
		H->header[p].value = INT_MAX;	//delete symbol
		H->header[p].info = EMPTY;
	}
}

//create H
ptrToHashTable_oa createHashTable_oa(const int key[], int N, int tableSize, int detectFlag)
{
	ptrToHashTable_oa H = createEmptyHashTable_oa(tableSize);
	for(int i=0; i<N; i++)
	{
		int current_key = key[i];
		insert_oa(current_key, H, detectFlag);
	}

	return H;
}

//rehash
ptrToHashTable_oa rehash(ptrToHashTable_oa H, int detectFlag)
{
	int oldSize = H->tableSize;
	ptrToNode_oa oldTable = H->header;

	//1- resize
	H = createEmptyHashTable_oa(2 * oldSize);

	//2- scan, reinsert
	for(int i=0; i<oldSize; i++)
	{
		if(oldTable[i].info == FILLED)
			insert_oa(oldTable[i].value, H, detectFlag);
	}
	free(oldTable);
	
	return H;
}