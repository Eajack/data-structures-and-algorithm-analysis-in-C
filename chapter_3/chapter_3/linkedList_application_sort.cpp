/*
	Author: Eajack Lau
	Date: 2019/3/29
	Function:
		《数据结构与算法分析（C语言描述）》第三章
		链表应用，桶式排序&基数排序
*/

#include "linkedList_application_sort.h"
#include "linkedList.h"
using namespace std;

//桶式排序，默认升序
//N个整数，取值范围为0~M-1
//O(N+M)
int* bucketSort(const int A[], int N, int M, bool reverseFlag=false)
{
	int *buckets=new int[M]();
	int *sortedArray=new int[N]();
	int array_count = 0;

	for(int i=0; i<N; i++)
	{
		buckets[A[i]]++;
	}

	cout << "bucket sort: " << endl;
	if(reverseFlag)
	{
		for(int i=M-1; i>=0; i--)
		{
			if(buckets[i] != 0)
			{
				while(buckets[i])
				{
					sortedArray[array_count] = i;
					++array_count;
					--buckets[i];
					cout << i << " ";
				}
			}
		}
	}
	else
	{
		for(int i=0; i<M; i++)
		{
			if(buckets[i] != 0)
			{
				while(buckets[i])
				{
					sortedArray[array_count] = i;
					++array_count;
					--buckets[i];
					cout << i << " ";
				}
			}
		}
	}

	delete buckets, sortedArray;

	return sortedArray;
}

//基数排序

//O(digit)
int get_digit(int num, int digit)
{
	if(digit == 1)
		return (num%10);
	else
		return get_digit(num/10, digit-1);
}

//O( P*(N+N+M*N+N) ) <=> O(P*(N+M*N)) <=> O(PNM)
//real in book... O(P(N+M)), that is don't check digits again
void radixSort(int* A, int N, bool reverseFlag, int M)
{
	//N => array size, M => buckets num(0~M-1)

	//1- get the max in A
	int maxVal = 0;
	for(int i=0; i<N; i++)
	{
		if(A[i] > maxVal)
			maxVal = A[i];
	}

	//2- radix sort begin
	// radix <=> 'while' cost times
	// eg. maxVal = 312, then: radix = 3 <=> 'while' cost times = 3
	int digitPosition = 1, radixCount = 1;
	while(maxVal/digitPosition > 0)
	{
		int *buckets=new int[M](), *sorted_A=new int[N](), *digits=new int[N]();

		//3- get current digits
		for(int i=0; i<N; i++)
		{
			digits[i] = get_digit(A[i], radixCount);
		}

		//4- put in buckets
		for(int i=0; i<N; i++)
		{
			buckets[ digits[i] ] ++;
		}

		//5- go through buckets
		int sorted_count = 0;
		for(int j=0; j<M; j++)
		{
			if(buckets[j])
			{
				// go through digits,check if==buckets[j]
				for(int i=0; i<N; i++)
				{
					if(digits[i] == j)
					{
						sorted_A[sorted_count] = A[i];
						sorted_count++;
					}
				}
			}
		}

		//6- update A
		for(int i=0; i<N; i++)
		{
			A[i] = sorted_A[i];
		}

		delete buckets, sorted_A, digits;
		digitPosition = digitPosition*10;
		radixCount++;
 	}

 	//7- reverse, won't calculate into O(*)
 	//O(N)
 	if(reverseFlag)
 	{
		int *A_buffer = new int[N]();
 		for(int i=0; i<N; i++)
		{
			A_buffer[i] = A[i];
		}

		for(int i=N-1; i>=0; i--)
		{
			A[i] = A_buffer[N-1-i];
		}
		delete A_buffer;
 	}
}
