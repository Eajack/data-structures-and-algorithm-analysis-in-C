/*
	Author: Eajack Lau
	Date: 2019/6/21
	Function:
		二叉树类实现
*/
#pragma once

#include <vector>
#include <string>
#include <algorithm>

struct TreeNodeBinary{
	int val;
	TreeNodeBinary *left;
	TreeNodeBinary *right;
	TreeNodeBinary(): val(0), left(nullptr), right(nullptr) {};
	TreeNodeBinary(int val): val(0), left(nullptr), right(nullptr) {};
};
enum TraversalFlag {
	PRE_ORDER=1,
	MID_ORDER,
	AFTER_ORDER,
	LEVEL_ORDER
};

//1 普通二叉树
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int val);
	~BinaryTree();

	//N为节点总数
	//1 获取树的高度，O(N)
	int height();
	//2 前序/中序/后序/层序遍历，O(N)
	std::vector<int> Traversal(enum TraversalFlag flag);
	//3 DFS应用1：树的查找，O(N)
	TreeNodeBinary* find(int val);
	//4 DFS应用2：打印所有【根 => 叶节点】路径，O(N)
	std::vector<std::string> getPath();
	//5 DFS应用3：树清空，O(N)
	void clear();

private:
	TreeNodeBinary* root;
	std::vector<int> traversalVals;
	std::vector<std::string> paths;
	std::vector<std::vector<int>> levelVals;

	//1 获取树的高度
	int _height(TreeNodeBinary* r);
	//2 前序/中序/后序/层序遍历
	void _preOrder(TreeNodeBinary* r);
	void _midOrder(TreeNodeBinary* r);
	void _afterOrder(TreeNodeBinary* r);
	void _levelOrder(TreeNodeBinary* r);
	void _Traversal(TreeNodeBinary* r, enum TraversalFlag flag);
	//3 DFS应用1：树的查找
	void _find(TreeNodeBinary* r, int val, TreeNodeBinary* &ans);
	//4 DFS应用2：打印所有【根 => 叶节点】路径
	void _getPath(TreeNodeBinary * r, std::string cur);
	//5 DFS应用3：树清空
	void _clear(TreeNodeBinary* r);
};

//2 二叉查找树（左小右大）
class BinarySearchTree:public BinaryTree
{
public:
	BinarySearchTree();
	BinarySearchTree(std::vector<int> vals);
	~BinarySearchTree();

	//1 插入，O(logN)
	void insert(int val);
	//2 查找，O(logN)
	bool find(int val);
	int findMax();
	int findMin();
	//3 删除，O(logN)
	void erase(int val);
private:
	TreeNodeBinary * root;

	//1 插入
	TreeNodeBinary* _insert(int val, TreeNodeBinary* r);
	//2 查找
	TreeNodeBinary* _find(int val, TreeNodeBinary* r);
	TreeNodeBinary* _findMax(TreeNodeBinary* r);
	TreeNodeBinary* _findMin(TreeNodeBinary* r);
	//3 删除
	TreeNodeBinary* _erase(int val, TreeNodeBinary* r);
};