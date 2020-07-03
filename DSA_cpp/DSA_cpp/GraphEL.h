/*
	Author: Eajack Lau
	Date: 2019/5/17
	Function:
		图论算法
*/

#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//general functions
struct listNode;
typedef struct listNode *ptrToNode;	//the List[i] pointer(i>0)
typedef ptrToNode List;	//the List[0] pointer

struct adjList_DAG;
typedef struct adjList_DAG *ptrToAdjList_DAG;//directed acyclic graph
typedef struct adjList_DAG *ptrToAdjList_uDAG;//undirected acyclic graph
typedef struct adjList_DAG *ptrToAdjList;//double, ud & d
typedef int** ptrToAdjMatrix_DAG;

typedef int* ptrToIndegreeArray;
typedef string Vertex;
typedef int Vertex_int;
typedef vector<Vertex_int> Vertex_vector;
typedef map<string, int> IndegreeMap;
typedef vector<string> TopSorted_name_vector;

struct distNode;
typedef struct distNode *DistNode;
typedef vector<DistNode> DistVector;

typedef DistVector tree_MST_Prim;
typedef pair<int, int> Edge;
typedef pair<Edge, int> Edge_info;
typedef vector<Edge_info> Edges;
typedef Edges tree_MST_Kruskal;


//1- createGraph
// uW-DAG(无权有向无圈图)|W-DAG(正权有向无圈图)|nW-DAG(负权有向无圈图)|W-uDAG(正权无向无圈图)
ptrToAdjList_DAG createGraph_adjList(int option, int v_num);
ptrToAdjMatrix_DAG createGraph_adjMatrix(int option, int v_num);
//2- getIndegree
// DG(有向图)
int* getIndegree_adjList(ptrToAdjList_DAG adj_list, int v_num);
int* getIndegree_adjMatrix(ptrToAdjMatrix_DAG adj_matrix, int v_num);
//3- findNewVertexOfIndegreeZero
Vertex findNewVertexOfIndegreeZero(IndegreeMap indegree_map);
//4- topolopy sort
// DAG(有向无圈图)
IndegreeMap transfer_array2map(ptrToIndegreeArray indegree_array, int v_num);
TopSorted_name_vector topSort(ptrToAdjList_DAG adj_list);
//5- findMinPath algorithms
//5.1 Unweighted Graph(uW-DAG)
void print_DistVector(DistVector dist_vector, int targetV);
DistVector createDistVector(ptrToAdjList_DAG adj_list, int targetV);
DistVector findMinPath_unweighted_1(ptrToAdjList_DAG adj_list, int targetV);
DistVector findMinPath_unweighted_2(ptrToAdjList_DAG adj_list, int targetV);
//5.2 Weighted Graph(Dijkstra)(W-DAG)
int getSmallestDist_unknowV(vector<int>& unknown_v, DistVector dist_vector);
DistVector findMinPath_weighted(ptrToAdjList_DAG adj_list, int targetV);
//5.3 Weighted Graph(negative)(nW-DAG)
bool isInq(int w_int, vector<int> q);
DistVector findMinPath_weighted_negative(ptrToAdjList_DAG adj_list, int targetV);
//6- minimum spanning tree(MST)
// W-uDAG(正权无向无圈图)
//(1)- Prim
tree_MST_Prim buildMST_Prim(ptrToAdjList_uDAG adj_list, int targetV);
//(2)- Kruskal
bool cmp(const Edge_info &e_info1, const Edge_info &e_info2);
void Edges_sort(Edges &edges);
//tree_MST_Kruskal buildMST_Kruskal(ptrToAdjList_uDAG adj_list);
//7- Graph Traversal
// (1)breadth-first search(BFS)
// (2)depth-first search(DFS)
Vertex_vector GraphTraversal_BFS(ptrToAdjList adj_list, int targetV);
void DFS(ptrToAdjList adj_list, int* nodeFlag_array, Vertex_vector &vertexs, int v_int);
Vertex_vector GraphTraversal_DFS(ptrToAdjList adj_list, int targetV);