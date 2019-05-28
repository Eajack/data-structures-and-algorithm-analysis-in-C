/*
	Author: Eajack Lau
	Date: 2019/5/17
	Function:
		《数据结构与算法分析（C语言描述）》第九章
		图论算法
*/

#include "graph_algorithms.h"
using namespace std;

void test()
{
	//1- create graph(list & matrix)
	ptrToAdjList_DAG adj_list = createGraph_adjList(1, 7);
	ptrToAdjMatrix_DAG adj_matrix = createGraph_adjMatrix(1, 7);

	//2- get indegree array(list & matrix)
	int* indegree_list = getIndegree_adjList(adj_list, 7);
	int* indegree_matrix = getIndegree_adjMatrix(adj_matrix, 7);

	//3- topology sort
	TopSorted_name_vector topSorted_vector = topSort(adj_list);

	//4- Shortest Problem
	//4.1 Unweighted Graph
	int targetV = 3;
	DistVector dist_vector_1 = findMinPath_unweighted_1(adj_list, targetV);
	DistVector dist_vector_2 = findMinPath_unweighted_2(adj_list, targetV);
	print_DistVector(dist_vector_1, targetV);
	print_DistVector(dist_vector_2, targetV);
	//4.2 Weighted Graph(Dijkstra)
	ptrToAdjList_DAG adj_list_w = createGraph_adjList(2, 7);
	DistVector dist_vector_w = findMinPath_weighted(adj_list_w, 0);
	print_DistVector(dist_vector_w, 0);
	//4.3 Weighted Graph(negative)
	ptrToAdjList_DAG adj_list_nw = createGraph_adjList(3, 7);
	DistVector dist_vector_nw = findMinPath_weighted_negative(adj_list_nw, 0);
	print_DistVector(dist_vector_nw, 0);

	//5- maximum flow problem
	ptrToAdjList_uDAG adj_list_uDAG = createGraph_adjList(4, 7);
	tree_MST_Prim tree_mst_prim = buildMST_Prim(adj_list_uDAG, 0);
	tree_MST_Kruskal tree_mst_kruskal = buildMST_Kruskal(adj_list_uDAG);

	//6- Graph Traversal: BFS & DFS
	Vertex_vector vertexs_BFS = GraphTraversal_BFS(adj_list, 0);
	Vertex_vector vertexs_DFS = GraphTraversal_DFS(adj_list, 0);
}


int main()
{
	test();

	return 0;
}