/*
	Author: Eajack Lau
	Date: 2019/4/18
	Function:
		《数据结构与算法分析（C语言描述）》第四章
		树
		tree => no header as stack/linkedList
		1- expression tree
*/
#include "tree.h"
using namespace std;

//=================stack=================//
//1- Stack implementation
// pointer
struct node_stack
{
	ptrToNode_bi value;
	ptrToNode_stack next;
};

// test if S is |value = NULL, next = NULL|
//O(1)
int isEmptyStack(Stack S)
{
	return (S->value == NULL && S->next == NULL);
}

//produce empty stack, which is |value = NULL, next = NULL|
//O(1)
Stack produceEmptyStack()
{
	ptrToNode_stack tmpNode = (ptrToNode_stack)malloc(sizeof(struct node_stack));
	if (tmpNode == NULL)
	{
		cout << "produceEmptyStack ERROR: malloc out of space" << endl;
		return NULL;
	}
	tmpNode->value = NULL;
	tmpNode->next = NULL;

	return tmpNode;
}


//push x to S，meanwhile S = the addr of 'x'
// Attention: the addr of S is always the same, only S->next changes
//O(1)
void push(ptrToNode_bi p, Stack S)
{
	ptrToNode_stack tmpNode = (ptrToNode_stack)malloc(sizeof(struct node_stack));
	if (tmpNode == NULL)
	{
		cout << "push ERROR: malloc out of space" << endl;
		return;
	}
	tmpNode->value = p;
	tmpNode->next = S->next;
	S->next = tmpNode;
}

//pop, return the top number, and change S ---> lastNode
// Attention: the addr of S is always the same, only S->next changes
//O(1)
void pop(Stack S)
{
	ptrToNode_stack tmpNode;
	if( !isEmptyStack(S) )
	{
		//pop
		tmpNode = S->next;
		S->next = S->next->next;
		free(tmpNode);
	}
}

//top, get the top number
//O(1)
ptrToNode_bi top(Stack S)
{
	if( !isEmptyStack(S) )
		return S->next->value;
	else
	{
		cout << "top ERROR: Empty Stack" <<  endl;
		return NULL;
	}
}

//delete
void deleteStack(Stack S)
{
	if( !isEmptyStack(S) )
	{
		while( !isEmptyStack(S) )
			pop(S);
	}
	else
	{
		cout << "deleteStack ERROR: Empty Stack" << endl;
	}
}
//================================================//

//================tree================//
//binary tree node
struct treeNode_bi
{
	int value;
	tree_bi left;
	tree_bi right;
};

// empty tree <=> only root, value = INT_MIN
// O(1)
tree_bi createEmptyTree()
{
	tree_bi T = (tree_bi)malloc(sizeof(struct treeNode_bi));
	T->value = INT_MIN;
	T->left = NULL;
	T->left = NULL;

	return T;
}

//produce single node tree
// single node tree <=> root, value = x
// O(1)
tree_bi createRoot(int x)
{
	tree_bi T = (tree_bi)malloc(sizeof(struct treeNode_bi));
	if(T == NULL)
	{
		cout << "createRoot ERROR: malloc out of space" << endl;
		return NULL;
	}
	T->value = x;
	T->left = NULL;
	T->right = NULL;

	return T;
}

//get height
// O(N)
int getHeight(searchTree T)
{
	if(T == NULL)
		return -1;
	else
		return ( 1+(getHeight(T->left) > getHeight(T->right) ? \
			getHeight(T->left) : getHeight(T->right)) );
}

//binary search tree, special binary tree, P73
// delete, O(N)
void delete_wholeST(searchTree T)
{
	if(T != NULL)
	{
		delete_wholeST(T->left);
		delete_wholeST(T->right);
		free(T);
	}
}

//binary search tree, special binary tree, P73
// find_x_ST, O(logN)
ptrToNode_bi find_x_ST(int x, searchTree T)
{
	if(T != NULL)
		return NULL;

	if(x < T->value)
		return find_x_ST(x, T->left);
	else if(x > T->value)
		return find_x_ST(x, T->right);
	else
		return T;
}

//binary search tree, special binary tree, P73
// find_min_ST, the left-est one, recursion
// O(logN)
ptrToNode_bi find_min_ST(searchTree T)
{
	if(T == NULL)
		return NULL;
	else if(T->left == NULL)
		return T;
	else
		return find_min_ST(T->left);
}

//binary search tree, special binary tree, P73
// find_max_ST, the right-est one, non-recursion
// O(logN)
ptrToNode_bi find_max_ST(searchTree T)
{
	if(T != NULL)
		while(T->right != NULL)
			T = T->right;
	return T;
}

//binary search tree, special binary tree, P73
// insert x, O(logN)
searchTree insert_ST(int x, searchTree T)
{
	if(T == NULL)
	{
		T = createRoot(x);
	}
	else if(x < T->value)
	{
		T->left = insert_ST(x, T->left);// return T->left itself(update inside)
	}
	else if(x > T->value)
	{
		T->right = insert_ST(x, T->right);// return T->right itself(update inside)
	}
	/* else x in T, do nothing */
	return T;// return T itself(update inside)
}

//binary search tree, special binary tree, P73
// delete x, O(logN)
searchTree delete_ST(int x, searchTree T)
{
	ptrToNode_bi tmpNode;
	if(T == NULL)
		cout << "delete_ST ERROR: element not found" << endl;
	else if(x < T->value)
	{
		T->left = delete_ST(x, T->left);
	}
	else if(x > T->value)
	{
		T->right = delete_ST(x, T->right);
	}
	else if(T->left && T->right)	//found x to delete, (1) 2 children
	{
		tmpNode = find_min_ST(T->right);
		T->value = tmpNode->value;
		T->right = delete_ST(T->value, T->right);
	}
	else
	{
		//(1) 0&1 children
		tmpNode = T;
		if(T->left == NULL)
			T = T->right;
		else if(T->right == NULL)
			T = T->left;
		free(tmpNode);
	}

	return T;
}

//binary search tree, special binary tree, P73
// create a search tree
searchTree create_ST(const int A[], int N)
{
	searchTree T = createRoot(A[0]);
	for(int i=1; i<N; i++)
	{
		T = insert_ST(A[i], T);
	}

	return T;
}


//tree print/get through
// sub-function: infixPrint_ST
void printValue_ST(int value, int depth)
{
	for(int i=0; i<depth; i++)
	{
		cout << '\t';
	}
	cout << value << endl;
}

//tree print/get through
// preorder, infix & post
// O(N)
void print_ST(searchTree T, int depth, int option)
{
	if(option == 1)
	{
		//preorder, print order: value => left => right
		if(T != NULL)
		{
			printValue_ST(T->value, depth);
			print_ST(T->left, depth+1, option);
			print_ST(T->right, depth+1, option);
		}
	}
	else if(option == 2)
	{
		//infix, print order: left => value => right
		if(T != NULL)
		{
			print_ST(T->left, depth+1, option);
			printValue_ST(T->value, depth);
			print_ST(T->right, depth+1, option);
		}
	}
	else if(option == 3)
	{
		//post, print order: left  => right => value
		if(T != NULL)
		{
			print_ST(T->left, depth+1, option);
			print_ST(T->right, depth+1, option);
			printValue_ST(T->value, depth);
		}
	}
}

//================================================//


//================tree test functions================//
//build a expression tree
// input: postfix expression, output: tree
tree_bi build_expressionTree(const int A[], int N)
{
	//step 1
	Stack S = produceEmptyStack();

	//step 2
	for(int i=0; i<N; i++)
	{
		// binary operators
		if( (A[i] != '+') and (A[i] != '-') and (A[i] != '*') and (A[i] != '/'))
		{
			tree_bi T_num = createRoot(A[i]);
			push(T_num, S);
		}
		else
		{
			tree_bi T_ope = createRoot(A[i]);
			ptrToNode_bi ptr_num1 = top(S);
			pop(S);
			ptrToNode_bi ptr_num2 = top(S);
			pop(S);

			T_ope->right = ptr_num1;
			T_ope->left = ptr_num2;

			push(T_ope, S);
		}
	}

	//step 3
	tree_bi return_T = top(S);
	pop(S);
/*	int stack_len = 0;
	if( !isEmptyStack(S) )
	{
		while( !isEmptyStack(S) )
		{
			pop(S);
			stack_len++;
		}
	}
	else
	{
		cout << "deleteStack ERROR: Empty Stack" << endl;
	}

	cout << "stack_len: " << stack_len << endl;*/

	return return_T;
}

//================================================//