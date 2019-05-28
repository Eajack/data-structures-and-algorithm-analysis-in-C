/*
	Author: Eajack Lau
	Date: 2019/5/25
	Function:
		《数据结构与算法分析（C语言描述）》第十章
		算法设计技巧
*/

#include "algorithms_DesignTips.h"
using namespace std;

static unsigned long Seed = 1;	//random

//10.1 Greedy Algorithm(贪婪算法)
//10.1.2 Huffman Code
struct treeNode_Huffman
{
	string name;
	int frequency;
	tree_Huffman left;
	tree_Huffman right;
};

bool cmp(const tree_Huffman &tree1, const tree_Huffman &tree2) 
{
	return tree1->frequency < tree2->frequency;
};

void treeFrequency_sort(vector<tree_Huffman> &treeH)
{
	sort(treeH.begin(),treeH.end(),cmp);
};

SymbolTable createSymbolTable()
{
	SymbolTable T;
	T["a"] = 10;
	T["e"] = 15;
	T["i"] = 12;
	T["s"] = 3;
	T["t"] = 4;
	T["space"] = 13;
	T["newline"] = 1;

	return T;
};

//(1) buildHuffmanTree
//O(n)
tree_Huffman buildHuffmanTree(SymbolTable T)
{
	//1- create empty trees
	// O(N)
	vector<tree_Huffman> treeH;
	for(auto iter=T.begin(); iter != T.end(); iter++)
	{
		ptrToNode tmp = new(struct treeNode_Huffman);
		tmp->name = (*iter).first;
		tmp->frequency = (*iter).second;
		tmp->left = tmp->right = nullptr;
		treeH.push_back(tmp);
	}

	//2- begin
	while(treeH.size() > 1)
	{
		//find 2 min frequency tree
		treeFrequency_sort(treeH);
		tree_Huffman leftTree = treeH[0];
		tree_Huffman rightTree = treeH[1];
		treeH.erase(treeH.begin());
		treeH.erase(treeH.begin());

		//join 2 tree
		ptrToNode tmp = new(struct treeNode_Huffman);
		tmp->name = "CODE_ROOT";
		tmp->frequency = leftTree->frequency + rightTree->frequency;
		tmp->left = leftTree;
		tmp->right = rightTree;

		//push_back
		treeH.push_back(tmp);
	}

	//3-end
	return treeH[0];
};

//(2) buildHuffmanCodeTable
//O(logN)
void getAllCode(tree_Huffman treeH, HuffmanCodeTable &T, vector<string> &S, int LeftorRight)
{
	if(treeH)
	{
		//push
		if(LeftorRight == 1)
		{
			S.push_back("0");
		}
		else if(LeftorRight == -1)
		{
			S.push_back("1");
		}

		if(!treeH->left and !treeH->right)
		{
			//get code
			string code = "";
			for(auto iter = S.begin(); iter != S.end(); iter++)
			{
				code += (*iter);
			}
			//get name
			string name = treeH->name;
			//save
			T[name] = code;
		}
		else
		{
			getAllCode(treeH->left, T, S, 1);
			getAllCode(treeH->right, T, S, -1);
		}

		if(S.size())
		{
			S.pop_back();//pop
		}
	}
};

//O(logN)
HuffmanCodeTable buildHuffmanCodeTable(tree_Huffman treeH)
{
	HuffmanCodeTable T;
	vector<string> S;
	getAllCode(treeH, T, S, 0);

	return T;
};

//10.1.3 bin packing problem(BMP)
double sum_bins(ptrToBin bin)
{
	double sum = 0;
	for(auto iter = (*bin).begin(); iter != (*bin).end(); iter++)
	{
		sum += (*iter);
	}
	return sum;
};

//(1) Next-Fit algorithm
// O(N)
Bins solveBMPOnline_nextFit(const double A[], int N)
{
	//1- pre
	Bins bins;
	ptrToBin bin_0 = new(Bin);
	int current_bin = 0;
	bins.push_back(bin_0);

	for(int i=0; i<N; i++)
	{
		if( ((*(bins[current_bin])).size() == 0) or (sum_bins(bins[current_bin])+A[i] < 1.0) )
		{
			(*(bins[current_bin])).push_back(A[i]);
		}
		else
		{
			current_bin++;
			ptrToBin bin_ptr = new(Bin);
			(*bin_ptr).push_back(A[i]);
			bins.push_back(bin_ptr);
		}
	}

	return bins;
};

//(2) First-Fit algorithm
//O(N^2)
Bins solveBMPOnline_firstFit(const double A[], int N)
{
	//1- pre, O(N)
	Bins bins;
	int bin_num = N;
	for(int i=0; i<bin_num; i++)
	{
		ptrToBin bin_ptr = new(Bin);
		bins.push_back(bin_ptr);
	}

	//2- begin, O(N^2)
	for(int i=0; i<N; i++)
	{
		int full_flag = 1;
		for(int j=0; j<bin_num; j++)
		{
			if( ((*(bins[j])).size() == 0) or (sum_bins(bins[j])+A[i] < 1.0) )
			{
				(*(bins[j])).push_back(A[i]);
				full_flag = 0;
				break;
			}
		}
		if(full_flag)
		{
			bin_num++;
			ptrToBin bin_ptr = new(Bin);
			(*bin_ptr).push_back(A[i]);
			bins.push_back(bin_ptr);
		}
	}

	return bins;
};

//(3) Best-Fit algorithm
//O(N^2)
int* bin_sort(Bins &bins)
{
	//1- get storages
	map<int, double> bin_storage;
	int cnt = 0;
	for(auto iter=bins.begin(); iter != bins.end(); iter++)
	{
		bin_storage[cnt] = sum_bins(*iter);
		cnt++;
	}

	//2- sort
	vector<pair<int, double>> bin_sorted_vmap;
	for (auto iter = bin_storage.begin(); iter != bin_storage.end(); iter++)
	{
		bin_sorted_vmap.push_back(make_pair(iter->first, iter->second));
	}

	sort(bin_sorted_vmap.begin(), bin_sorted_vmap.end(), 
		[](const pair<int, double> &first, const pair<int, double> &second) -> int {
		return first.second > second.second;
	});

	//3- get new index
	int* bin_index_sorted = new int[bins.size()];
	int bin_cnt = 0;
	for(auto iter=bin_sorted_vmap.begin(); iter != bin_sorted_vmap.end(); iter++)
	{
		bin_index_sorted[bin_cnt] = (*iter).first;
		bin_cnt++;
	}

	return bin_index_sorted;
};

Bins solveBMPOnline_bestFit(const double A[], int N)
{
	//1- pre, O(N)
	Bins bins;
	int bin_num = N;
	for(int i=0; i<bin_num; i++)
	{
		ptrToBin bin_ptr = new(Bin);
		bins.push_back(bin_ptr);
	}

	//2- begin, O(N^2)
	int* bin_index_sorted = new int[bin_num];
	for(int i=0; i<bin_num; i++)
	{
		bin_index_sorted[i] = i;
	}

	for(int i=0; i<N; i++)
	{
		int full_flag = 1;

		//begin
		int A_index;
		for(int j=0; j<bin_num; j++)
		{
			A_index = bin_index_sorted[j];
			if( sum_bins(bins[A_index])+A[i] <= 1.0 ) 
			{
				(*(bins[A_index])).push_back(A[i]);
				full_flag = 0;
				bin_index_sorted = bin_sort(bins);
				break;
			}
		}

		//isFull
		if(full_flag)
		{
			bin_num++;
			ptrToBin bin_ptr = new(Bin);
			(*bin_ptr).push_back(A[i]);
			bins.push_back(bin_ptr);
			bin_index_sorted = bin_sort(bins);
		}
	}

	return bins;
};


//10.2 Divide & Conquer
//10.2.2 Minumum Points Problem
// refer: https://www.jianshu.com/p/8bc681afbaff
Points createPoints()
{
	Points points_vector;
	srand(unsigned(time(nullptr)));
	for (int i = 0; i < POINTS_NUM; i++)
	{
		ptrToPoint p_ptr = new(Point);
		p_ptr->first = (rand() % int(COORDINATE_RANGE * 200)) / COORDINATE_RANGE - COORDINATE_RANGE;
		p_ptr->second = (rand() % int(COORDINATE_RANGE * 200)) / COORDINATE_RANGE - COORDINATE_RANGE;
		points_vector.push_back(p_ptr);
	}

	return points_vector;
};

double getDistance(ptrToPoint a_ptr, ptrToPoint b_ptr)
{
	return sqrt((a_ptr->first - b_ptr->first)*(a_ptr->first - b_ptr->first) + (a_ptr->second - b_ptr->second)*(a_ptr->second - b_ptr->second));
};

void points_sort(Points &points_vector, int xory)
{
	if (xory == 1)
	{
		sort(points_vector.begin(), points_vector.end(),
			[](const ptrToPoint a, const ptrToPoint b) -> int {
			return (a->first < b->first);
		});
	}
	else
	{
		sort(points_vector.begin(), points_vector.end(),
			[](const ptrToPoint a, const ptrToPoint b) -> int {
			return (a->second < b->second);
		});
	}

};

Points get_buffer(Points points_vector)
{
	Points points_vector_buffer;
	for(auto iter=points_vector.begin(); iter != points_vector.end(); iter++)
	{
		ptrToPoint tmp = new(Point);
		int x = (*(*iter)).first;
		int y = (*(*iter)).second;
		(*tmp) = make_pair(x, y);
		points_vector_buffer.push_back(tmp);
	}

	return points_vector_buffer;
}

double getMinimumPoints_sub(Points points_vector, Point &a, Point &b)
{
	int points_num = points_vector.size();
	double distance, minDis_left, minDis_right;

	if(points_num < 2)
	{
		cout << "getMinimumPoints ERROR: points_num < 2." << endl;
		return INFINITE_DISTANCE;
	}
	else if(points_num == 2)
	{
		a = *(points_vector[0]);
		b = *(points_vector[1]);
		distance = getDistance(points_vector[0], points_vector[1]);
	}
	else//begin
	{
		//1- sort(first)
		points_sort(points_vector, 1);

		//2- divide 2 part
		double mid_x = points_vector[(points_num-1)/2]->first;
		Points leftPoints, rightPoints;
		for(auto iter=points_vector.begin(); iter != points_vector.end(); iter++)
		{
			if( (*iter)->first <= mid_x)
			{
				leftPoints.push_back(*iter);
			}
			else
			{
				rightPoints.push_back(*iter);
			}
		}

		//3- D&C: divide
		Point a_left, b_left, a_right, b_right, a_min, b_min;
		minDis_left = getMinimumPoints_sub(leftPoints, a_left, b_left);
		minDis_right = getMinimumPoints_sub(rightPoints, a_right, b_right);

		a = (minDis_left < minDis_right) ? (a_left) : (a_right);
		b = (minDis_left < minDis_right) ? (b_left) : (b_right);
		double delta = (minDis_left < minDis_right) ? (minDis_left) : (minDis_right);
		distance = delta;
	}

	return distance;
};

double getMinimumPoints(Points points_vector, Point &a, Point &b)
{
	//0- pre
	Points points_vector_buffer = get_buffer(points_vector);
	double delta = getMinimumPoints_sub(points_vector, a, b);

	//4- D&C: conquer
	// P280, Fig.10-33
	Point p_i , p_j;
	for(int i=0; i<points_vector_buffer.size(); i++)
	{
		for(int j=i+1; j<points_vector_buffer.size(); j++)
		{
			p_i = *(points_vector_buffer[i]);
			p_j = *(points_vector_buffer[j]);
			if(getDistance(&p_i,&p_j) < delta)
			{
				delta = getDistance(&p_i,&p_j);
				a = p_i;
				b = p_j;
			}
		}
	}

	return delta;
}

//10.2.4 matrix multiply
vector<Matrix> createAB()
{
	Matrix A = new int* [2];
	for(int i=0; i<2; i++)
	{
		A[i] = new int[3];
	}
	A[0][0] = 2; A[0][1] = 3; A[0][2] = 4;
	A[1][0] = 5; A[1][1] = 4; A[1][2] = 2;

	Matrix B = new int* [3];
	for(int i=0; i<3; i++)
	{
		B[i] = new int[2];
	}
	B[0][0] = 2; B[0][1] = 3; 
	B[1][0] = 5; B[1][1] = 4; 
	B[2][0] = 2; B[2][1] = 7;

	vector<Matrix> return_matrix{A,B};
	
	return return_matrix;
}

//O(N^3)
Matrix matrix_mul_origin(Matrix A, Matrix B, int rowA, int colA, int rowB, int colB)
{
	if(colA != rowB)
	{
		cout << "matrix_mul_origin ERROR: colA != rowB." << endl;
		return nullptr;
	}

	//begin
	// O(N)
	Matrix C = new int* [rowA];
	for(int i=0; i<rowA; i++)
	{
		C[i] = new int[colB];
	}

	// O(N^3)
	for(int i=0; i<rowA; i++)
	{
		for(int j=0; j<colB; j++)
		{
			int tmp = 0;
			for(int k=0; k<colA; k++)
			{
				tmp += (A[i][k]*B[k][j]);
			}
			C[i][j] = tmp;
		}
	}

	return C;
}

void printMatrix(Matrix X, int row, int col)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout << X[i][j] << "\t";
		}
		cout << endl;
	}
}

//10.4 Random Algorithm
//10.4.1 Random Number
void initRandom(unsigned long initVal)
{
	Seed = initVal;
}

double getRandom()
{
	long tmpSeed = A_RANDOM * (Seed % Q_RANDOM) - R_RANDOM * (Seed / Q_RANDOM);
	if(tmpSeed >= 0)
	{
		Seed = tmpSeed;
	}
	else
	{
		Seed = tmpSeed + M_RANDOM;
	}

	return (double) Seed / M_RANDOM;
}

