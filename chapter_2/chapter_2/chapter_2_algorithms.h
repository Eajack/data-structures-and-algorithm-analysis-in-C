/*
	Author: Eajack Lau
	Date: 2019/3/28
	Function:
		《数据结构与算法分析（C语言描述）》第二章
*/
#include <iostream>
using namespace std;

#ifndef CHAPTER_2_ALGORITHMS
#define CHAPTER_2_ALGORITHMS

// 1- 最大子序列和问题
class solve_maxSubsequence
{
	public:
		//functions
		int method_1(const int A[], int N);//method 1: O(N^3)
		int method_2(const int A[], int N);//method 2: O(N^2)
		int method_3(const int A[], int N);//method 3: O(N*logN)
		int method_4(const int A[], int N);//method 4: O(N)
};

//2- 二分法查找
int binarySearch(const int sortedAscendingA[], int targetNum, int N);

//3- gcd
unsigned int gcd(unsigned int M, unsigned int N);

//4- 幂运算
long int Pow(long int X,unsigned int N);

#endif
