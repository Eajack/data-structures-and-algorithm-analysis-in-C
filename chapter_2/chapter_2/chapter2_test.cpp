/*
	Author: Eajack Lau
	Date: 2019/3/28
	Function:
		《数据结构与算法分析（C语言描述）》第二章
*/
#include "chapter_2_algorithms.h"

int main()
{
	int A[10] = {9,-4,3,4,5,-8,-7,10,6,-3};
	int N = 10;

	//1- 最大子序列和
	solve_maxSubsequence solve_MS;
	int MS_1 = solve_MS.method_1(A, N);
	int MS_2 = solve_MS.method_2(A, N);
	int MS_3 = solve_MS.method_3(A, N);
	int MS_4 = solve_MS.method_4(A, N);

	cout << "1- Max Sequence Sum: " << endl;
	cout << "method 1:" << MS_1 << endl;
	cout << "method 2:" << MS_2 << endl;
	cout << "method 3:" << MS_3 << endl;
	cout << "method 4:" << MS_4 << endl;

	//2- 二分法查找
	int target_index = binarySearch(A, 10, 10);
	cout << "2- binarySearch:" << target_index << endl;

	//3- gcd
	int rem = gcd(50, 15);
	cout << "3- GCD:" << rem << endl;

	//4- 幂运算
	long int pow_result = Pow(2,10);
	cout << "4- Pow:" << pow_result << endl;

	return 0;
}