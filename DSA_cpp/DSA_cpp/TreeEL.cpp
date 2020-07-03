/*
	Author: Eajack Lau
	Date: 2019/6/21
	Function:
		二叉树类实现
*/
#include "TreeEL.h"
using namespace std;


//1 普通二叉树
BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::BinaryTree(int val)
{
	root = new TreeNodeBinary(val);
}

BinaryTree::~BinaryTree()
{
}

int BinaryTree::height()
{
	if (!root) {
		return 0;
	}
	int ans = _height(root);
	return ans;
}

vector<int> BinaryTree::Traversal(TraversalFlag flag)
{
	if (!root) {
		return {};
	}

	traversalVals.clear();
	levelVals.clear();
	_Traversal(root, flag);
	return traversalVals;
}

TreeNodeBinary * BinaryTree::find(int val)
{
	if (!root) {
		return nullptr;
	}

	TreeNodeBinary* ans = nullptr;
	_find(root, val, ans);
	return ans;
}

vector<string> BinaryTree::getPath()
{
	if (!root) {
		return {};
	}

	paths.clear();
	string cur = to_string(root->val);
	_getPath(root, cur);
	return paths;
}

void BinaryTree::clear()
{
	if (!root) {
		return;
	}
	_clear(root);
}

int BinaryTree::_height(TreeNodeBinary * r)
{
	if (!r) {
		return 0;
	}
	return max(_height(r->left), _height(r->right)) + 1;
}

void BinaryTree::_preOrder(TreeNodeBinary * r)
{
	if (!r) {
		return;
	}
	traversalVals.push_back(r->val);
	_preOrder(r->left);
	_preOrder(r->right);
}

void BinaryTree::_midOrder(TreeNodeBinary * r)
{
	if (!r) {
		return;
	}
	_midOrder(r->left);
	traversalVals.push_back(r->val);
	_midOrder(r->right);
}

void BinaryTree::_afterOrder(TreeNodeBinary * r)
{
	if (!r) {
		return;
	}
	_afterOrder(r->left);
	_afterOrder(r->right);
	traversalVals.push_back(r->val);
}

void BinaryTree::_levelOrder(TreeNodeBinary * r)
{
	//1
	if (!r) {
		return;
	}

	//2
	vector<TreeNodeBinary*> nodes = { root };
	while (!nodes.empty()) {
		int size = nodes.size();
		vector<int> vals;
		while (size--) {
			int val = nodes[0]->val;
			vals.push_back(val);
			if (nodes[0]->left) {
				nodes.push_back(nodes[0]->left);
			}
			if (nodes[0]->right) {
				nodes.push_back(nodes[0]->right);
			}
			nodes.erase(nodes.begin());
		}
		levelVals.push_back(vals);
	}
}

void BinaryTree::_Traversal(TreeNodeBinary * r, TraversalFlag flag)
{
	switch (flag) {
		case PRE_ORDER: {
			_preOrder(r);
			break;
		}
		case MID_ORDER: {
			_midOrder(r);
			break;
		}
		case AFTER_ORDER: {
			_afterOrder(r);
			break;
		}
		case LEVEL_ORDER: {
			_levelOrder(r);
			break;
		}
		default: {
			break;
		}
	}
}

void BinaryTree::_find(TreeNodeBinary* r, int val, TreeNodeBinary* &ans)
{
	//1
	if (!root) {
		return;
	}

	//2
	if (r->val == val) {
		ans = r;
		return;
	}
	_find(r->left, val, ans);
	_find(r->right, val, ans);
}

void BinaryTree::_getPath(TreeNodeBinary * r, string cur)
{
	if (!r->left && !r->right) {
		paths.push_back(cur);
		return;
	}

	//1
	if (r->left) {
		_getPath(r->left, cur + "->" + to_string(r->left->val));
	}
	if (r->right) {
		_getPath(r->right, cur + "->" + to_string(r->right->val));
	}
}

void BinaryTree::_clear(TreeNodeBinary * r)
{
	//1
	if (!r) {
		return;
	}

	//2
	TreeNodeBinary *left = r->left, *right = r->right;
	delete r;
	_clear(left);
	_clear(right);
}

//2 二叉查找树（左小右大）
BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::BinarySearchTree(vector<int> vals)
{
	for (int v : vals) {
		insert(v);
	}
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(int val)
{
	root = _insert(val, root);
}

bool BinarySearchTree::find(int val)
{
	return (_find(val, root) != nullptr);
}

int BinarySearchTree::findMax()
{
	TreeNodeBinary* node = _findMax(root);
	return (node) ? (node->val) : (INT_MAX);
}

int BinarySearchTree::findMin()
{
	TreeNodeBinary* node = _findMin(root);
	return (node) ? (node->val) : (INT_MIN);
}

void BinarySearchTree::erase(int val)
{
	root = _erase(val, root);
}

TreeNodeBinary* BinarySearchTree::_insert(int val, TreeNodeBinary * r)
{
	if (!r) {
		r = new TreeNodeBinary(val);
	}
	else if (val < r->val) {
		r->left = _insert(val, r->left);
	}
	else if (val > r->val) {
		r->right = _insert(val, r->right);
	}
	return r;
}

TreeNodeBinary* BinarySearchTree::_find(int val, TreeNodeBinary * r)
{
	if (!r) {
		return nullptr;
	}

	if (val < r->val) {
		return _find(val, r->left);
	}
	else if (val > r->val) {
		return _find(val, r->right);
	}
	else {
		return r;
	}
}

TreeNodeBinary* BinarySearchTree::_findMax(TreeNodeBinary * r)
{
	if (!r) {
		while (r->right != nullptr) {
			r = r->right;
		}
	}
	return r;
}

TreeNodeBinary* BinarySearchTree::_findMin(TreeNodeBinary * r)
{
	if (!r) {
		while (r->left != nullptr) {
			r = r->left;
		}
	}
	return r;
}

TreeNodeBinary * BinarySearchTree::_erase(int val, TreeNodeBinary * r)
{
	TreeNodeBinary* tempNode = new TreeNodeBinary(0);
	if (r) {
		if (val < r->val) {
			r->left = _erase(val, r->left);
		}
		else if (val > r->val) {
			r->right = _erase(val, r->right);
		}
		// 查找到x了，开始删除操作
		// （1）存在左右2个子树
		//		找到当前节点（val = x）右子树的最小值节点Node代替当前x，然后删掉Node
		else if (r->left && r->right) {
			tempNode = _findMin(r->right);
			r->val = tempNode->val;
			r->right = _erase(r->val, r->right);
		}
		// （2）没有子树/1个子树
		//		tempNode = 当前节点
		//		1个子树：tempNode = 返回子树节点，删除tempNode
		//		没有子树（叶节点）：删除tempNode
		else {
			tempNode = r;
			if(r->left == nullptr){
				r = r->right;
			}
			else if (r->right == nullptr) {
				r = r->left;
			}
			delete tempNode;
		}
	}

	return r;
}
