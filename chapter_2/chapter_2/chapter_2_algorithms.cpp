/*
	Author: Eajack Lau
	Date: 2019/3/28
	Function:
		《数据结构与算法分析（C语言描述）》第二章
*/

#include "chapter_2_algorithms.h"
using namespace std;

//1- 最大子序列和问题
// method_3 子函数
static int maxSubSum_method3(const int A[], int left, int right)
{
	int maxLeftSum, maxRightSum;
	int maxLeftBorderSum, maxRightBorderSum;
	int leftBorderSum, rightBorderSum;
	int center, i, maxSequenceSum;

	if(left == right)
		if(A[left] > 0)
			return A[left];
		else
			return 0;

	center = (left + right) / 2;
	maxLeftSum = maxSubSum_method3(A, left, center);
	maxRightSum = maxSubSum_method3(A, center+1, right);

	maxLeftBorderSum = 0;
	leftBorderSum = 0;
	for(i=center; i>=left; i--)
	{
		leftBorderSum += A[i];
		if(leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	maxRightBorderSum = 0;
	rightBorderSum = 0;
	for(i=center+1; i<=right; i++)
	{
		rightBorderSum += A[i];
		if(rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	// get the max in (maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum)
	maxSequenceSum = 0;
	maxSequenceSum = (maxLeftSum >= maxRightSum) ? maxLeftSum : maxRightSum;
	if(maxSequenceSum < maxLeftBorderSum+maxRightBorderSum)
		maxSequenceSum = maxLeftBorderSum + maxRightBorderSum;

	return maxSequenceSum;
}

int solve_maxSubsequence::method_1(const int A[], int N)
{
	int thisSum, maxSum, i, j, k;
	maxSum = 0;
	for(i=0; i<N; i++)
		for(j=i; j<N; j++)
		{
			thisSum = 0;
			for(k=i; k<=j; k++)
				thisSum += A[k];
			if(thisSum > maxSum)
				maxSum = thisSum;
		}

	return maxSum;
}

int solve_maxSubsequence::method_2(const int A[], int N)
{
	int thisSum, maxSum, i, j;
	maxSum = 0;
	for(i=0; i<N; i++)
	{
		thisSum = 0;
		for(j=i; j<N; j++)
		{
			thisSum += A[j];
			if(thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

int solve_maxSubsequence::method_3(const int A[], int N)
{
	return maxSubSum_method3(A, 0, N-1);
}

int solve_maxSubsequence::method_4(const int A[], int N)
{
	int thisSum, maxSum, i;
	thisSum = maxSum = 0;
	for(i=0; i<N; i++)
	{
		thisSum += A[i];
		if(thisSum > maxSum)
			maxSum = thisSum;
		else if(thisSum < 0)
			thisSum = 0;
	}

	return maxSum;
}

//2- 二分法查找
// 时间复杂度为O(log N)
int binarySearch(const int sortedAscendingA[], int targetNum, int N)
{
	int low, mid, high;

	low = 0;
	high = N-1;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(sortedAscendingA[mid] < targetNum)
			low = mid + 1;
		else if(sortedAscendingA[mid] > targetNum)
			high = mid - 1;
		else
			return mid;
	}
	return -404;//404 not Found, :)
}

//3- 欧几里得算法
// 时间复杂度为O(log N),N为较小数字。
// 迭代次数最多为2log(N)
// 定理：若M>N,则 M mod N < M/2
unsigned int gcd(unsigned int M, unsigned int N)
{
	unsigned int rem;

	while(N > 0)
	{
		rem = M%N;
		M = N;
		N = rem;
	}

	return M;
}

//4- 幂运算
long int Pow(long int X,unsigned int N)
{
	if(N==0)
		return 1;
	if(N%2)	//N为奇数
		return Pow(X*X,N/2)*X;
	else
		return Pow(X*X,N/2);
}
/*
	时间复杂度分析：(一般，log均指以2为底求对数)
	对于大O分析，直接考虑最坏情况。
	显然，运行次数包括 N==0的O(1)部分以及奇偶判断后面的return递归（对半分）。
	1、O(1)容易，先不理。
	2、因为每次递归分解return中，当N为奇数时，有乘法次数最大，为2。
		假设递归过程中，N均为奇数。（最坏情况）
		又由于，对于N每次对半分;
		则，对于自然数N有:一定存在N0=2^x，使得N<N0，其中x为自然数;
		则，有对N0对半分，直到N=1,再继续1/2=0，次数为log(N0)+2（‘2’为包括计算到了1，0的次数）。
		同理，N对半分次数应该也是log(N),且N的对半分次数比N0小。
	所以，有最多为2[log(N)]+4（此处[]为向上取整）
	3、所以，有O(log(N))

	Some Note:
	1、对于N为奇数递归return语句，可改为：
			return Pow(X,N-1)*X
	2、然而以下修改有误：
			return Pow(Pow(X,2),N/2)
			return Pow(Pow(X,N/2),2)
		(因为，当N=2时，有死循环)
	3、存在第四种修改：
			return Pow(X,N/2)*Pow(X,N/2);
		可以运行，然而此处有两个Pow递归调用，不再是O(log(N)),而是以下分析：
	对于return Pow(X,N/2)*Pow(X,N/2)，每次都有2的次方增加的数列：(括号内为乘法次数)
	(N);(0)
	(N/2 * N/2);(2^0)
	(N/4 * N/4),(N/4 * N/4);(2^1)
	(N/8 * N/8),(N/8 * N/8),(N/8 * N/8),(N/8 * N/8);(2^2)
	...
	0											( 2^(log(N)+2-2) )
	（N = 2^k）
	则运行次数为1+2+4+8+...+2^(log(N)+2-2)=2N-1；
	所以，有O(N)。
	因为增长速度上，N>log(N),符合实际,效率减小了。
*/
