/*
	Author: Eajack Lau
	Date: 2019/5/25
	Function:
		《数据结构与算法分析（C语言描述）》第十章
		算法设计技巧
*/

#include <iostream>
#include <climits>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <windows.h>
#define INFINITE_DISTANCE INT_MAX
#define POINTS_NUM 5
#define COORDINATE_RANGE 100
#define A_RANDOM 48271L
#define M_RANDOM 2147483647L
#define Q_RANDOM (M_RANDOM / A_RANDOM)
#define R_RANDOM (M_RANDOM % A_RANDOM)

using namespace std;

//10.1 Greedy Algorithm(贪婪算法)
//10.1.2 Huffman Code
struct treeNode_Huffman;
typedef struct treeNode_Huffman *ptrToNode;
typedef ptrToNode tree_Huffman;
typedef map<string, int> SymbolTable;
typedef map<string, string> HuffmanCodeTable;

bool cmp(const tree_Huffman &tree1, const tree_Huffman &tree2);
void treeFrequency_sort(vector<tree_Huffman> &treeH);
SymbolTable createSymbolTable();
tree_Huffman buildHuffmanTree(SymbolTable T);
void getAllCode(tree_Huffman treeH, HuffmanCodeTable &T, vector<string> &S, int LeftorRight);
HuffmanCodeTable buildHuffmanCodeTable(tree_Huffman treeH);

//10.1.3 bin packing problem
typedef vector<double> Bin;
typedef Bin *ptrToBin;
typedef vector<ptrToBin> Bins;
double sum_bins(ptrToBin bin);
Bins solveBMPOnline_nextFit(const double A[], int N);
Bins solveBMPOnline_firstFit(const double A[], int N);
int* bin_sort(Bins &bins);
Bins solveBMPOnline_bestFit(const double A[], int N);

//10.2 Divide & Conquer
//10.2.2 Minumum Points Problem
typedef pair<int, int> Point;
typedef Point *ptrToPoint;
typedef vector<ptrToPoint> Points;
typedef Points *ptrToPoints;

Points createPoints();
double getDistance(ptrToPoint a_ptr, ptrToPoint b_ptr);
void points_sort(Points &points_vector, int xory);
double getMinimumPoints_sub(Points points_vector, Point &a, Point &b);
double getMinimumPoints(Points points_vector, Point &a, Point &b);

//10.2.4 matrix multiply
typedef int** Matrix;
vector<Matrix> createAB();
Matrix matrix_mul_origin(Matrix A, Matrix B, int rowA, int colA, int rowB, int colB);
void printMatrix(Matrix X, int row, int col);

//10.4 Random Algorithm
//10.4.1 Random Number
void initRandom(unsigned long initVal);
double getRandom();
//10.4.2 Skip Lists
struct skipNode;
typedef struct skipNode *ptrToSkipNode;
typedef struct skipNode **Next;
typedef ptrToSkipNode SkipList;