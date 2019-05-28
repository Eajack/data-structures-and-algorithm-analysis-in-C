/*
	Author: Eajack Lau
	Date: 2019/5/3
	Function:
		《数据结构与算法分析（C语言描述）》第七章
		排序（升序）
		7种排序：insert_sort、shell_sort、heap_sort、
				merge_sort、quick_sort、bubble_sort、selection_sort
		radix_sort（基数排序）&bucket_sort（桶式排序）
			在chapter_3的“linkedList_application_sort.cpp”
*/

#include "sort_algorithms.h"
using namespace std;


void sort_test(int sort_option)
{
	int A[] = {12,12,15,41,4,84,411,1,5,78,61,88,88,54,54,66,74};
	int N = sizeof(A)/sizeof(A[0]);

	if(sort_option == 1)
	{
		insert_sort(A, N);
		cout << "===================1- insert_sort===================" << endl;
		for(int i=0; i<N; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "================================================" << endl;
		cout << "\n";
	}
	else if(sort_option == 2)
	{
		shell_sort(A, N);
		cout << "===================2- shell_sort===================" << endl;
		for(int i=0; i<N; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "================================================" << endl;
		cout << "\n";
	}
	else if(sort_option == 3)
	{
		heap_sort(A, N);
		cout << "===================3- heap_sort===================" << endl;
		for(int i=0; i<N; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "================================================" << endl;
		cout << "\n";
	}
	else if(sort_option == 4)
	{
		merge_sort(A, N);
		cout << "===================4- merge_sort===================" << endl;
		for(int i=0; i<N; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "================================================" << endl;
		cout << "\n";
	}
	else if(sort_option == 5)
	{
		quick_sort(A, N);
		cout << "===================5- quick_sort===================" << endl;
		for(int i=0; i<N; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "================================================" << endl;
		cout << "\n";
	}
	else if(sort_option == 6)
	{
		bubble_sort(A,N);
		cout << "===================6- bubble_sort===================" << endl;
		for(int i=0; i<N; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "================================================" << endl;
		cout << "\n";
	}
	else if(sort_option == 7)
	{
		selection_sort(A, N);
		cout << "===================7- selection_sort===================" << endl;
		for(int i=0; i<N; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "================================================" << endl;
		cout << "\n";		
	}
}


int main()
{
	//sort algorithms test
	for(int i=1; i<=7; i++)
	{
		sort_test(i);
	}
	
}