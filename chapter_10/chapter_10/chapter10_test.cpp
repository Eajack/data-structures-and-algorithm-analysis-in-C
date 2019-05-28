/*
	Author: Eajack Lau
	Date: 2019/5/25
	Function:
		《数据结构与算法分析（C语言描述）》第十章
		算法设计技巧
*/
#include "algorithms_DesignTips.h"
using namespace std;

void test()
{
	//1- Greedy Algorithm
	SymbolTable T = createSymbolTable();
	tree_Huffman treeH = buildHuffmanTree(T);
	HuffmanCodeTable codeTable = buildHuffmanCodeTable(treeH);

	//2- bin packing problem
	double A[] = {0.2, 0.5, 0.4, 0.7, 0.1, 0.3, 0.8};
	int N = sizeof(A) / sizeof(A[0]);
	Bins bins1 = solveBMPOnline_nextFit(A, N);
	Bins bins2 = solveBMPOnline_firstFit(A, N);
	Bins bins3 = solveBMPOnline_bestFit(A, N);

	//3- Minumum Points Problem
	for(int i=0; i<10; i++)
	{
		Points points_vector = createPoints();
		Point a, b;
		double minDis = getMinimumPoints(points_vector, a, b);

		// cout
		cout << "===============================================================" << endl;
		cout << "p1\t\tp2\t\tdistance" << endl;
		for(int i=0; i<points_vector.size(); i++)
		{
			for(int j=i+1; j<points_vector.size(); j++)
			{
				double distance = getDistance(points_vector[i], points_vector[j]);
				cout << "(" << (points_vector[i])->first << ", " << (points_vector[i])->second << ")" << "\t" \
					 << "(" << (points_vector[j])->first << ", " << (points_vector[j])->second << ")" << "\t" \
					 << distance << endl;
			}
		}

		cout << "--\tminDis\t--" << endl;
		cout << "(" << a.first << ", " << a.second << ")" << "\t" \
			 << "(" << b.first << ", " << b.second << ")" << "\t" \
			 << minDis << endl;
		cout << "===============================================================" << endl;
		cout << "\n\n";

		Sleep(2000);

		//delete
		for(auto iter=points_vector.begin(); iter != points_vector.end(); iter++)
		{
			delete(*iter);
		}
	}

	//4- matrix multiply
	vector<Matrix> tmp = createAB();
	Matrix A_m = tmp[0], B_m = tmp[1];
	Matrix C_m = matrix_mul_origin(A_m, B_m, 2, 3, 3, 2);
	cout << "Matrix Multiply: matrix_mul_origin" << endl;
	cout << "==Matrix A_m==" << endl;
	printMatrix(A_m, 2, 3);
	cout << "==Matrix B_m==" << endl;
	printMatrix(B_m, 3, 2);
	cout << "==Matrix C_m==" << endl;
	printMatrix(C_m, 2, 2);

	//5 Random Algorithm
	cout << "===================Random Algorithm=====================" << endl; 
	initRandom((unsigned)time(NULL));
	for(int i=0; i<10; i++)
	{
		cout << getRandom() << "\t";
	}
	cout << endl;
	cout << "===============================================================" << endl;
}

int main()
{
	test();

	return 0;
}