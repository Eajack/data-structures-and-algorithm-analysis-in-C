/*
	Author: Eajack Lau
	Date: 2019/5/17
	Function:
		《数据结构与算法分析（C语言描述）》第九章
		图论算法，行 => src，列 => dst
*/
#include "graph_algorithms.h"
#include "sets.h"
using namespace std;

//general functions
struct listNode
{
	int v_int;
	int weight;
	ptrToNode next;
};

struct adjList_DAG
{
	int tableSize;		//the length of H
	List* listArray;	//the pointer of H
};


//1- createGraph(adj_list)
// option = 1, 0~6 <=> v0~v6, uW-DAG(无权有向无圈图)
// option = 2, 0~6 <=> v0~v6, W-DAG(正权有向无圈图)
// option = 3, 0~6 <=> v0~v6, nW-DAG(负权有向无圈图)
// option = 4, 0~6 <=> v0~v6, W-uDAG(正权无向无圈图)
// storage: O(|V|+|E|)
ptrToAdjList_DAG createGraph_adjList(int option, int v_num=7)
{
	//(1)- malloc
	ptrToAdjList_DAG adj_list = (ptrToAdjList_DAG)malloc(sizeof(struct adjList_DAG));
	if(adj_list == NULL)
	{
		cout << "createGraph_adjList ERROR 1: malloc out of space" << endl;
		return NULL;
	}
	adj_list->tableSize = v_num;
	adj_list->listArray = (List*)malloc(sizeof(int) * v_num);

	for(int i=0; i<v_num; i++)	//O(|V|)
	{
		adj_list->listArray[i] = (ptrToNode)malloc(sizeof(struct listNode));
		if(adj_list->listArray[i] == NULL)
		{
			cout << "createGraph_adjList ERROR 2: malloc out of space" << endl;
			return NULL;
		}
		adj_list->listArray[i]->v_int = INT_MIN;
		adj_list->listArray[i]->weight = INT_MIN;
		adj_list->listArray[i]->next = NULL;
	}

	//(2)- option
	int* A = NULL;
	int* B = NULL;
	int* weight = NULL;
	if(option == 1)
	{
		//init array
		int A_buffer[] = {1,3,2,3,4,5,5,6,2,3,6,5};//value of adjListList
		int B_buffer[] = {3,2,1,3,2,0,1};	//num of each list
		
		A = (int*)malloc(sizeof(int) * 12);
		B = (int*)malloc(sizeof(int) * v_num);
		weight = (int*)malloc(sizeof(int) * 12);
		for(int k=0; k<12; k++)
		{
			A[k] = 	A_buffer[k];
			weight[k] = 1;
		}
		for(int k=0; k<v_num; k++)
		{
			B[k] = B_buffer[k];
		}
	}
	else if(option == 2)
	{
		//init array
		int A_buffer[] = {1,3,4,3,0,5,2,4,5,6,6,5};//value of adjListList
		int B_buffer[] = {2,2,2,4,1,0,1};	//num of each list
		int weight_buffer[] = { 2,1,10,3,4,5,2,2,8,4,6,1 };
		
		A = (int*)malloc(sizeof(int) * 12);
		B = (int*)malloc(sizeof(int) * v_num);
		weight = (int*)malloc(sizeof(int) * 12);
		for(int k=0; k<12; k++)
		{
			A[k] = 	A_buffer[k];
			weight[k] = weight_buffer[k];
		}
		for(int k=0; k<v_num; k++)
		{
			B[k] = B_buffer[k];
		}
	}
	else if(option == 3)
	{
		//init array
		int A_buffer[] = {1,3,4,3,0,5,2,4,5,6,6,5};//value of adjListList
		int B_buffer[] = {2,2,2,4,1,0,1};	//num of each list
		//int weight_buffer[] = {-2,1,-10,3,4,5,2,2,-8,4,-6,1};
		int weight_buffer[] = {-2,-1,10,3,-4,5,2,2,8,4,6,1};
		
		A = (int*)malloc(sizeof(int) * 12);
		B = (int*)malloc(sizeof(int) * v_num);
		weight = (int*)malloc(sizeof(int) * 12);
		for(int k=0; k<12; k++)
		{
			A[k] = 	A_buffer[k];
			weight[k] = weight_buffer[k];
		}
		for(int k=0; k<v_num; k++)
		{
			B[k] = B_buffer[k];
		}
	}
	else if(option == 4)
	{
		//init array
		int A_buffer[] = {1,2,3,0,3,4,0,3,5,0,1,2,4,5,6,1,3,6,2,3,6,3,4,5};//value of adjListList
		int B_buffer[] = {3,3,3,6,3,3,3};	//num of each list
		//int weight_buffer[] = {-2,1,-10,3,4,5,2,2,-8,4,-6,1};
		int weight_buffer[] = {2,4,1,2,3,10,4,2,5,1,3,2,7,8,4,10,7,6,5,8,1,4,6,1};
		
		A = (int*)malloc(sizeof(int) * 24);
		B = (int*)malloc(sizeof(int) * v_num);
		weight = (int*)malloc(sizeof(int) * 24);
		for(int k=0; k<24; k++)
		{
			A[k] = 	A_buffer[k];
			weight[k] = weight_buffer[k];
		}
		for(int k=0; k<v_num; k++)
		{
			B[k] = B_buffer[k];
		}
	}
	else
	{
		return NULL;
	}

	//index of A
	int A_index = 0;
	for(int i=0; i<v_num; i++)//O(|V|)
	{
		ptrToNode p_last = adj_list->listArray[i], p_now;

		for(int j=B[i]; j>0; j--)//O(|V|)
		{
			p_now = (ptrToNode)malloc(sizeof(struct listNode));
			if(p_now == NULL)
			{
				cout << "createGraph_adjList ERROR 3: malloc out of space" << endl;
				return NULL;
			}
			p_now->v_int = A[A_index];
			p_now->weight = weight[A_index];	//un-weighted, i.e. weight = 1
			p_now->next = NULL;

			p_last->next = p_now;
			p_last = p_now;
			A_index++;
		}
	}

	return adj_list;
}


//1- createGraph(adj_matrix)
// option = 1, 0~6 <=> v0~v6, uW-DAG(无权有向图)
// storage: O(|V|^2)
ptrToAdjMatrix_DAG createGraph_adjMatrix(int option, int v_num=7)
{
	//(1)- malloc
	ptrToAdjMatrix_DAG adj_matrix = (ptrToAdjMatrix_DAG)malloc(sizeof(int*) * v_num);
	if(adj_matrix == NULL)
	{
		cout << "createGraph_adjMatrix ERROR 1: malloc out space." << endl;
		return NULL;
	}
	for(int i=0; i<v_num; i++)
	{
		adj_matrix[i] = (int*)malloc(sizeof(int) * v_num);
		if(adj_matrix[i] == NULL)
		{
			cout << "createGraph_adjMatrix ERROR 2: malloc out space." << endl;
			return NULL;
		}
	}
	for(int i=0; i<v_num; i++)
	{
		for(int j=0; j<v_num; j++)
		{
			adj_matrix[i][j] = INT_MIN;
		}
	}

	//(2)- option
	if(option == 1)
	{
		//0
		adj_matrix[0][1] = 1; adj_matrix[0][2] = 1; adj_matrix[0][3] = 1; 
		//1
		adj_matrix[1][3] = 1; adj_matrix[1][4] = 1;
		//2
		adj_matrix[2][5] = 1;
		//3
		adj_matrix[3][2] = 1; adj_matrix[3][5] = 1; adj_matrix[3][6] = 1;
		//4
		adj_matrix[4][3] = 1; adj_matrix[4][6] = 1; 
		//5
		//6
		adj_matrix[6][5] = 1;

		//others => 0
		for(int i=0; i<v_num; i++)
		{
			for(int j=0; j<v_num; j++)
			{
				if(adj_matrix[i][j] == INT_MIN)
				{
					adj_matrix[i][j] = 0;
				}
			}
		}

		return adj_matrix;
	}
	else
	{
		return NULL;
	}

/*	// free
	for (int i = 0; i < row; ++i)
	{
		free(*(arr + i));
	}*/

}

//2- get indegree(adjMatrix)
// time: O(|E|)
ptrToIndegreeArray getIndegree_adjList(ptrToAdjList_DAG adj_list, int v_num)
{
	// e.g. if(indegree_array[i] == 0), that means v(i+1) is a vertex with indgree 0
	ptrToIndegreeArray indegree_array = (int*)malloc(sizeof(int) * v_num);
	if(indegree_array == NULL)
	{
		cout << "getIndegree_adjList ERROR 1: malloc out space." << endl;
		return NULL;
	}
	//init
	for(int i=0; i<v_num; i++)
	{
		indegree_array[i] = 0;
	}

	//get through adj_list
	ptrToNode p_now;
	for(int i=0; i<adj_list->tableSize; i++)
	{
		p_now = adj_list->listArray[i]->next;
		while(p_now != NULL)
		{
			indegree_array[p_now->v_int]++;
			p_now = p_now->next;
		}
	}

	return indegree_array;
}

//2- get indegree(adjMatrix)
// time: O(|V|^2)
ptrToIndegreeArray getIndegree_adjMatrix(ptrToAdjMatrix_DAG adj_matrix, int v_num)
{
	// e.g. if(indegree_array[i] == 0), that means v(i+1) is a vertex with indgree 0
	ptrToIndegreeArray indegree_array = (int*)malloc(sizeof(int) * v_num);
	if(indegree_array == NULL)
	{
		cout << "getIndegree_adjMatrix ERROR 1: malloc out space." << endl;
		return NULL;
	}
	//init
	for(int i=0; i<v_num; i++)
	{
		indegree_array[i] = 0;
	}

	//2- get indegree
	for(int j=0; j<v_num; j++)
	{
		for(int i=0; i<v_num; i++)
		{
			if(adj_matrix[i][j] != 0)
			{
				indegree_array[j]++;
			}
		}
	}
	return indegree_array;
}

//3- findNewVertexOfIndegreeZero
// O(|V|)
Vertex findNewVertexOfIndegreeZero(IndegreeMap indegree_map)
{
	Vertex notAVertex = "INT_MIN";
	Vertex v_n;
	auto iter = indegree_map.begin();

	while (iter != indegree_map.end())
	{
		//cout << iter->first << " : " << iter->second << endl;
		if (iter->second == 0)
		{
			return iter->first;
		}
		iter++;
	}

	if(notAVertex == "INT_MIN")
	{
		return notAVertex;
	}
}

//assist funtion for topSort1
// O(|V|)
IndegreeMap transfer_array2map(ptrToIndegreeArray indegree_array, int v_num)
{
	IndegreeMap indegree_map;

	for(int i=0; i<v_num; i++)
	{
		string v_n = "v" + to_string(i);
		indegree_map.insert(pair<string, int>(v_n, indegree_array[i])); 
	}

	return indegree_map;
}


//4- topolopy sort
// set adjList_DAG as the default expression of graph
// O(|E|)
TopSorted_name_vector topSort(ptrToAdjList_DAG adj_list)
{
	// pre + topSort: O(|E| + |V|)(time)
	// pre
	// O(|E| + |V|)
	Vertex v;
	ptrToIndegreeArray indegree_array = getIndegree_adjList(adj_list, adj_list->tableSize);//O(|E|)
	IndegreeMap indegree_map = transfer_array2map(indegree_array, adj_list->tableSize);//O(|V|)
	TopSorted_name_vector topSorted_vector;

	ptrToNode p_now;
	// top sort begin
	// O(|E|)
	for(int i=0; i<adj_list->tableSize; i++)
	{
		v = findNewVertexOfIndegreeZero(indegree_map);
		if(v == "INT_MIN")
		{
			// not DAG, can't topSort
			cout << "topSort1 ERROR: v = INT_MIN" << endl;
			return topSorted_vector;
		}
		topSorted_vector.push_back(v);

		//update indegree_map
		//(1)- delete listArray(v)
		int v_int = stoi(v.replace(v.find("v"),1,""));
		string v_name = "v" + to_string(v_int);
		p_now = adj_list->listArray[v_int]->next;
		while(p_now != NULL)
		{
			//indegree_array[p_now->value]--;
			string v_n = "v" + to_string(p_now->v_int);
			indegree_map[v_n]--;
			p_now = p_now->next;
		}
		//(2)- delete other listArray
		// because v is indegree zero point, so v won't appear in other listArray[j]

		indegree_map.erase(v_name);
	}

	return topSorted_vector;
}

//5- findMinPath algorithms
// Shortest Problem: given a specific graph and a point, 
//		find the shortest path to other points.
//(1)- Unweighted Graph
//(2)- Weighted Graph(>= 0)
//(3)- Weighted Graph(has weight < 0)
//(4)- DAG

struct distNode
{
	int v_int;
	int d_v;
	int previous_vInt;
	bool know_flag;
};

//O(|V|)
DistVector createDistVector(ptrToAdjList_DAG adj_list, int targetV=INT_MAX)
{
	//INT_MAX maens all the node are <i, INT_MAX, INT_MAX, false>
	DistVector dist_vector;
	string v_n;

	for(int i=0; i<adj_list->tableSize; i++)
	{
		//key code, malloc can't fix with "string" in distNode
		DistNode node = new (struct distNode);

		if(i != targetV)
		{
			node->v_int = i;
			node->d_v = INT_MAX;
			node->previous_vInt = INT_MAX;
			node->know_flag = false;
		}
		else
		{
			node->v_int = i;
			node->d_v = 0;
			node->previous_vInt = targetV;
			node->know_flag = false;
		}
		dist_vector.push_back(node);
	}

	return dist_vector;
}

void print_DistVector(DistVector dist_vector, int targetV)
{
	cout.width(12);
	cout << "==================================" << endl;
	cout << "v_int\td_v\tknow_flag\tprevious_vInt" << endl;
	cout << "----------------------------------" << endl;
	for(auto iter = dist_vector.begin(); iter != dist_vector.end(); iter++)
	{
		cout << (*iter)->v_int << "\t";
		if((*iter)->d_v > 100000)
		{
			cout << -1 << "\t";
		}
		else
		{
			cout << (*iter)->d_v << "\t";
		}
		cout << (*iter)->know_flag << "\t";

		//print path
		vector<int> v_path;
		v_path.push_back((*iter)->v_int);
		int previous_vInt = (*iter)->previous_vInt;

		if(previous_vInt != INT_MAX)
		{
			while(previous_vInt != targetV)
			{
				v_path.push_back(previous_vInt);
				previous_vInt = dist_vector[previous_vInt]->previous_vInt;
			}
			v_path.push_back(previous_vInt);

			for(auto iter1 = v_path.rbegin(); iter1 != v_path.rend(); iter1++)
			{
				cout << (*iter1) << "->";
			}
			cout << endl;
		}
		else
		{
			cout << "INT_MAX" << endl;
		}

	}
	cout << "==================================" << endl;
}

//(1)- Unweighted Graph(easy version)
// breadth-first search: get throught all the i-th nodes before the (i+1)-th nodes
// BFS
// 	P223, get through the max level(v_num), each level get through the points
//O(|V|^2)
DistVector findMinPath_unweighted_1(ptrToAdjList_DAG adj_list, int targetV)
{
	//1- init dist_vector
	DistVector dist_vector = createDistVector(adj_list, targetV);

	//2- begin, update dist_vector
	// O(|V|^2)
	for(int level=0; level<adj_list->tableSize; level++)
	{
		for(auto iter=dist_vector.begin(); iter != dist_vector.end(); iter++)
		{
			if( (not((*iter)->know_flag)) and ((*iter)->d_v == level) )// check this level point
			{
				(*iter)->know_flag = true;
				ptrToNode p_now = adj_list->listArray[(*iter)->v_int]->next;
				while(p_now != NULL)
				{
					if(dist_vector[p_now->v_int]->d_v == INT_MAX)
					{
						dist_vector[p_now->v_int]->d_v = level + 1;
						dist_vector[p_now->v_int]->previous_vInt = (*iter)->v_int;
					}

					p_now = p_now->next;
				}
			}
		}
	}

	//INT_MAX points
	for(auto iter=dist_vector.begin(); iter != dist_vector.end(); iter++)
	{
		if( (not((*iter)->know_flag)) and ((*iter)->d_v == INT_MAX) )
		{
			(*iter)->know_flag = true;
		}
	}

	return dist_vector;
}

//(1)- Unweighted Graph(queue version)
// breadth-first search: get throught all the i-th nodes before the (i+1)-th nodes
// 	P244, use queue to store, i.e. due to using the queue(enqueue at the tail, dequeue at the head),
//		so, queue can confirm that before dealing with the (i+1)-th level nodes, all the i-th nodes can be dealed
//	Attention: in the code, enquenue => push the (i+1)-th level nodes; dequeue => get the i-th level nodes, 
//		i.e."由于队列尾部入队，头部出对，这保证了在处理(i+1)-th层之前，处理好所有i-th层节点"
//O(|E| + |V|)
DistVector findMinPath_unweighted_2(ptrToAdjList_DAG adj_list, int targetV)
{
	//1- init dist_vector
	DistVector dist_vector = createDistVector(adj_list, targetV);

	//2- begin
	vector<int> v_vector;
	v_vector.push_back(targetV);//enqueue

	int v_int, w_int;
	while(v_vector.size())
	{
		//dequeue, i-th level nodes
		v_int = v_vector[0];
		v_vector.erase(v_vector.begin());

		dist_vector[v_int]->know_flag = true;
		ptrToNode p_now = adj_list->listArray[v_int]->next;
		while(p_now != NULL)
		{
			w_int = p_now->v_int;
			if(dist_vector[w_int]->d_v == INT_MAX)
			{
				dist_vector[w_int]->d_v = dist_vector[v_int]->d_v + 1;
				dist_vector[w_int]->previous_vInt = v_int;
				v_vector.push_back(w_int);//enqueue, (i+1)-th level nodes
			}

			p_now = p_now->next;
		}
	}

	//INT_MAX points
	for(auto iter=dist_vector.begin(); iter != dist_vector.end(); iter++)
	{
		if( (not((*iter)->know_flag)) and ((*iter)->d_v == INT_MAX) )
		{
			(*iter)->know_flag = true;
		}
	}

	v_vector.clear();

	return dist_vector;
}

//(2)- Weighted Graph(Dijkstra)
// breadth-first search, P227-P228
//get smallest unknown distance vertex
int getSmallestDist_unknowV(vector<int>& unknown_v, DistVector dist_vector)
{
	int smallest_vInt = 0, iter_index = 0, iter_cnt = -1, smallest_dv = INT_MAX;
	for(auto iter = unknown_v.begin(); iter != unknown_v.end(); iter++)
	{
		iter_cnt++;
		if(dist_vector[(*iter)]->d_v < smallest_dv)
		{
			smallest_dv = dist_vector[(*iter)]->d_v;
			smallest_vInt = (*iter);
			iter_index = iter_cnt;
		}
	}
	unknown_v.erase(unknown_v.begin() + iter_index);

	return smallest_vInt;
}

//Dijkstra
// O(|V|^2 + |E|)
DistVector findMinPath_weighted(ptrToAdjList_DAG adj_list, int targetV)
{
	//1- init dist_vector
	DistVector dist_vector = createDistVector(adj_list, targetV);

	//2- begin
	int v_int, w_int;
	vector<int> unknow_v, know_v;
	for(int i=0; i<adj_list->tableSize; i++)//O(|V|)
	{
		unknow_v.push_back(i);
	}

	while(unknow_v.size())//O(|V|)
	{
		v_int = getSmallestDist_unknowV(unknow_v, dist_vector);//O(|V|)
		know_v.push_back(v_int);
		dist_vector[v_int]->know_flag = true;

		ptrToNode p_now = adj_list->listArray[v_int]->next;
		while(p_now != NULL)//O(|E|)
		{
			w_int = p_now->v_int;
			if(not dist_vector[w_int]->know_flag)
			{
				if(dist_vector[v_int]->d_v + p_now->weight < dist_vector[w_int]->d_v)
				{
					dist_vector[w_int]->d_v = dist_vector[v_int]->d_v + p_now->weight;
					dist_vector[w_int]->previous_vInt = v_int;
				}
			}

			p_now = p_now->next;
		}

	}
	return dist_vector;
}

//(3)- Weighted Graph(has weight < 0)
// (1) + (2)

//O(|V|)
bool isInq(int w_int, vector<int> q)
{
	for(auto iter = q.begin(); iter != q.end(); iter++)
	{
		if( (*iter) == w_int )
			return true;
	}
	return false;
}

//Bellman-Ford algorithm, don't use known_flag
// O(|V|*|E|)
DistVector findMinPath_weighted_negative(ptrToAdjList_DAG adj_list, int targetV)
{
	//1- init dist_vector
	DistVector dist_vector = createDistVector(adj_list, targetV);

	//2- begin
	vector<int> q;
	int v_int, w_int;
	int all_cnt = 0;
	int *dequeue_cnt=new int [adj_list->tableSize];	//check if has negative loop
	for(int i=0; i<adj_list->tableSize; i++)
		dequeue_cnt[i] = 0;

	q.push_back(targetV);//enqueue
	while(q.size())//O(|V|)
	{
		all_cnt++;

		//check if has negative loop
		for(int i=0; i<adj_list->tableSize; i++)
		{
			if(dequeue_cnt[i] > adj_list->tableSize)
			{
				DistVector trash_vector;
				cout << "findMinPath_weighted_negative ERROR: has negative loop" << endl;
				return trash_vector;
			}
		}

		//dequeue
		v_int = q[0];
		q.erase(q.begin());
		dequeue_cnt[v_int]++;

		ptrToNode p_now = adj_list->listArray[v_int]->next;
		while(p_now != NULL)//O(|E|)
		{
			w_int = p_now->v_int;
			if(dist_vector[v_int]->d_v + p_now->weight < dist_vector[w_int]->d_v)
			{
				dist_vector[w_int]->d_v = dist_vector[v_int]->d_v + p_now->weight;
				dist_vector[w_int]->previous_vInt = v_int;
				if(not isInq(w_int,q))
				{
					q.push_back(w_int);//enqueue
				}
			}

			p_now = p_now->next;
		}
	}

	cout << "----------all_cnt: " << all_cnt << endl;
	q.clear();

	return dist_vector;
}

//6- minimum spanning tree(MST)
//(1)- Prim algorithm, similar to Dijkstra
// O(|V|^2)
tree_MST_Prim buildMST_Prim(ptrToAdjList_uDAG adj_list, int targetV)
{
	//1- init dist_vector
	DistVector dist_vector = createDistVector(adj_list, targetV);

	//2- begin
	int v_int, w_int;
	vector<int> unknow_v, know_v;
	for(int i=0; i<adj_list->tableSize; i++)//O(|V|)
	{
		unknow_v.push_back(i);
	}

	while(unknow_v.size())//O(|V|)
	{
		v_int = getSmallestDist_unknowV(unknow_v, dist_vector);//O(|V|)
		know_v.push_back(v_int);
		dist_vector[v_int]->know_flag = true;

		ptrToNode p_now = adj_list->listArray[v_int]->next;
		while(p_now != NULL)//O(|E|)
		{
			w_int = p_now->v_int;
			if(not dist_vector[w_int]->know_flag)
			{
				// the only diffrence with Dijkstra
				int d_v_buffer = dist_vector[w_int]->d_v;
				dist_vector[w_int]->d_v = ( (d_v_buffer<p_now->weight)?(d_v_buffer):(p_now->weight));
				if(dist_vector[w_int]->d_v != d_v_buffer)
				{
					dist_vector[w_int]->previous_vInt = v_int;
				}
				// the only diffrence with Dijkstra
			}

			p_now = p_now->next;
		}
	}

	return dist_vector;
}

//(2)- Kruskal algorithm
// use set in chapter 7, no targetV
// O(|E|log|E|)
bool cmp(const Edge_info &e_info1, const Edge_info &e_info2) 
{
    return e_info1.second < e_info2.second;
}

void Edges_sort(Edges &edges)
{
	sort(edges.begin(),edges.end(),cmp);
}

tree_MST_Kruskal buildMST_Kruskal(ptrToAdjList_uDAG adj_list)
{
	//1- init dist_vector
	DistVector dist_vector = createDistVector(adj_list);

	//1- build ascending(weight value) edge_vector
	Edges edges;
	tree_MST_Kruskal tree_mst_Kruskal;

	for(int i=0; i<adj_list->tableSize; i++)
	{
		ptrToNode p_now = adj_list->listArray[i]->next;
		while(p_now != NULL)
		{
			Edge e(i, p_now->v_int);
			Edge_info e_info(e, p_now->weight);
			edges.push_back(e_info);
			p_now = p_now->next;
		}

	}

	//sort the "edges"
	Edges_sort(edges);

	//2- get through edges
	int* mst_forest = createEmptySet();
	int node1, node2, node1_s, node2_s;
	int addEdge_cnt = 0;

	for(auto iter = edges.begin(); iter != edges.end(); iter++)
	{
		if(addEdge_cnt >= adj_list->tableSize-1)
		{
			return tree_mst_Kruskal;
		}

		node1 = (*iter).first.first;
		node2 = (*iter).first.second;
		node1_s = find_set(mst_forest, node1);
		node2_s = find_set(mst_forest, node2);
		if(node1_s != node2_s)
		{
			//node1 & node2 in diffrent set
			// step1: add edge => union(node1, node2)
			// Attention: use union3_set!!!, union with rank
			union3_set(mst_forest, node1_s, node2_s);
			
			//update tree_mst_Kruskal
			tree_mst_Kruskal.push_back(*iter);

			addEdge_cnt++;
		}
	}

	return tree_mst_Kruskal;
}

//7- Graph Traversal
// (1)breadth-first search(BFS)
// DAG & uDAG, refer to "findMinPath_unweighted_2"
// O(|E| + |V|)
Vertex_vector GraphTraversal_BFS(ptrToAdjList adj_list, int targetV)
{
	//0- pre
	int* nodeFlag_array = new int[adj_list->tableSize];
	for(int i=0; i<adj_list->tableSize; i++)
	{
		nodeFlag_array[i] = 0;
	}

	//1- begin
	vector<int> v_vector;
	v_vector.push_back(targetV);//enqueue
	Vertex_vector vertexs;

	int v_int, w_int;
	while(v_vector.size())
	{
		//dequeue, i-th level nodes
		v_int = v_vector[0];
		v_vector.erase(v_vector.begin());
		vertexs.push_back(v_int);

		nodeFlag_array[v_int] = 1;

		ptrToNode p_now = adj_list->listArray[v_int]->next;
		while(p_now != NULL)
		{
			w_int = p_now->v_int;
			if(nodeFlag_array[w_int] != 1)
			{
				nodeFlag_array[w_int] = 1;
				v_vector.push_back(w_int);
			}

			p_now = p_now->next;
		}
	}
	v_vector.clear();

	return vertexs;
}

//(2)depth-first search(DFS)
// P240-P241, 
void DFS(ptrToAdjList adj_list, int* nodeFlag_array, Vertex_vector &vertexs, int v_int)
{
	if(nodeFlag_array[v_int] != 1)
	{
		vertexs.push_back(v_int);
		nodeFlag_array[v_int] = 1;
	}
	
	ptrToNode p_now = adj_list->listArray[v_int]->next;
	while(p_now != NULL)
	{
		int w_int = p_now->v_int;
		if(nodeFlag_array[w_int] != 1)
		{
			nodeFlag_array[w_int] = 1;
			vertexs.push_back(w_int);
			DFS(adj_list, nodeFlag_array, vertexs, w_int);
		}
		p_now = p_now->next;
	}
}

Vertex_vector GraphTraversal_DFS(ptrToAdjList adj_list, int targetV)
{
	//0- pre
	int* nodeFlag_array = new int[adj_list->tableSize];
	for(int i=0; i<adj_list->tableSize; i++)
	{
		nodeFlag_array[i] = 0;
	}
	Vertex_vector vertexs;

	//1- begin
	for(int i=0; i<adj_list->tableSize; i++)
	{
		DFS(adj_list, nodeFlag_array, vertexs, i);
	}

	return vertexs;
}